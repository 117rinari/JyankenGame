#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Jyanken();
void Pattern1();
void Pattern2();
void Pattern3();
void Pattern4();
void Show_Hand();
int Judge(int, int);
void Result(int, int);
void GameEnd(int, int);

int main(void)
{
  Pattern1();

  return 0;
}

void Pattern1()
{
  //
  int count = 0, Player_wins = 0, Enemy_wins = 0;

  //
  int Player_hand, Enemy_hand;

  //じゃんけんのループ
  while(Player_wins + Enemy_wins < 5){
    //プレイヤーの選択肢
    printf("0:グー, 1:チョキ, 2:パー\n");
    scanf("%d", &Player_hand);
    getchar();

    //敵の選択肢
    Enemy_hand = count % 3;

    //プレイヤーと敵の手、勝敗結果を表示
    printf("あなたの手: ");
    Show_Hand(Player_hand);
    printf("敵の手: ");
    Show_Hand(Enemy_hand);
    Result(Player_hand, Enemy_hand);

    //結果の表示と処理
    switch(Judge(Player_hand, Enemy_hand)){
      case 0:
        //あいこの場合
        break;

      case 1:
        //プレイヤーの勝ちの場合
        Player_wins++;
        break;

      case 2:
        //プレイヤーの負けの場合
        Enemy_wins++;
        break;
    }

    //1戦毎に行う処理
    count++;
  }
   //決着が着いた後
   GameEnd(Player_wins, Enemy_wins);

}

int Judge(int Player_h, int Enemy_h)
{
  //引数:0:グー, 1:チョキ, 2:パー
  //返り値: 0:あいこ, 1:プレイヤー勝ち, 2:敵の勝ち

  if(Player_h == Enemy_h){
    return 0;
  }else if(Player_h < Enemy_h || (Player_h == 2 && Enemy_h == 0)){
    return 1;
  }else{
    return 2;
  }
}

void Result(int Player_h, int Enemy_h)
{
  switch(Judge(Player_h, Enemy_h)){
    case 0:
      printf("あいこです\n\n");
      break;
    case 1:
      printf("あなたの勝ちです\n\n");
      break;
    case 2:
      printf("あなたの負けです\n\n");
      break;
  }
}

void Show_Hand(int hand)
{
  switch(hand){
    case 0:
    printf("グー\n");
    break;

    case 1:
     printf("チョキ\n");
     break;

    case 2:
      printf("パー\n");
      break;
  }
}

void GameEnd(int Player_w, int Enemy_w)
{
  printf("%d勝%d敗で", Player_w, Enemy_w);

  if(Player_w > Enemy_w){
    printf("あなたの勝ち\n");
  }else if(Player_w < Enemy_w){
    printf("あなたの負け\n");
  }else{
    printf("引き分け\n");
  }

}
