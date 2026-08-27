#include <iostream>
#include <algorithm>
#include <queue>

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

	printf("2:%p", node2);

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

//节点个数
int TreeSize(BTNode* root)
{
	//if (root == NULL) return 0;

	//int left = TreeSize(root->left);
	//int right = TreeSize(root->right);

	//return left + right + 1;

	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1; 
}

//叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;

	if (root->left == NULL && root->right == NULL) return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//树高
int TreeHeight(BTNode* root)
{
	if (root == NULL) return 0;

	return std::max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

//第k层节点个数 
int TreeLevelKSize(BTNode* root,int k)
{
	if (root == NULL) return 0;

	if (k == 1) return 1;

	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
	
}

//查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL) return NULL;

	if (root->data == x) return root;

	//左边找到了，不需要去右边找
	//BTNode* _left = TreeFind(root->left, x);
	//BTNode* _right = TreeFind(root->right, x);
	
	BTNode* _left = TreeFind(root->left, x);
	if (_left) return _left;
	return TreeFind(root->right, x);

}

//二叉树的销毁
void TreeDestroy(BTNode* root)
{
	if (root == NULL) return;

	TreeDestroy(root->left);
	TreeDestroy(root->right);

	free(root);
}	

//层序遍历
void TreeLevelOrder(BTNode* root)
{
	std::queue<BTNode*> q;

	if(root) q.push(root);

	while (!q.empty())
	{
		BTNode* front = q.front();
		q.pop();

		std::cout << front->data << " ";

		if (front->left) q.push(front->left);
		if (front->right) q.push(front->right);
	}
	std::cout << std::endl;
}

//判断是否完全二叉树
//层序+入空节点
bool TreeCompleted(BTNode* root)
{
	std::queue<BTNode*> q;

	if (root) q.push(root);

	while (!q.empty())
	{
		BTNode* front = q.front();

		//遇到第一个空就可以进行判断，如果有非空，就不是完全二叉树
		//因为空之前的非空的孩子全部都进入队列
		if (front == NULL)
		{
			break;
		}

		q.pop();

		q.push(front->left);
		q.push(front->right);
	}
	//判断是否有非空
	while (!q.empty())
	{
		BTNode* front = q.front();
		q.pop();

		if (front) return false;
	}
	return true;
}

//bool TreeCompleted(BTNode* root)
//{
//	std::queue<BTNode*> q;
//
//	if (root) q.push(root);
//
//	while (!q.empty())
//	{
//		BTNode* front = q.front();
//		q.pop();
//
//		//遇到第一个空就可以进行判断，如果有非空，就不是完全二叉树
//		//因为空之前的非空的孩子全部都进入队列
//		if (front == NULL)
//		{
//			while (!q.empty())
//			{
//				BTNode* front = q.front();
//				q.pop();
//
//				if (front) return false;
//			}
//			return true;
//		}
//
//		q.push(front->left);
//		q.push(front->right);
//	}
//	return true;
//}

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
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(root,4));
	printf("TreeFind:%p\n", TreeFind(root, 2));
	TreeLevelOrder(root);
	std::cout << TreeCompleted(root) << std::endl;

	return 0;
}