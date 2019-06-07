import random, itertools as it
f = open('test.in', 'w')
n = random.choice(range(10))
f.write(str(n) + '\n')
for i in range(1,n + 1):
  m = random.choice(range(n))
  f.write(str(m) + ' ')
  f.write(" ".join(random.choices(list(map(str, list(it.chain(range(1,i),range(i + 2, n + 1))))), k = m)) + '\n')
f.close()  