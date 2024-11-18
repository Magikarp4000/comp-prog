"""
ID: 1fishyb1
LANG: PYTHON3
TASK: revegetate
"""
fin = open('revegetate.in', 'r')
fout = open('revegetate.out', 'w')
N, M = list(map(int, fin.readline().split()))
v = [[] for _ in range(N)]
for i in range(M):
  a, b = list(map(int, fin.readline().split()))
  a -= 1; b -= 1
  v[a].append(b)
  v[b].append(a)

for i in range(N):
  v[i].sort()
c = [0]*N
c[0] = 1
for i in range(N):
  cur = 1
  for u in v[i]:
    if c[u]: cur = max(cur, c[u]+1)
  c[i] = cur
for i in c:
  fout.write(i, end="")
