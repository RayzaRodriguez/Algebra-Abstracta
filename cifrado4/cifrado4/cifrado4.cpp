#include<stdio.h>
#include<fstream>
#include "Escitala.h"

using namespace std;

int main()
{	//CIFRAR//
	/*
	ifstream men;
	ofstream cif;
	string mensaje;
	men.open("mensaje.txt");
	cif.open("cifrado.txt");
	getline(men, mensaje);
	int cla1;
	int cla2;
	cout << "Ingrese clave 1: ";
	cin >> cla1;
	cout << "Ingrese clave 2: ";
	cin >> cla2;
	while (mensaje.size() > cla1 * cla2)
	{
		cout << "¡CLAVES ERRONEAS!" << endl;
		cout << "Ingrese clave 1: ";
		cin >> cla1;
		cout << "Ingrese clave 2: ";
		cin >> cla2;
	}

	Escitala a(mensaje);
	a.cifrar(cla1, cla2);
	cif << a.mostrarCifrado();
	men.close();
	cif.close();
	*/

	//DESCIFRAR//
	ifstream cif;
	ofstream des;
	string mensaje;
	getline(cif, mensaje);
	int cla1;
	int cla2;
	cout << "Ingrese clave 1: ";
	cin >> cla1;
	cout << "Ingrese clave 2: ";
	cin >> cla2;
	Escitala a(mensaje,cla1,cla2);
	a.descifrar();
	des << a.mostrarDescifrado();

}