// You are provided a positive integer k and an integer array nums that is 0-indexed.



// An index is referred to as i k-big if the following criteria are met:



// At least k distinct indices of idx1 exist such that nums[idx1] < nums[i] and idx1 < i.
// At least k distinct indices of idx2 exist such that nums[idx2] < nums[i] and idx2 > i.


// Give back how many k-big indices there are.

class Solution {
    public:
        int kBigIndices(vector<int>& nums, int k) {
            //your code goes here
            int n = nums.size();
            priority_queue<int>left;
            priority_queue<int>right;
            vector<bool> leftGood(n, false);
            for(int i=0;i<k;i++){
                left.push(nums[i]);
                right.push(nums[n-i-1]);
            }
            for(int i=k;i<n-k;i++){
                if(nums[i]>left.top()){
                    leftGood[i] = true;
                }
                else{
                    left.pop();
                    left.push(nums[i]);
                }
            }
            int c=0;
            for(int i=n-k-1;i>=k;i--){
                if(nums[i]> right.top() && leftGood[i]){
                    c++;
                }
                else{
                    right.pop();
                    right.push(nums[i]);
                }
            }
            return c;
        }
};