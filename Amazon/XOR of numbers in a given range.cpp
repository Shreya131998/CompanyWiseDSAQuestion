class Solution{	
	public:
        int getXor(int x){
            if(x%4==1)return 1;
            else if(x%4==2)return x+1;
            else if(x%4==3) return 0;
            else return x;
        }
		int findRangeXOR(int l,int r){
			//your code goes here
            return getXor(r) ^ getXor(l-1);
		}
};