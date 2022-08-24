#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTAQUA 11
#define LIGHTRED 12
#define LIGHTPURPLE 13
#define LIGHTYELLOW 14
#define BRIGHTWHITE 15
#define TAM 5
using namespace std;

void preencher(int cartela[TAM][TAM])
{
    for(int i=0; i<TAM; i++)
    {
        int soma=15;
        for(int j=0; j<TAM; j++)
        {
            cartela[i][j] = i*15+(rand()%soma+1);
        }
    }
}

void ordem (int cartela[TAM][TAM])
{
    int cond=1, temp=0;
    for(int i=0; i<TAM; i++){}
}

void exibir(int cartela[TAM][TAM])
{
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            if (cartela[i][j]<10)
            cout << "0" << cartela[i][j] << " ";
            else
            cout << cartela[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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

int random (int max) {
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
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (WHITE | newcolor));
}

void movimenta (int tecla, int *x, int *y)
{
    switch(tecla)
    {
        case 72: gotoxy(*x,--*y); break; //cima
        case 80: gotoxy(*x,++*y); break; //baixo
        case 75: gotoxy(--*x,*y); break; //esquerda
        case 77: gotoxy(++*x,*y); break; //direita
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int cartela1[TAM][TAM]{0};
    int cartela2[TAM][TAM]{0};
    int cartela3[TAM][TAM]{0};
    int cartela4[TAM][TAM]{0};
    int cartela5[TAM][TAM]{0};
    preencher(cartela1);
    preencher(cartela2);
    preencher(cartela3);
    preencher(cartela4);
    preencher(cartela5);
    textcolor(7,0);
    exibir(cartela1);
    textcolor(2,0);
    exibir(cartela2);
    textcolor(7,0);
    exibir(cartela3);
    textcolor(2,0);
    exibir(cartela4);
    textcolor(7,0);
    exibir(cartela5);
    textbackground(3);
    textcolor(7,0);
    return 0;
}
