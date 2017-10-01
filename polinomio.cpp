# include "polinomio.h"
# include <iostream>
#include <stdlib.h>

// Constructor
Polinomio::Polinomio(){
    grado = 10;
    terminos = new Monomio [grado + 1];
}

Polinomio::Polinomio(int g){
    grado = g;
    terminos = new Monomio [grado + 2] ;
}

Polinomio::Polinomio(const Polinomio &C){
    //Llamando al constructor de copia
    grado = C.grado;
    terminos = new Monomio[C.grado + 2];
    for (register int i = 0; i < grado + 1; i++) terminos[i] = C.terminos[i];
}

Polinomio::~Polinomio(){
    delete [] terminos;
}

void Polinomio::asignarGrado(int g){
    grado = g;
    delete [] terminos;
    terminos = new Monomio[grado + 1];
}

int Polinomio::obtenerGrado(){
    return grado;
}

void Polinomio::asignarTermino(int c, int i){
    terminos[i].asignarCoeficiente(c);
    terminos[i].asignarExponente(i);
}

Monomio* Polinomio::getTerminos(){
  return terminos;
}

// Visualizar los terminos de un polinomio
ostream& operator<<(ostream& Salida, const Polinomio& P)
{
    int i = P.grado;
    i = i + 1;
    while (i--) Salida << P.terminos[i];

    return Salida;
}

//Producto de polinomios normal
Polinomio Polinomio::operator*(Polinomio& polB) {
	Polinomio solucion(obtenerGrado() + polB.obtenerGrado());
	for (int i = 0; i < obtenerGrado() + 1; i++) {
		for (int j = 0; j < polB.obtenerGrado() + 1; j++) {
			solucion.asignarTermino(solucion.terminos[i + j].obtenerCoeficiente() + (terminos[i].obtenerCoeficiente() * polB.terminos[j].obtenerCoeficiente()) ,i + j);
		}
	}
	return solucion;
}

//para devolver la multiplicacion en otro polinomio
Polinomio& Polinomio::operator=(const Polinomio &pol)
{
    if (this->terminos != pol.terminos)
    {
        grado = pol.grado;
        delete [] terminos;
        terminos = new Monomio[grado + 1];
        for (register int i = 0; i < grado + 1; i++) terminos[i] = pol.terminos[i];
    }
    return *this;
}

//calcular los coeficientes de forma random
void Polinomio::generarPolinomios(int numGrado){
  for(int i = 0; i <= obtenerGrado();i++){
    getTerminos()[i].asignarCoeficiente((rand() % 10));
  }
}

//Producto Recursivo
Polinomio Polinomio::productoRecursivo(Polinomio polA, Polinomio polB, int n) {
  Polinomio Ah(n / 2);
  Polinomio Al(n / 2);
  Polinomio Bh(n / 2);
  Polinomio Bl(n / 2);
  Polinomio x1, x2, x3, x4, aux, x, s1, s2;

  if (n == 0)
    return polA * polB;
  else {
    int j = (n / 2) + 1;
    for(int i = 0; i < (n / 2) + 1; i++) {
      Al.setMonomio(polA.terminos[i].obtenerCoeficiente(), i);
      Bl.setMonomio(polB.terminos[i].obtenerCoeficiente(), i);
      Ah.setMonomio(polA.terminos[j].obtenerCoeficiente(), i);
      Bh.setMonomio(polB.terminos[j].obtenerCoeficiente(), i);
      j++;
    }
    s1 = Ah + Al;
    s2 = Bh + Bl;
    x1 = productoRecursivo(Ah, Bh, n / 2);
    x2 = productoRecursivo(s1, s1, n / 2);
    x3 = productoRecursivo(Al, Bl, n / 2);
    x4 = x1.cambiarSigno(x1);
    x2 = x2 + x4;
    x4 = x3.cambiarSigno(x3);
    aux = x2 + x4;
    x1 = x1.desplazarIzq((n + n));
    aux = aux.desplazarIzq(n);
    x = x1 + aux;
    x = x + x3;

    return x;
  }
}

//Set Monomio
void Polinomio::setMonomio(int coeficiente, int exponente) {
  terminos[exponente].asignarCoeficiente(coeficiente);
  terminos[exponente].asignarExponente(exponente);
}

//Sobrecarga sumar polinomios
Polinomio Polinomio::operator+(Polinomio& polB) {
  int gradoPolA = obtenerGrado();
  int gradoPolB = polB.obtenerGrado();
  int gradoPolS;
  float coefA, coefB;
  gradoPolS = gradoPolA;
  if (gradoPolA < gradoPolB)
    gradoPolS = gradoPolB;
  Polinomio polS(gradoPolS);
  gradoPolS = polS.obtenerGrado();
  for (int i = 0;i <= gradoPolS; i++) {
    coefA = coefB = 0;
    if (i <= gradoPolA)
      coefA = terminos[i].obtenerCoeficiente();
    if (i <= gradoPolB)
      coefB = polB.terminos[i].obtenerCoeficiente();
    polS.setMonomio(coefA + coefB , i);
  }
  return polS;
}

//cambiarSigno
Polinomio Polinomio::cambiarSigno(Polinomio pol) {
  Polinomio negativo(0);
  negativo.terminos[0].asignarCoeficiente(-1);
  Polinomio resultado = negativo * pol;

  //cout << negativo << endl;
  return resultado;
}

//Desplazar Izq
Polinomio Polinomio::desplazarIzq(int n) {
  Polinomio pol(n);
  int j = 0;
  for(int i = (n / 2) + 1; i < n + 1; i++) {
    pol.setMonomio(terminos[j].obtenerCoeficiente(), i);
    j++;
  }
  return pol;
}

//visualizar polinomio auxiliar
void Polinomio::visualizarPolinomio() {
    
}
