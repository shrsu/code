#include <iostream>
using namespace std;

#define MAX_SIZE 100000

int arr[MAX_SIZE];
int top_index = -1;

void push(int element, int max_size)
{
    if (top_index == max_size - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        top_index++;
        arr[top_index] = element;
    }
}

int pop()
{
    if (top_index == -1)
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else
    {
        int poppedElement = arr[top_index];
        top_index--;
        return poppedElement;
    }
}

int findTop()
{
    if (top_index == -1)
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else
    {
        return arr[top_index];
    }
}

int main()
{
    int numberOfTestCases;
    cin >> numberOfTestCases;
    while (numberOfTestCases > 0)
    {
        top_index = -1;
        int numberOfOperations, maxSize;
        cin >> numberOfOperations >> maxSize;
        string command;
        for (int i = 0; i < numberOfOperations; i++)
        {
            cin >> command;
            if (command == "push")
            {
                int element;
                cin >> element;
                push(element, maxSize);
            }
            else if (command == "pop")
            {
                int popped = pop();
                if (popped != -1)
                {
                    cout << popped << endl;
                }
            }
            else if (command == "top")
            {
                int top = findTop();
                if (top != -1)
                {
                    cout << top << endl;
                }
            }
        }
    }
    return 0;
}