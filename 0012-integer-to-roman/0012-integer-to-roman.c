char* intToRoman(int num) {
    int index = 0;
    char *roman = (char *)calloc(sizeof(char), 16);
    while (num >= 1000){
        roman[index] = 'M';
        num -= 1000;
        index ++;
    }
    if (num >= 900){
        roman[index] = 'C';
        index ++;
        roman[index] = 'M';
        index ++;
        num -= 900;
    }
    if (num >= 500){
        roman[index] = 'D';
        index ++;
        num -= 500;
    }
    if (num >= 400){
        roman[index] = 'C';
        index ++;
        roman[index] = 'D';
        index ++;
        num -= 400;
    }
    while (num >= 100){
        roman[index] = 'C';
        index ++;
        num -= 100;
    }
    if (num >= 90){
        roman[index] = 'X';
        index ++;
        roman[index] = 'C';
        index ++;
        num -= 90;
    }
    if (num >= 50){
        roman[index] = 'L';
        index ++;
        num -= 50;
    }
    if (num >= 40){
        roman[index] = 'X';
        index ++;
        roman[index] = 'L';
        index ++;
        num -= 40;
    }
    while (num >= 10){
        roman[index] = 'X';
        index ++;
        num -= 10;
    }
    if (num >= 9){
        roman[index] = 'I';
        index ++;
        roman[index] = 'X';
        index ++;
        num -= 9;
    }
    if (num >= 5){
        roman[index] = 'V';
        index ++;
        num -= 5;
    }
    if (num >= 4){
        roman[index] = 'I';
        index ++;
        roman[index] = 'V';
        index ++;
        num -= 4;
    }
    while (num >= 1){
        roman[index] = 'I';
        index ++;
        num -= 1;
    }
    return roman;
}