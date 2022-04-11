#pragma once

#include "Global.h"
using namespace std;

// ����Ϊ�ⲿ���õı����ͺ���
// �����ķ������е������������ַ���ת����Сд
extern int isString(char c);		// �ж��Ƿ�Ϊ�ַ����е��ַ�
extern void tolowercase(char s[]);	// ���ַ����еĴ�дӢ���ַ�ת��ΪСд

// ��������
extern void error(char errorCode);


// ����Ϊ�ڲ�����ı����ͺ���
int globalAddr = 0;					// ��¼ȫ�ֱ�����ջ�еĵ�ַ
int localAddr = 0;					// ��¼�ֲ�������ջ�еĵ�ַ

string curLevel;					// ��¼��ǰ���ڵķ��ű�������
struct sym curSym;					// ��¼��ǰ����ʹ�õķ���
map<string, struct sym> curMap;		// ��¼��ǰ���ڵķ��ű��ε�map
map<string, map<string, struct sym>> symList;

void initCurrentSymbol();

void insertCurrentSymbol();

void insertCurrentLevel();

void insertSymbol(string name, int kind, int type);
