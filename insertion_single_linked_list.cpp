#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        // Set the new node's next pointer to the current head
        newNode->next = head;

        // Set the head to the new node
        head = newNode;
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

            // Insert the new node at the end
            current->next = newNode;
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
            newNode->next = head;
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

        // Insert the new node at the specified position
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    LinkedList myList;

    // Insert elements at the beginning
    for (int i = 5; i >= 1; --i) {
        myList.insertAtBeginning(i);
    }

    // Display the linked list after insertion at the beginning
    std::cout << "Linked List after insertion at the beginning:" << std::endl;
    myList.displayList();

    // Insert elements at the end
    for (int i = 6; i <= 10; ++i) {
        myList.insertAtEnd(i);
    }

    // Display the linked list after insertion at the end
    std::cout << "\nLinked List after insertion at the end:" << std::endl;
    myList.displayList();

    // Insert element at a specific position
    myList.insertAtPosition(4, 99);

    // Display the linked list after insertion at a specific position
    std::cout << "\nLinked List after insertion at position 4:" << std::endl;
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
//DELETION FROM THE PARTICULAR POSITION IN SINGLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node at the end
    void addNodeAtEnd(int value) {
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

            // Insert the new node at the end
            current->next = newNode;
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
            newNode->next = head;
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

        // Insert the new node at the specified position
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    LinkedList myList;

    // Add elements to the linked list
    for (int i = 1; i <= 5; ++i) {
        myList.addNodeAtEnd(i);
    }

    // Display the linked list
    std::cout << "Linked List before insertion:" << std::endl;
    myList.displayList();

    // Insert at a specific position
    int positionToInsert = 3;
    int valueToInsert = 10;
    myList.insertAtPosition(positionToInsert, valueToInsert);

    std::cout << "\nLinked List after insertion at position " << positionToInsert << ":" << std::endl;
    myList.displayList();

    // Clean up memory (free nodes)
    Node* current = myList.head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}*/










/*
//DELETION AN ELEMENT FROM BEGGINING OF A SINGLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        // Set the new node's next pointer to the current head
        newNode->next = head;

        // Set the head to the new node
        head = newNode;
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    LinkedList myList;

    // Add elements to the linked list
    for (int i = 5; i >= 1; --i) {
        myList.insertAtBeginning(i);
    }

    // Display the linked list
    std::cout << "Linked List after insertion at the beginning:" << std::endl;
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
//DELETION OF AN ELEMENT FROM THE END OF A SINGLE LINKED LIST
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node at the end
    void addNodeAtEnd(int value) {
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

            // Insert the new node at the end
            current->next = newNode;
        }
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Example usage
    LinkedList myList;

    // Add elements to the linked list
    for (int i = 1; i <= 5; ++i) {
        myList.addNodeAtEnd(i);
    }

    // Display the linked list before insertion
    std::cout << "Linked List before insertion at the end:" << std::endl;
    myList.displayList();

    // Insert an element at the end
    int elementToInsert = 10;
    myList.addNodeAtEnd(elementToInsert);

    // Display the updated linked list
    std::cout << "\nLinked List after insertion at the end:" << std::endl;
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