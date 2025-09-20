class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        //Your code goes here
        int x = start ^ goal;
        int c=0;
        while(x){
            if(x&1){
                c++;
            }
            x = x>>1;
        }
        return c;
    }
};