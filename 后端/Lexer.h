#pragma once

#include "Global.h"

// ����Ϊ�ⲿ���õı����ͺ���
extern string CODEN[40];
extern string CODES[40];

extern ifstream ifile;
extern ofstream ofile;

extern void error(char errorCode);		// ��������

// ����Ϊ�ڲ�����ı����ͺ���
int isFirst = 1;			// ����Ƿ�Ϊ��һ�ε���

int symbol;					// ���浱ǰ��ʶ�𵥴ʵ�����
char CHAR;					// ��ŵ�ǰ������ַ�
char TOKEN[256];			// ��ŵ����ַ���
char buffer[256];			// �ļ����뻺����

int cnt;					// ��¼��һ����ȡ���ַ���λ��
int cnt_len;				// ��¼��ǰ�������ַ����ĳ���
int cnt_line;				// ��¼��ǰ��������Դ�ļ��е��������Ա���д������
int lastCountLine;

int lastBegin;				// ��һ��Token��ʼλ��
int lastSymbol;				// ��һ��Token������
char lastTOKEN[256];		// ��һ��Token���ַ���

int lastlastBegin;			// ���ϸ�Token��ʼλ��
int lastlastSymbol;			// ���ϸ�Token������
char lastlastTOKEN[256];	// ���ϸ�Token���ַ���

void getsym();				// ��ȡ��һ�� symbol
void getsym(bool isOutput);
void trysym();				// ��ȡ��һ�� symbol���������
void ungetsym();			// ����һ�� symbol
void outputsym();			// �����ǰ�� symbol

int isDigit(char c);		// �ж��ַ��Ƿ�Ϊ ����
int isLetter(char c);		// �ж��ַ��Ƿ�Ϊ ��ĸ
int isChar(char c);			// �ж��ַ��Ƿ�Ϊ �ַ��е��ַ����� '���ӷ��������'��'���˷��������'��'����ĸ��'��'�����֣�'
int isString(char c);		// �ж��ַ��Ƿ�Ϊ �ַ����е��ַ����� "��ʮ���Ʊ���Ϊ32,33,35-126��ASCII�ַ���"

void cat(char s[], char c); // ���ַ����뵽�ַ�����ĩβ
int getnbc();				// ���ַ���������ȡ��һ���ǿ��ַ������� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
void getch();				// ���ַ���������ȡһ���ַ� 
void ungetch();				// ���ַ�����������һ���ַ� 
void reserve(char s[]);		// �жϻ�ȡ�����ַ����Ƿ�Ϊ������
void tolowercase(char s[]);	// ���ַ����еĴ�дӢ���ַ�ת��ΪСд