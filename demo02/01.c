#include <stdlib.h>
#include <stdio.h>

char const map[] = "\n%d|%d|%d\n-+-+-\n%d|%d|%d\n-+-+-\n%d|%d|%d\n";
char status[3][3] = {0};

extern int start(int bot);

extern int bot(int mode);

extern int calc();

int main()
{
  while (1)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        status[i][j] = 0;
    int mode = -1;
    system("clear");
    //模式选择
    printf("选择先手：\n1.玩家\n2.电脑\n>");
    
    while (scanf("%d", &mode) != 1 || mode < 1 || mode > 2)
    {
      printf("输入错误，请重新输入：\n>");
      while (getchar() != '\n');
    }
    start(mode);
  }
}

int calc()
{
  if (status[0][0] == status[0][1] && status[0][1] == status[0][2] && status[0][0] != 0)
    return status[0][0];
  
  if (status[1][0] == status[1][1] && status[1][1] == status[1][2] && status[1][0] != 0)
    return status[1][0];
  
  if (status[2][0] == status[2][1] && status[2][1] == status[2][2] && status[2][0] != 0)
    return status[2][0];
  
  if (status[0][0] == status[1][0] && status[1][0] == status[2][0] && status[0][0] != 0)
    return status[0][0];
  
  if (status[0][1] == status[1][1] && status[1][1] == status[2][1] && status[0][1] != 0)
    return status[0][1];
  
  if (status[0][2] == status[1][2] && status[1][2] == status[2][2] && status[0][2] != 0)
    return status[0][2];
  
  if (status[0][0] == status[1][1] && status[1][1] == status[2][2] && status[0][0] != 0)
    return status[0][0];
  
  if (status[0][2] == status[1][1] && status[1][1] == status[2][0] && status[0][2] != 0)
    return status[0][2];
  
  return 0;
}

int start(int mode)
{
  int result;
  int turn = 1;
  while (1)
  {
    system("clear");
    
    if (mode == 2)
    {
      bot(turn);
      turn = -turn;
  
      //判断输赢
      result = calc();
  
      system("clear");
      printf(map, status[0][0], status[0][1], status[0][2], status[1][0], status[1][1], status[1][2], status[2][0],
             status[2][1], status[2][2]);
      if (result)
      {
    
        printf("%d赢了！\n（输入任意字符继续）\n>", result);
        int c;
        scanf("%d", &c);
        break;
      }
    }
    //打印棋盘
    system("clear");
    printf(map, status[0][0], status[0][1], status[0][2], status[1][0], status[1][1], status[1][2], status[2][0],
           status[2][1], status[2][2]);
    //接受输入
    int x, y;
    printf("输入坐标：\n(你是%d)>", turn);
    while ((scanf("%d,%d", &x, &y) != 2) || x - 1 < 0 || x - 1 > 2 || y - 1 < 0 || y - 1 > 2 ||
           (status[x - 1][y - 1] != 0))
    {
      printf("输入错误！\n请重新输入>");
      while (getchar() != '\n');
    }
    x--;
    y--;
    status[x][y] = turn;
    turn = -turn;
    //打印棋盘
    system("clear");
    printf(map, status[0][0], status[0][1], status[0][2], status[1][0], status[1][1], status[1][2], status[2][0],
           status[2][1], status[2][2]);
  
    //判断输赢
    result = calc();
    if (result)
    {
      printf("%d赢了！\n（输入任意字符继续）\n>", result);
      int c;
      scanf("%d", &c);
      break;
    }
  
    if (mode == 1)
    {
      bot(turn);
      turn = -turn;
      //判断输赢
      result = calc();
    
      system("clear");
      printf(map, status[0][0], status[0][1], status[0][2], status[1][0], status[1][1], status[1][2], status[2][0],
             status[2][1], status[2][2]);
      if (result)
      {
        printf("%d赢了！\n（输入任意字符继续）\n>", result);
        int c;
        scanf("%d", &c);
        break;
      }
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