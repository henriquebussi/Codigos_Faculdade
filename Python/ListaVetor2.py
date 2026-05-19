from random import randint

Lista = []
media = 0

for i in range(20):
    Num_Ran = randint(1, 50)
    Lista.append(Num_Ran)

    if Num_Ran % 2 == 0:
        media = media + Num_Ran

media = media / 20

print(f"Lista: {Lista}")
print(f"Media dos pares: {media}")
