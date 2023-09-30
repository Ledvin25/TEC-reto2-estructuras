#include <iostream>
#include "stack.h"
#include <vector>
#include <string>


using namespace std;

// El objeto inventory va a ser como tal un vector de stacks, donde cada stack va a tener un dato de tipo string que sera el ingrediente de una comida, bebida o postre
class Inventory
{
    private:
        vector<Stack<string>> foodIngredient; // Vector de stacks de productos'
        vector<Stack<string>> drinkIngredient; // Vector de stacks de productos'
        vector<Stack<string>> dessertIngredient; // Vector de stacks de productos'

    public:

        // Constructor por defecto
        Inventory() {}

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

        // Metodo para agregar un ingrediente a la pila de ingredientes de comida por nombre que es un string
        void addFoodIngredientByName(const string &foodIngredientName)
        {
            for (int i = 0; i < foodIngredient.size(); i++)
            {
                if (foodIngredient[i].peek() == foodIngredientName)
                {
                    foodIngredient[i].push(foodIngredientName);
                }
            }
        }

        // Metodo para agregar un ingrediente a la pila de ingredientes de bebida por nombre que es un string
        void addDrinkIngredientByName(const string &drinkIngredientName)
        {
            for (int i = 0; i < drinkIngredient.size(); i++)
            {
                if (drinkIngredient[i].peek() == drinkIngredientName)
                {
                    drinkIngredient[i].push(drinkIngredientName);
                }
            }
        }

        // Metodo para agregar un ingrediente a la pila de ingredientes de postre por nombre que es un string
        void addDessertIngredientByName(const string &dessertIngredientName)
        {
            for (int i = 0; i < dessertIngredient.size(); i++)
            {
                if (dessertIngredient[i].peek() == dessertIngredientName)
                {
                    dessertIngredient[i].push(dessertIngredientName);
                }
            }
        }

        // Metodo para sacar un ingredientes de la pila de ingredientes de comida por nombre que es un string
        void removeFoodIngredientByName(const string &foodIngredientName)
        {
            for (int i = 0; i < foodIngredient.size(); i++)
            {
                if (foodIngredient[i].peek() == foodIngredientName)
                {
                    foodIngredient[i].pop();
                }
            }
        }

        // Metodo para sacar un ingredientes de la pila de ingredientes de bebida por nombre que es un string
        void removeDrinkIngredientByName(const string &drinkIngredientName)
        {
            for (int i = 0; i < drinkIngredient.size(); i++)
            {
                if (drinkIngredient[i].peek() == drinkIngredientName)
                {
                    drinkIngredient[i].pop();
                }
            }
        }

        // Metodo para sacar un ingredientes de la pila de ingredientes de postre por nombre que es un string
        void removeDessertIngredientByName(const string &dessertIngredientName)
        {
            for (int i = 0; i < dessertIngredient.size(); i++)
            {
                if (dessertIngredient[i].peek() == dessertIngredientName)
                {
                    dessertIngredient[i].pop();
                }
            }
        }

        // Metodo para comprobar si la pila de ingredientes de comida esta vacia por nombre que es un string
        bool isFoodIngredientEmptyByName(const string &foodIngredientName)
        {
            for (int i = 0; i < foodIngredient.size(); i++)
            {
                if (foodIngredient[i].peek() == foodIngredientName)
                {
                    return foodIngredient[i].isEmpty();
                }
            }
        }

        // Metodo para comprobar si la pila de ingredientes de bebida esta vacia por nombre que es un string
        bool isDrinkIngredientEmptyByName(const string &drinkIngredientName)
        {
            for (int i = 0; i < drinkIngredient.size(); i++)
            {
                if (drinkIngredient[i].peek() == drinkIngredientName)
                {
                    return drinkIngredient[i].isEmpty();
                }
            }
        }

        // Metodo para comprobar si la pila de ingredientes de postre esta vacia por nombre que es un string
        bool isDessertIngredientEmptyByName(const string &dessertIngredientName)
        {
            for (int i = 0; i < dessertIngredient.size(); i++)
            {
                if (dessertIngredient[i].peek() == dessertIngredientName)
                {
                    return dessertIngredient[i].isEmpty();
                }
            }
        }

        
        
        
};