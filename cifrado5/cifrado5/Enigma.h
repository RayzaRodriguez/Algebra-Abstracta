#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
using namespace std;

class Enigma
{
private:
	string alfabeto = "abcdefghijklmnopqrstuvwxyz";
	string cilindro1 = "abcdefghijklmnopqrstuvwxyz";
	string cilindro5 = "abcdefghijklmnopqrstuvwxyz";
	string cilindro5Modificado;
	vector<string> cilindro2 = { {"aa"}, {"bb"}, {"cc"}, {"dd"}, {"ee"}, {"ff"}, {"gg"}, {"hh"}, {"ii"}, {"jj"}, {"kk"}, {"ll"}, {"mm"}, {"nn"}, {"oo"}, {"pp"}, {"qq"}, {"rr"}, {"ss"}, {"tt"}, {"uu"}, {"vv"}, {"ww"}, {"xx"}, {"yy"}, {"zz"} };
	vector<string> cilindro2Modificado;
	vector<string> cilindro3 = { {"aa"}, {"bb"}, {"cc"}, {"dd"}, {"ee"}, {"ff"}, {"gg"}, {"hh"}, {"ii"}, {"jj"}, {"kk"}, {"ll"}, {"mm"}, {"nn"}, {"oo"}, {"pp"}, {"qq"}, {"rr"}, {"ss"}, {"tt"}, {"uu"}, {"vv"}, {"ww"}, {"xx"}, {"yy"}, {"zz"} };
	vector<string> cilindro3Modificado;
	vector<string> cilindro4 = { {"aa"}, {"bb"}, {"cc"}, {"dd"}, {"ee"}, {"ff"}, {"gg"}, {"hh"}, {"ii"}, {"jj"}, {"kk"}, {"ll"}, {"mm"}, {"nn"}, {"oo"}, {"pp"}, {"qq"}, {"rr"}, {"ss"}, {"tt"}, {"uu"}, {"vv"}, {"ww"}, {"xx"}, {"yy"}, {"zz"} };
	vector<string> cilindro4Modificado;
	string mensaje;
	string cifrado;
	string descifrado;
	string r1, r2, r3;
	int clave1;
	int clave2;
	int clave3;

public:
	Enigma(string m);
	Enigma(string men, string c1, string c2, string c3, string r1a, string r2a, string r3a);
	void generarClaves();
	void mostrarClaves();
	void crearCilindros();
	void modificarCilindros();
	void mostrarCilindro2();
	void mostrarCilindro3();
	void mostrarCilindro4();
	void mostrarCilindroMoodificado5();
	void mostrarCilindroMoodificado2();
	void mostrarCilindroMoodificado3();
	void mostrarCilindroMoodificado4();
	void cifrar();
	void pasarClaves();
	void mostrar();
	void mensajeCifrado();
	string descifrar();
	void pasar();
	//void mostrarDescifrado();
};

