import random

M4 = []

for i in range(3):
    M4.append([])
    for j in range(3):
        M4[i].append(random.randint(0, 50))
print(f"M4: {M4}")

# Exercicio 1
soma = 0
for i in range(3):
    soma = soma + M4[i][i]

# Exercicio 2
variavel = 0
soma2 = 0
for i in range(3):
    variavel = variavel - 1
    soma2 = soma2 + M4[i][variavel]

print(f"Soma dos Elementos da Diagonal Principal:{soma}, e Diagonal Secundaria{soma2}")

#
soma3 = 0
v2 = 0

for i in range(3):
    produto = 1
    for j in range(3):
        produto *= M4[j][(i + j) % 3]
    soma3 += produto

for i in range(3):
    produto = 1
    for j in range(3):
        produto *= M4[j][(i - j) % 3]
    v2 += produto

determinante = soma3 - v2

print(f"Soma das diagonais principais: {soma3}")
print(f"Soma das diagonais secundárias: {v2}")
print(f"O determinante da matriz M4 é: {determinante}")
