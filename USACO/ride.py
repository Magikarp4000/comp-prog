"""
ID: 1fishyb1
LANG: PYTHON3
TASK: ride
"""
fin = open('ride.in', 'r')
fout = open('ride.out', 'w')
alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
abc = {alph[i]:i+1 for i in range(26)}
a = fin.readline().strip()
b = fin.readline().strip()
ares, bres = 1, 1
for i in a:
  ares *= abc[i]
for i in b:
  bres *= abc[i]
if ares%47 == bres%47:
  fout.write("GO\n")
else:
  fout.write("STAY\n")
fout.close()