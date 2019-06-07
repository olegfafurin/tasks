import random as rn
import sys

letters = list(map(chr, range(97, 123)))
s = [rn.choice(letters) for i in range(int(sys.argv[1]))]
print("".join(s))