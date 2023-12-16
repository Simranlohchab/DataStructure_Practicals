#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
            newNode->next = head; // Circular link to itself
        } else {
            // Traverse to the last node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            // Update pointers for the new node and the last node
            newNode->next = head;
            last->next = newNode;

            // Update the head to the new node
            head = newNode;
        }
    }

    // Function to insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
            newNode->next = head; // Circular link to itself
        } else {
            // Traverse to the last node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            // Update pointers for the new node and the last node
            newNode->next = head;
            last->next = newNode;
        }
    }

    // Function to insert a new node at a specific position
    void insertAtPosition(int position, int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
            newNode->next = head; // Circular link to itself
        } else {
            // Traverse to the node before the desired position
            Node* current = head;
            for (int i = 1; i < position - 1; ++i) {
                current = current->next;
            }

            // Update pointers for the new node and the nodes around the specified position
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the circular linked list
    void displayList() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);

        std::cout << " (Head)" << std::endl;
    }
};

int main() {
    // Example usage
    CircularLinkedList myList;

    // Insert elements at the beginning
    myList.insertAtBeginning(1);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(3);

    // Display the circular linked list after insertion at the beginning
    std::cout << "Circular Linked List after insertion at the beginning:" << std::endl;
    myList.displayList();

    // Insert elements at the end
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    // Display the circular linked list after insertion at the end
    std::cout << "\nCircular Linked List after insertion at the end:" << std::endl;
    myList.displayList();

    // Insert an element at a specific position
    myList.insertAtPosition(2, 99);

    // Display the circular linked list after insertion at a specific position
    std::cout << "\nCircular Linked List after insertion at position 2:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    Node* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != myList.head);

    return 0;
}









/*
//INSERT ELEMENT AT BEGINNING OF A CIRCULAR LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
            newNode->next = head; // Circular link to itself
        } else {
            // Traverse to the last node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            // Update pointers for the new node and the last node
            newNode->next = head;
            last->next = newNode;

            // Update the head to the new node
            head = newNode;
        }
    }

    // Function to display the circular linked list
    void displayList() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);

        std::cout << " (Head)" << std::endl;
    }
};

int main() {
    // Example usage
    CircularLinkedList myList;

    // Insert elements at the beginning
    for (int i = 1; i <= 5; ++i) {
        myList.insertAtBeginning(i);
    }

    // Display the circular linked list after insertion at the beginning
    std::cout << "Circular Linked List after insertion at the beginning:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    Node* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != myList.head);

    return 0;
}
*/












/*
//INSERT AN ELEMENT AT THE END OF TH EDOUBLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
            newNode->next = head; // Circular link to itself
        } else {
            // Traverse to the last node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            // Update pointers for the new node and the last node
            newNode->next = head;
            last->next = newNode;
        }
    }

    // Function to display the circular linked list
    void displayList() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);

        std::cout << " (Head)" << std::endl;
    }
};

int main() {
    // Example usage
    CircularLinkedList myList;

    // Insert elements at the end
    for (int i = 1; i <= 5; ++i) {
        myList.insertAtEnd(i);
    }

    // Display the circular linked list after insertion at the end
    std::cout << "Circular Linked List after insertion at the end:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    Node* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != myList.head);

    return 0;
}
*/












/*
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at a specific position
    void insertAtPosition(int position, int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
            newNode->next = head; // Circular link to itself
        } else {
            // Traverse to the node before the desired position
            Node* current = head;
            for (int i = 1; i < position - 1; ++i) {
                current = current->next;
            }

            // Update pointers for the new node and the nodes around the specified position
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the circular linked list
    void displayList() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);

        std::cout << " (Head)" << std::endl;
    }
};

int main() {
    // Example usage
    CircularLinkedList myList;

    // Insert elements at the end
    for (int i = 1; i <= 5; ++i) {
        Node* newNode = new Node(i);

        if (!myList.head) {
            // If the list is empty, make the new node the head
            myList.head = newNode;
            newNode->next = myList.head; // Circular link to itself
        } else {
            // Traverse to the last node
            Node* last = myList.head;
            while (last->next != myList.head) {
                last = last->next;
            }

            // Update pointers for the new node and the last node
            newNode->next = myList.head;
            last->next = newNode;
        }
    }

    // Display the circular linked list before insertion
    std::cout << "Circular Linked List before insertion:" << std::endl;
    myList.displayList();

    // Insert an element at a specific position
    myList.insertAtPosition(3, 99);

    // Display the circular linked list after insertion at a specific position
    std::cout << "\nCircular Linked List after insertion at position 3:" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    Node* nextNode;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != myList.head);

    return 0;
}
*/
