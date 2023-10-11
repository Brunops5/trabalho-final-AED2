#ifndef ESPECIFICAS_H_INCLUDED
#define ESPECIFICAS_H_INCLUDED

using namespace std;

void transferirMusica(TFilaP &f, TListaDP &l, TItem musica);

void adcionarMusica(TFilaP &f, TItem musica);

void mostrarMusicaTocando(TListaDP lp,TArvoreBin &arv, TNo *&no, TItem item);

void removerMusica(TListaDP &lp);

void menu();




#endif // ESPECIFICAS_H_INCLUDED
