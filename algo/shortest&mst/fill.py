f = open('ford.in', 'w')
n = 2000
f.write(str(n) + ' ' + str(n+1) + ' 1\n')
for i in range(1,n+1):
  f.write(str(i) + ' ' + str((i % n) + 1) + ' -1000000000000000\n')