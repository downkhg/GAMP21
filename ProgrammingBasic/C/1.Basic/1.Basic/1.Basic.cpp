//stdio: ǥ������� ���̺귯��
//��ó����: ������������ ó���Ǵ��ڵ�
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
	
	//circleArea = radius * radius * Pi; //������ �̿��ϸ� ���� �����ϱ� ����. //78.5398 = 5*5*Pi
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

#define BYTE unsigned char
//������ ����� �� �������ΰ�?
//������ ���¼��� 1�ε� �������Ǹ� �����ϸ� ���¼��� 2�����Ѵ�. 
//�׷��Ƿ�, �����÷ο찡 �߻��Ͽ� �ְ����� 255�� �Ǿ� ���¼��� �ְ���ġ�� �Ǿ���.
void WhyIsGandhiSoViolentMain()
{
	BYTE nGandhiViolent = 1;
	BYTE nDemocracyPoint = -2;
	printf("GandhiViolent:%d\n", nGandhiViolent);
	nGandhiViolent = nGandhiViolent + nDemocracyPoint;
	printf("Democrcy-GandhiViolent:%d\n",nGandhiViolent);
}

void ValueIsNumberMain()
{
	char cData = 'A';//�ƽ�Ű�ڵ�A(65)
	int nData = 65; 
	//������ ���� ������ ���尪�� �ƴ϶� ������Ŀ� ���� ����� �ٸ��� ���´�.
	printf("Data(char): %c / %c\n", cData, nData);
	printf("Data(int): %d / %d\n", cData, nData);
}

//�¾翡�� ���� �������� ���µ� �ɸ��� �ð��� ����Ͽ���.
//�¾�� ���������� �Ÿ�: 14960�� km
//���� �ӵ�: 30�� km/s
//���� �����ϴ½ð�: 14960/30  -> �¾���������̰Ÿ�/���Ǽӵ�
//����: ���޽ð�, ���Ǽӵ�(���), �¾���������̰Ÿ�(���) 
//->����,����,�Ǽ� -> �Ǽ��� ���°��� �����ϴ�. -> �� ������ �ȵǴ°�?  �Ҽ��� �ڸ����� ����� ������ Ŭ���ִ�. -> ������ �ڵ��ۼ��ؼ� Ȯ���غ���
//��Ģ������: +(���ϱ�).-(����),/(������),*(���ϱ�)
//�� -> ��/60 
//��ü��-��*60 = �������� or ��ü��%60 (�������̿�)
void LightSpeedMain()
{
	float lightSpeed = 30; //���� �ӵ� ������ ����� ���� �ʱ�ȭ�Ѵ�. //30
	float distance = 14960; //�¾�� ���������� �Ÿ� ������ ����� ���� �ʱ�ȭ�Ѵ�. //14960
	float time = distance / lightSpeed; //�� ������ ����� �Ÿ��� �ӵ��� ������ �ɸ� �ð��� ���Ѵ�. // 14960/30 = 498.6666666666667
	printf("Time:%f\n",time); //���� �ð��� ����Ѵ�.
	int m = time / 60; //���ѽð��� ������ �ٲ۴�. 498 / (60 * 8) = 480 ������ 18
	//int c = (int)time % 60;
	int c = time - m * 60; //���ѽð��� ���� �ð��� ���Ѵ�. //498 - (8 * 60) = 18
	printf("%d��%d��",m,c); //���ʷ� ����Ѵ�.
}
//����: ���ϴ� ��. -> ROM(�б�����)�̹Ƿ� ���� ���氡���� �޸𸮴� RAM�̴� �׷��Ƿ�, RAM�� ������ �����Ѵ�. 
// -> RAM�� �ֹ߼�(���Ⱑ������ ����X) ROM�� �����ϰ� �ʿ��Ҷ� RAM�� �����Ѵ�.
// ����Ÿ���� �ִ� -> �������� ǥ���ǹǷ� �� ���������� ǥ���� ��Ī�Ǿ��ִ�. �׷��Ƿ�, �����Ͱ� ��� ����ִ��� ���ĸ��� �ٸ��Ƿ� ������ �ؾ߸��Ѵ�.
// // //�������������� ������ �뵵: �������� ���� �Է¹޾� �����Ͽ� ���α׷��� ���뼺�ְ� �ۼ��Ҽ��ִ�.
//���ǵ��޽ð� ������ �뵵: ?????? 
//�ּ�: �����Ϸ��� �м������ʴ� ����
void main()//���α׷��� ����Ǹ� os���� �ڵ����� ȣ���ϴ� �Լ�
{
	//HelloWorldMain(); //�Լ��� ȣ��: �Լ��� ȣ���ؾ� ����ȴ�.
	//CircleAreaMain();
	//SizeMain();
	//ValueMain();
	//WhyIsGandhiSoViolentMain();
	//ValueIsNumberMain();
	LightSpeedMain();
}