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

// https://leetcode.com/problems/lru-cache/

// T.C => O(n^2)
// S.C => O(n)

// class LRUCache {
// public:
//     vector<pair<int, int>> cache;
//     int n;

//     LRUCache(int capacity) { n = capacity; }

//     int get(int key) {
//         for (int i = 0; i < cache.size(); i++) {
//             if (cache[i].first == key) {
//                 int val = cache[i].second;

//                 pair<int, int> temp = cache[i];
//                 cache.erase(cache.begin() + i);
//                 cache.push_back(temp);

//                 return val;
//             }
//         }

//         return -1;
//     }

//     void put(int key, int value) {
//         for (int i = 0; i < cache.size(); i++) {
//             if (cache[i].first == key) {
//                 cache.erase(cache.begin() + i);
//                 cache.push_back({key, value});
//                 return;
//             }
//         }

//         if (cache.size() == n) {
//             cache.erase(cache.begin());
//             cache.push_back({key, value});
//         } else {
//             cache.push_back({key, value});
//         }
//     }
// };

// T.C => O(1)
// S.C => O(n)

// class LRUCache {
// public:
//     list<int> doublyLinkedList;
//     map<int, pair<list<int>::iterator, int>> cache;
//     int size;

//     LRUCache(int capacity) { size = capacity; }

//     void shiftRecentlyUsedNodeToFront(int key) {
//         doublyLinkedList.erase(cache[key].first);
//         doublyLinkedList.push_front(key);

//         cache[key].first = doublyLinkedList.begin();
//     }

//     int get(int key) {
//         if (cache.find(key) == cache.end()) {
//             return -1;
//         }

//         shiftRecentlyUsedNodeToFront(key);

//         return cache[key].second;
//     }

//     void put(int key, int value) {
//         if (cache.find(key) != cache.end()) {
//             cache[key].second = value;
//             shiftRecentlyUsedNodeToFront(key);
//         } else {
//             doublyLinkedList.push_front(key);
//             cache[key] = {doublyLinkedList.begin(), value};

//             size--;
//         }

//         if (size < 0) {
//             int nodeToDel = doublyLinkedList.back();
//             cache.erase(nodeToDel);
//             doublyLinkedList.pop_back();
//             size++;
//         }
//     }
// };

// https://leetcode.com/problems/split-linked-list-in-parts/

// T.C => O(l + k)
// S.C => O(1)

// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         ListNode* curr = head;

//         int length = 0;
//         while (curr) {
//             length++;
//             curr = curr->next;
//         }

//         int eachBucketNodes = length / k;
//         int extraNodes = length % k;

//         vector<ListNode*> result(k, NULL);
//         curr = head;
//         ListNode* prev = NULL;

//         for (int i = 0; i < k; i++) {
//             result[i] = curr;

//             for (int count = 1;
//                  count <= eachBucketNodes + (extraNodes > 0 ? 1 : 0); count++) {

//                 prev = curr;
//                 curr = curr->next;
//             }

//             if (prev != NULL) {
//                 prev->next = NULL;
//             }
//             extraNodes--;
//         }

//         return result;
//     }
// };

// https://leetcode.com/problems/linked-list-components

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int numComponents(ListNode* head, vector<int>& nums) {
//         unordered_set<int> st(nums.begin(), nums.end());

//         int components = 0;

//         while (head) {
//             if (st.count(head->val) &&
//                 (head->next == nullptr || !st.count(head->next->val))) {
//                 components++;
//             }

//             head = head->next;
//         }

//         return components;
//     }
// };
