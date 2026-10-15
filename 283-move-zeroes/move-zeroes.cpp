class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zpoint=0,numpoint=0;
        while(zpoint<nums.size()){
            while(zpoint<nums.size() && nums[zpoint]!=0 ){
                zpoint++;
            }
            numpoint=zpoint;
            while(numpoint<nums.size() && nums[numpoint]==0 ){
                numpoint++;
            }
            if(zpoint<nums.size() && numpoint<nums.size()){
                int temp=nums[zpoint];
                nums[zpoint]=nums[numpoint];
                nums[numpoint]=temp;
            }
            zpoint++;
        }
    }
};