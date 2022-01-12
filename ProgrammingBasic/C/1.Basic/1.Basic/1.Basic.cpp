//stdio: 표준입출력 라이브러리
#include <stdio.h> 

void HelloWorldMain()//함수: 코드를 작성하여 기능으로 만드는것. 
{
	//출력기능("문장");
	printf("khg\n");//세미콜론(;): 프로그램 문장의 끝에 들어간다.
	printf("Hello World!\n");//\n: 줄바꿈문자
}
//원의 면적을 구하는 프로그램을 작성하여라.(단, 원의 반지름은 3이다)
//반지름*반지름*3.14 = 원의 넓이
//변경될수있는것: 변수-반지름,원의넓이 //정수? 실수?->정수는 소숫점이 안나오므로 실수를 사용한다.
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

//주석: 컴파일러가 분석하지않는 문장
void main()//프로그램이 실행되면 os에서 자동으로 호출하는 함수
{
	HelloWorldMain(); //함수의 호출: 함수는 호출해야 실행된다.
	CircleAreaMain();
}