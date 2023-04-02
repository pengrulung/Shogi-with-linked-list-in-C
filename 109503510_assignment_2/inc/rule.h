#define false 0 
#define true 1  
#include<stdio.h> 
#include<stdlib.h>
int bubing(const int source[], const int destination[],const int player) {
	if (source[1] != destination[1]) {
		printf("不能這樣走~\n");
		return false;
	}
	if (player == 2 && ((source[0] - 1) == destination[0])) {
		return true;
	}
	if (player == 1 && ((source[0] + 1) == destination[0])) {
		return true;
	}
	else {
		printf("不能這樣走~\n");
		return false;
	}
	printf("code error");
}
int xion(const int source[], const int destination[], const int player) {
	if (source[1] != destination[1]) {
		printf("不能這樣走~\n");
		return false;
	}
	if (player == 2 && (source[0] > destination[0])) {
		return true;
	}
	else if (player == 1 && (source[0] < destination[0])) {
		return true;
	}
	else {
	printf("不能這樣走~\n");
	return false;
	}
	printf("code error");
}
int gui(const int source[], const int destination[], const int player) {
	if (!(source[1] == (destination[1] + 1)) || (source[1] == (destination[1] - 1))) {
		printf("不能這樣走~\n");
		return false;
	}
	if (player == 2 && ((source[0] - 2) == destination[0])) {
		return true;
	}
	if (player == 1 && ((source[0] + 2) == destination[0])) {
		return true;
	}
	else {
		printf("不能這樣走~\n");
		return false;
	}
	printf("code error");
}
int ing(const int source[], const int destination[], const int player) {
	if (player == 2) {
		if ((source[0] - 1) == destination[0]) {
			if (((source[1] - 1) == destination[1]) || (source[1] == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
		if ((source[0] + 1) == destination[0]) {
			if (((source[1] - 1) == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
	}
	else if (player == 1) {
		if ((source[0] + 1) == destination[0]) {
			if (((source[1] - 1) == destination[1]) || (source[1] == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
		if ((source[0] - 1) == destination[0]) {
			if (((source[1] - 1) == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}

	}
	else {
		printf("不能這樣走~\n");
		return false;
	}
	printf("code error");
}
int jin(const int source[], const int destination[], const int player) {
	if (player == 2) {
		if ((source[0] - 1) == destination[0]) {
			if (((source[1] - 1) == destination[1]) || (source[1] == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
		if (source[0] == destination[0]) {
			if (((source[1] - 1) == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
		if ((source[0] + 1) == destination[0]) {
			if (source[1] == destination[1]) {
				return true;
			}
		}
	}
	else if (player == 1) {
		if ((source[0] + 1) == destination[0]) {
			if (((source[1] - 1) == destination[1]) || (source[1] == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
		if (source[0] == destination[0]) {
			if (((source[1] - 1) == destination[1]) || ((source[1] + 1) == destination[1])) {
				return true;
			}
		}
		if ((source[0] - 1) == destination[0]) {
			if (source[1] == destination[1]) {
				return true;
			}
		}
	}
	else {
		printf("不能這樣走~\n");
		return false;
	}
	printf("code error");
}
int jiao(const int source[], const int destination[], const int player) {
	int d = source[0] - destination[0];
	if (((source[0] - destination[0]) == d) || ((source[0] - destination[0]) == -d)) {
		return true;
	}
	else {
		printf("不能這樣走~\n");
		return false;
	}
}
int fei(const int source[], const int destination[], const int player) {
	if ((source[0] != destination[0])&&(source[1] != destination[1])) {
		printf("不能這樣走~\n");
		return false;
	}
	else return true;
	printf("code error");
}
int yu(const int source[], const int destination[], const int player) {
	if ((source[0] - 1) == destination[0]) {
		if (((source[1] - 1) == destination[1]) || (source[1] == destination[1]) || ((source[1] + 1) == destination[1])) {
			return true;
		}
	}
	if (source[0] == destination[0]) {
		if (((source[1] - 1) == destination[1]) || ((source[1] + 1) == destination[1])) {
			return true;
		}
	}
	if (((source[0] + 1) == destination[0])|| ((source[1] - 1) == destination[1]) || ((source[1] + 1) == destination[1])) {
		if (source[1] == destination[1]) {
			return true;
		}
	}
	printf("不能這樣走~\n");
	return false;
	printf("code error");
}
int over_column(const int chess_pre[][10][2],const int source[], const int destination[]) {
	if (destination[0] > source[0]) {
		for (int i = source[0] + 1; i < destination[0] ; i++) {
			if (chess_pre[i][source[1]][0] != 0) {
				printf("不能這樣走~\n");
				return false;
			}
		}
	}else{
		for (int i = destination[0] + 1; i < source[0] ; i++) {
			if (chess_pre[i][source[1]][0] != 0) {
				printf("不能這樣走~\n");
				return false;
			}
		}
	}
	return true;
}
int over_diag(const int chess_pre[][10][2], const int source[], const int destination[]) {
	int row, column, d, a, b;
	if (source[0] < destination[0]) {
		column = 1;
		d = destination[0] - source[0];
	}
	else {
		column = -1;
		d = source[0] - destination[0];
	}
	if (source[1] < destination[1])
		row = 1;
	else row = -1;
	a = source[0] + column;
	b = source[1] + row;
	for(; d > 1; d--, a = a + column, b = b + row) {
		if (chess_pre[a][b][0] != 0) {
			printf("不能這樣走~\n");
			return false;
		}
	}
	return true;
}
int over_row(const int chess_pre[][10][2], const int source[], const int destination[]) {
	for (int i = source[1] + 1; i < destination[1] - 1; i++) {
		if (chess_pre[source[0]][i][0] != 0) {
			return false;
		}
	}
	return true;
}
int win_or_not(const int chess_pre[][10][2], const int source[], const int destination[],const int which_player) {
	if (chess_pre[destination[0]][destination[1]][1] == 9) {
		if (which_player == 1) {
			printf("red player wins!");
			return true;
		}
		if (which_player == 2) {
			printf("blue player wins!");
			return true;
		}
	}
	return false;
}
