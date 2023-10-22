#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
template <typename T>

class Stack
{
private:
    string name;            // Nombre de la pila
    vector<T> stackList;    // Elementos en la pila
    vector<chrono::high_resolution_clock::time_point> waitTimes; // Tiempos de espera
    int removedCount;       // Contador de elementos retirados

public:
    Stack(const string &stackName) : name(stackName), removedCount(0) {}

    void push(const T &data)
    {
        stackList.push_back(data);
    }

    T pop()
    {
        
        T result = stackList.back();
        stackList.pop_back();
        chrono::high_resolution_clock::time_point endTime = chrono::high_resolution_clock::now();
        waitTimes.push_back(endTime);
        removedCount++;
        printStackInfo();
        

        return result;
    }

    T peek()
    {
        return stackList.back();
    }

    bool isEmpty()
    {
        return stackList.empty();
    }

    int size()
    {
        return stackList.size();
    }

    void printStackInfo()
    {
        cout << "Nombre de la pila: " << name << endl;
        cout << "Cantidad de elementos en la pila: " << size() << endl;
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