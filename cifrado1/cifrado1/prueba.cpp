#include "prueba.h"

prueba::prueba(string m)
{
	mensaje = m;
}

prueba::prueba(string m, string c)
{
	mensajeCifrado = m;
	claveS = c;
}

string prueba::cifrado()
{
	numAleatorios();
	tam = mensaje.size();
	for (int i = 0; i < tam; i++)
	{
		int posMensaje = alfabeto.find(mensaje[i]);
		mensajeCifrado += alfabeto[(posMensaje+claveE[i])%alfabeto.size()];
	}
	return mensajeCifrado;
}

string prueba::descifrado()
{
	tam = mensajeCifrado.size();
	pasarClave();
	for (int i = 0; i < tam; i++)
	{
		int posMensaje = alfabeto.find(mensajeCifrado[i]);
		mensajeDescifrado += alfabeto[(posMensaje - claveE[i])%alfabeto.size()];
	}
	return mensajeDescifrado;
}

void prueba::numAleatorios()
{
	srand(time(NULL));
	for (int i = 0; i < mensaje.size(); i++)
	{
		claveE.push_back(rand() % alfabeto.size());
	}
	for (int i = 0; i < mensaje.size(); i++)
	{
		if (claveE[i] / 10 < 1)
		{
			claveS += '0';
			claveS+=to_string(claveE[i]);
		}
		else
			claveS+=to_string(claveE[i]);
	}

}

void prueba::imprimirClaveEntera()
{
	for (int i = 0; i < tam ; i++)
		cout << claveE[i]<<" ";
}

string prueba::imprimirClaveString()
{
		return claveS;
}

void prueba::pasarClave()
{
	int j = 0;
	string c;
	for (int i = 0; i < tam; i++)
	{
		c = "";
		c += claveS[j];
		c += claveS[j+1];
		j += 2;
		claveE.push_back(atoi(c.c_str()));
	}
}
