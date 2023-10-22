#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include <ctime>
#include "queue.h"
using namespace std;

class Window
{
    protected:
    
        bool available;
        int cantMaximaporVentana;
        Queue<int> windowQueue; // Cola de personas va tener el ID de la persona
        
    public:
        // Constructor con parametros
        Window(bool available, int cantMaximaporVentana):windowQueue("Cola de ventana")
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

        int getCantidadpersonas()
        {
            return windowQueue.size();
        }
    
        // Metodo para pasar el cliente a la ventana
        void passClient(int ID)
        {
            // comprobar si en la cola no hay mas de cantMaximaporVentana
            if ( windowQueue.size() < cantMaximaporVentana)
            {
                // Aqui se pasa el cliente a la ventana 
                windowQueue.push(ID);
            }
        }

        // Metodo para sacar el cliente de la ventana

        int removeClient()
        {
            // Aqui se saca el cliente de la ventana
            
            return windowQueue.pop();
            
        }
};

class OrderWindow: public Window
{
    private:
        int velocidadDeVentanaP;
        Menu menu;

    public :

        OrderWindow(Menu menu, int velocidadDeVentanaP, int cantMaximaporVentana)
            : Window(true, cantMaximaporVentana),  menu(menu), velocidadDeVentanaP(velocidadDeVentanaP) {};

        int getVelocidadDeVentana()
        {
            return velocidadDeVentanaP;
        }

        Order attendClient(int opcion, int orderID)
        {
            // Crear orden con el ID de la orden
            Order order(orderID); // Utiliza el constructor para crear un objeto, no "new"

            if (opcion == 1) { // si opciones 1, va a ser una comida y un refresco
                // Generar un índice aleatorio dentro del rango del vector
                order.setTipoOrden(1);
                int i = rand() % menu.getFood().size();
                order.addFood(menu.getFood()[i]);
                i = rand() % menu.getDrink().size();
                order.addDrink(menu.getDrink()[i]);
                for (Food& comida : order.getFood()) { // Usa una referencia a Food
                    cout << "Comida: " << comida.getName() << " Orden: " << order.getIdOrder() << endl;
                }
                for (Drink& fresco : order.getDrink()) { // Usa una referencia a Drink
                    cout << "Refresco: " << fresco.getName() << " Orden: " << order.getIdOrder() << endl;
                }
            }

            // Lógica para seleccionar el producto
            if (opcion == 2) { // si opciones 2, va a ser un postre
                // Generar un índice aleatorio dentro del rango del vector
                int i = rand() % menu.getDessert().size();
                order.setTipoOrden(2);
                order.addDessert(menu.getDessert()[i]);
                for (Dessert& postre : order.getDessert()) { // Usa una referencia a Dessert
                    cout << "Postre: " << postre.getName() << " Orden: " << order.getIdOrder() << endl;
                }
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

        int getVelocidadDeVentana()
        {
            return velocidadDeVentanaD;
        }

        Queue<int> getClientes()
        {
            return windowQueue;
        }

 
        Order deliverOrder(Order order)
        {
            // Aquí se entrega la orden cuando esté lista y pagada y se comprueba el ID de la orden y del cliente
            order.deliver();

            windowQueue.pop();

            return order; // Retornar un puntero a la orden con el estado entregado
        }

};