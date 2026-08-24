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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(ListNode* head:lists){
            while(head !=NULL){
                arr.push_back(head->val);
                head=head->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        for(int x:arr){
            temp->next=new ListNode(x);
            temp=temp->next;
        }
        return dummy->next;
        
    }
};