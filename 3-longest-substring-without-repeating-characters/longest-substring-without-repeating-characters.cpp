class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // i and j init
        // maxl=0
        // loop i<j
        // update in unordered_map
        // if map[s[j]]>1
        // while map[s[j]]!=1
        // i++ and map[s[i]]--;
        // end loop
        // else
        // increment unordered_map and maxl=max(maxl,r-l+1)
        // end if
        // j++
        // end loop
        int i=0,j=0;
        int maxl=0;
        unordered_map<char,int> cnt;
        while(i<=j && j<s.size() && i<s.size()){
            cnt[s[j]]++;
            if(cnt[s[j]]>1){
                while(cnt[s[j]]!=1 && i<s.size() && i<=j){
                    cnt[s[i]]--;
                    i++;
                }
            }
            maxl=max(maxl,j-i+1);
            j++;
        }
        return maxl;
    }
};