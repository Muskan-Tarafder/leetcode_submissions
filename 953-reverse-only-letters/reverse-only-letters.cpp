class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j && j>0 && i<s.size()){
            if(!isalpha(s[i])){
                i++;
            }
            if(!isalpha(s[j])){
                j--;
            }
            if(i>=0 && j<s.size() && isalpha(s[i]) && isalpha(s[j])){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            

        }
        return s;
    }
};