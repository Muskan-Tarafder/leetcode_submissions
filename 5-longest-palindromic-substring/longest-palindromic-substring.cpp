class Solution {
public:
    string longestPalindrome(string s) {
        int i=0,n=s.size();
        int len=1;
        string str;
        while(i<n-1){
            for(int j=i+1;j<=i+2 && j<n;j++){
                int k=i;
                int m=j;
                if(s[k]==s[j]){
                    while(k>=0 && j<n && s[k]==s[m]){
                        k--;
                        m++;
                    }
                }
                int length = m-k-1;
                if(length>len){
                    len=length;
                    str=s.substr(k+1, m-k-1);
                }
            }
            i++;
        }
        if(len==1){
            return str=s[0];
        }
        return str;
    }
};