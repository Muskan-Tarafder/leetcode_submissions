class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int zpoint=0,numpoint=0;
        // while(zpoint<nums.size()){
        //     while(zpoint<nums.size() && nums[zpoint]!=0 ){
        //         zpoint++;
        //     }
        //     numpoint=zpoint;
        //     while(numpoint<nums.size() && nums[numpoint]==0 ){
        //         numpoint++;
        //     }
        //     if(zpoint<nums.size() && numpoint<nums.size()){
        //         int temp=nums[zpoint];
        //         nums[zpoint]=nums[numpoint];
        //         nums[numpoint]=temp;
        //     }
        //     zpoint++;
        // }

        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]!=0 && j<nums.size()){
                nums[i++]=nums[j++];
            }else{
                j++;
            }

        }
        while(i<nums.size()){
            nums[i++]=0;
        }
    }
};