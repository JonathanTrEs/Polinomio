#include <cstdlib>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "polinomio.h"

using namespace std;

double timeval_diff(struct timeval *a,struct timeval *b){
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int opcion() {
  cout << endl;
  cout << "1. Introducir polinomio" << endl;
  cout << "2. Rellenar polinomio Random" << endl;
  cout << ">";
  int opc;
  cin >> opc;
  cout << endl;
  return opc;
}

int metodo() {
  cout << endl;
  cout << "1. Algoritmo lineal" << endl;
  cout << "2. Algoritmo recursivo" << endl;
  cout << ">";
  int opc;
  cin >> opc;
  cout << endl;
  return opc;
}

void menu() { 
  Polinomio  PolinomioA, PolinomioB, Resultado;
  int gradoA, gradoB;
  int coef;
  int opc;
  opc = opcion();
  switch (opc) {
    case 1:
	    cout << "Grado del polinomio A" << endl ;
	    cin >> gradoA ;
	    PolinomioA.asignarGrado(gradoA);
	    cout << " Terminos del polinomio A" << endl;
	    for (register int i = 0; i < gradoA + 1; i++) {
			cout << " Introduce el coeficiente " << i << ": " ;
			cin  >> coef;
			cout << endl;
			PolinomioA.asignarTermino(coef , i);
	    }
	    cout << "Grado del polinomio B" << endl;
	    cin >> gradoB;
	    PolinomioB.asignarGrado(gradoB);
	    cout << "Terminos del pol inomio B" << endl;
	    for (int i = 0; i < gradoB + 1; i++) {
			cout << " Introduce el coeficiente " << i << " : " ;
			cin  >> coef ;
			cout << endl;
			PolinomioB.asignarTermino(coef , i);
	    }
	    cout << "PolinomioA: " << PolinomioA << endl;
	    cout << "PolinomioB: " << PolinomioB << endl;
	    
	    if(metodo() == 1) {
	      Resultado = PolinomioA * PolinomioB;
	      cout << "Producto: " << Resultado << endl;
	    }
	    else{
	      Resultado = PolinomioA.productoRecursivo(PolinomioA, PolinomioB, gradoA);
	      cout << "Producto: " << Resultado << endl;
	    }
	    break;
    case 2:
	    struct timeval iniTime, endTime;
	    
	    cout << "Grado maximo del polinomio" << endl;
	    cin >> gradoA;
	    PolinomioA.asignarGrado(gradoA);
	    PolinomioB.asignarGrado(gradoA);
	    srand(time(NULL));
	    PolinomioA.generarPolinomios(gradoA);
	    PolinomioB.generarPolinomios(gradoA);
	    
	    if(metodo() == 1) {
	      gettimeofday(&iniTime, NULL);
	      Resultado = PolinomioA * PolinomioB;
	      gettimeofday(&endTime, NULL);
	    }
	    else {
	      gettimeofday(&iniTime, NULL);
	      Resultado = PolinomioA.productoRecursivo(PolinomioA, PolinomioB, gradoA);
	      gettimeofday(&endTime, NULL);
	    }
	    cout << endl;
	    cout << "Grado: " << gradoA << endl;
	    cout << timeval_diff(&endTime, &iniTime) << " Segundos" << endl;
	    
	    break;
    default:
	    cout << "Opcion incorrecta" << endl;
	    break;
  }
}

int main(){
    menu();
    return 0;
}
