#include "biblioteca.hpp"

Biblioteca::Biblioteca(int n){
	calidad_maxima = n;
}
void Biblioteca::anadir_revista(){
	Revista r;
	r.leer_revista();
	list<Revista>::iterator it;
	it = llibreria.end();
	llibreria.insert(it,r);
}

void Biblioteca::listar_revistas_all(){
	list<Revista>::iterator it;
	it = llibreria.begin();
	while(it != llibreria.end()) {
		cout << (*it).consultar_nombre() << endl;
		int size = (*it).num_pal_clave();
		(*it).listar_palabras_clave();
		cout << (*it).consultar_calidad() << endl;
		++it;
	}
}

void Biblioteca::buscar_revistas(const string r1, const string r2, bool& b1, bool& b2, list<Revista>::iterator& it1, list<Revista>::iterator& it2){
	list<Revista>::iterator it;
	it = llibreria.begin();
	while(it != llibreria.end()){
		string nom = (*it).consultar_nombre();
		if(nom == r1){
			it1 = it;
			b1 = true;
		}
		else if(nom == r2){
			it2 = it;
			b2 = true;
		}
		++it;
	}
}
void Biblioteca::buscar_revista(const string r1, bool& b1, list<Revista>::iterator& it1){
	list<Revista>::iterator it;
	it = llibreria.begin();
	while(it != llibreria.end()){
		string nom = (*it).consultar_nombre();
		if(nom == r1){
			it1 = it;
			b1 = true;
		}
		++it;
	}
}

void Biblioteca::eliminar_revista_iterador(list<Revista>::iterator& it){
	it = llibreria.erase(it);
}
	
void Biblioteca::eliminar_revista(string nombre){
	list<Revista>::iterator it;
	bool b = false;
	buscar_revista(nombre, b, it);
	if(b) eliminar_revista_iterador(it);
}


void Biblioteca::fusionar_revistas(const string r1, const string r2, list<Revista>::iterator& it, bool& b1){
	bool b2;
	b1 = b2 = false;
	list<Revista>::iterator it1, it2;
	buscar_revistas(r1, r2, b1, b2, it1, it2);
	if(b1 and b2) {
		string palabra;
		int tamany = (*it2).num_pal_clave();
		for(int i = 1; i <= tamany; ++i){
			palabra = (*it2).consultar_palabra_clave(i);
			(*it1).anadir_palabras_clave(palabra);
		}
		eliminar_revista_iterador(it2);
		it = it1;
	}
	if(b1) it = it1;
}

