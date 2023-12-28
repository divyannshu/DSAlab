#include <iostream>
#define MAX_SIZE 100
using namespace std;
class queue
{
    int q[MAX_SIZE];
    int front = -1;

public:
    int rear = -1;
    bool IsFull()
    {
        if (rear == MAX_SIZE - 1)
            return 1;
        else
            return 0;
    }
    bool IsEmpty()
    {
        if ((rear == -1 && front == -1) || (front > rear))
            return 1;
        else
            return 0;
    }

    void insert(int data)
    {
        if (IsFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            q[++rear] = data;
            if (rear == 0)
                front = 0;
        }
    }
    int dele()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
            return q[front++];
    }
};
int main()
{
    queue q1, q2;
    int choice = 1;
    while (choice != 0)
    {
        cout << "Enter 1 to push" << endl;
        cout << "Enter 2 to pop" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int dt;
            cout << "Enter data";
            cin >> dt;
            q1.insert(dt);
            break;
        case 2:
            if (!q1.IsEmpty())
            {
                for (int i = 0; i < q1.rear; i++)
                {
                    int value = q1.dele();
                    q2.insert(value);
                }
                cout << "Popped element" << q1.dele() << endl;
                q1.rear = -1;
                while (!q2.IsEmpty())
                {
                    int value = q2.dele();

                    q1.insert(value);
                }
                        }
            else
            {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            break;
        case 0:
            exit(1);

            break;
        }
    }
}