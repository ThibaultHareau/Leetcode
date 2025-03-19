int reverse(int x){
    int result = 0;
    bool isnegative = x < 0;
    if (x == -2147483648) return 0;
    if (isnegative) x = -x;
    while (x >= 10){
        result = result * 10 + (x % 10);
        x = x / 10;
    }
    if (result > 214748364){
            return 0;
    }
    result = result * 10 + (x % 10);
    x = x / 10;
    if (isnegative) {
        return -result;
    }
    return result;
}