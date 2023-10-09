#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include <ctime>
#include "orderCounter.h"

using namespace std;

class Window
{
    protected:
    
        bool available;
        int cantMaximaporVentana;
        queue<int> windowQueue; // Cola de personas va tener el ID de la persona
        
    public:
        // Constructor con parametros
        Window(bool available, int cantMaximaporVentana)
        {
            this->available = true;
            this->cantMaximaporVentana = cantMaximaporVentana;
        }

        bool getAvailable()
        {
            return available;
        }

        int getCantMaximaporVentana()
        {
            return cantMaximaporVentana;
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
    private:
        OrderCounter& orderCounter; // Referencia a OrderCounter
        int velocidadDeVentanaP;
        Menu menu;

    public :

        OrderWindow(OrderCounter& orderCounter, Menu menu, int velocidadDeVentanaP, int cantMaximaporVentana)
            : Window(true, cantMaximaporVentana), orderCounter(orderCounter), menu(menu), velocidadDeVentanaP(velocidadDeVentanaP) {}
        ~OrderWindow();

        int getVelocidadDeVentana()
        {
            return velocidadDeVentanaP;
        }

        int getOrderCounter()
        {
            return orderCounter.getNextOrderID();
        }

        // Metodo para atender al cliente
        Order attendClient(int opcion)
        {
            Order order(orderCounter.getNextOrderID()); // Crear orden con el ID de la orden
            srand(static_cast<unsigned int>(time(nullptr))); // generar el numero random
            if (opcion==1){ // si opciones 1, va a ser una comida y un refresco
                // Generar un índice aleatorio dentro del rango del vector
                int i = rand() % menu.getFood().size();
                order.addFood(menu.getFood()[i]);
                i = rand() % menu.getDrink().size();
                order.addDrink(menu.getDrink()[i]);
            }

            // Logica para seleccionar el producto
            if (opcion==2){ // si opciones 2, va a ser un postre
                // Generar un índice aleatorio dentro del rango del vector
                int i = rand() % menu.getDessert().size();
                order.addDessert(menu.getDessert()[i]);
                
            }
            
            order.process();
    
            return order;
        }
};

class DeliveryWindow: public Window
{
    private:
        int velocidadDeVentanaD;
    
    public :

        DeliveryWindow(int velocidadDeVentanaD, int cantMaximaporVentana)
            : Window(true, cantMaximaporVentana), velocidadDeVentanaD(velocidadDeVentanaD) {};
        ~DeliveryWindow();

        int getVelocidadDeVentana()
        {
            return velocidadDeVentanaD;
        }

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