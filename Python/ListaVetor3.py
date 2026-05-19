from random import randint

Lista = []

for i in range(20):
    Num_Ran = randint(1, 50)
    Lista.append(Num_Ran)

print(f"Lista: {Lista}")

for i in range(0, len(Lista), +1):
    if Lista[i] % 5 == 0:
        print(Lista[i], end=",")
