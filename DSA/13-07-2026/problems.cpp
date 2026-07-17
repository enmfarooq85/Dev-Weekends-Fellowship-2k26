// https://leetcode.com/problems/k-th-symbol-in-grammar/

// T.C => O(n)
// S.C => O(n ^ 2)

// Note: This solution will produce TLE or MLE.

// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         vector<int> currentRow = {0};

//         for (int i = 2; i <= n; i++) {
//             vector<int> nextRow;

//             for (int val : currentRow) {
//                 if (val == 0) {
//                     nextRow.push_back(0);
//                     nextRow.push_back(1);
//                 } else {
//                     nextRow.push_back(1);
//                     nextRow.push_back(0);
//                 }
//             }

//             currentRow = nextRow;
//         }

//         return currentRow[k - 1];
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         if (k == 1 && n == 1) {
//             return 0;
//         }

//         // calculate current row length
//         int length = pow(2, n - 1);
//         // find current row mid
//         int mid = length / 2;

//         // just return the previous row result element
//         // because have same result like previous
//         if (k <= mid) {
//             return kthGrammar(n - 1, k);
//         } else {
//             // return the flip version of previous row element
//             // because the next mid is just flip of previous first half
//             return 1 - kthGrammar(n - 1, k - mid);
//         };
//     }
// };

// https://leetcode.com/problems/construct-string-from-binary-tree/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     string tree2str(TreeNode* root) {
//         if (root == NULL) {
//             return "";
//         }

//         string result = to_string(root->val);
//         string left = tree2str(root->left);
//         string right = tree2str(root->right);

//         if (root->left == NULL && root->right == NULL) {
//             return result;
//         } else if (root->left == NULL) {
//             return result + "()" + "(" + right + ")";
//         } else if (root->right == NULL) {
//             return result + "(" + left + ")";
//         } else if (root->left != NULL && root->right != NULL) {
//             return result + "(" + left + ")" + "(" + right + ")";
//         }

//         return result;
//     }
// };

// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// T.C => O(n * n)
// S.C => O(n)

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         if (n == 1) {
//             return n;
//         };

//         vector<int> ans;

//         for (int i = 1; i <= n; i++) {
//             ans.push_back(i);
//         };

//         int startingPoint = 0;
//         while (ans.size() > 1){
//             int removedElementIndex = ((startingPoint + k) - 1) % ans.size();
//             ans.erase(ans.begin() + removedElementIndex);
//             startingPoint = removedElementIndex;
//         }

//         return ans[0];
//     }
// };

// T.C => O(n * k)
// S.C => O(n)

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int> qu;
//         for (int i = 1; i <= n; i++)
//         {
//             qu.push(i);
//         }

//         while (qu.size() > 1){
//             for (int count = 1; count <= k -1; count++){
//                 qu.push(qu.front());
//                 qu.pop();
//             }

//             qu.pop();
//         }
//         return qu.front();
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int findWinnerFriendIndex(int n, int k) {
//         // if only one left then i have to return 0 index
//         // then we will add k + 1 to return the original array index element
//         if (n == 1) {
//             return 0;
//         }

//         // removed one friend
//         int idx = findWinnerFriendIndex(n - 1, k);
//         // now, add k in the idx to find original index because we removed kth element
//         // also make sure that it doesn't overflow
//         idx = (idx + k) % n;

//         return idx;
//     }

//     int findTheWinner(int n, int k) {
//         int winnerIndex = findWinnerFriendIndex(n, k);
//         // we found the original position in the array
//         // now add + 1 to index and return the friend identifier
//         return winnerIndex + 1;
//     }
// };

// https://leetcode.com/problems/integer-to-english-words

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     unordered_map<int, string> belowTenMap = {
//         {0, ""},     {1, "One"}, {2, "Two"},   {3, "Three"}, {4, "Four"},
//         {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
//     unordered_map<int, string> belowTwentyMap = {
//         {10, "Ten"},      {11, "Eleven"},  {12, "Twelve"},  {13, "Thirteen"},
//         {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
//         {18, "Eighteen"}, {19, "Nineteen"}};
//     unordered_map<int, string> belowHundreMap = {
//         {1, "Ten"},   {2, "Twenty"},  {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"},
//         {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

//     string solve(int num) {
//         if (num < 10) {
//             return belowTenMap[num];
//         }

//         if (num < 20) {
//             return belowTwentyMap[num];
//         }

//         if (num < 100) {
//             // 99 => Ninety Nine
//             return belowHundreMap[num / 10] +
//                    ((num % 10 != 0) ? " " + belowTenMap[num % 10] : "");
//         }

//         if (num < 1000) {
//             // 998 => Nine Hundred Ninty Eight
//             return solve(num / 100) + " Hundred" +
//                    ((num % 100 != 0) ? " " + solve(num % 100) : "");
//         }

//         if (num < 1000000) {
//             // 10023 => Ten Thousand Twenty Three
//             return solve(num / 1000) + " Thousand" +
//                    ((num % 1000 != 0) ? " " + solve(num % 1000) : "");
//         }

//         if (num < 1000000000) {
//             return solve(num / 1000000) + " Million" +
//                    ((num % 1000000 != 0) ? " " + solve(num % 1000000) : "");
//         }

//         return solve(num / 1000000000) + " Billion" +
//                ((num % 1000000000 != 0) ? " " + solve(num % 1000000000) : "");
//     }

//     string numberToWords(int num) {
//         if (num == 0) {
//             return "Zero";
//         }

//         return solve(num);
//     }
// };

// Note: A new version of previous approach.

// class Solution {
// public:
//     unordered_map<int, string> below10 = {
//         {0, ""},     {1, "One"}, {2, "Two"},   {3, "Three"}, {4, "Four"},
//         {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
//     unordered_map<int, string> below20 = {
//         {10, "Ten"},      {11, "Eleven"},  {12, "Twelve"},  {13, "Thirteen"},
//         {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
//         {18, "Eighteen"}, {19, "Nineteen"}};
//     unordered_map<int, string> below100 = {
//         {1, "Ten"},   {2, "Twenty"},  {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"},
//         {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

//     string solve(int num) {
//         if (num >= 0 && num <= 9) {
//             return below10[num];
//         }

//         if (num >= 10 && num <= 19) {
//             return below20[num];
//         }

//         if (num >= 20 && num <= 99) {
//             return below100[num / 10] +
//                    ((num % 10 != 0) ? " " + below10[num % 10] : "");
//         }

//         if (num >= 100 && num <= 999) {
//             return solve(num / 100) + " Hundred" +
//                    ((num % 100 != 0) ? " " + solve(num % 100) : "");
//         }

//         if (num >= 1000 && num <= 999999) {
//             return solve(num / 1000) + " Thousand" +
//                    ((num % 1000 != 0) ? " " + solve(num % 1000) : "");
//         }

//         if (num >= 1000000 && num <= 999999999) {
//             return solve(num / 1000000) + " Million" +
//                    ((num % 1000000 != 0) ? " " + solve(num % 1000000) : "");
//         } else {
//             return solve(num / 1000000000) + " Billion" +
//                    ((num % 1000000000 != 0) ? " " + solve(num % 1000000000)
//                                             : "");
//         }
//     };

//     string numberToWords(int num) {
//         if (num == 0) {
//             return "Zero";
//         }

//         return solve(num);
//     };
// };