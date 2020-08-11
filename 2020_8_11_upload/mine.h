#ifndef _MINE_H_
#define _MINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#pragma warning(disable:4996)

#define ROW 12//(其实是10+2，10*10的面板用来进行游戏，定义成12*12则是为了便于统计雷数)
#define COL 12
#define MINE_NUM 15//雷的数量

void Menu();//菜单函数
void Game();//游戏函数
void InitBoard(char show_board[][COL], int row, int col, char elem);//初始化面板函数
void SetMine(char mine_board[][COL], int row, int col);//布雷函数
void ShowBoard(char show_board[][COL], int row, int col);//打印游戏面板
char GetNum(char mine_board[][COL], int x, int y);//获取周围雷的数量
void Extend(char show_board[][COL], char mine_board[][COL], int row, int col, int x, int y);//递归展开函数
int Judge(char show_board[][COL], int row, int col);//判断游戏结果

#endif