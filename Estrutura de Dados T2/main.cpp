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
    return true;
}

bool iniciaGSocios(gsocios &g){    ///Inicialização da lista de guichês para sócios
    g.primeiroS = NULL;
    return true;
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

bool addGNormal(gnormal Normal, int nome, int tempo){
    if(Normal.primeiroN==NULL)
        return false;
    guiches *nav = Normal.primeiroN;
    int aux = nav->total;
    
    
    
    Torcedor novo;
    novo.nome = nome;
    novo.tempo = tempo;
    novo.socio = false;
}

bool addGSocios(gsocios Socios ,int nome, int tempo){
    if(Socios.primeiroS==NULL)
        return false;
    guiches *nav = Socios.primeiroS;
    int aux = nav->total;
    
    
    
    Torcedor novo;
    novo.nome = nome;
    novo.tempo = tempo;
    novo.socio = true;
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
    for(int i=1; i<=qtdCarga; i++){
        int j = 0;
        if(i%20!=0){
            if((i%20) < 10)
                addGNormal(Normal, i-j, 3);
            if((i%20) < 16)
                addGNormal(Normal, i-j, 2);
            if((i%20) < 20)
                addGNormal(Normal, i-j, 1);
        }else{
            j++;
            if((j%20) < 17)
                addGSocios(Socios, j, 1);
            if((j%20) < 20)
                addGSocios(Socios, j, 2);
        }
    }

    return 0;
}
/* balanceamento de procentagem: 1-((1+x)/x%)
