/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode*  l3 = ans;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr){
                l3->val += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                l3->val += l2->val;
                l2 = l2->next;
            }

            int save = 0;
            if(l3 ->val >= 10){
                l3 ->val -= 10;
                save = 1;
            }


            if(l1 != nullptr || l2 != nullptr || save > 0){
                l3->next = new ListNode();
                l3 = l3->next;
                l3 -> val = save;
            }else{
                l3 = l3->next;
            }
        }
     


        return ans;
    }
};
