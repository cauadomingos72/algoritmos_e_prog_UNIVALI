#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename Tipo>
struct elementoEnc{
    Tipo dado;
    elementoEnc <Tipo> *proximo;
};

template <typename Tipo>
struct listaEnc{
    elementoEnc <Tipo> *inicio;
};

template <typename Tipo>
bool iniciaListaEnc(listaEnc<Tipo> &lEnc){
    lEnc.inicio = NULL;
    return true;
}

template <typename Tipo>
int retornaTamanhoListaEnc(listaEnc<Tipo> &lEnc){
    int i=0;
    if(lEnc.inicio != NULL){
        i++;
        elementoEnc <Tipo> *nav = lEnc.inicio;
        while(nav->proximo!=NULL){
            nav = nav->proximo;
            i++;
        }
    }
    return i;
}

template <typename Tipo>
elementoEnc<Tipo> *novoElemento(Tipo dado){
    elementoEnc <Tipo> *novo = new elementoEnc<Tipo>;
    novo->dado = dado;
    novo->proximo = NULL;
};

template <typename Tipo>
bool insereFimListaEnc(listaEnc<Tipo> &lEnc, Tipo dado){
    elementoEnc <Tipo> *nav = lEnc.inicio;
    if(lEnc.inicio != NULL){
        while(nav->proximo!=NULL){
            nav = nav->proximo;
        }
        elementoEnc <Tipo> *novo = novoElemento(dado);
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        return true;
    }else{
        elementoEnc<Tipo> *novo = novoElemento(dado);
        novo->proximo = NULL;
        lEnc.inicio = novo;
        return true;
    }
}

template <typename Tipo>
bool removeFimListaEnc(listaEnc<Tipo> &lEnc){
    if(lEnc.inicio != NULL){
        elementoEnc <Tipo> *nav = lEnc.inicio;
        if(nav->proximo != NULL){
            elementoEnc <Tipo> *aux = lEnc.inicio;
            nav = nav->proximo;
            while(nav->proximo!=NULL){
                aux = nav;
                nav = nav->proximo;
            }
            aux->proximo = NULL;
            delete nav;
            return true;
        }else{
            lEnc.inicio = NULL;
            delete nav;
            return true;
        }
    }else{
        return false;
    }
}

template <typename Tipo>
bool insereInicioListaEnc(listaEnc<Tipo> &lEnc, Tipo dado){
    elementoEnc<Tipo> *novo = novoElemento(dado);
    novo->proximo = lEnc.inicio;
    lEnc.inicio = novo;
    return true;
}

template <typename Tipo>
bool removeInicioListaEnc(listaEnc<Tipo> &lEnc){
    if(lEnc.inicio != NULL){
        elementoEnc <Tipo> *aux = lEnc.inicio;
        lEnc.inicio = aux->proximo;
        delete aux;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo>
bool inserePosicaoListaEnc(listaEnc<Tipo> &lEnc, Tipo dado, int posicao){
    elementoEnc<Tipo> *novo = novoElemento(dado);
    if(posicao == 0){
        novo->proximo = lEnc.inicio;
        lEnc.inicio = novo;
        return true;
    }else{
        elementoEnc <Tipo> *nav = lEnc.inicio;
        for(int i=1; i<posicao && nav!=NULL; i++){
            nav = nav->proximo;
        }
        if(nav != NULL){
            novo->proximo = nav->proximo;
            nav->proximo = novo;
        }else{
            return false;
        }
    }
}

template <typename Tipo>
bool removePosicaoListaEnc(listaEnc<Tipo> &lEnc, int posicao){
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

template <typename Tipo, int MAX>
void bubblesort(listaEnc<Tipo> &lEnc){
    if(lEnc.inicio != NULL){
        Tipo temp;
        int cond=1;
        while(cond==1){
            cond = 0;
            elementoEnc <Tipo> *nav = lEnc.inicio;
            elementoEnc <Tipo> *aux = nav->proximo;
            while(aux!=NULL){
                elementoEnc <Tipo> *aux = nav->proximo;
                if(aux->dado < nav->dado){
                    temp = aux->dado;
                    aux->dado = nav->dado;
                    nav->dado = temp;
                    cond = 1;
                }
            }
        }
    }
}
