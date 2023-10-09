#include <iostream>
#include <string>
#include <vector>
#include "productMaker.h"
#include <chrono>
using namespace std;

// Estados del pedido
enum EstadoPedido {
    SIN_PROCESAR,
    PROCESADO, 
    PREPARADO,
    PAGADO,
    ENTREGADO
};

// Clase Order que puede contener Food, Drink y Dessert
class Order
{
private:
    vector<Food> food;
    vector<Drink> drink;
    vector<Dessert> dessert;
    EstadoPedido status;
    int idOrder;
    chrono::system_clock::time_point tiempo; // fuuro atributo para fecha y hora
    Inventory inventory;

public:

    // Constructor
    Order(int idOrder)
        : idOrder(idOrder), status(SIN_PROCESAR) {}

    // Destructor
    ~Order() {}

    // Metodos para darle forma al pedido

    // Set y get del id del pedido
    void setIdOrder(int idOrder)
    {
        this->idOrder = idOrder;
    }

    int getIdOrder()
    {
        return idOrder;
    }

    // Agregar Food
    void addFood(const Food &Food)
    {
        food.push_back(Food);
    }

    // Agregar Drink
    void addDrink(const Drink &Drink)
    {
        drink.push_back(Drink);
    }

    // Agregar Dessert
    void addDessert(const Dessert &Dessert)
    {
        dessert.push_back(Dessert);
    }

    // Obtener las comidas
    vector<Food> getFood()
    {
        return food;
    }

    // Obtener las bebidas
    vector<Drink> obtenerdrink()
    {
        return drink;
    }

    // Obtener los postres
    vector<Dessert> obtenerdessert()
    {
        return dessert;
    }

    // Las siguientes funciones van a cumplir lo que les corresponde, por ahora solo cambian el estado para dar la idea

    // Procesar pedido
    void process()
    {
        // Cuando se escoge del menu de la ventana, se agregan a la orden los nombres de los productos
        status = PROCESADO;
    }

    // Preparar pedido
    void prepare()
    {
        status = PREPARADO;
        // Se comprueba que los productos escogidos, tengan stock suficiente en inventario, en caso de ser si se utilizan los ingredientes
        // por lo tanto se restan de la pila correspondiente y la orden esta lista para continuar con el pago

        // Iterar a traves de las comidas de la orden
        for (int i = 0; i < food.size(); i++)
        {
            // Iterar a traves de los ingredientes de la comida
            for (int j = 0; j < food[i].getIngredients().size(); j++)
            {
                // Iterar a traves de los ingredientes del inventario
                for (int k = 0; k < inventory.getIngredients().size(); k++)
                {
                    // Si el ingrediente de la comida es igual al ingrediente del inventario
                    if (food[i].getIngredients()[j].getName() == inventory.getIngredients()[k].getName())
                    {
                        // Se resta la cantidad de ingredientes de la comida a la cantidad de ingredientes del inventario
                        inventory.getIngredients()[k].setQuantity(inventory.getIngredients()[k].getQuantity() - food[i].getIngredients()[j].getQuantity());
                    }
                }
            }
        }
    }

    // Pagar pedido

    void pay()
    {
        status = PAGADO;
        // Se comprueba que el pago sea correcto, en caso de serlo se procede a la entrega del pedido
    }

    // Entregar pedido
    void deliver()
    {
        status = ENTREGADO;
        // Se entrega el pedido y se saca de la cola de pedidos
    }

    // Obtener el estado del pedido
    EstadoPedido getStatus()
    {
        return status;
    }

};
