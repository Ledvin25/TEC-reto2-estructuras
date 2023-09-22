// Esto va a ser una plantilla para las pilas

#include <iostream>
#include <vector>

using namespace std;

class Stack 
{
    private:
        vector<int> stackList;

    public:

        Stack(){}

        void push(int data)
        {
            stackList.push_back(data);
        }

        int pop()
        {
            int result = stackList.back();
            stackList.pop_back();
            return result;
        }

        int top()
        {
            return stackList.back();
        }

};