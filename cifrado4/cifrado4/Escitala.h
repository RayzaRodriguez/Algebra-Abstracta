#pragma once
#include <string>
#include <iostream>
using namespace std;

class Escitala
{
private:
	string mensaje;
	string cifrado;
	string descifrado;
	int clave1;
	int clave2;

public:
	Escitala(string m);
	Escitala(string m,int cla1,int cla2);
	void cifrar(int cla1,int cla2);
	void rellenar();
	string mostrarCifrado();
	void descifrar();
	void borrar();
	void mostrarDescifrado();
};

