import sys

input = sys.stdin.readline


def main():
    A, B, C, D = map(int, input().split())

    while True:
        C -= B
        if C <= 0:
            ans = "Yes"
            break
        A -= D
        if A <= 0:
            ans = "No"
            break

    print(ans)


if __name__ == "__main__":
    main()
