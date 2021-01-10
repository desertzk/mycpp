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
		T = T->lchird;//一直往左走
	}
	return T;//找到一个没有左孩子的节点，就是中序遍历的起点

}

void Inorder(BiTNode *T){
	stack<BiTNode *> s;
	BiTNode *t = GoFarLeft(T, s);
	while (t){
		printf("%d ", t->data);
		if (t->rchild){//如果有右孩子重复12步骤
			t = GoFarLeft(T->rchild, s);
		}
		else if(!s.empty()){//如果没有右孩子，说明该节点的树放完毕需要返回弹栈
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