#include "biblioteca.hpp"
#include "estructura.hpp"

int main(){
	Biblioteca b;
	Estructura c;
	c.llegir_estructura();
	//cout << "ESTRUCTURA LLEGIDA!" << endl;
	int operacion = readint();
	while(operacion != -6){
		if(operacion == -1){
			//cout << "<< AFEGIR REVISTA >>" << endl;
			b.anadir_revista();
		}
		if(operacion == -2){
			//cout << "<< LISTAR REVISTAS >>" << endl;
			b.listar_revistas_all();
		}		
		if(operacion == -3){
			//cout << "<< FUSIONAR REVISTA >>" << endl;
			string r1, r2;
			r1 = readstring();
			r2 =  readstring();
			bool b1;
			list<Revista>::iterator it;
			b.fusionar_revistas(r1, r2, it, b1);
			if(b1){
				Revista r = (*it);
				string nombre = c.criterio1(r);
				cout << nombre << endl;
				string mierder = c.criterio2(r);
				cout << mierder << endl;
				//cout << "RECORREGUT ACABAT" << endl;
				int area = 1;
				//(*it).asignar_area(area, nombre);
			}
		}
		if(operacion == -4){
			cout << "<< ELIMINAR REVISTA >>" << endl;
			string r1 = readstring();
			b.eliminar_revista(r1);
		}
		operacion = readint();
	}
}
