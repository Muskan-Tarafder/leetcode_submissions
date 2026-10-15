class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        int cnt=1;
        while(i<nums.size() && j<nums.size()){
            int curr=nums[i];
            while(j<nums.size() && nums[j]==curr){
                j++;
            }
            if(i<nums.size()-1 && j<nums.size()){
                i++;
                nums[i]=nums[j];
                cnt++;
            }
        }
        return cnt;
    }
};