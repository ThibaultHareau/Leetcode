int strStr(char* haystack, char* needle) {
    int index=0;
    int i;
    bool check;
    i = 0;
    while (needle[i] != NULL){
        if (haystack[index+i] == NULL) return -1;
        if (haystack[index+i] != needle[i]){
            i = 0;
            index++;
        }
        else i++;
    }
    return index;
    
}