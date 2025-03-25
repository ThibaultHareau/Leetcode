bool isValid(char* s) {
    int MAX_STACK_SIZE = 1+(strlen(s)/2);
    char *stack = (char *)malloc(sizeof(char)*MAX_STACK_SIZE);
    int top = 0;
    for (int i=0;i<strlen(s);i++){
        // If opening
        if (s[i] == '(' || s[i] == '['  || s[i] == '{' ){
            if (top >= MAX_STACK_SIZE) return false;
            stack[top] = s[i];
            top++;
        }
        // If closing
        else {
            if (top==0) return false;
            switch (s[i]){
                case ')':
                    if (stack[top-1] != '(') return false;
                    break;
                case '}':
                    if (stack[top-1] != '{') return false;
                    break;
                case ']':
                    if (stack[top-1] != '[') return false;
                    break;
            }
            top--;
        }
    }
    return top == 0;
}