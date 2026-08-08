class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        int i=0,j=1;
        // while(i<j and j<n){
        //     while(j<n && temperatures[i]>=temperatures[j]){
        //         j++;
        //     }
        //     if(j<n) ans[i]=j-i;
        //     i++;
        //     j=i+1;
        // }
        stack<int> s;
        // s.push(n-1);
        // vector<int> idx(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()) {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }
        // for(int i=0;i<n;i++){
        //     ans[i]=idx[i]-i;
        // }
        return ans;
    }
};