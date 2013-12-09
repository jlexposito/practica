#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "revista.hpp"

class Biblioteca {

private:
	vector<list<Revista> > llibreria;
	vector<list<pair<string, string> > > lcriteri2;

    /** @brief Buscar revistas.
        \pre cierto.
        \post Si b1 es cierto it1 apunta a la revista con nombre r1 y si b2 es cierto it2 apunta la revista r2.
    */
	void buscar_revistas(const string r1, const string r2, bool& b1, bool& b2, list<Revista>::iterator& it1, list<Revista>::iterator& it2);

    /** @brief Eliminar revista iterador.
        \pre it e it2 apuntan a una revista que existe
        \post todas las apariciones de la revista han sido eliminadas del parametro implicito
    */
    void eliminar_revista_iterador(list<Revista>::iterator& it, list<pair<string, string> >::iterator& it2, const int calidad);
	
	
public:
    /*Creadoras*/

    /** @brief Añadir revista.
        \pre esta preparada la revista en el canal de entrada.
        \post se ha añadido al parámetro implícito la revista.
    */
    void anadir_revista(Revista& r);
    Biblioteca (int n);

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

    /** @brief Escritora de Revistas por critero1.
         \pre cierto
         \post El canal estándar de salida contiene las revistas de calidad "calidad" ordenadas según el criterio1 alfabéticamente.
    */
	
	void listar_criterio1(const int& calidad);

    /** @brief Escritora de Revistas por critero2.
         \pre cierto
         \post El canal estándar de salida contiene las revistas de calidad "calidad" ordenadas según el criterio2 alfabéticamente.
    */

	void listar_criterio2(const int& calidad);

    /** @brief Reordenar areas.
         \pre Las estructuras del parámetro implícito contienen la revista r pero estan desordenadas segun crtiterio 1 y criterio 2
         \post Las estructuras del parámetro implícito contienen la revista r, ordenadas según criterio 1 y criterio 2
    */
	void reordenar_areas(Revista& r, const int& calidad, const string& nombre, list<Revista>::iterator& it);

    /** @brief Buscar revista criterio 1.
         \pre cierto
         \post Si b1 es cierto it apunta a la revista que buscamos en la estructura del del p.i. del criterio 1
    */
    void buscar_revista_criterio1(const string r1, bool& b1, list<Revista>::iterator& it1);

    /** @brief Buscar revista criterio 2.
         \pre cierto
         \post it apunta a la revista que buscamos en la estructura del del p.i. del criterio 2
    */
    void buscar_revista_criterio2(const int& calidad, const string nombre, list<pair<string, string> >::iterator& it1);

};

#endif
