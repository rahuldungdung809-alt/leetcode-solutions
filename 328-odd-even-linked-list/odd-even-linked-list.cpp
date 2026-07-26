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
    ListNode* oddEvenList(ListNode* head) {
        //OPTIMAL SOLUTION (USING REARRENGING )
        if(!head || !head->next){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        while(even && even->next){
            odd->next=even->next;
            odd=odd->next;

            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
        //******************************************
        //BETTER SOLUTION (USING SEPARATE LINKED LIST)
        /*if(!head){
            return head;
        }
        ListNode* oddHead=nullptr;
        ListNode* oddTail=nullptr;
        ListNode* evenHead=nullptr;
        ListNode* evenTail=nullptr;
        ListNode* curr=head;
        int pos=1;
        while(curr){
            if(pos%2){
                if(!oddHead){
                    oddHead=oddTail=curr;
                }
                else{
                    oddTail->next=curr;
                    oddTail=curr;
                }
            }
            else{
                if(!evenHead){
                    evenHead=evenTail=curr;
                }
                else{
                    evenTail->next=curr;
                    evenTail=curr;
                }  
            }
            curr=curr->next;
            pos++;
        }
        if(evenTail){
            evenTail->next=nullptr;
        }
        oddTail->next=evenHead;
        return oddHead;
        */
        //*********************************************
        //BRUTE FORCE SOLUTION (USING EXTRA SPACE )
        /*if(!head){
            return head;
        }
        vector<int>odd,even;
        ListNode* curr=head;
        int pos=1;
        while(curr){
            if(pos%2){
                odd.push_back(curr->val);
            }
            else{
                even.push_back(curr->val);
            }
            curr=curr->next;
            pos++;
        }
        curr=head;
        for(int x:odd){
            curr->val=x;
            curr=curr->next;
        }
        for(int x:even){
            curr->val=x;
            curr=curr->next;
        }
        return head;*/
        
    }
};