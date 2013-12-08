#ifndef REVISTA_HPP
#define REVISTA_HPP
#include "utils.PRO2"
#include <list>
#include <string>
#include <vector>

class Revista { 

private:
	int calidad;
	string nombre;
	list<string> palabras_clave;
	string AreaTematica1, AreaTematica2;

public:
    /* Creadoras */

    /** @brief Añadir palabras clave.
        \pre cierto.
        \post las pclave se añaden a la revista.
    */
    void anadir_palabras_clave(string s);

    /* Modificadoras */
    
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

    void buscar_revista(const string nombre, int& i);
    
    bool buscar_palabra_clave(const string& nombre);

    const string consultar_palabra_clave(const int i);

    /** @brief Consultora del nombre del Area Tematica según clasificación
        \pre cierto.
        \post El resultado es el area tematica del parámetro implícito.
    */
    const string consultar_AreaTematica(const int i);

    /* Lectoras  y escritoras */
    /** @brief Lectora por defecto
        \pre Estan preparados en el canal de entrada toda la información de la revista.
        \post Se le ha asignado a la revista todos sus parámetros.
    */
    void leer_revista();
	int num_pal_clave();
	const int consultar_calidad();
	void modificar_AreasTematicas(const string area1, const string area2);
};

#endif
