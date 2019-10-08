#include<stdio.h>
#include<fstream>
#include<ostream>
#include <string>
#include"prueba.h"

using namespace std;

int main()
{
	//CIFRAR
	/*ifstream men;
	ofstream cif;
	string mensaje;
	men.open("../mensaje.txt");
	cif.open("../cifrado.txt");
	getline(men, mensaje);
	prueba a(mensaje);
	cif << a.cifrado();
	cif << "\n";
	cif << a.imprimirClaveString();
	men.close();
	cif.close();
	*/

	//DESCIFRAR
	
	ifstream cif;
	ofstream des;
	string mensaje;
	string clave;
	cif.open("../cifrado.txt");
	des.open("../descifrado.txt");
	string tem;
	int cont=0;
	while (getline(cif, tem))
	{
		if (cont == 1)
			clave = tem;
		else
			mensaje = tem;
		cont++;
	}
	prueba a(mensaje,clave);
	des << a.descifrado();
	cif.close();
	des.close();
	
	return 0;
}
