#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    TreeNode* searchNode(TreeNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    void displayPreOrder(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            displayPreOrder(node->left);
            displayPreOrder(node->right);
        }
    }

    void displayInOrder(TreeNode* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    void displayPostOrder(TreeNode* node) {
        if (node != nullptr) {
            displayPostOrder(node->left);
            displayPostOrder(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    TreeNode* search(int value) {
        return searchNode(root, value);
    }

    void display() {
        std::cout << "Preorder traversal: ";
        displayPreOrder(root);
        std::cout << std::endl;

        std::cout << "Inorder traversal: ";
        displayInOrder(root);
        std::cout << std::endl;

        std::cout << "Postorder traversal: ";
        displayPostOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the Binary Search Tree
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        bst.insert(value);
    }

    // Display the Binary Search Tree before deletion
    std::cout << "Binary Search Tree:" << std::endl;
    bst.display();

    // Search for elements in the Binary Search Tree
    int searchValue = 40;
    TreeNode* foundNode = bst.search(searchValue);

    if (foundNode != nullptr) {
        std::cout << "\nElement " << searchValue << " found in the Binary Search Tree." << std::endl;
    } else {
        std::cout << "\nElement " << searchValue << " not found in the Binary Search Tree." << std::endl;
    }

    // Delete elements from the Binary Search Tree
    bst.remove(30);
    bst.remove(60);

    // Display the Binary Search Tree after deletion
    std::cout << "\nAfter Deletion:" << std::endl;
    bst.display();

    return 0;
}








/*
//INSERTING AN NODE IN BINARY SEARCH TREE
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void displayInOrder(TreeNode* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    void displayPreOrder(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            displayPreOrder(node->left);
            displayPreOrder(node->right);
        }
    }

    void displayPostOrder(TreeNode* node) {
        if (node != nullptr) {
            displayPostOrder(node->left);
            displayPostOrder(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        std::cout << "In-order traversal: ";
        displayInOrder(root);
        std::cout << std::endl;

        std::cout << "Pre-order traversal: ";
        displayPreOrder(root);
        std::cout << std::endl;

        std::cout << "Post-order traversal: ";
        displayPostOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the Binary Search Tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display the Binary Search Tree with different traversals
    bst.display();

    return 0;
}*/










/*
//DELEETING AN ELEMENT OF A  BINARY SEARCH TREE
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void displayInOrder(TreeNode* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void display() {
        std::cout << "In-order traversal: ";
        displayInOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the Binary Search Tree
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        bst.insert(value);
    }

    // Display the Binary Search Tree before deletion
    std::cout << "Before Deletion:" << std::endl;
    bst.display();

    // Delete elements from the Binary Search Tree
    bst.remove(30);
    bst.remove(60);

    // Display the Binary Search Tree after deletion
    std::cout << "\nAfter Deletion:" << std::endl;
    bst.display();

    return 0;
}
*/









/*
//SEARCH AN ELEMENT IN A BINARY SEARCH TREE
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    TreeNode* searchNode(TreeNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    void displayInOrder(TreeNode* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    TreeNode* search(int value) {
        return searchNode(root, value);
    }

    void display() {
        std::cout << "In-order traversal: ";
        displayInOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the Binary Search Tree
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        bst.insert(value);
    }

    // Display the Binary Search Tree
    std::cout << "Binary Search Tree:" << std::endl;
    bst.display();

    // Search for elements in the Binary Search Tree
    int searchValue = 40;
    TreeNode* foundNode = bst.search(searchValue);

    if (foundNode != nullptr) {
        std::cout << "\nElement " << searchValue << " found in the Binary Search Tree." << std::endl;
    } else {
        std::cout << "\nElement " << searchValue << " not found in the Binary Search Tree." << std::endl;
    }

    return 0;
}
*/







/*
//BINARY SEARCH TREE IN DIFFERENT TRAVERSALS
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void displayPreOrder(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            displayPreOrder(node->left);
            displayPreOrder(node->right);
        }
    }

    void displayInOrder(TreeNode* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    void displayPostOrder(TreeNode* node) {
        if (node != nullptr) {
            displayPostOrder(node->left);
            displayPostOrder(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        std::cout << "Preorder traversal: ";
        displayPreOrder(root);
        std::cout << std::endl;

        std::cout << "Inorder traversal: ";
        displayInOrder(root);
        std::cout << std::endl;

        std::cout << "Postorder traversal: ";
        displayPostOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the Binary Search Tree
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        bst.insert(value);
    }

    // Display the Binary Search Tree in preorder, inorder, and postorder traversal
    std::cout << "Binary Search Tree:" << std::endl;
    bst.display();

    return 0;
}
*/

