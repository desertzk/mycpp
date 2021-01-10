/* avlTree.h */

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_
#if OS==3 || OS==4  /*#if OS == VXWORKS || OS == VXWORKS_M*/
#include "semLib.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define EH_FACTOR	0
#define LH_FACTOR	1
#define RH_FACTOR	-1

#define LEFT_MINUS	0
#define RIGHT_MINUS	1

#define ORDER_LIST_WANTED

#define INSERT_PREV	0
#define INSERT_NEXT	1

#define AVL_NULL	(TREE_NODE *)0

typedef struct _AVL_TREE_NODE
{
#ifdef ORDER_LIST_WANTED
	struct _AVL_TREE_NODE *prev;
	struct _AVL_TREE_NODE *next;
#endif
	struct _AVL_TREE_NODE *tree_root;
	struct _AVL_TREE_NODE *left_child;
	struct _AVL_TREE_NODE *right_child;
	int  bf;    			    /*平衡因子；当平衡因子的绝对值大于
	                            或等于2的时候就表示树不平衡(balance_factor)*/
}TREE_NODE;

/*增加函数指针定义*/
typedef int (*PkeyCompareFunc)(TREE_NODE * , TREE_NODE *);
typedef int (*PfreeFunc)(TREE_NODE *);

typedef struct _AVL_TREE_HEADER
{
	TREE_NODE	*pTreeHeader;
#ifdef ORDER_LIST_WANTED
	TREE_NODE	*pListHeader;
	TREE_NODE	*pListTail;
#endif
	unsigned int	count;		/*AVL树里的节点总数*/
	/*int 		(*keyCompare)(TREE_NODE * , TREE_NODE *);*/
	/*int		(*free)(TREE_NODE *);*/
	PkeyCompareFunc keyCompare;
	PfreeFunc free;
#if OS==3 || OS==4 /*#if OS == VXWORKS || OS == VXWORKS_M*/
	SEM_ID		sem;
#endif
} tAVLTree;

/*extern tAVLTree *avlTreeCreate(int *keyCompareFunc,int *freeFunc);*/
extern tAVLTree *avlTreeCreate(PkeyCompareFunc, PfreeFunc);
extern int avlTreeDestroy(tAVLTree *pTree);
extern int avlTreeFlush(tAVLTree *pTree);
extern int avlTreeAdd(tAVLTree *pTree , TREE_NODE *pInsertNode);
extern int avlTreeDel(tAVLTree *pTree ,TREE_NODE *pDelNode);
extern int avlTreeUpdate(tAVLTree *pTree ,TREE_NODE *pUpdateNode);
extern TREE_NODE *avlTreeFind(tAVLTree *pTree,TREE_NODE *pKeyNode);
extern unsigned int avlTreeCount(tAVLTree *pTree);
#ifdef ORDER_LIST_WANTED
extern TREE_NODE *avlTreeFirst(tAVLTree *pTree);
extern TREE_NODE *avlTreeLast(tAVLTree *pTree);
extern TREE_NODE *avlTreeNext(TREE_NODE *pNode);
extern TREE_NODE *avlTreePrev(TREE_NODE *pNode);
#endif
extern void AVL_TREE_LOCK(tAVLTree *pTree,int timeout);
extern void AVL_TREE_UNLOCK(tAVLTree *pTree);
extern void AVL_TREENODE_FREE(tAVLTree *pTree,TREE_NODE *pNode);
#endif
