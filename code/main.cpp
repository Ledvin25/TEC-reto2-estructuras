#include <iostream>
#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

int main() {
    // Leer el archivo JSON
    std::ifstream archivo_json("config.json");
    json datos;
    archivo_json >> datos;

    // Acceder a los valores del JSON
    int tiempoSimulacionHora = datos["tiempoSimulacionHora"];
    int minHora = datos["minHora"];
    int maxHora = datos["maxHora"];
    int velocidadDeLlegada = datos["velocidadDeLlegada"];
    int ventanasParaPedido = datos["ventanasParaPedido"];
    int velocidadParaAtender = datos["velocidadParaAtender"];
    int ventanasParaRetirar = datos["ventanasParaRetirar"];
    int velocidadParaRetirar = datos["velocidadParaRetirar"];
    int cantMaximaporVentana = datos["cantMaximaporVentana"];
    int cantidadMaxIngrediente = datos["cantidadMaxIngrediente"];

    // Acceder a elementos anidados
    std::string hamburguesa_ingrediente1 = datos["menu"]["comidas"]["hamburguesa"][0];
    std::string hotdog_ingrediente2 = datos["menu"]["comidas"]["hotdog"][1];

    // Imprimir los valores
    std::cout << "tiempoSimulacionHora: " << tiempoSimulacionHora << std::endl;
    std::cout << "minHora: " << minHora << std::endl;
    std::cout << "maxHora: " << maxHora << std::endl;
    // Continuar imprimiendo otros valores y elementos anidados

    return 0;
}