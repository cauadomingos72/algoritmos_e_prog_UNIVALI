#include <iostream>
#include <windows.h>
#include "fila.h"
#include "torcedor.h"

using namespace std;

struct guiches{    ///Criação do tipo Guichê
    int num;    ///Variável que descreve o numero referente ao guichê
    int total;    ///Variável que indica o total de pessoas aguardando atendimento
    Fila<Torcedor> gfila;    ///Englobamento da fila de espera do guichê
    guiches *proximo;    ///Ponteiro para o guichê ao lado
};

struct gnormal{
    guiches *primeiroN;    ///Criação de uma lista de guichês normais
};

struct gsocios{
    guiches *primeiroS;    ///Criação de uma lista de guichês para sócios
};

guiches *novoGuiche(int num){    ///Função para criação de um novo guichê
    guiches *novoG = new guiches;    ///Declaração de guichê
    novoG->num = num;    ///Atribuição do numero referente
    novoG->total = 0;    ///Inicialização do guichê com zero na espera
    iniciaFila(novoG->gfila);    ///Inicialização da fila do guichê
    novoG->proximo = NULL;   ///Preparação do ponteiro
}

bool iniciaGNormal(gnormal &g){    ///Inicialização da lista de guichês normais
    g.primeiroN = NULL;
}

bool iniciaGSocios(gsocios &g){    ///Inicialização da lista de guichês para sócios
    g.primeiroS = NULL;
}

void menu(int &GS, int &GN, int &C, int &P, int &T) ///Função de seleção das opções da simulação
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
