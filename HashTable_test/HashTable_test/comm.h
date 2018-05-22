#pragma once

typedef unsigned long size_t;
typedef int DataType;

typedef size_t(*PDTInt)(DataType str);

//用来获取容量，使每次都是素数
int GetCapacity(int capacity);

size_t StrToInt(const char * str);

size_t IntToInt(int data);


