class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<vector<int>>ans;
        int n = nums.size();
        int x = pow(2,n);
        for(int i=0;i<x;i++){
            vector<int>v;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};