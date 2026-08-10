class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int mini=nums[0];
        int i=1,ans=nums[0];
        while(i<nums.size()){
            if(nums[i]<0){
                swap(maxi,mini);
            }
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
            ans=max(ans,maxi);
            i++;
        }
        return ans;
    }
};