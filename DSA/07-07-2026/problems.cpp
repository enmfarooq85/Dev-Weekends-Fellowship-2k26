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

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // if list is empty or the next node is null then we don't have to reverse the list
//         if (head == nullptr || head->next == nullptr)
//             return head;

//         // it is saying that please reverse the rest of list not me
//         ListNode* newHead = reverseList(head->next);

//         // point the next.next back to current node
//         // like 4->3
//         head->next->next = head;

//         // break the old connection
//         // means 3 still points to 4 so remvoe this connection
//         head->next = nullptr;

//         // it will return new head which the last node of reverse list points to null
//         return newHead;
//     }
// };

// https://leetcode.com/problems/partition-list/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     ListNode* reverseLinkList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }

//         ListNode* newHead = reverseLinkList(head->next);

//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     };

//     ListNode* partition(ListNode* head, int x) {
//         stack<int> linkedListStack;
//         ListNode* curr = head;

//         // first push those nodes those are less than x
//         while (curr != NULL) {
//             if (curr->val < x) {
//                 linkedListStack.push(curr->val);
//             };
//             curr = curr->next;
//         }
//         // cout << linkedListStack.top();

//         curr = head;
//         // second push those nodes those are greater than or equal to x
//         while (curr != NULL) {
//             if (curr->val >= x) {
//                 linkedListStack.push(curr->val);
//             };
//             curr = curr->next;
//         }
//         // cout << linkedListStack.top();

//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* currPtrDummyNode = dummyNode;

//         // pick up the nodes from stack according to LIFO principle and create a linked list but it is in the reverse order because we are first push the less nodes than x and then greater than or equal to x and according to problem statement less nodes should be before the greater than or eqaul to nodes
//         while (!linkedListStack.empty()) {
//             currPtrDummyNode->next = new ListNode(linkedListStack.top());
//             linkedListStack.pop();
//             currPtrDummyNode = currPtrDummyNode->next;
//         }
        
//         // finally reversing it
//         return reverseLinkList(dummyNode->next);
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode* small  = new ListNode(0);
//         ListNode* large  = new ListNode(0);
        
//         ListNode* smallP = small;
//         ListNode* largeP = large;
        
//         while(head) {
//             if(head->val < x) {
//                 smallP->next = head;
//                 smallP = smallP->next;
//             } else {
//                 largeP->next = head;
//                 largeP = largeP->next;
//             }
            
//             head = head->next;
//         }
        
//         largeP->next = NULL;
//         smallP->next = large->next;
//         return small->next;
//     }
// };

// https://leetcode.com/problems/merge-in-between-linked-lists/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     ListNode* reverseLinkList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }

//         ListNode* newHead = reverseLinkList(head->next);

//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     };

//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//         stack<int> l1Stack;
//         stack<int> l2Stack;
//         ListNode* curr = list1;

//         while (curr != NULL) {
//             l1Stack.push(curr->val);
//             curr = curr->next;
//         }

//         curr = list2;
//         while (curr != NULL) {
//             l2Stack.push(curr->val);
//             curr = curr->next;
//         }

//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* currPtr = dummyNode;
//         bool isRemove = false;
//         int count = l1Stack.size() - 1;

//         while (!l1Stack.empty()) {
//             if (count >= a && count <= b) {
//                 isRemove = true;
//                 l1Stack.pop();
//                 count--;
//             };

//             if (isRemove) {
//                 while (!l2Stack.empty()) {
//                     currPtr->next = new ListNode(l2Stack.top());
//                     l2Stack.pop();
//                     currPtr = currPtr->next;
//                 }
//                 isRemove = false;
//             } else {
//                 currPtr->next = new ListNode(l1Stack.top());
//                 l1Stack.pop();
//                 currPtr = currPtr->next;
//                 count--;
//             }
//         }

//         return reverseLinkList(dummyNode->next);
//     }
// };

// T.C => O(n+m)
// S.C => O(n+m)

// class Solution {
// public:
//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//         ListNode* left = new ListNode(-1);
//         ListNode* right = new ListNode(-1);
//         ListNode* leftPtr = left;
//         ListNode* rightPtr = right;

//         ListNode* curr = list1;

//         int count = 0;
//         bool isRemoval = false;

//         while (curr) {
//             if (count >= a && count <= b) {
//                 isRemoval = true;
//             };

//             if (isRemoval) {
//                 while (list2) {
//                     leftPtr->next = new ListNode(list2->val);
//                     list2 = list2->next;
//                     leftPtr = leftPtr->next;
//                 };
//                 isRemoval = false;
//             } else if (count > b) {
//                 rightPtr->next = new ListNode(curr->val);
//                 rightPtr = rightPtr->next;
//             } else {
//                 leftPtr->next = new ListNode(curr->val);
//                 leftPtr = leftPtr->next;
//             };

//             count++;
//             curr = curr->next;
//         }

//         cout << left->next->val << endl;
//         cout << right->next->val << endl;
//         leftPtr->next = right->next;

//         return left->next;
//     }
// };

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//         ListNode* leftPart = NULL;
//         ListNode* rightPart = list1;

//         // for pointing both leftPart and rightPart nodes
//         // less than b because we are moving like right->next
//         for (int i = 0; i <= b; i++) {
//             if (i == a - 1) {
//                 leftPart = rightPart;
//             };
            
//             rightPart = rightPart->next;
//         }

//         // attaching leftPart with list2
//         leftPart->next = list2;

//         ListNode* temp = list2;
//         // now going to last node of list2
//         while (temp && temp->next) {
//             temp = temp->next;
//         }

//         // when on last node we will attach rightPart
//         temp->next = rightPart;

//         return list1;
//     }
// };
