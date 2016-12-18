import functools, re

find_nums = re.compile(r'\d+')

def inv(a, m):
    u1, u2, u3 = 1, 0, a
    v1, v2, v3 = 0, 1, m
    while v3 != 0:
        q = u3 // v3
        v1, v2, v3, u1, u2, u3 = (u1 - q * v1), (u2 - q * v2), (u3 - q * v3), v1, v2, v3
    return u1 % m

def crt(num, rem):
    prod = functools.reduce(lambda x, y: x * y, num, 1)
    result = 0
    for i in range(len(rem)):
        pp = prod // num[i]
        result += rem[i] * inv(pp, num[i]) * pp
    return result % prod


def run(lines):
    rem = []
    num = []

    for i, line in enumerate(lines):
        _, positions, _, start_pos = re.findall(find_nums, line)
        num.append(int(positions))
        rem.append(num[-1] - (int(start_pos) + i + 1) % num[-1])
    print(crt(num, rem))


if __name__ == '__main__':
    instructions = open('day15.in','r').read().splitlines()
    run(instructions)
