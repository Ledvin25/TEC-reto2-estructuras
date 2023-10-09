#include <iostream>
#include <fstream>
#include "json.hpp"
#include <unordered_map>
#include <vector>
#include "simulation.h"
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
    
   
   
    // Crea un unordered_map para almacenar las comidas y sus ingredientes
    unordered_map<string, vector<string>> todasLasComidas;
    json comidas1 = datos.getMenuComidas();
    // Itera a través de las comidas y sus ingredientes
    for (json::iterator it = comidas1.begin(); it != comidas1.end(); ++it) {
        string nombreComida = it.key();
        cout << "Nombre de la comida: " << nombreComida << endl;
        vector<string> ingredientes = it.value();
        for (string ingrediente:ingredientes){
            cout << " - " << ingrediente << endl;
        }
        
       
    }
    json pila_comidas = datos.getPilaComidas();
    json pila_refrescos = datos.getPilaRefrescos();
    json pila_postres = datos.getPilaPostres();

    // Convierte los elementos de las pilas en vectores de strings
    vector<string> comidas = pila_comidas;
    vector<string> refrescos = pila_refrescos;
    vector<string> postres = pila_postres;

    // Imprime los elementos de cada pila
    cout << "Pila de Comidas:" << endl;
    for (const string& comida : comidas) {
        cout << " - " << comida << endl;
    }

    cout << "Pila de Refrescos:" << endl;
    for (const string& refresco : refrescos) {
        cout << " - " << refresco << endl;
    }

    cout << "Pila de Postres:" << endl;
    for (const string& postre : postres) {
        cout << " - " << postre << endl;
    }

    // Crear el menú

    OrderCounter& orderCounter = OrderCounter::getInstance();

    

    return 0;
}
