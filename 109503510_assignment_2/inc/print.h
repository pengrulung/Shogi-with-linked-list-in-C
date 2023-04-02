#include<stdio.h>
#include<stdlib.h>
void show(int color, int which);
int atoi(const char *str);
void print(const int chess_stack[][9][2],const int times) {
	for (int k = 0; k <= times; k++) {
		printf("第%d張圖:\n",k);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				show(chess_stack[i][j][0], chess_stack[i][j][1]);
				//printf("%d%d ", chess_stack[k][i][j][0], chess_stack[k][i][j][1]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
void print_from_list(int chess[][10][2], const int times){
		printf("第%d張圖:\n",times);
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				show(chess[i][j][0], chess[i][j][1]);
				}
				printf("\n");
		}
		printf("\n");
}
void print_to_file(const int chess_stack[10][10][2],const int times,char*filename) {
	FILE *chess_process;
	chess_process=fopen(filename,"a+");
	if(chess_process == NULL){
 	printf("I'm so sorry,Open file error.\n");
 	}else 
		fprintf(chess_process,"%d:\n",times);
		for (int i = 1; i < 10; i++) {
		fprintf(chess_process,"\t");
			for (int j = 1; j < 10; j++) {
				fprintf(chess_process,"%d%d ", chess_stack[i][j][0], chess_stack[i][j][1]);
			}
			fprintf(chess_process,"\n");
		}
		fprintf(chess_process,"\n");
	fclose(chess_process);
	}
void show(int color, int which) {
	if (color == 0 && which == 0) {
		printf(" __");
	}
	if (color == 1) { //color red
		if (which == 1) 
			printf("\033[31m 步\033[m");
		if (which == 2)
			printf("\033[31m 香\033[m");
		if (which == 3)
			printf("\033[31m 桂\033[m");
		if (which == 4)
			printf("\033[31m 銀\033[m");
		if (which == 5)
			printf("\033[31m 金\033[m");
		if (which == 6)
			printf("\033[31m 角\033[m");
		if (which == 7)
			printf("\033[31m 飛\033[m");
		if (which == 8)
			printf("\033[31m 玉\033[m");
	}
	if (color == 2) { //color blue
		if (which == 1)
			printf("\033[34m 步\033[m");
		if (which == 2)
			printf("\033[34m 香\033[m");
		if (which == 3)
			printf("\033[34m 桂\033[m");
		if (which == 4)
			printf("\033[34m 銀\033[m");
		if (which == 5)
			printf("\033[34m 金\033[m");
		if (which == 6)
			printf("\033[34m 角\033[m");
		if (which == 7)
			printf("\033[34m 飛\033[m");
		if (which == 8)
			printf("\033[34m 王\033[m");
	}
}
void read_old_game(char*filename){
	char *contents = NULL;
    	size_t len = 0;
    	int count=0;
    	int temp[2];
	FILE *old_chess_process;
	old_chess_process=fopen(filename,"r");
	if(old_chess_process == NULL){
 	printf("I'm so sorry. NO file.\n");
 	}else{
 		while (getline(&contents, &len, old_chess_process) != -1){
 			if(contents[1]==':'){
 				printf("%s\n",contents);}
 			else{
 			if(count==9){
 			count=0;
 			}else{
				for(int i=1;i<27;i=i+3){
				temp[0]=atoi(&contents[i]);
				temp[0]=temp[0]/10;
				temp[1]=atoi(&contents[i+1]);
 				show(temp[0],temp[1]);
 				//printf("%d %d ",temp[0],temp[1]);
 				}
 				count++;}
        		printf("\n");
    			}
 	}
	fclose(old_chess_process);
}
}
