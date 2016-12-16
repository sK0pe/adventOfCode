from collections import deque
import re
import hashlib

find_triple = re.compile(r'(.)\1{2,}')
find_five = re.compile(r'(.)\1{4,}')

def get_hash_2016(line, five):
    i = 0
    while( i < 2017):
        temp = hashlib.md5(line.encode('utf-8')).hexdigest()
        line = temp
        i += 1
    if(five):
        match = find_five.search(line)
    else:
        match = find_triple.search(line)
    return match.group(0)[0] if match else None



def get_hash(line, five):
    if(five):
        match = find_five.search(hashlib.md5(line.encode('utf-8')).hexdigest())
    else:
        match = find_triple.search(hashlib.md5(line.encode('utf-8')).hexdigest())
    return match.group(0)[0] if match else None


def roll_database(possKeys, salt, index):
    # Remove last hash match if it exists
    tail = get_hash_2016(salt + str(index), True)
    if tail:
        possKeys[tail] -= 1
    # Add new hash if it exists
    head = get_hash_2016(salt + str(index + 1001), True)
    if head :
        if possKeys.get(head, 0) > 0:
            possKeys[head] += 1
        else:
            possKeys[head] = 1

def loadNums(salt):
    possibleKeys = {}
    for i in range(1, 1001):
        match = get_hash_2016(salt + str(i), True)
        if match :
            if possibleKeys.get(match, 0) > 0:
                possibleKeys[match] += 1
            else:
                possibleKeys[match] = 1
    return possibleKeys

def main():
    salt = open('day14.in', 'r').read().strip()
    index = 0
    keys = set([])
    possKeys = loadNums(salt)

    while len(keys) < 64:
        match = get_hash_2016(salt + str(index), False)
        if match:
            if possKeys.get(match, 0) > 0:
                print(index)
                keys.add(index)
        index += 1
        roll_database(possKeys, salt, index)
    print(index - 1)


if __name__ == '__main__':
    main()
