class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<pair<int, int>> hm;
        for(int i=0;i<n;i++){
            hm.push_back({i, abs(arr[i] - x)});
        }
        sort(hm.begin(),hm.end(),[&](const auto& a,const auto& b){
            if (a.second == b.second)
                return arr[a.first] < arr[b.first];
            return a.second<b.second;
        });
        vector<int> ans;
        for(auto &a:hm){
            if(k){
                ans.push_back(arr[a.first]);
                k--;
            }else{
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};