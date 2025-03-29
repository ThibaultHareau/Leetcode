int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int i=2;
    int previous[2] = {1, 2};
    int ways;
    while (i<n) {
        ways = previous[0]+previous[1];
        previous[0] = previous[1];
        previous[1] = ways;
        i++;
    }
    return ways;

}