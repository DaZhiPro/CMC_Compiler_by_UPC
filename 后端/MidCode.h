#pragma once

#include "Global.h"
using namespace std;

// ����Ϊ�ⲿ���õı����ͺ���
extern string curLevel;
extern ofstream midCodeFile;
extern vector <struct midCode> midCodes;
extern vector<midCode> midCodesForProgram;
extern map<string, map<string, struct sym>> symList;

// ����Ϊ�ڲ�����ı����ͺ���
// ��������
void insertMidCode(midOp op, string result, string left, string right);

void insertMidCode(midOp op, string result, string left, string right, string backup);

void outputMidCodes();

void outputMidCode(struct midCode m);