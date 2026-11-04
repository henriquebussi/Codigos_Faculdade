#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *mother;
    struct Person *father;
    struct Person *sibling;
} Person;

Person* createNode(const char *name, int age) {
    Person *p = (Person*)malloc(sizeof(Person));
    if (!p) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    strncpy(p->name, name, sizeof(p->name) - 1);
    p->name[sizeof(p->name) - 1] = '\0';
    p->age = age;
    p->mother = NULL;
    p->father = NULL;
    p->sibling = NULL;
    return p;
}

void setFather(Person *child, Person *father) {
    if (!child) return;
    child->father = father;
}

void setMother(Person *child, Person *mother) {
    if (!child) return;
    child->mother = mother;
}

void addSibling(Person *root, Person *bro) {
    if (!root) return;
    if (!root->sibling) {
        root->sibling = bro;
    } else {
        Person *cur = root->sibling;
        while (cur->sibling) cur = cur->sibling;
        cur->sibling = bro;
    }
}

void printTree(const Person *node, int depth, int isRight) {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        if (i == depth - 1) {
            printf(isRight ? "|-" : "|_");
        } else {
            printf("   ");
        }
    }
    printf("%s (idade:%d)\n", node->name, node->age);

    printTree(node->mother, depth + 1, 0);
    printTree(node->father, depth + 1, 1);
}

void printSiblings(const Person *root) {
    if (!root || !root->sibling) return;
    const Person *cur = root->sibling;
    int idx = 1;
    while (cur) {
        printf("Irmao %d: %s (idade:%d)\n", idx, cur->name, cur->age);
        cur = cur->sibling;
        idx++;
    }
}

void freeTree(Person *node) {
    if (!node) return;
    freeTree(node->mother);
    freeTree(node->father);

    Person *cur = node->sibling;
    while (cur) {
        Person *next = cur->sibling;
        free(cur);
        cur = next;
    }
    free(node);
}

void readPersonData(char *nameBuf, int *ageBuf) {
    printf("Nome: ");
    scanf(" %49[^\n]", nameBuf);
    printf("Idade: ");
    scanf("%d", ageBuf);
}

int main(void) {
    char name[50];
    int age;

    printf("== Cadastro da pessoa principal ==\n");
    readPersonData(name, &age);
    Person *root = createNode(name, age);

    int option = 0;
    while (option != 5) {
        printf("\n== MENU ==\n");
        printf("1 - Cadastrar Pai\n");
        printf("2 - Cadastrar Mae\n");
        printf("3 - Cadastrar Irmao\n");
        printf("4 - Listar Arvore\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                char pName[50];
                int pAge;
                printf("\nCadastro do Pai\n");
                readPersonData(pName, &pAge);
                Person *father = createNode(pName, pAge);
                setFather(root, father);
                printf("Pai cadastrado com sucesso!\n");
                break;
            }
            case 2: {
                char mName[50];
                int mAge;
                printf("\nCadastro da Mae\n");
                readPersonData(mName, &mAge);
                Person *mother = createNode(mName, mAge);
                setMother(root, mother);
                printf("Mae cadastrada com sucesso!\n");
                break;
            }
            case 3: {
                char bName[50];
                int bAge;
                printf("\nCadastro de irmao\n");
                readPersonData(bName, &bAge);
                Person *bro = createNode(bName, bAge);
                addSibling(root, bro);
                printf("Irmao cadastrado com sucesso!\n");
                break;
            }
            case 4: {
                printf("\nArvore Geral\n");
                printTree(root, 0, 0);
                printf("\nIrmaos:\n");
                printSiblings(root);
                break;
            }
            case 5:
                printf("Encerrando o sistema\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }
    freeTree(root);
    return 0;
}