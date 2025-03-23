char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    char *output = (char *)calloc(sizeof(char), 201);
    char current;
    while (i<201){
        if (strlen(strs[0]) <= i) return output;
        current = strs[0][i];
        for (int j=1; j<strsSize;j++){
            if (strlen(strs[j]) <= i) return output;
            if (current != strs[j][i]) return output;
        }
        output[i] = current;
        i++;
    }
    return output;
}