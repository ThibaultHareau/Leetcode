bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    double numlen;
    if (x != 2147483647) {
        numlen = (int)(ceil(log10(x+1)));
    }
    else {
        numlen = (int)(ceil(log10(x)));
    }
    for (double i=0;i<(numlen/2);i++){
        if ((x/((int) pow(10.,i)))%10 != (x/((int) pow(10.,numlen-i-1)))%10) return false;
    }
    return true;
}