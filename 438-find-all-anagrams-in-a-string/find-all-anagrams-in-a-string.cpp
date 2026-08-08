class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()){
            return {};
        }
        vector<int> p_freq(26,0);
        vector<int> s_freq(26,0);
        for(int i=0;i<p.size();i++){
            p_freq[p[i]-'a']++;
            s_freq[s[i]-'a']++;
        }
        int i=0,j=p.size()-1;
        vector<int> ans;
        while(i<=j && j<s.size()){
            if(p_freq==s_freq){
                ans.push_back(i);
            }
            s_freq[s[i]-'a']--;
            i++;
            j++;
            if(j<s.size()) s_freq[s[j]-'a']++;
        }
        return ans;
    }
};