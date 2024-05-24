#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>

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

BTNode* BinaryTreeCreate(BTDataType* pre, int pstart, int pend, BTDataType* in, int istart, int iend)
{
	//if (a[*pi] == '#')
	//{
	//	(*pi)++;
	//	return NULL;
	//}
	if (pstart > pend || istart > iend)
	{
		return NULL;
	}

	BTNode* root = BuyNode(*(pre + pstart));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int leftsize = 0, rightsize = 0;
	for (int i = istart; i <= iend; i++)
	{
		if (in[i] == *(pre + pstart))
		{
			leftsize = i - istart;
			rightsize = iend - i;
			break;
		}
	}

	root->left = BinaryTreeCreate(pre, pstart + 1, pstart + leftsize, in, istart, istart + leftsize - 1);
	root->right = BinaryTreeCreate(pre, pend - rightsize + 1, pend, in, iend - rightsize + 1, iend);
	return root;
}
// 二叉树前序遍历 
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
// 二叉树中序遍历
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
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("# ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c", root->data);
}
int main()
{
	char arr1[] = { "FDXEAG" };
	char arr2[] = { "XDEFAG" };
	//scanf("%s", arr);
	int count = 0;
	BTNode* root = BinaryTreeCreate(arr1, 0, sizeof(arr1) / sizeof(arr1[0]) - 1, arr2, 0, sizeof(arr2) / sizeof(arr2[0]) - 1);
	//BinaryTreePrevOrder(root);
	//BinaryTreeInOrder(root);
	BinaryTreePostOrder(root);
}