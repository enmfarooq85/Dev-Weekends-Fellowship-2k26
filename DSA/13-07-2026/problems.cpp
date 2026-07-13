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
