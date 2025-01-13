#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) 
{
    FILE *inputfile,*outputfile;//ファイル宣言
    double left, right;  //左右の項を格納
    char operator; //演算子を格納

    //インプットファイルを開く
    inputfile = fopen("input.txt","r");
    if(inputfile == NULL)
    {
        printf("ファイルが見つかりません\n");
        return 1;
    }
    //アウトプットファイルを開きます
    outputfile = fopen ("output.txt","w");
    if (outputfile ==NULL)
    {
        printf("ファイルを出力できません\n");
        fclose(inputfile);
        return 1;
    }
    
    // 文字列の解析
    while((fscanf(inputfile,"%lf %c %lf",&left,&operator,&right) == 3))
    {   
        switch(operator)  // 演算子の識別と計算結果の出力
        {
            case '+':
                fprintf(outputfile,"%.2f\n", left + right);
                break;
            case     '-':
                fprintf(outputfile,"%.2f\n", left - right);
                break;
            case '*':
                fprintf(outputfile,"%.2f\n", left * right);
                break;
            case '/':
                if(right != 0) 
                {
                    fprintf(outputfile,"%.2f\n", left / right);
                } 
                else
                {
                    printf("0以外で割ってください\n");
                }
                break;
            case '%':
            if (fmod(left,1)==0 && fmod(right,1)==0)
                {
                    fprintf(outputfile,"%d\n",(int)left % (int)right);
                }
            else
            {
                printf("整数を入力してください\n");
            }
                break;
            default:
                printf("演算子を入力してください(+, -, *, /).\n");
                break;
            
        }
    }

    printf ("計算が終了しました計算結果はoutput.txtに保存されています\n");
    fclose(inputfile);
    fclose(outputfile);
    return 0; // 正常終了
} 