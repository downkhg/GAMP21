//stdio: ǥ������� ���̺귯��
#include <stdio.h> 
#define PI 3.141592

void HelloWorldMain()//�Լ�: �ڵ带 �ۼ��Ͽ� ������� ����°�. 
{
	//��±��("����");
	printf("khg\n");//�����ݷ�(;): ���α׷� ������ ���� ����.
	printf("Hello World!\n");//\n: �ٹٲ޹���
}
//���� ������ ���ϴ� ���α׷��� �ۼ��Ͽ���.(��, ���� �������� 3�̴�)
//������*������*3.14 = ���� ����
//����(����ɼ��ִ°�): ����-������,���ǳ��� //����? �Ǽ�?->������ �Ҽ����� �ȳ����Ƿ� �Ǽ��� ����Ѵ�.
/*void CircleAreaMain()
{
	int radius = 3;
	int circleArea;

	circleArea = radius * radius * 3.14;

	printf("CircleArea:%d\n", circleArea);
}*/
//����<-������: �������� �� �ʿ��� �����͸� �ִ´�.
//����<-����: �ʿ��� ������ ���濡 �־�ٴѴ�.
//����: �޸𸮿� �����ǰ�, �����͸� ��� �ٽû���ϴµ� �̿�ȴ�.
void CircleAreaMain()
{
	//������ �ʱ�ȭ���������� �������� ����ִ��� �˼��������Ƿ� �����߿� ������ �߻��Ѵ�.
	float radius = 3;//�ʱ�ȭ: ������ �����Ҷ� ���� �ִ� ��. //3
	float circleArea; //?
	const float Pi = 3.141592;//�������: ������ �ʱ�ȭ�� ���� �����Ҽ�����. 
	//Pi = 3; //���� �������Ŀ� ���� ���������ϸ� ������ �߻��Ѵ�.
	printf("radius?");
	scanf("%f", &radius);//���α׷����� ����Ұ��� ����ڰ� �����ϱ����ؼ� //5
	
	circleArea = radius * radius * Pi; //������ �̿��ϸ� ���� �����ϱ� ����. //78.5398 = 5*5*Pi
	//circleArea = 3 * 3 * 3.14;  //����� �̿��ϸ� �ڵ带 �����ϴµ� ���ŷӴ�.
	//���ͷ��� �̿��� ���. �������ó�� �޸𸮸� ���������ʰ�, �����Ϸ��ܿ��� PI�� �ִ� ��ġ�� ���� ���ڷ� �������ش�.
	circleArea = radius * radius * PI;

	printf("CircleArea:%f\n", circleArea);//CircleArea:78.5398
}

void SizeMain()
{
	int x;
	printf("x: %d\n",sizeof(x));
	printf("char: %d\n", sizeof(char));
	printf("int: %d\n", sizeof(int));
	printf("short: %d\n", sizeof(short));
	printf("long: %d\n", sizeof(long));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
}

void ValueMain()
{
	int nDataA = 10; //10
	int nDataB = 3.141592; //3

	float fDataA = 10; //10.0
	float fDataB = 3.141592;//3.141592

	printf("nDataA/nDataB:%d/%d\n",nDataA,nDataB);//nDataA/nDataB:10/3
	printf("fDataA/fDataB:%f/%f\n", fDataA, fDataB);//fDataA/fDataB:10.0/3.141592

	nDataA = 100; //100
	nDataA = 200; //200
	nDataA = 300; //300
	nDataA = 400; //400

	printf("nDataA:%d\n",nDataA); //nDataA:400
}


//�ּ�: �����Ϸ��� �м������ʴ� ����
void main()//���α׷��� ����Ǹ� os���� �ڵ����� ȣ���ϴ� �Լ�
{
	//HelloWorldMain(); //�Լ��� ȣ��: �Լ��� ȣ���ؾ� ����ȴ�.
	//CircleAreaMain();
	//SizeMain();
	ValueMain();
}