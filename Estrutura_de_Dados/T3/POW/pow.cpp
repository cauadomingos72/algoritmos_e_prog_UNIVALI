double pow(double a, double b){

    double result;

    result = a;

    for(int cont = 1; cont < b; cont++){
        result = result * a;
    }

    return result;

}
