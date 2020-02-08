import random as rn


def perm(l, permutation):
    return [l[permutation[i]] for i in range(len(permutation))]


def s_block(n, input):
    row = input[0] * 2 + input[5]
    column = sum([input[i] * 2 ** (4 - i) for i in range(1, 5)])
    return [int(elem) for elem in bin(s[n][4 * row + column])[2:].zfill(4)]


def round(round_input, round_key):
    l0 = round_input[:32]
    r0 = round_input[32:]
    p1 = perm(r0, expand)
    p2 = [[p1[j] ^ round_key[j] for j in range(i, i + 6)] for i in range(0, 48, 6)]
    after_s = []
    for i in range(8):
        after_s.extend(s_block(i, p2[i]))
    p3 = perm(after_s, p)
    return r0 + [l0[i] ^ p3[i] for i in range(32)]


def next_key():
    global c, d, shift_counter
    for i in range(16):
        c = c[shifts[shift_counter]:] + c[:shifts[shift_counter]]
        d = d[shifts[shift_counter]:] + d[:shifts[shift_counter]]
        shift_counter += 1
        yield perm(c + d, key_final)


def byte(bits):
    return sum([bits[i] * 2 ** (7 - i) for i in range(8)])


ip = [57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31,
      23, 15, 7, 56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46,
      38, 30, 22, 14, 6]

ip_rev = [39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12,
          52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25,
          32, 0, 40, 8, 48, 16, 56, 24]

expand = [31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 11, 12, 13, 14, 15, 16, 15, 16, 17, 18, 19, 20, 19,
          20, 21, 22, 23, 24, 23, 24, 25, 26, 27, 28, 27, 28, 29, 30, 31, 0]

s = [[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
     [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
     [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
     [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9],
     [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
     [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12],
     [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
     [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]]

a = range(32)
for i in range(1):
    print(" ".join(list(map(str, perm(s[i],
                                      [11, 21, 12, 28, 15, 22, 17, 2, 26, 9, 30, 13, 8, 10, 14, 5, 19, 4, 23, 25, 29,
                                       24, 27, 6, 7, 16, 3, 31, 0, 18, 1, 20])))))
    s[i] = perm(s[i],
                [11, 21, 12, 28, 15, 22, 17, 2, 26, 9, 30, 13, 8, 10, 14, 5, 19, 4, 23, 25, 29, 24, 27, 6, 7, 16, 3, 31,
                 0, 18, 1, 20])

p = [15, 6, 19, 20, 28, 11, 27, 16, 0, 14, 22, 25, 4, 17, 30, 9, 1, 7, 23, 13, 31, 26, 2, 8, 18, 12, 29, 5, 21, 10, 3,
     24]

key_init_perm = [56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43,
                 35, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27,
                 19, 11, 3]
shifts = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]
shift_counter = 0
key_final = [13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 40, 51, 30, 36, 46,
             54, 29, 39, 50, 44, 32, 47, 43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31]
c = []
d = []


def encrypt(filename, key_input):  # 8-bit key
    global c, d, shift_counter

    shift_counter = 0

    pre_text = list(map(lambda x: [int(a) for a in bin(x)[2:].zfill(8)], open(filename, 'rb').read()))
    text = []
    for piece in pre_text:
        text.extend(piece)

    key = []
    if isinstance(key_input, int):  # key is given as an integer
        if (len(str(key_input))) != 8:
            print("USAGE: des.encrypt(filename, [64-bit key (8 digit) | key_filename])")
            return
        for sym in str(key_input):
            key.extend([int(d) for d in bin(ord(sym))[2:].zfill(8)])
    elif isinstance(key_input, str):  # key is given in a file
        pre_key = list(map(lambda x: [int(a) for a in bin(x)[2:].zfill(8)], open(key_input, 'rb').read()))
        for piece in pre_key:
            key.extend(piece)
    else:
        print("USAGE: des.encrypt(filename, [64-bit key (8 digit) | key_filename])")
        return

    for i in range(8):
        if sum(key[8 * i:8 * i + 8]) % 2 != 0:
            print("BAD KEY")
            return
            # key[8 * i + 7] ^= 1

    print("KEY: " + "".join(list(map(str, key))))

    key = perm(key, key_init_perm)
    c = key[:28]
    d = key[28:]
    text.extend([0 for i in range((64 - len(text)) % 64)])
    chunks = [text[i:i + 64] for i in range(0, len(text), 64)]
    keygen = next_key()
    for i in range(len(chunks)):
        chunks[i] = perm(chunks[i], ip)
    for i in range(16):
        round_key = next(keygen)
        for j in range(len(chunks)):
            chunks[j] = round(chunks[j], round_key)
    for i in range(len(chunks)):
        chunks[i] = perm(chunks[i], ip_rev)
    g = open(filename[:filename.rfind(".")] + ".des", "wb")
    for i in range(len(chunks)):
        g.write(bytes([byte(chunks[i][j:j + 8]) for j in range(0, 64, 8)]))
    g.close()
    print("ENCRYPTED to " + filename[:filename.rfind(".")] + ".des")


def reversed_round(ciphertext, round_key):
    l0 = ciphertext[:32]
    r0 = ciphertext[32:]
    p1 = perm(l0, expand)
    p2 = [[p1[j] ^ round_key[j] for j in range(i, i + 6)] for i in range(0, 48, 6)]
    after_s = []
    for i in range(8):
        after_s.extend(s_block(i, p2[i]))
    p3 = perm(after_s, p)
    return [p3[i] ^ r0[i] for i in range(32)] + l0


def decrypt(enc_filename, key_input):
    global c, d, shift_counter

    key = []
    if isinstance(key_input, int):  # key is given as an integer
        if (len(str(key_input))) != 8:
            print("USAGE: des.decrypt(filename, [64-bit key (8 digit) | key_filename])")
            return
        for sym in str(key_input):
            key.extend([int(d) for d in bin(ord(sym))[2:].zfill(8)])
    elif isinstance(key_input, str):  # key is given in a file
        try:
            pre_key = list(map(lambda x: [int(a) for a in bin(x)[2:].zfill(8)], open(key_input, 'rb').read()))
            for piece in pre_key:
                key.extend(piece)
        except:
            print("ENCRYPTED FILE NOT FOUND")
            return

    shift_counter = 0

    for i in range(8):
        if sum(key[8 * i:8 * i + 8]) % 2 != 0:
            print("BAD KEY")
            return
            # key[8 * i + 7] ^= 1

    print("KEY: " + "".join(list(map(str, key))))

    key = perm(key, key_init_perm)
    c = key[:28]
    d = key[28:]
    pre_ciphertext = list(map(lambda x: [int(a) for a in bin(x)[2:].zfill(8)], open(enc_filename, 'rb').read()))
    ciphertext = []
    for piece in pre_ciphertext:
        ciphertext.extend(piece)
    ciphertext.extend([0 for i in range((64 - len(ciphertext)) % 64)])
    chunks = [ciphertext[i:i + 64] for i in range(0, len(ciphertext), 64)]
    keygen = next_key()
    round_key = [0 for i in range(16)]
    for i in range(16):
        round_key[i] = next(keygen)
    for i in range(len(chunks)):
        chunks[i] = perm(chunks[i], ip)

    for j in range(len(chunks)):
        for i in range(16):
            chunks[j] = reversed_round(chunks[j], round_key[15 - i])
    for i in range(len(chunks)):
        chunks[i] = perm(chunks[i], ip_rev)
    g = open(enc_filename[:enc_filename.rfind(".")] + ".decoded", "wb")
    for i in range(len(chunks)):
        g.write(bytes([byte(chunks[i][j:j + 8]) for j in range(0, 64, 8)]))
    g.close()
    print("DECRYPTED to " + enc_filename[:enc_filename.rfind(".")] + ".decoded")
