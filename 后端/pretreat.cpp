#include "pretreat.h"
#include "Global.h"
//in >> noskipws 读取文件中的空白字符

//状态转换表见pretreat.h
void delzs(fstream& in, fstream& out)
{
	char temp, pre;
	string temp_s = "";		//存储可能为注释的字符串
	int status = 0;
	in >> noskipws;
	while (!in.eof())
	{
		if (!status) status = 1;
		in >> temp;
		if (in.fail())
			break;
		switch (status)
		{
		case 1:
			if (temp != '/')
			{
				out << temp;	//cout << temp;
				status = 1;
			}
			else
				status = 2;
			pre = temp;
			break;
		case 2:
			if (temp == '/')
			{
				out << temp;	//cout << temp;
				status = 2;
			}
			else
				if (temp != '*')
				{
					out << '/' << temp;		//cout << '/' << temp;
					status = 1;
				}
				else
					status = 3;
			pre = temp;
			break;
		case 3:
			if (temp == '*')
				status = 4;
			else
				status = 3;
			temp_s.push_back(temp);
			if (pre == '/' && temp == '*')
			{
				cout << "出现注释嵌套！" << endl;
				out << "[Error Occured!]";
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				exit(0);
			}
			pre = temp;
			break;
		case 4:
			if (temp == '/')
				status = 5;
			else
				if (temp == '*')
					status = 4;
				else
					status = 3;
			temp_s.push_back(temp);
			pre = temp;
			break;
		case 5:
			temp_s = "";		//一段注释结束 清空暂存的可能为的注释信息
			if (temp != '/')
			{
				out << temp;	//cout << temp;
				status = 1;
			}
			else
				status = 2;
			pre = temp;
			break;
		default:
			cout << "An error occured!" << endl;
			break;					//进入default分支 说明发生比较神奇的错误
		};
	}
	//如果最后注释格式右侧没有闭合 则需要将 尚为输出 正在判别的部分输出
	if (status == 2)
	{
		out << "/";		//cout << "/";
	}
	if (status == 3 || status == 4)
	{
		out << "/*" << temp_s;	//cout << "/*" << temp_s;
	}
}

//状态转换表见pretreat.h
void delblank(fstream& in, fstream& out)
{
	char temp, pre;
	int status = 0;
	in >> noskipws;
	in >> temp;
	while (temp == ' ' || temp == '\t' || temp == '\n')
		in >> temp;
	out << temp;	//cout << temp;
	pre = temp;				//去除程序前所有的空白字符，直到第一个非换行符空格或制表符
	while (!in.eof())
	{
		in >> temp;
		if (in.fail())
			break;
		if (!status) status = 1;
		switch (status)
		{
		case 1:
			if (temp == ' ' || temp == '\n' || temp == '\t')
				status = 2;
			else
			{
				out << temp;	//cout << temp;
			}
			pre = temp;
			break;
		case 2:
			if (temp != ' ' && temp != '\n' && temp != '\t')
			{
				status = 1;
				out << pre << temp;		//cout << pre << temp;			//2状态接收到一个非空白字符 则输出最近的一个空白字符
			}
			if (pre != '\n')
				pre = temp;				//如换行与制表符或空格同时出现 保留换行 保证程序大体格式不被改变
			break;
		default:
			cout << "An error occured!" << endl;
			break;						//进入default分支 说明发生比较神奇的错误
		};
	}
	return;
}

void pretreat() {
	fstream in, out;
	in.open("testfile.txt", ios::in);
	out.open("after_del_zs.txt", ios::out);
	delzs(in, out);
	in.close(), out.close();
}