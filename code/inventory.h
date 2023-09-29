// Aqui se van a trabajar las pilas de comida, refresco y postre que se van preparando cuando los pedidos son aprobados

#include <iostream>
#include "stack.h"
#include "foodmaker.h"

// Pila de comida
class FoodStack
{
    private:
        Stack<Comida> foodStack;
    public:
        FoodStack(){}
        void push(Comida comida)
        {
            foodStack.push(comida);
        }
        Comida pop()
        {
            return foodStack.pop();
        }
        Comida peek()
        {
            return foodStack.peek();
        }
        bool isEmpty()
        {
            return foodStack.isEmpty();
        }
};

// Pila de refresco

class DrinkStack
{
    private:
        Stack<Refresco> drinkStack;
    public:
        DrinkStack(){}
        void push(Refresco refresco)
        {
            drinkStack.push(refresco);
        }
        Refresco pop()
        {
            return drinkStack.pop();
        }
        Refresco peek()
        {
            return drinkStack.peek();
        }
        bool isEmpty()
        {
            return drinkStack.isEmpty();
        }
};

// Pila de postre

class DessertStack
{
    private:
        Stack<Postre> dessertStack;
    public:
        DessertStack(){}
        void push(Postre postre)
        {
            dessertStack.push(postre);
        }
        Postre pop()
        {
            return dessertStack.pop();
        }
        Postre peek()
        {
            return dessertStack.peek();
        }
        bool isEmpty()
        {
            return dessertStack.isEmpty();
        }
};