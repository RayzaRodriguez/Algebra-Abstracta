#include "Enigma.h"

Enigma::Enigma(string m)
{
	mensaje = m;
	crearCilindros();
}

Enigma::Enigma(string men, string c1, string c2, string c3, string r1a, string r2a, string r3a)
{
	cifrado = men;
	clave1 = alfabeto.find(c1);
	clave2 = alfabeto.find(c2);
	clave3 = alfabeto.find(c3);
	r1 = r1a;
	r2 = r2a;
	r3 = r3a;
	modificarCilindros();
	pasar();
}

void Enigma::generarClaves()
{
	srand(time(NULL));
	clave1 = (rand()) % alfabeto.size();
	clave2 = (rand()) % alfabeto.size();
	clave3 = (rand()) % alfabeto.size();

	modificarCilindros();
}

void Enigma::mostrarClaves()
{
	cout <<cilindro2Modificado[0][0] << " " << clave1 << " " << cilindro3Modificado[0][0] << " " << clave2 << " " << cilindro4Modificado[0][0] << " " << clave3 << endl;
}

void Enigma::crearCilindros()
{
	string alfabeto = cilindro1;
	int pos = 26;
	for (int i = 0; i < 26; i++)
	{
		int num = (rand()) % pos;
		cilindro2[i][1]=alfabeto[num];
		alfabeto.erase(num, 1);
		pos--;
		if (pos == 0)
		{
			break;
		}
	}
	alfabeto = cilindro1;
	pos = 26;
	for (int i = 0; i < 26; i++)
	{
		int num = (rand()) % pos;
		cilindro3[i][1] = alfabeto[num];
		alfabeto.erase(num, 1);
		pos--;
		if (pos == 0)
		{
			break;
		}
	}
	alfabeto = cilindro1;
	pos = 26;
	for (int i = 0; i < 26; i++)
	{
		int num = (rand()) % pos;
		cilindro4[i][1] = alfabeto[num];
		alfabeto.erase(num, 1);
		pos--;
		if (pos == 0)
		{
			break;
		}
	}
}

void Enigma::modificarCilindros()
{
	int i;
	for (i = clave1; i < alfabeto.size(); i++)
	{
		cilindro2Modificado.push_back(cilindro2[i]);
		cilindro5Modificado.push_back(cilindro5[i]);
	}
	for (i = 0; i < clave1; i++)
	{
		cilindro2Modificado.push_back(cilindro2[i]);
		cilindro5Modificado.push_back(cilindro5[i]);
	}
	
	for (i = clave2; i < alfabeto.size(); i++)
	{
		cilindro3Modificado.push_back(cilindro3[i]);
	}
	for (i = 0; i < clave2; i++)
	{
		cilindro3Modificado.push_back(cilindro3[i]);
	}
	for (i = clave3; i < alfabeto.size(); i++)
	{
		cilindro4Modificado.push_back(cilindro4[i]);
	}
	for (i = 0; i < clave3; i++)
	{
		cilindro4Modificado.push_back(cilindro4[i]);
	}
}

void Enigma::mostrarCilindro2()
{
	for (int i = 0; i < 26; i++)
		cout << cilindro2[i] << " ";
	cout << endl;
}

void Enigma::mostrarCilindro3()
{
	for (int i = 0; i < 26; i++)
		cout << cilindro3[i] << " ";
	cout << endl;
}

void Enigma::mostrarCilindro4()
{
	for (int i = 0; i < 26; i++)
		cout << cilindro4[i] << " ";
	cout << endl;
}

void Enigma::mostrarCilindroMoodificado5()
{
	for (int i = 0; i < cilindro1.size(); i++)
		cout << cilindro5Modificado[i] << " ";
}

void Enigma::mostrarCilindroMoodificado2()
{
	for (int i = 0; i < cilindro1.size(); i++)
		cout << cilindro2Modificado[i] << " ";
}

void Enigma::mostrarCilindroMoodificado3()
{
	for (int i = 0; i < cilindro1.size(); i++)
		cout << cilindro3Modificado[i] << " ";
}

void Enigma::mostrarCilindroMoodificado4()
{
	for (int i = 0; i < cilindro1.size(); i++)
		cout << cilindro4Modificado[i] << " ";
}

void Enigma::cifrar()
{
	generarClaves();
	pasarClaves();
	int temPos;
	string tempLetra;
	int contador = 0;
	for (int i = 0; i < mensaje.size(); i++)
	{
		temPos = cilindro5Modificado.find(mensaje[i]);
		tempLetra = cilindro2Modificado[temPos][1];
		for (int j = 0; j < 26; j++)
		{
			if (cilindro3Modificado[j][0] == tempLetra[0])
			{
				temPos = j;
				break;
			}
		}
		tempLetra = cilindro3Modificado[temPos][1];

		for (int j = 0; j < 26; j++)
		{
			if (cilindro4Modificado[j][0] == tempLetra[0])
			{
				temPos = j;
				break;
			}
		}
		tempLetra = cilindro4Modificado[temPos][1];

		cifrado += tempLetra;
		contador++;
		if (contador >= 4)
		{
			string p = cilindro2Modificado[0];
			cilindro2Modificado.erase(cilindro2Modificado.begin());
			cilindro2Modificado.push_back(p);
		}
		if (contador >= 8)
		{
			string p = cilindro3Modificado[0];
			cilindro3Modificado.erase(cilindro3Modificado.begin());
			cilindro3Modificado.push_back(p);
			contador++;
		}
		if (contador >= 12)
		{
			string p = cilindro4Modificado[0];
			cilindro4Modificado.erase(cilindro4Modificado.begin());
			cilindro4Modificado.push_back(p);
		}
	}
}

void Enigma::pasarClaves()
{
	int i;
	for (i = 0; i < alfabeto.size(); i++)
		r1 += cilindro2Modificado[i][1];
	for (i = 0; i < alfabeto.size(); i++)
		r2 += cilindro3Modificado[i][1];
	for (i = 0; i < alfabeto.size(); i++)
		r3 += cilindro4Modificado[i][1];
}

void Enigma::mostrar()
{
	cout << r1 << "\n" << r2 << "\n" << r3 << endl;
}

void Enigma::mensajeCifrado()
{
	cout << cifrado;
}

string Enigma::descifrar()
{
	string temLetra;
	int temPos=0;
	for (int i = 0; i < cifrado.size(); i++)
	{
		temLetra = cifrado[i];
		for (int j = 0; j < cilindro4Modificado.size(); j++)
		{
			if (cilindro4Modificado[j][1] == temLetra[0])
			{
				temPos = j;
				break;
			}
		}
		temLetra = cilindro4Modificado[temPos][0];

		for (int j = 0; j < cilindro3Modificado.size(); j++)
		{
			if (cilindro3Modificado[j][1] == temLetra[0])
			{
				temPos = j;
				break;
			}
		}
		temLetra = cilindro3Modificado[temPos][0];
		for (int j = 0; j < cilindro2Modificado.size(); j++)
		{
			if (cilindro2Modificado[j][1] == temLetra[0])
			{
				temPos = j;
				break;
			}
		}
		temLetra = cilindro2Modificado[temPos][0];
		descifrado += temLetra;
	}
	return descifrado;
}

void Enigma::pasar()
{
	int i;
	for (i = 0; i < alfabeto.size(); i++)
		cilindro2[i][1] = r1[i];

	for (i = 0; i < alfabeto.size(); i++)
		cilindro3Modificado[i][1] = r2[i];

	for (i = 0; i < alfabeto.size(); i++)
		cilindro4Modificado[i][1] = r3[i];
}
