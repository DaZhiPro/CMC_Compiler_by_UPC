#pragma once

#include "Global.h"
using namespace std;

// ����Ϊ�ⲿ���õı����ͺ���
extern ofstream mipsCodeFile;
extern map<string, map<string, struct sym>> symList;
extern vector <struct midCode> midCodes;
extern vector <struct mipsCode> mipsCodes;

extern  map <string, int> functionParameterCount;	// ��¼��������������
vector<string> stringList;			//�������е��ַ���

string curFuncName = "";			// ��¼��ǰ���ں�������
extern int string2int(string s);
extern string int2string(int t);

extern map<string, vector<midCode>> funcMidCodeTable;	//ÿ�������������м����
extern map<string, vector<Block>> funcBlockTable;		//ÿ�������Ļ������б�
extern vector<string> funcNameList;
extern vector<midCode> midCodesForProgram;

// ����Ϊ�ڲ�����ı����ͺ���
extern int isDebug;
int tRegBusy[10] = { 0, };		// ��t3-t9��7����ʱ�Ĵ��������� ���ڼ�¼��ʱ�Ĵ����Ƿ�ռ��
string tRegContent[10];			// ��¼ÿһ����ʱ�Ĵ������������һ���м���� #T0,#T1...
int sRegBusy[10] = { 0, };		// ��s0-s7��8��ȫ�ּĴ��������� ���ڼ�¼ȫ�ּĴ����Ƿ�ռ��
string sRegContent[10];			// ��¼ÿһ��ȫ�ּĴ������������һ���ֲ�����

void generateMipsCodes();

void loadValue(string& symbolName, string& regName, bool gene, int& va, bool& get, bool assign=true);

void storeValue(string& symbolName, string& regName);

void insertMipsCode(mipsOp op, string result, string left, string right, int imm);

void insertMipsCode(mipsOp op, string result, string left, string right);

void outputMipsCodes();

void outputMipsCode(struct mipsCode mc);