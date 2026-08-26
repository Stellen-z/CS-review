#include <iostream>
#include <algorithm>


typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}

void MidOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	MidOrder(root->left);
	printf("%d ", root->data);
	MidOrder(root->right);
}

//不能使用局部静态变量
//int TreeSize(BTNode* root)
//{
//	//静态变量只会被初始化一次，多次调用实际上是在第一次的基础上进行累加
//	static int size = 0;
//	if (root == NULL) return 0;
//	else ++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//改成全局静态即可，每次调用前显式初始化
//static int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL) return 0;
//	else ++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

int TreeSize(BTNode* root)
{
	//if (root == NULL) return 0;

	//int left = TreeSize(root->left);
	//int right = TreeSize(root->right);

	//return left + right + 1;

	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1; 
}


int TreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;

	if (root->left == NULL && root->right == NULL) return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL) return 0;

	return std::max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

int main()        
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");

	MidOrder(root);
	printf("\n");

	//size = 0;
	//printf("%d\n", TreeSize(root));

	//size = 0;
	//printf("%d\n", TreeSize(root));

	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));


	return 0;
}