
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "config.h"
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class JSON {
private:
    Setting configuracionSimulador;
    
    json comidas;
    json refrescos;
    json postres;

    // Accede a los elementos de inventario
    
    json pila_comidas;
    json pila_refrescos;
    json pila_postres;

public:
    JSON(const json& json_data) {
        configuracionSimulador.simulationTime = json_data["tiempoSimulacionHora"];
        configuracionSimulador.minHora = json_data["minHora"];
        configuracionSimulador.maxHora = json_data["maxHora"];
        configuracionSimulador.velocidadDeLlegada = json_data["velocidadDeLlegada"];
        configuracionSimulador.ventanasParaPedido = json_data["ventanasParaPedido"];
        configuracionSimulador.velocidadParaAtender = json_data["velocidadParaAtender"];
        configuracionSimulador.ventanasParaRetirar = json_data["ventanasParaRetirar"];
        configuracionSimulador.velocidadParaRetirar = json_data["velocidadParaRetirar"];
        configuracionSimulador.cantMaximaPorVentana = json_data["cantMaximaporVentana"];
        configuracionSimulador.cantidadMaxIngrediente = json_data["cantidadMaxIngrediente"];
        
        // Accede a los elementos del menú
        
        comidas = json_data["menu"]["comidas"];
        refrescos = json_data["menu"]["refrescos"];
        postres = json_data["menu"]["postres"];

        // Accede a los elementos de inventario
        
        pila_comidas = json_data["inventario"]["pila_comidas"];
        pila_refrescos = json_data["inventario"]["pila_refrescos"];
        pila_postres = json_data["inventario"]["pila_postres"];
    }

    // Métodos para acceder a la información del menú
    json getMenuComidas() const {
        return comidas;
    }

    json getMenuRefrescos() const {
        return refrescos ;
    }

    json getMenuPostres() const {
        return postres;
    }

    json getPilaComidas()  const {
        return pila_comidas;
    }

    json getPilaRefrescos() const {
        return pila_refrescos;
    }

    json getPilaPostres() const {
        return pila_postres;
    }

    // Métodos para acceder a la configuración del simulador
    Setting getConfiguracionSimulador() const {
        return configuracionSimulador;
    }
};
