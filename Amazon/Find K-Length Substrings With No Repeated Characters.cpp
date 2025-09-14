// You are given a string s and an integer k. You need to find all the substrings of length k that do not contain any repeated characters. Return the count of all such substrings.

class Solution {
public:
    int solve(string s, int k){
        int l=0;
        int r=0;
        int ans =0;
        unordered_map<char,int>m;
        while(r<s.length()){
            m[s[r]]++;
            while(m[s[r]]>1){
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
            if(r-l+1 == k){
                ans++;
                // slide forward by removing left
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            // ans++;
            r++;
        }
        return ans;
    }
    int numKLenSubstrNoRepeats(string s, int k) {
        //Your Code Goes Here
        return solve(s,k);
    }
};