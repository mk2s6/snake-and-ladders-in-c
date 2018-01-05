#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int ladder[10][2]={	{4,53},
					{15,45},
					{8,28},
					{11,70},
					{31,75},
					{27,55},
					{23,96},
					{21,59},
					{43,80},
					{52,89}};
int snake[10][2]={{98,20},
					{84,12},
					{74,3},
					{72,26},
					{79,32},
					{60,37},
					{64,44},
					{90,67},
					{34,10},
					{92,50}};
int a,b;
int dice;
char player1[20],player2[20];
void init(){
	a=1;
	b=1;
}
int rollDice() {
	return (rand()%6)+1;
}
void eaten(char c,int num){
	int i;
	for(i=0;i<10;i++) {
		if(num == snake[i][0]){
			num = snake[i][1];
			if( c == 'A'){
				a=num;
				printf("Oh! NO.., Sorry.. \n--You are eaten by a snake ha!ha!ha!--\n");
				printf("You are dropped to %d\n", num);
			}
			else{
				b=num;
				printf("Oh! NO.., Sorry.. \n--You are eaten by a snake ha!ha!ha!--\n");
				printf("You are dropped to %d\n", num);
			}
			break;
		}
	}
	return;
}

void promoted(char c, int num) {
	int i;
	for(i=0;i<10;i++) {
		if(num == ladder[i][0]){
			num = ladder[i][1];
			if( c == 'A'){
				a=num;
				printf("You're lucky today! You have ladder in your position to climb\n");
				printf("After climbing you are on %d\n", num);
			}
			else{
				b=num;
				printf("You're lucky today! You have ladder in your position to climb\n");
				printf("After climbing you are on %d\n", num);
			}
			break;
		}
	}
	return;
}
void main(){
	char g;
	printf("----------Snake and ladders game of two players----------\n");
	printf("Enter name of player1 : ");
	gets(player1);
	printf("Enter name of player2 : ");
	gets(player2);
	init();
	srand(time(NULL));
	while(1){
	A:	if(a <= 100){
			printf("\n\nTurn for %s \n", player1);
			printf("To roll the dice press any key or \'N\' to give-up : ");
			g=getch();
			if(g == 'N') {
				printf("\n\n%s left the game\n", player1);
				printf("\n%s wins the game\n",player2);
				exit(0);
			}
			dice = rollDice();
			printf("\ndice of %s is %d\n", player1, dice);
			a += dice;
			if(a > 100){
				a -= dice;
				goto B;
			}
			promoted('A',a);
			eaten('A',a);
			printf("%s is on %d\n", player1, a);
			if(dice == 6){
				printf("\nYou got a great luck, you get another chance to throw the dice\n");
				goto A;
			}
			if(a == 100){
				printf("\n%s is the winner", player1);
				break;
			}
		}
	B:	if(b <= 100){
			printf("\n\nTurn for %s \n", player2);
			printf("To roll the dice press any key or \'N\' to give-up : ");
			g=getch();
			if(g == 'N') {
				printf("\n\n%s left the game\n", player2);
				printf("\n%s wins the game\n",player1);
				exit(0);
			}
			dice = rollDice();
			printf("\ndice of %s is %d\n", player2, dice);
			b += dice;
			if(b > 100){
				b -= dice;
				goto A;
			}
			promoted('B',b);
			eaten('B',b);
			printf("%s is on %d\n", player2 ,b);
			if(dice == 6){
				printf("\nYou got a great luck, you get another chance to throw the dice\n");
				goto B;
			}
			if(b == 100){
				printf("\n%s is the winner", player2);
				break;
			}
		}
	}
	printf("Copyright registerd to SIVA: 15381A0518");
}
