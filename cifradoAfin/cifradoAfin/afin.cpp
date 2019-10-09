#include "stdafx.h"
#include "afin.h"
#include<stdlib.h>
#include<time.h>
#include <string>
#include <iostream>

using namespace std;

afin::afin(int n)
{
	mod = n;
}

int afin::modulo(int a, int b)
{
	int q = a / b;
	int r = a - q*b;
	if (r<0)
		r += b;
	return r;
}

bool afin::mcd(int num)
{
	int a = num;
	int b = mod;
	int r = 1;
	int q;
	while (r>0)
	{
		q = a / b;
		r = a - (b*q);
		a = b;
		b = r;
	}
	b = a;
	a = b*q;
	if (b == 1)
		return true;
	else
		return false;
}


void afin::generarClaveA()
{
	srand(time(NULL));
	int num = 1 + rand() % 50;
	if (mcd(num))
	{
		claveA = num;
		cout << claveA << endl;
	}
	else
		generarClaveA();
}

void afin::generarClaveB()
{
	//srand(time(NULL));
	int num = 1 + rand() % 100;
	claveB = num;
	cout << claveB << endl;
}

int afin::euclidesExtendido(int num)
{
	int r1 = num;
	int r2 = mod;
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	int s = 0;
	int t = 0;
	while (r2 > 0)
	{
		int q = r1 / r2;
		int r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	s = s1;
	t = t1;
	s = modulo(s, mod);
	return s;
}

string afin::cifrado(string mensaje)
{
	string cifrado = "";
	for (int i = 0; i < mensaje.size(); i++)
	{
		int pos = alfabeto.find(mensaje[i]);
		cifrado += alfabeto[modulo(pos*claveA + claveB, mod)];
	}
	return cifrado;
}

string afin::descifrado(string cifrado,int a,int b)
{
	string descifrado = "";
	for (int i = 0; i < cifrado.size(); i++)
	{
		int pos = alfabeto.find(cifrado[i]);
		descifrado += alfabeto[modulo(((pos-b)*a), mod)];
	}
	return descifrado;
}





