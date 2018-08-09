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

//4.����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

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

 //5.������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
 class Solution
 {
 public:
	 void push(int node) {
		 //stack1��������Ԫ��
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
				 for (int i = 0; i < size; ++i)//!!������������Ϊ����sizeһֱ�ڱ�i < stack1.size(); ++i)
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

 //6.��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء�
// ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

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

		 while (v[left] >= v[right])//������ת֮����ԭ����1��2��3�� 4�� 5
		 {
			 if (right - left == 1)
			 {
				 mid = right;
				 break;
			 }
			 mid = (left + right) / 2;
			 //�п��������������ظ������ֻ���ֻ��һ������
			 //�������ֻ��˳����ң���1��1��1��1��0��1
			 if (v[left] == v[mid] && v[mid] == v[right])
			 {
				 return MinNumber(v, left, right);
			 }
			 if (v[mid] >= v[left])//˵��mid��ֵ�ϴ������������
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