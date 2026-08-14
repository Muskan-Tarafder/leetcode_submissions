class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int rot=k%n;
        // vector<int> temp(n);
        // for(int i=0;i<n;i++){
        //     temp[(i+k)%n]=nums[i];
        // }
        // nums=temp;
        reverse(nums.begin(),nums.begin()+(n-rot));
        reverse(nums.begin()+(n-rot),nums.end());
        reverse(nums.begin(),nums.end());
    }
};