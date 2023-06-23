#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Lista {
    No* inicio;
    No* fim;
} Lista;

void inicializar(Lista* l);
void inserir_inicio(Lista* l, int valor);
void inserir_fim(Lista* l, int valor);
void inserir_posicao(Lista* l, int valor, int posicao);
void ordenar_lista(Lista* l);
void inserir_em_ordem(Lista* l, int valor);
void exibir_lista(Lista* l);
void exibir_lista_reversa(Lista* l);
void exibir_no_reverso(No* atual);
void remover_inicio(Lista* l);
void remover_fim(Lista* l);
void remover_posicao(Lista* l, int posicao);
void remover_valor(Lista* l, int valor);
int procurar(Lista* l, int valor);
int calcular_somatorio(Lista* l);
int obter_tamanho(Lista* l);
void elevar_ao_quadrado(Lista* l);
void liberar_lista(Lista* l);

#endif
