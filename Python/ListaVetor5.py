from random import randint

option = int(input("Escolha entre (1) - Ordem Normal, (2) - Ordem Inversa"))

Vetor = []

for i in range(10):
    num_ran = randint(1, 50)
    Vetor.append(num_ran)

print(Vetor)

if option == 1:
    for i in range(0, len(Vetor) + 1):
        print(Vetor[i], end=",")
else:
    for i in range(len(Vetor) - 1, -1, -1):
        print(Vetor[i], end=",")
