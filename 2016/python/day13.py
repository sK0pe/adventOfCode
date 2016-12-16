from collections import deque

TARGET = (31, 39)


#    Returns true if a wall
def is_wall(x, y, fav_number):
    return bin(fav_number + (x * x + 3 * x + 2 * x * y + y + y * y)).count('1')% 2 != 0


def bfs(fav_number, directions, part2):
    visited = set([])
    q = deque()
    q.append(((1, 1), 0))
    while q:
        current = q.popleft()
        #print(current)
        if part2 and current[1] > 50:
            return len(visited)
        if current[0] == TARGET and not part2:
            return current[1]
        for d in directions:
            new_pos = (current[0][0] + d[0], current[0][1] + d[1])
            if new_pos not in visited and new_pos[0] >= 0 and new_pos[1] >= 0 and not is_wall(new_pos[0], new_pos[1], fav_number):
                print(current)
                q.append((new_pos, current[1] + 1))
        visited.add(current[0])
    return -1


def main():
    fav_number = open('day13.in', 'r').read().strip()
    directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    print(bfs(int(fav_number), directions, True))


if __name__ == '__main__':
    main()
