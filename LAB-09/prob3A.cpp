
#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int a[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue is Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        a[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << a[front++] << endl;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}
