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

// T.C => O(n)
// S.C => O(n)

// class Solution {
// 	public:
// 	// to avoid writing again and again long long
// 	typedef long long ll;
// 	vector<int> firstNegInt(vector<int>& arr, int k) {
// 		int i = 0, j = 0;
// 		int n = arr.size();
		
// 		queue<ll> negativeIntQueue;
// 		vector<int> ans;
		
// 		while (j < n) {
// 			if (arr[j] < 0) {
// 				negativeIntQueue.push(arr[j]);
// 			};
			
// 			if (j - i + 1 == k) {
// 				if (!negativeIntQueue.empty()) {
// 					ans.push_back(negativeIntQueue.front());
// 				} else {
// 					ans.push_back(0);
// 				};
				
// 				if (!negativeIntQueue.empty() && arr[i] < 0) {
// 					negativeIntQueue.pop();
// 				};
				
// 				i++;
// 			};
			
// 			j++;
// 		};
		
// 		return ans;
// 	};
// };

// T.C => O(n)
// S.C => O(n)

// Note: TC and SC is same, but dequeue is mostly used in the sliding window problems as well as we store indices in the deque. That is the main reason behing more good code rather than prev approach. 

// class Solution {
// public:
//     vector<int> firstNegInt(vector<int>& arr, int k) {
//         // stores indices of negative elements
//         deque<int> deq;
//         // store find result
//         vector<int> result;

//         int n = arr.size();

//         // process the first window of size k
//         // store indices of all negative numbers in the deque
//         for (int i = 0; i < k; i++) {
//             if (arr[i] < 0) {
//                 deq.push_back(i);
//             }
//         }

//         // process the remaining windows
//         for (int i = k; i < n; i++) {

//             // font of the deque always contains the index
//             // of the first negative number in the current window.
//             if (!deq.empty()) {
//                 result.push_back(arr[deq.front()]);
//             } else {
//                 result.push_back(0);
//             }

//             // remove indices that are no longer part of the current window.
//             while (!deq.empty() && deq.front() < i - k + 1) {
//                 deq.pop_front();
//             }

//             // add the current element's index if it is negative.
//             if (arr[i] < 0) {
//                 deq.push_back(i);
//             }
//         }

//         // process the last window
//         if (!deq.empty()) {
//             result.push_back(arr[deq.front()]);
//         } else {
//             result.push_back(0);
//         }

//         return result;
//     }
// };

// https://leetcode.com/problems/minimum-window-substring/description/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.length();
//         map<char, int> mp;

//         for (char& ch : t) {
//             mp[ch]++;
//         }

//         int requiredStringCount = t.length();
//         int i = 0, j = 0;
//         int startIndex = 0;
//         int minWindowSize = INT_MAX;

//         while (j < n) {
//             // if s[j] in map has value greater than zero it means we required it so do -1 to requiredSubstringCount
//             if (mp[s[j]] > 0){
//                 requiredStringCount--;
//             }
            
//             // always reduce the s[j] count either present in map or not
//             // it help us to shrink the size as much as possible
//             mp[s[j]]--;

//             // try to shrink the window untill our requiredSubstringCount remains zero so that we get min size substring
//             while (requiredStringCount == 0) {
//                 int currWindowSize = j - i + 1;
//                 if (minWindowSize > currWindowSize) {
//                     minWindowSize = currWindowSize;
//                     startIndex = i;
//                 }
                
//                 // incrementing plus one to every i element that we will removed from window
//                 mp[s[i]]++;

//                 // if i element that we are going to extract it is one char of t then we need to check this in the upcoming window
//                 if (mp[s[i]] > 0){
//                     requiredStringCount++;
//                 }
                
//                 // shrink
//                 i++;
//             }

//             // always move on
//             j++;
//         }

//         // minWindow remains INT_MAX then return empty string otherwise minWindow substring
//         return minWindowSize == INT_MAX ? "" : s.substr(startIndex, minWindowSize);
//     }
// };
  
// https://leetcode.com/problems/contains-duplicate-ii/description/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_set<int> st;
//         int i = 0, j = 0;
        
//         while(j < n) {
//             while(abs(i-j) > k) {
//                 st.erase(nums[i]);
//                 i++;
//             }
            
//             if(st.find(nums[j]) != st.end()) {
//                 return true;
//             }
            
//             st.insert(nums[j]);
//             j++;
//         }
        
//         return false;
//     }
// };

// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         long long ans = 0;

//         int minKPosition = -1;
//         int maxKPosition = -1;
//         int wrongIndex = -1;

//         for (int i = 0; i < nums.size(); i++) {
            
//             // If the current element is outside the valid range,
//             // any subarray including this element becomes invalid.
//             if (nums[i] < minK || nums[i] > maxK)
//                 wrongIndex = i;

//             // Update the latest occurrence of minK.
//             if (nums[i] == minK)
//                 minKPosition = i;

//             // Update the latest occurrence of maxK.
//             if (nums[i] == maxK)
//                 maxKPosition = i;

//             // earliest position that guarantees both minK and maxK
//             // are included is
//             // next subarray must start AFTER the latest invalid index.
//             int count = min(minKPosition, maxKPosition) - wrongIndex;

//             // If count is positive, add it to the answer.
//             // Otherwise, no valid subarray ends at index i.
//             ans += (count > 0) ? count : 0;
//         }

//         return ans;
//     }
// };

