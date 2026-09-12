class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int prev=-1;
        int max_l=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(prev==-1 || nums[prev]+1==nums[i]){
                cnt++;
                max_l=max(max_l,cnt);
            }else{
                cnt=1;
            }
            prev=i;
        }
        return max_l;
    }
};