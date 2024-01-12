#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BinaryTreeNode
{
	int val;
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
	BTNode* node1 = BuyNode(3);
	BTNode* node2 = BuyNode(3);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(2);
	BTNode* node5 = BuyNode(3);

	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;

	return node1;
}

bool isUnivalTree(BTNode* root) {
    if (root == NULL)
    {
        return true;
    }
    int stand = root->val;
	bool left = false;
	bool right = false;
    if (root->left == NULL || stand == root->left->val)
    {
        left = isUnivalTree(root->left);
    }
    if (root->right == NULL || stand == root->right->val)
    {
        right = isUnivalTree(root->right);
    }
    return left && right;
}

int main()
{
	BTNode* root = CreateBinaryTree();
	isUnivalTree(root);
	return 0;
}