#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>

#include"queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
//{
//	BTNode* tmp = NULL;
//	if (*(a + *pi) == '#')
//	{
//		(*pi)++;
//		return NULL;
//	}
// 	if (*(a + *pi) != '#')
//	{
//		tmp = BuyNode(*(a + *pi));
//		(*pi)++;
//		tmp->left = BinaryTreeCreate(a, pi);
//		tmp->right = BinaryTreeCreate(a, pi);
//	}
//	return tmp;
//}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = BuyNode(*(a + *pi));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	root->data = a[(*pi)++];

	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}


// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->left == NULL && root->right == NULL ? 1 : BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* tmp = BinaryTreeFind(root->left, x);
	if (tmp != NULL)
	{
		return tmp;
	}
	return BinaryTreeFind(root->right, x);
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* first = QueueFront(&q);
		QueuePop(&q);
		if (first != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

int main()
{
	char arr[18] = "ABD##E#H##CF##G##";
	int count = 0;
	BTNode* root = BinaryTreeCreate(arr, &count);
	
	printf("PrevOrder: ");
	BinaryTreePrevOrder(root);
	printf("\n");
	
	printf("InOrder:   ");
	BinaryTreeInOrder(root);
	printf("\n");
	
	printf("PostOrder: ");
	BinaryTreePostOrder(root);
	printf("\n");

	printf("LevelOrder: ");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root,3));

	printf("BinaryTreeFind:%p\n", BinaryTreeFind(root,'E'));
	printf("BinaryTreeFind:%p\n", BinaryTreeFind(root,'F'));
	printf("BinaryTreeFind:%p\n", BinaryTreeFind(root,'C'));

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(root));

	BinaryTreeDestory(&root);
	return 0;
}