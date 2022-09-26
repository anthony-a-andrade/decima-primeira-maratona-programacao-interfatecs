N = int(input())
for n in range(N):
    entrada = [int(x) for x in input().split(' ')]
    maior = entrada[0] * entrada[1]
    if maior % 2 == 0: print("[:=[primeiro]")
    else: print("[segundo]=:]")