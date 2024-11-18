n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
l = 0
r = 0
z = [0] * (200001)
num = 0
ma = 0
resl = resr = 0
while r < n:
    z[a[r]] += 1
    num += z[a[r]] == 1
    while num > k:
        z[a[l]] -= 1
        num -= z[a[l]] == 0
        l += 1
    if r-l+1 > ma:
        ma = r-l+1
        resl = l+1
        resr = r+1
    r += 1
print(ma)
print(resl, resr)