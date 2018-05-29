class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res="1"
        if n<=0:
            return res 
        
        for _ in range(n-1):
            tmp, prev, count = '','0',0
            
            for ch in res:
                if prev=='0' or ch==prev:
                    count+=1
                else:
                    tmp += str(count)+prev
                    count = 1
                prev = ch
                
            tmp += str(count)+prev
            res = tmp
        return res