alfa = "-abcdefghijklmnopqrstuvwxyz."

while True:
    entrada = input().split(' ')
    if entrada[0] == '0': break

    k = int(entrada[0])
    cifra = entrada[1]
    n = len(cifra)

    indexes_cifra = [alfa.index(x) for x in cifra]
    indexes_codigo = [0 for x in range(n)]

    for i in range(n):
        ki_n = (k * i) % n
        indexes_codigo[ki_n] = (indexes_cifra[i] + i) % 28

    print("".join([alfa[x] for x in indexes_codigo]))