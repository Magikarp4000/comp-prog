n = int(input())
a = list(map(int, input().split()))
a.sort()
print(1 if n == 1 else 361 - max([(a[i]-a[i-1]+360)%360 for i in range(n)]))