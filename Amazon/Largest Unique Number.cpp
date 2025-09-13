// Given an array of integers nums, return the largest integer that appears exactly once. If no integer occurs exactly once, return -1.

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        // Your code goes here
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i: m){
            q.push({i.first,i.second});
        }
        while(!q.empty() && m[q.top().first]>1){
            q.pop();
        }
        return !q.empty()?q.top().first:-1;
    }
};