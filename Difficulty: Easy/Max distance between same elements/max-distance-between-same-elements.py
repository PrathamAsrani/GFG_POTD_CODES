class Solution:
    # Your task is to Complete this function
    # functtion should return an integer
    def maxDistance(self, arr):
        # Code here
        mp = {}
        ans = 0
        for i in range(len(arr)):
            num = arr[i]
            if mp.get(num) is not None:
                ans = max(ans, i - mp.get(num))
            else:
                mp[num] = i
        return ans



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.maxDistance(arr))

# } Driver Code Ends