class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>0){
            if(nums[i]>nums[i-1]){
                break;
            }
            i--;
        }
        if(i>0){
            i--;
            sort(nums.begin()+i+1,nums.end());
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    int temp=nums[j];
                    nums[j]=nums[i];
                    nums[i]=temp;
                    break;
                }
            }
            
        }else{
            sort(nums.begin(),nums.end());
        }
    }
};