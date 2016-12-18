import hashlib
from collections import deque

def is_open(character, index, current):
    not_wall = False
    if index == 0:
        not_wall = current[1] + 1 < 4
    if index == 1:
        not_wall = current[1] - 1 > -1
    if index == 2:
        not_wall = current[0] - 1 > -1
    if index == 3:
        not_wall = current[0] + 1 < 4

    return character > 'a' and character < 'g' and not_wall


def get_hash(line):
    return hashlib.md5(line.encode('utf-8')).hexdigest()[:4]

def next_pos(pos, i, passcode):
    x = 0
    y = 0
    if i == 0:
        y = 1
        character = 'U'
    if i == 1:
        y = -1
        character = 'D'
    if i == 2:
        x = -1
        character = 'L'
    if i == 3:
        x = 1
        character = 'R'
    return (([pos[0] + x, pos[1] + y], passcode + character))



def dls(current, finish, depth):
    (start, passcode) = current
    if(start == finish):
        return passcode
    if(depth <= 0):
        return 10000*'0'
    code = get_hash(passcode)
    shortest = 10000*'0'
    for i, door in enumerate(code):
        if is_open(door, i, start):
            check = dls(next_pos(start, i, passcode), finish, depth - 1)
            if len(shortest) >= len(check):
                shortest = check
    return shortest

def iddls(start, finish, passcode, maxDepth, part2):
    longest = 0
    for depth in range(1, maxDepth):
        if dls((start, passcode), finish, depth) is not None:
            if(not part2):
                return passcode
            else:
                longest = depth
                continue
    return longest


def bfs(start, finish, passcode, part2):
    q = deque()
    q.appendleft((start,passcode))
    while(q):
        (pos, passcode) = q.pop()
        if pos == finish:
            if(not part2):
                return passcode
            else:
                longest = len(passcode)
                continue
        code = get_hash(passcode)
        for i, door in enumerate(code):
            if is_open(door, i, pos):
                q.appendleft(next_pos(pos, i, passcode))
    return longest



def main():
    passcode = open('day17.in', 'r').read().strip()
    start = len(passcode)
    current_pos = [0,3]
    target = [3,0]
    # shortest path
    print(bfs(current_pos, target, passcode, False)[start:])
    print(bfs(current_pos, target, passcode, True) - start)


if __name__ == '__main__':
    main()
