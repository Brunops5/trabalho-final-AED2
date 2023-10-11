#include <iostream>
#include "Estruturas.h"
#include "Especificas.h"


using namespace std;

void transferirMusica(TFilaP &f, TListaDP &lp, TItem musica )
{
    TCelulaFila *celAux;
    celAux = f.frente->proximo;

    if (estaVaziaFilaP(f))
    {
        cout << "Fila vazia! Nenhuma m�sica para  tocar!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        while (celAux != NULL)
        {
            musica.nomeArtista = celAux->item.nomeArtista;
            musica.nomeMusica = celAux->item.nomeMusica;
            inserirLista(lp, musica);
            desenfileirar(f);
            celAux = celAux->proximo;
        }
    }
}

void adcionarMusica(TFilaP &f, TItem musica)
{

    char resp = 'S';

    while (resp != 'N')
    {
        cout << "============================== " << endl;
        cout << "   Digite o nome da m�sica: ";
        cin >> musica.nomeMusica;
        cout << "   Digite o artista: ";
        cin >> musica.nomeArtista;
        enfileirar(f, musica);
        cout << "   Deseja cadastrar outro item? (S/N): ";
        cin >> resp;
    }
}

void mostrarMusicaTocando(TListaDP lp,TArvoreBin &arv, TNo *&no, TItem item)
{
    string aux3 = "S";
    string aux2 = "N";
    string aux = "N";
    TCelulaLista *celAux;
    celAux = lp.primeiro -> proximo;

    cout << "Musica tocada no momento: " << celAux ->item.nomeMusica << endl;
    cout << "Deseja trocar de musica? (S/N)";
    cin >> aux;
    while(aux3 == "S"){
        if(aux == "S")
        {

            cout << "Deseja ir para a m�sica anterior ou para a pr�xima?(A/P) ";
            cin >> aux2;
            if(aux2 == "P")
            {
                cout << "Musica trocada" << endl;
                inserirArvore(arv, arv.raiz, celAux->item);
                celAux = celAux->proximo;

                cout << "Musica tocada no momento: " << celAux ->item.nomeMusica << endl;

            }
            else
            {
                if(celAux->anterior->anterior == NULL)
                {
                    cout << "Esta � a primeira m�sica da fila. N�o possue anterior." << endl;
                    cout << "Musica tocada no momento: " << celAux ->item.nomeMusica << endl;
                }
                else
                {
                    cout << "Musica trocada" << endl;
                    inserirArvore(arv, arv.raiz, celAux->item);
                    celAux = celAux->anterior;

                    cout << "Musica tocada no momento: " << celAux ->item.nomeMusica << endl;

                }

            }
        }
        else
        {
            cout << "Musica continua" << endl;

        }
        cout << "Deseja continuar reproduzindo? (S/N) ";
        cin >> aux3;
    }


}

void removerMusica(TListaDP &lp, TItem musica){
    cout << "Digite o nome da m�sica que deseja remover: ";
    cin >> musica.nomeMusica;
    retirarPorChave(lp, musica);
}

void menu(){
    string c;
    TListaDP lista;
    TFilaP fila;
    TArvoreBin arv;
    TItem musica;
    criarFilaPVazia(fila);
    criarListaPVazia(lista);
    criarArvoreBinVazia(arv,"SpotifyUniversit�rio");

    while(true){
        int opt;
            cout << "****-SPOTIFY UNIVERSIT�RIO-****" << endl;
            cout<<" ________________________________________ "<<endl;
            cout<<"| 1 | Adcionar M�sica                    |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 2 | Transferir M�sicas para a Playlist |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 3 | Mostrar Playlist                   |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 4 | Tocar M�sicas                      |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 5 | Buscar M�sica                      |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 6 | Mostrar �rvore de M�sicas          |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 7 | Remover M�sica da Playlist         |"<<endl;
            cout<<"|_|______________________________________|"<<endl;
            cout<<"| 8 | Sair                               |"<<endl;
            cout<<"|_|______________________________________|"<<endl;

            cout << "Digite o numero da op��o: ";
            cin >> opt;

        switch(opt){
            case 1:
                adcionarMusica(fila, musica);
                break;

            case 2:
               transferirMusica(fila, lista, musica );
                break;

            case 3:
               mostrarED(lista);
                break;
            case 4:
                mostrarMusicaTocando(lista,arv, arv.raiz, musica);
                break;

            case 5:
                pesquisar(c, arv.raiz);
                break;

            case 6:
                percorrerINOrdem(arv.raiz);

            case 7:
                removerMusica(lista,musica);
                break;
            case 8:
                return;
                break;
        }
    }
}




