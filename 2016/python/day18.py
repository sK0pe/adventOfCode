def next_row(line):
    output = '0'
    for i in range(len(line) - 2):
        if(line[i] == line[i] and line[i] != line[i+2]):
            output += '1'
        elif(line[i+1] == line[i+2] and line[i] != line[i+1]):
            output += '1'
        else:
            output += '0'
    output += '0'
    return output

def main(first_row, part2):
    if(part2):
        ROWS = 400000
    else:
        ROWS = 40
    safe = 0
    temp_row = ''
    temp_row += '0'
    for tile in first_row:
        if tile == '.':
            temp_row += '0'
        else:
            temp_row += '1'
    temp_row += '0'
    for r in range(ROWS):
        safe += temp_row[1:-1].count('0')
        temp_row = next_row(temp_row)
    print(safe)

if __name__ == '__main__':
    first_row = open('day18.in', 'r').read().strip()
    main(first_row, False)
    main(first_row, True)
