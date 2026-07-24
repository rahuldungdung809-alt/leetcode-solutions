/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //OPTIMAL SOLUTION (FLOYD'S CYCLE DETECTION ALGORITHM)
    bool hasCycle(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head;
        while((fast!=nullptr) && (fast->next !=nullptr)){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    // BRUTE FORCE SOLUTION 
    /*bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        while(head!=NULL){
            if(st.find(head)!=st.end()){
                return true;
            }
            st.insert(head);
            head=head->next;
        }
        return false;*/
    }
};