#pragma once

#include "Global.h"
using namespace std;

// ����Ϊ�ⲿ���õı����ͺ���
extern ofstream ofile;			// ����ļ�
extern int isError;
extern int isDebug;

// �ʷ������׶�
extern int symbol;				// ��¼��ǰToken������
extern char TOKEN[256];			// ��¼��ǰToken���ַ���
extern int lastSymbol;			// ��¼��һ��Token������
extern char lastTOKEN[256];		// ��¼��һ��Token���ַ���
extern int lastlastSymbol;		// ��¼���ϸ�Token������
extern char lastlastTOKEN[256];	// ��¼���ϸ�Token���ַ���
extern int cnt_line;			// ��¼��ǰ��������Դ�ļ��е��������Ա���д������

extern void getsym();
extern void getsym(bool isOutput);
extern void trysym();
extern void ungetsym();
extern void outputsym();

// ������׶�
extern void error(char errorCode);

// ���ű�
extern int localAddr;
extern string curLevel;										// ��¼��ǰ���ڵķ��ű�������
extern struct sym curSym;									// ��¼��ǰ����ʹ�õķ���
extern map<string, map<string, struct sym>> symList;		// ���ű�

extern void initCurrentSymbol();
extern void insertCurrentSymbol();
extern void insertCurrentLevel();
extern void insertSymbol(string name, int kind, int type);
extern void insertSymbol(string name, struct sym tmpSymbol);

// �м�������ɽ׶�
extern int nameId;
extern vector<string> stringList;
vector<midCode> midCodesForProgram;							// ȫ�ֱ����ĳ�ʼ��
map<string, vector<midCode> > funcMidCodeTable;				//ÿ�������������м����	
map<string, bool> funcInlineAble; //�����Ƿ��������		
vector<string> funcNameList; //��������
extern vector <struct midCode> midCodes;	// �м����

extern string genTmp();				// ��ȡ��ʱ��������
extern string genSTmp();
extern string genName();
extern string genLabel();			// ��ȡ�������ǩ
extern string genLabel(string app);
extern int string2int(string s);	// �ַ���ת��Ϊ����
extern string int2string(int t);	// ����ת��Ϊ�ַ���
extern void insertMidCode(midOp op, string result, string left, string right);
extern void insertMidCode(midOp op, string result, string left, string right, string backup);

// ����Ϊ�ڲ�����ı����ͺ���
int returnedType;								// ��¼�����Ѿ�����ֵ�����ͣ�0Ϊ�޷���ֵ��1Ϊ���ͣ�2Ϊ�ַ���3Ϊreturn;
map <string, int> functionReturnType;			// ��¼��������ֵ���ͣ�0Ϊ�޷���ֵ��1Ϊ���ͣ�2Ϊ�ַ�
map <string, int> functionParameterCount;		// ��¼�з���ֵ�����Ĳ�������
map <string, int[100]> functionParameterType;	// ��¼�з���ֵ�����Ĳ�������

// �ݹ�����Ӻ���
void getAdditionOperator(int& additionOperator);				// <�ӷ������>
void getMultiplicationOperator(int& multiplicationOperator);	// <�˷������>
void getRelationalOperator(int& tmpRelationalOperator);			// <��ϵ�����>
void getChar(string& c);										// <�ַ�>
void getString(string& s);										//*<�ַ���>

void getProgram();									//*<����>
void getConstantDeclaration();						//*<����˵��>
void getConstantDefination();						//*<��������>
void getUnsignedInteger(int& tmpUnsignedInteger);	//*<�޷�������>				
void getInteger(int& tmpInteger);					//*<����>
			
void getIdentifier(string& identifier);				// <��ʶ��>
void getConstant(int& tmpConstType, int& constInteger, string& constChar);		//*<����>

void getVariableDeclaration();															//*<����˵��>
void getVariableDeclarationForProgram(int tmpTypeIdentifier);
void getVariableDefination();															//*<��������>
void getVariableDefinationForProgram(int tmpTypeIdentifier);
void getVariableDefinationWithoutInitialization(int tmpTypeIdentifier);					//*<���������޳�ʼ��>
void getVariableDefinationWithInitialization(int tmpTypeIdentifier, int dimension);		//*<�������弰��ʼ��>	
void getTypeIdentifier(int& typeIdentifier);											// <���ͱ�ʶ��>

void getFunctionDefinationWithReturnValueForProgram(int returnType);		//*<�з���ֵ��������>
void getFunctionDefinationWithoutReturnValueForProgram(int returnType);		//*<�޷���ֵ��������>
void getCompoundStatements();												//*<�������>
void getParameterList();													//*<������>
void getMainForProgram();													//*<������>
	
void getExpression(int& type, string& ansTmp);			// ���ʽ	
void getTerm(int& type, string& ansTmp);				// ��	
void getFactor(int& type, string& ansTmp);				// ����

void getStatement();
void getAssignmentStatement();
void getConditionalStatement();
void getCondition(string& tmpCondition);
void getLoopStatement();
void getStep(int& tmpStep);
void getSwitch();
void getCaseTable(int tmpExpressionType, string tmpExpression, string endLabel);
void getCase(int tmpExpressionType, string tmpExpression, string endLabel);
void getDefault(string endLabel);
void getFunctionCallStatementWithReturnValue(int& type);
void getFunctionCallStatementWithoutReturnValue();
void getValueParameterTable(string tmpFunctionCall);
void getStatementList();
void getScanf();
void getPrintf();
void getReturn();

// ���symbol����
void checkSymbol(int symType, char errorType);
void checkSymbolandGetSym(int symType, char errorType);

// ���Identifier
void checkUndefinedIdentifier(string tmpIdentifier);

// ������������
void checkBeforeFunc();
void fullNameMap(map<string, string>& nameMap, vector<midCode> ve, string funcName);
void dealInlineFunc(string name, int& begin, int& end);