f = open("check.in")
g = open("check.out")
n, m = map(int, f.readline().split())
sets = []
for line in f.readlines():
  sets.append(set(map(int, line.split()[1:])))
sets.sort(key=len)
if sets[0] != set():
  print("NO")
  exit(0)
if sets[-1] != set(range(1, n + 1)))
  print("NO")
  exit(0)
