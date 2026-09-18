class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l,r=0,0
        mf,ml=0,0
        hm={}
        while(r<len(s)):
            hm[s[r]]=hm.get(s[r],0)+1
            mf=max(mf,hm[s[r]])
            if(r-l+1)-mf>k:
                hm[s[l]]-=1
                l+=1
            ml=max(ml,r-l+1)
            r+=1
        return ml