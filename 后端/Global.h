#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define MAIN "main"
#define PROGRAM "Program"
using namespace std;

// �ʷ�������ض���
enum classCode {
	IDENFR,
	INTCON,
	CHARCON,
	STRCON,
	CONSTTK, 
	INTTK, 
	CHARTK, 
	VOIDTK, 
	MAINTK, 
	IFTK, 
	ELSETK, 
	SWITCHTK, 
	CASETK, 
	DEFAULTTK, 
	WHILETK, 
	FORTK, 
	SCANFTK, 
	PRINTFTK,
	RETURNTK, 
	PLUS, MINU, 
	MULT, 
	DIV, 
	LSS, 
	LEQ, 
	GRE, 
	GEQ, 
	EQL, 
	NEQ, 
	COLON, 
	ASSIGN, 
	SEMICN, 
	COMMA, 
	LPARENT, 
	RPARENT, 
	LBRACK, 
	RBRACK, 
	LBRACE, 
	RBRACE
};

// ���ű���ض���
struct sym {
	// ����Ϊͨ�ò���
	string name;
	int kind;	// ���ŵ����࣬0������1�г�ʼֵ������2�޳�ʼֵ������3�з���ֵ������4�޷���ֵ������5����������6main����
	int type;	// ���ŵ����ͣ�1int��2int[]��3int[][]��4char��5char[]��6char[][]
	int dimension;	// ��Ϊ�������ͣ���¼��ά�ȣ���Ϊ�������ͣ���¼���������
	int addr;

	// ����Ϊ�������
	int num;	// ��¼��ֵ�ͷ��ŵ�ֵ
	string str;	// ��¼�ַ����ַ����ͷ��ŵ�ֵ
	int index;		// ��Ϊ�������ͣ���¼������
	int columns;	// ��Ϊ�������ͣ���¼������
	int length;		// ��¼�����в���+����+�м����������
};

// �м������ض���
enum midOp {
	PLUSOP, //+
	MINUOP, //-
	MULTOP, //*
	DIVOP,  // /
	LSSOP,  //<
	LEQOP,  //<=
	GREOP,  //>
	GEQOP,  //>=
	EQLOP,  //==
	NEQOP,  //!=
	ASSIGNOP,  //=
	GOTO,  //��������ת
	BZ,    //������������ת
	BNZ,   //����������ת
	PUSH,  //��������ʱ��������
	CALL,  //��������
	RET,   //�����������
	RETVALUE, //�з���ֵ�������صĽ��
	SCAN,  //��
	PRINT, //д
	LABEL, //���
	CONST, //����
	ARRAY, //����
	VAR,   //����
	FUNC,  //��������
	PARAM, //��������
	GETARRAY,  //ȡ�����ֵ  t = a[]
	GETARRAY2,  //ȡ�����ֵ  t = a[][]
	PUTARRAY,  //�����鸳ֵ  a[] = t
	PUTARRAY2,  //�����鸳ֵ  a[][] = t
	EXIT,  //�˳� main���
	JMAIN,	// ��ת��main
	EXITCASE,		// ����case���
	ENTERSWITCH,
	EXITSWITCH,
	INLINERET,  //��������֮��ķ������
	INLINEEND   //�����Ľ�β
};
struct midCode {
	string result;		// ���
	string left;		// �������
	midOp op;			// �����
	string right;		// �Ҳ�����
	string backup;		// ����
};


// ����������ض���
enum mipsOp {
	add,
	addi,
	sub,
	mult,
	mul,
	divop,
	mflo,
	mfhi,
	sll,
	beq,
	bne,
	bgt, //��չָ�� �൱��һ��ALU��ָ��+һ��branchָ��
	bge, //��չָ�� �൱��һ��ALU��ָ��+һ��branchָ��
	blt, //��չָ�� �൱��һ��ALU��ָ��+һ��branchָ��
	ble, //��չָ�� �൱��һ��ALU��ָ��+һ��branchָ��
	blez,  //һ��branch
	bgtz,  //һ��branch
	bgez,  //һ��branch
	bltz,  //һ��branch
	j,
	jal,
	jr,
	lw,
	sw,
	syscall,
	li,
	la,
	moveop,
	dataSeg,  //.data
	textSeg,  //.text
	asciizSeg,  //.asciiz
	globlSeg,  //.globl
	label,  //�������
};
struct mipsCode {
	mipsOp op;		// ����
	string result;	// ���
	string left;	// �������
	string right;	// �Ҳ�����
	int imm;		// ������
};


class Block {
public:
	int start;
	int end;
	int nextBlock1;
	int nextBlock2;
	vector<midCode> midCodeVector;
	vector<string> use;
	vector<string> def;
	vector<string> in;
	vector<string> out;

	Block(int s, int e, int n1, int n2) : start(s), end(e), nextBlock1(n1), nextBlock2(n2) {
		use = vector<string>();
		def = vector<string>();
		in = vector<string>();
		out = vector<string>();
	}

	void setnextBlock1(int n1) {
		nextBlock1 = n1;
	}

	void setnextBlock2(int n2) {
		nextBlock2 = n2;
	}

	void insert(midCode mc) {
		midCodeVector.push_back(mc);
	}

	void useInsert(string name) {
		use.push_back(name);
	}

	void defInsert(string name) {
		def.push_back(name);
	}

	void inInsert(string name) {
		in.push_back(name);
	}

	void outInsert(string name) {
		out.push_back(name);
	}

	void output() {
		cout << start << " " << end << " " << nextBlock1 << " " << nextBlock2 << "\n";
		cout << "use: \n";
		for (int i = 0; i < use.size(); i++) {
			cout << use[i] << " ";
		}
		cout << "\n";
		cout << "def: \n";
		for (int i = 0; i < def.size(); i++) {
			cout << def[i] << " ";
		}
		cout << "\n";
		cout << "in: \n";
		for (int i = 0; i < in.size(); i++) {
			cout << in[i] << " ";
		}
		cout << "\n";
		cout << "out: \n";
		for (int i = 0; i < out.size(); i++) {
			cout << out[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < midCodeVector.size(); i++) {
			cout << "(" << start + i << ") ";
			midCode mc = midCodeVector[i];
			switch (mc.op) {
			case PLUSOP:
				cout << mc.result << " = " << mc.left << " + " << mc.right << "\n";
				break;
			case MINUOP:
				cout << mc.result << " = " << mc.left << " - " << mc.right << "\n";
				break;
			case MULTOP:
				cout << mc.result << " = " << mc.left << " * " << mc.right << "\n";
				break;
			case DIVOP:
				cout << mc.result << " = " << mc.left << " / " << mc.right << "\n";
				break;
			case LSSOP:
				cout << mc.result << " = (" << mc.left << " < " << mc.right << ")\n";
				break;
			case LEQOP:
				cout << mc.result << " = (" << mc.left << " <= " << mc.right << ")\n";
				break;
			case GREOP:
				cout << mc.result << " = (" << mc.left << " > " << mc.right << ")\n";
				break;
			case GEQOP:
				cout << mc.result << " = (" << mc.left << " >= " << mc.right << ")\n";
				break;
			case EQLOP:
				cout << mc.result << " = (" << mc.left << " == " << mc.right << ")\n";
				break;
			case NEQOP:
				cout << mc.result << " = (" << mc.left << " != " << mc.right << ")\n";
				break;
			case ASSIGNOP:
				cout << mc.result << " = " << mc.left << "\n";
				break;
			case GOTO:
				cout << "GOTO " << mc.result << "\n";
				break;
			case BZ:
				cout << "BZ " << mc.result << "(" << mc.left << "=0)" << "\n";
				break;
			case BNZ:
				cout << "BNZ " << mc.result << "(" << mc.left << "=1)" << "\n";
				break;
			case PUSH:
				cout << "PUSH " << mc.result << "\n";
				break;
			case CALL:
				cout << "CALL " << mc.result << "\n";
				break;
			case RET:
				cout << "RET " << mc.result << "\n";
				break;
			case INLINERET:
				cout << "INLINERET " << mc.result << "\n";
				break;
			case RETVALUE:
				cout << "RETVALUE " << mc.result << " = " << mc.left << "\n";
				break;
			case SCAN:
				cout << "SCAN " << mc.result << "\n";
				break;
			case PRINT:
				cout << "PRINT " << mc.result << " " << mc.left << "\n";
				break;
			case LABEL:
				cout << mc.result << ": \n";
				break;
			case CONST:
				cout << "CONST " << mc.result << " " << mc.left << " = " << mc.right << endl;
				break;
			case ARRAY:
				cout << "ARRAY " << mc.result << " " << mc.left << "[" << mc.right << "]" << endl;
				break;
			case VAR:
				cout << "VAR " << mc.result << " " << mc.left << endl;
				break;
			case FUNC:
				cout << "FUNC " << mc.result << " " << mc.left << "()" << endl;
				break;
			case PARAM:
				cout << "PARA " << mc.result << " " << mc.left << endl;
				break;
			case GETARRAY:
				cout << mc.result << " = " << mc.left << "[" << mc.right << "]\n";
				break;
			case PUTARRAY:
				cout << mc.result << "[" << mc.left << "]" << " = " << mc.right << "\n";
				break;
			case EXIT:
				cout << "EXIT\n";
				break;
			default:
				break;
			}
		}
	}
};