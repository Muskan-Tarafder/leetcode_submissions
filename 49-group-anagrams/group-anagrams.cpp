class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> grp_map;

        for(int i=0;i<strs.size();i++){
            vector<int> cnt(26,0);
            for(int j=0;j<strs[i].size();j++){
                cnt[strs[i][j]-'a']++;
            }
            grp_map[cnt].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto const&[key,val]:grp_map){
            ans.push_back(val);
        }
        return ans;
    }
};