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

// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         int prefixSum = 0;
//         // maps a prefix sum to the node where it was last seen.
//         unordered_map<int, ListNode*> prefixSumMap;

//         // create a dummy node to handle cases where
//         // the zero-sum sublist starts from the head.
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;

//         // prefix sum 0 exists before the list starts.
//         prefixSumMap[0] = dummy;

//         while (head) {
//             prefixSum += head->val;

//             // If this prefix sum has appeared before,
//             // then the nodes between the previous occurrence
//             // and the current node sum to zero.
//             if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
//                 // Node where this prefix sum was first seen.
//                 ListNode* previousNode = prefixSumMap[prefixSum];

//                 // Used to traverse the zero-sum sublist.
//                 ListNode* currentNode = previousNode;

//                 // Temporary prefix sum for removing
//                 // intermediate prefix sums from the map.
//                 int tempPrefixSum = prefixSum;

//                 // Traverse all nodes inside the zero-sum sublist.
//                 while (currentNode != head) {
//                     currentNode = currentNode->next;
//                     tempPrefixSum += currentNode->val;

//                     // Remove intermediate prefix sums because
//                     // those nodes will be deleted.
//                     if (currentNode != head)
//                         prefixSumMap.erase(tempPrefixSum);
//                 }

//                 previousNode->next = head->next;
//             } else {
//                 // First time seeing this prefix sum.
//                 prefixSumMap[prefixSum] = head;
//             }

//             // Move to the next node.
//             head = head->next;
//         }

//         return dummy->next;
//     }
// };

// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int calcLength(ListNode* linkedList) {
//         int count = 0;
//         while (linkedList != NULL) {
//             linkedList = linkedList->next;
//             count++;
//         }
//         return count;
//     }

//     ListNode* swapNodes(ListNode* head, int k) {
//         if (head == NULL || head->next == NULL) {
//             return head;
//         }

//         int l = calcLength(head);

//         int leftKPosition = k;
//         int rightKPosition = l - k + 1;

//         ListNode* node1 = NULL;
//         ListNode* node2 = NULL;

//         ListNode* temp = head;

//         while (temp != NULL) {
//             if (leftKPosition == 1) {
//                 node1 = temp;
//                 break;
//             }

//             temp = temp->next;
//             leftKPosition--;
//         }

//         temp = head;

//         while (temp != NULL) {
//             if (rightKPosition == 1) {
//                 node2 = temp;
//                 break;
//             }

//             temp = temp->next;
//             rightKPosition--;
//         }

//         swap(node1->val, node2->val);

//         return head;
//     }
// };

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         ListNode* node1 = NULL;
//         ListNode* node2 = NULL;

//         ListNode* temp = head;
//         int count = 1;

//         while (temp != NULL){
//             if (node2 != NULL){
//                 node2 = node2->next;
//             }

//             if (count == k){
//                 node1 = temp;
//                 node2 = head;
//             }
    
//             count++;
//             temp = temp->next;
//         }

//         swap(node1->val, node2->val);

//         return head;
//     }
// };

