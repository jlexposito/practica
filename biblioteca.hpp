#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "revista.hpp"

class Biblioteca {

private:
	list<Revista> llibreria;
	int nrevistas;
	
	//PLANTEAR COMO ORDENAR PARA CRITERIOS!!

public:
    /*Creadoras*/

    /** @brief Añadir revista.
        \pre esta preparada la revista en el canal de entrada.
        \post se ha añadido al parámetro implícito la revista.
    */
    void anadir_revista();

    /** @brief Eliminar revista.
        \pre cierto.
        \post la revista ha sido eliminada del parámetro implícito.
    */
    void eliminar_revista(const string nombre);

    /** @brief Fusionar revista.
        \pre cierto.
        \post se han fusionado la revista r1 con r2.
    */
    void fusionar_revistas(const string r1, const string r2, list<Revista>::iterator& it, bool& b1);

    /** @brief Escritora de Revistas.
         \pre cierto
         \post El canal estándar de salida contiene todas las revistas.
    */
    void listar_revistas(int n, int criterio);
    void listar_revistas_all();
    void buscar_revistas(const string r1, const string r2, bool& b1, bool& b2, list<Revista>::iterator& it1, list<Revista>::iterator& it2);
    void buscar_revista(const string r1, bool& b1, list<Revista>::iterator& it1);
    void eliminar_revista_iterador(list<Revista>::iterator& it);

};

#endif
