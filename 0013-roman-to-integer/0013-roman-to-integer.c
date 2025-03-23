int romanToInt(char* s) {
    int result = 0;
    char previous;
    for (int i=0; i<strlen(s); i++){
        if (i>0){
            if ((previous == 'I' && s[i] == 'V') || (previous == 'I' && s[i] == 'X')) result -= 2;
            else if ((previous == 'X' && s[i] == 'L') || (previous == 'X' && s[i] == 'C')) result -= 20;
            else if ((previous == 'C' && s[i] == 'D') || (previous == 'C' && s[i] == 'M')) result -= 200;
        }
        switch(s[i])
        {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
        }
        previous = s[i];
    }
    return result;
}