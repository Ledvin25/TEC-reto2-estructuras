// Aqui se van a trabajar todos los procesos necesarios para que la simulacion funcione

#include <iostream>
#include <queue>
#include <string>
#include "inventory.h"
#include "window.h"
#include "getJson.h"
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class Simulation {
private:
    Queue<Order> orders; // Cola de pedidos
    Queue<int> ClientQueue; // Cola de personas va a tener el ID de la
    Queue<int> ClientesAtendidos;
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
    
    Queue<Order>& getOrders()
    {
        return orders;
    }

    Queue<int>& getClientQueue()
    {
        return ClientQueue;
    }

    Queue<int>& getClientesAtendidos()
    {
        return ClientesAtendidos;
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
    void hacerCola()
    {
        int id = 0;

        while(true)
        {
            if(id < 100)
            {
                ClientQueue.push(id%99);

                cout << "Cliente " << id << " en cola de espera" << endl << endl;

                id++;

                int duracion = velocidadDeLlegada * 60 / tiempoSimulacionHora;
                // Pausa de tiempo de llegada
                std::this_thread::sleep_for(std::chrono::seconds(duracion));
            }
        }
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

        cout << "El cliente " << ID << " pasó a una ventana para pedir. " << endl << endl; // se pasa el cliente a la ventana " << window->getCantidadpersonas() << endl << endl
        
        return window;
    }


    // Funcion para atender al cliente

    void atenderCliente(OrderWindow* orderWindow, int Option)
    {
        Order& newOrder = orderWindow->attendClient(Option, (OrderID % 99));
        orders.push(newOrder); // Agregar una referencia al objeto retornado

        cout << "Se genero la orden " << OrderID << endl << endl;
        OrderID++;
    }

    // Preparacion del pedido

   void prepararPedido(Order& order)
   {
        // Comprobar que haya inventario suficiente

        for (Food& comida : order.getFood())
        {
            for (string ingredient : comida.getIngredients())
            {
                if (!inventory.quantityIngredientFood(ingredient))
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
            for (string ingredient : bebida.getIngredients())
            {
                if (!inventory.quantityIngredientDrink(ingredient))
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
            for (string ingredient : postre.getIngredients())
            {
                if (!inventory.quantityIngredientDessert(ingredient))
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

    int EntregarAlCliente(int ID)
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
        cout << "Ventana retiro " << window->getCantidadpersonas() << endl << endl;

        return ID;
    }

    // Pagar el pedido

    void pagarPedido(Order& order)
    {
        int NumVentana = 1;
        for (DeliveryWindow& window : ventanasRetiro) 
        {
            for (int i = 0; i < window.getClientes().size(); i++)
            {
                if (order.getIdOrder() == window.getClientes().obtener_dato(i))
                {
                    cout << "Cliente que quiere retirar: " << window.getClientes().obtener_dato(i) << " en Ventana: " << NumVentana << endl << endl;
                    order.pay();
                    break;
                }
            } 
            NumVentana++;
        }
    }

    // Retirar el pedido

    void retirarPedido(Order& order)
    {
        int NumVentana = 1;
        for (DeliveryWindow& window : ventanasRetiro) 
        {
            for (int i = 0; i < window.getClientes().size(); i++)
            {
                if (order.getIdOrder() == window.getClientes().obtener_dato(i))
                {
                    cout << "Cliente que retiró la orden: " << order.getIdOrder() << " en Ventana: " << NumVentana << endl << endl;
                    order.deliver();
                    window.removeClient();
                    break;
                }
            } 
            NumVentana++;
        }
    }
   
    void load()
    {
        json config;

        ifstream file("conf.json");
        if (!file.is_open()) {
            cout << "Error al abrir el archivo." << endl;
        }

        try {
            file >> config;
        } catch (json::parse_error& e) {
            cout << "Error de parseo JSON: " << e.what() << endl;
        }

        JSON data(config);

        setMenu(data);
        setInventario(data);
        setWindows();
    }

    // ---------------------------- Metodos para la simulacion ---------------------------- //

    void windowWork()
    {
        if (ClientQueue.size() == 0)
        {
            return;
        }

        OrderWindow* ventanaAtendiendo = pasarCliente(ClientQueue.pop());
        int resultado = (rand() % 2) + 1;
        atenderCliente(ventanaAtendiendo, resultado);

        int duracion = velocidadParaAtender * 60 / tiempoSimulacionHora;

        std::this_thread::sleep_for(std::chrono::seconds(duracion));

        ClientesAtendidos.push(ventanaAtendiendo->removeClient()); // se pasa el cliente a la cola de clientes atendidos
    }

    void kitchen()
    {
        if (orders.size() == 0)
        {
            return;
        }

        int id = 0;
        prepararPedido(orders.obtener_dato(id));

        cout << "Se preparó el pedido " << id << endl << endl;

        int duracion = 120 / tiempoSimulacionHora;

        std::this_thread::sleep_for(std::chrono::seconds(duracion));

        id++;
    }

    void deliveryWork()
    {
        if(ClientesAtendidos.size() == 0)
        {
            return;
        }

        int ID = EntregarAlCliente(ClientesAtendidos.pop());

        pagarPedido(orders.obtener_dato(ID));

        cout << "Se pagó el pedido " << ID << endl << endl;

        int duracion = 30 / tiempoSimulacionHora;

        std::this_thread::sleep_for(std::chrono::seconds(duracion));

        retirarPedido(orders.obtener_dato(ID));

        cout << "Se retiró el pedido " << ID << endl << endl;

        orders.pop();

    }

    // Inicia la simulación
    void run() {
        
        int tiempo = minHora * 3600;
        int tiempoFinal = maxHora * 3600;

        // Meter personas a la cola de llegada cada x tiempo
        std::thread cola(&Simulation::hacerCola, this);

        while (tiempo <= tiempoFinal)
        {
            std::thread ventanas(&Simulation::windowWork, this); // se pasa al cliente a las colas de las distintas ventanas
            std::thread cocina(&Simulation::kitchen, this); // se prepara cada pedido
            std::thread retiro(&Simulation::deliveryWork, this); // se pasan los clientes de las colas de las ventanas para ordenar para una cola para ir a la sventanas a retirar
            
            int factorDeEscala = tiempoSimulacionHora;
            std::this_thread::sleep_for(std::chrono::seconds(1) / factorDeEscala);

            tiempo++;

            cout << "Tiempo: " << tiempo << endl << endl;

            ventanas.join();
            cocina.join();
            retiro.join();
        }

        cola.join();

    }

    // Detiene la simulación
    void stop() {
        cout << "Deteniendo la simulación." << endl;
        // Lógica para detener la simulación
    }

};