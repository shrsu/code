#include <iostream>
using namespace std;

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int back = -1;

bool isEmpty()
{
    return front == -1 && back == -1;
}

bool isFull()
{
    return back == MAX_SIZE - 1;
}

void enqueue(int item)
{
    if (isFull())
    {
        cout << "Failed";
        return;
    }
    if (isEmpty())
    {
        front = 0;
        back = 0;
    }
    else
    {
        back++;
    }
    queue[back] = item;
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int item = queue[front];
    if (front == back)
    {
        front = back = -1;
    }
    else
    {
        front++;
    }
    return item;
}

int main()
{
    int n;
    cin >> n;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        enqueue(item);
    }
    while (!isEmpty())
    {
        cout << dequeue() << endl;
    }
    return 0;
}