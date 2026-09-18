class Solution {
public:
    void solve(int i,int n,int cl,string str,vector<string> &ans){
        if(i>n){
            if(cl!=n){    
                while(cl!=n){
                    str+=")";
                    cl++;
                }
            }
            ans.push_back(str);
            return;
        }
        if(cl==n && i<=n){
            return;
        }
        if(cl>i-1){
            return;
        }
        // include
        solve(i+1,n,cl,str+"(",ans);
        // exclude
        solve(i,n,cl+1,str+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        int i=1,cl=0;
        string str="(";
        vector<string> ans;
        solve(i+1,n,cl,str,ans);
        return ans;
    }
};