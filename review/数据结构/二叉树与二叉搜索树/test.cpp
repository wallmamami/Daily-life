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

//1.��ǰ���������������ؽ�������
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() <= 0 || vin.size() <= 0)
			return NULL;//�����д���
		return CreateBinTree(0, pre.size() - 1, 0, vin.size() - 1, pre, vin);
	}

	TreeNode* CreateBinTree(int startPre, int endPre, int startIn, int endIn, vector<int>& pre, vector<int>& vin)
	{
		//�õ����ڵ��ֵ
		int rootVal = pre[startPre];//�϶���ǰ������ĵ�һ��

		//�������ڵ�
		TreeNode* root = new TreeNode(rootVal);

		//�ж��ǲ������һ���ڵ�
		if (startPre == endPre)
		{
			if (startIn == endIn && pre[startPre] == vin[startIn])
			{
				return root;
			}
			else
				return NULL;//�����д���
		}

		//����������������Ҹ��ڵ�
		int i = 0;
		for (i = startIn; i <= endIn; i++)
		{
			if (rootVal == vin[i])//�ҵ���ǰ��Ϊ�� ����Ϊ��
				break;
		}
		if (vin[i] != rootVal)
			return NULL;//�����д���

		//����������
		int leftLen = i - startIn;
		if (leftLen > 0)
		{
			root->left = CreateBinTree(startPre + 1, startPre + leftLen, startIn, startIn + leftLen - 1, pre, vin);
		}
		if (leftLen < endIn - startIn)//�ܳ��ȱ���������˵����������
		{
			root->right = CreateBinTree(startPre + leftLen + 1, endPre, startIn + leftLen + 1, endIn, pre, vin);
		}
		return root;
	}

};

//2.��B�Ƿ�Ϊ��A���ӽṹ
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//1.��ȥ�жϸ��ڵ��Ƿ���ͬ
		//2.��ȥ�ж�֮��ṹ�Ƿ���ͬ

		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;

		bool result = false;//������ڵ���ͬ���������ڵ㲻��ͬ��Ҫ������
		//���ȱ��������ҵ���root2��ȵĸ��ڵ㣬��ȥ�����ǵ������ڵ��Ƿ���ͬ
		if (pRoot1->val == pRoot2->val)
			result = DoseTree1HasTree2(pRoot1, pRoot2);

		//����Ѿ�����tree1��tree2�˾Ͳ������ˣ����򣬼�������tree1
		if (!result)
			//����������
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			//������
			result = HasSubtree(pRoot1->right, pRoot2);

		return result;
	}

	//����tree1���ҵ�����tree2�ĸ��ڵ���ͬ�������жϺ�����Ƿ���ͬ
	bool DoseTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//���tree2�ݹ����ˣ�˵��֮ǰ�����
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;

		//���ڵ���ȣ���ȥ����������������
		return DoseTree1HasTree2(pRoot1->left, pRoot2->left) && DoseTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};

//3.�������ľ���
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		//ǰ�����������
		if (pRoot == NULL)
			return;
		//��֤���ڵ�������һ��������ȥ������
		if (pRoot->left == NULL && pRoot->right == NULL)
			return;

		stack<TreeNode*> s;
		s.push(pRoot);

		while (!s.empty())
		{
			//�������ڵ�
			TreeNode* pRoot = s.top();
			TreeNode* pTmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = pTmp;

			s.pop();//������һ��Ҫ��ջ

			if (pRoot->right)
				s.push(pRoot->right);
			if (pRoot->left)
				s.push(pRoot->left);
		}

	}
};

//4.����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����

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

		//������������һ��ʱ���һ��
		int root = arr[size - 1];

		//��ǰ��ȥ��������������������
		int i = 0;
		for (i = 0; i < size - 1; ++i)
		{
			if (arr[i] > root)
				break;
		}

		int j = i;//�ٴ�i��λ��ȥ��������,��������������бȸ��ڵ�С�ģ���ô�������һ���Ǵ���
		for (j = i; j < size - 1; ++j)
		{
			if (arr[j] < root)
				return false;
		}

		//���i>0��˵��һ��������������i��ֵλ�������ĳ��ȣ���ȥ���������������жԲ���
		bool left = true;//���û����������������������Ҳ����ȷ��
		if (i > 0)
			left = VSOfBST(arr, i);
		//���i<size-1˵��������һ�����ڣ�����Ϊsize-i-1�����������ڵ�
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

		//�õ����ڵ�
		int root = arr[right - 1];
		int i = left;
		//�ҵ����������к�����������
		for (i = left; i < right - 1; ++i)
		{
			if (root < arr[i])
				break;
		}

		int j = i;
		//����������бȸ��ڵ�С�ģ���ôһ������
		for (j = i; j < right - 1; ++j)
		{
			if (arr[j] < root)
				return false;
		}

		//�ֱ�������������ȥ�ж�
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

//5.����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ
//��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ���
//�������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
class Solution {
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return (vector<vector<int>>)0;
		vector<vector<int>> PATH;//�洢����ֵΪexNumber��·��
		vector<int> path;//�洢��ǰ·��
		int CurSum = 0;
		FindPath(root, expectNumber, PATH, path, CurSum);

		return PATH;
	}

	//��Ϊ���ǴӸ��ڵ㿪ʼ����������ʹ��ǰ�����������
	void FindPath(TreeNode* root, int exNumber, vector<vector<int>>& PATH, vector<int>& path, int CurSum)
	{
		if (root == NULL)
			return;
		CurSum += root->val;
		path.push_back(root->val);

		//�������֮��ֵ����������������ҵ�ǰ�ڵ�ΪҶ�ӽڵ㣬���ӡ�ýڵ㲢����·��
		bool isLeaf = root->left == NULL && root->right == NULL;
		if (CurSum == exNumber && isLeaf)
		{
			//�Ƚ���ǰ·���洢��PATH��
			PATH.push_back(path);
		}

		//�������Ҷ�ӽڵ㣬��ȥ���������ӽڵ�
		if (root->left)
			FindPath(root->left, exNumber, PATH, path, CurSum);
		if (root->right)
			FindPath(root->right, exNumber, PATH, path, CurSum);

		//�ڻ��˵����ڵ�֮ǰ���ȴ�path��ɾ����ǰ�ڵ㣬����CurSum��ȥ��ǰֵ
		path.pop_back();
		CurSum -= root->val;
	}
};

//6.����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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

//7.���������
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		int left = 0;
		int right = 0;
		if (pRoot == NULL)
			return 0;

		//�����û��������Ҳû������������Ⱦ���1
		if (!pRoot->left && !pRoot->right)
			return 1;

		if (pRoot->left)
			left = TreeDepth(pRoot->left);
		if (pRoot->right)
			right = TreeDepth(pRoot->right);

		return left > right ? left + 1 : right + 1;
	}
};

//8.����һ�������������е�һ����㣬���ҳ��������˳�����һ��
//��㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
		//1.�����ҽڵ�
		if (pCur)
		{
			while (pCur->left)
				pCur = pCur->left;

			return pCur;
		}

		//2.���и��ڵ㣬���Ǹ��ڵ��������
		pCur = pNode->next;
		if (pCur && pCur->left == pNode)
			return pCur;

		//3.��û����������Ҳ���Ǹ��ڵ��������
		//�����ҵ�һ�������Ľڵ㣬���������ڵ��������������ڵ�ĸ��ڵ������һ���ڵ�
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

//9.��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		//�ж�ǰ�������ԳƱ���(��-��-��)�Ƿ�һ����Ҫ�������Ŀ�ָ�룬��Ϊ�п������нڵ��ֵ��һ��
		return isSymmetrical(pRoot, pRoot);
	}

	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//��
		if (pRoot1 == NULL && pRoot2 == NULL)//����Ҳ�ǶԳƵ�
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)//�����һ��Ϊ�գ���һ����Ϊ�գ�һ�����ǶԳƵģ�������Ϊ��ǰ���Ѿ�������
			return false;

		if (pRoot1->val != pRoot2->val)
			return false;

		//��-��/��-��
		return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
	}

};

//10.��ʵ��һ����������֮���δ�ӡ������������һ�а���
//�����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ����
//���а��մ����ҵ�˳���ӡ���������Դ����ơ�

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {

		if (pRoot == NULL)
			return (vector<vector<int>>)0;

		//ʹ������ջһ���������������е��ӽڵ㣨�ӽڵ㴦��ż���У���������ң�
		//һ��ջ��������ż���е��ӽڵ㣨���Һ���
		stack<TreeNode*> s1;//���������е��ӽڵ㣨ż����
		stack<TreeNode*> s2;//����ż���е��ӽڵ㣨������

		vector<vector<int>> AllLine;
		vector<int> Line;

		int line = 1;//��ʶ��ż
		s2.push(pRoot);

		while (!s1.empty() || !s2.empty())
		{
			TreeNode* pCur = NULL;
			if (line % 2 == 1)//������
			{
				//�ȱ���ջ�е�Ԫ��,��Ϊ�������У���������Ԫ����s2�������ӽڵ���ż���У�������s1
				pCur = s2.top();
				s2.pop();
				Line.push_back(pCur->val);

				if (pCur->left)
					s1.push(pCur->left);
				if (pCur->right)
					s1.push(pCur->right);
			}
			else//ż����
			{
				pCur = s1.top();
				s1.pop();

				Line.push_back(pCur->val);

				if (pCur->right)
					s2.push(pCur->right);
				if (pCur->left)
					s2.push(pCur->left);
			}

			//�ж�һ���Ƿ������
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

//11.����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 
//��5��3��7��2��4��6��8���У��������ֵ��С˳�����С����ֵΪ4��
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//�÷ǵݹ�-ջ
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


//�ж�һ�����Ƿ�Ϊƽ�������
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {

		int depth = 0;
		return IsBalanced(pRoot, depth);
	}

	//���ú�������������ظ������ڵ㡢
	bool IsBalanced(TreeNode* pRoot, int& depth)
	{
		if (pRoot == NULL)
		{
			depth = 0;
			return true;
		}

		int left = 0;
		int right = 0;

		//����һ���ж��Ƿ�Ϊƽ�������֮ǰ����ȥ�ж�������������
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




//ǰ�����
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

//�������
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


//�������
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


//�������
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
		//���⻹û�����������ȱ�pop
		pTop = s.top();

		if ((pTop->right == NULL) || pPre == pTop->right)
		{
			//�������������
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