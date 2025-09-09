// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.


// Examples:
// Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 

// Output: 5

// Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

class Solution{
public:
    int isValid(vector<vector<int>>&matrix, int mid){
        int sum =0;
        for(int i=0;i<matrix.size();i++){
            vector<int>v = matrix[i];
            int s=0;
            int e = v.size()-1;
            int ans =-1;
            while(s<=e){
                int m = s+(e-s)/2;
                if(v[m]<=mid){
                    ans = m;
                    s = m+1;
                }
                else{
                    e = m-1;
                }
            }
            ans = ans+1;
            sum+=ans;
        }
        return sum;
    }
    int findMedian(vector<vector<int>>&matrix) {
        int s=INT_MAX;
        int e = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        int total = (n*m+1)/2;
        for(int i=0;i<n;i++){
            s = min(s,matrix[i][0]);
            e = max(e,matrix[i][m-1]);
        }
        
        int ans =-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isValid(matrix,mid)>=total){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;

    }
};