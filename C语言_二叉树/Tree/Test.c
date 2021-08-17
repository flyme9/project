#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
typedef char TDataType;
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	TDataType data;
}TNode;
#include"Queue.h"
//前序
void PreOrder(TNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//先访问根 在访问左子树 最后访问右子树
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序
void InOrder(TNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//先访问左子树 在访问根 最后访问右子树
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//后序
void PostOrder(TNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//先访问左子树 在访问右子树 最后访问根
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
//层序遍历
void LevelOrder(TNode* root)
{
	//创建队列
	Queue q1;
	QueueInit(&q1);
	//不为空树
	if (root)
		QueuePush(&q1, root);
	//队列不为空
	while (!QueueEmpty(&q1))
	{
		//出队头
		TNode* front = QueueFront(&q1);
		QueuePop(&q1);
		printf("%c ", front->data);
		//带入下一层节点
		if (front->left)
			QueuePush(&q1, front->left);
		if (front->right)
			QueuePush(&q1, front->right);
	}
}
//计算总节点个数
int TreeSize(TNode* root)
{
	//如果为空树，返回0，否则进行递归
	return root==NULL ? 0 : (TreeSize(root->left) + TreeSize(root->right) + 1);
}
//计算叶节点个数
int TreeLeafSize(TNode* root)
{
	//空树
	if (root == NULL)
		return 0;
	//只有根节点
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int main()
{
	TNode* A = (TNode*)malloc(sizeof(TNode));
	TNode* B = (TNode*)malloc(sizeof(TNode));
	TNode* C = (TNode*)malloc(sizeof(TNode));
	TNode* D = (TNode*)malloc(sizeof(TNode));
	TNode* E = (TNode*)malloc(sizeof(TNode));
	TNode* F = (TNode*)malloc(sizeof(TNode));
	TNode* G = (TNode*)malloc(sizeof(TNode));
	TNode* H = (TNode*)malloc(sizeof(TNode));

	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	F->data = 'F';
	F->left = NULL;
	F->right = NULL;

	G->data = 'G';


	H->data = 'H';
	H->left = NULL;
	H->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	PreOrder(A);
	printf("TerrSize: %-d ", TreeSize(A));
	printf("TerrLeafSize: %d ", TreeLeafSize(A));
	printf("\n");

	InOrder(A);
	printf("TerrSize: %d ", TreeSize(A));
	printf("TerrLeafSize: %d ", TreeLeafSize(A));
	printf("\n");

	PostOrder(A);
	printf("TerrSize: %d ", TreeSize(A));
	printf("TerrLeafSize: %d ", TreeLeafSize(A));
	printf("\n");

	LevelOrder(A);
	printf("\n");

	return 0;
}