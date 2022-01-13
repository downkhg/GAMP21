//stdio: 표준입출력 라이브러리
#include <stdio.h> 
#define PI 3.141592

void HelloWorldMain()//함수: 코드를 작성하여 기능으로 만드는것. 
{
	//출력기능("문장");
	printf("khg\n");//세미콜론(;): 프로그램 문장의 끝에 들어간다.
	printf("Hello World!\n");//\n: 줄바꿈문자
}
//원의 면적을 구하는 프로그램을 작성하여라.(단, 원의 반지름은 3이다)
//반지름*반지름*3.14 = 원의 넓이
//변수(변경될수있는것): 변수-반지름,원의넓이 //정수? 실수?->정수는 소숫점이 안나오므로 실수를 사용한다.
/*void CircleAreaMain()
{
	int radius = 3;
	int circleArea;

	circleArea = radius * radius * 3.14;

	printf("CircleArea:%d\n", circleArea);
}*/
//변수<-데이터: 변수에는 꼭 필요한 데이터만 넣는다.
//가방<-물건: 필요한 물건을 가방에 넣어다닌다.
//변수: 메모리에 생성되고, 데이터를 담고 다시사용하는데 이용된다.
void CircleAreaMain()
{
	//변수를 초기화하지않으면 무슨값이 들어있는지 알수가없으므로 실행중에 오류가 발생한다.
	float radius = 3;//초기화: 변수를 생성할때 값을 넣는 것. //3
	float circleArea; //?
	const float Pi = 3.141592;//상수변수: 변수에 초기화된 값을 변경할수없음. 
	//Pi = 3; //변수 선언이후에 값을 넣으려고하면 오류가 발생한다.
	printf("radius?");
	scanf("%f", &radius);//프로그램에서 사용할값을 사용자가 지정하기위해서 //5
	
	circleArea = radius * radius * Pi; //변수를 이용하며 값을 변경하기 쉽다. //78.5398 = 5*5*Pi
	//circleArea = 3 * 3 * 3.14;  //상수를 이용하면 코드를 변경하는데 번거롭다.
	//리터럴을 이용한 상수. 변수상수처럼 메모리를 차지하지않고, 컴파일러단에서 PI가 있는 위치에 값을 숫자로 변경해준다.
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


//주석: 컴파일러가 분석하지않는 문장
void main()//프로그램이 실행되면 os에서 자동으로 호출하는 함수
{
	//HelloWorldMain(); //함수의 호출: 함수는 호출해야 실행된다.
	//CircleAreaMain();
	//SizeMain();
	ValueMain();
}