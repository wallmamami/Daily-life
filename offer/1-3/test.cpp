#include <vector>
#include <set>
#include <iostream>
#include <deque>

using namespace std;



//1.在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		
		//从右上角开始找
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

//2.请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，
//当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str, int length) {

		//先计算出源字符串一共有几个空格，
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


//3.输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

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

//方法二：
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
			Cur->next = Pre;//是让Cur的next指向Pre不是Pre=Cur->next;
			Pre = Cur;
			Cur = Next;
		}

		head = Pre;//Pre为新的头节点
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		return v;
	}
};