#include <stdio.h>
//세균은 10마리를 배양하고 4시간 이후에 세균의 수는?
//세균은 1시간마다 2배씩 증가한다.
//데이터: 세균수,시간
//알고리즘: 세균수*2, 1시간마다, 100마리 이상이될때까지
//1.데이터와 알고리즘을 분리한다.
//2.데이터는 변수 알고리즘은 연산,반복,조건 등이 조합된다.
//3.반복되는 경우는 먼저 반복하고 정답을 출력한다.
/*
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	nBateria = nBateria * 2;//20
	nTime = 1;

	nBateria = nBateria * 2;//40
	nTime = 2;

	nBateria = nBateria * 2;//80
	nTime = 3;

	nBateria = nBateria * 2;//160
	nTime = 4;

	printf("Time:%d\n", nTime);
}
*/
//4.반복되는 규칙성을 찾아서 무한반복을 돌린후 반복된 과정을 모두 확인한다.
//(프로그래머가 아니라면 여기서 마쳐도 무방함. 그러나 정치질(약점잡아 늘어지기)에 희생량이 될수있음)
/*
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while (true)
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		if (nBateria > 100) break;
	}
}
*/
//5.break문의 조건을 반대로 if문에 넣는다.(초과,미만:불포함  이상,이하:포함)
//세균은 10마리를 배양하고 세균수가 100마리 이상이 되는 시간은?
//세균은 1시간마다 2배씩 증가한다.
//데이터: 세균수,시간
//알고리즘: 세균수*2, 1시간마다, 100마리 이상이될때까지
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while (nBateria <= 100)
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria > 100) break;
	}
}

//종이를 접으면 (면적)이 (1/2로 줄어)들때,
//(종이면적이 1/10이하)로 줄어들려면, (몇번접)아야하는가?
//데이터: 면적, 횟수, 0.5
void PaperAreaMain()
{
	float fPaperArea = 100; // 10
	int nCount = 0;

	//fPaperArea = fPaperArea * 0.5f; //100*0.5 = 50
	//nCount = 1;

	//fPaperArea = fPaperArea * 0.5f; //50*0.5 = 25
	//nCount = 2;

	//fPaperArea = fPaperArea * 0.5f; //25*0.5 = 12.5
	//nCount = 3;

	//fPaperArea = fPaperArea * 0.5f; //12.5*0.5 = 6.25
	//nCount = 4;

	while (true)
	{
		fPaperArea = fPaperArea * 0.5f; //100*0.5 = 50
		nCount++;
		printf("Area/Count:%f/%d\n",fPaperArea,nCount);
		if (fPaperArea < 10) break;
	}
	printf("Count:%d\n", nCount);
}

//(세균:변수) 10마리를 배양하여 (10시간후:조건)의 세균수를 구하여라.
//이때, 세균이 (1시간 마다 4배)찍 증가한다 
//세균수:10 //시간:0  //세균수*=4
void BateriaCountMain()
{

}


//업다운게임: 
//숫자를 제시하면 그 숫자가 정해진수 보다 작으면, down 크면 up 맞추면 끝.
//1.(정답 Q) 은 정해져있다.
//2.정답보다 (큰수)를  (A 입력)받으면 up이라고 출력
//3.정답보다 (작은수)를 (A 입력)받으면 down이라고 출력
//4.정답이 아니라면 다시 입력받음.
//5.정답이라면 게임을 끝낸다.
//정답을 랜덤으로 생성하도록 만들기
void UpDownGameMain()
{

}
/* 다음모양을 출력하라.
해당모양의 이름의 함수안에 조건만 변경하여 해당모양이 출력되도록만들기
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.규칙을 찾는다.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> 홀수
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.규칙대로 조건을 모두 준다.
//
//3.규칙에서 줄일만한 부분이 없는지 찾는다.
//(조건문없이가능) -> y가 증가할때마다 x의 값이 증가한다.
// 01234
//0#####\n
//1#####\n
//2#####\n
//3#####\n
//4#####\n
void RectMain()
{
	for (int y = 0; y < 5; y++)//0 ; 0<5->T ; 0++ // 1<5->T
	{
		for (int x = 0; x < 5; x++)//0; 0<5;0++ // 1 < 5->T ; 1++// 2 < 5->T; 2++ // 3<5->T; 3++ //4<5->T 4++ //5<5->F
		{
			printf("#");
		}
		printf("\n");
	}
}
void WindowMain()
{

}
void StiarMain()
{

}

void main()
{
	//BateriaMain();
	PaperAreaMain();
}