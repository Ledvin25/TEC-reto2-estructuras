#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include <ctime>
using namespace std;

class Window
{
    protected:
    
        bool available;
        int cantMaximaporVentana;
        int velocidadDeVentanaP;
        int velocidadDeVentanaD;
        Menu menu;
        queue<int> windowQueue; // Cola de personas va tener el ID de la persona
        
    public:
        // Constructor con parametros
        Window(Menu menu, int MaxPeronas, int P, int D) {
        this->menu = menu;
        cantMaximaporVentana = MaxPeronas;
        available = true;
        velocidadDeVentanaP = P;
        velocidadDeVentanaD = D;
    }

        bool getAvailable()
        {
            return available;
        }

        int getCantMaximaporVentana()
        {
            return cantMaximaporVentana;
        }

        int getVelocidadDeVentanaP()
        {
            return velocidadDeVentanaP;
        }

        int getVelocidadDeVentanaD()
        {
            return velocidadDeVentanaD;
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
        Order attendClient(int opcion)
        {
            Order order;
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