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
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left!=NULL){
            temp->next=left;
        }
        if(right!=NULL){
            temp->next=right;
        }
        return dummy->next;

    }
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* right=slow->next;
        slow->next=NULL;
        ListNode* left=head;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);

        //BETTER SOLUTION(INSERTION SORT)
        /*if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* sorted=NULL;
        while(head!=nullptr){
            ListNode* curr=head;
            head=head->next;
            if(sorted==NULL || curr->val<sorted->val){
                curr->next=sorted;
                sorted=curr;
            }
            else{
                ListNode* temp=sorted;
                while(temp->next!=nullptr && temp->next->val <curr->val){
                    temp=temp->next;
                }
                curr->next=temp->next;
                temp->next=curr;
            }
        }
        return sorted;*/
        //********************************************
        //BRUTE FORCE SOLUTION (STORE VALUE AND SORT)
        /*vector<int>arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp=head;
        for(int x:arr){
            temp->val=x;
            temp=temp->next;

        }
        return head;*/
    }
};