#include <iostream>

class Queue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            arr[rear] = value;
        } else {
            std::cout << "Queue Overflow: Cannot enqueue " << value << ", queue is full." << std::endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int value = arr[front];

            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }

            return value;
        } else {
            std::cout << "Queue Underflow: Cannot dequeue from an empty queue." << std::endl;
            return -1;  // Assuming -1 as an invalid value for simplicity
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[front];
        } else {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return -1;  // Assuming -1 as an invalid value for simplicity
        }
    }
};

int main() {
    // Example usage of the Queue
    Queue myQueue;

    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Display the front element
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    // Dequeue elements
    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;

    // Display the front element after dequeuing
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    // Enqueue more elements
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Display the front element after enqueuing
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    return 0;
}
