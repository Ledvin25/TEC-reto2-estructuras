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

    // Datos del JSON
    int velocidadDeLlegada;
    int ventanasParaPedido;
    int ventanasParaRetirar;
    int tiempoSimulacionHora;
    
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
    void load() {
        cout << "Actualizando la simulación." << endl;
        
        // Lógica para actualizar la simulación con los datos extraidos del saver.load()

        saver.load();
    }

    // Guarda la simulación

    void save() {
        cout << "Guardando la simulación." << endl;
        // Lógica para guardar la simulación en un archivo JSON
        saver.save();
    }

    // Crear la cantidad de ventanas extraidas del JSON

    void createWindows(int ventanasParaPedido, int ventanasParaRetirar)
    {
        // Aqui se crean las ventanas
    }

    // Funciones para la logisitca de la simulacion

    // Funcion para agregar un cliente a la cola
    void hacerCola(int id)
    {
        ClientQueue.push(id);
    }

    // Funcion para pasar el cliente a la ventana con menos cola
    void pasarCliente(Window window)
    {
        window.passClient(ClientQueue);
    }

    // Funcion para atender al cliente

    void atenderCliente(OrderWindow orderWindow)
    {
        orderWindow.attendClient();
    }

    // Preparacion del pedido

    void prepararPedido(Order order)
    {
        order.prepare();
    }

    // Pagar el pedido

    void pagarPedido(DeliveryWindow deliveryWindow)
    {
        // Se hace match del ID del cliente con el ID del pedido
        // Se paga el pedido
    }

    // Retirar el pedido

    void retirarPedido(DeliveryWindow deliveryWindow)
    {
        // Se hace match del ID del cliente con el ID del pedido
        // Se retira el pedido
    }

    // Funcion para sacar el cliente de la ventana
    void sacarCliente(Window window)
    {
        window.removeClient();
    }

};