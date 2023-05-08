#include <iostream>
#include <windows.h>
#include "fila.h"
#include "torcedor.h"

using namespace std;

struct guiches{
    int num;
    int total;
    Fila<Torcedor> gfila;
    guiches *proximo;
};

struct gnormal{
    guiches *primeiroN;
};

struct gsocios{
    guiches *primeiroS;
};

guiches *novoGuiche(int num){
    guiches *novoG = new guiches;
    novoG->num = num;
    novoG->total = 0;
    iniciaFila(novoG->gfila);
    novoG->proximo = NULL;
}

bool iniciaGNormal(gnormal &g){
    g.primeiroN = NULL;
}

bool iniciaGSocios(gsocios &g){
    g.primeiroS = NULL;
}

void menu(int &GS, int &GN, int &C, int &P, int &T) ///Função de exibição e seleção de opções.
{
    system("cls");
    cout<<"Qtd. de guichês sócio-torcedor: "<<endl;
    cin >> GS;
    cout<<"Qtd. de guichês normais: "<<endl;
    cin >> GN;
    cout<<"Qtd. de pessoas na carga inicial: "<<endl;
    cin >> C;
    cout<<"Qtd. de pessoas procurando fila a cada unidade de tempo: "<<endl;
    cin >> P;
    cout<<"Qtd. de tempo da simulação: "<<endl;
    cin >> T;
    system("cls");
}

int main()
{
    int qtdGuicheSocio, qtdGuicheNormal, qtdCarga, qtdProcura, qtdTempo;
    gnormal Normal;
    iniciaGNormal(Normal);
    gsocios Socios;
    iniciaGSocios(Socios);
    menu(qtdGuicheSocio, qtdGuicheNormal, qtdCarga, qtdProcura, qtdTempo);
    for(int i=qtdGuicheNormal; i>0; i--){
        guiches *novo = novoGuiche(i);
        novo->proximo = Normal.primeiroN;
        Normal.primeiroN = novo;
    }
    for(int i=qtdGuicheSocio; i>0; i--){
        guiches *novo = novoGuiche(i);
        novo->proximo = Socios.primeiroS;
        Socios.primeiroS = novo;
    }
    return 0;
}
/* balanceamento de procentagem: 1-((1+x)/x%)
