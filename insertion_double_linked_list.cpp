
#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Update pointers for the new node and the current head
            newNode->next = head;
            head->prev = newNode;

            // Set the head to the new node
            head = newNode;
        }
    }

    // Function to insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Traverse to the end of the list
            Node* current = head;
            while (current->next) {
                current = current->next;
            }

            // Update pointers for the new node and the last node
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to insert a new node at a specific position
    void insertAtPosition(int position, int value) {
        Node* newNode = new Node(value);

        if (position <= 0) {
            // Invalid position
            std::cout << "Invalid position. Position should be greater than 0." << std::endl;
            delete newNode;
            return;
        }

        if (position == 1 || !head) {
            // If the position is the head or the list is empty, insert at the beginning
            insertAtBeginning(value);
            return;
        }

        // Traverse to the node before the desired position
        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            // Invalid position
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            delete newNode;
            return;
        }

        // Update pointers for the new node and the nodes around the specified position
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    // Function to display the doubly linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    DoublyLinkedList myList;

    // Insert elements at the beginning
    for (int i = 5; i >= 1; --i) {
        myList.insertAtBeginning(i);
    }

    // Display the doubly linked list after insertion at the beginning
    std::cout << "Doubly Linked List after insertion at the beginning:" << std::endl;
    myList.displayList();

    // Insert elements at the end
    for (int i = 6; i <= 10; ++i) {
        myList.insertAtEnd(i);
    }

    // Display the doubly linked list after insertion at the end
    std::cout << "\nDoubly Linked List after insertion at the end:" << std::endl;
    myList.displayList();

    // Insert element at a specific position
    myList.insertAtPosition(4, 99);

    // Display the doubly linked list after insertion at a specific position
    std::cout << "\nDoubly Linked List after insertion at position 4:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}












/*
//INSERT AN ELEMENT AT THE BEGGINING OF A DOUBLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Update pointers for the new node and the current head
            newNode->next = head;
            head->prev = newNode;

            // Set the head to the new node
            head = newNode;
        }
    }

    // Function to display the doubly linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    DoublyLinkedList myList;

    // Insert elements at the beginning
    for (int i = 5; i >= 1; --i) {
        myList.insertAtBeginning(i);
    }

    // Display the doubly linked list after insertion at the beginning
    std::cout << "Doubly Linked List after insertion at the beginning:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
*/







/*
//INSERT AN ELEMENT AT THE END OF DOUBLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Traverse to the end of the list
            Node* current = head;
            while (current->next) {
                current = current->next;
            }

            // Update pointers for the new node and the last node
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to display the doubly linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    DoublyLinkedList myList;

    // Insert elements at the end
    for (int i = 1; i <= 5; ++i) {
        myList.insertAtEnd(i);
    }

    // Display the doubly linked list after insertion at the end
    std::cout << "Doubly Linked List after insertion at the end:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
*/











/*
//INSERTION OF A ELEMENT AT A PARTICULAR POSITION IN A DOUBLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at a specific position
    void insertAtPosition(int position, int value) {
        Node* newNode = new Node(value);

        if (position <= 0) {
            // Invalid position
            std::cout << "Invalid position. Position should be greater than 0." << std::endl;
            delete newNode;
            return;
        }

        if (position == 1 || !head) {
            // If the position is the head or the list is empty, insert at the beginning
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        // Traverse to the node before the desired position
        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            // Invalid position
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            delete newNode;
            return;
        }

        // Update pointers for the new node and the nodes around the specified position
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // Function to display the doubly linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    DoublyLinkedList myList;

    // Insert elements at the beginning
    for (int i = 1; i <= 5; ++i) {
        myList.insertAtPosition(i, i);
    }

    // Display the doubly linked list after insertion at the beginning
    std::cout << "Doubly Linked List after insertion at the beginning:" << std::endl;
    myList.displayList();

    // Insert element at a specific position
    myList.insertAtPosition(3, 99);

    // Display the doubly linked list after insertion at a specific position
    std::cout << "\nDoubly Linked List after insertion at position 3:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
*/



