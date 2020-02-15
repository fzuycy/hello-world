#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
void start(char temp[],char num[],int*p);//
void errorstore(int n);//存无用数组和提示报错 
void operatejudge(char operate[],int*p,int*o);//判断操作关键字是否合理 
int pre(char temp[],char markname[]);//处理从第二行开始的首个字符串,进行正误判断并在必要时储存无用数组和提示报错
void calculate(int*p,int order,char num[]);//进行加减乘除运算 
int charge(int n[]);//在汉字数字转阿拉伯数字时判断汉字字符串类型并整合转化为阿拉伯数字 
void cut(char temp[],int first);//切割字符串，便于分析汉字字符串类型 
int change_1(char temp[]);//汉字数字转阿拉伯数字主体框架 
void change_2(int sum);// 将阿拉伯数字转为汉字数字
void link(int sum,int flag);
int len=strlen("一");//得到一个汉字字符长度 
char model[11][4]={"零","一","二","三","四","五","六","七","八","九","十"};
char store[10];//用于截取字符串中的单个汉字 
char index[10],op[4][5]={"增加","减少","乘","除以"};
int mark;//检测到"负"时做标记 
int main()
{
	int flag,index1,order,sum;
	char s[10],markname[10],operate[10],num[10];
	scanf("%s",s);
	scanf("%s",markname);
	start(s,num,&sum); 
	while(1){
		scanf("%s",s);
		flag=pre(s,markname);
		if(flag==1){
			index1=0;
			order=0;
			scanf("%s",operate);
			scanf("%s",num);
			operatejudge(operate,&index1,&order);
			if(index1==1) calculate(&sum,order,num);
		}
		else if(flag==-1) break;
		else continue;
	}
	if(sum<0) flag=3;
	sum=fabs(sum);
	if(sum<=10){
		if(flag==3) printf("负"); 
		change_2(sum);
	}
	else link(sum,flag);
	return 0;
}
void start(char temp[],char num[],int*p)
{
	while(1){
		scanf("%s",temp);
		if(strcmp(temp,"等于")!=0){
			scanf("%s",temp);
			printf("请正确使用赋值关键字\n");
		}
		else{
			scanf("%s",num);
			break;
		}
	}
	(*p)=change_1(num);
}
int pre(char temp[],char markname[])
{
	int i;
	char depot[10];
	if(!strcmp(temp,markname)) return 1;
	else if(!strcmp(temp,"看看")){
		scanf("%s",index);
		return -1;
	}
	else{
		errorstore(1);
		printf("出现未定义变量\n");
		return 0;
	}
}
void errorstore(int n)
{
	int i;
	char depot[10];
	for(i=1;i<=2;i++) scanf("%s",depot);
}
void operatejudge(char operate[],int*p,int*o)
{
	int i;
	for(i=0;i<4;i++) if(!strcmp(operate,op[i])){
		(*p)=1;
		(*o)=i;
		break;
	}
	if(i==4) printf("出现未定义运算关键字\n");
}
void calculate(int*p,int order,char num[])
{
	switch(order){
		case 0:(*p)+=change_1(num);break;
		case 1:(*p)-=change_1(num);break;
		case 2:(*p)*=change_1(num);break;
		case 3:(*p)=(*p)/change_1(num);break;
	}
}
int change_1(char temp[])
{
	int i,j,k=0,res,n[3];
	mark=0;
	for(i=0;i<3;i++) n[i]=0;
	for(i=0;i<strlen(temp);i+=len){
		cut(temp,i);
		if(strcmp(store,"负")==0){
			mark=1;
			continue;
		} 
		for(j=0;j<11;j++){
			if(strcmp(model[j],store)==0){
				n[k++]=j;
				break;
			}
		}
	}
	res=charge(n);
	if(mark==1) return res*(-1);
	else return res;
}
void cut(char temp[],int first)
{
	int i,j=0;
	for(i=first;i<len+first;i++){
		store[j]=temp[i];
		j++;
	}
	store[j]='\0';
}
int charge(int n[])
{
	int res;
	if(n[1]==0) return n[0];
	else if(n[0]==10){
		res=10+n[1];
		return res;
	}
	else if(n[1]==10){
		res=10*n[0]+n[2];
		return res;
	}
}
void link(int sum,int flag)
{
	if(flag==3) printf("负");
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
