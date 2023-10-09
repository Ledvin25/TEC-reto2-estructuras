#include <iostream>
#include <string>
#include <vector>
#include "order.h"
using namespace std;
class Menu
{
    private:
    // Vector que va a ser un menu de todas las comidas, bebidas y postres y cada una va a necesitar un setter y un getter
    vector<Food> food;
    vector<Drink> drink;
    vector<Dessert> dessert;

    public:

    // Constructor por defecto
    Menu() {}

    // Metodos para darle forma al menu

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
    
};