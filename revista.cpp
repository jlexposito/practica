#include "revista.hpp"

void Revista::leer_revista(){
	nombre = readstring();
	string palabra_clave =  readstring();
	while(palabra_clave != "."){
		anadir_palabras_clave(palabra_clave);
		palabra_clave =  readstring();
	}
	cin >> calidad;
}

void Revista::anadir_palabras_clave(string s){
	list<string>::iterator it;
	it = palabras_clave.end();
	palabras_clave.insert(it,s);
}

string Revista::consultar_nombre(){
	return nombre;
}

string Revista::consultar_palabra_clave(const int i){
	list<string>::iterator it;
	it = palabras_clave.begin();
	int n = 1;
	while (n < i){
		++it;
		++n;
	}
	return *it;
}

void Revista::listar_palabras_clave(){
	list<string>::iterator it;
	it = palabras_clave.begin();
	while (it != palabras_clave.end()){
		cout << (*it) << endl;
		++it;
	}
}

int Revista::num_pal_clave(){
	return palabras_clave.size();
}

int Revista::consultar_calidad(){
	return calidad;
}

void Revista::list_palabras_clave(list<string>& pc){		//NO VALIDO
	pc = palabras_clave;
}

