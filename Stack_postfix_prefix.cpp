#include <iostream>
#include <stack>
#include <cmath>  // For power function in postfix evaluation

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        } else {
            std::cout << "Stack Overflow: Cannot push " << value << ", stack is full." << std::endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            std::cout << "Stack Underflow: Cannot pop from an empty stack." << std::endl;
            return -1;  // Assuming -1 as an invalid value for simplicity
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1;  // Assuming -1 as an invalid value for simplicity
        }
    }
};

// Function to evaluate a prefix expression
int evaluatePrefix(const std::string& expression) {
    Stack stack;
    int result = 0;

    for (int i = expression.size() - 1; i >= 0; --i) {
        char currentChar = expression[i];

        if (isdigit(currentChar)) {
            stack.push(currentChar - '0');
        } else {
            int operand1 = stack.pop();
            int operand2 = stack.pop();

            switch (currentChar) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = static_cast<int>(std::pow(operand1, operand2));
                    break;
                default:
                    std::cout << "Invalid operator in the prefix expression." << std::endl;
                    return -1;  // Assuming -1 as an invalid value for simplicity
            }

            stack.push(result);
        }
    }

    return stack.pop();
}

// Function to evaluate a postfix expression
int evaluatePostfix(const std::string& expression) {
    Stack stack;

    for (char currentChar : expression) {
        if (isdigit(currentChar)) {
            stack.push(currentChar - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (currentChar) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                case '^':
                    stack.push(static_cast<int>(std::pow(operand1, operand2)));
                    break;
                default:
                    std::cout << "Invalid operator in the postfix expression." << std::endl;
                    return -1;  // Assuming -1 as an invalid value for simplicity
            }
        }
    }

    return stack.pop();
}

int main() {
    // Example of evaluating a prefix expression
    std::string prefixExpression = "+*32^45";
    int resultPrefix = evaluatePrefix(prefixExpression);
    std::cout << "Result of prefix expression " << prefixExpression << ": " << resultPrefix << std::endl;

    // Example of evaluating a postfix expression
    std::string postfixExpression = "32*45^+";
    int resultPostfix = evaluatePostfix(postfixExpression);
    std::cout << "Result of postfix expression " << postfixExpression << ": " << resultPostfix << std::endl;

    return 0;
}
