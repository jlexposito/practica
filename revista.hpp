#ifndef REVISTA_HPP
#define REVISTA_HPP
//#include "utils.PRO2"
//#include <list>
//#include <string>
//#include <vector>

class Revista { 

private:
	int calidad;
	string nombre;
	list<string> palabras_clave;
	string AreaTematica1, AreaTematica2;

public:
    /* Modificadoras */
    /** @brief Modificadora areas tematicas.
        \pre cierto.
        \post el parametro implicito tiene area1 y area2 como sus areas asociadas.
    */
    void modificar_AreasTematicas(const string area1, const string area2);
    /** @brief Añadir palabras clave.
        \pre cierto.
        \post las pclave se añaden a la revista.
    */
    void anadir_palabras_clave(string s);

    /* Consultoras */

    /** @brief Consultora del nombre de la revista
        \pre cierto.
        \post El resultado es nombre del parámetro implícito.
    */
	const string consultar_nombre();

    /** @brief Consultora de la iessima palabra clave.
        \pre cierto.
        \post El resultado es la iessima palabra clave.
    */
    
    bool buscar_palabra_clave(const string& nombre);

    /** @brief Consultar Palabra clave
        \pre cierto.
        \post El resultado es la palabra clave de posicion iessima.
    */
    const string consultar_palabra_clave(const int i);

    /** @brief Consultor Area Tematica
        \pre cierto.
        \post El resultado es el area tematica del parámetro implícito.
    */
    const string consultar_AreaTematica(const int i);

    /** @brief Consultora numero de palabras clave
        \pre cierto.
        \post El resultado es el numero de palabras clave que tiene el parametro implicito.
    */
    const int num_pal_clave();

    /** @brief Consultora calidad
        \pre cierto.
        \post El resultado la calidad que tiene el parametro implicito.
    */
    const int consultar_calidad();
    /* Lectoras  y escritoras */
    /** @brief Lectora por defecto
        \pre Estan preparados en el canal de entrada toda la información de la revista.
        \post Se le ha asignado a la revista todos sus parámetros.
    */
    void leer_revista();

};

#endif
