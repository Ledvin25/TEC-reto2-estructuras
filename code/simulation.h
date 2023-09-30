// Aqui se van a trabajar todos los procesos necesarios para que la simulacion funcione

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include "order.h"
#include "inventory.h"
#include "window.h"
#include "saver.h"

using namespace std;

class Simulation {
public:

    private:
    queue<Order> orders; // Cola de pedidos
    queue<int> ClientQueue; // Cola de personas va tener el ID de la persona
    Saver saver; // Objeto para guardar la informacion de la simulacion
    Inventory inventory; // Objeto para manejar el inventario
    
    
    public:

    // Funciones base para la simulacion

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
        // Lógica para reiniciar la simulación y limpiar los datos
    }

    // Actualiza la simulación
    void update() {
        cout << "Actualizando la simulación." << endl;
        // Lógica para actualizar la simulación con los datos extraidos del saver.load()
    }

    // Crear la cantidad de ventanas extraidas del JSON

    // Funciones para la logisitca de la simulacion

    // Funcion para agregar un cliente a la cola
    void hacerCola(int id)
    {
        ClientQueue.push(id);
    }

    // Funcion para pasar el cliente a la ventana
    void pasarCliente(Window window)
    {
        window.passClient(ClientQueue);
    }

};