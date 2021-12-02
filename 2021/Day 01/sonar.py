import os

def find_increases(depths: list):
    depthIncreaseCount: int = 0
    current_depth: int = None
    if len(depths) > 1:
        for depth in depths:
            if current_depth is not None and depth > current_depth:
                depthIncreaseCount += 1
            current_depth = depth
    return depthIncreaseCount

def find_sliding_window_increases(depths:  list, window_size: int = 3):
    # rolling_depths = []
    # for i in range(0, len(depths) - window_size + 1):
    #     rolling_depths.append(sum(depths[i : i + window_size]))
    rolling_depths = [sum(depths[i : i + window_size]) for i in range(0, len(depths) - window_size + 1)]
    return find_increases([rolling_depths])


def parse_input_file(filename: str):
    current_dir = os.path.dirname(__file__);
    full_path = os.path.join(current_dir, filename)
    with open(full_path) as input_file:
        parsed_input = input_file.readlines()
    return [int(line.strip()) for line in parsed_input]


def main():
    parsed_input = parse_input_file("input.txt")

    result_1 = find_increases(parsed_input)
    print(f"Part 1: {result_1}")

    result_2 = find_sliding_window_increases(parsed_input)
    print(f"Part 2: {result_2}")

if __name__ == "__main__":
    main()
