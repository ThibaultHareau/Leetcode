int strStr(char* haystack, char* needle) {
    int index=0;
    int i;
    bool check;
    while(haystack[index] != NULL){
        i = 0;
        check = true;
        while (needle[i] != NULL){
            if (haystack[index+i] == NULL) return -1;
            if (haystack[index+i] != needle[i]){
                check = false;
                break;
            }
            i++;
        }
        if (check) return index;
        index++;
    }
    return -1;
    
}