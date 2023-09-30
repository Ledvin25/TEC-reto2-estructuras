#include <iostream>
#include <string>
#include <vector>
#include "order.h"

using namespace std;
class Menu
{
    private:
    // Vector que va a ser un menu de todas las comidas, bebidas y postres y cada una va a necesitar un setter y un getter
    vector<string> food;
    vector<string> drink;
    vector<string> dessert;

    public:

    // Constructor por defecto
    Menu() {}

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
    protected:
    
        bool available;
        int cantMaximaporVentana;
        int velocidadDeVentana;
        Menu menu;
        queue<int> windowQueue; // Cola de personas va tener el ID de la persona
        
    public:
        // Constructor con parametros
        Window();
        ~Window();

        // setters y getters

        void setAvailable(bool available)
        {
            this->available = available;
        }

        bool getAvailable()
        {
            return available;
        }

        void setCantMaximaporVentana(int cantMaximaporVentana)
        {
            this->cantMaximaporVentana = cantMaximaporVentana;
        }

        int getCantMaximaporVentana()
        {
            return cantMaximaporVentana;
        }

        void setVelocidadDeVentana(int velocidadDeVentana)
        {
            this->velocidadDeVentana = velocidadDeVentana;
        }

        int getVelocidadDeVentana()
        {
            return velocidadDeVentana;
        }
    
        // Metodo para pasar el cliente a la ventana
        void passClient(queue<int> clientQueue)
        {
            // comprobar si en la cola no hay mas de cantMaximaporVentana
            if (windowQueue.size() < cantMaximaporVentana)
            {
                // Aqui se pasa el cliente a la ventana 
                windowQueue.push(clientQueue.front());
            }
        }

        // Metodo para sacar el cliente de la ventana

        void removeClient()
        {
            // Aqui se saca el cliente de la ventana
            windowQueue.pop();
        }
};

class OrderWindow: public Window
{
    public :
        OrderWindow();
        ~OrderWindow();

        // Metodo para atender al cliente
        Order attendClient()
        {
            // Aqui se atiende al cliente y se selecciona del menu

            // Logica para seleccionar el producto

            int i = 0;
            
            Order order;

            Food food(menu.getFood()[i], {"Ingredientes"});
            Drink drink(menu.getDrink()[i], {"Ingredientes"});
            Dessert dessert(menu.getDessert()[i], {"Ingredientes"});

            order.addFood(food);
            order.addDrink(drink);
            order.addDessert(dessert);
    
            // Logica para tomar la orden
    
            order.process();
    
            return order;
        }
};

class DeliveryWindow: public Window
{
    public :

        DeliveryWindow();
        ~DeliveryWindow();

        // Metodo para pagar la orden y comprobar el id de la orden y del cliente
        Order payOrder(Order order)
        {
            // Aqui se paga la orden
            order.pay();
    
            return order;
        }

        // Metodo para entregar la orden
        Order deliverOrder(Order order)
        {
            // Aqui se entrega la orden cuando este lista y pagada y comprobar el id de la orden y del cliente
            order.deliver();
    
            windowQueue.pop();
            
            return order;
    
        }

};