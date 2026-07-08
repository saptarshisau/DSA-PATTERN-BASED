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
    typedef ListNode node;

    node* rev(node* head) {
        if (!head || !head->next) return head;
        node* prev = nullptr;
        node* curr = head;
        node* nex = nullptr;
        
        while (curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        node* secondHalfHead = rev(slow->next);
        
        node *temp1 = head;
        node *temp2 = secondHalfHead;
        bool isPalin = true;

        while (temp2) {
            if (temp1->val != temp2->val) {
                isPalin = false;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        slow->next = rev(secondHalfHead);

        return isPalin;
    }
};
