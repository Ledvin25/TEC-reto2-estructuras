// Aqui se van a trabajar todos los procesos necesarios para que la simulacion funcione

#include <iostream>
#include <queue>
#include <string>
#include "inventory.h"
#include "window.h"
#include "saver.h"
#include "getJson.h"
#include <vector>
using namespace std;

class Simulation {
private:
    queue<Order> orders; // Cola de pedidos
    queue<int> ClientQueue; // Cola de personas va a tener el ID de la persona
    Saver saver; // Objeto para guardar la información de la simulación
    Inventory inventory; // Objeto para manejar el inventario
    Menu menu;
    vector<OrderWindow> ventanasPedido;
    vector<DeliveryWindow> ventanasRetiro;
    OrderCounter& orderCounter; 
    
    int velocidadDeLlegada;
    int cantMaxPeronas;
    int tiempoSimulacionHora;
    int cantMaxIngrediente;
    int minHora;
    int maxHora;
    int velocidadParaAtender;
    int velocidadParaRetirar;
    int ventanasParaPedido;
    int ventanasParaRetirar;

public:
    // Funciones base para la simulación

    // Constructor
    Simulation(Setting valoresIniciales, OrderCounter& orderCounter)
        : velocidadDeLlegada(valoresIniciales.velocidadDeLlegada),
        tiempoSimulacionHora(valoresIniciales.simulationTime),
        cantMaxPeronas(valoresIniciales.cantMaximaPorVentana),
        cantMaxIngrediente(valoresIniciales.cantidadMaxIngrediente),
        minHora(valoresIniciales.minHora),
        maxHora(valoresIniciales.maxHora),
        velocidadParaAtender(valoresIniciales.velocidadParaAtender),
        velocidadParaRetirar(valoresIniciales.velocidadParaRetirar),
        ventanasParaPedido(valoresIniciales.ventanasParaPedido),
        ventanasParaRetirar(valoresIniciales.ventanasParaRetirar),
        menu(),
        inventory(inventory), 
        orderCounter(orderCounter) {
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

    void setWindows()
    {
        for (int i = 0; i < ventanasParaPedido; i++) {
            // Crear ventana con los parametros que se indica en el json
            OrderWindow ventanaPedido(orderCounter, menu, velocidadParaAtender, cantMaxPeronas);
            this->ventanasPedido.push_back(ventanaPedido);
        }

        for (int i = 0; i < ventanasParaRetirar; i++) {
            DeliveryWindow ventanaRetiro(velocidadParaRetirar, cantMaxPeronas); // crear las ventanas que se indica en el json 
            this->ventanasRetiro.push_back(ventanaRetiro);
        }
        
    }

    void setmenu(JSON productos)
    {
        json comidas = productos.getMenuComidas();
        json refrescos = productos.getMenuRefrescos();
        json postres = productos.getMenuPostres();
        
        
         // Configurar el menú de comidas
        for (json::iterator it = comidas.begin(); it != comidas.end(); ++it) {
            string nombreComida = it.key();
            vector<string> ingredientes = it.value();  // crear objeto con nombre e ingredientes
            Food comida(nombreComida, ingredientes);   // agregar objeto
            
            menu.addFood(comida);
        }  

        // Configurar el menú de refrescos 
        for (json::iterator it = refrescos.begin(); it != refrescos.end(); ++it) {
            string nombreRefresco = it.key();
            vector<string> ingredientes = it.value();
            Drink refresco(nombreRefresco, ingredientes); // crear objeto con nombre e ingredientes
            menu.addDrink(refresco); // agregar objeto
        }

        // Configurar el menú de postres (análogamente)
        for (json::iterator it = postres.begin(); it != postres.end(); ++it) {
            string nombrePostre = it.key();
            vector<string> ingredientes = it.value();
            Dessert postre(nombrePostre, ingredientes); // crear objeto con nombre e ingredientes
            menu.addDessert(postre);  // agregar objeto
        }
        
    }

    void setInventario(JSON productos)
    {
        json ingredientes_comidas = productos.getPilaComidas();
        json ingredientes_refrescos = productos.getMenuRefrescos();
        json ingredientes_postres = productos.getPilaPostres();
        

        inventory.setMaxIngredientQuantity(cantMaxIngrediente);

        for (string elemento : ingredientes_comidas){
            Stack<string> pila_ingrediente; // crear pila de ingredientes de x tamaño segun indique json
            for (int i = 0; i<cantMaxIngrediente; ++i){
                pila_ingrediente.push(elemento); // agregar pila a inventario por cada elemento
            }
            inventory.addFoodIngredient(pila_ingrediente);
        }

        for (string elemento : ingredientes_refrescos){
            Stack<string> pila_ingrediente; // crear pila de ingredientes de x tamaño segun indique json
            for (int i = 0; i<cantMaxIngrediente; ++i){
                pila_ingrediente.push(elemento);
            }
            inventory.addFoodIngredient(pila_ingrediente); // agregar pila a inventario por cada elemento
        }
        
        for (string elemento : ingredientes_postres){
            Stack<string> pila_ingrediente; // crear pila de ingredientes de x tamaño segun indique json
            for (int i = 0; i<cantMaxIngrediente; ++i){ 
                pila_ingrediente.push(elemento);
            }
            inventory.addFoodIngredient(pila_ingrediente); // agregar pila a inventario por cada elemento
        }
        
    }

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

    void atenderCliente(OrderWindow orderWindow, int Option)
    {
        orderWindow.attendClient(Option);
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