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

// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         if (head == NULL || head->next == NULL || head->next->next == NULL) {
//             return {-1, -1};
//         }
//         // you can say that we are starting from node 2 because first will not be always critical point as well as last
//         ListNode* prev = head;
//         ListNode* curr = head->next;
//         ListNode* next = curr->next;

//         vector<int> criticalPoints;
//         int count = 1;

//         while (next != nullptr) {
//             if (curr->val > prev->val && curr->val > next->val) {
//                 // Local Maxima
//                 criticalPoints.push_back(count);
//             } else if (curr->val < prev->val && curr->val < next->val) {
//                 // Local Minima
//                 criticalPoints.push_back(count);
//             }

//             count++;

//             prev = curr;
//             curr = curr->next;
//             next = curr->next;
//         }

//         if (criticalPoints.size() < 2) {
//             return {-1, -1};
//         }

//         int minDistance = INT_MAX;
//         // maximum will be must of always of last and first
//         int maxDistance = criticalPoints.back() - criticalPoints.front();

//         for (int i = 1; i < criticalPoints.size(); i++) {
//             int distance = criticalPoints[i] - criticalPoints[i - 1];
//             minDistance = min(minDistance, distance);
//         }

//         return {minDistance, maxDistance};
//     }
// };

// https://leetcode.com/problems/linked-list-in-binary-tree/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     // Check if linked list matches starting from this tree node
//     bool check(ListNode* head, TreeNode* root) {

//         // Linked list completely matched
//         if (head == nullptr)
//             return true;

//         // Tree ended before linked list
//         if (root == nullptr)
//             return false;

//         // Current values don't match
//         if (head->val != root->val)
//             return false;

//         // Continue either left or right
//         return check(head->next, root->left) ||
//                check(head->next, root->right);
//     }

//     bool isSubPath(ListNode* head, TreeNode* root) {

//         // Empty linked list always exists
//         if (head == nullptr)
//             return true;

//         // Tree is empty
//         if (root == nullptr)
//             return false;

//         // Try starting from current node
//         if (check(head, root))
//             return true;

//         // Otherwise try every node in left and right subtree
//         return isSubPath(head, root->left) ||
//                isSubPath(head, root->right);
//     }
// };

// https://leetcode.com/problems/design-twitter

// T = relevant tweets for a feed
// N = total tweets stored
// E = total follow relationships

// T.C => O(T log T)
// S.C => O(N + E)

// class Twitter {
// public:
//     // userId -> {tweetId, timestamp}
//     map<int, vector<pair<int, int>>> tweetsMp;

//     // followerId -> followeeIds
//     // followerId mtlb jis ne follow kia hua hy
//     // followeeId mtlb jis ko follow kia hua hy
//     map<int, vector<int>> following;

//     // timestamp so that we can sort the newest tweets
//     int timestamp;

//     Twitter() { timestamp = 1; }

//     void postTweet(int userId, int tweetId) {
//         tweetsMp[userId].push_back({tweetId, timestamp});
//         timestamp++;
//     }

//     vector<int> getNewsFeed(int userId) {
//         // This will contain tweets from:
//         // User himself
//         // Everyone he follows
//         vector<pair<int, int>> allTweets;

//         // Add user's own tweets
//         if (tweetsMp.find(userId) != tweetsMp.end()) {
//             for (auto tweet : tweetsMp[userId]) {
//                 allTweets.push_back(tweet);
//             }
//         }

//         // Add tweets of followees
//         if (following.find(userId) != following.end()) {
//             for (int followeeId : following[userId]) {
//                 if (tweetsMp.find(followeeId) == tweetsMp.end())
//                     continue;

//                 for (auto tweet : tweetsMp[followeeId]) {
//                     allTweets.push_back(tweet);
//                 }
//             }
//         }

//         // Sort newest -> oldest
//         sort(allTweets.begin(), allTweets.end(),
//              [](const pair<int, int>& a, const pair<int, int>& b) {
//                  return a.second > b.second;
//              });

//         // Return maximum 10 tweets
//         vector<int> result;
//         for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
//             result.push_back(allTweets[i].first);
//         }

//         return result;
//     }

//     void follow(int followerId, int followeeId) {
//         // Don't allow following yourself
//         if (followerId == followeeId)
//             return;

//         // If already following, don't add duplicate
//         for (int id : following[followerId]) {
//             if (id == followeeId)
//                 return;
//         }

//         // now just add follower
//         following[followerId].push_back(followeeId);
//     }

//     void unfollow(int followerId, int followeeId) {
//         // if the followerId not found return nothing
//         if (following.find(followerId) == following.end())
//             return;

//         // if found then unfollow it
//         vector<int>& followees = following[followerId];
//         for (auto it = followees.begin(); it != followees.end(); it++) {
//             if (*it == followeeId) {
//                 followees.erase(it);
//                 return;
//             }
//         }
//     }
// };
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
