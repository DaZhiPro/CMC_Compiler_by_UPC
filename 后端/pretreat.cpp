#include "pretreat.h"
#include "Global.h"
//in >> noskipws ��ȡ�ļ��еĿհ��ַ�

//״̬ת�����pretreat.h
void delzs(fstream& in, fstream& out)
{
	char temp, pre;
	string temp_s = "";		//�洢����Ϊע�͵��ַ���
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
				cout << "����ע��Ƕ�ף�" << endl;
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
			temp_s = "";		//һ��ע�ͽ��� ����ݴ�Ŀ���Ϊ��ע����Ϣ
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
			break;					//����default��֧ ˵�������Ƚ�����Ĵ���
		};
	}
	//������ע�͸�ʽ�Ҳ�û�бպ� ����Ҫ�� ��Ϊ��� �����б�Ĳ������
	if (status == 2)
	{
		out << "/";		//cout << "/";
	}
	if (status == 3 || status == 4)
	{
		out << "/*" << temp_s;	//cout << "/*" << temp_s;
	}
}

//״̬ת�����pretreat.h
void delblank(fstream& in, fstream& out)
{
	char temp, pre;
	int status = 0;
	in >> noskipws;
	in >> temp;
	while (temp == ' ' || temp == '\t' || temp == '\n')
		in >> temp;
	out << temp;	//cout << temp;
	pre = temp;				//ȥ������ǰ���еĿհ��ַ���ֱ����һ���ǻ��з��ո���Ʊ��
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
				out << pre << temp;		//cout << pre << temp;			//2״̬���յ�һ���ǿհ��ַ� ����������һ���հ��ַ�
			}
			if (pre != '\n')
				pre = temp;				//�绻�����Ʊ����ո�ͬʱ���� �������� ��֤��������ʽ�����ı�
			break;
		default:
			cout << "An error occured!" << endl;
			break;						//����default��֧ ˵�������Ƚ�����Ĵ���
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