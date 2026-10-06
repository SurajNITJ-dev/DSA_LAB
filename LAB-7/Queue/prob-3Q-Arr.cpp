#include <iostream>

using namespace std;

class ArrayQueue {
private:
    static const int capacity = 10;
    int arr[capacity];
    int front;
    int rear;
    int count;

public:
    ArrayQueue() : front(0), rear(-1), count(0) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool enqueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        ++count;
        return true;
    }

    bool dequeue(int& value) {
        if (isEmpty()) {
            return false;
        }

        value = arr[front];
        front = (front + 1) % capacity;
        --count;
        return true;
    }

    bool peek(int& value) const {
        if (isEmpty()) {
            return false;
        }

        value = arr[front];
        return true;
    }

    
};

int main() {
    ArrayQueue q;
   

    
}
