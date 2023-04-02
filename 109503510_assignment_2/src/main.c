#include<stdio.h>
#include <stdlib.h>
#include"init.h"
#include"rule.h"
#include"print.h"
#include"move.h"
#include<stdbool.h>
int main(int argc, char* argv[]) {
int s=0;
    if(argv[1][1]=='n'){
    if(argv[2][1]=='s'){
    s=1;
    }else{
    argv[3]=NULL;
    }
    start_to_play(s,argv[3]);
    }
    if(argv[1][1]=='l'){
    read_old_game(argv[2]);
    }
    return 0;        
}
void start_to_play(int s,char argv[]){
	int times = 1;
	int source[2];
	int destination[2];
	int value = 0;
	int which_player = 2;
	int eat_list[20];
	int eat_count = 0;
	int back=0;
	int cmove=0;
	int result = 0;
	int flag = 0;
	char nextstep[0];
	struct Node *head=malloc(sizeof(struct Node));
	init(head->chess);
	struct Node *ptr=head;
	struct Node *tmp_print=head;
	struct Node *previous=head;
	head -> previous = NULL;
	while (times < 100) {
		push(ptr);
		while (true) {  //使用者輸入有錯 那一輪重來
		cmove=0;
			flag = 0;
			back=0;
			printf("動哪個(段) (筋):");
			scanf("%d %d", &source[0], &source[1]);
			if (source[0] < 1 || source[0] > 9)
				break;
			if (source[1] < 1 || source[1] > 9)
				break;
			printf("去哪裡(段) (筋):");
			scanf("%d %d", &destination[0], &destination[1]);
			if (destination[0] < 1 || destination[0] > 9)
				break;
			if (destination[1] < 1 || destination[1] > 9)
				break;
			value = (ptr->chess)[source[0]][source[1]][1];
			if (which_player != (ptr->chess)[source[0]][source[1]][0]) {//只能動自己的棋子
				if ((ptr->chess)[source[0]][source[1]][0] == 0){
					printf("沒棋子!\n");
					break;
					}
				printf("請操作自己的棋子\n");
				break;
			}
			if (which_player == (ptr->chess)[destination[0]][destination[1]][0]) { //去的地方沒有自己的棋子
				printf("destination有自己的棋子\n");
				break;
			}
			if (value == 1) {  //步兵的部分
				if (!bubing(source, destination, which_player)) {
					break;
				}
			}
			else if (value == 2) { //香
				if (!xion(source, destination, which_player)) {
					break;
				}
				if (!over_column(ptr->chess, source, destination)) {
					break;
				}
			}
			else if (value == 3) { //桂
				if (!gui(source, destination, which_player)) {
					break;
				}
			}
			else if (value == 4) {//銀
				if (!ing(source, destination, which_player)) {
					break;
				}
			}
			else if (value == 5) {//金
				if (!jin(source, destination, which_player)) {
					break;
				}
			}
			else if (value == 6) {//角
				if (!jiao(source, destination, which_player)) {
					break;
				}
				if (!over_diag(ptr->chess, source, destination)) {
					break;
				}
			}
			else if (value == 7) { //飛
				if (!fei(source, destination, which_player)) {
					break;
				}
				if (!over_column(ptr->chess, source, destination)) {
					break;
				}
				if (!over_row(ptr->chess, source, destination)) {
					break;
				}
			}
			else if (value == 8) { //玉
				if (!yu(source, destination, which_player)) {
					break;
				}
			}
			if (((ptr->chess)[destination[0]][destination[1]][0] != 0) && ((ptr->chess)[destination[0]][destination[1]][0] != which_player)) {
				result = win_or_not(ptr->chess, source, destination, which_player);
				eat_list[eat_count] = (ptr->chess)[destination[0]][destination[1]][1];
				eat_count++;
			}  //如果des不是自己或沒有棋子 要吃掉 吃掉的棋子紀錄
			move(ptr->chess, ptr->next->chess, source, destination);
			cmove=1;
			tmp_print=head;
			for(int i=0;i<=times;i++){
			print_from_list(tmp_print->chess,i);
			tmp_print=tmp_print->next;
			}
			printf("輸入f繼續玩 or 輸入b反悔 or 輸入q離開:");//gets
			scanf("%s", &nextstep[0]);
			if(nextstep[0]=='q'){
			break;//first loop
			}
			if (nextstep[0] == 'b') {
			ptr=ptr -> previous;
			back=1;
				printf("輸入f繼續玩 or 輸入b反悔 or 輸入q離開:");
				scanf("%s", &nextstep[0]);
				while (nextstep[0] == 'b') {
					ptr = ptr -> previous;
					printf("輸入f繼續玩 or 輸入b反悔 or 輸入q離開:");
					scanf("%s", &nextstep[0]);
					if (times > 1) {
						times--;
						if (which_player == 2) { //換人玩
							which_player = 1;
						}
						else which_player = 2;
					}
					else{printf("it's over!plz restart the game!/n");}
				}
			break;
			}
			flag = 1;
			break;
		}
		if(nextstep[0]=='q'){
			break;}//second loop
		if (flag) {
			times=times+1;
			if (result == 1) {
				break;
			}
			if (which_player == 2) { //換人玩
				which_player = 1;
			}
			else which_player = 2;
		}
		if(cmove){
		ptr=ptr -> next;}
	}
	if(s==1){
		for(int i=0;i<=times;i++){
		print_to_file(head->chess, i, argv);
		head=head->next;
		}
	}
	return;
	}
