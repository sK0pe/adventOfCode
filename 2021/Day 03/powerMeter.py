import os
from typing import Dict

def aggregateNums(lines: list):
    fullLine: dict = {}
    if(lines is not None):
        for lineNumber, line in enumerate(lines):
            maxRequired: int = len(line)//2
            for i in range(0, len(line), 1):
                if(lineNumber == 0):
                    fullLine[i] = [0, 0]
                if(int(line[i]) == 0):
                    fullLine.get(i)[0] += 1
                else:
                    fullLine.get(i)[1] += 1
        gamma = ''.join(['0' if zero > one else '1' for zero, one in fullLine.values()])
        epsilon = ''.join(['1' if c == '0' else '0' for c in gamma])
        
        return int(gamma, 2) * int(epsilon, 2)
    else:
        raise Exception(f"{lines} is None")
        

def parse_input_file(filename: str):
    current_dir = os.path.dirname(__file__);
    full_path = os.path.join(current_dir, filename)
    with open(full_path) as input_file:
        parsed_input = input_file.readlines()
    return [line.strip() for line in parsed_input]


def main():
    parsed_input = parse_input_file("input.txt")
    print(aggregateNums(parsed_input))

    gamma: str = aggregateNums(parsed_input)
    # print(f"Part 1: {result_1}")

    # result_2 = find_sliding_window_increases(parsed_input)
    # print(f"Part 2: {result_2}")

if __name__ == "__main__":
    main()
