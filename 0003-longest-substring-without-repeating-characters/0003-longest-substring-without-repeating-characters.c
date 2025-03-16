int lengthOfLongestSubstring(char* s) {
    int *ascii = (int *)calloc(sizeof(int), 128);
    for (int i=0;i<128;i++) {ascii[i]=-1;}
    if (strlen(s) == 0) return 0;
    int maxlen = 1;
    bool exited;
    for (int i=0;i<strlen(s)-1;i++){
        if (maxlen + i > strlen(s)) return maxlen;
        ascii[s[i]] = i;
        exited = false;
        for (int j=i+1;j<strlen(s);j++){
            if (ascii[s[j]] < j && ascii[s[j]] > -1){
                exited = true;
                if (maxlen < j-i){
                    maxlen = j-i;
                }
                break;
            }
            ascii[s[j]] = j%128;
            if (s[j] == 121){
            }
        }
        if (!exited){
            return strlen(s) - i ;
        }
        ascii[s[i]] = -1;
        if (s[i] == 121){
        }
    }
    free(ascii);
    return maxlen;
}