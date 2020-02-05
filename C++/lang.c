#include<stdio.h>
#include<string.h>
void operatejudge(char operate[10],int*p);
void varyjudge(char markname[10],char varyname[10],int*p); 
void numberjudge(char temp[10],int* p);
int change_1(char temp[10]);
void change_2(int sum);
void link(int sum);
int main()
{//用operate统一储存操作 
	char markname[10],store[10],depot[10],varyname[10],operate[10],number[10];
	int sum,flag=0,index1,index2,aid;//辅助 
	scanf("%s",store);
	scanf("%s",markname);
	scanf("%s",store); 
	while(flag==0){
		scanf("%s",number);
		numberjudge(number,&flag);
	}
	sum=change_1(number);
	while(1){
		scanf("%s",store);
		if(strcmp(store,markname)!=0&&strcmp(store,"看看")!=0){
            scanf("%s",depot);
            scanf("%s",depot);
			printf("出现未定义变量\n");
		}
		else{
			if(strcmp(store,markname)==0){
				    index1=1;
				    index2=1;
				    scanf("%s",operate);
				    scanf("%s",number);
				    operatejudge(operate,&index1);
				    numberjudge(number,&index2);
				    if(index1+index2==2){
					    if(strcmp(operate,"增加")==0) sum=sum+change_1(number);
					    else{
					    	aid=sum-change_1(number);
							if(aid<0){
								printf("数额输入过大\n"); 
							}
							else sum=aid;
						}
				    }
	        }
	        else if(strcmp(store,"看看")==0){
                break;
	        }
		}
	}
	flag=1;
	do{
		scanf("%s",varyname);
	    varyjudge(markname,varyname,&flag);
	}while(flag==0);
	if(sum<=10) change_2(sum);
	else link(sum);
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
void numberjudge(char temp[10],int* p)
{
	if(change_1(temp)==-1){
		printf("输入的数额无效\n");
		*p=0;
	}
	else *p=1;
}
void varyjudge(char markname[10],char varyname[10],int*p)
{
	if(strcmp(markname,varyname)==0) *p=1;
	else{
		printf("出现了未定义变量\n");
		*p=0;
	} 
}
void operatejudge(char operate[10],int*p)//默认不检查“看看”操作 
{
    if(strcmp(operate,"增加")==0) *p=1;
	else if(strcmp(operate,"减少")==0) *p=1;
	else{
		printf("出现了未定义操作\n");
		*p=0;
	} 
}
void link(int sum)
{
	if((sum/10)>1) change_2(sum/10);
	printf("十");
	if((sum%10)!=0) change_2(sum%10); 
}
void change_2(int sum)
{
	switch(sum){
	    case 0:printf("零");break;
		case 1:printf("一");break;
		case 2:printf("二");break;
		case 3:printf("三");break;
		case 4:printf("四");break;
		case 5:printf("五");break;
		case 6:printf("六");break;
		case 7:printf("七");break;
		case 8:printf("八");break;
		case 9:printf("九");break;
		case 10:printf("十");break; 		
	}
}