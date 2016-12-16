import re

find_pattern = re.compile(r'[(](\d+)x(\d+)[)]')


def findAll(compressed):
    decompressed = ''
    remaining = compressed
    while remaining:
        match = find_pattern.search(remaining)
        decompressed += remaining[0:match.start()]
        length, repeat = match.groups()
        length = int(length)
        repeat = int(repeat)
        tag_end = match.end()
        segment_end = tag_end + length
        repeat_segment = remaining[tag_end:segment_end]
        repeat_segment *= repeat
        decompressed += repeat_segment
        remaining = remaining[segment_end:]
    return decompressed.strip()


def main():
    with open('day9.in', 'r') as input_file:
        remaining = input_file.read().strip()
    while find_pattern.search(remaining.strip()) is not None:
        compressed = findAll(remaining)
        remaining = compressed
    print('answer 2: {}'.format(len(remaining.strip())))


if __name__ == '__main__':
    main()
