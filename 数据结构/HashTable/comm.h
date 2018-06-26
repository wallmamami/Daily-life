#pragma once

typedef char* DataType;

typedef unsigned(PSTI)(DataType str);



//���ַ���ת��Ϊ����
unsigned StrToInt1(const char * str);

unsigned int StrToInt2(char *str);

// RS Hash Function
unsigned int StrToInt3(char *str);

// JS Hash Function
unsigned int StrToInt4(char *str);

// ELF Hash Function
unsigned int StrToInt5(char *str);

unsigned IntToInt(int data);




