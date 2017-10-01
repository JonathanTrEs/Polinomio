
#include <iostream>

#ifndef MONOMIO_H_
#define MONOMIO_H_

using namespace std;

class Monomio{
  private:
    int Coeficiente;
    int Exponente;

  public:

    Monomio( int coef = 0, int exp = 1); //Constructor con Coeficiente y Exponente
    
    //Getter && Setter Coeficiente
    void asignarCoeficiente(int) ;
    int obtenerCoeficiente() ;
    
    //Getter && Setter Exponente
    void asignarExponente(int) ;
    int obtenerExponente();
    
    //Operadores de insercion y extraccion
    friend ostream& operator<<(ostream& Salida, const Monomio&);
    friend istream& operator>>(istream &sin, Monomio &r);
    
    //Funcion evaluar ¿¿??
    int evaluar(int x); // evalua un monomio en un punto
};
#endif