# print("hello world")
#
# a = 1
# b = 2
# c = None
#
# print(f"A: {a}, B: {b}")
#
# a, b = b, a
# print(f"A: {a}, B: {b}")
#
#
# # dias = int(input("dias: "))
# # horas = int(input("horas: "))
# # minutos = int(input("minutos: "))
# # segundos = int(input("segundos: "))
#
# # print(f"tem {segundos+(minutos*60)+(horas*3600)+(dias*86400)} segundos")
#
# preco_litro = int(input("Preço do Combustivel: "))
# desemprenho_carro = int(input("Desempenho do Veiculo(km/l): "))
# distancia = int(input("Distancia entre duas cidades: "))
#
# print(preco_litro * (distancia / desemprenho_carro))
#
# salario = float(input("Salario: "))
# reajuste = float(input("Reajuste: "))
# print(salario + (salario * (reajuste / 100)))
#
#
# amigo = input("Qual é seu nome? ")
# print(amigo)
# while True:
#     try:
#         nome = str(input("Qual é o seu nome: "))
#         telefone = int(input("Qual é o seu telefone: "))
#         rua = str(input("Qual é a sua rua?"))
#         print(f"{nome}, {telefone}, {rua}")
#         break
#     except ValueError:
#         print("Isso não faz sentido, tente novamente")
#

for i in range(0, 10, 3):
    print(i)

for i in range(100, 10, -2):
    print(i)


nome = input("Qual é o seu nome? ")
n = int(input("Quantas vezes repetir? "))

for i in range(n):
    print(nome)

n = 0
for i in range(1, 100, 1):
    print(n)
    n = n + i

somaPar = 0
somaImpar = 0

for i in range(1, 100, 1):
    if i % 2 == 0:
        somaPar = somaPar + i
    else:
        somaImpar = somaImpar + i
print(f"Soma de Pares: {somaPar}, Soma de Impares: {somaImpar}")

firstN = int(input("Primeiro Numero: "))
lastN = int(input("Ultimo Numero: "))
divis = int(input("Divisivel por quanto? "))

for i in range(firstN, lastN, 1):
    if i % divis == 0:
        print(i)
