// Aqui se va a trabajar las clases para crear comidas y va a tomar del simulation la cantidad de ingredientes que se van a tener en el inventario

#include <iostream>
#include <queue>
#include <string>

// Clase para crear una comida - Atributos: nombre, array de ingredientes | Metodos: Constructor, setters y getters

class Comida
{
    private:
        string nombre;
        string ingredientes[5];
    public:
        Comida(){}
        // Setters
        void setNombre(string nombre)
        {
            this->nombre = nombre;
        }
        void setIngredientes(string ingredientes[5])
        {
            this->ingredientes = ingredientes;
        }
        // Getters
        string getNombre()
        {
            return this->nombre;
        }
        string getIngredientes()
        {
            return this->ingredientes;
        }
};

// Clase para crear un refresco - Atributos: nombre, array de ingredientes | Metodos: Constructor, setters y getters

class Refresco
{
    private:
        string nombre;
        string ingredientes[5];
    public:
        Refresco(){}
        // Setters
        void setNombre(string nombre)
        {
            this->nombre = nombre;
        }
        void setIngredientes(string ingredientes[5])
        {
            this->ingredientes = ingredientes;
        }
        // Getters
        string getNombre()
        {
            return this->nombre;
        }
        string getIngredientes()
        {
            return this->ingredientes;
        }
};

// Clase para crear un postre - Atributos: nombre, array de ingredientes | Metodos: Constructor, setters y getters

class Postre
{
    private:
        string nombre;
        string ingredientes[5];
    public:
        Postre(){}
        // Setters
        void setNombre(string nombre)
        {
            this->nombre = nombre;
        }
        void setIngredientes(string ingredientes[5])
        {
            this->ingredientes = ingredientes;
        }
        // Getters
        string getNombre()
        {
            return this->nombre;
        }
        string getIngredientes()
        {
            return this->ingredientes;
        }
};

