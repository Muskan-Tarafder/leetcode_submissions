class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int n=-1;
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]]>nums.size()/2){
                n= nums[i];
                break;
            }
        }
        return n;
    }
};