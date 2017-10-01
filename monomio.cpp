#include "polinomio.h"

#include <cmath>

using namespace std;

// Constructor
Monomio::Monomio(int coef, int exp){
    Coeficiente = coef;
    Exponente = exp;
}

// Asignar valor al coeficiente
void Monomio::asignarCoeficiente(int coef){
    Coeficiente = coef;
}

// Obtener el coeficiente
int Monomio::obtenerCoeficiente(){
 return Coeficiente ;
}

// Asignar valor al exponente
void Monomio::asignarExponente(int exp){
    Exponente = exp;
}

// Obtener el exponente
int Monomio::obtenerExponente(){
    return Exponente;
}

// Visualizar un término
ostream& operator<<(ostream& Salida, const Monomio& T){
    Salida << ( ( T.Coeficiente < 0) ? " - " : " + " ) << T.Coeficiente;
    if (T.Exponente == 1)
        Salida << "x";
    else
        if (T.Exponente) Salida << "x^" << T.Exponente;

    return Salida;
}

istream& operator>>(istream &sin, Monomio &r){
  sin >> r.Coeficiente >> r.Exponente;
  return sin;
}
