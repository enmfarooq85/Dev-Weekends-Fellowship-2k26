// https://leetcode.com/problems/insertion-sort-list/description/

// T.C => O(2^n)
// S.C => O(n)

// olution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         if (!head || !head->next)
//             return head;

//         // Dummy node makes insertion at the beginning easier.
//         ListNode* dummy = new ListNode(0);

//         ListNode* curr = head;

//         while (curr) {
//             ListNode* nextNode = curr->next;

//             // Find the correct position for curr
//             ListNode* prev = dummy;

//             while (prev->next && prev->next->val < curr->val) {
//                 prev = prev->next;
//             }

//             // Insert curr between prev and prev->next
//             curr->next = prev->next;
//             prev->next = curr;

//             curr = nextNode;
//         }

//         ListNode* result = dummy->next;
//         delete dummy;

//         return result;
//     }
// };

// https://leetcode.com/problems/odd-even-linked-list/description/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if (!head || !head->next)
//             return head;

//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* evenHead = even;

//         while (even && even->next) {
            
//             odd->next = even->next;
//             odd = odd->next;

//             even->next = odd->next;
//             even = even->next;
//         }

//         odd->next = evenHead;

//         return head;
//     }
// };
