#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

using namespace std;

struct TItem{
    string nomeMusica;
    string nomeArtista;
};
//Célula da fila

struct TCelulaFila{
    TItem item;
    TCelulaFila *proximo;
};

//Célula da Lista

struct TCelulaLista{
    TCelulaLista *anterior;
    TItem item;
    TCelulaLista *proximo;
};

struct TFilaP{
    TCelulaFila *frente;
    TCelulaFila *tras;
};

struct TListaDP{
    TCelulaLista *primeiro;
    TCelulaLista *ultimo;
};

//ESTRUTURAS DA ÁRVORE

struct TNo{
    TItem item;
    TNo *esquerda;
    TNo *direita;
};

struct TArvoreBin{
    string nomeArvore;
    int contItens;
    TNo *raiz;
};


// OPERAÇÕES BÁSICAS DA FILA

void criarFilaPVazia(TFilaP &f);

bool estaVaziaFilaP(TFilaP f);

void enfileirar(TFilaP &f, TItem x);

void mostrar(TFilaP f);

void desenfileirar(TFilaP &f);

//OPERAÇÕES BÁSICAS DA LISTA

void criarListaPVazia(TListaDP &lp);

void inserirLista(TListaDP &lp, TItem x);

void mostrarED(TListaDP lp);

TCelulaLista *pegaAnterior(TListaDP lp, TItem musica);

void retirarPorChave(TListaDP &lp, TItem musica);

//OPERAÇÕES BÁSICAS DA ÁRVORE

void criarArvoreBinVazia(TArvoreBin &a, string n);

void inserirArvore(TArvoreBin &a, TNo *&no, TItem i);

void percorrerINOrdem(TNo *&no);

void pesquisar(string c, TNo *&n);







#endif // ESTRUTURAS_H_INCLUDED
