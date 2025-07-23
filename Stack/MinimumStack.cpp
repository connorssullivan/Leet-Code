#include <memory>
#include <math.h>
#include <assert.h>
#include <iostream>

class MinStack {
private:
    struct Node 
    {
        int val;
        int minSoFar;
        std::unique_ptr<Node> next;

        Node(int v, int min, std::unique_ptr<Node> nextNode)
        : val(v) , minSoFar (min), next (std::move(nextNode))
        {
        }
    };

    std::unique_ptr<Node> head;
    
public:
    MinStack() : head(nullptr) {}
    
    void push(int val) 
    {
        if (!head)
            head = std::make_unique<Node>(val, val, nullptr);
        else 
        {
            int newMin = std::min(val, head->minSoFar);
            head = std::make_unique<Node>(val, newMin, std::move(head));
        }
    }
    
    void pop() {
        if (head)
        {
            head = std::move(head->next);
        }
    }
    
    int top() {
        //assert(head && "No top when top() called");

        return head->val;
    }
    
    int getMin() {
        //assert(head && "No top when min() called");

        return head->minSoFar;
    }
};


int main() {
    MinStack s;
    s.push(1);
    s.push(2);
    s.push(0);
    std::cout << "Min: " << s.getMin() << "\n";  // Expect 0
    s.pop();
    std::cout << "Top: " << s.top() << "\n";     // Expect 2
    std::cout << "Min: " << s.getMin() << "\n";  // Expect 1
}
