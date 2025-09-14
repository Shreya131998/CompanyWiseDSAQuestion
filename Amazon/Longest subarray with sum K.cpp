// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<int,int>m;
        int sum =0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                maxi = max(maxi,i+1);
            }
            if(m.find(sum-k)!=m.end()){
                maxi = max(maxi,i-m[sum-k]);
            }
            if(m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        return maxi;
    }
};
