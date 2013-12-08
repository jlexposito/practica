#include "estructura.hpp"
#include "revista.hpp"

void Estructura::llegir_estructura_arbre(Arbre<string>& a){
	Arbre<string> a1;
	Arbre<string> a2;
	string x;
	cin >> x;
	if (x != ".") {
	llegir_estructura_arbre(a1);
	llegir_estructura_arbre(a2);
	a.plantar(x,a1,a2);
  }
}

void Estructura::anadir_palabra(list<string>& l, string& s){
	list<string>::iterator it = l.begin();
	bool trobat = false;
	bool repetit = false;
	while(it != l.end() and not trobat){
		if((*it) == s) {
			repetit = true;
			trobat = true;
		}
		else if((*it) > s) trobat = true;
		else ++it;
	}
	l.insert(it, s);
}

void Estructura::juntar_listas(list<string>& l1, list<string>& l2){
	list<string>::iterator it1;
	list<string>::iterator it2;
	it1 = l1.begin();
	it2 = l2.begin();
	while(it1 != l1.end() and it2 != l2.end()){
		if((*it1) == (*it2)) ++it2;
		else if((*it1) > (*it2)) {
			l1.insert(it1, (*it2));
			++it2;
		}
		else ++it1;
	}
	if(it1 == l1.end() and it2 != l2.end()){
		while(it2 != l2.end()) {
			l1.insert(l1.end(), (*it2));
			++it2;
		}
	}
	
}

void Estructura::llegir_estructura(){
	llegir_estructura_arbre(clasificacion);
}

string Estructura::criterio1(Revista& r1){
	string res;
	int tamany = r1.num_pal_clave();
	if(tamany > 1){
		list<string> l;
		Arbre<string> a = clasificacion;
		int nivellres = 0;
		int nivell = 0;
		clas_criterio1(a, l, r1, nivell, res, nivellres);
	}
	else res = r1.consultar_palabra_clave(1);
	return res;
}

void Estructura::clas_criterio1(Arbre<string>& a, list<string>& l, Revista& r1, int& nivell, string& res, int& nivellres){
	if(not a.es_buit()){
		string s = a.arrel();
		Arbre<string> ae, ad;
		a.fills(ae,ad);
		if(ae.es_buit() and ad.es_buit()){
			//COMPROVAR SI ES PC
			bool b = r1.buscar_palabra_clave(s);
			if (b) anadir_palabra(l,s);
		}
		else {
			int nivellE = nivell+1;
			int nivellD = nivell+1;
			string resE, resD;
			list<string> le;
			list<string> ld;
			int nivellresE, nivellresD;
			nivellresE = nivellresD = 0;
			if(not ae.es_buit())clas_criterio1(ae, le, r1, nivellE, res, nivellres);
			if(not ad.es_buit())clas_criterio1(ad, ld, r1, nivellD, res, nivellres);
			if(le.size() == r1.num_pal_clave()){
				if(ld.size() == r1.num_pal_clave()){
					if(nivellE > nivellD){
						if(nivellE > nivellres){
							res = ae.arrel();
							nivellres = nivellE;
						}
					}
					else if (nivellD > nivellE){
						if(nivellD > nivellres){
							res = ad.arrel();
							nivellres = nivellD;
						}
					}
					else{
						if(nivellE > nivellres){
							if(ae.arrel() < ad.arrel()){
								res = ae.arrel();
								nivellres = nivellE;
							}
							else {
								res = ad.arrel();
								nivellres = nivellD;	
							}
						}
					}
				}
				else{
					if(nivellE > nivellres){
						res = ae.arrel();
						nivellres = nivellD;
					}
				}
			}
			else if(ld.size() == r1.num_pal_clave()){
				if(nivellD > nivellres){
					res = ad.arrel();
					nivellres = nivellD;
				}
			}
			//juntar listas
			juntar_listas(le, ld);
			l = le;
			if(l.size() == r1.num_pal_clave()){
				if(nivell >= nivellres) {
					res = s;
					nivellres = nivell;
				 }
			 }
			 //cout << s << " NivelE " << nivellE << " " << l.size() << " NivellD " << nivellD << " " << le.size() << " " << ld.size() << " " << res << " " << nivellres << endl;
		}
		
		a.plantar(s, ae, ad);			
	}
}

void Estructura::clas_criterio2(Arbre<string>& a, Revista& r1, bool& b, string& res){
	if(not a.es_buit()){
		string s = a.arrel();
		Arbre<string> ae, ad;
		a.fills(ae,ad);
		bool be, bd;
		be = bd = false;
		if(ae.es_buit() and ad.es_buit()){
			b = r1.buscar_palabra_clave(s);
			if(b)res = s;
		}
		else{
			clas_criterio2(ae, r1, be, res);
			clas_criterio2(ad, r1, bd, res);
			b = bd or be;
			if(be and bd){
				res  = s;
				b = bd;
			}
		}
		a.plantar(s, ae, ad);
	}
}

string Estructura::criterio2(Revista& r){
	bool b = false;
	string res;
	Arbre<string> a = clasificacion;
	clas_criterio2(a, r, b, res);
	return res;
}
