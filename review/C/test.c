//#include <iostream>
//using namespace std;


/*int main()
{
	char arr[] = "adfe";
	cout << sizeof(arr) << endl;

	return 0;
}      */      


#include <stdio.h>
#include <string.h>
#include <assert.h>


//ģ��ʵ��strlen
int mystrlen1(const char *ptr)
{
	int count = 0;
	if (*ptr == '\0')
		return 0;

	while (*(ptr++))
		count++;

	return count;
}

int mystrlen2(const char *str)
{
	if (str == '\0')
		return 0;

	else
		return 1 + strlen(str + 1);
}

int mystrlen3(const char *str)
{
	char *p = str;
	
	while (*(p++))
	{
		;
	}

	return (p - str);
}


//ģ��ʵ��strcpy
char* mystrcpy(char *dest, const char *src)
{
	char *ret = dest;

	assert(dest);
	assert(src);

	while ((*dest++ = *src++))
	{
		;
	}

	return ret;
}

//ģ��ʵ��strcat
char* mystrcat(char* dest, const char *src)
{
	char* ret = dest;
	assert(dest);
	assert(src);

	while(*dest)
		++dest;
	while ((*dest++ = *src++))
	{
		;
	}

	return ret;
}

//ģ��ʵ��strstr
//strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ�������ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
char *mystrstr(const char *str1, const char *str2)
{
	char* ret = str1;
	char *ptr1 = str1;
	char *ptr2 = str2;
	assert(str1);
	assert(str2);

	if (str2 == '\0')
		return NULL;
	while (ret)
	{
		ptr1 = ret;
		while (*ptr1 && *ptr2 && (*ptr1 == *ptr2))
		{
			++ptr1;
			++ptr2;
		}

		if (*ptr2 == '\0')
			return ret;
		++ret;
	}
}

//ģ��ʵ��strcmp
//��һ���󷵻�1�� �ڶ����󷵻�-1

int mystrcmp(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	int ret = 0;
	while (!(ret = *str1 - *str2) && *str1 && *str2)
	{
		++str1;
		++str2;
	}

	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	else
		return 0;
}

//ģ��ʵ��memcpy��û�п���Դ��Ŀ�����ڴ��ص��������
//��Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��dest��ָ���ڴ��ַ����ʼλ���У�����ָ��dest��ָ��
void *mymemcpy(void *dest, const void *src, size_t count)
{
	void *ret = dest;
	assert(dest);
	assert(src);

	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}

	return ret;
}

//ģ��ʵ��memmove�������memcpy������Ϊ�ڴ��ص������ֵ����⣩
void *memmove(void *dest, const char *src, size_t count)
{
	void *ret = dest;

	if (src >= dest || dest >= ((char*)src + count))//�����������memcpyһ���������ҿ���
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}

	else //�ڴ��ص������ҵ��󿽱�
	{
		src = (char*)src + count;
		dest = (char*)dest + count;

		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
}

int main()
{
	//printf("%d\n", mystrlen2("adcd"));

	char p[] = "hello world";
	//printf("%s\n", mystrcpy(p, "hello"));
	/*printf("%s\n", mystrstr(p, "worlp"));*/

	//printf("%d\n", mystrcmp("hello", "helloA"));
	
	printf("%s\n", mymemcpy(p, "dsafeafaefaegaegae", 12));
	return 0;
}