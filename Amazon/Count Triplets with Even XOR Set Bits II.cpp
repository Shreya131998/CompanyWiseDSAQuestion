// Given three integer arrays a, b, and c, find the number of valid triplets (a[i], b[j], c[k]), where: (0 ≤ i < a.length, 0 ≤ j < b.length, 0 ≤ k < c.length).



// A triplet is considered valid if the bitwise XOR of its elements has an even number of set bits (bits with value 1).



// Return the total count of such triplets.


class Solution {
public:
    int setbits(int x){
        int c=0;
        while(x){
            if(x&1)c++;
            x = x>>1;
        }
        return c;
    }

    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c){
       long long evenA=0,oddA=0,evenB=0,oddB=0,evenC=0,oddC=0;
       for(int i=0;i<a.size();i++){
            int x = setbits(a[i]);
            if(x%2==0){
                evenA++;
            }
            else{
                oddA++;
            }
       }
       for(int i=0;i<b.size();i++){
            int x = setbits(b[i]);
            if(x%2==0){
                evenB++;
            }
            else{
                oddB++;
            }
       }
       for(int i=0;i<c.size();i++){
            int x = setbits(c[i]);
            if(x%2==0){
                evenC++;
            }
            else{
                oddC++;
            }
       }
       long long ans =0;
       ans+= evenA*evenB*evenC;
        ans+= oddA*oddB*evenC;
        ans+= oddA*oddC*evenB;
        ans+= evenA*oddB*oddC;
        return ans;
    }
};

