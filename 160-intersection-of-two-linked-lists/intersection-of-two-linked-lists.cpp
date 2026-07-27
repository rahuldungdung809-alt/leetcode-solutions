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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // OPTIMAL SOLUTION (TWO POINTER)
        ListNode* pA=headA;
        ListNode* pB=headB;
        while(pA!=pB){
            if(pA==nullptr){
                pA=headB;
            }
            else{
                pA=pA->next;
            }
            if(pB==nullptr){
                pB=headA;
            }
            else{
                pB=pB->next;
            }
        }
        return pA;
        //BETTER SOLUTION (USING HASH SET)
        /*unordered_set<ListNode*>st;
        ListNode* temp=headA;
        while(temp!=nullptr){
            st.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            if(st.find(temp)!=st.end()){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;*/
        //BRUTE FORCE APPROACH (COMPARE A WITH B)
        /*ListNode* tempA=headA;
        while(tempA!=nullptr){
            ListNode* tempB=headB;
            while(tempB!=nullptr){
                if(tempA==tempB){
                    return tempA;
                }
                tempB=tempB->next;
            }
            tempA=tempA->next;
        }
        return NULL;*/
        
    }
};