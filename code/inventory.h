#include <iostream>
#include "stack.h"
#include <vector>
#include <string>

using namespace std;

class Inventory
{
private:
    vector<Stack<string>> foodIngredient;    // Vector de stacks de productos de comida
    vector<Stack<string>> drinkIngredient;   // Vector de stacks de productos de bebida
    vector<Stack<string>> dessertIngredient; // Vector de stacks de productos de postre
    int maxIngredientQuantity;               // Cantidad máxima de ingredientes

public:
    // Constructor por defecto
    Inventory() {}

    // Set y get maxIngredientQuantity para el JSON
    void setMaxIngredientQuantity(int maxIngredientQuantity)
    {
        this->maxIngredientQuantity = maxIngredientQuantity;
    }

    int getMaxIngredientQuantity()
    {
        return maxIngredientQuantity;
    }

    // Metodo para agregar una pila de ingredientes de comida
    void addFoodIngredient(const Stack<string> &foodIngredient)
    {
        this->foodIngredient.push_back(foodIngredient);
    }

    // Metodo para agregar una pila de ingredientes de bebida
    void addDrinkIngredient(const Stack<string> &drinkIngredient)
    {
        this->drinkIngredient.push_back(drinkIngredient);
    }

    // Metodo para agregar una pila de ingredientes de postre
    void addDessertIngredient(const Stack<string> &dessertIngredient)
    {
        this->dessertIngredient.push_back(dessertIngredient);
    }

    // Método para sacar un ingrediente de la pila de ingredientes de comida por nombre que es un string
    void UseFoodIngredientByName(const string &foodIngredientName)
    {
        for (int i = 0; i < foodIngredient.size(); i++)
        {
            if (!foodIngredient[i].isEmpty() && foodIngredient[i].peek() == foodIngredientName)
            {
                foodIngredient[i].pop();
                break; // Salir del bucle una vez que se ha encontrado y utilizado el ingrediente
            }
        }
    }

    // Método para sacar un ingrediente de la pila de ingredientes de bebida por nombre que es un string
    void UseDrinkIngredientByName(const string &drinkIngredientName)
    {
        for (int i = 0; i < drinkIngredient.size(); i++)
        {
            if (!drinkIngredient[i].isEmpty() && drinkIngredient[i].peek() == drinkIngredientName)
            {
                drinkIngredient[i].pop();
                break; // Salir del bucle una vez que se ha encontrado y utilizado el ingrediente
            }
        }
    }

    // Método para sacar un ingrediente de la pila de ingredientes de postre por nombre que es un string
    void UseDessertIngredientByName(const string &dessertIngredientName)
    {
        for (int i = 0; i < dessertIngredient.size(); i++)
        {
            if (!dessertIngredient[i].isEmpty() && dessertIngredient[i].peek() == dessertIngredientName)
            {
                dessertIngredient[i].pop();
                break; // Salir del bucle una vez que se ha encontrado y utilizado el ingrediente
            }
        }
    }

    // Método para comprar ingredientes de comida
    void buyFoodIngredient(const string &foodIngredientName)
    {
        for (int i = 0; i < foodIngredient.size(); i++)
        {
            if (foodIngredient[i].isEmpty())
            {
                for (int j = 0; j < maxIngredientQuantity; j++)
                {
                    foodIngredient[i].push(foodIngredientName);
                }
                break; // Salir del bucle una vez que se ha comprado el ingrediente
            }
        }
    }

    // Método para comprar ingredientes de bebida
    void buyDrinkIngredient(const string &drinkIngredientName)
    {
        for (int i = 0; i < drinkIngredient.size(); i++)
        {
            if (drinkIngredient[i].isEmpty())
            {
                for (int j = 0; j < maxIngredientQuantity; j++)
                {
                    drinkIngredient[i].push(drinkIngredientName);
                }
                break; // Salir del bucle una vez que se ha comprado el ingrediente
            }
        }
    }

    // Método para comprar ingredientes de postre
    void buyDessertIngredient(const string &dessertIngredientName)
    {
        for (int i = 0; i < dessertIngredient.size(); i++)
        {
            if (dessertIngredient[i].isEmpty())
            {
                for (int j = 0; j < maxIngredientQuantity; j++)
                {
                    dessertIngredient[i].push(dessertIngredientName);
                }
                break; // Salir del bucle una vez que se ha comprado el ingrediente
            }
        }
    }

    // Método para comprobar si hay suficientes ingredientes de comida
    bool quantityIngredientFood(const string &foodIngredientName)
    {
        for (int i = 0; i < foodIngredient.size(); i++)
        {
            if (!foodIngredient[i].isEmpty() && foodIngredient[i].peek() == foodIngredientName)
            {
                return true;
            }
        }

        return false;
    }

    // Método para comprobar si hay suficientes ingredientes de bebida
    bool quantityIngredientDrink(const string &drinkIngredientName)
    {
        for (int i = 0; i < drinkIngredient.size(); i++)
        {
            if (!drinkIngredient[i].isEmpty() && drinkIngredient[i].peek() == drinkIngredientName)
            {
                return true;
            }
        }

        return false;
    }

    // Método para comprobar si hay suficientes ingredientes de postre
    bool quantityIngredientDessert(const string &dessertIngredientName)
    {
        for (int i = 0; i < dessertIngredient.size(); i++)
        {
            if (!dessertIngredient[i].isEmpty() && dessertIngredient[i].peek() == dessertIngredientName)
            {
                return true;
            }
        }

        return false;
    }
};