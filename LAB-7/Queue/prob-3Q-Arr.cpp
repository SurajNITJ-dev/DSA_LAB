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

    int size() const {
        return count;
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

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front -> ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "<- Rear\n";
    }
};

class LinkedListQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int v) : data(v), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    LinkedListQueue() : head(NULL), tail(NULL), count(0) {}

    ~LinkedListQueue() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return head == NULL;
    }

    int size() const {
        return count;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }

    bool dequeue(int& value) {
        if (isEmpty()) {
            return false;
        }

        Node* temp = head;
        value = temp->data;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        }

        delete temp;
        --count;
        return true;
    }

    bool peek(int& value) const {
        if (isEmpty()) {
            return false;
        }

        value = head->data;
        return true;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front -> ";
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "<- Rear\n";
    }
};

int main() {
    int value;

    cout << "Array Queue \n";
    ArrayQueue aq;
    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);
    aq.display();

    if (aq.peek(value)) cout << "Front element: " << value << "\n";

    if (aq.dequeue(value)) cout << "Dequeued: " << value << "\n";
    aq.display();
    cout << "Size: " << aq.size() << "\n";

    cout << "\nLinked List Queue\n";
    LinkedListQueue lq;
    lq.enqueue(5);
    lq.enqueue(15);
    lq.enqueue(25);
    lq.display();

    if (lq.peek(value)) cout << "Front element: " << value << "\n";

    if (lq.dequeue(value)) cout << "Dequeued: " << value << "\n";
    lq.display();
    cout << "Size: " << lq.size() << "\n";

    return 0;
}