package Java;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class GerenciamentoDeTarefas {
    static List<String> Lista_Tarefas = new ArrayList<>();
    public static Scanner scanner = new Scanner(System.in);

    public static void AddTarefa(String tarefa) {
        Lista_Tarefas.add(tarefa);
    }

    public static void ListTarefa() {
        System.out.println(Lista_Tarefas);
    }

    public static void DeleteTarefa(String[] args) {
        DeleteTarefa(args);
    }

    public static void GerenciarTarefa() {
        int escolha;
        do {

        System.out.print(
                "Escolha o que voce quer fazer: \n 1 - Adicionar uma Tarefa \n 2 - Listar todas as Tarefas \n 3 - Deletar uma Tarefa \n 4 - Sair \n");
        escolha = scanner.nextInt();
        scanner.nextLine();

        switch (escolha) {
                case 1:
                    System.out.println("Adicione uma Tarefa: ");
                    String Tarefa = scanner.nextLine();
                    AddTarefa(Tarefa);
                    System.out.print("Tarefa adicionada com sucesso! \n");
                    break;
                case 2:
                    ListTarefa();
                    break;
                case 3:
                    DeleteTarefa(null);
                    break;
                case 4:
                    System.out.println("Saindo...");
                default:
                    System.out.println("Valor Invalido, Tente Novamente \n");
        }
    }  while (escolha != 4);
    }

    public static void main(String[] args) {


        GerenciarTarefa();

        System.out.print("Lista de Tarefas" + Lista_Tarefas);
        scanner.close();
    }

}
