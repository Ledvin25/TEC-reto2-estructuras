
#include <iostream>
#include "stack.h"
#include "productMaker.h"

using namespace std;

// El objeto inventory va a ser como tal un vector de stacks, donde cada stack va a poder tener cualquier tipo de comida, bebibda o postre
class Inventory
{
    private:
        vector<Stack<Food>> food; // Vector de stacks de comida
        vector<Stack<Drink>> drink; // Vector de stacks de bebida
        vector<Stack<Dessert>> dessert; // Vector de stacks de postre

    public:

        // Constructor por defecto
        Inventory() {}

        // Metodo para agregar una pila de comida con el nombre de la comida
        void addFood(const string& name, const Stack<Food>& stack)
        {
            food.push_back(stack);
        }

        // Metodo para agregar una pila de bebida con el nombre de la bebida
        void addDrink(const string& name, const Stack<Drink>& stack)
        {
            drink.push_back(stack);
        }

        // Metodo para agregar una pila de postre con el nombre del postre
        void addDessert(const string& name, const Stack<Dessert>& stack)
        {
            dessert.push_back(stack);
        }

        // Metodo para comprobar si hay comida en el inventario
        bool hasFood(const string& name)
        {
            for (int i = 0; i < food.size(); i++)
            {
                if (food[i].peek().getName() == name)
                {
                    return true;
                }
            }
            return false;
        }

        // Metodo para comprobar si hay bebida en el inventario
        bool hasDrink(const string& name)
        {
            for (int i = 0; i < drink.size(); i++)
            {
                if (drink[i].peek().getName() == name)
                {
                    return true;
                }
            }
            return false;
        }

        // Metodo para comprobar si hay postre en el inventario
        bool hasDessert(const string& name)
        {
            for (int i = 0; i < dessert.size(); i++)
            {
                if (dessert[i].peek().getName() == name)
                {
                    return true;
                }
            }
            return false;
        }

        // Metodo para sacar comida del inventario
        Food getFood(const string& name)
        {
            for (int i = 0; i < food.size(); i++)
            {
                if (food[i].peek().getName() == name)
                {
                    return food[i].pop();
                }
            }
        }

        // Metodo para sacar bebida del inventario
        Drink getDrink(const string& name)
        {
            for (int i = 0; i < drink.size(); i++)
            {
                if (drink[i].peek().getName() == name)
                {
                    return drink[i].pop();
                }
            }
        }

        // Metodo para sacar postre del inventario
        Dessert getDessert(const string& name)
        {
            for (int i = 0; i < dessert.size(); i++)
            {
                if (dessert[i].peek().getName() == name)
                {
                    return dessert[i].pop();
                }
            }
        }
        
        // Metodo para agregar comida al inventario
        void addFood(const string& name, const Food& food)
        {
            for (int i = 0; i < this->food.size(); i++)
            {
                if (this->food[i].peek().getName() == name)
                {
                    this->food[i].push(food);
                }
            }
        }

        // Metodo para agregar bebida al inventario
        void addDrink(const string& name, const Drink& drink)
        {
            for (int i = 0; i < this->drink.size(); i++)
            {
                if (this->drink[i].peek().getName() == name)
                {
                    this->drink[i].push(drink);
                }
            }
        }

        // Metodo para agregar postre al inventario
        void addDessert(const string& name, const Dessert& dessert)
        {
            for (int i = 0; i < this->dessert.size(); i++)
            {
                if (this->dessert[i].peek().getName() == name)
                {
                    this->dessert[i].push(dessert);
                }
            }
        }
};