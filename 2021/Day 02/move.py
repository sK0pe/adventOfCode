import os

def findPosition(movements: list):
    depth = 0
    progress = 0
    if(movements is not None):
        for movement in movements:
            direction, value = movement.split(' ')
            value = int(value.strip())
            if(direction == "up"):
                depth -= value
            elif(direction == "down"):
                depth += value
            elif(direction == "forward"):
                progress += value
            else:
                raise Exception(f"{direction} is not a known direction")
    print(f"Progress = {progress}")
    print(f"Depth = {depth}")
    return progress * depth;

def findPositionAim(movements: list):
    depth = 0
    progress = 0
    aim = 0
    if(movements is not None):
        for movement in movements:
            direction, value = movement.split(' ')
            value = int(value.strip())
            if(direction == "up"):
                aim -= value
            elif(direction == "down"):
                aim += value
            elif(direction == "forward"):
                progress += value
                depth += (aim * value)
            else:
                raise Exception(f"{direction} is not a known direction")
    print(f"Progress = {progress}")
    print(f"Depth = {depth}")
    print(f"Aim = {aim}")
    return progress * depth


def parse_input_file(filename: str):
    current_dir = os.path.dirname(__file__);
    full_path = os.path.join(current_dir, filename)
    with open(full_path) as input_file:
        parsed_input = input_file.readlines()
    return [line.strip() for line in parsed_input]


def main():
    parsed_input = parse_input_file("input.txt")

    result_1 = findPosition(parsed_input)
    print(f"Part 1: {result_1}")

    result_2 = findPositionAim(parsed_input)
    print(f"Part 2: {result_2}")

if __name__ == "__main__":
    main()
