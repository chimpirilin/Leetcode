# https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/
class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        ans, p = 0, 1
        while sum(list(map(int,str(n)))) > target:
            ans, n, p = ans+(10-((n//p)%10))*p, n+(10-((n//p)%10))*p, p*10
        return ans
