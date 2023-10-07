
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
    unordered_map<string, unordered_map<string, vector<string>>> menu;
    unordered_map<string, vector<string>> inventario;

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
        menu = json_data["menu"];
        inventario = json_data["inventario"];
    }

    // Métodos para acceder a la información del menú
    unordered_map<string, vector<string>> obtenerMenuComidas() const {
        return menu["comidas"];
    }

    unordered_map<string, vector<string>> obtenerMenuRefrescos() const {
        return menu["refrescos"];
    }

    unordered_map<string, vector<string>> obtenerMenuPostres() const {
        return menu["postres"];
    }

    // Métodos para acceder al inventario
    unordered_map<string, vector<string>> obtenerInventario() const {
        return inventario;
    }

    vector<string> obtenerPilaComidas() const {
        return inventario["pila_comidas"];
    }

    vector<string> obtenerPilaRefrescos() const {
        return inventario["pila_refrescos"];
    }

    vector<string> obtenerPilaPostres() const {
        return inventario["pila_postres"];
    }

    // Métodos para acceder a la configuración del simulador
    Settings obtenerConfiguracionSimulador() const {
        return configuracionSimulador;
    }
};
