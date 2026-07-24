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
    ListNode* middleNode(ListNode* head) {
        //OPTIMAL APPROACH [ SLOW AND FAST POINTER ]
        ListNode* slow=head;
        ListNode* fast=head;
        while((fast!=nullptr)&&(fast->next!=nullptr)){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;


        /* BRUTE FORCE APPROACH [ TWO TRAVERSAL ]
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int middle=count/2;
        temp=head;
        while(middle--){
            temp=temp->next;
        }
        return temp;*/
        
    }
};