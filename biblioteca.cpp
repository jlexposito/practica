#include "biblioteca.hpp"

Biblioteca::Biblioteca(int n){
	llibreria = vector<list<Revista> > (n);
	lcriteri2 = vector<list<pair<string, string> > > (n);
}
void Biblioteca::anadir_revista(Revista& r){
	bool trobat = false;
	int calidad = r.consultar_calidad();
	string area1 = r.consultar_AreaTematica(1);
	list<Revista>::iterator it = llibreria[calidad-1].begin();
	while(it != llibreria[calidad-1].end() and not trobat){
		if((*it).consultar_AreaTematica(1) > area1) trobat = true;
		else ++it;
	}
	llibreria[calidad-1].insert(it,r);
	list<pair<string, string> >::iterator it2 = lcriteri2[calidad-1].begin();
	trobat = false;
	string area2 = r.consultar_AreaTematica(2);
	while(it2 != lcriteri2[calidad-1].end() and not trobat){
		if((*it2).first > area2) trobat = true;
		else ++it2;
	}
	pair<string, string> x;
	x.first = area2;
	x.second = r.consultar_nombre();	
	lcriteri2[calidad-1].insert(it2,x);
}

void Biblioteca::listar_criterio1(const int& calidad){
	list<Revista>::iterator it = llibreria[calidad-1].begin();
	while (it != llibreria[calidad-1].end()){
		cout << (*it).consultar_AreaTematica(1) << " " << (*it).consultar_nombre() << endl;
		++it;
	}
}

void Biblioteca::listar_criterio2(const int& calidad){
	list<pair<string, string> >::iterator it = lcriteri2[calidad-1].begin();
	while (it != lcriteri2[calidad-1].end()){
		cout << (*it).first << " " << (*it).second << endl;
		++it;
	}
}

void Biblioteca::buscar_revistas(const string r1, const string r2, bool& b1, bool& b2, list<Revista>::iterator& it1, list<Revista>::iterator& it2){
	int i = 0;
	list<Revista>::iterator it; 
	while(i < llibreria.size() and not (b1 and b2)) {
		it = llibreria[i].begin();
		while(it != llibreria[i].end()){
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
		++i;
	}
}
void Biblioteca::buscar_revista_criterio1(const string r1, bool& b1, list<Revista>::iterator& it1){
	int i = 0;
	while(i < llibreria.size() and not b1) {
		list<Revista>::iterator it;
		it = llibreria[i].begin();
		while(it != llibreria[i].end() and not b1){
			string nom = (*it).consultar_nombre();
			if(nom == r1){
				it1 = it;
				b1 = true;
			}
			++it;
		}
		++i;
	}
}

void Biblioteca::buscar_revista_criterio2(const int& calidad, const string nombre, list<pair<string, string> >::iterator& it1){
	bool trobat  = false;
	while(it1 != lcriteri2[calidad-1].end() and not trobat){
		if((*it1).second == nombre) trobat = true;
	}
}	

void Biblioteca::eliminar_revista_iterador(list<Revista>::iterator& it, list<pair<string, string> >::iterator& it2, const int calidad){
	it = llibreria[calidad-1].erase(it);
	it2 = lcriteri2[calidad-1].erase(it2);
}
	
void Biblioteca::eliminar_revista(string nombre){
	list<Revista>::iterator it;
	bool b = false;
	buscar_revista_criterio1(nombre, b, it);
	int calidad  = (*it).consultar_calidad();
	if(b) {
		list<pair<string, string> >::iterator it2 = lcriteri2[calidad-1].begin();
		buscar_revista_criterio2(calidad, nombre, it2);
		eliminar_revista_iterador(it, it2, calidad);
	}
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
		int calidadrev = (*it2).consultar_calidad();
		list<pair<string, string> >::iterator it3 = lcriteri2[calidadrev-1].begin();
		buscar_revista_criterio2(calidadrev, r2, it3);
		eliminar_revista_iterador(it2, it3, calidadrev);
		it = it1;
	}
	if(b1) it = it1;
}

