#include "biblioteca.hpp"

Biblioteca::Biblioteca(int n){
	calidad_maxima = n;
}
void Biblioteca::anadir_revista(Revista& r){
	list<Revista>::iterator it = llibreria.begin();
	bool trobat = false;
	int calidad = r.consultar_calidad();
	while(it != llibreria.end() and not trobat){
		if((*it).consultar_calidad() <= calidad) {
			++it;
		}
		else trobat = true;
	}
	llibreria.insert(it,r);
}

void Biblioteca::listar_revistas_all(){
	list<Revista>::iterator it;
	it = llibreria.begin();
	while(it != llibreria.end()) {
		cout << "REVISTA " << (*it).consultar_nombre() << endl;
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

void Biblioteca::ordenar_criteri(const int& criteri, const int& calidad_min){
	list<Revista>::iterator it = llibreria.begin();
	int actual = 0;
	pair<string, string> x;
	list<pair<string,string> > res;
	list<pair<string,string> >::iterator it1 = res.begin();
	int tamany = 0;
	string area, nombre;
	while(it != llibreria.end() and actual <= calidad_min){
		actual = (*it).consultar_calidad();
		if(actual == calidad_min) {
			nombre = (*it).consultar_nombre();
			area = (*it).consultar_AreaTematica(criteri);
			x.first = nombre;
			x.second = area;
			if(tamany == 0) {
				res.insert(it1,x);
			}
			else {
				it1 = res.begin();
				bool trobat  = false;
				while(it1 != res.end() and not trobat){
					if((*it1).second < area) ++it1;
					else if ((*it1).second == area){
						if((*it1).first < nombre) ++it1;
						else trobat  = true;
					}
				}
				res.insert(it1,x);
			}
			++tamany;
		}
		++it;
	}
	it1 = res.begin();
	while(it1 != res.end()){
		cout << (*it1).second  << " " << (*it1).first <<  endl;
		++it1;
	}				
}

