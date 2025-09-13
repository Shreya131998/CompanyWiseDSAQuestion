// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.



// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.



// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

class Solution {
public:
    int solve(vector<int>& heights, int k, int i,vector<int>&dp){
        // if(i>=heights.size()-1)return heights;
        if(dp[i]!=INT_MAX){
            return dp[i];
        }
        int ans= INT_MAX;
        for(int j=i+1;j<=i+k;j++){
            if(j<heights.size()-1){
                ans = min(ans, abs(heights[i]-heights[j])+solve(heights,k,j,dp));
            }
            else if(j==heights.size()-1){
                ans = min(ans, abs(heights[i]-heights[j]));
            }
        }
        return dp[i]= ans;
    }
    int frogJump(vector<int>& heights, int k) {
        if(heights.size()==1)return 0;
        vector<int>dp(heights.size(),INT_MAX);
        int ans =solve(heights,k,0,dp);
        return ans ==INT_MAX? 0: ans;
    }
};
