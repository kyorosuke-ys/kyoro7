#include <stdio.h>

int main(void) {
    double left, right;  //左右の項を格納
    char operator; //演算子を格納
    char input[256];  // 入力された文字列

    printf("Enter a calculation (e.g., 3 + 4)\n");
    // 文字列の格納
    fgets(input, sizeof(input), stdin);
    // 文字列の解析
    if(sscanf(input,"%lf %c %lf",&left,&operator,&right) != 3) {
        printf("Invalid input format. Please use the format: integer operator integer.\n");
        return 1; // 失敗
    }

    // 演算子の識別と計算結果の出力
    switch(operator) {
        case '+':
            printf("ans = %.2f\n", left + right);
            break;
        case '-':
            printf("ans = %.2f\n", left - right);
            break;
        case '*':
            printf("ans = %.2f\n", left * right);
            break;
        case '/':
            if(right != 0) 
            {
            printf("ans = %.2f\n", left / right);
            break;
            } 
            else
            {
            printf("0以外で割ってください\n");
            break;
            }
        default:
            printf("演算子を入力してください(+, -, *, /).\n");
            return 1;
    }

    return 0; // 正常終了
} 