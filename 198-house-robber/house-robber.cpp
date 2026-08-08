class Solution {
public:
    int solve(vector<int>& nums,int sum,int i,vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            cout<<i<<" "<<dp[i]<<endl;
            return dp[i];
        }
        int incl=nums[i]+solve(nums,sum+nums[i],i+2,dp);
        int excl=solve(nums,sum,i+1,dp);
        return dp[i]=max(incl,excl);
    }
    int rob(vector<int>& nums) {
        int sum=0;
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,sum,dp);
    }
};