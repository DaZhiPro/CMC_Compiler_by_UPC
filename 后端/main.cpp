#include "main.h"

int isError = 0;	// �Ƿ��������
int isDebug = 0;	// �Ƿ����ģʽ

int main() {
	
	pretreat();
	openFiles();			// �������ļ�

	getsym();				// �ʷ�����
	getProgram();			// �﷨����

	outputMidCodes();		// ����м����

	splitBlock();			// �ָ�����

	generateMipsCodes();	// ����mips����
	outputMipsCodes();		// ���mips����

	closeFiles();			// �ر������ļ�

	return 0;
}

void openFiles() {
	ifile.open("after_del_zs.txt", ios::in);
	ofile.open("output.txt", ios::out);
	errorFile.open("error.txt", ios::out);
	midCodeFile.open("midcode.txt", ios::out);
	mipsCodeFile.open("mips.txt", ios::out);
	init_CODEN();
	init_CODES();
}

void closeFiles() {
	ifile.close();
	errorFile.close();
	midCodeFile.close();
	mipsCodeFile.close();
}

void init_CODEN() {
	CODEN[0] = "IDENFR";        // ��ʶ��
	CODEN[1] = "INTCON";        // ���ͳ���
	CODEN[2] = "CHARCON";       // �ַ�����
	CODEN[3] = "STRCON";        // �ַ���
	CODEN[4] = "CONSTTK";
	CODEN[5] = "INTTK";
	CODEN[6] = "CHARTK";
	CODEN[7] = "VOIDTK";
	CODEN[8] = "MAINTK";
	CODEN[9] = "IFTK";
	CODEN[10] = "ELSETK";
	CODEN[11] = "SWITCHTK";
	CODEN[12] = "CASETK";
	CODEN[13] = "DEFAULTTK";
	CODEN[14] = "WHILETK";
	CODEN[15] = "FORTK";
	CODEN[16] = "SCANFTK";
	CODEN[17] = "PRINTFTK";
	CODEN[18] = "RETURNTK";
	CODEN[19] = "PLUS";
	CODEN[20] = "MINU";
	CODEN[21] = "MULT";
	CODEN[22] = "DIV";
	CODEN[23] = "LSS";
	CODEN[24] = "LEQ";
	CODEN[25] = "GRE";
	CODEN[26] = "GEQ";
	CODEN[27] = "EQL";
	CODEN[28] = "NEQ";
	CODEN[29] = "COLON";
	CODEN[30] = "ASSIGN";
	CODEN[31] = "SEMICN";
	CODEN[32] = "COMMA";
	CODEN[33] = "LPARENT";
	CODEN[34] = "RPARENT";
	CODEN[35] = "LBRACK";
	CODEN[36] = "RBRACK";
	CODEN[37] = "LBRACE";
	CODEN[38] = "RBRACE";
}

void init_CODES() {
	CODES[0] = "IDENFR";        // ��ʶ��
	CODES[1] = "INTCON";        // ���ͳ���
	CODES[2] = "CHARCON";       // �ַ�����
	CODES[3] = "STRCON";        // �ַ���
	CODES[4] = "const";
	CODES[5] = "int";
	CODES[6] = "char";
	CODES[7] = "void";
	CODES[8] = "main";
	CODES[9] = "if";
	CODES[10] = "else";
	CODES[11] = "switch";
	CODES[12] = "case";
	CODES[13] = "default";
	CODES[14] = "while";
	CODES[15] = "for";
	CODES[16] = "scanf";
	CODES[17] = "printf";
	CODES[18] = "return";
	CODES[19] = "+";
	CODES[20] = "-";
	CODES[21] = "*";
	CODES[22] = "/";
	CODES[23] = "<";
	CODES[24] = "<=";
	CODES[25] = ">";
	CODES[26] = ">=";
	CODES[27] = "==";
	CODES[28] = "!=";
	CODES[29] = ":";
	CODES[30] = "=";
	CODES[31] = ";";
	CODES[32] = ",";
	CODES[33] = "(";
	CODES[34] = ")";
	CODES[35] = "[";
	CODES[36] = "]";
	CODES[37] = "{";
	CODES[38] = "}";
}

string int2string(int t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

int string2int(string s) {
	stringstream ss;
	ss << s;
	int t;
	ss >> t;
	return t;
}

string genLabel() {
	labelId++;
	return "Label" + int2string(labelId);
}

string genLabel(string app) {
	labelId++;
	return "Label" + int2string(labelId) + app;
}

string genTmp() {
	tmpVarId++;
	return "#T" + int2string(tmpVarId);  // # ��ͷ��ʾ�м����
}

string genSTmp() {
	tmpVarId++;
	return "T" + int2string(tmpVarId);
}

string genName() {
	nameId++;
	return "%INLINE_" + int2string(nameId); //% ��ͷ�������ı������ֿ� 
}