#include <iostream>
#include <stack>
using namespace std;
class Queue
{
    stack<int> enqueueStack;
    stack<int> dequeueStack;

public:
    void enqueue(int data)
    {
        enqueueStack.push(data);
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            exit(1);
        }

        if (dequeueStack.empty())
        {
            while (!enqueueStack.empty())
            {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        dequeueStack.pop();
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot peek." << endl;
            exit(2);
        }

        if (dequeueStack.empty())
        {
            while (!enqueueStack.empty())
            {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        return dequeueStack.top();
    }

    bool isEmpty()
    {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    cout << q.peek() << endl;
    return 0;
}
