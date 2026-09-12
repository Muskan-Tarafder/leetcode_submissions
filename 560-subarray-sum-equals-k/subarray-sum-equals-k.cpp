class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum_;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                cnt++;
            }
            cout<<"sum:"<<sum<<endl;
            sum_.push_back(sum);
            

        }
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {

                if(sum_[j] - sum_[i] == k) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};