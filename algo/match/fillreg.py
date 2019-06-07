import random, itertools as it
f = open("possreg.in", 'w')
n = random.choice(range(1,41))
f.write(str(n) + '\n')
for first in range(n):
  for second in range(n):
    f.write(str(second + 1) + ' ')
  f.write("\n")
for i in range(n):
  f.write(str(i + 1) + ' ')
f.close()