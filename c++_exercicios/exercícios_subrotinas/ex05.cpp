#include <iostream>
#include <locale.h>

using namespace std;

void tabela(int tab){
  int res, i;
  cout<<"Insira um valor inteiro: "<<endl;
  cin>>tab;
  cout<<endl;
  for(i=1; i <= 10; i++){
    res = tab * i;
    cout<<tab<<" x "<<i<<" = "<<res<<endl;
    res=0;
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");

  int tab;
  
  tabela(tab);

  return 0;
}
