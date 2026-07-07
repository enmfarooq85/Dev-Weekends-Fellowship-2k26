// https://leetcode.com/problems/linked-list-random-node/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> arr;
//     Solution(ListNode* head) {
//         ListNode* temp = head;
//         while (temp) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//     }

//     int getRandom() {
//         int n = arr.size();
//         int r_index = rand() % n;
//         return arr[r_index];
//     }
// };

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* temp;
//     Solution(ListNode* head) { temp = head; };

//     int getRandom() {
//         int res;
//         ListNode* curr = temp;
//         int size = 1;
//         while (curr) {
//             // choosing probability is 1/size
//             if (rand() % size == 0)
//                 res = curr->val;
//             curr = curr->next;
//             size++;
//         }
//         return res;
//     }
// };
