//stdio: 표준입출력 라이브러리
//전처리기: 컴파일이전에 처리되는코드
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
	
	//circleArea = radius * radius * Pi; //변수를 이용하며 값을 변경하기 쉽다. //78.5398 = 5*5*Pi
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

#define BYTE unsigned char
//문명에 간디는 왜 폭력적인가?
//간디의 폭력성은 1인데 민주주의를 선택하면 폭력성이 2감소한다. 
//그러므로, 오버플로우가 발생하여 최고값인 255가 되어 폭력성이 최고수치가 되었다.
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
	char cData = 'A';//아스키코드A(65)
	int nData = 65; 
	//변수의 값은 실제로 저장값이 아니라 출력형식에 따라 결과가 다르게 나온다.
	printf("Data(char): %c / %c\n", cData, nData);
	printf("Data(int): %d / %d\n", cData, nData);
}

//태양에서 빛이 지구까지 오는데 걸리는 시간을 계산하여라.
//태양과 지구사이의 거리: 14960만 km
//빛의 속도: 30만 km/s
//빛이 도달하는시간: 14960/30  -> 태양과지구사이거리/빛의속도
//변수: 도달시간, 빛의속도(상수), 태양과지구사이거리(상수) 
//->문자,정수,실수 -> 실수를 쓰는것이 안전하다. -> 왜 정수는 안되는가?  소숫점 자리수가 사라져 오차가 클수있다. -> 정수로 코드작성해서 확인해보기
//사칙연산자: +(더하기).-(빼기),/(나누기),*(곱하기)
//분 -> 초/60 
//전체초-분*60 = 나머지초 or 전체초%60 (나머지이용)
void LightSpeedMain()
{
	float lightSpeed = 30; //빛의 속도 변수를 만들어 값을 초기화한다. //30
	float distance = 14960; //태양과 지구사이의 거리 변수를 만들어 값을 초기화한다. //14960
	float time = distance / lightSpeed; //각 변수에 저장된 거리와 속도를 나누어 걸린 시간을 구한다. // 14960/30 = 498.6666666666667
	printf("Time:%f\n",time); //구한 시간을 출력한다.
	int m = time / 60; //구한시간을 분으로 바꾼다. 498 / (60 * 8) = 480 나머지 18
	//int c = (int)time % 60;
	int c = time - m * 60; //구한시간에 남은 시간을 구한다. //498 - (8 * 60) = 18
	printf("%d분%d초",m,c); //분초로 출력한다.
}
//변수: 변하는 수. -> ROM(읽기전용)이므로 값을 변경가능한 메모리는 RAM이다 그러므로, RAM에 변수를 생성한다. 
// -> RAM은 휘발성(전기가없으면 유지X) ROM에 저장하고 필요할때 RAM에 적제한다.
// 변수타입이 있다 -> 이진수로 표현되므로 각 이진수마다 표현이 매칭되어있다. 그러므로, 데이터가 어떻게 들어있는지 형식마다 다르므로 지정을 해야만한다.
// // //반지름문제에서 변수의 용도: 반지름의 값을 입력받아 변경하여 프로그램을 범용성있게 작성할수있다.
//빛의도달시간 변수의 용도: ?????? 
//주석: 컴파일러가 분석하지않는 문장

//후위연산자와 전위연산자의 차이를 예제를 통해서 살펴보자.
void OperatorPrePostfixMain()
{
	int nDataA = 10; //10
	int nDataB = 20; //20
	int nResultA; //?
	int nResultB; //?

	nResultA = ++nDataA; //11,11
	nResultB = nDataB++; //20,21

	printf("Data/ResultA: %d,%d\n", nDataA, nResultA);
	printf("Data/ResultB: %d,%d\n", nDataB, nResultB);
}
//형변환 테스트 
//float / float -> float
//int / float -> ?
//int / int -> int
void CastingMain()
{
	int nDataA = 10; //10
	int nDataB = 20; //20
	float fDataA = 10.0f; //10.0
	float fDataB = 20.0f; //20.0

	float fResultFF,fResultIF,fResultII;//?,?,?
	int nResultFF, nResultIF, nResultII;//?,?,?

	fResultFF = fDataA / fDataB; //10 / 20 = 0.5
	fResultIF = nDataA / fDataB; //10 / 20 = 0.5
	fResultII = nDataA / nDataB; //10 / 20 = ?

	nResultFF = fDataA / fDataB; //10 / 20 = 0.5
	nResultIF = nDataA / fDataB; //10 / 20 = 0.5
	nResultII = nDataA / nDataB; //10 / 20 = ?

	printf("float-FF/IF/II: %f/%f/%f\n",fResultFF,fResultIF, fResultII);
	printf("int-FF/IF/II: %d/%d/%d\n", nResultFF, nResultIF, nResultII);
}
//숫자가 특정 범위 안에 있는지 검사하는 프로그램
//지정한 범위안에 숫자가 있는지 검사하도록 만든다.(단, 지정범위는 입력을 받아 변경하도록한다)
//min < input < max
//변수: 작은값, 큰값, 입력값
//알고리즘: 작은값보다 입력값이 크고, 입력값은 최대값보다 작을때 범위에 있다면 범위안에 있다고 표시하고, 
//아니면 아니라고 표시하기 
void DistaceValueMain()
{
	int nMin, nMax, nInput;
	printf("min < input < max (ex. 2 < 5 < 10)");
	scanf("%d<%d<%d", &nMin, &nInput, &nMax);
	printf("%d<%d<%d\n", nMin, nInput, nMax);
	bool bCheck = nMin < nInput && nInput < nMax;
	printf("Check:%d\n", bCheck); //결과가 1이나오면 참, 0이나오면 거짓이다.
	if (bCheck)
		printf("%d < %d < %d\n", nMin, nInput, nMax);
	else
		printf("%d is not in range\n", nInput);
}
//윤년계산기: 윤년(4의 나머지가 0이고, 100의 나머지가 0이 아니거나 400의 나머지 0일때)
//변수: 연도 
//알고리즘: 연도는 입력받는다. 연도%4 == 0 .연도%100 != 0 이거나, 연도%400 == 0 의 조건이 모두 만족하면 윤년이다.
//조건식 && 조건식: 조건식을 둘다 만족할때 참
//조건식 || 조건식: 조건식을 둘중 하나라도 만족할때 참
void LeapYearCalculatorMain()
{
	int nYear; //?
	printf("Year is LeapYear?");
	scanf("%d", &nYear); //2022
	//T: 1, F:0
	// F || F -> F
	//(2022 % 4 == 0 ->F && 2022 != 0 -> F) F || 2022%400 == 0 -> F 0
	bool  bCheck = (nYear % 4 == 0 && nYear%100 != 0) || nYear%400 == 0;
	printf("Check:%d\n", bCheck);
	if (bCheck == true)
		printf("%d is LeapYear!",nYear);
	else
		printf("%d is not LeapYear!", nYear);
}
void BitMaskMain()
{
	unsigned int nColor = 0x00385555;
	unsigned int nResult;
	printf("Color:%#08x\n", nColor);
	nResult = nColor & 0x00ff0000;
	printf("BitMaskResult:%#08x\n", nResult);
	nResult = nResult >> 16;
	printf("Result:%#08x\n",nResult);
}
//점수를 입력하면 등급을 계산하도록만든다. //A:90점이상,B:90미만, 80점이상,C:80점미만 70점이상, D:70점미만 60점이상, F: 60미만
//변수: 점수
//알고리즘: 점수를 입력받고, 각 값에 따라서 등급을 출력하도록 만들어라.
//A: 점수 >= 90, B: 80 <= 점수 < 90, C: 70 <= 점수 < 80, D:  60 <= 점수 < 70,  F: 60 > 점수
void GradeCheckMain()
{
	int nSocore = 100;//?
	while (nSocore >= 0)
	{
		printf("Score?");
		scanf("%d", &nSocore);//70
		if (nSocore >= 90) //70 >= 90 -> F
		{
			printf("A\n");
		}
		else if (nSocore >= 80 && nSocore < 90) // 70 >= 80 -> F && 70 < 90 -> T -> F
		{
			printf("B\n");
		}
		else if (nSocore >= 70 && nSocore < 80) // 70 >= 70 -> T && 70 < 80 -> T -> T
		{
			printf("C\n");
		}
		else if (nSocore >= 60 && nSocore < 70) //70 >= 60 -> T && 70 < 70 -> F -> F //else if는 위조건이 만족하면 아래조건은 검사하지않는다.
		{
			printf("D\n");
		}
		else if (nSocore < 60)//70 < 60 ->F
		{
			printf("F\n");
		}
	}
}

void main()//프로그램이 실행되면 os에서 자동으로 호출하는 함수
{
	//HelloWorldMain(); //함수의 호출: 함수는 호출해야 실행된다.
	//CircleAreaMain();
	//SizeMain();
	//ValueMain();
	//WhyIsGandhiSoViolentMain();
	//ValueIsNumberMain();
	//LightSpeedMain();
	//OperatorPrePostfixMain();
	//CastingMain();
	//DistaceValueMain();
	//LeapYearCalculatorMain();
	//BitMaskMain();
	GradeCheckMain();
}