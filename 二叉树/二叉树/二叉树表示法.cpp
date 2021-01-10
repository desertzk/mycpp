//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int data=0;
	struct BiTNode *lchird, *rchild;
}BiTNode, *BiTree;

typedef struct MyStruct
{
	int Nodedata = 0;
	MyStruct *pLeft = nullptr;
	MyStruct *pRight = nullptr;

}BTree, *pBTree;

//先序遍历
void PreOrder(BiTNode *T){
	if (T!=NULL){
		printf("%d", T->data); 
		PreOrder(T->lchird);
		PreOrder(T->rchild);
	}
}

void show(BTree *proot)
{
	if (proot == nullptr)
	{
		return;
	}
	show(proot->pLeft);
	cout << "  " << proot->Nodedata << endl;
	show(proot->pRight);
	
}

//中序遍历
void MidOrder(BiTNode *T){
	if (T!=NULL){
		MidOrder(T->lchird);
		printf("%d ", T->data);
		MidOrder(T->rchild);
	}
}

//后续遍历
void RearOrder(BiTNode *T)
{
	if (T != NULL)
	{
		RearOrder(T->lchird);
		
		RearOrder(T->rchild);
		printf("%d ", T->data);
	}
}

//求叶子数量

void CountLeaf(BiTNode *T,int *gcount){
	if (T != NULL){
		if (T->lchird == NULL&&T->rchild == NULL){
			(*gcount)++;
		}
		CountLeaf(T->lchird, gcount);
		CountLeaf(T->rchild, gcount);
	}
}

//求二叉树深度
int Depth(BiTNode *T){
	int depthval = 0, depthL = 0, depthR = 0;
	if (T == NULL){
		depthval = 0;
		return depthval;
	}
	depthL=Depth(T->lchird);
	depthR = Depth(T->rchild);
	depthval = 1 + (depthL > depthR ? depthL : depthR);
	return depthval;
}


BiTNode *copyBiTree(BiTNode *T){
	BiTNode *newNode = NULL, *newlptr = NULL, *newrptr = NULL;
	if (T == NULL){
		return NULL;
	}
	if (T->lchird != NULL){
		newlptr=copyBiTree(T->lchird);
	}
	else{
		newlptr = NULL;
	}
	if (T->rchild){
		newrptr=copyBiTree(T->rchild);
	}
	else{
		newrptr = NULL;
	}

	newNode = (BiTNode *)malloc(sizeof(BiTNode));
	newNode->lchird = newlptr;
	newNode->rchild = newrptr;
	newNode->data = T->data;
	return newNode;
}

BTree * insertnode(BTree *proot, int num)
{
	if (proot == nullptr)
	{
		BTree *pnew = new BTree;
		pnew->Nodedata = num;
		proot = pnew;
	}
	else if (num <= proot->Nodedata)
	{
		proot->pLeft = insertnode(proot->pLeft, num);
	}
	else{
		proot->pRight = insertnode(proot->pRight, num);
	}
	return proot;
}


void main()
{
	BTree *pRoot = nullptr;
	for (int i = 0; i < 10; i++)
	{
		pRoot = insertnode(pRoot, i);
	}
	show(pRoot);
	cin.get();
}

void main1(){
	BiTNode b1, b2, b3, b4, b5;
	BiTNode *pNewTree = NULL;


	memset(&b1, 0, sizeof(BiTNode));
	memset(&b2, 0, sizeof(BiTNode));
	memset(&b3, 0, sizeof(BiTNode));
	memset(&b4, 0, sizeof(BiTNode));
	memset(&b5, 0, sizeof(BiTNode));
	
	b1.data = 1;
	b2.data = 2;
	b3.data = 3;
	b4.data = 4;
	b5.data = 5;

	//构建树关系
	b1.lchird= &b2;
	b1.rchild = &b3;
	b2.lchird = &b4;
	b3.lchird= &b5;
	printf("pre \n");
	PreOrder(&b1);
	printf("mid \n");
	MidOrder(&b1);
	printf("rear \n");
	RearOrder(&b1);
	int g_count = 0;
	CountLeaf(&b1,&g_count);
	printf("leaf:%d \n",g_count);

	printf("depth:%d \n", Depth(&b1));


	pNewTree=copyBiTree(&b1);



	system("pause");
}