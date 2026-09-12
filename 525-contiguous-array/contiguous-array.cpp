class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0,one=0;
        int res=0;
        unordered_map<int,int> hm;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }else{
                one++;
            }
            if(hm.find(one-zero)==hm.end()){
                hm[one-zero]=i;
            }
            if(one==zero){
                res=one+zero;
            }else{
                int idx=hm[one-zero];
                res=max(res,i-idx);
            }
        }
        return res;
        
    }
};