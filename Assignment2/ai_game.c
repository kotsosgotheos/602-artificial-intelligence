//MinMax Game
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdbool.h>

typedef struct _player {
	int M;
	int N;
} player;

/*
//na kanw global to array
struct node{
	struct node parent;
	int cost;
	struct node *children;  // pinakas paidiwn
	int score;
}
*/
bool position_is_not_taken(char c){
    return !((c == 'X') || (c == 'A') || (c == 'B'));
}

bool can_move(int m, int n, int M, int N, char **array, player *playerB) {
	return (position_is_not_taken(array[playerB->M][playerB->N+1])
         || position_is_not_taken(array[playerB->M][playerB->N-1])
         || position_is_not_taken(array[playerB->M+1][playerB->N+1])
         || position_is_not_taken(array[playerB->M+1][playerB->N])
         || position_is_not_taken(array[playerB->M+1][playerB->N-1])
         || position_is_not_taken(array[playerB->M-1][playerB->N+1])
         || position_is_not_taken(array[playerB->M-1][playerB->N])
         || position_is_not_taken(array[playerB->M-1][playerB->N-1]));
}

int check_input(int m, int n, int new_M, int new_N, char **array, player *playerB) {
	if((playerB->M == new_M) && ((playerB->N == new_N+1) || (playerB->N == new_N-1))
	|| (((playerB->M == new_M+1) || (playerB->M == new_M-1)) && ((playerB->N == new_N) || (playerB->N == new_N+1) || (playerB->N == new_N-1))))
        return position_is_not_taken(array[new_M][new_N]);
	return false;
}

void update_Array(int m, int n, int M, int N, int new_M, int new_N, char **array, player *playerB) {
	int i, j;

	playerB->M = new_M;
	playerB->N = new_N;

    array[N][M] = 'X';
    array[new_N][new_M] = 'B';

	printf("\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
            printf("%c ", array[i][j]);
		printf("\n");
	}
	printf("\n");	
}


/*

struct node** children(){
	int position = 0;
	if(isnotXorA(*(Array + (playerA->M)*(playerA->N) + playerA->N+1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M)*(playerA->N) + playerA->N-1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M+1)*(playerA->N) + playerA->N+1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M+1)*(playerA->N) + playerA->N)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M+1)*(playerA->N) + playerA->N-1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M-1)*(playerA->N) + playerA->N+1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M-1)*(playerA->N) + playerA->N)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M-1)*(playerA->N) + playerA->N-1)==1){
		children[position] = make_child;
		position++;
	}
}


void start_tree(int m,int n,player* playerA,player* playerB,char *Array){
	struct node* root =  malloc(sizeof(struct node));
}
	


void tree

	
void Max(int m,int n,player* playerA,char *Array){
	
}	
*/
void Min(int m,int n,player* playerB,char **array){
	int M,N,new_M,new_N;
	
	M = playerB->M;
	N = playerB->N;
	
	if(can_move(m,n,M,N,array,playerB)==1){
		printf("Your turn. Give directions.\n");
		
		printf("Give M :");
		scanf("%d",&new_M);
		printf("Give N :");
		scanf("%d",&new_N);
		printf("\n");
		
		while(!check_input(m,n,new_M,new_N,array,playerB)){
			printf("Wrong directions.\n");
			printf("Try again.\n");
			printf("Give M :");
			scanf("%d",&new_M);
			printf("Give N :");
			scanf("%d",&new_N);
			printf("\n");
		}
		update_Array(m,n,M,N,new_M,new_N,array,playerB);
	}else{
		printf("Player 1 Lost!");
		printf("PLAYER 2 WIN THE GAME!!!\n");
		exit(1);
	}
}

int main(int argc, char **argv) {
	int M,N,i,j;

	assert(argc == 3);
	int m = atoi(argv[1]);  
	int n = atoi(argv[2]); 
	
	char **array = (char**)malloc(m * sizeof(char*));
	for(i = 0; i < m; i++)
		array[i] = (char*)malloc(n * sizeof(char));

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            array[i][j] = '0';
	
	printf("\n");

	player *player_a = (player*)malloc(sizeof(player));
	player_a-> M = 0;
	player_a-> N = (int)(n / 2);

	player* player_b =  malloc(sizeof(player));
	player_b-> M = m - 1;
	player_b-> N = (int)(n/2);

    array[0][n / 2] = 'A';
    array[m - 1][n / 2] = 'B';

	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++)
            printf("%c ", array[i][j]);
		printf("\n");
	}
	
	printf("\n");
	
	while(true) {
		Min(m, n, player_b, array);
		//Max();
	}
}
