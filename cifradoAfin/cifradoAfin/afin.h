#pragma once
#include<stdlib.h>
#include<time.h>
#include <string>
using namespace std;

class afin
{
private:
	string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
	int mod=alfabeto.size();
	int claveA;
	int claveB;
public:
	afin(int);
	int modulo(int, int);
	bool mcd(int);
	void generarClaveA();
	void generarClaveB();
	int euclidesExtendido(int);
	string cifrado(string);
	string descifrado(string,int,int);

};

