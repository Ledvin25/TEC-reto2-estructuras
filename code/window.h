#include <iostream>
#include <string>
#include <vector>
#include "order.h"

using namespace std;
class menu
{
    private:
    // Vector que va a ser un menu de todas las comidas, bebidas y postres y cada una va a necesitar un setter y un getter
    vector<string> food;
    vector<string> drink;
    vector<string> dessert;

    public:

    // Constructor por defecto
    menu() {}

    // Metodos para darle forma al menu

    // Agregar Food
    void addFood(const string &Food)
    {
        food.push_back(Food);
    }

    // Agregar Drin
    void addDrink(const string &Drink)
    {
        drink.push_back(Drink);
    }

    // Agregar Dessert
    void addDessert(const string &Dessert)
    {
        dessert.push_back(Dessert);
    }
    
    // Obtener las comidas
    vector<string> getFood()
    {
        return food;
    }

    // Obtener las bebidas

    vector<string> getDrink()
    {
        return drink;
    }

    // Obtener los postres

    vector<string> getDessert()
    {
        return dessert;
    }
    
};

class Window
{
private:

    bool available;
    int velocidadParaAtender;
    int velocidadParaRetirar;
    queue<int> windowQueue; // Cola de personas va tener el ID de la persona
    
public:
    // Constructor con parametros
    Window(bool available = true, int velocidadParaAtender, int velocidadParaRetirar) : available(available), velocidadParaAtender(velocidadParaAtender), velocidadParaRetirar(velocidadParaRetirar) {}
    ~Window();

    // Metodo para pasar el cliente a la ventana
    void passClient(queue<int> clientQueue)
    {
        // Aqui se pasa el cliente a la ventana
        windowQueue.push(clientQueue.front());
    }

    // Metodo para atender al cliente
    Order attendClient()
    {
        // Aqui se atiende al cliente y se toma la orden

        Order order = Order();

        // Logica para tomar la orden

        order.process();

        return order;
    }

    // Metodo para pagar la orden
    Order payOrder(Order order)
    {
        // Aqui se paga la orden
        order.pay();

        return order;
    }

    // Metodo para entregar la orden
    Order deliverOrder(Order order)
    {
        // Aqui se entrega la orden cuando este lista y pagada
        order.deliver();

        windowQueue.pop();
        
        return order;

    }
};