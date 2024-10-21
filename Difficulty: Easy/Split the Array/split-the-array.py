#User function Template for python3
class Solution:
	def countgroup(self,arr): 
		#Complete the function
		xr = 0
		for x in arr:
		    xr ^= x
		return (1 << (len(arr)-1))-1 if xr == 0 else 0



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.countgroup(arr)
        print(res)
        t -= 1

# } Driver Code Ends