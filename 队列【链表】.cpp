//链队
#include <iostream>
using namespace std;
typedef char ElemType;
typedef class node
{
public:
	ElemType data;
	class node* Next;
}NODE;
typedef class queue
{
public:
	NODE* front;
	NODE* rear;
}QUEUE;
void  init(QUEUE* s)
{
	s->front = s->rear = NULL;
	
}
void push(QUEUE* s, ElemType val)
{
	NODE * New = new NODE;
	New->data = val;
	if (s->front == NULL && s->rear == NULL){
		s->front = s->rear = New;
		New->Next = NULL;
	}
	else {
		s->rear->Next = New;
		s->rear = New;
		New->Next = NULL;
	}
}
bool empty(QUEUE* s)
{
	if (s->rear != NULL || s->front != NULL)
		return true;
	else return false;
}
void pop(QUEUE* s)
{
	if (empty(s)) {
		NODE* a;
		a = s->front;
		s->front = s->front->Next;
		cout << "出队元素：" << a->data << endl;
		free(a);
	}
	else cout << "出队失败，空队！" << endl;

}
void Disq(QUEUE* s)
{
	if (empty(s)) {
		NODE * a = s->front;
		while (a->Next != NULL) {
			cout << a->data<<"  ";
			a = a->Next;
		}
	}
}
int main()
{
	QUEUE S;
	init(&S);//初始化队列
	push(&S, 'a'); push(&S, 'b'); push(&S, 'c'); push(&S, 'd'); push(&S, 'e'); push(&S, 'f');//入队
	Disq(&S);//遍历队中元素
	pop(&S);//出队
	cout << endl;
	Disq(&S);
	return 0;
}
