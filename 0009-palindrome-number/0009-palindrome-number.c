bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    int numlen;
    if (x < 2147483647) {
        numlen = (int)(ceil(log10(x+1)));
    }
    else {
        numlen = (int)(ceil(log10(x)));
    }
    char str[numlen + 1];
    sprintf(str, "%d", x);
    for (int i=0;i<(numlen/2);i++){
        if (str[i] != str[numlen-i-1]) return false;
    }
    return true;
}