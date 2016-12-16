import re

pattern = re.compile(r'(\w+) ([\d\w]+) ([\d\w]+)')

registers = {
    'a': 0,
    'b': 0,
    'c': 0,
    'd': 0
}

def parse(input):
    try:
        return int(input)
    except:
        return registers[input]

def main():
    with open('day12.in', 'r') as fp:
        instructions = fp.read().splitlines()
    i = 0
    while i < len(instructions):
        action = instructions[i].split()
        if action[0] == 'cpy':
            registers[action[2]] = parse(action[1])
        if action[0] == 'inc':
            registers[action[1]] += 1
        if action[0] == 'dec':
            registers[action[1]] -= 1
            # print("index is {} which is {}".format(i, instructions[i]))
            # print(registers)
        if action[0] == 'jnz' and parse(action[1]) != 0:
            i += int(action[2])
            continue
        i += 1
    print(registers)




if __name__ == '__main__':
    main()
