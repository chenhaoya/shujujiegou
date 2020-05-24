//KMP算法
#include <stdio.h>
#include <iostream>
using namespace std;
#define MaxSize 100 //const int MaxSize=100;
typedef struct
{
	char data[MaxSize];
	int length;			//串长
} SqString;
void StrAssign(SqString& s, char cstr[])//s为引用型参数
{//生成一个与cstr[]等值的串				//生成串
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;						//给出串长
}
void GetNext(SqString t,int next[])		//由模式串t求出next值
{
	int j,k;			
	j=0;k=-1;	//j扫描t,k记录t[j]之前开头与t开头相同的字符个数
	next[0]=-1;//设置next[0]值
	while (j<t.length-1) //求t所有位置的next值
	{	
		if (k==-1 || t.data[j]==t.data[k]) 	//k为-1或比较的字符相等时
		{	
			j++;k++;//j、k一次移动到下一个字符
			next[j]=k;//设置next[j]为k
			printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,k);
       	}
       	else
		{
			k=next[k];//k退回
			printf("(2) k=%d\n",k);
		}
	}
}
int KMPIndex(SqString s,SqString t)  //KMP算法
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);

	while (i<s.length && j<t.length) 
	{
		if (j==-1 || s.data[i]==t.data[j]) 
		{
			i++;j++;  			//i,j各增1
		}
		else j=next[j]; 		//i不变,j后退
    }
    if (j>=t.length)			//匹配成功
		return(i-t.length);  	//返回匹配模式串的首字符下标
    else						//匹配不成功
		return(-1);        		//返回不匹配标志
}
void DispStr(SqString s)	//输出串s
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
			printf("%c", s.data[i]);
		printf("\n");
	}
}

int main()
{
	SqString s,t;
	char T[] = { "ababcabcacbab" };
	char D[] = { "abcac" };
	StrAssign(s,T);
	StrAssign(t,D);
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("位置:%d\n",KMPIndex(s,t));
	return 1;
}
