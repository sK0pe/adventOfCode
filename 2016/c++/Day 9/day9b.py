import re

find_pattern = re.compile(r'[\(](\d+)x(\d+)[\)]')

def findAll(compressed, part2):
    if(find_pattern.search(compressed) is None):
        return len(compressed)
    count = 0
    while(find_pattern.search(compressed)):
        #print(find_pattern.search(compressed))
        match = find_pattern.search(compressed)
        count += len(compressed[0:match.start()])
        numCharacters, multiplier = match.groups()
        numCharacters = int(numCharacters)
        multiplier = int(multiplier)
        if part2:
            count += findAll(compressed[:numCharacters] * multiplier, True)
        else:
            count += len(compressed[:numCharacters]) * multiplier
        compressed = compressed[numCharacters]
    count += len(compressed)
    return count


def main():
    with open('day9.in', 'r') as input_file:
        compressed = input_file.read().strip()
    print('answer 1: {}'.format(findAll(compressed, False)))
    #print('answer 2: {}'.format(findAll(compressed, True)))

if __name__=='__main__':
    main()
