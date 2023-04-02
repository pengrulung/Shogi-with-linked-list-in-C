#include<stdio.h>
void move(const int chess_pre[][10][2], int chess_now[][10][2], const int source[], const int destination[]) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 2; k++) {
				chess_now[i][j][k] = chess_pre[i][j][k];
			}
		}
	}
	for (int i = 0; i < 1; i++) {
		chess_now[destination[0]][destination[1]][0] = chess_pre[source[0]][source[1]][0];
		chess_now[destination[0]][destination[1]][1] = chess_pre[source[0]][source[1]][1];
		chess_now[source[0]][source[1]][0] = 0;
		chess_now[source[0]][source[1]][1] = 0;
	}
}
