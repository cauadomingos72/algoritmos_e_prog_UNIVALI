#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

template <typename Tipo>
struct elementoGen{
    Tipo dado;
};

template <typename Tipo, int MAX>
struct listaGen{
    elementoGen <Tipo> elementos[MAX];
    int tamanho;
};

template <typename Tipo, int MAX>
bool iniciaListaGen(listaGen<Tipo, MAX> &lGen){
    lGen.tamanho = 0;
    return true;
}

template <typename Tipo, int MAX>
int retornaTamanhoListaGen(listaGen<Tipo, MAX> &lGen){
    return lGen.tamanho;
}

template <typename Tipo, int MAX>
bool insereFimListaGen(listaGen<Tipo, MAX> &lGen, Tipo dado){
    if(lGen.tamanho < MAX){
        elementoGen<Tipo> e;
        e.dado = dado;
        lGen.elementos[lGen.tamanho] = e;
        lGen.tamanho++;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo, int MAX>
bool removeFimListaGen(listaGen<Tipo, MAX> &lGen){
    if(lGen.tamanho > 0){
        lGen.tamanho--;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo, int MAX>
bool insereInicioListaGen(listaGen<Tipo, MAX> &lGen, Tipo dado){
    if(lGen.tamanho < MAX){
        for(int i=lGen.tamanho; i>0; i--){
            lGen.elementos[i] = lGen.elementos[i-1];
        }
        elementoGen<Tipo> e;
        e.dado = dado;
        lGen.elementos[0] = e;
        lGen.tamanho++;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo, int MAX>
bool removeInicioListaGen(listaGen<Tipo, MAX> &lGen){
    if(lGen.tamanho > 0){
        for(int i=0; i<lGen.tamanho; i++){
            lGen.elementos[i] = lGen.elementos[i+1];
        }
        lGen.tamanho--;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo, int MAX>
bool inserePosicaoListaGen(listaGen<Tipo, MAX> &lGen, Tipo dado, int posicao){
    if(lGen.tamanho < MAX && posicao < lGen.tamanho){
        for(int i=lGen.tamanho; i+1>posicao; i--){
            lGen.elementos[i+1] = lGen.elementos[i];
        }
        elementoGen<Tipo> e;
        e.dado = dado;
        lGen.elementos[posicao] = e;
        lGen.tamanho++;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo, int MAX>
bool removePosicaoListaGen(listaGen<Tipo, MAX> &lGen, int posicao){
    if(lGen.tamanho > 0 && posicao < lGen.tamanho){
        for(int i=posicao; i+1<lGen.tamanho; i++){
            lGen.elementos[i] = lGen.elementos[i+1];
        }
        lGen.tamanho--;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo, int MAX>
void bubblesort(listaGen<Tipo, MAX> &lGen){
    Tipo temp;
    int cond=1;
    for(int i=lGen.tamanho; i>=1 && cond==1; i--){
        cond = 0;
        for(int j=0; j<i; j++){
            if(lGen.elementos[j+1].dado < lGen.elementos[j].dado){
                temp = lGen.elementos[j].dado;
                lGen.elementos[j].dado = lGen.elementos[j+1].dado;
                lGen.elementos[j+1].dado = temp;
                cond = 1;
            }
        }
    }
}
