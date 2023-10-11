#include <iostream>
#include "Estruturas.h"

using namespace std;

//OPERAÇÕES BÁSICAS DA FILA

void criarFilaPVazia(TFilaP &f){
   f.frente = new TCelulaFila;
   f.tras = f.frente;
   f.frente->proximo = NULL;
}

bool estaVaziaFilaP(TFilaP f){
    return f.frente == f.tras;
}

void enfileirar(TFilaP &f, TItem x){
    f.tras->proximo = new TCelulaFila;
    f.tras = f.tras->proximo;
    f.tras->item = x;
    f.tras->proximo = NULL;
}

void mostrar(TFilaP f){
    TCelulaFila *celAux;
    celAux = f.frente->proximo;

    cout << "=== MOSTRANDO A FILA === "<< endl;
    if (estaVaziaFilaP(f)){
        cout << "Fila vazia! Nenhum elemento para mostrar!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else{
        while (celAux != NULL){
            cout << "Nome da Música:   " << celAux->item.nomeMusica << endl;
            cout <<     "   Artista:   " << celAux->item.nomeArtista << endl;

            celAux = celAux->proximo;
            cout << "-------------------------------------------" << endl;
        }
    }
}

void desenfileirar(TFilaP &f){
    if (estaVaziaFilaP(f)){
        cout << "Fila Vazia! Nenhum elemento para desenfileirar..." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else{
        TCelulaFila *aux = f.frente;
        f.frente = f.frente->proximo;
        delete(aux);
    }
}

//OPERAÇÕES BÁSICAS DA LISTA

void criarListaPVazia(TListaDP &lp){
    lp.primeiro = new TCelulaLista;
    lp.ultimo = lp.primeiro;
    lp.primeiro->anterior = NULL;
    lp.primeiro->proximo = NULL;
}

void inserirLista(TListaDP &lp, TItem x){
    lp.ultimo->proximo = new TCelulaLista;
    lp.ultimo->proximo->anterior = lp.ultimo;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
}

void mostrarED(TListaDP lp){
    TCelulaLista *celAux;
    celAux = lp.primeiro->proximo;

    cout << "=== MÚSICAS NA PLAYLIST === " << endl;
    while (celAux != NULL){
        cout << "  Música: " << celAux->item.nomeMusica << endl;
        cout << "    Artista: " << celAux->item.nomeArtista << endl;
        celAux = celAux->proximo;
    }
}
TCelulaLista *pegaAnterior(TListaDP lp, TItem musica){

   TCelulaLista *celAux;
   bool achou = false;

   celAux = lp.primeiro;

    while (celAux->proximo != NULL){
        if (celAux->proximo->item.nomeMusica == musica.nomeMusica){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(TListaDP &lp, TItem musica){
    TCelulaLista *p = pegaAnterior(lp,musica); //anterior
    TCelulaLista *q; //alvo

    q = p->proximo;
    p->proximo = q->proximo;

    delete(q);
    cout << "Música removida com sucesso." << endl;
}

//OPERAÇÕES BÁSICAS DA ÁRVORE

void criarArvoreBinVazia(TArvoreBin &a, string n){
    a.nomeArvore = n;
    a.contItens = 0;
    a.raiz = NULL;
}

void inserirArvore(TArvoreBin &a, TNo *&no, TItem i){
    if (no == NULL){ // CASO BASE/PARADA

        no = new TNo;

        no->item = i;
        no->esquerda = NULL;
        no->direita = NULL;
        a.contItens++;
        if (a.raiz == NULL){
            a.raiz = no;
        }
    }
    else{
        if (i.nomeMusica < no->item.nomeMusica){ // chamada recursiva ESQ
            inserirArvore(a,no->esquerda,i);
        }
        else{
            if (i.nomeMusica > no->item.nomeMusica){ // chamada recursiva DIR
                inserirArvore(a,no->direita,i);
            }
            else{
                if (i.nomeMusica == no->item.nomeMusica){
                    cout << "Não posso inserir. Item já existe!" << endl;
                 }
            }
        }

    }
}

void percorrerINOrdem(TNo *&no){
    if(no!=NULL){
        percorrerINOrdem(no->esquerda);
        cout << no->item.nomeMusica << ", " << endl;
        percorrerINOrdem(no->direita);
    }
}

void pesquisar(string c, TNo *&n){

        cout<< "Nome da Música que deseja procurar: ";
        cin >> c;


    if (n == NULL){

    }
    else {

        if (c < n->item.nomeMusica){

            pesquisar(c, n->esquerda);

        }
        else {
            if (c > n->item.nomeMusica){

                pesquisar(c, n->direita);
            }
            else{
                // aqui vc faz o que precisar!!!
                cout << "Música encontrada: " << n->item.nomeMusica << endl;
            }
        }
    }

}
