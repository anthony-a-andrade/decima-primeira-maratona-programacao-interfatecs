import math

ln2 = math.log(2)
e = math.e

No = int(input())
N = int(input())
t_half = int(input())

Y = ln2 / t_half
x = math.log(N / No) / math.log(e)
t = x / Y
print("%d" % (-t))