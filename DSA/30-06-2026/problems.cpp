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

// https://leetcode.com/problems/find-all-anagrams-in-a-string

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     bool isAllZero(vector<int>& charIndices) {
//         for (auto& i : charIndices) {
//             if (i != 0) {
//                 return false;
//             }
//         }
//         return true;
//     };

//     vector<int> findAnagrams(string s, string p) {
//         int n = s.length();
//         int k = p.length();
//         if (n < k)
//             return {};

//         vector<int> charIndices(26, 0);
//         vector<int> ans;

//         for (char i : p) {
//             // picking character
//             // finding correct position of the char means a will point to zero
//             // and z will point to 26
//             charIndices[i - 'a']++;
//         }

//         int i = 0, j = 0;
//         while (j < n) {
//             // decreasing freq
//             charIndices[s[j] - 'a']--;
//             // if reached to window size then chk if find anagrams then push the
//             // starting index and shift the window
//             if (j - i + 1 == k) {
//                 if (isAllZero(charIndices)) {
//                     ans.push_back(i);
//                 }
//                 // increase the freq of extracted char
//                 charIndices[s[i] - 'a']++;
//                 // shift window
//                 i++;
//             };

//             // j will always move if window size reached or not
//             j++;
//         }

//         return ans;
//     };
// };

// https://leetcode.com/problems/minimum-size-subarray-sum/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int i = 0, j = 0;
//         int currSum = 0;
//         int minL = INT_MAX;

//         while (j < n) {
//             currSum += nums[j];
//             while (currSum >= target) {
//                 minL = min(minL, j - i + 1);
//                 currSum -= nums[i];
//                 i++;
//             }

//             j++;
//         }
//         cout << currSum << target << endl;

//         return minL == INT_MAX ? 0 : minL;
//     }
// };

// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     bool isAllZero(vector<int>& charIndices) {
//         for (auto& i : charIndices) {
//             if (i != 0) {
//                 return false;
//             }
//         }
//         return true;
//     };

//    int search(string &pat, string &txt) {
//         int n = txt.length();
//         int k = pat.length();
//         if (n < k)
//             return {};

//         vector<int> charIndices(26, 0);
//         int ans;

//         for (char i : pat) {
//             // picking character
//             // finding correct position of the char means a will point to zero
//             // and z will point to 26
//             charIndices[i - 'a']++;
//         }

//         int i = 0, j = 0;
//         while (j < n) {
//             // decreasing freq
//             charIndices[txt[j] - 'a']--;
//             // if reached to window size then chk if find anagrams then push the
//             // starting index and shift the window
//             if (j - i + 1 == k) {
//                 if (isAllZero(charIndices)) {
//                    ans++;
//                 }
//                 // increase the freq of extracted char
//                 charIndices[txt[i] - 'a']++;
//                 // shift window
//                 i++;
//             };

//             // j will always move if window size reached or not
//             j++;
//         }

//         return ans;
//     };
// };

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// T.C => O(n * k)
// S.C => O(n)

// class Solution {
// 	public:
// 	vector<int> copyRange(const vector<int>& arr, int start, int end) {
// 		return vector<int>(arr.begin() + start, arr.begin() + end + 1);
// 	}
	
// 	int findFirstNegativeInt(const vector<int>& nums) {
// 		for (int x : nums) {
// 			if (x < 0)
// 				return x;
// 		}
// 		return 0;
// 	}
	
// 	vector<int> firstNegInt(vector<int>& arr, int k) {
// 		// code here
// 		int n = arr.size();
// 		if (n < k) {
// 			return {};
// 		}
		
// 		int i = 0, j = 0;
// 		vector<int> ans;
		
// 		while (j < n) {
// 			if (j - i + 1 == k) {
// 				// means negative
// 				vector<int> window = copyRange(arr, i, j);
// 				int firstNegative = findFirstNegativeInt(window);
				
// 				if (firstNegative < 0) {
// 					ans.push_back(firstNegative);
// 				} else {
// 					ans.push_back(0);
// 				}
// 				i++;
// 			};
// 			j++;
// 		};
		
// 		return ans;
		
// 	}
// };
