#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100
#define TAM_TEXTO 50

void cadastrarTarefa(char tarefas[][4][TAM_TEXTO], int *quantidade) {
    if (*quantidade >= MAX_TAREFAS) {
        printf("\nLimite de tarefas alcançado!\n");
        return;
    }

    printf("\nDigite o título da tarefa: ");
    getchar();
    fgets(tarefas[*quantidade][0], TAM_TEXTO, stdin);
    tarefas[*quantidade][0][strcspn(tarefas[*quantidade][0], "\n")] = '\0';

    printf("Digite a descrição da tarefa: ");
    fgets(tarefas[*quantidade][1], TAM_TEXTO, stdin);
    tarefas[*quantidade][1][strcspn(tarefas[*quantidade][1], "\n")] = '\0';

    printf("Digite a prioridade da tarefa (Alta, Média, Baixa): ");
    fgets(tarefas[*quantidade][2], TAM_TEXTO, stdin);
    tarefas[*quantidade][2][strcspn(tarefas[*quantidade][2], "\n")] = '\0';

    printf("Digite o status da tarefa (Pendente, Concluído): ");
    fgets(tarefas[*quantidade][3], TAM_TEXTO, stdin);
    tarefas[*quantidade][3][strcspn(tarefas[*quantidade][3], "\n")] = '\0';

    (*quantidade)++;
    printf("\nTarefa cadastrada com sucesso!\n");
}

void listarTarefas(char tarefas[][4][TAM_TEXTO], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\n=== Lista de Tarefas ===\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nTarefa %d:\n", i + 1);
        printf("Título: %s\n", tarefas[i][0]);
        printf("Descrição: %s\n", tarefas[i][1]);
        printf("Prioridade: %s\n", tarefas[i][2]);
        printf("Status: %s\n", tarefas[i][3]);
    }
}

void editarTarefa(char tarefas[][4][TAM_TEXTO], int indice, int quantidade) {
    if (indice < 0 || indice >= quantidade) {
        printf("\nTarefa não encontrada.\n");
        return;
    }

    printf("\nEditando a tarefa %d:\n", indice + 1);

    printf("Digite o novo título: ");
    getchar();
    fgets(tarefas[indice][0], TAM_TEXTO, stdin);
    tarefas[indice][0][strcspn(tarefas[indice][0], "\n")] = '\0';

    printf("Digite a nova descrição: ");
    fgets(tarefas[indice][1], TAM_TEXTO, stdin);
    tarefas[indice][1][strcspn(tarefas[indice][1], "\n")] = '\0';

    printf("Digite a nova prioridade: ");
    fgets(tarefas[indice][2], TAM_TEXTO, stdin);
    tarefas[indice][2][strcspn(tarefas[indice][2], "\n")] = '\0';

    printf("Digite o novo status: ");
    fgets(tarefas[indice][3], TAM_TEXTO, stdin);
    tarefas[indice][3][strcspn(tarefas[indice][3], "\n")] = '\0';

    printf("\nTarefa editada com sucesso!\n");
}

void excluirTarefa(char tarefas[][4][TAM_TEXTO], int *quantidade, int indice) {
    if (indice < 0 || indice >= *quantidade) {
        printf("\nTarefa não encontrada.\n");
        return;
    }

    for (int i = indice; i < *quantidade - 1; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(tarefas[i][j], tarefas[i + 1][j]);
        }
    }

    (*quantidade)--;
    printf("\nTarefa excluída com sucesso!\n");
}

void salvarTarefasEmArquivo(char tarefas[][4][TAM_TEXTO], int quantidade) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (!arquivo) {
        printf("\nErro ao criar o arquivo!\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Tarefa %d:\n", i + 1);
        fprintf(arquivo, "Título: %s\n", tarefas[i][0]);
        fprintf(arquivo, "Descrição: %s\n", tarefas[i][1]);
        fprintf(arquivo, "Prioridade: %s\n", tarefas[i][2]);
        fprintf(arquivo, "Status: %s\n\n", tarefas[i][3]);
    }

    fclose(arquivo);
    printf("\nTarefas salvas em 'tarefas.txt' com sucesso!\n");
}

int main() {
    char tarefas[MAX_TAREFAS][4][TAM_TEXTO];
    int quantidade = 0;
    int opcao, indice;

    do {
        printf("\n=== Sistema de Gerenciamento de Tarefas ===\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Editar Tarefa\n");
        printf("4. Excluir Tarefa\n");
        printf("5. Salvar Tarefas em Arquivo\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &quantidade);
                break;
            case 2:
                listarTarefas(tarefas, quantidade);
                break;
            case 3:
                printf("\nDigite o índice da tarefa a ser editada: ");
                scanf("%d", &indice);
                editarTarefa(tarefas, indice - 1, quantidade);
                break;
            case 4:
                printf("\nDigite o índice da tarefa a ser excluída: ");
                scanf("%d", &indice);
                excluirTarefa(tarefas, &quantidade, indice - 1);
                break;
            case 5:
                salvarTarefasEmArquivo(tarefas, quantidade);
                break;
            case 6:
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}