int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if ((dividend == INT_MIN) && (divisor == -1)) return INT_MAX;
    if (divisor == INT_MIN) return 0;
    int sign = 1;
    unsigned int quotient = 0;
    if (dividend == INT_MIN){
        dividend += abs(divisor);
        quotient ++;
    }
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
    
    unsigned int dividend_abs = abs(dividend), divisor_abs = abs(divisor);

    int power_two;
    while (dividend_abs >= divisor_abs){
        power_two = 0;
        while (dividend_abs > (divisor_abs) << (power_two + 1)){
            power_two ++;
        }
        dividend_abs -= divisor_abs << power_two;
        quotient += 1 << power_two;
    }
    return quotient * sign;
}