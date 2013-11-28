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


void Estructura::escriure_estructura_arbre(Arbre<string> &a) {
/* Pre: cert */ 
/* Post: El canal estandar de sortida conté el recorregut en inordre d'a */ 
  if (not a.es_buit()) {
    Arbre<string> a1;
    Arbre<string> a2;
    string x = a.arrel();
    a.fills(a1,a2);
    escriure_estructura_arbre(a1); 
    cout << " " << x;
    escriure_estructura_arbre(a2);
    a.plantar(x,a1,a2);
  }
}


void Estructura::escriure_estructura(){
	escriure_estructura_arbre(clasificacion);
}

void Estructura::llegir_estructura(){
	llegir_estructura_arbre(clasificacion);
}

string Estructura::criterio1(Revista& r1){
	string res;
	int tamany = r1.num_pal_clave();
	vector<bool> b(tamany, false);
	list<string> pc;
	r1.list_palabras_clave(pc);
	Arbre<string> a = clasificacion;
	int nivellres = 0;
	int nivell = 0;
	clas_criterio1(a, b, pc, nivell, res, nivellres);
	cout << endl;
	return res;
}

void Estructura::clas_criterio1(Arbre<string>& a, vector<bool>& b, const list<string>& pc, int& nivell, string& res, int& nivellres){
	if(not a.es_buit()){
		string s = a.arrel();
		Arbre<string> ae, ad;
		a.fills(ae,ad);
		if(ae.es_buit() and ad.es_buit()){
			list<string>::const_iterator it = pc.begin();
			int i = 0;
			while(it != pc.end()){
				if((*it) == s) b[i] = true;
				++it;
				++i;
			}
		}
		else {
			int nivellE = nivell+1;
			int nivellD = nivell+1;
			string resE, resD;
			vector<bool> be (b.size(), false);
			vector<bool> bd (b.size(), false);
			int nivellresE, nivellresD;
			nivellresE = nivellresD = 0;
			if(not ae.es_buit())clas_criterio1(ae, be, pc, nivellE, res, nivellres);
			if(not ad.es_buit())clas_criterio1(ad, bd, pc, nivellD, res, nivellres);
			bool alltrueE = true;
			bool alltrueD = true;
			for(int m = 0; m < b.size(); ++m){
				if(be[m] == false)alltrueE = be[m];
				if(bd[m] == false)alltrueD = bd[m];
			}
			if(alltrueE){
				if(alltrueD){
					if(nivellE >= nivellD){
						if(nivellE > nivellres){
							res = ae.arrel();
							nivellres = nivellE;
						}
						if(nivellE == nivellD){
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
					else{
						if(nivellD > nivellres){
							res = ad.arrel();
							nivellres = nivellD;
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
			else if(alltrueD){
				if(nivellD > nivellres){
					res = ad.arrel();
					nivellres = nivellD;
				}
			}
			for(int i = 0; i < b.size(); ++i) b[i] = be[i] or bd[i];
			bool alltrue = true;
			for(int j = 0; j < b.size(); ++j) if(b[j] == false) alltrue = false;
			if(alltrue){
				if(nivell > nivellres) {
					res = s;
					nivellres = nivell;
				 }
			 }
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
		cout << s << " " << b  << " " << be << " " << bd  << " " << res<< endl;

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
