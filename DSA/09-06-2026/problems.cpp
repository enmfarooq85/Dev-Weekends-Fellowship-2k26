// count vowel in the string
// string hello = "hello";
// int count = 0;
// for (char ch : hello)
// {
//     if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//     {
//         count++;
//     }
// }
// cout << count << endl; // 2

// palindrome: means reading from start and end seem like same like mam will be mam either you read from forward or from back
// string m1 = "mam";
// int l = 0;
// int m = m1.length() - 1;
// while (l < m)
// {
//     if (m1[l] == m1[m])
//     {
//         l++;
//         m--;
//     }
//     else
//     {
//         cout << "This world is not palindrome." << endl;
//     }
// };

// if: else not run then means palindrome

// remove all coccurences of part from string

// string part = "ello";
// string str1 = "absdfellsellodfsellod";

// while (str1.length() > 0 && str1.find(part) < str1.length())
// {
//     str1.erase(str1.find(part), part.length());
// }
// cout << str1 << endl;

// https://leetcode.com/problems/jewels-and-stones

// string jewels = "aA";
// string stones = "aAAbbbb";
// int count1 = 0;

// // brute force: O(N * M)
// for (char stone : stones)
// {
//     for (char jewel : jewels)
//     {
//         if (stone == jewel)
//         {
//             count1++;
//             break;
//         }
//     }
// }

// cout << count1 << endl;

// Using Hashmap: O(N + m)

// unordered_map<char, int> freq;

// Count frequency of each stone
// for (char stone : stones)
// {
//     freq[stone]++;
// }


// int count2 = 0;
// Add frequencies of all jewels
// for (char jewel : jewels)
// {
//     if (freq.find(jewel) != freq.end())
//     {
//         count2 += freq[jewel];
//     }
// }

// cout << count2 << endl;

// https://leetcode.com/problems/repeated-substring-pattern/

// T.C => O(N)^2
// S.C => O(N)

// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         string stringCopy = s;

//         for (int i = 1; i < stringCopy.length(); i++) {
//             string pattern = stringCopy.substr(0, i);

//             string copy = "";

//             while (copy.length() < s.length()) {
//                 copy += pattern;
//             }

//             if (copy == s) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

// https://leetcode.com/problems/merge-strings-alternately/description/

// T.C => O(N + M)
// S.C => O(N + M)

// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         string ans = "";

//         int n = min(word1.length(), word2.length());

//         for (int i = 0; i < n; i++) {
//             ans += word1[i];
//             ans += word2[i];
//         }

//         if (word1.length() > word2.length()) {
//             for (int i = n; i < word1.length(); i++) {
//                 ans += word1[i];
//             }
//         } else {
//             for (int i = n; i < word2.length(); i++) {
//                 ans += word2[i];
//             }
//         }

//         return ans;
//     }
// };

// T.C => O(N + M)
// S.C => O(N + M)

// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         string ans = "";

//         int i = 0, j = 0;

//         while (i < word1.length() && j < word2.length()) {
//             ans += word1[i++];
//             ans += word2[j++];
//         }

//         while (i < word1.length()) {
//             ans += word1[i++];
//         }

//         while (j < word2.length()) {
//             ans += word2[j++];
//         }

//         return ans;
//     }
// };