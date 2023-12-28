#include <iostream>
#define MAX_SIZE 100
using namespace std;
class stack
{
    int s[MAX_SIZE];
    int top = -1;

public:
    void push(int);
    int pop();
    bool IsEmpty();
    bool IsFull();
    int peek();
};
bool stack::IsEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
bool stack::IsFull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}
void stack::push(int data)
{
    if (IsFull())
    {
        cout << "Stack Overflow";
    }
    else
        s[++top] = data;
}
int stack::pop()
{
    if (IsEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
        return s[top--];
}
int stack::peek()
{
    if (IsEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
        return s[top];
}
int main()
{
    stack s1;
    string input;
    char ch;
    cout << "Enter string";
    cin >> input;
    char o1, o2;

    for (int i = 0; i < input.length(); i++)
    {
        ch = input[i];
        if (ch == '+')
        {
            o2 = s1.pop();
            o1 = s1.pop();
            int result = o2 + o1;
            s1.push(result);
        }
        else if (ch == '*')
        {
            o2 = s1.pop();
            o1 = s1.pop();
            int result = o2 * o1;
            s1.push(result);
        }
        else if (ch == '/')
        {
            o2 = s1.pop();
            o1 = s1.pop();
            int result = o1/ o2;
            s1.push(result);
        }
        else if (ch == '-')
        {
            o2 = s1.pop();
            o1 = s1.pop();
            int result = o1 - o2;
            s1.push(result);
        }
        else
            s1.push(ch - '0');
    }
    cout << s1.pop();

    return 0;
}