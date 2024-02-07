#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int i, j;
  int x, y;
  x = 10;
  y = 5;
  char
      move_key; // 控制飞机,移动:wasd,发射子弹:通过space控制变量shoot_key,退出:q
  char shoot_key = 0; // space控制, 1为真:显示子弹, 0为假, 不显示子弹
  int ny = 5;         // 靶子位置
  int isKilled = 0; // 1为真(已经kill了):不显示靶子, 0为假, 显示靶子

  while (1) {

    // 清屏，win: cls, linux: clear
    system("cls");

    // print靶子
    if (!isKilled) {
      for (i = 0; i < ny; i++) {
        printf(" ");
      }
      printf("+\n");
    }

    // 如果shoot_key==1, 发射子弹，发射完成shoot_key重置为0,50ms后子弹消失,如果没有击中靶子清屏后还要继续显示靶子
    // 如果shoot_key==0, 直接print空行
    if (shoot_key) {
      for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
          printf(" ");
        }
        printf("  |\n");
      }
      if (y + 2 == ny) {
        isKilled = 1;
      }

      shoot_key = 0;
      Sleep(50);
      system("cls");
      if (!isKilled) {
        for (i = 0; i < ny; i++) {
          printf(" ");
        }
        printf("+\n");
      }
      for (i = 0; i < x; i++) {
        printf("\n");
      }
    } else {
      for (i = 0; i < x; i++) {
        printf("\n");
      }
    }

    // print飞机
    for (j = 0; j < y; j++) {
      printf(" ");
    }
    printf("  *\n");
    for (j = 0; j < y; j++) {
      printf(" ");
    }
    printf("*****\n");
    for (j = 0; j < y; j++) {
      printf(" ");
    }
    printf(" * *\n");

    // 获取move_key, 立即刷新缓存
    move_key = _getch();
    fflush(stdin);

    // 按键控制
    // wasd移动
    // space修改shoot_key发射子弹
    // q退出
    if (move_key == 'w' && x != 5) {
      x--;
    }
    if (move_key == 's' && x != 15) {
      x++;
    }
    if (move_key == 'a' && y != 0) {
      y--;
    }
    if (move_key == 'd' && y != 25) {
      y++;
    }
    if (move_key == ' ') {
      shoot_key = 1;
    }
    if (move_key == 'q') {
      break;
    }
  }

  return 0;
}