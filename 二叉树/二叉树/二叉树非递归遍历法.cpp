#include<iostream>
#include<stack>
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchird, *rchild;
}BiTNode, *BiTree;


BiTNode *GoFarLeft(BiTNode *T, stack<BiTNode *> &s){
	if (T == NULL){
		return NULL;
	}
	while (T->lchird){
		s.push(T);
		T = T->lchird;//һֱ������
	}
	return T;//�ҵ�һ��û�����ӵĽڵ㣬����������������

}

void Inorder(BiTNode *T){
	stack<BiTNode *> s;
	BiTNode *t = GoFarLeft(T, s);
	while (t){
		printf("%d ", t->data);
		if (t->rchild){//������Һ����ظ�12����
			t = GoFarLeft(T->rchild, s);
		}
		else if(!s.empty()){//���û���Һ��ӣ�˵���ýڵ�����������Ҫ���ص�ջ
			t = s.top();
			s.pop();
		}
		else{
			t = NULL;
		}
	}
}

void main111(){
	system("pause");
}