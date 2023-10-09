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
    vector<Drink> getDrink()
    {
        return drink;
    }

    // Obtener los postres
    vector<Dessert> getDessert()
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
    }

    // Pagar pedido

    void pay()
    {
        status = PAGADO;
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
