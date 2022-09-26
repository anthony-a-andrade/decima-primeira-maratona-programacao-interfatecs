def golden(atual, de, ate):
    if de + 1 == ate: return 2
    return 1 + (golden(atual, de + 1, ate) ** -1)

N = int(input())
print("%.15f" % golden(1, 0, N))