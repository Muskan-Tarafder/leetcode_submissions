class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        maxi=0
        prev=0
        for i in range(1,len(nums)):
            if(nums[i-1]>=nums[i]):
                maxi=max(maxi,i-prev)
                prev=i
        if(prev!=len(nums)-1):
            maxi=max(maxi,len(nums)-prev)
        if(maxi==0):
            maxi=len(nums)
        return maxi