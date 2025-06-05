//	���s���ʂ�
//	3RD
//	1ST
//	1ST
//	��Q�̔ԍ���I��Ō����߂��܂�


#include <iostream>
#include <string.h>
using namespace std;

#define MAXLIST	150
#define MAXNAME 4

class cStudent
{
public:
	cStudent(){strcpy(year, "1ST");}				//	���1
	void print(){cout << year << endl;}
private:
	char	year[MAXNAME + 1];
protected:
	cStudent(char* _name){strcpy(year, _name);}		//	���2
};

class cStudent3RD:public cStudent
{
public:
	cStudent3RD():cStudent("3RD"){}					//	���3
};

class cList
{
private:
	cStudent*	data[MAXLIST];
	int			size;
public:
	cList():size(0){}
	virtual ~cList()
	{
		for(int i = 0; i < size; i++)
		{
			delete data[i];							//	���4
		}
	}

	void push(cStudent* _data)
	{
		data[size++] = _data;
	}

	void print()
	{
		for(int i = 0; i < size; i++)
		{
			data[i]->print();						//	���5
		}
	}
};

int main()
{
	cList*	pList = new cList();

	pList->push(new cStudent3RD());					//	���6
	pList->push(new cStudent());
	pList->push(new cStudent());					//	���7

	pList->print();									//	���8

	delete pList;									//	���9

	cin.get();										//	���ʃe�X�g�p�����ɂ͂Ȃ�
	return 0;
}