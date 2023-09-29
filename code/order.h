#include <iostream>
#include <string>
#include <vector>
#include "foodmaker.h"

using namespace std;

// Clase Order que puede contener Comida, Refresco y Postre
class Order
{
private:
    vector<Comida> comidas;
    vector<Refresco> refrescos;
    vector<Postre> postres;

public:
    void agregarComida(const Comida &comida)
    {
        comidas.push_back(comida);
    }

    void agregarRefresco(const Refresco &refresco)
    {
        refrescos.push_back(refresco);
    }

    void agregarPostre(const Postre &postre)
    {
        postres.push_back(postre);
    }

    vector<Comida> obtenerComidas()
    {
        return comidas;
    }

    vector<Refresco> obtenerRefrescos()
    {
        return refrescos;
    }

    vector<Postre> obtenerPostres()
    {
        return postres;
    }
};

// Clase que mantiene una cola de objetos Order
