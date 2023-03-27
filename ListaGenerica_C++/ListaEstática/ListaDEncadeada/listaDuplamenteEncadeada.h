#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename Tipo>
struct elementoDEnc{
    Tipo dado;
    elementoDEnc<Tipo> *proximo;
    elementoDEnc<Tipo> *anterior;
};

template <typename Tipo>
struct listaDEnc{
    elementoDEnc<Tipo> *inicio;
    elementoDEnc<Tipo> *fim;
    int total;
};

template <typename Tipo>
bool iniciaListaDEnc(listaDEnc<Tipo> &lDEnc){
    lDEnc.inicio = NULL;
    lDEnc.fim = NULL;
    lDEnc.total = 0;
    return true;
}

template <typename Tipo>
int retornaTamanhoListaDEnc(listaDEnc<Tipo> &lDEnc){
    return lDEnc.total;
}

template <typename Tipo>
elementoDEnc<Tipo> *novoElemento(Tipo dado){
    elementoDEnc<Tipo> *novo = new elementoDEnc<Tipo>;
    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = NULL;
};

template <typename Tipo>
bool insereFimListaDEnc(listaDEnc<Tipo> &lDEnc, Tipo dado){
    elementoDEnc <Tipo> *novo = novoElemento(dado);
    if(lDEnc.fim != NULL){
        elementoDEnc <Tipo> *aux = lDEnc.fim;
        aux->proximo = novo;
        novo->anterior = aux;
        lDEnc.fim = novo;
        lDEnc.total++;
        return true;
    }else{
        lDEnc.inicio = novo;
        lDEnc.fim = novo;
        lDEnc.total++;
        return true;
    }
}

template <typename Tipo>
bool removeFimListaDEnc(listaDEnc<Tipo> &lDEnc){
    if(lDEnc.fim != NULL){
        elementoDEnc <Tipo> *apagado = lDEnc.fim;
        elementoDEnc <Tipo> *aux = apagado->anterior;
        lDEnc.fim = aux;
        aux->proximo = NULL;
        lDEnc.total--;
        delete apagado;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo>
bool insereInicioListaDEnc(listaDEnc<Tipo> &lDEnc, Tipo dado){
    elementoDEnc <Tipo> *novo = novoElemento(dado);
    if(lDEnc.inicio != NULL){
        elementoDEnc <Tipo> *aux = lDEnc.inicio;
        lDEnc.inicio = novo;
        aux->anterior = novo;
        novo->proximo = aux;
        lDEnc.total++;
        return true;
    }else{
        lDEnc.inicio = novo;
        lDEnc.fim = novo;
        lDEnc.total++;
        return true;
    }
}

template <typename Tipo>
bool removeInicioListaDEnc(listaDEnc<Tipo> &lDEnc){
    if(lDEnc.inicio != NULL){
        elementoDEnc <Tipo> *apagado = lDEnc.inicio;
        elementoDEnc <Tipo> *aux = apagado->proximo;
        lDEnc.inicio = aux;
        aux->anterior = NULL;
        lDEnc.total--;
        delete apagado;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo>
bool inserePosicaoListaDEncCI(listaDEnc<Tipo> &lDEnc, Tipo dado, int posicao){
    if(posicao > lDEnc.total){
        return false;
    }else{
        elementoEnc<Tipo> *novo = novoElemento(dado);
        if(posicao == 0){
            elementoDEnc <Tipo> *aux = lDEnc.inicio;
            lDEnc.inicio = novo;
            aux->anterior = novo;
            novo->proximo = aux;
        }
        if(posicao == lDEnc.total){
            elementoDEnc <Tipo> *aux = lDEnc.fim;
            aux->proximo = novo;
            novo->anterior = aux;
            lDEnc.fim = novo;
        }
        if(posicao<=lDEnc.total/2){
            elementoEnc <Tipo> *nav = lEnc.inicio;
            for(int i=1; i<posicao; i++){
                nav = nav->proximo;
            }
            novo->proximo = nav->proximo;
            novo->anterior = nav;
            nav->proximo = novo;
            nav = novo->proximo;
            nav->anterior = novo;
        }else{
            elementoEnc <Tipo> *nav = lEnc.fim;
            for(int i=lDEnc.total; i>posicao; i--){
                nav = nav->anterior;
            }
            novo->anterior = nav->anterior;
            nav->anterior = novo;
            novo->proximo = nav;
            nav = novo->anterior;
            nav->proximo = novo;
        }
        lDEnc.total++;
        return true;
    }
}

template <typename Tipo>
bool removePosicaoListaDEnc(listaDEnc<Tipo> &lDEnc, int posicao){

    elementoEnc <Tipo> *nav = lEnc.inicio;
    if(lEnc.inicio != NULL){
        elementoEnc <Tipo> *aux = lEnc.inicio;
        for(int i=1; i<posicao && nav!=NULL; i++){
            aux = nav;
            nav = nav->proximo;
        }
        aux->proximo = nav->proximo;
        delete nav;
        return true;
    }else{
        return false;
    }

}
