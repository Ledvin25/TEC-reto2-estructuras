#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Producto
{
protected:
    string name;
    vector<string> ingredients;

public:
    Producto(string name, vector<string> ingredients)
    {
        this->name = name;
        this->ingredients = ingredients;
    }

    string getName()
    {
        return this->name;
    }

    const vector<string>& getIngredients()
    {
        return this->ingredients;
    }
};

class Food : public Producto
{
public:
    Food(string name, vector<string> ingredients) : Producto(name, ingredients) {}
};

class Drink : public Producto
{
public:
    Drink(string name, vector<string> ingredients) : Producto(name, ingredients) {}
};

class Dessert : public Producto
{
public:
    Dessert(string name, vector<string> ingredients) : Producto(name, ingredients) {}
};