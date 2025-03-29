int lengthOfLastWord(char* s) {
    int length = 0;
    bool newWord;
    int i = 0;
    while (s[i] != NULL){
        if (s[i] != ' ') {
            if (newWord) {
                length = 1;
                newWord = false;
            }
            else length++;
        }
        else newWord = true;
        i++;
    }
    return length;
}