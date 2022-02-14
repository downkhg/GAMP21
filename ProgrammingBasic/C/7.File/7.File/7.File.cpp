﻿#include <stdio.h>
//파일탭: 오른쪽 > 상위폴더열기 > text.txt파일 확인하기
//텍스트파일: 메모장(txt)
void FileTextWirteMain()
{
	FILE* pFile = fopen("text.txt", "w");
	if (pFile)
	{
		int nSize = 10;
		fprintf(pFile, "%d\n", nSize);//1줄 이상입력할땐 첫줄에 길이를 저장한다.
		for (int i = 0; i < nSize; i++)
		{
			char strTextBuffer[128];
			sprintf(strTextBuffer, "GamePrograming%d", i);
			fprintf(pFile, "%s\n", strTextBuffer);
		}
		fclose(pFile);
	}
}
void FileTextReadMain()
{
	FILE* pFile = fopen("text.txt", "r");
	if (pFile)
	{
		int nSize;
		fscanf(pFile, "%d", &nSize); //첫줄에 저장된길이를 가져와 그만큼 반복하여 읽는다.
		printf("nSize:%d\n", nSize);
		for (int i = 0; i < nSize; i++)
		{
			char strReadBuffer[128];
			fscanf(pFile, "%s", strReadBuffer);
			printf("%s\n", strReadBuffer);
		}
		fclose(pFile);
	}
}
//바이너리파일: 이미지(dat,raw)
//파일을 메모리째로 저장하고 읽어온다.
void FileBinaryWirteMain()
{
	const int nWidth = 5;
	const int nHeight = 5;
	unsigned char bufferImage[nWidth * nHeight];
	for (int i = 0; i < nWidth * nHeight; i++)
	{
		bufferImage[i] = 10 * i;
	}

	FILE* pFile = NULL;
	//pFile = fopen("binary.raw", "wb");
	fopen_s(&pFile, "binary.raw", "wb");

	if (pFile)
	{
		fwrite(bufferImage, sizeof(bufferImage), nWidth * nHeight, pFile);
		fclose(pFile);
	}
}
void FileBinaryReadMain()
{
	const int nWidth = 5;
	const int nHeight = 5;
	unsigned char bufferImage[nWidth * nHeight];
	FILE* pFile = NULL;
	//pFile = fopen("binary.raw", "rb");
	fopen_s(&pFile, "binary.raw", "rb");

	if (pFile)
	{
		fread(bufferImage, sizeof(bufferImage), nWidth * nHeight, pFile);
		fclose(pFile);

		for (int y = 0; y < nHeight; y++)
		{
			for (int x = 0; x < nWidth; x++)
			{
				int nIdx = y * nWidth + x;
				printf("%d,", bufferImage[nIdx]);
			}
			printf("\n");
		}

		/*for (int i = 0; i < nWidth * nHeight; i++)
		{
			if (i % 5 == 0) printf("\n");
			printf("%d,", bufferImage[i]);
		}*/
	}
}
//1.파일 쓰기 함수를 실행
//2.파일생성 확인 (상위폴더보기)
//3.파일 읽기 함수 실행
//4.파일에 내용대로 출력되는지 확인하기
//5.텍스트와 바이너리 각각 확인하기.
//6.바이너리파일과 텍스트파일의 차이는 무엇인가?
void main()
{
	//FileTextWirteMain();
	//FileTextReadMain();
	//FileBinaryWirteMain();
	FileBinaryReadMain();
}