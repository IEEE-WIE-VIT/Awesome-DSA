from collections import deque


def palindrome(s):
    d = deque()
    for i in s:
        d.append(i)

    while len(d) > 1:
        if d.popleft() != d.pop():
            return 'NO'
    return('YES')


s = 'abcba'
print(palindrome(s))
