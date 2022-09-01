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
    cout << " __ _ _  _  __  _  " << endl;
    cout << "| _ ) |  | |/ __|/ _  " << endl;
    cout << "|  _  | ||  | | |  _| | | |" << endl;
    cout << "| |) | || |  | || | |_| |" << endl;
    cout << "|_/_|| | __| __/ " << endl;
    cout << endl;
    cout << "1 - Jogar\n2 - Fechar o jogo" << endl;
    cin >> opcao;
    if(opcao%2==0)
    return false;
    else
    return true;
}

bool verif(int cartela[][TAM],int temp){
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
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
            while(verif(cartela,temp)){
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

int sorteio()
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

    return n;
}


void gotoxy(int x, int y)
{
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void clrscr(){
  system("cls");
}

void delay (unsigned long t) {
  Sleep(t);
}

int random (int max){
   return (rand() % max) ;
}

void randomize() {
   srand((unsigned) time(NULL));
}

void textcolor (int forecolor, int backcolor) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void textbackground (int newcolor) {
    newcolor = newcolor << 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (2 | newcolor));
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
                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (15 | 0));
                if (cartela[i][j]<10)
                cout << "0" << cartela[i][j] << " ";
                else
                cout << cartela[i][j] << " ";
            }
            else if(igual==true)
            {
                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (12 | 0));
                if (cartela[i][j]<10)
                cout << "0" << cartela[i][j] << " ";
                else
                cout << cartela[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    bool game = menu();
    textcolor(15,0);
    while(game==true)
    {
        clrscr();
        int cartela1[TAM][TAM]{0};
        int cartela2[TAM][TAM]{0};
        int cartela3[TAM][TAM]{0};
        int cartela4[TAM][TAM]{0};
        int cartela5[TAM][TAM]{0};
        int sorteados[TAM*15]{0};
        string nome1 = preencher(cartela1);
        bubblesort(cartela1);
        string nome2 = preencher(cartela2);
        bubblesort(cartela2);
        string nome3 = preencher(cartela3);
        bubblesort(cartela3);
        string nome4 = preencher(cartela4);
        bubblesort(cartela4);
        string nome5 = preencher(cartela5);
        bubblesort(cartela5);
        for (int i=0; i<75; i++){
            clrscr();
            exibir(cartela1,nome1,sorteados);
            exibir(cartela2,nome2,sorteados);
            exibir(cartela3,nome3,sorteados);
            exibir(cartela4,nome4,sorteados);
            exibir(cartela5,nome5,sorteados);
            sorteados[i] = sorteio();
            for(int j=0; j<TAM*15; j++)
            {
                if(sorteados[j]!=0)
                cout << sorteados[j] << endl;
                else
                j=TAM*15;
            }
            getch();
        }
    }
}
