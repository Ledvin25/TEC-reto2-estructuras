#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T>
class Stack 
{
private:
    std::vector<T> stackList;

public:
    Stack() {}

    void push(const T &data)
    {
        stackList.push_back(data);
    }

    T pop()
    {
        T result = stackList.back();
        stackList.pop_back();
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
};
