# include "monomio.h"

# include <vector>
# include <iostream>

using namespace std;

class Polinomio{
    private:
        int grado; ////grado del polinomio
        Monomio *terminos; //terminos de nuestro polinomio

    public:
      
        Polinomio (); // constructor por defecto
        Polinomio(int g); //constructor pasandole el grado
        Polinomio(const Polinomio &); // constructor de copia
        ~Polinomio(); //destructor
	
	//Getters && Setters
        void asignarGrado(int g);
        int obtenerGrado();
        void asignarTermino(int c, int e);
	Monomio* getTerminos();
	void setMonomio(int coeficiente, int exponente);
	
	void visualizarPolinomio();//metodo mostrar
	
	//multiplicar polinomio
	Polinomio operator*(Polinomio& polB);
	Polinomio productoRecursivo(Polinomio polA, Polinomio polB, int n);
	
	//devolver la multiplicacion en un polinomio
	Polinomio& operator=(const Polinomio &pol);
	
	//Operador de extraccion
        friend ostream& operator<<(ostream& Salida, const Polinomio&);
	
	void generarPolinomios(int numGrado);
	
	//sumar polinomio
	Polinomio operator+(Polinomio& polB);
	
	Polinomio desplazarIzq(int n);
	Polinomio cambiarSigno(Polinomio pol);
};
