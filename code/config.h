#include <iostream>

// Aqui se van a trabajar todos las configuraciones del simulador como con sus correspondientes setters y getters

struct Setting {
    int simulationTime;
    int minHora;
    int maxHora;
    int velocidadDeLlegada;
    int ventanasParaPedido;
    int velocidadParaAtender;
    int ventanasParaRetirar;
    int velocidadParaRetirar;
    int cantMaximaPorVentana;
    int cantidadMaxIngrediente;

    Setting() : simulationTime(0), minHora(0), maxHora(0), velocidadDeLlegada(0),
                 ventanasParaPedido(0), velocidadParaAtender(0), ventanasParaRetirar(0),
                 velocidadParaRetirar(0), cantMaximaPorVentana(0), cantidadMaxIngrediente(0) {}
};
