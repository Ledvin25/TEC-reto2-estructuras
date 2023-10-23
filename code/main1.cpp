#include <iostream>
#include <fstream>
#include "json.hpp"
#include <unordered_map>
#include <vector>
#include "simulation.h"
#include <cstdlib> // Para la función rand
#include <ctime>   // Para inicializar la semilla del generador de números aleatorios
#include <cstdlib>
using json = nlohmann::json;
using namespace std;


int main() {
    // Lee el archivo JSON en un objeto json
    ifstream file("conf.json");
    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    json config;
    try {
        file >> config;
    } catch (json::parse_error& e) {
        cout << "Error de parseo JSON: " << e.what() << endl;
        return 1;
    }
    JSON datos(config);
    
    Simulation prueba(datos.getConfiguracionSimulador());
    
    prueba.setMenu(datos);
    prueba.setInventario(datos);
    prueba.setWindows();
   
    prueba.run();
   

    return 0;
}
