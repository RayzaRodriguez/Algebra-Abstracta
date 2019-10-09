#include <iostream>
#include "Enigma.h"

int main()
{
	//CIFRAR//
	
	/*string mensaje = "dora";
	Enigma a(mensaje);
	a.cifrar();
	cout << endl;
	cout << endl;
	a.mostrarClaves();
	cout << endl;
	a.mostrarCilindro2();
	a.mostrarCilindro3();
	a.mostrarCilindro4();
	cout << endl;
	a.mostrarCilindroMoodificado5();
	cout << endl;
	a.mostrarCilindroMoodificado2();
	cout << endl;
	a.mostrarCilindroMoodificado3();
	cout << endl;
	a.mostrarCilindroMoodificado4();
	cout << endl; cout << endl;
	a.mensajeCifrado();
	cout << endl;
	a.mostrar();
	*/

	//DESCIFRAR//
	
	string mensaje = "vuoh";
	string c1="y";
	string c2="h";
	string c3="t";
	string r1= "skwpvyuriblqahdmctzgefnxjo";
	string r2="phrkgmdqwbeyocxlzafsvnjtui";
	string r3="wrcpgjhozfmvlkyiasedxtunqb";
	Enigma a(mensaje, c1, c2, c3, r1, r2, r3);
	cout<<"Descifrado "<<a.descifrar()<<endl;

	cout << endl;
	a.mostrarClaves();
	cout << endl;
	a.mostrarCilindro2();
	cout << endl;
	a.mostrarCilindro3();
	cout << endl;
	a.mostrarCilindro4();
	cout << endl;
	cout << endl;
	a.mostrarCilindroMoodificado2();
	cout << endl;
	a.mostrarCilindroMoodificado3();
	cout << endl;
	a.mostrarCilindroMoodificado4();
	cout << endl; cout << endl;

}