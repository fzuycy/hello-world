#include<stdio.h>
#include<string.h>
int change_1(char temp[10]);
int main()
{
	int i;
	char number[10][4]={"��","һ","��","��","��","��","ɶ","��","˼"};
	for(i=0;i<9;i++){
		printf("���� %s ",number[i]);
		printf("��� %d",change_1(number[i]));
		if(change_1(number[i])!=-1) printf("  pass\n");
		else printf("  error\n");
	}
	return 0;
}
int change_1(char temp[10])
{
	if(strcmp(temp,"��")==0) return 0;
	else if(strcmp(temp,"һ")==0) return 1;
	else if(strcmp(temp,"��")==0) return 2;
	else if(strcmp(temp,"��")==0) return 3;
	else if(strcmp(temp,"��")==0) return 4;
	else if(strcmp(temp,"��")==0) return 5;
	else if(strcmp(temp,"��")==0) return 6;
	else if(strcmp(temp,"��")==0) return 7;
	else if(strcmp(temp,"��")==0) return 8;
	else if(strcmp(temp,"��")==0) return 9;
	else if(strcmp(temp,"ʮ")==0) return 10;
	else return -1;
}
