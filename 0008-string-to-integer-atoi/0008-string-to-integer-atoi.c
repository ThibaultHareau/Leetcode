int myAtoi(char* s) {
    int i = 0;
    int result = 0;
    bool isnegative = false;
    while (s[i] != "\0" && s[i] == ' '){
        i ++;
    }
    if (s[i] == '-') {
        isnegative = true;
        i ++;
    }
    else {
        if (s[i] == '+') i++;
    }
    while (s[i] != "\0" && s[i] >= '0' & s[i] <= '9'){
        if (result >= 214748364){
            if (result > 214748364){
                if (isnegative) return - 2147483648;
                return 2147483647;
            }
            if (isnegative && s[i] >= '8') return - 2147483648;
            if (!isnegative && s[i] >= '7') return  2147483647;
        }
        result = result * 10 + (s[i] - '0');
        i ++;
    }
    if (isnegative) return - result;
    return result;
}