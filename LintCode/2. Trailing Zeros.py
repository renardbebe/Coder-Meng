class Solution:
    """
    @param: n: An integer
    @return: An integer, denote the number of trailing zeros in n! (n/5+n/5/5+....n/5/5../5)
    """
    def trailingZeros(self, n):
        # write your code here, try to do it without arithmetic operators.
        cnt = 0
        while (n) :
            cnt += int(n/5)
            n /= 5
        return cnt