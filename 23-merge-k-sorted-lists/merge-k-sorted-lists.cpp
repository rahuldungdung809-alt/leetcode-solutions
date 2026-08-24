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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } 
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        return NULL;
    }
    ListNode* PartionandMerge(int start,int end,vector<ListNode*>& lists){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        }
        int mid=start+(end-start)/2;
        ListNode* L1=PartionandMerge(start,mid,lists);
        ListNode* L2=PartionandMerge(mid+1,end,lists);
        return mergeTwoLists(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        return PartionandMerge(0,k-1,lists);
        //BRUTE FORCE SOLUTION TC:O(N LOG N)   SC:O(N)
        /*vector<int>arr;
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
        return dummy->next;*/
        
    }
};