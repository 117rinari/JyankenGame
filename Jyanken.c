#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Jyanken();
int Pattern1(int, int, int, int, int);
void Pattern2();
void Pattern3();
void Pattern4();
void Show_Hand();
int Judge(int, int);
void Result(int, int);
void Game(int (*func)());
void GameEnd(int, int);

int main(void)
{
  Jyanken();

  return 0;
}

void Jyanken()
{
  //パターンを関数ポインタにて決定
  int (*fp)() = Pattern1;

  //1回目のじゃんけんゲームを開始
  Game(fp);

  char c = 'A';//適当な文字で初期化
  while(1){
    printf("続行:n   やめる:z\n\n");
    scanf("%c", &c);
    while(getchar() != '\n');
    if(c != 'n' && c != 'z') continue;
    if(c == 'z') break;

    //2戦目以降のゲーム
    fp = Pattern1;
    Game(fp);
    printf("\n");
  }
}

void Game(int (*func)())
{
  ///////////* ゲーム内で使用する変数 *///////////
  //じゃんけん数、プレイヤーの勝ち数、敵の勝ち数
  int gamecount = 0, Player_wins = 0, Enemy_wins = 0;

  //プレイヤーの手、敵の手、直前のプレイヤーの手、直前の敵の手
  int Player_hand, Enemy_hand, Player_before_hand = -1, Enemy_before_hand = -1;

  ///////////////////////////////////////////////

  //じゃんけんのループ
  while(Player_wins < 3 && Enemy_wins < 3){
    //プレイヤーの手を入力
    printf("0:グー, 1:チョキ, 2:パー\n");
    while(scanf("%d", &Player_hand) != 1 || (Player_hand < 0 || Player_hand > 2)){
      printf("エラー\n");
      printf("0:グー, 1:チョキ, 2:パー\n");
      while(getchar() != '\n');
    }
    while(getchar() != '\n');/////

    //敵の選択肢
    Enemy_hand = func(gamecount, Player_wins, Enemy_wins, Player_before_hand, Enemy_before_hand);

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
    }/////switch/////

    ///////////////////1戦毎の処理///////////////////
    gamecount++;//試合数カウントインクリメント

    //直前のプレイヤーと敵の手を記憶
    Player_before_hand = Player_hand;
    Enemy_before_hand = Enemy_hand;

    /////////////////////////////////////////////////

  }/////while/////

  //決着が着いた後
   GameEnd(Player_wins, Enemy_wins);
}

int Pattern1(int g_count, int p_wins, int e_wins, int ply_bef_hand, int enm_bef_hand)
{
  //グー、チョキ、パーの順で出していくパターン
  return g_count % 3;
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
