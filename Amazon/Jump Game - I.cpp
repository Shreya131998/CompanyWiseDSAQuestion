// Given an array of integers nums, each element in the array represents the maximum jump length at that position. Initially starting at the first index of the array, determine if it is possible to reach the last index. Return true if the last index can be reached, otherwise return false.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //your code goes here
        int maxi =0;
        for(int i=0;i<nums.size();i++){
            if(maxi<i){
                return false;
            }
            maxi = max(maxi,i+nums[i]);
        }
        return true;
    }
};