#include <iostream>
using namespace std;

#define SIZE 5 // Maximum size of the queue

// Queue variables
int queue[SIZE];
int front = -1, rear = -1;

// Function to enqueue (add) an element to the queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow! Cannot add " << value << endl;
        return;
    }
    if (front == -1) front = 0; // Initialize front if the queue is empty
    rear++;
    queue[rear] = value;
    cout << value << " enqueued to the queue." << endl;
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (front == -1



        || front > rear) {
        cout << "Queue Underflow! Cannot dequeue." << endl;
        return;
    }
    cout << "Dequeued element: " << queue[front] << endl;
    front++;
    // Reset the queue if it becomes empty
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Function to display the front element
int peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queue[front];
}

// Function to check if the queue is empty
bool isEmpty() {
    return (front == -1 || front > rear);
}

// Function to display all elements in the queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Perform queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    cout << "Front element: " << peek() << endl;

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue(); // Attempt to dequeue from an empty queue

    cout << "Is queue empty? " << (isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
