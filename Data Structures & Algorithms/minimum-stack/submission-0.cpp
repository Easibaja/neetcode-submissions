#include <limits>
#include <utility>

class MinStack {
private:
    class Node {
    public:
        std::pair<int, int> value;
        Node* next;
        Node(int value, int min, Node* current) : value({value, min}), next(current) {}
    };

    Node* head;

public:
    MinStack() {
        head = nullptr;
    }

    MinStack(const MinStack&) = delete;
    MinStack& operator=(const MinStack&) = delete;

    ~MinStack() {
        while (head != nullptr) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }
    
    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            int min = head->value.second;
            if (val < min) {
                min = val;
            }
            Node* temp = new Node(val, min, head);
            head = temp;
        }
    }
    
    void pop() {
        if (head != nullptr)
        {    
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const {
        return head == nullptr;
    }
    
    /**
    * @brief Returns the top element of the stack.
    * @warning The caller must check that the stack is not empty before calling.
    */
    int top() {
        return head->value.first;
    }

    /**
    * @brief Returns the minimum element in the stack.
    * @warning The caller must check that the stack is not empty before calling.
    */
    int getMin() {
        return head->value.second;
    }
};
