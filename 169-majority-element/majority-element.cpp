class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int> cnt;
        // int n=-1;
        // for(int i=0;i<nums.size();i++){
        //     cnt[nums[i]]++;
        //     if(cnt[nums[i]]>nums.size()/2){
        //         n= nums[i];
        //         break;
        //     }
        // }
        // return n;
        int cnt=1,val=nums[0];
        sort(nums.begin(),nums.end());
        int half=nums.size()/2;
        for(int i=1;i<nums.size();i++){
            cout<<nums[i-1]<<" "<<nums[i]<<endl;
            if(nums[i-1]==nums[i]){
                cnt++;
            }
            else{
                cnt=1;
            }
            cout<<cnt<<endl;
            if(cnt>half){
                val=nums[i-1];
                break;
            }
            
        }
        return val;
    }
};