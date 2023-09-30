#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Food
{
private:
    string name;
    vector<string> ingredients;

public:
    Food() {}

    // Setters
    void setName(string name)
    {
        this->name = name;
    }

    void setIngredients(const vector<string>& ingredients)
    {
        this->ingredients = ingredients;
    }

    // Getters
    string getName()
    {
        return this->name;
    }

    const vector<string>& getIngredients()
    {
        return this->ingredients;
    }
};

class Drink
{
private:
    string name;
    vector<string> ingredients;

public:
    Drink() {}

    // Setters
    void setName(string name)
    {
        this->name = name;
    }

    void setIngredients(const vector<string>& ingredients)
    {
        this->ingredients = ingredients;
    }

    // Getters
    string getName()
    {
        return this->name;
    }

    const vector<string>& getIngredients()
    {
        return this->ingredients;
    }
};

class Dessert
{
private:
    string name;
    vector<string> ingredients;

public:
    Dessert() {}

    // Setters
    void setName(string name)
    {
        this->name = name;
    }

    void setIngredients(const vector<string>& ingredients)
    {
        this->ingredients = ingredients;
    }

    // Getters
    string getName()
    {
        return this->name;
    }

    const vector<string>& getIngredients()
    {
        return this->ingredients;
    }
};
