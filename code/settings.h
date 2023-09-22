#include <iostream>

// Aqui se van a trabajar todos las configuraciones del simulador como con sus correspondientes setters y getters

class Settings
{

    private:
    
    public:
        Settings(){}

        // Setters
        void setSimulationTime(int simulationTime)
        {
            // 1. El tiempo de simulacion
        }
        void setArrivalTime(int arrivalTime)
        {
            // 2. El tiempo de llegada de los clientes
        }
        void setOrderWindow(int orderWindow)
        {
            // 3. Ventanas para pedido
        }
        void setOrderSpeed(int orderSpeed)
        {
            // 4. Velocidad para atender pedido
        }
        void setDeliveryWindow(int deliveryWindow)
        {
            // 5. Ventana para retirar pedido
        }
        void setDeliverySpeed(int deliverySpeed)
        {
            // 6. Velocidad para retirar pedido
        }
        void setMaxPerWindow(int maxPerWindow)
        {
            // 7. Cantidad maxima por ventana
        }

        // Getters
        int getSimulationTime()
        {
            return this->simulationTime;
        }
        int getArrivalTime()
        {
            return this->arrivalTime;
        }
        int getOrderWindow()
        {
            return this->orderWindow;
        }
        int getOrderSpeed()
        {
            return this->orderSpeed;
        }
        int getDeliveryWindow()
        {
            return this->deliveryWindow;
        }
        int getDeliverySpeed()
        {
            return this->deliverySpeed;
        }
        int getMaxPerWindow()
        {
            return this->maxPerWindow;
        }
};