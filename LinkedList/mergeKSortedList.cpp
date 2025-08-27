#include <vector> 
 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  
class Solution {
private:
    ListNode* nextNode(std::vector<ListNode*>& lists)
    {
        ListNode* smallest = nullptr;
        int index = 0;
        int smallest_index = -1;

        for (auto l : lists)
        {
            if (!l)
                continue;
            else
            {
                if (!smallest || smallest->val > l->val)
                {
                    smallest = l;
                    smallest_index = index;
                }
            }
            index++;
        }

        if (smallest_index != -1)
            lists[smallest_index] = lists[smallest_index]->next;


        return smallest;
    }
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::vector<ListNode*> curr_list;
        
        ListNode* first = nullptr;
        for (auto head : lists)
        {
            if (!head)
                continue;
            else
            {
                curr_list.push_back(head);
            }
        }

        ListNode dummy {};
        ListNode* curr = nextNode(curr_list);

        dummy.next = curr;

        while (curr)
        {
            curr->next = nextNode(curr_list);
            curr = curr->next;
        }


        return dummy.next;
        
    }
};