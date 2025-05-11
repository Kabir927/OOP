
#include <iostream>
using namespace std;

class QueueOverflowException : public std::exception {};
class QueueUnderflowException : public std::exception {};

template<typename T>
class Queue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        arr = new T[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (size == capacity) {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    T dequeue() {
        if (size == 0) {
            throw QueueUnderflowException();
        }
        T value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    try {
        Queue<int> q(3);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(4);
    }
    catch(const QueueOverflowException&) {
        cout << "Caught QueueOverflowException - what(): std::exception" << endl;
    }

    try {
        Queue<int> q(3);
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();
    }
    catch(const QueueUnderflowException&) {
        cout << "Caught QueueUnderflowException - what(): std::exception" << endl;
    }

    return 0;
}
