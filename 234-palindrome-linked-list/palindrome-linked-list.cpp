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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        while(head){
            ListNode* nextNode=head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHalf=reverse(slow->next);
        ListNode* firstHalf=head;
        ListNode* temp=secondHalf;
        while(temp){
            if(firstHalf->val != temp->val){
                return false;
            }
            firstHalf=firstHalf->next;
            temp=temp->next;
        }
        return true;
        //BETTER APPROCH (USING STACK)
        /*stack<int>st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val!=st.top()){
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;*/
        //BRUTE FORCE SOLUTION (USING ARRAY)
        /*vector<int>arr;
        while(head!=nullptr){
            arr.push_back(head->val);
            head=head->next;
        }
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            if(arr[left]!=arr[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;*/
        
    }
};