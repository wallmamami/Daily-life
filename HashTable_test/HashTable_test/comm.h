#pragma once

typedef unsigned long size_t;
typedef int DataType;

typedef size_t(*PDTInt)(DataType str);

//������ȡ������ʹÿ�ζ�������
int GetCapacity(int capacity);

size_t StrToInt(const char * str);

size_t IntToInt(int data);


