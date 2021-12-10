import os
from typing import Counter

def findBitCriteria(column: list, isOxygen: bool = True):
    bitCriteria = ''
    if(isOxygen):
        # only return 0 if it is the least
        if(sum(column) / len(column) < 0.5):
            bitCriteria = 0
        else:
            bitCriteria = 1
    else:
        # only return 1 if it is the least
        if(sum(column) / len(column) < 0.5):
            bitCriteria = 1
        else:
            bitCriteria = 0

    return bitCriteria

def calculateO2AndCO2(data: list, isOxygen: bool):
    max_number = len(data[0])
    valid_row_indices: set = [index for index in range(len(data))]
    binaryIndex = 0
    while(len(valid_row_indices) > 1 and binaryIndex < max_number):
        column = []
        for c in valid_row_indices:
            column.append(data[c][binaryIndex])
        bitCriteria = findBitCriteria(column, isOxygen)
        for lineIndex, line in enumerate(data):
            if(line[binaryIndex] != bitCriteria and lineIndex in valid_row_indices):
                valid_row_indices.remove(lineIndex)
        binaryIndex += 1
    print(valid_row_indices)
    return ''.join(str(x) for x in data[valid_row_indices[0]])






def calculateGammaEpsilon(data: list):
    max_numbers = len(data)
    rotated = zip(*reversed(data))
    epsilon = ''
    gamma = ''
    for column in rotated:
        if(sum(column) / max_numbers > 0.5):
            epsilon += '1'
            gamma += '0'
        else:
            epsilon += '0'
            gamma += '1'
    return int(epsilon, 2) * int(gamma, 2)


def parse_input_file(filename: str):
    current_dir = os.path.dirname(__file__);
    full_path = os.path.join(current_dir, filename)
    with open(full_path) as input_file:
        parsed_input = []
        for line in input_file.read().splitlines():
            parsed_input.append([int(code) for code in line])
    return parsed_input


def main():
    parsed_input = parse_input_file("input.txt")
    result_1 = calculateGammaEpsilon(parsed_input)
    print(f"Part 1: {result_1}")

    o2 = calculateO2AndCO2(parsed_input, True)
    co2 = calculateO2AndCO2(parsed_input, False)
    print(o2)
    print(co2)
    print(int(o2, 2))
    print(int(co2,2))
    result_2 = int(o2, 2) * int(co2,2)
    print(f"Part 2: {result_2}")

if __name__ == "__main__":
    main()
