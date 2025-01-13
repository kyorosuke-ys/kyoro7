/*=== rpg: ソースコードひな形 ===*/
/*** インクルード宣言 ***/

#include <stdio.h>

/*** 列挙型宣言 ***/

/*** グローバル定数の宣言 ***/

/*** 構造体型宣言 ***/
typedef struct
{
    char name[10];
    int hp;
    int attack;
    int defense;

}friend;

typedef struct
{
    char bossname[10];
    int hp;
    int attack;
    int defense;
}Boss;
//仲間一覧一覧
friend taka= {"taka",150,20,40};
friend toshi= {"tohsi",200,10,30};
friend daigo= {"daigo",100,70,30};
friend nobu= {"nobu",150,30,30};
//敵一覧
Boss sanma= {"sanma",170,60,60};
Boss takeshi= {"takeshi",120,50,25};
Boss ariyoshi= {"ariyoshi",150,20,20};

/*** プロトタイプ宣言 ***/
int match(int wincount);
int battle(int wincount);
/*** 関数宣言 ***/

int main(int argc, char** argv)
{
    if (argc<2)
    //入力チェック
    {
        printf("名前を入力してください\n");
        return 2;
    }
    
    printf("%sさんこんにちはそれでは敵を倒しにいこう\n",argv[1]);
    /***　ここから進めていく ***/
    /***変数宣言 ***/
    int wincount=0;
    wincount = match(wincount);
    /***クリアかどうか判別する ***/
    if(wincount ==3)
    {
        printf("ゲームクリア\n");
    }
    else
    {
        printf("ゲームオーバー\n");
    }

    return 0;
}

//敵の数遭遇する関数
int match(int wincount)
{
     printf("敵の元についた\n");
    
    while(wincount<3)//敵の数繰り返す
    {
        wincount += battle (wincount);
    }
    return wincount;
}

int battle (int wincount)
{//敵の配列を作成
    Boss boss[]={ariyoshi,takeshi,sanma};
    printf("%sが現れた\n",boss[wincount].bossname);
    //勝利
    printf("%sを倒した\n",boss[wincount].bossname);
    return 1;
}
