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
//ǰ��
void PreOrder(TNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//�ȷ��ʸ� �ڷ��������� ������������
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//����
void InOrder(TNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//�ȷ��������� �ڷ��ʸ� ������������
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//����
void PostOrder(TNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//�ȷ��������� �ڷ��������� �����ʸ�
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
//�������
void LevelOrder(TNode* root)
{
	//��������
	Queue q1;
	QueueInit(&q1);
	//��Ϊ����
	if (root)
		QueuePush(&q1, root);
	//���в�Ϊ��
	while (!QueueEmpty(&q1))
	{
		//����ͷ
		TNode* front = QueueFront(&q1);
		QueuePop(&q1);
		printf("%c ", front->data);
		//������һ��ڵ�
		if (front->left)
			QueuePush(&q1, front->left);
		if (front->right)
			QueuePush(&q1, front->right);
	}
}
//�����ܽڵ����
int TreeSize(TNode* root)
{
	//���Ϊ����������0��������еݹ�
	return root==NULL ? 0 : (TreeSize(root->left) + TreeSize(root->right) + 1);
}
//����Ҷ�ڵ����
int TreeLeafSize(TNode* root)
{
	//����
	if (root == NULL)
		return 0;
	//ֻ�и��ڵ�
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