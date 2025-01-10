#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//構造体の準備
typedef struct
{
    char question[256];
    char answer[50];
}quiz;
//問題集
quiz variation[]=
{
    {"危機的な状況から一挙に盛り返すことを、死にかかった人を生き返らせることを四字熟語でなんというか"
    ,"起死回生"},
    {"孔子の「論語」に由来する昔のことを研究して新しい学びを得るという意味の四字熟語","温故知新"},
    {"良くライバル関係を指して使われる、相手と競いながら成長することを意味する四字熟語","切磋琢磨"},
    {"どらえもんに登場する「しずかちゃん」の名字は？","源"},
    {"日本の県庁所在地で唯一ひらがなが使われているのは何県でしょう？","埼玉県"}
};
//答え合わせの関数
void check (int a, char useranswer[])
{
    if(strcmp(useranswer,variation[a].answer) == 0)
    {
        printf ("大正解\n");
    } else  
    {
        printf ("不正解\n");
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
    printf ("問題：%s(漢字で答えよ)\n" ,variation[a].question);
    //入力
    fgets(useranswer,sizeof(useranswer),stdin);
    useranswer[strcspn(useranswer, "\n")] = 0;
    //関数で答え合わせ
    check (a,useranswer);
    return 0;
}