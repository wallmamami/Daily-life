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


//模拟实现strlen
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


//模拟实现strcpy
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

//模拟实现strcat
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

//模拟实现strstr
//strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
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

//模拟实现strcmp
//第一个大返回1， 第二个大返回-1

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

//模拟实现memcpy（没有考虑源和目标有内存重叠的情况）
//从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中，返回指向dest的指针
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

//模拟实现memmove（解决了memcpy课能因为内存重叠而出现的问题）
void *memmove(void *dest, const char *src, size_t count)
{
	void *ret = dest;

	if (src >= dest || dest >= ((char*)src + count))//正常情况，与memcpy一样，从左到右拷贝
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}

	else //内存重叠，从右到左拷贝
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