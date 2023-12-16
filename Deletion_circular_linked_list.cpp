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

    // Function to delete a node at the beginning
    void deleteAtBeginning() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty. Nothing to delete at the beginning." << std::endl;
            return;
        }

        // Traverse to the last node
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Update pointers for the last node and the new head
        Node* temp = head;
        head = head->next;
        last->next = head;

        // Free the memory of the deleted node
        delete temp;
    }

    // Function to delete a node at the end
    void deleteAtEnd() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty. Nothing to delete at the end." << std::endl;
            return;
        }

        // Traverse to the last node
        Node* last = head;
        Node* secondToLast = nullptr;

        while (last->next != head) {
            secondToLast = last;
            last = last->next;
        }

        // Update pointers for the second-to-last node
        if (secondToLast) {
            secondToLast->next = head;
        } else {
            // If there is only one element in the list
            delete head;
            head = nullptr;
            return;
        }

        // Free the memory of the deleted node
        delete last;
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty. Nothing to delete at position " << position << "." << std::endl;
            return;
        }

        // Traverse to the node before the desired position
        Node* current = head;
        Node* previous = nullptr;

        for (int i = 1; i < position; ++i) {
            previous = current;
            current = current->next;
        }

        // Update pointers for the nodes around the specified position
        if (previous) {
            previous->next = current->next;
        } else {
            // If deleting the head node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = current->next;
            last->next = head;
        }

        // Free the memory of the deleted node
        delete current;
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

    // Display the circular linked list before deletion
    std::cout << "Circular Linked List before deletion operations:" << std::endl;
    myList.displayList();

    // Delete an element at the beginning
    myList.deleteAtBeginning();

    // Display the circular linked list after deletion at the beginning
    std::cout << "\nCircular Linked List after deletion at the beginning:" << std::endl;
    myList.displayList();

    // Delete an element at the end
    myList.deleteAtEnd();

    // Display the circular linked list after deletion at the end
    std::cout << "\nCircular Linked List after deletion at the end:" << std::endl;
    myList.displayList();

    // Delete an element at a specific position
    myList.deleteAtPosition(2);

    // Display the circular linked list after deletion at a specific position
    std::cout << "\nCircular Linked List after deletion at position 2:" << std::endl;
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
//INSERTION AT THE BEGINNING OF CIRCULAR LINKED LIST
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

    // Function to delete a node at the beginning
    void deleteAtBeginning() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty. Nothing to delete at the beginning." << std::endl;
            return;
        }

        // Traverse to the last node
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Update pointers for the last node and the new head
        Node* temp = head;
        head = head->next;
        last->next = head;

        // Free the memory of the deleted node
        delete temp;
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

    // Display the circular linked list before deletion
    std::cout << "Circular Linked List before deletion at the beginning:" << std::endl;
    myList.displayList();

    // Delete an element at the beginning
    myList.deleteAtBeginning();

    // Display the circular linked list after deletion at the beginning
    std::cout << "\nCircular Linked List after deletion at the beginning:" << std::endl;
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
//DELETION OF AN ELEMENT AT THE END OF A CIRCULAR LINKED LIST
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

    // Function to delete a node at the end
    void deleteAtEnd() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty. Nothing to delete at the end." << std::endl;
            return;
        }

        // Traverse to the last node
        Node* last = head;
        Node* secondToLast = nullptr;

        while (last->next != head) {
            secondToLast = last;
            last = last->next;
        }

        // Update pointers for the second-to-last node
        if (secondToLast) {
            secondToLast->next = head;
        } else {
            // If there is only one element in the list
            delete head;
            head = nullptr;
            return;
        }

        // Free the memory of the last node
        delete last;
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

    // Display the circular linked list before deletion
    std::cout << "Circular Linked List before deletion at the end:" << std::endl;
    myList.displayList();

    // Delete an element at the end
    myList.deleteAtEnd();

    // Display the circular linked list after deletion at the end
    std::cout << "\nCircular Linked List after deletion at the end:" << std::endl;
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
//DELETION OF AN ELEMENT AT A PARTICULAR POSITION IN A CIRCULAR LINKED LIST
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

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "Circular Linked List is empty. Nothing to delete at position " << position << "." << std::endl;
            return;
        }

        // Traverse to the node before the desired position
        Node* current = head;
        Node* previous = nullptr;

        for (int i = 1; i < position; ++i) {
            previous = current;
            current = current->next;
        }

        // Update pointers for the nodes around the specified position
        if (previous) {
            previous->next = current->next;
        } else {
            // If deleting the head node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = current->next;
            last->next = head;
        }

        // Free the memory of the deleted node
        delete current;
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

    // Display the circular linked list before deletion
    std::cout << "Circular Linked List before deletion at position 3:" << std::endl;
    myList.displayList();

    // Delete an element at a specific position
    myList.deleteAtPosition(3);

    // Display the circular linked list after deletion at a specific position
    std::cout << "\nCircular Linked List after deletion at position 3:" << std::endl;
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


