class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, unordered_map<char, int>> hm;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {

            unordered_map<char, int> freq;

            for (char c : strs[i]) {
                freq[c]++;
            }

            bool flag = false;

            for (auto &p : hm) {
                if (p.second == freq) {
                    ans[p.first].push_back(strs[i]);
                    flag = true;
                    break;
                }
            }

            if (flag == false) {
                int idx = hm.size();

                hm[idx] = freq;
                ans.push_back({strs[i]});
            }
        }

        return ans;
    }
};