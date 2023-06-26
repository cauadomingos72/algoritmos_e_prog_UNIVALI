int pow(int a, int b){
    
    int result;

    cin >> a;
    cin >> b;

    result = a;

    for(int cont = 1; cont < b; cont++){
        result = result * a;
    }

    return result; 
}
