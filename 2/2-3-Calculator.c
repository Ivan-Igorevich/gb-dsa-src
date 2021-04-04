#include <stdio.h>

void calculator() {
    float num1;
    float num2;
    char sign;
    float result;
    printf("%s", "Enter first number: ");
    scanf("%f", &num1);
    printf("%s", "Enter operator: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%c", &sign);
    if (sign == '/') {
        do {
            printf("%s", "Enter second number: ");
            scanf("%f", &num2);
        } while (num2 == 0);
    } else {
        printf("%s", "Enter second number: ");
        scanf("%f", &num2);
    }
    switch(sign) {
        case '+':
            result = num1 + num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '-':
            result = num1 - num2;
            break;
    }
    printf("Result is: %f \n", result);
}
