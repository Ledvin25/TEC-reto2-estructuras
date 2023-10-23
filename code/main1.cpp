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
   
    // hacer cola para entrar
    for (int j = 0 ; j<5 ; j++)
    {
        prueba.hacerCola();
    }


    // se pasa al cliente a las colas de las distintas ventanas 
    for (int i = 0; i < prueba.getClientQueue().size(); i++) 
    {
        // Genera un número aleatorio entre 1 y 2 
        int resultado = (rand() % 2) + 1;
        OrderWindow* ventanaAtendiendo = prueba.pasarCliente(prueba.getClientQueue().pop());
        prueba.atenderCliente(ventanaAtendiendo, resultado);
    }


    // se prepara cada pedido
    for (int i = 0; i < prueba.getOrders().size(); i++) 
    {
        prueba.prepararPedido(prueba.getOrders().obtener_dato(i));
    }


    // se pasan los clientes de las colas de las ventanas para ordenar para una cola para ir a la sventanas a retirar
    for (int i = 0; i < prueba.getClientesAtendidos().size(); i++) 
    {
     prueba.EntregarAlCliente(prueba.getClientesAtendidos().pop());
    }


    // se paga el pedido
    for (int i = 0; i < prueba.getOrders().size(); i++) 
    {
        prueba.pagarPedido(prueba.getOrders().obtener_dato(i));
    }

    // se retira y se saca la gente de la cola de las ventanas para retirar y de la cola de las orders
    for (int i = 0; i < prueba.getOrders().size(); i++) 
    {
        prueba.retirarPedido(prueba.getOrders().obtener_dato(i));
        cout << "Estado de la orden: " << prueba.getOrders().obtener_dato(i).getIdOrder() << " es " 
        << prueba.getOrders().obtener_dato(i).getStatus() << endl;
        prueba.getOrders().pop();
    }
   

    return 0;
}
