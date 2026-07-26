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
    ListNode* deleteMiddle(ListNode* head) {
        //OPTIMAL SOLUTION (SLOW AND FAST )
        if(head==nullptr || head->next==nullptr){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return head;
        //BETTER SOLUTION (ARRAY LIST)
        /*if(head==nullptr || head->next==nullptr){
            return NULL;
        }
        vector<ListNode*>nodes;
        ListNode* temp=head;
        while(temp!=nullptr){
            nodes.push_back(temp);
            temp=temp->next;
        }
        int mid=nodes.size()/2;
        nodes[mid-1]->next=nodes[mid]->next;
        return head;*/
        //BRUTE FORCE APPROACH
        /*if(head==nullptr || head->next==nullptr){
            return NULL;
        }
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        int mid=n/2;
        temp=head;
        for(int i=1;i<mid;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        */
    }
};