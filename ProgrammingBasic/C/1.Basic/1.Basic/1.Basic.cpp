//stdio: ǥ������� ���̺귯��
#include <stdio.h> 

void HelloWorldMain()//�Լ�: �ڵ带 �ۼ��Ͽ� ������� ����°�. 
{
	//��±��("����");
	printf("khg\n");//�����ݷ�(;): ���α׷� ������ ���� ����.
	printf("Hello World!\n");//\n: �ٹٲ޹���
}
//���� ������ ���ϴ� ���α׷��� �ۼ��Ͽ���.(��, ���� �������� 3�̴�)
//������*������*3.14 = ���� ����
//����ɼ��ִ°�: ����-������,���ǳ��� //����? �Ǽ�?->������ �Ҽ����� �ȳ����Ƿ� �Ǽ��� ����Ѵ�.
/*void CircleAreaMain()
{
	int radius = 3;
	int circleArea;

	circleArea = radius * radius * 3.14;

	printf("CircleArea:%d\n", circleArea);
}*/
void CircleAreaMain()
{
	float radius = 3;
	float circleArea;

	circleArea = radius * radius * 3.14;

	printf("CircleArea:%f\n", circleArea);
}

//�ּ�: �����Ϸ��� �м������ʴ� ����
void main()//���α׷��� ����Ǹ� os���� �ڵ����� ȣ���ϴ� �Լ�
{
	HelloWorldMain(); //�Լ��� ȣ��: �Լ��� ȣ���ؾ� ����ȴ�.
	CircleAreaMain();
}