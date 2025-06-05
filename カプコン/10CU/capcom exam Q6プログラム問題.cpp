//	実行結果は
//	3RD
//	1ST
//	1ST
//	語群の番号を選んで穴埋めします


#include <iostream>
#include <string.h>
using namespace std;

#define MAXLIST	150
#define MAXNAME 4

class cStudent
{
public:
	cStudent(){strcpy(year, "1ST");}				//	問題1
	void print(){cout << year << endl;}
private:
	char	year[MAXNAME + 1];
protected:
	cStudent(char* _name){strcpy(year, _name);}		//	問題2
};

class cStudent3RD:public cStudent
{
public:
	cStudent3RD():cStudent("3RD"){}					//	問題3
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
			delete data[i];							//	問題4
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
			data[i]->print();						//	問題5
		}
	}
};

int main()
{
	cList*	pList = new cList();

	pList->push(new cStudent3RD());					//	問題6
	pList->push(new cStudent());
	pList->push(new cStudent());					//	問題7

	pList->print();									//	問題8

	delete pList;									//	問題9

	cin.get();										//	結果テスト用試験にはない
	return 0;
}