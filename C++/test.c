#include<stdio.h>
#include<string.h>
int change_1(char temp[10]);
int main()
{
	int i;
	char number[10][4]={"零","一","二","三","四","五","啥","意","思"};
	for(i=0;i<9;i++){
		printf("输入 %s ",number[i]);
		printf("输出 %d",change_1(number[i]));
		if(change_1(number[i])!=-1) printf("  pass\n");
		else printf("  error\n");
	}
	return 0;
}
int change_1(char temp[10])
{
	if(strcmp(temp,"零")==0) return 0;
	else if(strcmp(temp,"一")==0) return 1;
	else if(strcmp(temp,"二")==0) return 2;
	else if(strcmp(temp,"三")==0) return 3;
	else if(strcmp(temp,"四")==0) return 4;
	else if(strcmp(temp,"五")==0) return 5;
	else if(strcmp(temp,"六")==0) return 6;
	else if(strcmp(temp,"七")==0) return 7;
	else if(strcmp(temp,"八")==0) return 8;
	else if(strcmp(temp,"九")==0) return 9;
	else if(strcmp(temp,"十")==0) return 10;
	else return -1;
}
