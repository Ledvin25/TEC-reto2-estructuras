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
    Queue<Order> orders; // Cola de pedidos
    Queue<int> ClientQueue; // Cola de personas va a tener el ID de la
    Queue<int> ClientesAtendidos;
    Saver saver; // Objeto para guardar la información de la simulación
    Inventory inventory; // Objeto para manejar el inventario
    Menu menu;
    vector<OrderWindow> ventanasPedido;
    vector<DeliveryWindow> ventanasRetiro;
    
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
    int OrderID = 0;

public:
    // Funciones base para la simulación

    // Constructor
    Simulation(Setting valoresIniciales)
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
        inventory(),
        orders("Cola de ordenes"),
        ClientQueue("Cola de clientes sin ser atendidos"),
        ClientesAtendidos("Cola de clientes atendidos")
        {
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
            OrderWindow ventanaPedido(menu, velocidadParaAtender, cantMaxPeronas);
            this->ventanasPedido.push_back(ventanaPedido);
        }

        for (int i = 0; i < ventanasParaRetirar; i++) {
            DeliveryWindow ventanaRetiro(velocidadParaRetirar, cantMaxPeronas); // crear las ventanas que se indica en el json 
            this->ventanasRetiro.push_back(ventanaRetiro);
        }
        
    }

    void setMenu(JSON productos)
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
        json ingredientes_refrescos = productos.getPilaRefrescos();
        json ingredientes_postres = productos.getPilaPostres();

        // Convierte los elementos de las pilas en vectores de strings
        vector<string> comidas = ingredientes_comidas;
        vector<string> refrescos = ingredientes_refrescos;
        vector<string> postres = ingredientes_postres;

        inventory.setMaxIngredientQuantity(cantMaxIngrediente);

        for (const string& elemento : comidas){
            Stack<string> pila_ingrediente("pila de " + elemento); // crear pila de ingredientes de x tamaño segun indique json
            for (int i = 0; i<inventory.getMaxIngredientQuantity(); ++i){
                pila_ingrediente.push(elemento); // agregar pila a inventario por cada elemento
            }
            inventory.addFoodIngredient(pila_ingrediente);
        }

        for (const string& elemento : refrescos){
            Stack<string> pila_ingrediente("pila de " + elemento); // crear pila de ingredientes de x tamaño segun indique json
            for (int i = 0; i<inventory.getMaxIngredientQuantity(); ++i){
                pila_ingrediente.push(elemento);
            }
            inventory.addFoodIngredient(pila_ingrediente); // agregar pila a inventario por cada elemento
        }
        
        for (const string& elemento : postres){
            Stack<string> pila_ingrediente("pila de " + elemento); // crear pila de ingredientes de x tamaño segun indique json
            for (int i = 0; i<inventory.getMaxIngredientQuantity(); ++i){ 
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

    OrderWindow* pasarCliente(int ID)
    {
        OrderWindow* window = &ventanasPedido[0];
        for (OrderWindow& x : ventanasPedido)
        {
            if (x.getCantidadpersonas() < window->getCantidadpersonas()) // se ve que ventana tiene menos gente 
            {
                window = &x;
            }
        }
        window->passClient(ID);
        ClientesAtendidos.push(window->removeClient());
        ClientQueue.pop();

        return window;
    }


    // Funcion para atender al cliente

    void atenderCliente(OrderWindow* orderWindow, int Option)
    {
        orders.push(orderWindow->attendClient(Option, (OrderID%99)));
        OrderID++;
    }

    // Preparacion del pedido

    void prepararPedido(Order order)
    {
        // Comprobar que haya inventario suficiente

        for (Food& comida : order.getFood())
        {
            for(string ingredient : comida.getIngredients())
            {
                if(!inventory.quantityIngredientFood(ingredient))
                {
                    // Comprar ingredientes
                    inventory.buyFoodIngredient(ingredient);
                    order.prepare();
                }
                else
                {
                    // Usar ingredientes
                    inventory.UseFoodIngredientByName(ingredient);
                }
            }
        }

        for (Drink& bebida : order.getDrink())
        {
            for(string ingredient : bebida.getIngredients())
            {
                if(!inventory.quantityIngredientDrink(ingredient))
                {
                    // Comprar ingredientes
                    inventory.buyDrinkIngredient(ingredient);
                    order.prepare();
                }
                else
                {
                    // Usar ingredientes
                    inventory.UseDrinkIngredientByName(ingredient);
                }
            }
        }

        for (Dessert& postre : order.getDessert())
        {
            for(string ingredient : postre.getIngredients())
            {
                if(!inventory.quantityIngredientDessert(ingredient))
                {
                    // Comprar ingredientes
                    inventory.buyDessertIngredient(ingredient);
                    order.prepare();
                }
                else
                {
                    // Usar ingredientes
                    inventory.UseDessertIngredientByName(ingredient);
                }
            }
        }
        order.prepare();
    }

    void EntregarAlCliente(int ID)
    {
        DeliveryWindow* window = &ventanasRetiro[0];
        cout << "Cliente para retirar: " << ID << endl;
        for (DeliveryWindow& x : ventanasRetiro)
        {
            if (x.getCantidadpersonas() < window->getCantidadpersonas())
            {
                window = &x;
            }
        }
        window->passClient(ID);
        cout << "Ventana retiro " << window->getCantidadpersonas() << endl;
        ClientesAtendidos.pop();
    }

    // Pagar el pedido

    void pagarPedido(Order order)
    {
        int NumVentana = 1;
        for (DeliveryWindow window : ventanasRetiro) 
        {
            for (int i = 0; i < window.getClientes().size(); i++)
            {
                if (order.getIdOrder()==window.getClientes().obtener_dato(i)){
                    cout << "cliente que quiere retirar: " << window.getClientes().obtener_dato(i) <<  " Ventana: " <<NumVentana  << endl;
                    order.pay();
                }
            } 
           
             
            NumVentana++;
        }
    }

    // Retirar el pedido

    void retirarPedido(Order order)
    {
        int NumVentana = 1;
        for (DeliveryWindow window : ventanasRetiro) 
        {
            for (int i = 0; i < window.getClientes().size(); i++)
            {
                if (order.getIdOrder()==window.getClientes().obtener_dato(i)){
                    cout << "cliente que retiro la orden: " << window.getClientes().obtener_dato(i) <<  " Ventana: " <<NumVentana  << endl;
                    order.deliver();
                    window.removeClient();
                }
            } 
           
             
            NumVentana++;
        }
    }

    

    Menu getMenu()
    {
        return menu;
    }

    Inventory getInventory()
    {
        return inventory;
    }

    vector<OrderWindow> getOrderWindows()
    {
        return ventanasPedido;
    } 
    
    vector<DeliveryWindow> getDeliveryWindows()
    {
        return ventanasRetiro;
    }
    
    Queue<Order> getOrders()
    {
        return orders;
    }

    Queue<int> getClientQueue()
    {
        return ClientQueue;
    }

    Queue<int> getClientesAtendidos()
    {
        return ClientesAtendidos;
    }
   


};