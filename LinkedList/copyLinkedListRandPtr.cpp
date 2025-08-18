#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> map = {};
        map[nullptr] = nullptr;


        Node* curr = head;

        while (curr)
        {
            map[curr] = new Node(curr->val);
            curr++;
        }

        curr = head;
        while (curr)
        {
            Node* copy = map[curr];
            copy->next = map[curr->next];
            copy->random = map[curr->random];
            curr++;
        }

        return map[head];
    }
};