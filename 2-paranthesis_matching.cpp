#include <iostream>
#define MAX_SIZE 100
using namespace std;
class stack
{
    char s[MAX_SIZE];
    int top = -1;

public:
    void push(char);
    char pop();
    bool IsEmpty();
    bool IsFull();
    char peek();
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
void stack::push(char data)
{
    if (IsFull())
    {
        cout << "Stack Overflow";
    }
    else
        s[++top] = data;
}
char stack::pop()
{
    if (IsEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
        return s[top--];
}
char stack::peek()
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
    char e;
    for (int i = 0; i < input.length(); i++)
    {
        ch = input[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s1.push(ch);
        }
        if (ch == ')' || ch == '}' || ch == ']')
        {
            if (!s1.IsEmpty())
            {
                e = s1.pop();
                if (e == '(' && ch == ')')
                {
                    continue;
                }
                else if (e == '{' && ch == '}')
                {
                    continue;
                }
                else if (e == '[' && ch == ']')
                {
                    continue;
                }
                else
                {
                    cout << "Invalid operation";
                    return 0;
                }
            }
            else
            {
                cout << "Invalid Operation" << endl;
                return 0;
            }
        }
    }
    if (!s1.IsEmpty())
    {
        cout << "Invalid Operation";
        return 0;
    }
    else
        cout << "Valid Operation";

    return 0;
}