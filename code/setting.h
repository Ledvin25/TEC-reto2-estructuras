#include <iostream>

// Aqui se van a trabajar todos las configuraciones del simulador como con sus correspondientes setters y getters

struct Settings {
    int simulationTime;      // 1. El tiempo de simulación
    int arrivalTime;         // 2. El tiempo de llegada de los clientes
    int orderWindow;         // 3. Ventanas para pedido
    int orderSpeed;          // 4. Velocidad para atender pedido
    int deliveryWindow;      // 5. Ventana para retirar pedido
    int deliverySpeed;       // 6. Velocidad para retirar pedido
    int maxPerWindow;        // 7. Cantidad máxima por ventana

    // Constructor para inicializar todas las configuraciones
    Settings() : simulationTime(0), arrivalTime(0), orderWindow(0),
                 orderSpeed(0), deliveryWindow(0), deliverySpeed(0),
                 maxPerWindow(0) {}
};