#include<stdio.h>
#include<fstream>
#include "Vernam.h"

using namespace std;

int main()
{
	//CIFRAR///
	ifstream men;
	ofstream cif;
	string mensaje;
	men.open("../mensaje.txt");
	cif.open("../cifrado.txt");
	getline(men, mensaje);
	Vernam a(mensaje);
	a.cifrar();
	cif << a.mostrarCifrado();
	cif << '\n';
	cif << a.mostrarClaveB();
	men.close();
	cif.close();

	//DESCIFRAR///
	/*
	ifstream cif;
	ofstream des;
	string mensaje;
	string clave;
	cif.open("../cifrado.txt");
	des.open("../descifrado.txt");
	string tem;
	int cont=0;
	while (getline(cif, tem))
	{
		if (cont == 1)
			clave = tem;
		else
			mensaje = tem;
		cont++;
	}
	Vernam a(mensaje,clave);
	a.descifrar();
	des << a.mostrarDescifrado();
	cif.close();
	des.close();
	*/
}

