//循环链表

#include <iostream>
using namespace std;
typedef char  EnemType;
typedef class Node  //表结构
{
public:
	EnemType data;
	class Node * front;
	class Node * next;
}NODE ,*PNODE;
bool creatnode(EnemType m,PNODE p) //开始插入各元素
{
	PNODE pNew = new NODE;
	pNew->data = m;
	if (p->front ==NULL&&NULL== p->next){//如果是空表插入时
		p->next = pNew;
		p->front = pNew;
		pNew->front = p;
		pNew->next = p;
	}
	else {								//不是空表插入操作
		p->front->next = pNew;
		pNew->front= p->front;
		p->front = pNew;
		pNew->next = p;
	}
	if (pNew)
		return true;
	else return false;
}
void disnode(PNODE p)//遍历表元素
{
	if (p->next == NULL)return;
	PNODE s = p->next;
	while (s != p) {
		cout << s->data << "   ";
		s = s->next;
	}

}
void Destruction(PNODE p)//销毁表
{
	
	PNODE s = p->next;
	PNODE i;
	while (s != p) {
		i = s;
		s = s->next;
		free(i);
	}
	p->front = p->next = NULL;
}
int main()
{
	PNODE h;
	h = new NODE;
	h->front = h->next = NULL;


	int n = 0;
	cin >> n;
	EnemType m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		creatnode(m, h);
	}
	disnode(h);
	Destruction(h);
	cout << endl;
	disnode(h);
	return 0;
}
