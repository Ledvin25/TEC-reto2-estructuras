#include <iostream>
#include <vector>
#include "queue.h"
#include "order.h"

class OrderQueue
{
private:
    queue<Order> colaDeOrdenes;

public:
    void agregarOrden(const Order &orden)
    {
        colaDeOrdenes.push(orden);
    }

    Order obtenerOrden()
    {
        Order orden = colaDeOrdenes.front();
        colaDeOrdenes.pop();
        return orden;
    }

    bool estaVacia()
    {
        return colaDeOrdenes.empty();
    }
};