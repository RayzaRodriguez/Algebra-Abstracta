#include "Escitala.h"

Escitala::Escitala(string m)
{
	mensaje = m;
}

Escitala::Escitala(string m,int cla1,int cla2)
{
	mensaje = m;
	clave1 = cla1;
	clave2 = cla2;
}

void Escitala::cifrar(int cla1, int cla2)
{
	clave1 = cla1;
	clave2 = cla2;
	rellenar();
	for (int i = 0; i < clave2; i++)
	{
		cifrado += mensaje[i];
		int a = i;
		for (int j = 1; j < clave1; j++)
		{
			a += clave2;
			cifrado += mensaje[a];
		}
	}
}

void Escitala::rellenar()
{
	if (mensaje.size() < clave1 * clave2)
	{
		int temp = (clave1 * clave2) - mensaje.size();
		for (int i = 0; i < temp; i++)
			mensaje += "w";
	}
}

string Escitala::mostrarCifrado()
{
	return cifrado;
}

void Escitala::descifrar()
{
	for (int i = 0; i < clave1; i++)
	{
		descifrado += cifrado[i];
		int a = i;
		for (int j = 1; j < clave2; j++)
		{
			a += clave1;
			descifrado += cifrado[a];
		}
	}
	borrar();
}

void Escitala::borrar()
{
	for (int i = descifrado.size() - 1; i > 0; i--)
	{
		if (descifrado[i] != 'w')
			break;
		else
			descifrado.pop_back();
	}
}

void Escitala::mostrarDescifrado()
{
	cout << descifrado;
}

