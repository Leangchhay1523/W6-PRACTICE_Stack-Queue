#include "Node.h"
using namespace std;

class Queue {
private:
    Node* front;     // Pointer to the front of the queue
    Node* rear;      // Pointer to the rear of the queue
    int length;      // Keeps track of the queue size
public:
    Queue() {       // Constructor
        // your code here
        front = nullptr;
        rear = nullptr;
        length = 0;
    }
    ~Queue() {      // Destructor to free memory
        while (!isEmpty()) {
            dequeue();   // Deallocate all nodes
        }
    }
    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }
    // Dequeue the front element from the queue
    void dequeue() {
        // your code here
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else 
        {
            Node* temp = front;
            front = temp->next;
            delete temp;
            length--;
            if (front == nullptr)
                rear = front;
        }   
    }
    // Peek the front element without removing it
    int peek() {
        // your code here
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Queue is empty
        }
        else 
        {
            return front->data;
        }
    }
    // Check if the queue is empty
    bool isEmpty() {
        // your code here
        if (length > 0)
            return 0;
        else 
            return 1;
    }
    // Get the current length of the queue
    int size() {
        return length;
    }

    // Convert the queue to a string representation
    std::string toString() {
      // your code here
        string queue = "[";
        Node* temp = front;
        
        while (temp != nullptr)
        {
            queue += to_string(temp->data);
            if (temp->next != nullptr)
                queue += ",";
            temp = temp->next;
        }
        return queue + "]";
    }
};
