#include "Vernam.h"

Vernam::Vernam(string m)
{
	mensaje = m;
}

Vernam::Vernam(string m, string cla)
{
	mensaje = m;
	clave = cla;
}

void Vernam::generarClave()
{
	int num;
	srand(time(NULL));
	for (int i = 0; i < mensaje.size(); i++)
	{
		num = rand() % alfabeto.size();
		clave+=alfabeto[num];
		claveB += binario[num];
	}
}

void Vernam::monstrarClave()
{
	cout << clave;
}

string Vernam::mostrarClaveB()
{
	return claveB;
}

void Vernam::cifrar()
{
	generarClave();
	string p1;
	string p2;
	for (int i = 0; i < mensaje.size(); i++)
	{
		p1=binario[alfabeto.find(mensaje[i])];
		p2 = binario[alfabeto.find(clave[i])];
		for (int j = 0; j < 6; j++)
		{
			if (p1[j] == p2[j])
				cifrado += "0";
			else
				cifrado += "1";
		}
	}
}

string Vernam::mostrarCifrado()
{
	return cifrado;
}

void Vernam::descifrar()
{
	string temp;
	while (cifrado.size() > 0)
	{
		for (int i = 0; i < 6; i++)
		{
			if (cifrado[i] == clave[i])
				descifradoB += "0";
			else
				descifradoB += "1";
		}
		cifrado.erase(0, 6);
		clave.erase(0, 6);
		for (int j=0;j<37;j++)
		{
			if (binario[j] == descifradoB) 
			{
				descifrado += alfabeto[j];
				descifradoB = "";
				break;
			}
		}
	}
	
}

void Vernam::mostrarDescifrado()
{
	cout << descifrado;
}
