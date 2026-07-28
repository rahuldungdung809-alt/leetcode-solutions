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
        ListNode* prev = NULL;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        /*vector<int> arr;

        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i + k <= arr.size(); i += k) {
            reverse(arr.begin() + i, arr.begin() + i + k);
        }

        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;*/
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp) {

            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextGroup = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverseList(temp);

            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            prevLast = temp;
            temp = nextGroup;
        }

        return head;

        
    }
};