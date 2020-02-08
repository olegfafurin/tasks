import sys, random as rn

if len(sys.argv) < 3:
    print("USAGE: python encrypt.py <filename> <length of permutation>")
    exit(1)

f = open(sys.argv[1]).read()
n = int(sys.argv[2])
if n > 2080:
    print("WARNING: length of permutation is too big")

g = open(sys.argv[1][:sys.argv[1].find(".")] + ".enc", "w+")

p = list(range(n))
rn.shuffle(p)

print(p)

for i in range(0, len(f), n):
    s = f[i:i+n]
    if len(s) == n:
        g.write("".join([s[p[i]] for i in range(n)]))
    else:
        s = s + " "*(n - len(s))
        g.write("".join(list(filter(lambda x: x != ' ', [s[p[i]] for i in range(n)]))))
