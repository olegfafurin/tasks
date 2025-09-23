def compareVersion(self, version1: str, version2: str) -> int:
    a = list(map(int, version1.split('.')))
    b = list(map(int, version2.split('.')))
    n = len(a)
    m = len(b)
    for i in range(max(n,m)):
        lhs = a[i] if i < n else 0
        rhs = b[i] if i < m else 0
        if lhs < rhs:
            return -1
        elif rhs < lhs:
            return 1
    return 0


def main():
    version1 = input()
    version2 = input()
    print(compareVersion(version1, version2))


if __name__ == '__main__':
    main()