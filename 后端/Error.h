#pragma once

#include "Global.h"
using namespace std;

// ����Ϊ�ⲿ���õı����ͺ���
extern ofstream errorFile;
extern int cnt_line;
extern int lastCountLine;

// ����Ϊ�ڲ�����ı����ͺ���
void error(char errorCode);