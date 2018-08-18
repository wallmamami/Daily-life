#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1.用前序遍历和中序遍历重建二叉树
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() <= 0 || vin.size() <= 0)
			return NULL;//序列有错误
		return CreateBinTree(0, pre.size() - 1, 0, vin.size() - 1, pre, vin);
	}

	TreeNode* CreateBinTree(int startPre, int endPre, int startIn, int endIn, vector<int>& pre, vector<int>& vin)
	{
		//拿到根节点的值
		int rootVal = pre[startPre];//肯定是前序遍历的第一个

		//构建跟节点
		TreeNode* root = new TreeNode(rootVal);

		//判断是不是最后一个节点
		if (startPre == endPre)
		{
			if (startIn == endIn && pre[startPre] == vin[startIn])
			{
				return root;
			}
			else
				return NULL;//序列有错误
		}

		//在中序遍历序列中找跟节点
		int i = 0;
		for (i = startIn; i <= endIn; i++)
		{
			if (rootVal == vin[i])//找到，前面为左， 后面为右
				break;
		}
		if (vin[i] != rootVal)
			return NULL;//序列有错误

		//构建左子树
		int leftLen = i - startIn;
		if (leftLen > 0)
		{
			root->left = CreateBinTree(startPre + 1, startPre + leftLen, startIn, startIn + leftLen - 1, pre, vin);
		}
		if (leftLen < endIn - startIn)//总长度比左子树长说明右右子树
		{
			root->right = CreateBinTree(startPre + leftLen + 1, endPre, startIn + leftLen + 1, endIn, pre, vin);
		}
		return root;
	}

};

//2.树B是否为树A的子结构
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//1.先去判断跟节点是否相同
		//2.再去判断之后结构是否相同

		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;

		bool result = false;//如果跟节点相同但是其他节点不相同还要继续找
		//首先遍历树，找到与root2相等的跟节点，再去看他们的其他节点是否相同
		if (pRoot1->val == pRoot2->val)
			result = DoseTree1HasTree2(pRoot1, pRoot2);

		//如果已经发现tree1有tree2了就不用找了，否则，继续遍历tree1
		if (!result)
			//遍历左子树
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			//右子树
			result = HasSubtree(pRoot1->right, pRoot2);

		return result;
	}

	//当在tree1中找到了与tree2的跟节点相同后，用来判断后序的是否相同
	bool DoseTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//如果tree2递归完了，说明之前都相等
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;

		//跟节点相等，再去看做子树和右子树
		return DoseTree1HasTree2(pRoot1->left, pRoot2->left) && DoseTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};

//3.二叉树的镜像
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		//前序遍历二叉树
		if (pRoot == NULL)
			return;
		//保证跟节点至少有一颗子树才去镜像它
		if (pRoot->left == NULL && pRoot->right == NULL)
			return;

		stack<TreeNode*> s;
		s.push(pRoot);

		while (!s.empty())
		{
			//遍历跟节点
			TreeNode* pRoot = s.top();
			TreeNode* pTmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = pTmp;

			s.pop();//遍历完一定要出栈

			if (pRoot->right)
				s.push(pRoot->right);
			if (pRoot->left)
				s.push(pRoot->left);
		}

	}
};

//4.输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		//45327896
		int size = sequence.size();
		if (size == 0)
			return false;

		bool result = VSOfBST(sequence, size);
		return result;
	}

	bool VSOfBST(vector<int>& arr, int size)
	{
		if (size <= 0)
			return false;

		//后序遍历根结点一定时最后一个
		int root = arr[size - 1];

		//在前面去找他的左子树和右子树
		int i = 0;
		for (i = 0; i < size - 1; ++i)
		{
			if (arr[i] > root)
				break;
		}

		int j = i;//再从i的位置去找右子树,右子树如果里面有比跟节点小的，那么这个序列一定是错了
		for (j = i; j < size - 1; ++j)
		{
			if (arr[j] < root)
				return false;
		}

		//如果i>0，说明一定有左子树，且i的值位左子树的长度，再去看他左子树的序列对不对
		bool left = true;//如果没有左子树或右子树，序列也是正确的
		if (i > 0)
			left = VSOfBST(arr, i);
		//如果i<size-1说明右子树一定存在，长度为size-i-1，不包含跟节点
		bool right = true;
		if (i < size - 1)
			right = VSOfBST(arr, size - i - 1);

		return (left && right);
	}

};
class Solu {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;

		return IsBST(sequence, 0, sequence.size());
	}

	bool IsBST(vector<int>& arr, int left, int right)
	{
		if (right - left == 0)
			return true;

		//拿到跟节点
		int root = arr[right - 1];
		int i = left;
		//找到左子树序列和右子树序列
		for (i = left; i < right - 1; ++i)
		{
			if (root < arr[i])
				break;
		}

		int j = i;
		//如果右子树有比跟节点小的，那么一定错了
		for (j = i; j < right - 1; ++j)
		{
			if (arr[j] < root)
				return false;
		}

		//分别到左右子树中再去判断
		bool lefttree = IsBST(arr, left, i);
		bool righttree = IsBST(arr, i, right - 1);

		return (lefttree && righttree);
	}

};


int main()
{
	Solu s;
	vector<int> arr = { 1, 3, 7, 10, 9, 6 };
	cout << s.VerifySquenceOfBST(arr) << endl;

	return 0;
}

//5.输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为
//输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点
//所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
class Solution {
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return (vector<vector<int>>)0;
		vector<vector<int>> PATH;//存储所有值为exNumber的路径
		vector<int> path;//存储当前路径
		int CurSum = 0;
		FindPath(root, expectNumber, PATH, path, CurSum);

		return PATH;
	}

	//因为都是从根节点开始遍历，所以使用前序遍历二叉树
	void FindPath(TreeNode* root, int exNumber, vector<vector<int>>& PATH, vector<int>& path, int CurSum)
	{
		if (root == NULL)
			return;
		CurSum += root->val;
		path.push_back(root->val);

		//如果加完之后值等于输入的整数并且当前节点为叶子节点，则打印该节点并保存路径
		bool isLeaf = root->left == NULL && root->right == NULL;
		if (CurSum == exNumber && isLeaf)
		{
			//先将当前路径存储到PATH中
			PATH.push_back(path);
		}

		//如果不是叶子节点，就去遍历他的子节点
		if (root->left)
			FindPath(root->left, exNumber, PATH, path, CurSum);
		if (root->right)
			FindPath(root->right, exNumber, PATH, path, CurSum);

		//在回退到父节点之前，先从path中删除当前节点，并且CurSum减去当前值
		path.pop_back();
		CurSum -= root->val;
	}
};

//6.输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* pPre = NULL;
		Convert(pRootOfTree, pPre);

		TreeNode* pHead = pPre;
		while (pHead != NULL && pHead->left != NULL)
			pHead = pHead->left;

		return pHead;
	}

	void Convert(TreeNode* pRoot, TreeNode*& pPre)
	{
		if (pRoot == NULL)
			return;

		if (pRoot->left)
			Convert(pRoot->left, pPre);

		pRoot->left = pPre;
		if (pPre)
			pPre->right = pRoot;
		pPre = pRoot;

		if (pRoot->right)
			Convert(pRoot->right, pPre);
	}
};

//7.求树的深度
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		int left = 0;
		int right = 0;
		if (pRoot == NULL)
			return 0;

		//如果树没有左子树也没有右子树，深度就是1
		if (!pRoot->left && !pRoot->right)
			return 1;

		if (pRoot->left)
			left = TreeDepth(pRoot->left);
		if (pRoot->right)
			right = TreeDepth(pRoot->right);

		return left > right ? left + 1 : right + 1;
	}
};

//8.给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个
//结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;

		TreeLinkNode* pCur = pNode->right;
		//1.它有右节点
		if (pCur)
		{
			while (pCur->left)
				pCur = pCur->left;

			return pCur;
		}

		//2.它有父节点，并是父节点的左子树
		pCur = pNode->next;
		if (pCur && pCur->left == pNode)
			return pCur;

		//3.既没有右子树，也不是父节点的左子树
		//向上找到一个这样的节点，他是它父节点的左子树，这个节点的父节点就是下一个节点
		pCur = pNode;
		while (pCur)
		{
			TreeLinkNode* pParent = pCur->next;
			if (pParent && pParent->left == pCur)
				return pParent;
			pCur = pParent;
		}

		return NULL;

	}
};

//9.请实现一个函数，用来判断一颗二叉树是不是对称的。
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		//判断前序遍历与对称遍历(根-右-左)是否一样，要考虑最后的空指针，因为有可能所有节点的值都一样
		return isSymmetrical(pRoot, pRoot);
	}

	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//根
		if (pRoot1 == NULL && pRoot2 == NULL)//空树也是对称的
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)//如果有一个为空，另一个不为空，一定不是对称的，两个都为空前面已经返回了
			return false;

		if (pRoot1->val != pRoot2->val)
			return false;

		//左-右/右-左
		return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
	}

};

//10.请实现一个函数按照之字形打印二叉树，即第一行按照
//从左到右的顺序打印，第二层按照从右至左的顺序打印，第
//三行按照从左到右的顺序打印，其他行以此类推。

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {

		if (pRoot == NULL)
			return (vector<vector<int>>)0;

		//使用两个栈一个用来保存奇数行的子节点（子节点处于偶数行）（先左后右）
		//一个栈用来保存偶数行的子节点（先右后左）
		stack<TreeNode*> s1;//保存奇数行的子节点（偶数）
		stack<TreeNode*> s2;//保存偶数行的子节点（奇数）

		vector<vector<int>> AllLine;
		vector<int> Line;

		int line = 1;//标识奇偶
		s2.push(pRoot);

		while (!s1.empty() || !s2.empty())
		{
			TreeNode* pCur = NULL;
			if (line % 2 == 1)//奇数行
			{
				//先遍历栈中的元素,因为是奇数行，所以它的元素在s2，它的子节点是偶数行，保存在s1
				pCur = s2.top();
				s2.pop();
				Line.push_back(pCur->val);

				if (pCur->left)
					s1.push(pCur->left);
				if (pCur->right)
					s1.push(pCur->right);
			}
			else//偶数行
			{
				pCur = s1.top();
				s1.pop();

				Line.push_back(pCur->val);

				if (pCur->right)
					s2.push(pCur->right);
				if (pCur->left)
					s2.push(pCur->left);
			}

			//判断一行是否遍历完
			if (line % 2 == 1 && s2.empty())
			{
				++line;
				AllLine.push_back(Line);
				Line.clear();
			}

			else if (line % 2 == 0 && s1.empty())
			{
				++line;
				AllLine.push_back(Line);
				Line.clear();
			}

		}
		return AllLine;
	}

};

//11.给定一棵二叉搜索树，请找出其中的第k小的结点。例如， 
//（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//用非递归-栈
		if (pRoot == NULL || k <= 0)
			return 0;

		stack<TreeNode*> s;
		TreeNode* pCur = pRoot;

		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}

			pCur = s.top();
			s.pop();
			if (k == 1)
				return pCur;
			--k;

			pCur = pCur->right;
		}
		return pCur;
	}

};


//判断一棵树是否为平衡二叉树
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {

		int depth = 0;
		return IsBalanced(pRoot, depth);
	}

	//采用后序遍历，避免重复遍历节点、
	bool IsBalanced(TreeNode* pRoot, int& depth)
	{
		if (pRoot == NULL)
		{
			depth = 0;
			return true;
		}

		int left = 0;
		int right = 0;

		//在这一层判断是否为平衡二叉树之前，先去判断他的左右子树
		if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right))
		{
			int dif = left - right;
			if (dif <= 1 && dif >= -1)
			{
				depth = 1 + (left > right ? left : right);
				return true;
			}

		}

		return false;
	}

};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {

		if (pRoot == NULL)
			return true;
		int left = Depth(pRoot->left);
		int right = Depth(pRoot->right);

		if ((left - right >= -1) && (left - right <= 1))
			return true;
		return false;
	}

	int Depth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		if (pRoot->left == NULL && pRoot->right == NULL)
			return 1;

		int left = Depth(pRoot->left);
		int right = Depth(pRoot->right);

		return left > right ? left + 1 : right + 1;
	}
};




//前序遍历
void PreOrder(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	stack<TreeNode*> s;
	s.push(pRoot);

	while (!s.empty())
	{
		TreeNode* pCur = s.top();
		s.pop();
		cout << pCur->val << " ";

		if (pCur->right)
			s.push(pCur->right);
		if (pCur->left)
			s.push(pCur->left);
	}
	cout << endl;
}

//层序遍历
void LevelOrder(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	queue<TreeNode*> q;
	q.push(pRoot);

	while (!q.empty())
	{
		TreeNode* pCur = q.front();
		q.pop();
		cout << pCur->val << " ";

		if (pCur->left)
			q.push(pCur->left);
		if (pCur->right)
			q.push(pCur->right);
	}

	cout << endl;
}


//中序遍历
void InOrder(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	TreeNode* pCur = pRoot;
	stack<TreeNode*> s;

	while (pCur || !s.empty())
	{
		while (pCur)
		{
			s.push(pCur);
			pCur = pCur->left;
		}

		pCur = s.top();
		s.pop();
		cout << pCur->val << " ";

		pCur = pCur->right;
	}

	cout << endl;
}


//后序遍历
void PostOrder(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	TreeNode* pPre = NULL;
	TreeNode* pCur = pRoot;
	TreeNode* pTop = NULL;
	stack<TreeNode*> s;

	while (pCur || !s.empty())
	{
		while (pCur)
		{
			s.push(pCur);
			pCur = pCur->left;
		}
		//到这还没遍历，所以先别pop
		pTop = s.top();

		if ((pTop->right == NULL) || pPre == pTop->right)
		{
			//这里才真正遍历
			s.pop();
			cout << pTop->val << " ";
			pPre = pTop;
		}
		else
			pCur = pTop->right;
	}

	cout << endl;
}

void Create(TreeNode*& pRoot)
{
	pRoot = new TreeNode(4);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(6);
	pRoot->left->left = new TreeNode(1);
	pRoot->left->right = new TreeNode(3);
	pRoot->right->left = new TreeNode(5);
	pRoot->right->right = new TreeNode(7);
}


void TestOrder(TreeNode* pRoot)
{
	PreOrder(pRoot);
	LevelOrder(pRoot);
	InOrder(pRoot);

	PostOrder(pRoot);

	return;
}

int main()
{
	TreeNode* pRoot;
	Create(pRoot);
	TestOrder(pRoot);

	return 0;
}