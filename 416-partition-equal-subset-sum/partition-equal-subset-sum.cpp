class Solution {
public:
    bool solve(vector<int>& nums,int i,int l,int sum,vector<vector<int>> &dp){
        if(l==sum/2){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if(dp[i][l]!=-1){
            return dp[i][l];
        }
        bool inc=solve(nums,i+1,l+nums[i],sum,dp);
        bool excl=solve(nums,i+1,l,sum,dp);
        return dp[i][l]=inc||excl;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int> (sum+1,-1));
        return solve(nums,0,0,sum,dp);
    }
};