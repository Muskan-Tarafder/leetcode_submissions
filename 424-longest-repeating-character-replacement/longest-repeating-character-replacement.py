class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l=r=ml=mf=0
        hm=[0 for i in range(26)]
        while(r<len(s)):
            hm[ord(s[r]) - ord('A')] += 1
            mf=max(mf,hm[ord(s[r]) - ord('A')])
            if (r-l+1)-mf>k:
                hm[ord(s[l]) - ord('A')]-=1
                l+=1
            ml=max(ml,r-l+1)
            r+=1
        return ml