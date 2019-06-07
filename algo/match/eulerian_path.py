def eul(v):
    for end in c[v - 1]:
        c[end - 1].remove(v)
        c[v - 1].remove(end)
        eul(end)
    l.append(v)


l = []
n = int(input())
c = [[] for i in range(n)]
for i in range(n):
    c[i] = list(map(int, input().split()))[1:]
# if map(lambda x : len(x) % 2, c).count(1)
eul(1)
print(len(l) - 1)
print(" ".join(map(str, l)))