/* ************ PacMan ************
************ first project ************
************ Pooria Heydarian************
************ Dr.Jamal kazazi ************
************ 1399, 2020-2021*************
****************** UT *******************/
#include <iostream>
#include <stdio.h>
#include<Windows.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <conio.h>
using namespace std;
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_DOWN 80
#define KEY_RIGHT 77
int random(int& x, int& y, int n)//easy proceSs
{
	srand(time(0) + n);
	int f = rand() % 2;
	if (f == 0)
	{
		int h = rand() % 2;
		if (h == 0)
			x++;
		if (h == 1)
			x--;
	}
	else
	{
		int h = rand() % 2;
		if (h == 0)
			y++;
		if (h == 1)
			y--;
	}
	return(x, y);
}
int Medium(int&x1, int&y1, int MI, int MJ) {//medium process //x1,y1=new position
	int d1, dml, dmr, dmn, dms,s=0;
	d1 = sqrt((MI - x1) * (MI - x1) + (MJ - y1) * (MJ - y1)); //first distance
	dml = sqrt((MI - x1+1) * (MI - x1+1) + (MJ - y1) * (MJ - y1));//if down distance
	dmr= sqrt((MI - x1-1) * (MI - x1-1) + (MJ - y1) * (MJ - y1));// if up distance
	dms= sqrt((MI - x1) * (MI - x1) +(MJ - y1-1) * (MJ - y1-1));//if left distance
	dmn = sqrt((MI - x1) * (MI - x1) + (MJ - y1+1) * (MJ - y1+1));// if right distance
	//check distance
	if (d1 < dml && d1 < dmr && d1 < dmn && d1 < dms);// if first distance <
	else if (dml < dmr && dml < dmn && dml < dms && dml < d1)// if up distance <
		x1 -= 1;
	else if (dmr < dml && dmr < dmn && dmr < dms && dmr < d1)// if down distance <
		x1 += 1;
	else if (dms < dml && dms < dmr && dms < dmn && dms < d1)// if right distance <
		y1 += 1;
	else if (dmn < dml && dmn < dmr && dmn < dms && dmn < d1)// if left distance <
		y1 -= 1;
	return (x1, y1); // new position of ghost
}
int main()
{
	char  M, B, P, I, C, order;	int i, j, PI, PJ, II, IJ, CI, CJ, BI, BJ, MI, MJ, type, page, t, x, y, tempPI, tempPJ, tempII, tempIJ, tempCI, tempCJ, tempBI, tempBJ, T = 0, tempMI, tempMJ, dgp = 0, dgi = 0, dgc = 0, dgb = 0, score = 0,nomove = 0; char a[20][20], g;
	printf("Which one?!\n1.Easy\n2.Medium\n");//types
	cin >> type;
	printf("which page?!\n1.manuoy\n2.tanyuo\n3.younio\n");//maps
	cin >> page; 
	for (i = 0; i < 20; i++)     //wall
		for (j = 0; j < 20; j++)
			a[0][j] = a[j][0] = a[j][19] = a[19][j] = '*';
	switch (page)
	{
	case 1://first page
		BI = 18; CI = 10; II = 15; PI = 18; BJ = 18; CJ = 10; PJ = 10; IJ = 15; MI = 16; MJ = 10; a[2][5] = a[3][5] = a[3][6] = a[4][5] = a[4][6] = a[4][15] = a[5][15] = a[6][15] = a[7][15] = a[7][14] = a[7][13] = a[9][1] = a[9][2] = a[9][3] = a[9][4] = a[9][5] = a[10][5] = a[11][5] = a[12][5] = a[14][1] = a[14][13] = a[14][14] = a[14][15] = a[15][13] = a[15][2] = a[15][14] = a[15][15] = a[16][3] = a[17][4] = '*'; a[6][2] = a[4][13] = a[4][14] = a[5][13] = a[5][14] = a[6][13] = a[6][14] = a[10][14] = a[9][14] = a[11][14] = a[10][13] = a[10][15] = a[15][1] = a[16][2] = a[17][3] = a[18][4] = a[18][3] = a[18][2] = a[18][1] = a[13][14] = a[16][14] = 'y';
		break;//second page
	case 2:a[2][4] = a[2][5] = a[2][6] = a[2][7] = a[2][12] = a[2][13] = a[2][14] = a[2][15] = a[3][4] = a[3][15] = a[4][4] = a[4][5] = a[4][6] = a[4][7] = a[4][12] = a[4][13] = a[4][14] = a[4][15] = a[8][4] = a[8][5] = a[8][6] = a[8][7] = a[8][8] = a[8][9] = a[8][10] = a[8][11] = a[8][12] = a[8][13] = a[8][14] = a[8][15] = a[11][9] = a[11][10] = a[12][9] = a[12][10] = a[13][9] = a[13][10] = a[14][9] = a[14][10] = a[15][9] = a[15][10] = a[16][9] = a[16][10] = a[17][9] = a[17][10] = a[12][8] = a[12][11] = a[13][7] = a[13][8] = a[13][11] = a[13][12] = '*'; a[3][5] = a[3][14] = a[7][5] = a[7][6] = a[7][7] = a[7][8] = a[7][9] = a[7][10] = a[7][11] = a[7][12] = a[7][13] = a[7][14] = a[14][8] = a[15][8] = a[16][8] = a[17][8] = a[14][11] = a[15][11] = a[16][11] = a[17][11] = a[18][10] = 'y'; BI = 1; BJ = 8; CI = 18; CJ = 1; MI = 3; MJ = 8; II = 10; IJ = 9; PI = 10; PJ = 10;
		break;
	case 3:printf("Please enter your map: wall:* gift:y ghosts:P,B,C,I you:M\n ");//get a map
		for (i = 0; i < 20; i++) 
			for (j = 0; j < 20; j++) {
			 a[i][j]=_getch();
			if (a[i][j] == 'B') { //b position
				BI = i;
				BJ = j;
			}
			if (a[i][j] == 'M') {//m position
				MI = i;
				MJ = j;
			}
			if (a[i][j] == 'C') {//c position
				CI = i;
				CJ = j;
			}
			if (a[i][j] == 'P') {//p position
				PI = i;
				PJ = j;
			}
			if (a[i][j] == 'I') {//i positon
				II = i;
				IJ = j;
			}
		}
	}
	for (t = 0;; t++) { // start of game 
		
		for (;;) {
			T++;
			if (T == 1)
				printf("enter for start");
		
			tempMI = MI; //last position
			tempMJ = MJ;
			tempII = II;
			tempIJ = IJ;
			tempPI = PI;
			tempPJ = PJ;
			tempCI = CI;
			tempCJ = CJ;
			tempBI = BI;
			tempBJ = BJ;
			switch (_getch()) {
			case KEY_UP: //go up
			case 'w':
				MI--;
				if (a[MI][MJ] == '*') //no move for up
				{
					cout << "NO MOVE!!" << endl << "PLEASE ENTER NEW KEY";
					MI = tempMI;
					
					continue;
				}
				t++;
				break;

			case KEY_DOWN://go down
			case 's':
				MI++;
				if (a[MI][MJ] == '*')// no move for down
				{
					cout << "NO MOVE!!" << endl << "PLEASE ENTER NEW KEY";
					MI = tempMI;
					
					continue;
				}
				t++;
				break;

			case KEY_LEFT://go left
			case 'a':
				MJ--;
				if (a[MI][MJ] == '*')
				{
					cout << "NO MOVE!!" << endl << "PLEASE ENTER NEW KEY";// no move for left
					MJ = tempMJ;
					
					continue;
				}
				t++;
				break;
			case KEY_RIGHT: //go right
			case'd':
				MJ++;
				if (a[MI][MJ] == '*')
				{
					cout << "NO MOVE!!" << endl << "PLEASE ENTER NEW KEY";// now move foe right
					MJ = tempMJ;
					
					continue;
				}
				t++;
				break;
			}
				if (t == 1) {
					if (score >= 0) { //b new position
						switch (type)
						{
						case 1: random(BI, BJ, 2); 
							break;
						case 2:Medium(BI, BJ, MI, MJ);
							break;
						}

						if (((BI == CI) && (BJ == CJ)) || ((BI == PI) && (BJ == PJ)) || ((BI == II) && (BJ == IJ)) || a[BI][BJ] == '*')// same position with wall or other ghost=> go back *

						{
							BI = tempBI;
							BJ = tempBJ;
						}
					}
					if (score >= 100) { //p new position
						switch (type)
						{
						case 1: random(PI, PJ, 1);// p easy position
							break;
						case 2:Medium(PI, PJ, MI, MJ);// p medium position
							break;
						}

						if (((PI == BI) && (PJ == BJ)) || ((PI == CI) && (PJ == CJ)) || ((PI == II) && (PJ == IJ)) || a[PI][PJ] == '*')//*
						{
							PI = tempPI;
							PJ = tempPJ;
						}
					}
					if (score >= 200) {//i new position
						switch (type)
						{
						case 1: random(II, IJ, 4);
							break;
						case 2:Medium(II, IJ, MI, MJ);
							break;
						}

						if (((II == BI) && (IJ == BJ)) || ((II == PI) && (IJ == PJ)) || ((CI == II) && (CJ == IJ)) || a[II][IJ] == '*')//*
						{
							IJ = tempIJ;
							II = tempII;
						}
					}
					if (score >= 500) { //c new position
						switch (type)
						{
						case 1: random(CI, CJ, 3);
							break;
						case 2:Medium(CI, CJ, MI, MJ);
							break;
						}

						if (((CI == BI) && (CJ == BJ)) || ((CI == PI) && (CJ == PJ)) || ((CI == II) && (CJ = IJ)) || a[CI][CJ] == '*')//*

						{

							CJ = tempCJ;
							CI = tempCI;
						}
					}
				
					//if p\c\i\b position equal y position
					if (dgp == 1) {
						a[tempPI][tempPJ] = 'y';
						dgp = 0;
					}
					if (a[PI][PJ] == 'y') {
						a[PI][PJ] = 'P';
						dgp++;
					}
					if (dgc == 1) {
						a[tempCI][tempCJ] = 'y';
						dgc = 0;
					}
					if (a[CI][CJ] == 'y') {
						a[CI][CJ] = 'C';
						dgc++;
					}
					if (dgb == 1) {
						a[tempBI][tempBJ] = 'y';
						dgb = 0;
					}
					if (a[BI][BJ] == 'y') {
						a[BI][BJ] = 'B';
						dgb++;
					}
					if (dgi == 1) {
						a[tempII][tempIJ] = 'y';
						dgi = 0;
					}
					if (a[II][IJ] == 'y') {
						a[II][IJ] = 'I';
						dgi++;
					}
					
					t = 0;
				}
				system("cls");
				for (i = 0; i < 20; i++) {   // print screen
					for (j = 0; j < 20; j++)
					{
						if (a[i][j] != '*'  && a[i][j] != 'y')
						{
							
							a[i][j] = ' ';
							
							if (a[MI][MJ] == 'y') {
								score += 50;
							}
							a[MI][MJ] = 'M';
							// enter ghost step by step
							if (score >= 0)
								a[BI][BJ] = 'B';
							
							if (score>=100)
								a[PI][PJ] = 'P';
							
							if (score>= 200)
								a[II][IJ] = 'I';
							
							if (score>=500)
								a[CI][CJ] = 'C';
							
						}
						cout << a[i][j];
					}
					cout << endl;
				}// notification
				printf("Pos M(%d,%d),Pos B(%d,%d)", MI, MJ,BI,BJ);
				if (score >= 100)
					printf(",Pos P(%d,%d)", PI, PJ);
				if (score >= 200)
					printf(",Pos I(%d,%d)", II, IJ);
				if (score >= 500)
					printf(",Pos C(%d,%d)", CI, CJ);
				
				cout << endl << score << endl;
				if (a[MI][MJ] == 'P') {
					printf("Pinky Caught Pac Man.\n");//ghost hunt pack man 
					break;
				}
				if (a[MI][MJ] == 'B') {
					printf("Blinky Caught Pac Man.\n");
					break;
				}
				if (a[MI][MJ] == 'I') {
					printf("Inky Caught Pac Man.\n");
					break;
				}
				if (a[MI][MJ] == 'C') {
					printf("Clyde Caught Pac Man.\n");
					break;
				}
				if (score == 1050) {
					cout << "You Win!!";
					Sleep(10000);
					return 0;
				}
			
		}
		printf("Game Over");
		break;
	}
	Sleep(10000);
	return 0;
}
