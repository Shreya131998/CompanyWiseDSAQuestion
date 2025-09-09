// Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j].A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.



// Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.



// Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s =0;
        int e = mat[0].size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int maxRow = 0;
            for(int i=1;i<mat.size();i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow =i;
                }
            }
            int left = mid-1>=0 ? mat[maxRow][mid-1] : -1;
            int right = mid+1< mat[0].size() ? mat[maxRow][mid+1] : -1;
            if(mat[maxRow][mid]>left && mat[maxRow][mid]>right){
                return {maxRow,mid};
            }
            else if(mat[maxRow][mid]<left){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return {-1,-1};
    }
};