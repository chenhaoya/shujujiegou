//汉诺塔
#include <iostream>
using namespace std;
void hnt(int, char, char, char);
int main()
{
	int n;
	cin >> n;
	char a='A', b='B', c='C';
	hnt(n,a,b,c);
	return 0;
}
void hnt(int n, char a, char b, char c)
{
	/*
		if：退化情况
			直接将A柱子上的盘子移动到C柱子上-----------【0】
		else
			将A柱子上的n-1个盘子借助C柱子移动到B柱子---【1】
			再将A柱子上的盘子移动到C柱子上-------------【2】
			最后将B柱子上的盘子借助A柱子移动到C柱子----【3】
	*/
	if (n == 1)	
		cout << "将编号为：" << n << "的盘子从"<<a<<"柱子上的盘子移动到"<<c<<"柱子上"<<endl;//【0】
	else {
		hnt(n - 1, a, c, b);//1
		cout << "将编号为：" << n << "的盘子从" << a << "柱子上的盘子移动到" << c << "柱子上"<<endl;//2
		hnt(n - 1, b, a, c);//3

	}
}
