// Esto va a ser una plantilla para las colas

#include <iostream>
#include <vector>

class Queue 
{
    private:
        vector<int> queueList;

    public:

        Queue(){}

        void push(int data)
        {
            queueList.push_back(data);
        }

        int pop()
        {
            int result = queueList.front();
            queueList.erase(queueList.begin());
            return result;
        }

        int front()
        {
            return queueList.front();
        }

        int back()
        {
            return queueList.back();
        }

        int size()
        {
            return queueList.size();
        }

        bool empty()
        {
            return queueList.empty();
        }

};