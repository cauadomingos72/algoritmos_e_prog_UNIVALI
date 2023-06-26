double pow(double a, double b){
    
    double result;

    cin >> a;
    cin >> b;

    result = a;

    for(int cont = 1; cont < b; cont++){
        result = result * a;
    }

    return result; 
}
