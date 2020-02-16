#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
void start(char temp[],char num[],int*p);//
void errorstore(int n);//�������������ʾ���� 
void operatejudge(char operate[],int*p,int*o);//�жϲ����ؼ����Ƿ���� 
int pre(char temp[],char markname[]);//����ӵڶ��п�ʼ���׸��ַ���,���������жϲ��ڱ�Ҫʱ���������������ʾ����
void calculate(int*p,int order,char num[]);//���мӼ��˳����� 
int charge(int n[]);//�ں�������ת����������ʱ�жϺ����ַ������Ͳ�����ת��Ϊ���������� 
void cut(char temp[],int first);//�и��ַ��������ڷ��������ַ������� 
int change_1(char temp[]);//��������ת���������������� 
void change_2(int sum);// ������������תΪ��������
void link(int sum,int flag);
int len=strlen("һ");//�õ�һ�������ַ����� 
char model[11][4]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
char store[10];//���ڽ�ȡ�ַ����еĵ������� 
char index[10],op[4][5]={"����","����","��","����"};
int mark;//��⵽"��"ʱ����� 
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
		if(flag==3) printf("��"); 
		change_2(sum);
	}
	else link(sum,flag);
	return 0;
}
void start(char temp[],char num[],int*p)
{
	while(1){
		scanf("%s",temp);
		if(strcmp(temp,"����")!=0){
			scanf("%s",temp);
			printf("����ȷʹ�ø�ֵ�ؼ���\n");
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
	else if(!strcmp(temp,"����")){
		scanf("%s",index);
		return -1;
	}
	else{
		errorstore(1);
		printf("����δ�������\n");
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
	if(i==4) printf("����δ��������ؼ���\n");
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
		if(strcmp(store,"��")==0){
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
	if(flag==3) printf("��");
	if((sum/10)>1) change_2(sum/10);
	printf("ʮ");
	if((sum%10)!=0) change_2(sum%10); 
}
void change_2(int sum)
{
	switch(sum){
	    case 0:printf("��");break;
		case 1:printf("һ");break;
		case 2:printf("��");break;
		case 3:printf("��");break;
		case 4:printf("��");break;
		case 5:printf("��");break;
		case 6:printf("��");break;
		case 7:printf("��");break;
		case 8:printf("��");break;
		case 9:printf("��");break;
		case 10:printf("ʮ");break; 		
	}
}
