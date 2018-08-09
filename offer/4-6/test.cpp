#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//4.输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

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

 //5.用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 class Solution
 {
 public:
	 void push(int node) {
		 //stack1用来插入元素
		 stack1.push(node);
	 }

	 int pop() {

		 if (stack2.size() == 0)
		 {
			 if (stack1.size() == 0)
				 return 0;
			 else
			 {
				 int size = stack1.size();
				 for (int i = 0; i < size; ++i)//!!不能这样，因为这样size一直在变i < stack1.size(); ++i)
				 {
					 int node = stack1.top();
					 stack1.pop();
					 stack2.push(node);
				 }
			 }
		 }

		 int top = stack2.top();
		 stack2.pop();

		 return top;
	 }

 private:
	 stack<int> stack1;
	 stack<int> stack2;
 };

 //6.把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

 class Solution {
 public:
	 int minNumberInRotateArray(vector<int> rotateArray) {
		 int size = rotateArray.size();
		 vector<int>& v = rotateArray;
		 if (size <= 0)
			 return 0;
		 int left = 0;
		 int right = size - 1;
		 int mid = left;

		 while (v[left] >= v[right])//避免旋转之后还是原来的1，2，3， 4， 5
		 {
			 if (right - left == 1)
			 {
				 mid = right;
				 break;
			 }
			 mid = (left + right) / 2;
			 //有可能数组里面有重复的数字或者只有一个数字
			 //这种情况只能顺序查找，如1，1，1，1，0，1
			 if (v[left] == v[mid] && v[mid] == v[right])
			 {
				 return MinNumber(v, left, right);
			 }
			 if (v[mid] >= v[left])//说明mid在值较大的子数组里面
				 left = mid;
			 else if (v[mid] <= v[right])
				 right = mid;
		 }
		 return v[mid];
	 }

	 int MinNumber(vector<int> v, int left, int right)
	 {
		 int i = left;
		 int min = v[left];
		 for (; i <= right; ++i)
		 {
			 if (v[i] < min)
				 min = v[i];
		 }
		 return min;
	 }

 };
 int main()
 {
	 string s = "ada";

	 cout << s.c_str() << endl;

	 return 0;
 }