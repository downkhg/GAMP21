/*##################################
STL(�ڷᱸ�� ������)
���ϸ�: STL_empty.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2022.03.09
���� : 1.05
###################################*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>//hash_map -> unordered_map: vs2019���� ����
using namespace std;
//����: �����迭
//0.�迭�� �����Ͱ� ����ɰ����� �̸� Ȯ���Ǿ��ִ�.
//1.�ε����� ���������� �����ϴ�.
//2.�� �ڷ�� �����Ϳ���(�ε���)�� ���� ����/���������� �����ϴ�.
//3.�迭�� ũ�⸦ ��Ÿ���߿� ���氡���ϴ�.
void VectorMain()
{
	vector<int> container(10);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		container[i] = (container.size() - i) * 10;
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;//\n
	container.resize(5); //�迭�� ũ�⸦ �����Ѵ�.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.�߰� 2.���� //3.ã�� //4.����
	container.push_back(0); //�߰�
	container.push_back(-10); //�߰�
	vector<int>::iterator it;
	it = container.begin()+3; //������ ���ͷ����� ����
	vector<int>::iterator itInsert = container.insert(it, -20); //�ش� ���ͷ����Ϳ� �տ� ���� ������.
	vector<int>::iterator itFind = find(container.begin(), container.end(), 1000); //������ ���ͷ����� ����
	if (itFind != container.end()) //���������� ���������ʴ´�.
		cout << "itFind:" << *itFind << endl;
	container.erase(itInsert); //�ش� ���ͷ����͸� �迭���� �����Ѵ�.
	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	reverse(container.begin(), container.end());
	cout << "Reverse:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	container.clear(); //��λ���
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}
//���Ḯ��Ʈ
//1.�����ʹ� �������ٸ� �����ϴ�.(����x)
//2.���Ḯ��Ʈ�� �߰�,����,������ O(1)�̴�.
//3.���Ḯ��Ʈ�� ����: ����, ȯ��, ���� stl�� ����Ʈ�� ��� �ش�Ǵ°�?
void ListMain()
{
	list<int> container(10);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	list<int>::iterator it;
	//container[0] = 10; //����Ʈ�� ������������ �Ұ����ϴ�.
	int i = 0;
	for (it = container.begin(); it != container.end(); it++)
	{
		*it = (container.size() - i) * 10;
		i++;
	}
	cout << "Print:";
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;//\n
	container.resize(5); //�迭�� ũ�⸦ �����Ѵ�.
	cout << "Print:";
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	//1.�߰� 2.���� //3.ã�� //4.����
	container.push_back(0); //�߰�
	container.push_back(-10); //�߰�
	container.push_front(-30);//
	//it = container.begin() + 3; //�����Ͽ���. ����Ʈ�� ������常 ���ٰ����ϴ�.
	it = container.begin()++; it++; it++; //it--; it--;//������ ���ͷ����� ���� //����Ʈ�� �������θ� �̵��� �����ϴ�. //�������� �̵��� �����ϴ� -> ���߿��Ḯ��Ʈ��.
	list<int>::iterator itInsert = container.insert(it, -20); //�ش� ���ͷ����Ϳ� �տ� ���� ������.
	list<int>::iterator itFind = find(container.begin(), container.end(), 1000); //������ ���ͷ����� ����
	if (itFind != container.end()) //���������� ���������ʴ´�.
		cout << "itFind:" << *itFind << endl;
	container.erase(itInsert); //�ش� ���ͷ����͸� �迭���� �����Ѵ�.
	//cout << "itFind:" << *itFind << endl; //����Ʈ�� Ư���� �������� �޸𸮴� �������������, apiƯ���� ��� �����̳ʵ��� ��ġ���� �����ϱ����ؼ� �̷��� �����?
	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	reverse(container.begin(), container.end());
	cout << "Reverse:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	container.clear(); //��λ���
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}
//��ũ: �յڷ� �ڷḦ �߰�/��������, �������ٰ���.
void DequeMain()
{
	deque<int> container(10);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		container[i] = (container.size() - i) * 10;
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;//\n
	container.resize(5); //�迭�� ũ�⸦ �����Ѵ�.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.�߰� 2.���� //3.ã�� //4.����
	container.push_back(0); //�߰�
	container.push_back(-10); //�߰�
	container.push_front(-30);
	deque<int>::iterator it;
	it = container.begin() + 3; //������ ���ͷ����� ����
	deque<int>::iterator itInsert = container.insert(it, -20); //�ش� ���ͷ����Ϳ� �տ� ���� ������.
	deque<int>::iterator itFind = find(container.begin(), container.end(), 1000); //������ ���ͷ����� ����
	if (itFind != container.end()) //���������� ���������ʴ´�.
		cout << "itFind:" << *itFind << endl;
	container.erase(itInsert); //�ش� ���ͷ����͸� �迭���� �����Ѵ�.
	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	reverse(container.begin(), container.end());
	cout << "Reverse:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	container.clear(); //��λ���
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}
//����: �ڿ��� �߰��ǰ� �ڿ��� ����.
//����Լ����� ���� �Լ��� ȣ���Ҷ����� ���ÿ� ����.
//���ڿ������� -> ���ڹ迭 -> apple -> elppa
void StackMain()
{
	char strApple[] = "Apple";
	stack<char> cStack;
	cout << "Apple:" << strApple << endl;
	int nIdx = 0;
	while (strApple[nIdx]!='\0')
	{
		cStack.push(strApple[nIdx]);
		nIdx++;
	}
	nIdx = 0;
	while (cStack.empty() == false)
	{
		strApple[nIdx] = cStack.top();
		cStack.pop();
		nIdx++;
	}
	cout <<"Reverse:"<< strApple << endl;
}
//ť: �ڿ��� �߰��ϰ� �տ��� ����.
//�޼���ť: �̺�Ʈ�� �߻��� ������� �����ϴ� ����.
//�Էµ� ������� ��ɾ� ó���ϱ�
void QueueMain()
{
	char cInput = '\0';
	queue<char> cQueue;
	
	while (cInput != 'x')
	{
		cin >> cInput;
		cQueue.push(cInput);
	}
	cout << "Message:" << endl;
	while (cQueue.empty() == false)
	{
		cout << cQueue.front() << endl;
		cQueue.pop();
	}
}
//�켱����ť: �켱������ ���� ���Ұ� ��������(��)
//�������� �����͸� �־����� � ������� �����Ͱ� �����°�? ū������ ���´�.
void PriorytyQueueMain()
{
	priority_queue<int> cPriorytyQueue;

	cPriorytyQueue.push(100);
	cPriorytyQueue.push(20);
	cPriorytyQueue.push(50);
	cPriorytyQueue.push(80);
	cPriorytyQueue.push(10);

	while (cPriorytyQueue.empty() == false)
	{
		cout << cPriorytyQueue.top() << endl;
		cPriorytyQueue.pop();
	}
}
//��: ���������� �����͸� ã�����ִ�.
//�ش翵��ܾ ������ �ѱ��� ����� ���´�.//����(�����)����Ʈ��
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//��: �������� �����͸� �ִ´�. �����ʹ� ������ ������� �����͸� ã�´�.//����(�����)����Ʈ��
void SetMain()
{
	set<int> setData;

	setData.insert(10);
	setData.insert(20);
	setData.insert(30);
	setData.insert(40);

	set<int>::iterator it = setData.find(10);

	if (it != setData.end()) it;
	for (it = setData.begin(); it != setData.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//�ؽø�: �ؽ����̺� 
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
void main()
{
	//VectorMain();
	//ListMain();
	//DequeMain();
	//StackMain();
	//QueueMain();
	//PriorytyQueueMain();
	//MapMain();
	SetMain();
}