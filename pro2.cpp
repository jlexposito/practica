#include "biblioteca.hpp"
#include "estructura.hpp"

int main(){
	int n = readint();
	Biblioteca b(n);
	Estructura c;
	c.llegir_estructura();
	//cout << "ESTRUCTURA LLEGIDA!" << endl;
	int operacion = readint();
	while(operacion != -6){
		if(operacion == -1){		//ALTA REVISTA
			//cout << "<< AFEGIR REVISTA >>" << endl;
			Revista r;
			r.leer_revista();
			string area1 = c.criterio1(r);
			string area2 = c.criterio2(r);
			//cout << area1 << " <<AREA1 AREA2>> " << area2 << endl;
			r.modificar_AreasTematicas(area1, area2);
			b.anadir_revista(r);
			//cout << "ACABADO " << endl;
		}
		else if(operacion == -2){
			//cout << "<< ELIMINAR REVISTA >>" << endl;
			string r1 = readstring();
			b.eliminar_revista(r1);
		}
		else if(operacion == -3){		//FUSIONAR REVISTAS
			//cout << "<< FUSIONAR REVISTA >>" << endl;
			string r1, r2;
			r1 = readstring();
			r2 =  readstring();
			bool b1;
			list<Revista>::iterator it;
			b.fusionar_revistas(r1, r2, it, b1);
			if(b1){
				Revista r = (*it);
				string area1 = c.criterio1(r);
				string area2 = c.criterio2(r);
				(*it).modificar_AreasTematicas(area1, area2);
			}
		}
		else if (operacion == -4){
			int calidad = readint();
			int criterio = readint();
			cout << "Revista de calidad " << calidad << " por criterio " << criterio << endl;
			if(criterio == 1) b.listar_criterio1(calidad);
			else b.listar_criterio2(calidad);
			cout << endl;
		}
		else if (operacion == -5){		//CONSULTA DE REVISTAS POR TÍTULO
			string r1 = readstring();
			cout << "Consulta de revista por titulo "<< endl;
			list<Revista>::iterator it1;
			bool b1 = false;
			b.buscar_revista_criterio1(r1, b1, it1);
			if(b1){
				cout << (*it1).consultar_nombre() << endl;
				int tamany = (*it1).num_pal_clave();
				for(int i = 1; i <= tamany; ++i) cout << (*it1).consultar_palabra_clave(i) << " ";
				cout << endl;
				cout << (*it1).consultar_AreaTematica(1) << " " << (*it1).consultar_AreaTematica(2) << endl;
				cout << (*it1).consultar_calidad() << endl;
			}
			else cout << "La revista " << r1 << " no existe"<< endl;
			cout << endl;
		}	
		operacion = readint();
	}
}
