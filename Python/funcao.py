def soma(v1, v2):
    print(v1 + v2)


def sub(v1, v2):
    print(v1 - v2)


def mult(v1, v2):
    print(v1 * v2)


def div(v1, v2):
    print(v1 / v2)


print("Bem vindo a Minha calculadora!")
while True:
    escolha = int(
        input(
            "\n Escolha uma operação: \n 1 - Soma \n 2 - Subtração \n 3 - Multiplicação \n 4 - Divisão \n 5 - Sair \n"
        )
    )
    if escolha == 5:
        break

    num1 = float(input("Escolha o Primeiro Numero: "))
    num2 = float(input("Escolha o Segundo Numero: "))
    match escolha:
        case 1:
            soma(num1, num2)
        case 2:
            sub(num1, num2)
        case 3:
            mult(num1, num2)
        case 4:
            div(num1, num2)
        case _:
            print("Invalido \n")
