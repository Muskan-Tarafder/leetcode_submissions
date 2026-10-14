class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;

        for(int i=0;i<s.size();i++){
            s_map[s[i]]+=1;
            t_map[t[i]]++;
        }
        for(auto const& [key, val] : s_map){
            if(!t_map.contains(key) || t_map[key] != val){
                return false;
            }
        }
        return true;
    }
};