class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here
            int sum =0;
            for(int i=0;i<nums.size();i++){
                sum=sum^nums[i];
            }
            int rem = (sum & (sum-1))^sum;
            int b1=0;
            int b2=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&rem){
                    b1 = b1^nums[i];
                }
                else{
                    b2 = b2^nums[i];
                }
            }
            if(b1<b2) return {b1,b2};
            return {b2,b1};

		}
};