Renda = float(input("Insira sua Renda: "))
Score = int(input("Insira seu Score: "))
ValorParcela = float(input("Insira o Valor da Parcela: "))


def ParcelaSobreRenda(porcentagem):
    limite = Renda * porcentagem
    if ValorParcela > limite:
        print("Crédito Negado")
    elif ValorParcela <= limite:
        if porcentagem == 0.40:
            print("Crédito Aprovado Premium")
        else:
            print("Crédito Aprovado")


if Score < 300:
    print("Crédito Negado")
elif Score <= 500:
    ParcelaSobreRenda(0.15)
elif Score <= 700:
    ParcelaSobreRenda(0.30)
elif Score > 700:
    ParcelaSobreRenda(0.40)
else:
    print("Algo deu errado")
