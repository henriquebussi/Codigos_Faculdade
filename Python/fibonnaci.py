n = int(input("Me fale um numero inteiro: "))
n1 = 1
n2 = 1

print(n1, n2)
if n <= 2:
    print()
else:
    for i in range(3, n + 1, 1):
        res = n1 + n2
        print(res)
        n1 = n2
        n2 = res

list = [1, 2, 3, 4, 5]
print(list[-1])
