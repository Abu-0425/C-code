#ifndef _MINE_H_
#define _MINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#pragma warning(disable:4996)

#define ROW 12//(��ʵ��10+2��10*10���������������Ϸ�������12*12����Ϊ�˱���ͳ������)
#define COL 12
#define MINE_NUM 15//�׵�����

void Menu();//�˵�����
void Game();//��Ϸ����
void InitBoard(char show_board[][COL], int row, int col, char elem);//��ʼ����庯��
void SetMine(char mine_board[][COL], int row, int col);//���׺���
void ShowBoard(char show_board[][COL], int row, int col);//��ӡ��Ϸ���
char GetNum(char mine_board[][COL], int x, int y);//��ȡ��Χ�׵�����
void Extend(char show_board[][COL], char mine_board[][COL], int row, int col, int x, int y);//�ݹ�չ������
int Judge(char show_board[][COL], int row, int col);//�ж���Ϸ���

#endif