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
    ListNode* reverseList(ListNode* head) {
        // OPTIMAL APPROACH ( THREE POINTER )
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
        //*******************************************
        //BETTER APPROACH ( USING STACK )
        /*if(head==nullptr ||head->next==nullptr){
            return head;
        }
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp!=nullptr){
            st.push(temp);
            temp=temp->next;
        }
        ListNode* newHead=st.top();
        st.pop();
        temp=newHead;
        while(!st.empty()){
            temp->next=st.top();
            st.pop();
            temp=temp->next;
        }
        temp->next=nullptr;
        return newHead;*/
        //*********************************************
        // BRUTE FORCE SOLUTION (USING ARRAY)
        /*vector<int>arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=arr.size()-1;
        while(temp!=nullptr){
            temp->val=arr[i];
            i--;
            temp=temp->next;
        }
        return head;*/
        
    }
};