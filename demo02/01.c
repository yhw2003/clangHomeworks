#include <stdlib.h>
#include <stdio.h>

char const map[] = "\n%d|%d|%d\n-+-+-\n%d|%d|%d\n-+-+-\n%d|%d|%d\n";
char status[3][3] = {0};
int point[2] = {0};

extern int start(int bot);

extern int bot(int mode);

int main()
{
  while (1)
  {
    int mode = -1;
    system("clear");
    //模式选择
    printf("选择先手：\n1.玩家\n2.电脑\n>");
    scanf("%d", &mode);
    start(mode);
  }
}


int start(int mode)
{
  int turn = 1;
  while (1)
  {
    system("clear");
    
    if (mode == 2)
    {
      bot(turn);
      turn = -turn;
    }
    //打印棋盘
    printf(map, status[0][0], status[0][1], status[0][2], status[1][0], status[1][1], status[1][2], status[2][0],
           status[2][1], status[2][2]);
    //接受输入
    int x, y;
    printf("输入坐标：\n(你是%d)>", turn);
    scanf("%d,%d", &x, &y);
    if (x <= 0 || x > 3 || y <= 0 || y > 3)
    {
      printf("输入错误！\n");
      continue;
    }
    x--;
    y--;
    status[x][y] = turn;
    turn = -turn;
    if (mode == 1)
    {
      bot(turn);
      turn = -turn;
    }
  }
}

int bot(int mode)
{
  //遍历每个点，更具周围字情况基于对应分数
  double max_score = -5;
  int bestPoint[2] = {0, 0};
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if (status[i][j] == 0)
      {
        double score;
        score = 0;
        if (i == 0 || i == 2)
        {
          score -= 0.5;
        }
        if (j == 0 || j == 2)
        {
          score -= 0.5;
        }
        
        //左上角
        if (i > 0 && j > 0)
        {
          if (mode == status[i - 1][j - 1])
            score += 1;
          else if (-mode == status[i - 1][j - 1])
            score += 0.3;
        }
        //上方
        if (j > 0)
        {
          if (mode == status[i][j - 1])
            score += 1;
          else if (-mode == status[i][j - 1])
            score += 0.3;
        }
        //右上角
        if (i < 2 && j > 0)
        {
          if (mode == status[i - 1][j + i])
            score += 1;
          else if (-mode == status[i - 1][j + i])
            score += 0.3;
        }
        //左侧
        if (i > 0)
        {
          if (mode == status[i][j - 1])
            score += 1;
          else if (-mode == status[i][j - 1])
            score += 0.3;
        }
        //右侧
        if (i < 2)
        {
          if (mode == status[i][j + 1])
            score += 1;
          else if (-mode == status[i][j + 1])
            score += 0.3;
        }
        //左下
        if (i > 0 && j < 2)
        {
          if (mode == status[i + 1][j - 1])
            score += 1;
          else if (-mode == status[i + 1][j - 1])
            score += 0.3;
        }
        //下
        if (j < 2)
        {
          if (mode == status[i + 1][j])
            score += 1;
          else if (-mode == status[i + 1][j])
            score += 0.3;
        }
        //右下
        if (i < 2 && j < 2)
        {
          if (mode == status[i + 1][j + 1])
            score += 1;
          else if (-mode == status[i + 1][j + 1])
            score += 0.3;
        }
        if (score > max_score)
        {
          max_score = score;
          bestPoint[0] = i;
          bestPoint[1] = j;
        }
      }
    }
  }
  //落子
  status[bestPoint[0]][bestPoint[1]] = mode;
  return 0;
}