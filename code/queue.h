#include <vector>
#include <string>
#include <chrono>
#include <iostream>

template <typename T>
class Queue
{
private:
    string name;            // Nombre de la cola
    vector<T> queueList;    // Elementos en la cola
    vector<chrono::high_resolution_clock::time_point> waitTimes; // Tiempos de espera
    int removedCount;       // Contador de elementos retirados

public:
    Queue(const string &queueName) : name(queueName), removedCount(0) {}

    void push(const T &data)
    {
        queueList.push_back(data);
    }

    T pop()
    {
        if (queueList.empty()) {
            cerr << "La cola está vacía. No se puede hacer pop." << endl;
            // Puedes lanzar una excepción o manejarlo de otra manera si lo prefieres.
        }

        T result = queueList.front();
        queueList.erase(queueList.begin());
        chrono::high_resolution_clock::time_point endTime = chrono::high_resolution_clock::now();
        waitTimes.push_back(endTime);
        removedCount++;
        printQueueInfo();
        

        return result;
    }

    T front()
    {
        return queueList.front();
    }

    T back()
    {
        return queueList.back();
    }

    size_t size()
    {
        return queueList.size();
    }

    T obtener_dato(int i)
    {
        return queueList[i];
    }

    bool empty()
    {
        return queueList.empty();
    }

    void printQueueInfo()
    {
        cout << "Nombre de la cola: " << name << endl;
        cout << "Cantidad de elementos en la cola: " << size() << endl;
        if (removedCount > 0)
        {
            double averageWaitTimeInSeconds = chrono::duration_cast<chrono::microseconds>(
                waitTimes.back() - waitTimes[0]
            ).count() / (1e6 * removedCount);
            cout << "Tiempo promedio de espera: " << averageWaitTimeInSeconds << " segundos" << endl;
        }
        else
        {
            cout << "Tiempo promedio de espera: N/A (no se han retirado elementos)" << endl;
        }
    }
};

