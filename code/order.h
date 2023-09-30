#include <iostream>
#include <string>
#include <vector>
#include "foodmaker.h"

using namespace std;

// Estados del pedido
enum EstadoPedido {
    SIN_PROCESAR,
    PROCESADO, 
    PREPARADO,
    SIN_PAGAR,
    PAGADO,
};

// Clase Order que puede contener Food, Drink y Dessert
class Order
{
private:
    vector<Food> food;
    vector<Drink> drink;
    vector<Dessert> dessert;
    EstadoPedido status;

public:

    // Constructor por defecto
    Order() : status(SIN_PROCESAR) {}

    // Metodos para darle forma al pedido

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
        status = PROCESADO;
    }

    // Preparar pedido
    void prepare()
    {
        status = PREPARADO;
    }

    // Listo para pagar

    void readyToPay()
    {
        status = SIN_PAGAR;
    }

    // Pagar pedido

    void pay()
    {
        status = PAGADO;
    }

    // Obtener el estado del pedido
    EstadoPedido getStatus()
    {
        return status;
    }


};

// Clase que mantiene una cola de objetos Order
