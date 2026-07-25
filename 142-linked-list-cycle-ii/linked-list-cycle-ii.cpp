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
    ListNode *detectCycle(ListNode *head) {
        //OPTIMAL APPROACH (FLOYD'S TORTOISE AND HARE ALGORITHM )
        ListNode *slow=head;
        ListNode *fast=head;
        while((fast!=nullptr) && (fast->next !=nullptr)){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
        // BRUTE FORCE SOLUTION ( USING HASHSET)
        /*unordered_set<ListNode*>visited;
        while(head!=nullptr){
            if(visited.count(head)){
                return head;
            }
            visited.insert(head);
            head=head->next;
        }
        return nullptr;*/
        
    }
};