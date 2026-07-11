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

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         };

//         ListNode* mid = slow;

//         ListNode* prev = NULL;
//         ListNode* nextNode = NULL;

//         while (mid != NULL) {
//             nextNode = mid->next;
//             mid->next = prev;
//             prev = mid;
//             mid = nextNode;
//         }

//         ListNode* curr = head;
//         int maxSum = INT_MIN;
//         while (prev != NULL){
//             maxSum = max(maxSum, prev->val + curr->val);
//             prev = prev->next;
//             curr = curr->next;
//         }

//         return maxSum;
//     }
// };

// https://leetcode.com/problems/add-two-numbers/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* curr = dummyNode;

//         int carry = 0;

//         while (l1 || l2 || carry) {
//             int sum = carry;

//             if (l1) {
//                 sum += l1->val;
//                 l1 = l1->next;
//             }

//             if (l2) {
//                 sum += l2->val;
//                 l2 = l2->next;
//             }

//             carry = sum / 10;
//             sum = sum % 10;

//             curr->next = new ListNode(sum);
//             curr = curr->next;
//         };

//         return dummyNode->next;
//     }
// };

// https://leetcode.com/problems/add-two-numbers-ii/description/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         stack<int> l1Stack;
//         stack<int> l2Stack;
//         while (l1) {
//             l1Stack.push(l1->val);
//             l1 = l1->next;
//         }

//         while (l2) {
//             l2Stack.push(l2->val);
//             l2 = l2->next;
//         }

//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* curr = dummyNode;

//         int carry = 0;
//         while (!l1Stack.empty() || !l2Stack.empty() || carry) {
//             int sum = carry;

//             if (!l1Stack.empty()) {
//                 sum += l1Stack.top();
//                 l1Stack.pop();
//             }

//             if (!l2Stack.empty()) {
//                 sum += l2Stack.top();
//                 l2Stack.pop();
//             }

//             carry = sum / 10;
//             sum = sum % 10;

//             ListNode* node = new ListNode(sum);
//             node->next = dummyNode->next;
//             dummyNode->next = node;
//         };

//         return dummyNode->next;
//     }
// };

// https://leetcode.com/problems/reverse-linked-list/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* next = NULL;
//         ListNode* curr = head;
//         ListNode* prev = NULL;

//         while (curr != NULL){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         return prev;
//     }
// };
