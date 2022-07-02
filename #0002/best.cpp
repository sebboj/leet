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
        int carry = 0;
        int sum = 0;
        
        ListNode *sol = new ListNode();
        ListNode *curr = sol;
        
        while(l1 != nullptr and l2 != nullptr){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum %= 10;
            curr->val = sum;
            
            l1 = l1->next;
            l2 = l2->next;
            
            if(l1 != nullptr or l2 != nullptr){
                ListNode *temp = new ListNode();
                curr->next = temp;             
                curr = curr->next;
            }
            
        }

        while(l1 != nullptr){ //fills with the rest of l1
            sum = l1->val + carry;
            carry = sum/10;
            sum %= 10;
            curr->val = sum;
            
            l1 = l1->next;
            
            if(l1 != nullptr){
                ListNode *temp = new ListNode();
                curr->next = temp;             
                curr = curr->next;
            }
        }

        while(l2 != nullptr){ //fills with the rest of l2
            sum = l2->val + carry;
            carry = sum/10;
            sum %= 10;
            curr->val = sum;
            
            l2 = l2->next;
            
            if(l2 != nullptr){
                ListNode *temp = new ListNode();
                curr->next = temp;             
                curr = curr->next;
            }
        }
        
        if(carry != 0){ //check to see if there is a final carry to include
            ListNode *temp = new ListNode();
            curr->next = temp;             
            curr = curr->next;
            curr->val = carry;
        }
        
        return sol; 
    }
};
