#include <iostream>
#include <windows.h>

using namespace std;

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
    menu(qtdGuicheSocio, qtdGuicheNormal, qtdCarga, qtdProcura, qtdTempo);
    return 0;
}
/* balanceamento de procentagem: 1-((1+x)/x%)
