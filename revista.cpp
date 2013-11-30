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
	list<string>::iterator it = palabras_clave.begin();
	bool trobat = false;
	bool repetit = false;
	while(it != palabras_clave.end() and not trobat and not repetit){
		if((*it) < s) ++it;
		else if((*it) == s) repetit = true;
		else{
			trobat = true;
		}
	}
	if(not repetit)palabras_clave.insert(it,s);
}

string Revista::consultar_nombre(){
	return nombre;
}

string Revista::consultar_AreaTematica(const int i){
	if(i == 1) return AreaTematica1;
	if(i == 2) return AreaTematica2;
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

bool Revista::buscar_palabra_clave(const string& nombre){
	bool resultat = false;
	list<string>::const_iterator it = palabras_clave.begin();
	while(it != palabras_clave.end() and not resultat){
		if((*it) == nombre) resultat = true;
		++it;
	}
	return resultat;
}

void Revista::modificar_AreasTematicas(const string area1, const string area2){
	AreaTematica1 = area1;
	AreaTematica2 = area2;
}


