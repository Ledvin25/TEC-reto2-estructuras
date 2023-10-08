#include <iostream>
#include <vector>
#include <string>

using namespace std;
template <typename T>
class Queue 
{
private:
    std::vector<T> queueList;

public:
    Queue() {}

    void push(const T &data)
    {
        queueList.push_back(data);
    }

    T pop()
    {
        T result = queueList.front();
        queueList.erase(queueList.begin());
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

    bool empty()
    {
        return queueList.empty();
    }
};