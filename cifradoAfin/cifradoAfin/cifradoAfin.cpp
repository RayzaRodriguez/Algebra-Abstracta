// cifradoAfin.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "afin.h"
#include <iostream>

using namespace std;

int main()
{
	string mensaje = "hola como";
	string cifrado = "H2TnAt2W2";
	string descifrado = "";
	afin a(64);
	/*a.generarClaveA();
	a.generarClaveB();
	cout << a.cifrado(mensaje)<<endl;*/
	int cla = a.euclidesExtendido(3);
	cout << a.descifrado(cifrado,cla,13) << endl;
    return 0;
}

