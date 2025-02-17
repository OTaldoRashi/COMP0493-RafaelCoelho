#include "header.h"

class Ponto{ // P = (x, y)
    public:
        double X;
        double Y;
        Ponto() {}
        Ponto(double X, double Y){
            this->X = X;
            this->Y = Y;
        }
};

class Reta{ // r: ax + by + c = 0;

    public:
        double A; // coeficiente de X
        double B; // coeficiente de Y
        double C; // coeficiente livre
        Reta() {}
        Reta(double A, double B, double C){
            this->A = A;
            this->B = B;
            this->C = C;
        }
};

double distPontos(Ponto A, Ponto B){
    double DX = A.X - B.X;
    double DY = A.Y - B.Y;

    double dist = sqrt((DX * DX) + (DY * DY)); 

    return dist;
}

double distPontoReta(Ponto P, Reta R){
    double numerador = (R.A * P.X) + (R.B * P.Y) + R.C;
    double denom = hypot(R.A, R.B); // eh numericamente uma hipotenusa mas na pratica não eh

    double dist = (abs(numerador)) / denom;
    return dist;
}

int main(){
    

    return 0;
}