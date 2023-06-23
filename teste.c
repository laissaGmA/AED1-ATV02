#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

void exibirMenu() {
    printf("Selecione uma opcao:\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no fim\n");
    printf("3. Inserir em uma posicao\n");
    printf("4. Ordenar a lista\n");
    printf("5. Inserir em ordem\n");
    printf("6. Exibir lista\n");
    printf("7. Exibir lista reversa\n");
    printf("8. Remover do inicio\n");
    printf("9. Remover do fim\n");
    printf("10. Remover de uma posicao\n");
    printf("11. Remover por valor\n");
    printf("12. Procurar valor na lista\n");
    printf("13. Calcular somatorio\n");
    printf("14. Obter tamanho da lista\n");
    printf("15. Elevar lista ao quadrado\n");
    printf("Opcao: ");
}

int main() {
    Lista l1;
    inicializar(&l1);

    int valor, posicao, opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inserir_inicio(&l1, valor);
                printf("Valor inserido no inicio da lista.\n");
                break;

            case 2:
                printf("Digite o valor a ser inserido no fim: ");
                scanf("%d", &valor);
                inserir_fim(&l1, valor);
                printf("Valor inserido no fim da lista.\n");
                break;

            case 3:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                inserir_posicao(&l1, valor, posicao);
                printf("Valor inserido na posicao %d da lista.\n", posicao);
                break;

            case 4:
                ordenar_lista(&l1);
                printf("Lista ordenada.\n");
                break;

            case 5:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir_em_ordem(&l1, valor);
                printf("Valor inserido na lista em ordem.\n");
                break;

            case 6:
                printf("Lista:\n");
                exibir_lista(&l1);
                break;

            case 7:
                printf("Lista reversa:\n");
                exibir_lista_reversa(&l1);
                printf("\n");
                break;

            case 8:
                remover_inicio(&l1);
                printf("Elemento removido do inicio da lista.\n");
                break;

            case 9:
                remover_fim(&l1);
                printf("Elemento removido do fim da lista.\n");
                break;

            case 10:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                remover_posicao(&l1, posicao);
                printf("Elemento removido da posicao %d da lista.\n", posicao);
                break;

            case 11:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover_valor(&l1, valor);
                printf("Valor %d removido da lista.\n", valor);
                break;

            case 12:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                if (procurar(&l1, valor)) {
                    printf("O valor %d foi encontrado na lista.\n", valor);
                } else {
                    printf("O valor %d nao foi encontrado na lista.\n", valor);
                }
                break;

            case 13:
                printf("Somatorio dos valores da lista: %d\n", calcular_somatorio(&l1));
                break;

            case 14:
                printf("Tamanho da lista: %d\n", obter_tamanho(&l1));
                break;

            case 15:
                elevar_ao_quadrado(&l1);
                printf("Lista elevada ao quadrado.\n");
                break;

            default:
                printf("Opcao invalida. Digite novamente.\n");
        }

        printf("\n");

    } while (opcao != 0);

    liberar_lista(&l1);
    return 0;
}
