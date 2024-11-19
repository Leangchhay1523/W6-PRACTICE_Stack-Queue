#include "Node.h"
#include <string>
using namespace std;

class Stack {
private:
    Node* top;     // Pointer to the top of the stack
    int length;      // Keeps track of the stack size

public:
    Stack() {       // Constructor
        // your code here
        top = nullptr;
        length = 0;
    }

    ~Stack() {      // Destructor to free memory
        while (!isEmpty()) {
            pop();   // Deallocate all nodes
        }
    }
    // Push an element onto the stack
    void push(int value) {
        // your code here
        Node* newElement = new Node(value);
        newElement->next = top;
        top = newElement;
        length++;
    } 

    // Pop the top element from the stack
    void pop() {
        // your code here
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
            length--;
        }  
    }

    // Peek the top element without removing it
    int peek() {
        // your code here
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else 
        {
            return top->data;
        } 
    }

    // Check if the stack is empty
    bool isEmpty() {
       // your code here
        if (length > 0)
            return 0;
        else 
            return 1;
    }

    // Get the current length of the stack
    int size() {
        return length;
    }
    // Convert the stack to a string representation
    std::string toString() {
       // your code here
        string stack = "[";
        Node* temp = top;
        
        while (temp != nullptr)
        {
            stack += to_string(temp->data);
            if (temp->next != nullptr)
                stack += ",";
            temp = temp->next;
        }
        return stack + "]";
    }
};
