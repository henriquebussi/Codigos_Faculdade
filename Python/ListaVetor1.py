from random import randint

Lista = []
Lista_Par = []
Lista_Impar = []

for i in range(11):
    Num_Ran = randint(1, 50)
    Lista.append(Num_Ran)

    if Num_Ran % 2 == 0:
        Lista_Par.append(Num_Ran)
    else:
        Lista_Impar.append(Num_Ran)
print(f"Lista: {Lista}")
print(f"Lista de Pares: {Lista_Par}")
print(f"Lista de Impares: {Lista_Impar}")
