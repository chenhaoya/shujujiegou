//链栈
#include <iostream>
using namespace std;
typedef char EnemType;
const int max = 7;
typedef class node
{
public:
	EnemType  data;
	class node* next;
}NODE,*PNODE;
typedef class stack
{
public:
	PNODE pTop;
	PNODE pBorrom;
}STACK,*PSTACK;
void init(PSTACK a)//初始化栈
{
	a->pTop = new NODE;
	a->pBorrom = a->pTop;
	a->pBorrom->next = NULL;
}
void push(EnemType m, PSTACK a)//入栈
{
	PNODE pNew = new NODE;
	pNew->data = m;
	if (a->pTop->next == NULL) {
		pNew->next = a->pBorrom;
		a->pTop = pNew;
	}
	else {
		pNew->next = a->pTop;
		a->pTop = pNew;
	}
}
void disstack(PSTACK a)//遍历栈中元素
{
	if (a->pBorrom == a->pTop)return;
	PNODE s = a->pTop;
	cout << "栈中元素：";
	while (s != a->pBorrom) {
		cout <<s->data << "  ";
		s = s->next;
	}
	
}
void Destruction(PSTACK p)//销毁栈
{
	PNODE s = p->pTop;
	while (s != p->pBorrom) {
		p->pTop = p->pTop->next;
		free(s);
		s = p->pTop;
	}
	p->pTop = p->pBorrom;
}
void pop(PSTACK a, EnemType* x) //出栈一个元素
{
	if (a->pBorrom == a->pTop) {
		cout << "空栈！"; return;
	}
	PNODE s = a->pTop;
	a->pTop = a->pTop->next;
	cout << "出栈元素：" << s->data << endl;
	free(s);
}
int main()
{
	EnemType val;
	STACK a;
	init(&a);
	cout << "入栈元素个数：";
	int n; cin >> n;
	EnemType m;
	for (int i = 0; i < n; i++) {
		cout << "第" << i + 1 << "个入栈元素："; cin >> m;
		push(m,&a);
	}
	disstack(&a);
	pop(&a, &val);
	disstack(&a);
	//Destruction(&a);//销毁栈
	pop(&a, &val);
	disstack(&a);
	return 0;
}
