def dragon_curve(a):
    b_mod = ''
    for c in a[::-1]:
        if c == '0':
            b_mod += '1'
        else:
            b_mod += '0'
    return a + '0' + b_mod

def gen_check(uncompressed):
    i = 0
    compressed = ''
    while i < len(uncompressed):
        if uncompressed[i] == uncompressed[i + 1]:
            compressed += '1'
        else:
            compressed += '0'
        i += 2
    return compressed

def main(first_disk):
    initial_state = open('day16.in', 'r').read().strip()
    while(len(initial_state) < first_disk):
        initial_state = dragon_curve(initial_state)
    #print(initial_state)
    initial_state = initial_state[:first_disk]
    #print(initial_state)

    initial_state = gen_check(initial_state)
    while len(initial_state) % 2 == 0 :
        #print(initial_state)
        initial_state = gen_check(initial_state)
    print(initial_state)


if __name__ == '__main__':
    main(272)
    main(35651584)
