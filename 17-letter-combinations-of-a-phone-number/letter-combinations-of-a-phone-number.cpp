class Solution {
public:
    void solve(string digits,vector<string> &ans,int i,int n,string str,unordered_map<char,string> &mapping){
         if(i == n){
            ans.push_back(str);
            return;
        }

        string word = mapping[digits[i]];

        for(int j = 0; j < word.size(); j++){
            str.push_back(word[j]);
            solve(digits, ans, i + 1, n, str, mapping);
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mapping;
        mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        int n=digits.size();
        vector<string> ans;
        string str="";
        solve(digits,ans,0,n,str,mapping);
        return ans;
   }
};