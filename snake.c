#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int ladder[10][2]={	{4,53},
					{15,45},
					{8,28},
					{11,70},
					{31,74},
					{27,55},
					{23,96},
					{21,59},
					{43,80},
					{52,89}};
int snake[10][2]={{94,20},
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
			if( c == 'A')
				a=num;
			else
				b=num;
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
			if( c == 'A')
				a=num;
			else
				b=num;
			break;
		}
	}
	return;
}
void main(){
	init();
	srand(time(NULL));
	while(1){
	A:	if(a <= 100){
			dice = rollDice();
			printf("dice of a is %d\n",dice);
			a += dice;
			if(a > 100){
				a -= dice;
				goto B;
			}
			promoted('A',a);
			eaten('A',a);
			printf("a is %d\n",a);
			if(dice == 6)
				goto A;
			if(a == 100){
				printf("\nA is the winner");
				break;
			}
		}
	B:	if(b <= 100){
			dice = rollDice();
			printf("dice of b is %d\n",dice);
			b = b + dice;
			if(b > 100){
				b -= dice;
				goto A;
			}
			promoted('B',b);
			eaten('B',b);
			printf("b is %d\n",b);
			if(dice == 6)
				goto B;
			if(b == 100){
				printf("B is the winner");
				break;
			}
		}
	}
	printf("\n\n\nCopyright registerd to SIVA: 15381A0518");
}
