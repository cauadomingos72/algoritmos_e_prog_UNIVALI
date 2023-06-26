void tab(int cont){
    for(int k=0;k<cont;k++){
        cout<<"\t";
    }
}

void imprimir(string vet,int cont,int tam){
    int ajuda;
    tab(cont);
    cout<<vet[0];
    cout<<endl;
    cont=cont/2;
    ajuda=2;
    for(int i=1;i<tam;i++){
        //int var=cont*2;
        //cout<<var<<cont;
        for(int j=0;j<ajuda;j++){
            if(j%ajuda==0){
                tab(cont);
            }
            else{
                tab(cont*2);
            }
            cout<<vet[i];
            i++;
        }
        i--;
        cout<<endl;
        cont=cont/2;
        ajuda=ajuda*2;
    }
}
