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

    // Function to remove the first node
    void deleteAtBeginning() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the beginning." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to remove the last node
    void deleteAtEnd() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the end." << std::endl;
            return;
        }

        if (!head->next) {
            // If there is only one node in the list, remove it
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // Function to remove a node at a particular position
    void deleteAtPosition(int position) {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to delete at the specified position." << std::endl;
            return;
        }

        if (position == 1) {
            // If the node to be removed is the head
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse the list to find the node at the specified position
        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current || !current->next) {
            // If the position is invalid
            std::cout << "Invalid position. Node not found." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
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
    std::cout << "Linked List before deletions:" << std::endl;
    myList.displayList();

    // Delete at the beginning
    myList.deleteAtBeginning();
    std::cout << "\nLinked List after deletion at the beginning:" << std::endl;
    myList.displayList();

    // Delete at the end
    myList.deleteAtEnd();
    std::cout << "\nLinked List after deletion at the end:" << std::endl;
    myList.displayList();

    // Delete at a particular position
    int positionToDelete = 2;
    myList.deleteAtPosition(positionToDelete);
    std::cout << "\nLinked List after deletion at position " << positionToDelete << ":" << std::endl;
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
//DELETE A ELEMENT FROM BEGGINING OF A SINGLE LINKED LIST
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

    // Function to remove the first node
    void removeFirstNode() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to remove." << std::endl;
            return;
        }

        // Save the reference to the current head
        Node* oldHead = head;

        // Update the head to the next node
        head = head->next;

        // Free the memory of the old head
        delete oldHead;
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
    myList.head = new Node(1);
    Node* secondNode = new Node(2);
    Node* thirdNode = new Node(3);

    myList.head->next = secondNode;
    secondNode->next = thirdNode;

    // Display the linked list
    std::cout << "Linked List before removing element from the beginning:" << std::endl;
    myList.displayList();

    // Remove the element from the beginning
    myList.removeFirstNode();

    // Display the updated linked list
    std::cout << "\nLinked List after removing element from the beginning:" << std::endl;
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
//DELETING AN ELEMENT FROM THE END OF A SINGLE LINKED LIST
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

    // Function to remove the last node
    void removeLastNode() {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to remove." << std::endl;
            return;
        }

        if (!head->next) {
            // If there is only one node in the list, remove it
            delete head;
            head = nullptr;
            return;
        }

        // Traverse the list to find the second-to-last node
        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }

        // Free the last node and update the second-to-last node's next pointer
        delete current->next;
        current->next = nullptr;
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
    myList.head = new Node(1);
    Node* secondNode = new Node(2);
    Node* thirdNode = new Node(3);

    myList.head->next = secondNode;
    secondNode->next = thirdNode;

    // Display the linked list
    std::cout << "Linked List before removing element from the end:" << std::endl;
    myList.displayList();

    // Remove the element from the end
    myList.removeLastNode();

    // Display the updated linked list
    std::cout << "\nLinked List after removing element from the end:" << std::endl;
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
//DELETE ELEMENT FROM A PARTICULAR POSITION FROM A SINGLE LINKED LIST
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

    // Function to remove a node with a specific value
    void removeNode(int value) {
        if (!head) {
            // If the list is empty, do nothing
            std::cout << "List is empty. Nothing to remove." << std::endl;
            return;
        }

        // If the node to be removed is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse the list to find the node to be removed
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        // If the node with the specified value is found
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            std::cout << "Element not found in the list." << std::endl;
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
    myList.head = new Node(1);
    Node* secondNode = new Node(2);
    Node* thirdNode = new Node(3);
    Node* fourthNode = new Node(4);

    myList.head->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;

    // Display the linked list
    std::cout << "Linked List before removing element from the middle:" << std::endl;
    myList.displayList();

    // Remove the element from the middle
    myList.removeNode(3);

    // Display the updated linked list
    std::cout << "\nLinked List after removing element from the middle:" << std::endl;
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
