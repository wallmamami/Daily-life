#include <vector>
#include <set>
#include <iostream>
#include <deque>

using namespace std;



//1.��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		
		//�����Ͻǿ�ʼ��
		int row = 0;
		int col = array[0].size() - 1;

		while (row >= 0 && row < array.size() && col >= 0 && col < array[0].size() - 1)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				col -= 1;
			else
				row += 1;
		}

		return false;
	}
};

//2.��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬
//���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

class Solution {
public:
	void replaceSpace(char *str, int length) {

		//�ȼ����Դ�ַ���һ���м����ո�
		int count = 0;

		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
				++count;
		}

		if (count == 0)
			return;

		int index = length + 2 * count;
		for (int i = length; i >= 0; --i)
		{
			if (str[i] == ' ')
			{
				str[index--] = '0';
				str[index--] = '2';
				str[index--] = '%';
			}

			else
			{
				str[index--] = str[i];
			}
		}

	}
};


//3.����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {

		vector<int> v1;
		vector<int> v;
		ListNode* pCur = head;

		while (pCur)
		{
			v1.push_back(pCur->val);
			pCur = pCur->next;
		}

		for (int i = v1.size() - 1; i >= 0; --i)
		{
			v.push_back(v1[i]);
			v1.pop_back();
		}

		return v;
	}
};

//��������
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {

		vector<int> v;
		struct ListNode* Pre = NULL;
		struct ListNode* Cur = head;
		struct ListNode* Next = NULL;

		while (Cur)
		{
			Next = Cur->next;
			Cur->next = Pre;//����Cur��nextָ��Pre����Pre=Cur->next;
			Pre = Cur;
			Cur = Next;
		}

		head = Pre;//PreΪ�µ�ͷ�ڵ�
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		return v;
	}
};