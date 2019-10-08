#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class prueba
{
private:
	string alfabeto = "abcdefghijklmnopqrstuvwxyz 1234567890";
	vector<int> claveE;
	string claveS;
	string mensaje;
	string mensajeCifrado;
	string mensajeDescifrado;
	int tam;
	
public:
	prueba(string m);
	prueba(string m, string c);
	string cifrado();
	string descifrado();
	void numAleatorios();
	void imprimirClaveEntera();
	string imprimirClaveString();
	void pasarClave();
};

