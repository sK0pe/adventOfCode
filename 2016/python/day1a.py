#! /usr/bin/python
import sys

cardinal = ((0, 1),
            (1, 0),
            (0, -1),
            (-1, 0))

TURN = dict(R=lambda x: (x + 1) % 4, L=lambda x: (x - 1) % 4)


def main():
    current_direction = 0
    location = (0, 0)
    for instructions in open("input.txt", "r"):
        for instruction in [x.strip() for x in instructions.split(",")]:
            direction, magnitude = instruction[0], int(instruction[1:])
            current_direction = TURN[direction](current_direction)
            location = (location[0] + cardinal[current_direction][0] * magnitude,
                        location[1] + cardinal[current_direction][1] * magnitude)
    print("distance is = {}".format(abs(location[0]) + abs(location[1])))


if __name__ == '__main__':
    main()
