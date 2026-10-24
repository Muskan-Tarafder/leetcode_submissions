class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        lst=[]
        heapq.heapify(lst)
        prev=-999999
        for i in range(len(nums)):
            if  lst!=[] and nums[i]>lst[0] and k==0:
                heapq.heappop(lst)
                heapq.heappush(lst,nums[i])
            elif k!=0:
                heapq.heappush(lst,nums[i])
                k-=1
        return heapq.heappop(lst)


