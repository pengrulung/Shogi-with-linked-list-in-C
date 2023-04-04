#define ROW 10
#define COLUMN 10
#define stack_total 100
#include<stdlib.h>
void start_to_play(int s,char argv[]);
struct Node{
	int chess[ROW][COLUMN][2];
	struct Node *next;
	struct Node *previous;
};
void push(struct Node *ptr){
	struct Node *plan_to_move=malloc(sizeof(struct Node));
	ptr -> next=plan_to_move;
	plan_to_move -> previous = ptr;
	return;
}
void pop(struct Node *ptr){
	struct Node *prev_move=malloc(sizeof(struct Node));
	prev_move=ptr -> previous;
	ptr = prev_move;
	free(prev_move);
	return;
}
void init(int chess_init[][10][2]) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 2; k++) {
				chess_init[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		chess_init[1][i][0] = 1; //player1
		chess_init[3][i][0] = 1; //player1
		chess_init[3][i][1] = 1; //步
	}
	for (int i = 1; i < 10; i++) {
		chess_init[9][i][0] = 2; //player2
		chess_init[7][i][0] = 2; //player2
		chess_init[7][i][1] = 1; //步
	}
	//player1
	chess_init[1][1][1] = 2; //香
	chess_init[1][2][1] = 3; //桂
	chess_init[1][3][1] = 4; //銀
	chess_init[1][4][1] = 5; //金
	chess_init[1][5][1] = 8; //王
	chess_init[1][6][1] = 5; //金
	chess_init[1][7][1] = 4; //銀
	chess_init[1][8][1] = 3; //桂
	chess_init[1][9][1] = 2; //香

	chess_init[2][2][1] = 7; //飛
	chess_init[2][8][1] = 6; //角
	chess_init[2][2][0] = 1; //飛 player1
	chess_init[2][8][0] = 1; //角 player1

	//player2
	chess_init[9][1][1] = 2; //香
	chess_init[9][2][1] = 3; //桂
	chess_init[9][3][1] = 4; //銀
	chess_init[9][4][1] = 5; //金
	chess_init[9][5][1] = 8; //王
	chess_init[9][6][1] = 5; //金
	chess_init[9][7][1] = 4; //銀
	chess_init[9][8][1] = 3; //桂
	chess_init[9][9][1] = 2; //香

	chess_init[8][8][1] = 7; //飛
	chess_init[8][2][1] = 6; //角
	chess_init[8][8][0] = 2; //飛 player2
	chess_init[8][2][0] = 2; //角 player2
	return;
}

