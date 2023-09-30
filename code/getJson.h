#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Restaurante {
private:
    int tiempoSimulacionHora;
    int minHora;
    int maxHora;
    int velocidadDeLlegada;
    int ventanasParaPedido;
    int velocidadParaAtender;
    int ventanasParaRetirar;
    int velocidadParaRetirar;
    int cantMaximaPorVentana;
    int cantidadMaxIngrediente;
    unordered_map<string, unordered_map<string, vector<string>>> menu;
    unordered_map<string, vector<string>> inventario;

public:
    // Constructor que toma el JSON como entrada
    Restaurante(const json& json_data) {
        tiempoSimulacionHora = json_data["tiempoSimulacionHora"];
        minHora = json_data["minHora"];
        maxHora = json_data["maxHora"];
        velocidadDeLlegada = json_data["velocidadDeLlegada"];
        ventanasParaPedido = json_data["ventanasParaPedido"];
        velocidadParaAtender = json_data["velocidadParaAtender"];
        ventanasParaRetirar = json_data["ventanasParaRetirar"];
        velocidadParaRetirar = json_data["velocidadParaRetirar"];
        cantMaximaPorVentana = json_data["cantMaximaporVentana"];
        cantidadMaxIngrediente = json_data["cantidadMaxIngrediente"];
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

    // Otros métodos para acceder a la información del restaurante
    int obtenerTiempoSimulacionHora() const {
        return tiempoSimulacionHora;
    }

    int obtenerMinHora() const {
        return minHora;
    }

    int obtenerMaxHora() const {
        return maxHora;
    }

    int obtenerVelocidadDeLlegada() const {
        return velocidadDeLlegada;
    }

    int obtenerCantidadMaxIngrediente() const {
        return cantidadMaxIngrediente;
    }
};

#endif // RESTAURANTE_H