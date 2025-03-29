int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int i=2;
    int prev2 = 1;
    int prev1 = 2;
    int ways;
    while (i<n) {
        ways = prev2+prev1;
        prev2 = prev1;
        prev1 = ways;
        i++;
    }
    return ways;

}