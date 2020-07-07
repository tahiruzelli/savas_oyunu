/*****************************************************************************************************************************************************************
**														SAKARYA ÜNÝVERSÝTESÝ
**														BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**														BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**														PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**														ÖDEV NUMARASI…...:4
**														ÖÐRENCÝ ADI...............:Tahir Uzelli
**														ÖÐRENCÝ NUMARASI.:g181210005
**														DERS GRUBU…………:B
******************************************************************************************************************************************************************/

#include <iostream>
#include <windows.h>
#include <time.h> 
using namespace std;


const int genislik = 80;
const int yukseklik = 20;
char sahne[genislik][yukseklik];
char tuslar[256];
char ucakcizz[5][5];
int i = 1, j = 1, dusmany = 80, dusmanx = 10, dusman2x = 17, dusman2y=80, u = 4, mermix, mermiy, x = 79,x2=79,sayac=3,y=80,v=17,dusman3x=5,dusman3y=80,m=80,n=5,x3=79;

void klavyeoku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
	{
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}
int ateset()
{
	klavyeoku(tuslar);
	if (tuslar[' '] != 0)
	{	
		sahne[u][j + 2] = 177;
		mermix = j + 2;
		mermiy = u;

		return 1;
	}
	return 0;
}
void mermihareket()
{	
	sahne[mermiy][mermix] = 178;
	mermiy++;
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sahneyiciz()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}
}
void sinirlariolustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int y = 0; y < yukseklik; y++)
	{
		sahne[0][y] = 219;
		sahne[genislik-1][y] = 219;
	}
}
void kursorugizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO		cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void sahneyitemizle()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][y]=' ';
		}
	}
}
void ucakkontrol()
{
	klavyeoku(tuslar);
	if (tuslar['W'] != 0)
	{
		j -= 1;		
	}
	if (tuslar['S'] != 0)
	{
		j += 1;
	}
}
void ucakciz()
{
	sahne[i][j] = 219;
	sahne[i + 1][j + 1] = 219;
	sahne[i + 2][j + 2] = 219;
	sahne[i + 1][j + 3] = 219;
	sahne[i][j + 4] = 219;
}
void dusman()
{
	sahne[dusmany][dusmanx] = 254;
	if (dusmany == 0)
	{
		dusmanx = rand() % 15;
		dusmany += 80;
		sayac--;
	}
	
}
int dusman2()
{
	if (dusmany < 60)
	{
		sahne[dusman2y][dusman2y] = 254;
		return 1;

	}
	return 0;
}
int dusman3()
{
	if (dusmany < 40)
	{
		sahne[dusman3y][dusman3y] = 254;
		return 1;
	}
	return 0;
}
void dusman2hareket()
{
	sahne[y][v] = 254;
	if (y == 0)
	{
		v = rand() % 15;
		y += 80;
		sayac--;
	}
	y--;
}
void dusman3hareket()
{
	sahne[m][n] = 254;
	if (m == 0)
	{
		n = rand() % 15;
		m += 80;
		sayac--;
	}
	m--;
}
void patla()
{	
	if ((mermiy == dusmany && mermix == dusmanx) || (mermiy +1 == dusmany && mermix == dusmanx))
	{
		x = mermiy;
	} 
	sahne[x][dusmanx] = ' ';
	if (x == 0)
		x += 79;
	if (x == mermiy)
	{
		dusmany = 80;
		dusmanx = rand() % 15;
	}
}
void patla2()
{
	if ((mermiy == y && mermix == v) || (mermiy + 1 == y && mermix == v))
		x2 = mermiy;
	sahne[x2][v] = ' ';
	if (x2 == 0)
		x2 += 79;
	if (x2 == mermiy)
	{
		y = 80;
		v = rand() % 15;
	}
}
void patla3()
{
	if ((mermiy == m && mermix == n) || (mermiy + 1 == m && mermix == n))
		x3 = mermiy;
	sahne[x2][n] = ' ';
	if (x3 == 0)
		x3 += 79;
	if (x3 == mermiy)
	{
		m = 80;
		n = rand() % 15;
	}
}
void can()
{
	sahne[74][1] = 'C';
	sahne[75][1] = 'a';
	sahne[76][1] = 'n';
	sahne[77][1] = ':';
	sahne[78][1] = '3';
	if (sayac == 2)
		sahne[78][1] = '2';
	if (sayac == 1)
		sahne[78][1] = '1';
	if (sayac == 0)
	{
		sahne[78][1] = '0';
		gotoxy(20,10 );
		cout << "Oldun, sag ustteki carpi isaretinden kapat";
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		system("pause");
	}
}

int main()
{
	kursorugizle();
	int kontrol2=0,kontrol4=0,kontrol6=0;
	while (true)
	{
		srand(time(NULL));
		gotoxy(0, 0);
		sahneyitemizle();
		ucakciz();	
		dusman();		
		patla();
		patla2();
		patla3();
		can();
		int kontrol = ateset();
		if (kontrol == 1)
			kontrol2 = 1;
		if (kontrol2 == 1)
		{
			mermihareket();
			if (u == 80)
				kontrol2 = 0;
		}
		int kontrol3 = dusman2();
		if (kontrol3 == 1)
			kontrol4 = 1;
		if (kontrol4 == 1)
		{
			dusman2hareket();
			if (y == 80)
				kontrol4 = 0;
		}
		int kontrol5 = dusman3();
		if (kontrol5 == 1)
			kontrol6 = 1;

		if (kontrol6 == 1)
		{
			dusman3hareket();
			if (m == 80)
				kontrol6 = 0;
		}
		sinirlariolustur();
		sahneyiciz();	
		ucakkontrol();
		dusmany--;
		x--;
		x2--;
		x3--;
	}
	system("pause");
	return 0;
} 