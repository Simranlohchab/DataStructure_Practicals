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

    // Function to delete a node at the beginning
    void deleteAtBeginning() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the beginning." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Function to delete a node at the end
    void deleteAtEnd() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the end." << std::endl;
            return;
        }

        if (!head->next) {
            // If there is only one element in the list
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        Node* prevNode = current->prev;
        prevNode->next = nullptr;

        delete current;
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at position " << position << "." << std::endl;
            return;
        }

        if (position <= 0) {
            // Invalid position
            std::cout << "Invalid position. Position should be greater than 0." << std::endl;
            return;
        }

        if (position == 1) {
            // Delete the first node
            Node* temp = head;
            head = head->next;

            if (head) {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        // Traverse to the node at the desired position
        Node* current = head;
        for (int i = 1; i < position && current; ++i) {
            current = current->next;
        }

        if (!current) {
            // Invalid position
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            return;
        }

        // Update pointers for the nodes around the specified position
        if (current->prev) {
            current->prev->next = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }

        delete current;
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

    // Display the doubly linked list before deletion
    std::cout << "Doubly Linked List before deletion:" << std::endl;
    myList.displayList();

    // Delete an element at the beginning
    myList.deleteAtBeginning();
    std::cout << "\nDoubly Linked List after deletion at the beginning:" << std::endl;
    myList.displayList();

    // Delete an element at the end
    myList.deleteAtEnd();
    std::cout << "\nDoubly Linked List after deletion at the end:" << std::endl;
    myList.displayList();

    // Delete an element at a specific position
    myList.deleteAtPosition(2);
    std::cout << "\nDoubly Linked List after deletion at position 2:" << std::endl;
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
//DELETE AN ELEMENT AT BEGGINING OF A DOUBLE LINKED LIST
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

    // Function to delete a node at the beginning
    void deleteAtBeginning() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the beginning." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        }

        delete temp;
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
        Node* newNode = new Node(i);
        newNode->next = myList.head;
        if (myList.head) {
            myList.head->prev = newNode;
        }
        myList.head = newNode;
    }

    // Display the doubly linked list before deletion
    std::cout << "Doubly Linked List before deletion at the beginning:" << std::endl;
    myList.displayList();

    // Delete an element at the beginning
    myList.deleteAtBeginning();

    // Display the doubly linked list after deletion at the beginning
    std::cout << "\nDoubly Linked List after deletion at the beginning:" << std::endl;
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
//DELETE AN ELEMENT FROM THE END OF A DOUBLE LINKED LIST
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

    // Function to delete a node at the end
    void deleteAtEnd() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the end." << std::endl;
            return;
        }

        if (!head->next) {
            // If there is only one element in the list
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        Node* prevNode = current->prev;
        prevNode->next = nullptr;

        delete current;
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
        Node* newNode = new Node(i);
        if (!myList.head) {
            myList.head = newNode;
        } else {
            Node* current = myList.head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Display the doubly linked list before deletion
    std::cout << "Doubly Linked List before deletion at the end:" << std::endl;
    myList.displayList();

    // Delete an element at the end
    myList.deleteAtEnd();

    // Display the doubly linked list after deletion at the end
    std::cout << "\nDoubly Linked List after deletion at the end:" << std::endl;
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
//DELETION OF AN ELEMENT AT A PARTICULAR POSITION IN A DOUBLE LINKED LIST
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

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at position " << position << "." << std::endl;
            return;
        }

        if (position <= 0) {
            // Invalid position
            std::cout << "Invalid position. Position should be greater than 0." << std::endl;
            return;
        }

        if (position == 1) {
            // Delete the first node
            Node* temp = head;
            head = head->next;

            if (head) {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        // Traverse to the node at the desired position
        Node* current = head;
        for (int i = 1; i < position && current; ++i) {
            current = current->next;
        }

        if (!current) {
            // Invalid position
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            return;
        }

        // Update pointers for the nodes around the specified position
        if (current->prev) {
            current->prev->next = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }

        delete current;
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
        Node* newNode = new Node(i);
        if (!myList.head) {
            myList.head = newNode;
        } else {
            Node* current = myList.head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Display the doubly linked list before deletion
    std::cout << "Doubly Linked List before deletion at a particular position:" << std::endl;
    myList.displayList();

    // Delete an element at a specific position
    myList.deleteAtPosition(3);

    // Display the doubly linked list after deletion at a specific position
    std::cout << "\nDoubly Linked List after deletion at position 3:" << std::endl;
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