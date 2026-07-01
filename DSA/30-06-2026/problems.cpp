// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//         int n = s.length();

//         if (n < 3)
//             return 0;

//         char a = s[0];
//         char b = s[1];
//         char c = s[2];

//         int count = 0;

//         for (int i = 3; i < n; i++) {
//             if (a != b && b != c && c != a) {
//                 count++;
//             }

//             a = b;
//             b = c;
//             c = s[i];
//         }

//         // Check the last window
//         if (a != b && b != c && c != a) {
//             count++;
//         }

//         return count;
//     }
// };

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

// T.C => O(n)
// S.C => O(1)

// int maxVowels(string s, int k)
// {
//     if (s.length() < k)
//     {
//         return 0;
//     }

//     int maxVowels = 0;
//     int windowVowels = 0;
//     int n = string.length();

//     unordered_set<char> vowles = {'a', 'i', 'e', 'o', 'u'};

//     for (int i = 0; i < k; i++)
//     {
//         if (vowels.count(s[i]))
//         {
//             windowVowels++;
//         }
//     }
//     maxVowels = windowVowels;

//     for (int i = k; i < n; i++)
//     {
//         if (vowles.count(s[i - k]))
//         {
//             windowVowels--;
//         }
//         if (vowles.count(s[i]))
//         {
//             windowVowels++;
//         }

//         maxVowels = max(windowVowels, maxVowels);
//     }
//     return maxVowels;
// };

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     bool hasAllCodes(string s, int k) {
       
//         unordered_set<string> st;
        
//         int n          = s.length();
//         int possibleCodes = pow(2, k); 
            
//         for(int i = k; i<=n; i++) {
//             string a = s.substr(i-k, k);
//             if(!st.count(a)) {
//                 st.insert(a);
//                 possibleCodes--;
                
//                 if(possibleCodes == 0)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
