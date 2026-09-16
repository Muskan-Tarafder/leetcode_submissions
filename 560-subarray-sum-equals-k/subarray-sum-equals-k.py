class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # prefix = prefix + nums[i]

        # diff = prefix - 3

        # if diff exists in map:
        #     cnt += map[diff]

        # map[prefix] += 1
        prefix=[nums[0]]
        for i in range(1,len(nums)):
            prefix.append(prefix[-1]+nums[i])
        hm={0:1}
        cnt=0
        # print(prefix)
        for i in range(len(nums)):
            diff=prefix[i]-k
            if diff in hm:
                cnt+=hm[diff]
            hm[prefix[i]]=hm.get(prefix[i], 0) + 1

        return cnt
