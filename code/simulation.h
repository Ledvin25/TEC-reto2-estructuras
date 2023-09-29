// Aqui se van a trabajar todos los procesos necesarios para que la simulacion funcione

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include "order.h"
#include "orderQueue.h"

using namespace std;

class Simulation {
public:

    private:
    // Cola de pedidos
    OrderQueue orderQueue;

    // Inventario de ingredientes
    map<string, int> inventory;

    // Cola de personas
    queue<string> queue;

    // Constructor
    Simulation() {
        // Inicializar otros atributos si es necesario
    }

    // Inicia la simulación
    void run() {
        cout << "Iniciando la simulación." << endl;
        // Lógica para iniciar la simulación
    }

    // Detiene la simulación
    void stop() {
        cout << "Deteniendo la simulación." << endl;
        // Lógica para detener la simulación
    }

    // Reinicia la simulación
    void restart() {
        cout << "Reiniciando la simulación." << endl;
        // Lógica para reiniciar la simulación
    }

    // Actualiza la simulación
    void update() {
        cout << "Actualizando la simulación." << endl;
        // Lógica para actualizar la simulación
    }


};