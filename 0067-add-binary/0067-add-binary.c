char* addBinary(char* a, char* b) {
    int i = strlen(a)-1;
    int j = strlen(b)-1;
    int sum,carry =0,k=0;
    int len = (i>j ? i : j)+1;
    char* result = malloc(len+2);
    while(i>=0 || j>=0 || carry){
        sum = carry;
        if(i>=0){
            sum+=a[i]-'0';
            i--;
        }
        if(j>=0){
            sum+=b[j]-'0';
            j--;
        }
        result[k++] = (sum%2) + '0';
        carry = sum/2;
    }
    result[k]='\0';
        int rig = k-1;
        int lef = 0;
        while(lef<rig){
            char temp = result[lef];
            result[lef++]=result[rig];
            result[rig--]=temp;
        }
        return result;
}