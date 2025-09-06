
// Given a string s, return the length of the longest substring that contains at most two distinct characters.




// Examples:
// Example 1:

// Input: s = "eceba"

// Output: 3

// Explanation: The substring is "ece" which its length is 3.





class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // Your code goes here
        int l =0;
        int r=0;
        unordered_map<char,int>m;
        int ans = 0;
        while(r<s.length()){
            m[s[r]]++;
            while(m.size()>2){
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }

};