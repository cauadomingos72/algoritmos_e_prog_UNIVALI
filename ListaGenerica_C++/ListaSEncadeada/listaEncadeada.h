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
    if(lEnc.inicio != NULL){
        int i=1;
        elementoEnc <Tipo> *nav = lEnc.inicio;
        while(nav!=NULL){
            nav = nav->proximo;
            i++;
        }
        return i;
    }else{
        return 0;
    }
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
    if(posicao == 1){
        novo->proximo = lEnc.inicio;
        lEnc.inicio = novo;
        return true;
    }else{
        elementoEnc <Tipo> *nav = lEnc.inicio;
        for(int i=2; i<posicao && nav!=NULL; i++){
            nav = nav->proximo;
        }
        if(nav != NULL){
            novo->proximo = nav->proximo;
            nav->proximo = novo;
            return true;
        }else{
            return false;
        }
    }
    return false;
}

template <typename Tipo>
bool removePosicaoListaEnc(listaEnc<Tipo> &lEnc, int posicao){
    if(lEnc.inicio != NULL && posicao > 0){
        elementoEnc <Tipo> *aux = lEnc.inicio;
        elementoEnc <Tipo> *nav = aux->proximo;
        if(posicao == 1){
            lEnc.inicio = nav;
            delete aux;
            return true;
        }else{
            for(int i=2; i<posicao && nav!=NULL; i++){
                aux = nav;
                nav = nav->proximo;
            }
            aux->proximo = nav->proximo;
            delete nav;
            return true;
        }
    }else{
        return false;
    }
}

template <typename Tipo>
void bubblesort(listaEnc<Tipo> &lEnc){
    if(lEnc.inicio != NULL){
        Tipo temp;
        elementoEnc <Tipo> *nav = lEnc.inicio;
        elementoEnc <Tipo> *aux = nav->proximo;
        while(aux!=NULL){
            if(aux->dado < nav->dado){
                temp = aux->dado;
                aux->dado = nav->dado;
                nav->dado = temp;
                nav = lEnc.inicio;
                aux = nav->proximo;
            }else{
                aux = aux->proximo;
                nav = nav->proximo;
            }
        }
    }
}
