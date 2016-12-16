import re

find_pattern = re.compile(r'[(](\d+)x(\d+)[)]')

part2 = False

def decompress(compressed):
    if '(' not in compressed:
        return len(compressed)
    count = 0
    while '(' in compressed:
        count += compressed.find('(')
        compressed = compressed[compressed.find('('):]
        marker = compressed[1:compressed.find(')')].split('x')
        compressed = compressed[compressed.find(')') + 1:]
        if part2:
            count += decompress(compressed[:int(marker[0])]) * int(marker[1])
        else:
            count += len(compressed[:int(marker[0])]) * int(marker[1])
        compressed = compressed[int(marker[0]):]
    count += len(compressed)
    return count


input_file = open('day9.in', 'r').read().strip()
print(decompress(input_file))
part2 = True
print(decompress(input_file))
