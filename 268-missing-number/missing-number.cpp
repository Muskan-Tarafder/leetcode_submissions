class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // if(nums)
        sort(nums.begin(),nums.end());
        int val=-1;
        if(nums[0]==0){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+1!=nums[i+1]){
                    val=nums[i]+1;
                    break;
                }
            }
        }else{
            return 0;
        }
        if(val==-1){
            return nums.size();
        }
        return val;

    }
};