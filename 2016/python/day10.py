import collections
import re

bots = collections.defaultdict(list)
output = collections.defaultdict(list)

numbers = re.compile(r'-?\d+')
destinations = re.compile(r' (bot|output)')
getnums = lambda n: map(int, numbers.findall(n))


def main():
    with open('day10.in', 'r') as fp:
        instructions = fp.read().splitlines()
    factory = {}
    for instruction in instructions:
        if instruction.startswith('value'):
            chip, botID = map(int, re.findall(r'\d+', instruction))
            bots[botID].append(chip)
        if instruction.startswith('bot'):
            bi, lowChip, highChip = map(int, re.findall(r'\d+', instruction))
            lowDestination, highDestination = re.findall(r' (bot|output)', instruction)
            factory[bi] = (lowDestination, lowChip), (highDestination, highChip)

    while (bots):
        for identity, chips in dict(bots).items():
            print(identity)
            if len(chips) == 2:
                current = bots.pop(identity)
                low = min(current)
                high = max(current)
                if (low == 17 and high == 61):
                    print(identity)
                (lowDestination, lowChip), (highDestination, highChip) = factory[identity]
                if lowDestination.startswith('out'):
                    output[lowDestination].append(low)
                else:
                    bots[lowDestination].append(low)
                if highDestination.startswith('out'):
                    output[highDestination].append(high)
                else:
                    bots[highDestination].append(high)

    a, b, c = (output[k][0] for k in [0, 1, 2])
    print(a * b * c)


if __name__ == '__main__':
    main()
