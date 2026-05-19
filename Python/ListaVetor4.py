# Exercicio 4

from random import randint

L = []
L_M = []

Multiple = int(input("Digite o numero divisor"))
for i in range(21):
    Num_Ran = randint(1, 100)
    L.append(Num_Ran)

    if Num_Ran % Multiple == 0:
        L_M.append(Num_Ran)

print(f"Total de Numeros: {L}")
print(f"Numeros Divisiveis por {Multiple}: {L_M}")
