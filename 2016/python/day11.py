import re

findFloor = re.compile(r'The (\w+) floor')
findGenerator = re.compile(r'(\w+) generator')
findMicrochip = re.compile(r'(\w+)-compatible')

M = 0
G = 1


def get_two_different_items(microchips, generators):
    output = []
    m_backup = microchips.copy()
    g_backup = generators.copy()
    for m in m_backup:
        for g in g_backup:
            microchips.discard(m)
            generators.discard(g)
            if safe_chips(microchips, generators):
                output.append([{m}, {g}])
            assert isinstance(m, object)
            microchips.add(m)
            generators.add(g)
    return output


def get_two_same_items(items, other_items, isChip):
    output = []
    items_backup = items.copy()
    for i in range(len(items_backup)):
        for j in range(i, len(items_backup) + 1):
            items.discard(items_backup[i])
            items.discard(items_backup[j])
            if safe_chips(items, other_items):
                if isChip:
                    output.append([{items_backup[i], items_backup[j]}, {}])
                else:
                    output.append([{}, {items_backup[i], items_backup[j]}])
            items.add(items_backup[i])
            items.add(items_backup[j])
    return output


def get_valid_single_items(a_items, b_items, isChip):
    output = []
    a_backup = a_items.copy()
    for m in a_backup:
        a_items.discard(m)
        if safe_chips(a_items, b_items):
            if isChip:
                output.append([{m}, {}])
            else:
                output.append([{}, {m}])
        a_items.add(m)
    return output


def get_valid_elevator_states(microchips, generators):
    output = []
    if len(microchips):
        output.extend(get_valid_single_items(microchips, generators, True))
    if len(generators):
        output.extend(get_valid_single_items(generators, microchips, False))
    if len(microchips) > 1:
        output.extend(get_two_same_items(microchips, generators, True))
    if len(generators) > 1:
        output.extend(get_two_same_items(generators, microchips, False))
    if len(microchips) and len(generators):
        output.extend(get_two_different_items(microchips, generators))
    return output


def safe_chips(microchips, generators):
    num_safe_pairs = 0
    for gen in generators:
        if gen in microchips:
            num_safe_pairs += 1
    return num_safe_pairs == len(generators) or num_safe_pairs == len(microchips)


def wrong_floor(building, level):
    total_items = 0
    for floor in range(0, level + 1):
        total_items += len(building[floor][M]) + len(building[floor][G])
    return total_items == 0 or level > 3 or level < 0


def elevate(building, level, elevator, total, steps):
    # check if trying to move to a floor which has already been cleared or non existent
    if wrong_floor(building, level):
        return float('inf')
    # offload items to floor
    for m in elevator[M]:
        building[level][M].add(m)
    for g in elevator[G]:
        building[level][G].add(g)
    # End or exit if all items on top floor
    if len(building[level][M]) == len(building[level][G]) and len(building[level][M]) == total and level == 3:
        return 0
    # if a chip gets fried, return impossible
    if not safe_chips(building[level][M], building[level][G]):
        return float('inf')
    # determine all possible elevator fill states
    elevator_states = get_valid_elevator_states(building[level][M], building[level][G])
    # iterate through elevator states and initiate recursive calls to move up or down
    for state in elevator_states:
        if level == 0:
            return elevate(building, level + 1, state, total) + 1
        if level == 3:
            return elevate(building, level - 1, state, total) + 1
        return min(elevate(building, level + 1, state, total, steps) + 1, elevate(building, level - 1, state, total, steps) + 1)


def main():
    input_file = open('day11.in', 'r').read().splitlines()
    # floor = 0
    # building = [(set(),set())]
    building = []
    total = 0
    for line in input_file:
        generators = set(re.findall(findGenerator, line))
        microchips = set(re.findall(findMicrochip, line))
        total += len(microchips)
        building.append((microchips, generators))
    # print('total microchips = {}'.format(len(building[0][0]) + len(building[0][1])))
    print(elevate(building, 0, [{},{}], total, 0))

    # for a, b in building:
    #     if(a or b):
    #         print('generators {}'.format(a))
    #         print('microchips {}'.format(b))


if __name__ == '__main__':
    main()
