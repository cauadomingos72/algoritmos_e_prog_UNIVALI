#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15
#define TAM 5
using namespace std;

bool menu()
{
    int opcao;
    cout << " ____ ___ _  _  ____  ___  " << endl;
    cout << "| __ )_ _|  | |/ ___|/ _  " << endl;
    cout << "|  _  | ||  | | |  _| | | |" << endl;
    cout << "| |_) | || |  | |_| | |_| |" << endl;
    cout << "|____/___|_| _| ____| ___/ " << endl;
    cout << endl;
    cout << "1 - Jogar\n2 - Fechar o jogo" << endl;
    cin >> opcao;
    if(opcao%2==0)
    return false;
    else
    return true;
}

bool verif(int cartela[][TAM],int temp)
{
    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            if(cartela[i][j]==temp)
            return true;
        }
    }
    return false;
}

string preencher(int cartela[TAM][TAM])
{
    int temp;
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            temp = 1+i*15+(rand()%15);
            while(verif(cartela,temp))
            {
                temp = 1+i*15+(rand()%15);
            }
            cartela[i][j]=temp;
        }
    }
    string nome;
    cout << "De um nome para a cartela:";
    cin >> nome;
    return nome;
}

void bubblesort (int cartela[TAM][TAM]){
    int cond=1, temp=0;
    for(int i=TAM-1; (i>=1) && (cond==1); i--){
    cond=0;
        for(int j=0; j<TAM;j++){
            for(int k=0; k<i; k++){
                if(cartela[j][k+1]<cartela[j][k]){
                  temp=cartela[j][k];
                  cartela[j][k]=0;
                  cartela[j][k]=cartela[j][k+1];
                  cartela[j][k+1]=temp;
                  cond=1;
                }
            }
        }
    }
}

int sorteio(bool zero)
{
    srand((unsigned) time(NULL));
    static int numerosParaSortear[76] = {0};
    int n;
    bool mantemWhile = true;
    do
    {
        n = rand()%75+1;

        if (numerosParaSortear[n] == 0)
        {
            numerosParaSortear[n] = n;
            mantemWhile = false;
        }

    } while (mantemWhile);
    if(zero==true)
    for(int i=0; i<77; i++)
    numerosParaSortear[i]=0;
    return n;
}

void clrscr(){
  system("cls");
}

void textcolor (int forecolor, int backcolor) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void exibir(int cartela[TAM][TAM], string nome, int vet[TAM*15])
{
    cout << "Cartela de " << nome << endl;
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            bool igual=false;
            for(int k=0; k<TAM*15; k++)
            {
                if(cartela[i][j]==vet[k])
                igual=true;
            }
            if(igual==false)
            {
                textcolor (BRIGHTWHITE, BLACK);
                if (cartela[i][j]<10)
                cout << "0" << cartela[i][j] << " ";
                else
                cout << cartela[i][j] << " ";
            }
            else if(igual==true)
            {
                textcolor (LIGHTRED, BLACK);
                if (cartela[i][j]<10)
                cout << "0" << cartela[i][j] << " ";
                else
                cout << cartela[i][j] << " ";
                textcolor (BRIGHTWHITE, BLACK);
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool bingo(int mat[TAM][TAM], int vet[TAM*15])
{
    int cont=0;
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            for(int k=0; k<TAM*15; k++)
            {
                if(mat[i][j]==vet[k])
                cont++;
            }
        }
    }
    if(cont==25)
    return true;
    else
    return false;
}

bool menufim(string name)
{
    clrscr();
    cout << "A cartela de " << name << " venceu!";
    cout << endl;
    cout << "1 - Jogar Novamente\n2 - Fechar o jogo" << endl;
    int opcao;
    cin >> opcao;
    if(opcao%2==0)
    return false;
    else
    return true;
}

void marcados(int sorteados[TAM*15])
{
    for(int j=0; j<TAM*15; j++)
    {
        if(sorteados[j]!=0)
        {
            if (sorteados[j]<10)
            cout << "0" << sorteados[j] << " ";
            else
            cout << sorteados[j] << " ";
        }
        else
        j=TAM*15;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    bool game = menu();
    textcolor(15,0);
    if (game==true)
    do
    {
        bool zerar=true;
        sorteio(zerar);
        int sorteados[TAM*15]{0};
        clrscr();
        int cartela1[TAM][TAM]{0};
        int cartela2[TAM][TAM]{0};
        int cartela3[TAM][TAM]{0};
        int cartela4[TAM][TAM]{0};
        int cartela5[TAM][TAM]{0};
        string nome1 = preencher(cartela1);
        string nome2 = preencher(cartela2);
        string nome3 = preencher(cartela3);
        string nome4 = preencher(cartela4);
        string nome5 = preencher(cartela5);
        bubblesort(cartela1);
        bubblesort(cartela2);
        bubblesort(cartela3);
        bubblesort(cartela4);
        bubblesort(cartela5);
        for (int i=0; i<75; i++){
            clrscr();
            zerar=false;
            sorteados[i] = sorteio(zerar);
            exibir(cartela1,nome1,sorteados);
            exibir(cartela2,nome2,sorteados);
            exibir(cartela3,nome3,sorteados);
            exibir(cartela4,nome4,sorteados);
            exibir(cartela5,nome5,sorteados);
            marcados(sorteados);
            getch();
            bool fim = false;
            fim = bingo(cartela1, sorteados);
            if(fim==true)
            {
            system("pause");
            game = menufim(nome1);
            break;
            }
            fim = bingo(cartela2, sorteados);
            if(fim==true)
            {
            system("pause");
            game = menufim(nome2);
            break;
            }
            fim = bingo(cartela3, sorteados);
            if(fim==true)
            {
            system("pause");
            game = menufim(nome3);
            break;
            }
            fim = bingo(cartela4, sorteados);
            if(fim==true)
            {
            system("pause");
            game = menufim(nome4);
            break;
            }
            fim = bingo(cartela5, sorteados);
            if(fim==true)
            {
            system("pause");
            game = menufim(nome5);
            break;
            }
        }
    }while(game==true);
    return 0;
}
