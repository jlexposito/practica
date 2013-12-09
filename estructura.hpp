#ifndef ESTRUCTURA_HPP
#define ESTRUCTURA_HPP

//#include "Arbre.hpp"
//#include <string>
#include "revista.hpp"

class Estructura{

private:
	Arbre<string> clasificacion;

    /** @brief anadir palabra.
         \pre cierto
         \post la lista de strings l ahora contiene s ordenada alfabeticamente
    */
	static void anadir_palabra(list<string>& l, string& s);

    /** @brief Juntar listas.
         \pre cierto
         \post l1 es el resultado de combinar ambas listas.
    */
	static void juntar_listas(list<string>& l1, list<string>& l2);

    /** @brief Clas criterio2.
         \pre cierto
         \post res contiene la area tematica asociada a la revista r por criterio 2.
    */
	void clas_criterio1(Arbre<string>& a, list<string>& l, Revista& r1, int& nivell, string& res, int& nivellres);

    /** @brief Clas criterio2.
         \pre cierto
         \post res contiene la area tematica asociada a la revista r por criterio 2.
    */
    void clas_criterio2(Arbre<string>& a, Revista& r1, bool& b, string& res);

    /** @brief Lectora por defecto de arbol
        \pre Esta preparada en el canal estandar de entrada la estructura del arbol.
        \post el arbol a contiene la clasificacion leida del canal estandar de entrada.
    */
    static void llegir_estructura_arbre(Arbre<string>& a);

public:

    /** @brief Lectora por defecto
        \pre Esta preparada en el canal estandar de entrada la estructura del arbol.
        \post el arbol a contiene la clasificacion leida del canal estandar de entrada.
    */
    void llegir_estructura();

    /** @brief Criterio1.
         \pre R es una revista que existe en la biblioteca
         \post El resultado es la area tematica asociada a la revista r por criterio 2.
    */
    string criterio1(Revista& r1);

    /** @brief Criterio1.
         \pre R es una revista que existe en la biblioteca
         \post El resultado es la area tematica asociada a la revista r por criterio 2.
    */
    string criterio2(Revista& r);
};

#endif
