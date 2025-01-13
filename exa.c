#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//構造体の準備
typedef struct
{
    char question[150];
    char answer[50];
} quiz;

//問題集
quiz variation[]=
{
    {"question1","ans1"},
    {"question2","ans2"},
    {"question3","ans3"},
    {"question4","ans4"},
    {"question5","ans5"}
};

//答え合わせの関数
void check (int a, char useranswer[])
{
    // デバッグ
    printf("variation[a].answer is %s\n", variation[a].answer);
    printf("your input is %s\n", useranswer);

    if(strcmp(useranswer,variation[a].answer) == 0)
    {
        printf ("ok\n");
    } else  
    {
        printf ("ng\n");
    }
}

void printCharWithCodes(char str[], int length)
{
    for (int i = 0; i < length; i++) {
        // 文字とその文字コードを表示
        printf("Character: '%c', ASCII Code: %d\n", str[i], (unsigned char)str[i]);
    }
}

// 配列の残りの部分を '\0' にする関数
void clear_remaining(char *string, int size) {
    int length = strlen(string);
    for (int i = length; i < size; i++) {
        string[i] = '\0';
    }
}

//問題表示とユーザー入力
int main (void)
{
    int a;
    char useranswer[50];
    srand ( (unsigned)time(NULL) );
    a = rand () % 5;
    //問題を表示
    printf ( "%s\n" ,variation[a].question);
    //入力
    fgets(useranswer,sizeof(useranswer),stdin);

    // デバッグ:答えの文字表示
    printf("\n--- anser ---\n");
    printCharWithCodes(variation[a].answer, 50);

    // デバッグ:入力の確認
    printf("\n--- input ---\n");
    // 1文字ずつ確認
    printCharWithCodes(useranswer, 50);

    // 改行コードを終端文字に変換
    useranswer[strcspn(useranswer, "\n")] = 0;

    // デバッグ: 入力の確認
    printf("\n--- input ---\n");
    // 1文字ずつ確認
    printCharWithCodes(useranswer, 50);

    //clear_remaining(useranswer, 50);
    // 1文字ずつ確認
    //printCharWithCodes(useranswer, 50);

    //関数で答え合わせ
    check (a,useranswer);
    return 0;
}