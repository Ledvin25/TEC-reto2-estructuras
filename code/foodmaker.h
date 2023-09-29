#include <iostream>
#include <string>
#include <vector>

// Clase para crear una comida - Atributos: nombre, vector de ingredientes | Métodos: Constructor, setters y getters

class Comida
{
private:
    std::string nombre;
    std::vector<std::string> ingredientes;

public:
    Comida() {}

    // Setters
    void setNombre(std::string nombre)
    {
        this->nombre = nombre;
    }

    void setIngredientes(const std::vector<std::string>& ingredientes)
    {
        this->ingredientes = ingredientes;
    }

    // Getters
    std::string getNombre()
    {
        return this->nombre;
    }

    const std::vector<std::string>& getIngredientes()
    {
        return this->ingredientes;
    }
};

// Clase para crear un refresco - Atributos: nombre, vector de ingredientes | Métodos: Constructor, setters y getters

class Refresco
{
private:
    std::string nombre;
    std::vector<std::string> ingredientes;

public:
    Refresco() {}

    // Setters
    void setNombre(std::string nombre)
    {
        this->nombre = nombre;
    }

    void setIngredientes(const std::vector<std::string>& ingredientes)
    {
        this->ingredientes = ingredientes;
    }

    // Getters
    std::string getNombre()
    {
        return this->nombre;
    }

    const std::vector<std::string>& getIngredientes()
    {
        return this->ingredientes;
    }
};

// Clase para crear un postre - Atributos: nombre, vector de ingredientes | Métodos: Constructor, setters y getters

class Postre
{
private:
    std::string nombre;
    std::vector<std::string> ingredientes;

public:
    Postre() {}

    // Setters
    void setNombre(std::string nombre)
    {
        this->nombre = nombre;
    }

    void setIngredientes(const std::vector<std::string>& ingredientes)
    {
        this->ingredientes = ingredientes;
    }

    // Getters
    std::string getNombre()
    {
        return this->nombre;
    }

    const std::vector<std::string>& getIngredientes()
    {
        return this->ingredientes;
    }
};
