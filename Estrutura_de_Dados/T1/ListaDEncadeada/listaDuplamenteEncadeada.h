//Alunos: Cauã Domingos, Pedro Kons, Paulo Martino
#include <iostream>
#include <locale.h>
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
elementoDEnc<Tipo> *novoElementoD(Tipo dado){
    elementoDEnc<Tipo> *novo = new elementoDEnc<Tipo>;
    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = NULL;
};

template <typename Tipo>
bool insereFimListaDEnc(listaDEnc<Tipo> &lDEnc, Tipo dado){
    elementoDEnc <Tipo> *novo = novoElementoD(dado);
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
    elementoDEnc <Tipo> *novo = novoElementoD(dado);
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
    if(posicao > lDEnc.total || lDEnc.total == 0){
        return false;
    }else{
        elementoDEnc<Tipo> *novo = novoElementoD(dado);
        if(posicao == 1){
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
            elementoDEnc <Tipo> *nav = lDEnc.inicio;
            for(int i=2; i<posicao; i++){
                nav = nav->proximo;
            }
            novo->proximo = nav->proximo;
            novo->anterior = nav;
            nav->proximo = novo;
            nav = novo->proximo;
            nav->anterior = novo;
        }else{
            elementoDEnc <Tipo> *nav = lDEnc.fim;
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
bool removePosicaoListaDEncCI(listaDEnc<Tipo> &lDEnc, int posicao){
    if(posicao >= lDEnc.total || lDEnc.total == 0){
        return false;
    }else{
        if(posicao == 1){
            elementoDEnc <Tipo> *aux = lDEnc.inicio;
            lDEnc.inicio = aux->proximo;
            lDEnc.inicio->anterior = NULL;
            delete aux;
        }
        if(posicao == lDEnc.total-1){
            elementoDEnc <Tipo> *aux = lDEnc.fim;
            lDEnc.fim = aux->anterior;
            lDEnc.fim->proximo = NULL;
            delete aux;
        }
        if(posicao<lDEnc.total/2){
            elementoDEnc <Tipo> *nav = lDEnc.inicio;
            for(int i=2; i<posicao; i++){
                nav = nav->proximo;
            }
            elementoDEnc <Tipo> *aux = nav->anterior;
            aux->proximo = nav->proximo;
            aux = nav->proximo;
            aux->anterior = nav->anterior;
            delete nav;
        }else{
            elementoDEnc <Tipo> *nav = lDEnc.fim;
            for(int i=lDEnc.total-1; i>posicao; i--){
                nav = nav->anterior;
            }
            elementoDEnc <Tipo> *aux = nav->anterior;
            aux->proximo = nav->proximo;
            aux = nav->proximo;
            aux->anterior = nav->anterior;
            delete nav;
        }
        lDEnc.total--;
        return true;
    }
}

template <typename Tipo>
bool inserePosicaoListaDEncSI(listaDEnc<Tipo> &lDEnc, Tipo dado, int posicao){
    if(lDEnc.inicio == NULL){
        return false;
    }else{
        elementoDEnc<Tipo> *novo = novoElementoD(dado);
        if(posicao == 1){
            elementoDEnc <Tipo> *aux = lDEnc.inicio;
            lDEnc.inicio = novo;
            aux->anterior = novo;
            novo->proximo = aux;
        }else{
            elementoDEnc <Tipo> *nav = lDEnc.inicio;
            for(int i=2; i<posicao; i++){
                if(nav!=NULL){
                    nav = nav->proximo;
                }else{
                    return false;
                }
            }
            elementoDEnc <Tipo> *aux = nav->proximo;
            novo->proximo = aux;
            aux->anterior = novo;
            novo->anterior = nav;
            nav->proximo = novo;
        }
        return true;
    }
}

template <typename Tipo>
bool removePosicaoListaDEncSI(listaDEnc<Tipo> &lDEnc, int posicao){
    if(lDEnc.inicio == NULL){
        return false;
    }else{
        if(posicao == 1){
            elementoDEnc <Tipo> *aux = lDEnc.inicio;
            lDEnc.inicio = aux->proximo;
            lDEnc.inicio->anterior = NULL;
            delete aux;
        }else{
            elementoDEnc <Tipo> *nav = lDEnc.inicio;
            for(int i=1; i<posicao; i++){
                if(nav!=NULL){
                    nav = nav->proximo;
                }else{
                    return false;
                }
            }
            elementoDEnc <Tipo> *auxA = nav->anterior;
            elementoDEnc <Tipo> *auxB = nav->proximo;
            auxA->proximo = auxB;
            auxB->anterior = auxA;
            delete nav;
        }
        return true;
    }
}

template <typename Tipo>
void bubblesortD(listaDEnc<Tipo> &lDEnc){
    if(lDEnc.inicio != NULL){
        Tipo temp;
        elementoDEnc <Tipo> *nav = lDEnc.inicio;
        elementoDEnc <Tipo> *aux = nav->proximo;
        while(aux!=NULL){
            if(aux->dado < nav->dado){
                temp = aux->dado;
                aux->dado = nav->dado;
                nav->dado = temp;
                nav = lDEnc.inicio;
                aux = nav->proximo;
            }else{
                aux = aux->proximo;
                nav = nav->proximo;
            }
        }
    }
}

///Esta é a ordenação implementada por nós, não achamos o erro para correção.
/*template <typename Tipo>
void quicksortD(listaDEnc<Tipo> &lDEnc){
    elementoDEnc <Tipo> *navi = lDEnc.inicio;
    elementoDEnc <Tipo> *navf = lDEnc.fim;
    if (navf!=NULL && navi!=navf && navf!=navi->proximo){
        Tipo meio = navf->dado;
        elementoDEnc <Tipo> *i = navf->anterior;
        for (elementoDEnc <Tipo> *j=navi; j!=navf; j=j->proximo){
            if (j->dado <= meio){
                if(i==NULL){
                    i = navi;
                }else{
                    i = i->proximo;
                }
                Tipo temp = i->dado;
                i->dado = j->dado;
                j->dado = temp;
            }
        }
        if(i==NULL){
            i = navi;
        }else{
            i = i->proximo;
        }
        Tipo temp = i->dado;
        i->dado = navf->dado;
        navf->dado = temp;
        lDEnc.inicio = navi;
        lDEnc.fim = i->anterior;
        quicksortD(lDEnc);
        lDEnc.inicio = i->proximo;
        lDEnc.fim = navf;
        quicksortD(lDEnc);
    }
}*/

///Neste final da biblioteca, está a correção criada pelo "ChatGPT" para o nosso quicksort.

template <typename Tipo>
elementoDEnc<Tipo>* partitionD(elementoDEnc<Tipo> *esquerda, elementoDEnc<Tipo> *direita){
    Tipo pivo = direita->dado;
    elementoDEnc<Tipo> *i = esquerda->anterior;

    for (elementoDEnc<Tipo> *j = esquerda; j != direita; j = j->proximo) {
        if (j->dado <= pivo) {
            i = (i == NULL) ? esquerda : i->proximo;
            std::swap(i->dado, j->dado);
        }
    }
    i = (i == NULL) ? esquerda : i->proximo;
    std::swap(i->dado, direita->dado);
    return i;
}

template <typename Tipo>
void quicksortD(elementoDEnc<Tipo> *esquerda, elementoDEnc<Tipo> *direita){
    if (direita != NULL && esquerda != direita && esquerda != direita->proximo) {
        elementoDEnc<Tipo>* pivo = partitionD(esquerda, direita);
        quicksortD(esquerda, pivo->anterior);
        quicksortD(pivo->proximo, direita);
    }
}

template <typename Tipo>
void quicksortD(listaDEnc<Tipo> &lDEnc){
    quicksortD(lDEnc.inicio, lDEnc.fim);
}
