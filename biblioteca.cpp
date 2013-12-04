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
}

void Biblioteca::listar_criterio1(const int& calidad){
	list<Revista>::iterator it = llibreria[calidad-1].begin();
	while (it != llibreria[calidad-1].end()){
		cout << (*it).consultar_AreaTematica(1) << " " << (*it).consultar_nombre() << endl;
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
void Biblioteca::buscar_revista(const string r1, bool& b1, list<Revista>::iterator& it1){
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

void Biblioteca::eliminar_revista_iterador(list<Revista>::iterator& it, const int calidad){
	it = llibreria[calidad-1].erase(it);
}
	
void Biblioteca::eliminar_revista(string nombre){
	list<Revista>::iterator it;
	bool b = false;
	buscar_revista(nombre, b, it);
	int calidad  = (*it).consultar_calidad();
	if(b) eliminar_revista_iterador(it, calidad);
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
		eliminar_revista_iterador(it2, calidadrev);
		it = it1;
	}
	if(b1) it = it1;
}

