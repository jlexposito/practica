#ifndef ESTRUCTURA_HPP
#define ESTRUCTURA_HPP

#include "Arbre.hpp"
#include <string>
#include "revista.hpp"

class Estructura{

private:
	Arbre<string> clasificacion;
	static void anadir_palabra(list<string>& l, string& s);
	static void juntar_listas(list<string>& l1, list<string>& l2);
	static void listar_lista(list<string> l);
public:

    /** @brief Clasificar criterios.
        \pre cierto.
        \post se ha clasificado la revista segun el criterio.
    */
    void clasificar_criterios(Revista& r, int criterio);

    /** @brief Lectora por defecto
        \pre Esta preparada en el canal estandar de entrada la estructura del arbol.
        \post el arbol a contiene la clasificacion leida del canal estandar de entrada.
    */
    void llegir_estructura();
    static void llegir_estructura_arbre(Arbre<string>& a);
    static string busqueda_critero1(Revista& r);
    static string busqueda_criterio2(Revista& r);

    /** @brief Escritora de la estructura del arbol.
         \pre cierto
         \post El canal estandar de salida contiene el recorrido en inordren de a.
    */
    void escriure_estructura_arbre(Arbre<string>& a);
    void escriure_estructura();
    string criterio1(Revista& r1);
    void clas_criterio1(Arbre<string>& a, list<string>& l, Revista& r1, int& nivell, string& res, int& nivellres);
    void clas_criterio2(Arbre<string>& a, Revista& r1, bool& b, string& res);
    string criterio2(Revista& r);
};

#endif
