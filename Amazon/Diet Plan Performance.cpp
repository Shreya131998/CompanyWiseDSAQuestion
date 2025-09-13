A dieter tracks their calorie intake over several days, represented as an array calories[i].



// Given an integer k, for each consecutive sequence of k days (calories[i], calories[i+1], ..., calories[i+k-1] for all 0 <= i <= n-k), they calculate T, the total calories consumed in that sequence:

// If T < lower, they performed poorly and lose 1 point.
// If T > upper, they performed well and gain 1 point.
// Otherwise, they performed normally, and no points are gained or lost.


// Initially, the dieter has zero points. Return the total number of points the dieter has after calories.length days.



// The total points can be negative.


class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        // Your code goes here
        int sum =0;
        for(int i=0;i<k;i++){
            sum+=calories[i];
        }
        int ans =0;
        if(sum<lower){
            ans+=-1;
        }
        else if(sum>upper){
            ans+=1;
        }
        int j =0;
        for(int i=k;i<calories.size();i++){
            sum+=calories[i];
            sum-=calories[j++];
            if(sum<lower){
                ans+=-1;
            }
            else if(sum>upper){
                ans+=1;
            }
        }
        return ans;
    }
};
