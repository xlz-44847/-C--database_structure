#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

BTNode* CreateBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node6->right = node7;
	node7->right = node8;

	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	}
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
	//int leftheight = TreeHeight(root->left);
	//int rightheight = TreeHeight(root->right);
	//return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}

int TreeLevelK(BTNode* root, int k)
{
	assert(k > 0);
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
		return TreeLevelK(root->left, k - 1) + TreeLevelK(root->right, k - 1);
	}
}

int main()
{
	BTNode* root = CreateBinaryTree();
	
	//遍历
	//1、前序遍历 root left right
	PrevOrder(root);
	printf("\n");
	//2、中序遍历 left root right
	InOrder(root);
	printf("\n");
	//3、后序遍历 left right root
	PostOrder(root);
	printf("\n");

	//结点个数
	printf("TreeSize:%d\n", TreeSize(root));

	//叶子结点个数
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));

	//树高
	printf("TreeHeight:%d\n", TreeHeight(root));

	//k层结点个数
	printf("TreeLevelK:%d\n", TreeLevelK(root, 4));
	return 0;
}