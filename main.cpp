#include <iostream>
#include <ctime>
#include <windows.h>
#include<cstdlib>
#include<stdio.h>
#include "conio2.h"
#define DOL		0
#define GORA	1
#define PRAWO	2
#define LEWO	3
#define PRZOD 1
#define TYL 2
#define META 3
#define OBECNIE 4
#define ZAMKNIETE 5
#define ZAMKNIETE1 21
#define ZAMKNIETE2 22
#define OTWARTE 6
#define OTWARTE1 44
#define OTWARTE2 14
#define WOLNE 7
#define SCIANA1 8
#define SCIANA2 9
#define SCIANA3 10
#define SCIANA4 11
#define SCIANA5 12
#define SCIANA 13
#define DRZWI_EDYTOR 15
#define START_EDYTOR 16
#define META_EDYTOR 17
#define WLEWO 1
#define WPRAWO 2
#define PoczatekX 8
#define PoczatekY 3
using namespace std;
//sciana po boku jak wczesniej wolne
//rysowanie najkrótszej drogi
//edytor 
/* Uwaga: w docelowym programie nalezy zadeklarowac odpowiednie
   stale, na przyklad po to, aby wyeliminowac z programu
   wartosci numeryczne umieszczajac w ich miejsce 
   dobrze dobrane identyfikatory */
   	void ResetujPlansze(int **Pola, int &kierunek, int &x, int &y, int &M, int &N, int &startX, int &startY, int &kierunekPoczatkowy)
   	{
   		for(int i=0; i<N; i++)
   		{
   			for(int j=0; j<M; j++)
   			{
   				if(Pola[i][j]==OTWARTE || Pola[i][j]==OTWARTE1 || Pola[i][j]==OTWARTE2)
   				Pola[i][j]=ZAMKNIETE;
   			}
   		}
   		cout<<Pola[y][x];
   		if(Pola[y][x]!=ZAMKNIETE)
   	 	Pola[y][x]=WOLNE;
   		kierunek=kierunekPoczatkowy;
   		x=startX;
   		y=startY;
   		Pola[y][x]=OBECNIE;
   	}
    int Sciana()
   {
   	int jaka=((rand()%5)+1);
   	if(jaka==1)
   	return SCIANA1;
   	if(jaka==2)
   	return SCIANA2;
   	if(jaka==3)
   	return SCIANA3;
   	if(jaka==4)
   	return SCIANA4;
   	if(jaka==5)
   	return SCIANA5;
   }
   	void ZapiszEdytor(int **Edytor, int &edytor_m, int &edytor_n)
   	{
   		clrscr();
		FILE *plik;
		string nazwa="";
		char bufor=0;;
		gotoxy(44,15);
		cout<<"Wprowadz nazwe pliku";
		gotoxy(50,16);
		  cin.clear(); //kasowanie flagi b³êdu strumienia
  cin.sync(); //kasowanie zbêdnych znaków z bufora
     	while((bufor=getchar())!= '\n' && bufor!=EOF && bufor!='\r')
     	{ 		
     		if(bufor=='\b')
     		{
     			nazwa="";
     			clrscr();
     			gotoxy(44,15);
		cout<<"Wprowadz nazwe pliku";
      			gotoxy(50,16);    			
     		}
     		else
     		{
     		nazwa=nazwa+bufor;
     		cout<<bufor;
     		}
     	}
     			  cin.clear(); //kasowanie flagi b³êdu strumienia
  cin.sync(); //kasowanie zbêdnych znaków z bufora
     	while(kbhit()) getch(); 
     	plik = fopen(nazwa.c_str(), "w" );
		fprintf(plik, "%d\n", edytor_m);		
		fprintf(plik, "%d", edytor_n);
		fprintf(plik, "\n");
		for(int i=0; i<edytor_n; i++)
	{
			for(int j=0; j<edytor_m; j++)
			{			switch(Edytor[i][j])	
			{
				case WOLNE:
									fprintf(plik, "0 ");
					break;
				case SCIANA:
				case SCIANA1:
				case SCIANA2:
				case SCIANA3:
				case SCIANA4:
				case SCIANA5:
									fprintf(plik, "1 ");					
				break;
				case DRZWI_EDYTOR:
										fprintf(plik, "2 ");			
				break;
				case META_EDYTOR:
										fprintf(plik, "4 ");	
										break;			
				case START_EDYTOR:	
				fprintf(plik,"3 ");
				break;			
				}
				}
			fprintf(plik, "\n");	
		}
		fclose(plik);
   	}
   void Zapisz(int **Plansza, int &kierunek, int &x, int &y, int &M, int &N, int &startX, int &startY, int &kierunekPoczatkowy)
   {
		clrscr();
		FILE *plik;
		string nazwa="";
		char bufor=0;;
		gotoxy(44,15);
		cout<<"Wprowadz nazwe pliku";
		gotoxy(50,16);
		     	cin.clear();
     	cin.sync();
     	while((bufor=getchar())!= '\n' && bufor!=EOF && bufor!='\r')
     	{ 		
     		if(bufor=='\b')
     		{
     			nazwa="";
     			clrscr();
     			gotoxy(44,15);
		cout<<"Wprowadz nazwe pliku";
      			gotoxy(50,16);    			
     		}
     		else
     		{
     		nazwa=nazwa+bufor;
     		cout<<bufor;
     		}
     	}
     	cin.clear();
     	cin.sync();
     	while(kbhit()) getch(); 
     	plik = fopen(nazwa.c_str(), "w" );
		fprintf(plik, "%d\n", M);		
		fprintf(plik, "%d", N);
		fprintf(plik, "\n");
		for(int i=0; i<N; i++)
	{
			for(int j=0; j<M; j++)
			{			switch(Plansza[i][j])	
			{
				case WOLNE:
									fprintf(plik, "0 ");
					break;
				case SCIANA:
				case SCIANA1:
				case SCIANA2:
				case SCIANA3:
				case SCIANA4:
				case SCIANA5:
									fprintf(plik, "1 ");					
				break;
				case ZAMKNIETE1:
				case ZAMKNIETE2:
				case ZAMKNIETE:
				case OTWARTE1:
				case OTWARTE2:
					case OTWARTE:
										fprintf(plik, "2 ");			
				break;
				case META:
										fprintf(plik, "4 ");	
										break;			
				case OBECNIE:
											fprintf(plik, "3 ");	
							break;		
				
				}
				}
			fprintf(plik, "\n");	
		}
		fclose(plik);
   }
   	bool Sprawdz(int **Edytor, int M, int N)
   	{
   		int Start=0,Meta=0;
   					for(int i=0; i<N; i++)
   					{
   						for(int j=0;j<M;j++)
   						{
   											if(Edytor[i][j]==START_EDYTOR)
				Start++;
				if(Edytor[i][j]==META_EDYTOR)
				Meta++;								
			if(i<N-1 && j<M-1 && Edytor[i][j+1]==WOLNE && Edytor[i+1][j]==WOLNE && Edytor[i+1][j+1]==WOLNE && Edytor[i][j]==WOLNE)	
			return 0;	
			if(Start>1 || Meta>1)
			return 0;
   						}
   					}
   					return 1;
   				}
   	int Wczytaj(int **Plansza, int &kierunek, int &x, int &y, int &M, int &N, int &startX, int &startY, int &kierunekPoczatkowy)
	{
		clrscr();
		int x1=-1,y1=-1,M1=-1,N1=-1;
		FILE *plik;
		string nazwa="";
		char bufor=0;
		do
		{
		gotoxy(44,15);
		cout<<"Wprowadz nazwe pliku, q aby wyjsc.";
		gotoxy(50,16);
		  cin.clear(); //kasowanie flagi b³êdu strumienia
  cin.sync(); //kasowanie zbêdnych znaków z bufora
     	while((bufor=getchar())!= '\n' && bufor!='\r')
     	{
     		
     		if(bufor=='\b')
     		{
     			nazwa="";
     			clrscr();
     			gotoxy(44,15);
		cout<<"Wprowadz nazwe pliku, q aby wyjsc.";
      			gotoxy(50,16);    			
     		}
     		else
     		{
     		nazwa=nazwa+bufor;
     		cout<<bufor;
     		}
     	}
     			  cin.clear(); //kasowanie flagi b³êdu strumienia
  cin.sync(); //kasowanie zbêdnych znaków z bufora
		if((plik=fopen(nazwa.c_str(), "r"))==NULL)
		{
			     			nazwa="";
					clrscr();
			gotoxy(44,13);
			cout<<"Wprowadzona nazwa: "<<nazwa<<" jest nieprawidlowa";
			if(nazwa=="q")
			{
				return false;
			}
		gotoxy(44,14);
		cout<<"Wprowadz nazwe ponownie";
		}
		else
		{
		break;
		}
		}	while(1);
		while(kbhit()) getch(); 
		fscanf(plik, "%d", &M1);
		fscanf(plik, "%d", &N1);
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{				
				fscanf(plik, "%d", &Plansza[i][j]);
				switch(Plansza[i][j])
				{
					case 0:
						Plansza[i][j]=WOLNE;
					break;
					case 1:
						Plansza[i][j]=Sciana();
					break;
					case 2:
						Plansza[i][j]=ZAMKNIETE;
					break;
					case 3:
						Plansza[i][j]=OBECNIE;
						x1=j; startX=j; y1=i; startY=i;
					break;				
					case 4:
						Plansza[i][j]=META;
					break;	
					default:
					return false;
						break;
				}
			}
		}
				fclose(plik);
		if(	Sprawdz(Plansza, M1, N1)==0)
		{
			M=M1;N=N1;
		return 2;
		}
		else
		{
			x=x1;y=y1;M=M1;N=N1;
		}
		kierunek=PRAWO;kierunekPoczatkowy=PRAWO;
		return 1;
	}
   void Wygrana(int roznica, int ruchy)
{
	int godziny=0, minuty=0, sekundy=roznica;
			while(sekundy>=60)
		{
			sekundy-=60;
			minuty++;
		}
		while(minuty>=60)
		{
			minuty-=60;
			godziny++;
		}
					gotoxy(42,20);
			cout<<"Gratuluje";
			gotoxy(42,21);
			cout<<"Przeszedles/as labirynt w "<<ruchy<<" ruchach";
			gotoxy(42,22);
	cout<<"Trwalo to ";
	if(godziny==1)
	cout<<"1 godzine ";
	if(godziny>1)
	{
		if(godziny>4)
		{
			cout<<godziny<<" godzin ";
		}
		else
		{
	std::cout<<godziny<<" godziny ";
    }
   }
	if(minuty==1)
		cout<<"1 minute ";
	if(minuty>1)
	{
		if(minuty>4)
		{
			cout<<minuty<<" minut ";
		}
		else
		{
	cout<<minuty<<" minuty ";
     }
}
	if(sekundy==1)
	{
	cout<<"1 sekunde."<<endl;
   }
   else
   {
   	if(sekundy!=0)
   	{
	if(sekundy<=4 || sekundy>=22 && sekundy<=24 || sekundy>=32 && sekundy<=34 || sekundy>=42 && sekundy<=44 || sekundy>=42 && sekundy<=44)
	{
	cout<<sekundy<<" sekundy.";
   }
   else
   {
   	cout<<sekundy<<" sekund.";
   }
}
}
   					if(getch()==0)
		getch();
}
	void GenerujDomyslny(int **Plansza,int &kierunek,int &x,int &y, int &M, int &N, int &startY, int &startX, int &kierunekPoczatkowy)
	{
		M=20, N=20;
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				Plansza[i][j]=WOLNE;
				if(i==0 || i==19 || j==0 || j==19)
				Plansza[i][j]=Sciana();
			}
		}
		Plansza[1][14]=Sciana();
		Plansza[2][2]=Sciana();
		Plansza[2][3]=Sciana();
		Plansza[2][4]=Sciana();
		Plansza[2][5]=Sciana();
		Plansza[2][6]=Sciana();
		Plansza[2][7]=Sciana();
		Plansza[2][8]=Sciana();
		Plansza[2][9]=Sciana();
		Plansza[2][10]=Sciana();
		Plansza[2][12]=Sciana();
		Plansza[2][14]=Sciana();
		Plansza[2][16]=Sciana();
		Plansza[3][5]=Sciana();
		Plansza[3][12]=Sciana();
		Plansza[3][14]=Sciana();
		Plansza[1][14]=Sciana();
		Plansza[3][16]=Sciana();
		Plansza[2][16]=Sciana();
		Plansza[6][14]=Sciana();
		Plansza[3][18]=Sciana();
		Plansza[3][15]=Sciana();
		Plansza[1][14]=Sciana();
		Plansza[4][1]=Sciana();
		Plansza[4][2]=Sciana();
		Plansza[4][3]=Sciana();
		Plansza[4][5]=Sciana();
		Plansza[4][7]=Sciana();
		Plansza[4][8]=Sciana();
		Plansza[4][9]=Sciana();
		Plansza[4][10]=Sciana();
		Plansza[4][11]=Sciana();
		Plansza[4][12]=Sciana();
		Plansza[4][14]=Sciana();
		Plansza[5][5]=Sciana();
		Plansza[5][7]=Sciana();
		Plansza[5][9]=Sciana();
		Plansza[5][14]=Sciana();
		Plansza[5][16]=Sciana();
		Plansza[5][17]=Sciana();
		Plansza[6][2]=Sciana();
		Plansza[6][3]=Sciana();
		Plansza[6][5]=Sciana();
		Plansza[6][7]=Sciana();
		Plansza[6][9]=Sciana();
		Plansza[6][11]=Sciana();
		Plansza[6][12]=Sciana();
		Plansza[6][13]=Sciana();		
		Plansza[7][3]=Sciana();
		Plansza[7][9]=Sciana();		
		Plansza[7][16]=Sciana();
		Plansza[7][17]=Sciana();
		Plansza[8][1]=Sciana();
		Plansza[8][3]=Sciana();
		Plansza[8][4]=Sciana();
		Plansza[8][5]=Sciana();
		Plansza[8][6]=Sciana();
		Plansza[8][7]=Sciana();
		Plansza[8][9]=Sciana();
		Plansza[8][10]=Sciana();
		Plansza[8][11]=Sciana();
		Plansza[8][12]=Sciana();
		Plansza[8][14]=Sciana();
		Plansza[8][15]=Sciana();
		Plansza[8][16]=Sciana();
		Plansza[9][3]=Sciana();
		Plansza[9][7]=Sciana();
		Plansza[9][9]=Sciana();
		Plansza[9][14]=Sciana();
		Plansza[9][16]=Sciana();
		Plansza[9][17]=Sciana();
		Plansza[9][18]=Sciana();
		Plansza[10][2]=Sciana();
		Plansza[10][3]=Sciana();
		Plansza[10][5]=Sciana();
		Plansza[10][7]=Sciana();
		Plansza[10][9]=Sciana();
		Plansza[10][10]=Sciana();
		Plansza[10][11]=Sciana();
		Plansza[10][12]=Sciana();
		Plansza[10][14]=Sciana();
		Plansza[11][5]=Sciana();
		Plansza[11][7]=Sciana();
		Plansza[11][9]=Sciana();
		Plansza[11][14]=Sciana();
		Plansza[11][16]=Sciana();
		Plansza[11][17]=Sciana();
		Plansza[12][1]=Sciana();
		Plansza[12][2]=Sciana();
		Plansza[12][3]=Sciana();
		Plansza[12][4]=Sciana();
		Plansza[12][5]=Sciana();
		Plansza[12][7]=Sciana();
		Plansza[12][9]=Sciana();
		Plansza[12][11]=Sciana();
		Plansza[12][12]=Sciana();
		Plansza[12][13]=Sciana();
		Plansza[12][14]=Sciana();
		Plansza[12][16]=Sciana();
		Plansza[13][2]=Sciana();
		Plansza[13][7]=Sciana();
		Plansza[13][9]=Sciana();
		Plansza[13][12]=Sciana();
		Plansza[13][16]=Sciana();
		Plansza[13][18]=Sciana();
		Plansza[14][4]=Sciana();
		Plansza[14][6]=Sciana();
		Plansza[14][7]=Sciana();
		Plansza[14][9]=Sciana();
		Plansza[14][10]=Sciana();
		Plansza[14][12]=Sciana();
		Plansza[14][14]=Sciana();
		Plansza[14][15]=Sciana();
		Plansza[14][16]=Sciana();
		Plansza[14][11]=Sciana();
		Plansza[14][12]=Sciana();
		Plansza[14][14]=Sciana();
		Plansza[15][2]=Sciana();
		Plansza[15][3]=Sciana();
		Plansza[15][4]=Sciana();
		Plansza[15][6]=Sciana();
		Plansza[15][12]=Sciana();
		Plansza[15][14]=Sciana();
		Plansza[15][16]=Sciana();
		Plansza[15][17]=Sciana();
		Plansza[16][2]=Sciana();
		Plansza[16][6]=Sciana();
		Plansza[16][7]=Sciana();
		Plansza[16][8]=Sciana();
		Plansza[16][9]=Sciana();
		Plansza[16][10]=Sciana();
		Plansza[16][11]=Sciana();
		Plansza[16][12]=Sciana();
		Plansza[16][14]=Sciana();
		Plansza[17][2]=Sciana();
		Plansza[17][3]=Sciana();
		Plansza[17][4]=Sciana();
		Plansza[17][5]=Sciana();
		Plansza[17][6]=Sciana();
		Plansza[17][8]=Sciana();
		Plansza[17][12]=Sciana();
		Plansza[17][14]=Sciana();
		Plansza[17][16]=Sciana();
		Plansza[17][17]=Sciana();
		Plansza[17][18]=Sciana();
		Plansza[18][10]=Sciana();
		Plansza[18][14]=Sciana();
		Plansza[19][16]=Sciana();
		Plansza[19][16]=OBECNIE;
		startY=19;
		startX=16;
		Plansza[0][4]=META;
		 x=16;
		 y=19;
		 kierunek=GORA, kierunekPoczatkowy=GORA;
	}
	void Rysuj(int **Plansza,int kierunek,int y,int x, int M, int N, int kolor, int coRobic)
	{
		gotoxy(PoczatekX,PoczatekY);
			HANDLE uchwyt;
		uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD zwykleKolory;
		CONSOLE_SCREEN_BUFFER_INFO screen_info;
		GetConsoleScreenBufferInfo(uchwyt, &screen_info);
		zwykleKolory = screen_info.wAttributes;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				if(coRobic==1 && x==j && y==i)
				{
						SetConsoleTextAttribute(uchwyt, BACKGROUND_INTENSITY);
				switch(Plansza[i][j])
				{
					case SCIANA1:
						std::cout<<"#";
					break;
					case SCIANA2:
						std::cout<<"&";
					break;
					case SCIANA3:
						std::cout<<"@";
					break;
					case SCIANA4:
						std::cout<<"%";
					break;
					case SCIANA5:
						std::cout<<"$";
					break;										
			case WOLNE:
			cout<<" ";
			break;
			case DRZWI_EDYTOR:
			cout<<"D";
			break;
			case START_EDYTOR:
			cout<<"S";
			break;
			case META_EDYTOR:
			cout<<"M";
			break;																			
				}										
			}
			else
			{
				
				switch(Plansza[i][j])
				{
			case DRZWI_EDYTOR:
										SetConsoleTextAttribute(uchwyt, BACKGROUND_INTENSITY);
			cout<<"D";
										SetConsoleTextAttribute( uchwyt, zwykleKolory );		
			break;	
			case START_EDYTOR:
						SetConsoleTextAttribute(uchwyt, BACKGROUND_INTENSITY);						
			cout<<"S";
									SetConsoleTextAttribute( uchwyt, zwykleKolory );			
			break;
			case META_EDYTOR:
						SetConsoleTextAttribute(uchwyt, BACKGROUND_INTENSITY);						
			cout<<"M";	
									SetConsoleTextAttribute( uchwyt, zwykleKolory );			
			break;					
					case SCIANA1:
						std::cout<<"#";
					break;
					case SCIANA2:
						std::cout<<"&";
					break;
					case SCIANA3:
						std::cout<<"@";
					break;
					case SCIANA4:
						std::cout<<"%";
					break;
					case SCIANA5:
						std::cout<<"$";
					break;
					case ZAMKNIETE1:
						std::cout<<"-";
						continue;
						break;
						case ZAMKNIETE2:
						std::cout<<"|";
						continue;
						break;	
					case OTWARTE1:
						if(kolor<14)
				textcolor(kolor+2);
				else
				textcolor((kolor+2)%16);
				if(y==i && x==j)
				{
					
					if(kierunek==DOL)
								putch('v');
							if(kierunek==GORA)
								putch('^');
							if(kierunek==PRAWO)
								putch('>');
							if(kierunek==LEWO)
								putch('<');
				}
				else					
					{
						textcolor(kolor);
					std::cout<<"\\";}
									textcolor(kolor);
					break;
					case OTWARTE2:
						if(kolor<14)
				textcolor(kolor+2);
				else
				textcolor((kolor+2)%16);
				if(y==i && x==j)
				{
					if(kierunek==DOL)
								putch('v');
							if(kierunek==GORA)
								putch('^');
							if(kierunek==PRAWO)
								putch('>');
							if(kierunek==LEWO)
								putch('<');
				}
				else
				{	
				textcolor(kolor);
					std::cout<<"/";
				}
								textcolor(kolor);
					break;
				break;											
					case OTWARTE:
						if(Plansza[i+1][j]==OBECNIE || Plansza[i][j-1]==OBECNIE)//Otwieranie z do³u lub z lewej
						{ 
						std::cout<<"\\";
						Plansza[i][j]=OTWARTE1;
						}
						if(Plansza[i][j+1]==OBECNIE || Plansza[i-1][j]==OBECNIE) //Otwieranie z góry lub prawej
						{
							std::cout<<"/";
							Plansza[i][j]=OTWARTE2;
						}
					break;
				case ZAMKNIETE:
						if(Plansza[i-1][j]==WOLNE || Plansza[i+1][j]==WOLNE)
						{
						std::cout<<"-";
						Plansza[i][j]=ZAMKNIETE1;
						continue;
						}
						if(Plansza[i][j-1]==WOLNE || Plansza[i][j+1]==WOLNE)
						{
						std::cout<<"|";
						Plansza[i][j]=ZAMKNIETE2;
						continue;
						}
					break;	
					case OBECNIE:
						if(kolor<14)
				textcolor(kolor+2);
				else
				textcolor((kolor+2)%16);
							if(kierunek==DOL)
								putch('v');
							if(kierunek==GORA)
								putch('^');
							if(kierunek==PRAWO)
								putch('>');
							if(kierunek==LEWO)
								putch('<');
								textcolor(kolor);
					break;	
					case WOLNE:
						std::cout<<" ";
					break;	
					case META:
						std::cout<<" ";		
					break;														
				}
				}
									SetConsoleTextAttribute( uchwyt, zwykleKolory );				
			}
			gotoxy(PoczatekX, PoczatekY+i+1);
		}
		gotoxy(1,1);
	}
	void Drzwi(int *Plansza[], int kierunek, int x, int y)
	{
		switch(kierunek)
		{
			case DOL:
				if(Plansza[y+1][x]==ZAMKNIETE || Plansza[y+1][x]==ZAMKNIETE1 || Plansza[y+1][x]==ZAMKNIETE2 )
				{
				Plansza[y+1][x]=OTWARTE;}
				else{
				
				
				if(Plansza[y+1][x]==OTWARTE || Plansza[y+1][x]==OTWARTE1 || Plansza[y+1][x]==OTWARTE2)
				{Plansza[y+1][x]=ZAMKNIETE;}
				}
			break;
			case GORA:
				if(Plansza[y-1][x]==ZAMKNIETE || Plansza[y-1][x]==ZAMKNIETE1 || Plansza[y-1][x]==ZAMKNIETE2)
				{
				Plansza[y-1][x]=OTWARTE;
				}
				else{
				if(Plansza[y-1][x]==OTWARTE || Plansza[y-1][x]==OTWARTE1 || Plansza[y-1][x]==OTWARTE2)
				{Plansza[y-1][x]=ZAMKNIETE;}
				}
			break;
			case PRAWO:
				if(Plansza[y][x+1]==ZAMKNIETE || Plansza[y][x+1]==ZAMKNIETE1 || Plansza[y][x+1]==ZAMKNIETE2)
				{
				Plansza[y][x+1]=OTWARTE;
				}else
				{
				if(Plansza[y][x+1]==OTWARTE || Plansza[y][x+1]==OTWARTE1 || Plansza[y][x+1]==OTWARTE2)
				{	Plansza[y][x+1]=ZAMKNIETE;}
				}
			break;
			case LEWO:
				if(Plansza[y][x-1]==ZAMKNIETE || Plansza[y][x-1]==ZAMKNIETE1 || Plansza[y][x-1]==ZAMKNIETE2)
				{
				Plansza[y][x-1]=OTWARTE;
			}else
			{
				if(Plansza[y][x-1]==OTWARTE || Plansza[y][x-1]==OTWARTE1 || Plansza[y][x-1]==OTWARTE2)
				{Plansza[y][x-1]=ZAMKNIETE;	}
			}
			break;			
		}
	}
	int WykonajObrot( int kierunek, int Strona)
	{
		if(kierunek==DOL)
		{
			if(Strona==WPRAWO)
			return LEWO;
			return PRAWO;
		}
				if(kierunek==GORA)
		{
			if(Strona==WPRAWO)
			return PRAWO;
			return LEWO;
		}
				if(kierunek==PRAWO)
		{
			if(Strona==WPRAWO)
			return DOL;
			return GORA;
		}
				if(kierunek==LEWO)
		{
			if(Strona==WPRAWO)
			return GORA;
			return DOL;
		}
		return 0;
	}
	void Tekstury(char **Trzy_D, int Widok[8][3], int gora, int dol, int Poczatek, int Koniec, int strona, int glebokosc)
	{
		char znak;
		bool czyDrzwi=0;
		int jakaSciana;
				jakaSciana=Widok[glebokosc][strona];		
				switch(jakaSciana)
				{
					case SCIANA1:
					znak='#';
					break;
					case SCIANA2:
					znak='&';
					break;
					case SCIANA3:
					znak='@';
					break;
					case SCIANA4:
					znak='%';
					break;
					case SCIANA5:
					znak='$';
					break;
					case ZAMKNIETE2:
					case ZAMKNIETE:
					case ZAMKNIETE1:
					czyDrzwi=1;
					break;
				}
					if(czyDrzwi==0)		
					{
		for(int i=gora; i<dol;i++)
		{
			for(int j=Poczatek;j<Koniec;j++)
				{
					Trzy_D[i][j]=znak;
				}	
		}
		}
		else
		{
			if((Poczatek+Koniec)%2==1)
			Poczatek++;
			if((gora+dol)%2==1)
			gora++;
			Trzy_D[(gora+dol)/2][(Poczatek+Koniec)/2]='|';
			Trzy_D[(gora+dol)/2][(Poczatek+Koniec)/2+1]='_';			
		}
}
	int WykonajRuch (int **Plansza, int kierunek, int Wktora, int &x, int &y, int M, int N, time_t koniec, time_t start, int &ileRuchow, int roznica)
	{	
		switch(Wktora)
		{
			case PRZOD:
				switch(kierunek)
				{
				case DOL:
						if(y<N-1 && (Plansza[y+1][x]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						y++;
						}					
						if(y<N-1 && (Plansza[y+1][x]==WOLNE ||Plansza[y+1][x]==OTWARTE || Plansza[y+1][x]==OTWARTE1 || Plansza[y+1][x]==OTWARTE2))
						{
							
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y+1][x]!=OTWARTE && Plansza[y+1][x]!=OTWARTE1 && Plansza[y+1][x]!=OTWARTE2 )
							Plansza[y+1][x]=OBECNIE;
							y++;
							ileRuchow++;
						}
						break;
					case GORA:
						if(y>0 && (Plansza[y-1][x]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						y--;
						}						
						if(y>0 && (Plansza[y-1][x]==WOLNE ||Plansza[y-1][x]==OTWARTE|| Plansza[y-1][x]==OTWARTE1 || Plansza[y-1][x]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y-1][x]!=OTWARTE && Plansza[y-1][x]!=OTWARTE1 && Plansza[y-1][x]!=OTWARTE2 )
							Plansza[y-1][x]=OBECNIE;
							y--;
							ileRuchow++;
						}
						break;
					case PRAWO:	
						if(y<M-1 && (Plansza[y][x+1]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						x++;
						}								
						if(x<M-1 && (Plansza[y][x+1]==WOLNE ||Plansza[y][x+1]==OTWARTE|| Plansza[y][x+1]==OTWARTE1 || Plansza[y][x+1]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y][x+1]!=OTWARTE && Plansza[y][x+1]!=OTWARTE1 && Plansza[y][x+1]!=OTWARTE2 )
								Plansza[y][x+1]=OBECNIE;
							x++;
							ileRuchow++;
						}
						break;
					case LEWO:
						if(x>0 && (Plansza[y][x-1]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						x--;
						}						
						if(x>0 && (Plansza[y][x-1]==WOLNE ||Plansza[y][x-1]==OTWARTE|| Plansza[y][x-1]==OTWARTE1 || Plansza[y][x-1]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y][x-1]!=OTWARTE && Plansza[y][x-1]!=OTWARTE1 && Plansza[y][x-1]!=OTWARTE2 )
							Plansza[y][x-1]=OBECNIE;
							x--;
							ileRuchow++;
						}						
						break;												
					
				}
			break;
			case TYL:
				switch(kierunek)
				{
					case DOL:
						if(y>0 && (Plansza[y-1][x]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						y--;
						}						
						if(y>0 && (Plansza[y-1][x]==WOLNE ||Plansza[y-1][x]==OTWARTE|| Plansza[y-1][x]==OTWARTE1 || Plansza[y-1][x]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y-1][x]!=OTWARTE && Plansza[y-1][x]!=OTWARTE1 && Plansza[y-1][x]!=OTWARTE2 )
							Plansza[y-1][x]=OBECNIE;
							y--;
							ileRuchow++;
						}						
						break;
					case GORA:
						if(y<N-1 && (Plansza[y+1][x]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						y++;
						}						
						if(y<N-1 && (Plansza[y+1][x]==WOLNE ||Plansza[y+1][x]==OTWARTE|| Plansza[y+1][x]==OTWARTE1 || Plansza[y+1][x]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y+1][x]!=OTWARTE && Plansza[y+1][x]!=OTWARTE1 && Plansza[y+1][x]!=OTWARTE2 )
							Plansza[y+1][x]=OBECNIE;
							y++;
							ileRuchow++;
						}						
						break;
					case PRAWO:
						if(x>0 && (Plansza[y][x-1]==META))
						{
							x--;
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						}						
						if(x>0 && (Plansza[y][x-1]==WOLNE ||Plansza[y][x-1]==OTWARTE|| Plansza[y][x-1]==OTWARTE1 || Plansza[y][x-1]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y][x-1]!=OTWARTE && Plansza[y][x-1]!=OTWARTE1 && Plansza[y][x-1]!=OTWARTE2 )
							Plansza[y][x-1]=OBECNIE;
							x--;
							ileRuchow++;
						}						
						break;
					case LEWO:
						if(x<M-1 && (Plansza[y][x+1]==META))
						{
						time( & koniec );
						roznica += difftime( koniec, start );
						ileRuchow++;
						x++;
						}						
						if(x<M-1 && (Plansza[y][x+1]==WOLNE ||Plansza[y][x+1]==OTWARTE|| Plansza[y][x+1]==OTWARTE1 || Plansza[y][x+1]==OTWARTE2))
						{
							if(Plansza[y][x]==OBECNIE)
							Plansza[y][x]=WOLNE;
							if(Plansza[y][x+1]!=OTWARTE && Plansza[y][x+1]!=OTWARTE1 && Plansza[y][x+1]!=OTWARTE2 )
							Plansza[y][x+1]=OBECNIE;
							x++;
							ileRuchow++;
						}						
						break;												
					
				}
			break;
		}
		return roznica;
	}
	int Sprawdz(int Widok[8][3], int i, int x)
	{
	if(Widok[i][x]== WOLNE || Widok[i][x]== OTWARTE || Widok[i][x]== OTWARTE1 || Widok[i][x]==OTWARTE2 || Widok[i][x]==META )
	{
		return WOLNE;
	}
	if((Widok[i][x]>=8 && Widok[i][x]<=13) || Widok[i][x]==ZAMKNIETE || Widok[i][x]==ZAMKNIETE1 || Widok[i][x]==ZAMKNIETE2)
	return SCIANA;
	return 666666;
	}
	void RysujPerspektywistycznie(int **Pola,int kierunek,int y,int x,int M,int N, char **Trzy_D)
	{
		int Widok[8][3];
		int glebokosc=1;
		switch(kierunek)
		{
			case GORA:
				for(int i=1; i<7; i++)
				{
					if(y-i<0)
					goto koniec;
					if( Pola[y-i][x]!=WOLNE && Pola[y-i][x]!=OTWARTE && Pola[y-i][x]!=OTWARTE1 && Pola[y-i][x]!=OTWARTE2 && Pola[y-i][x]!=META )
					break;
					glebokosc++;
				}
				for(int j=0; j<glebokosc; j++)
				{
					for(int i=0; i<3; i++)
					{
						if((y-j-1)>=0 && (x-1+i)>=0)
						Widok[j][i]=Pola[y-j-1][x-1+i];
					}
				}
			break;
			case DOL:
				for(int i=1; i<7; i++)
				{
					if(Pola[y+i][x]!=WOLNE && Pola[y+i][x]!=OTWARTE && Pola[y+i][x]!=OTWARTE1 && Pola[y+i][x]!=OTWARTE2 && Pola[y+i][x]!=META )
					break;
					glebokosc++;
				}
				for(int j=0; j<glebokosc; j++)
				{
					for(int i=0; i<3; i++)
					{
						if((x+1-i)>=0)
						Widok[j][i]=Pola[y+j+1][x+1-i];
					}
				}
			break;
			case PRAWO:
			for(int i=1; i<7; i++)
				{
					if(Pola[y][x+i]!=WOLNE && Pola[y][x+i]!=OTWARTE && Pola[y][x+i]!=OTWARTE1 && Pola[y][x+i]!=OTWARTE2 && Pola[y][x+i]!=META )
					break;
					glebokosc++;
				}
				for(int j=0; j<glebokosc; j++)
				{
					for(int i=0; i<3; i++)
					{
						if((y-1+i)>=0)
						Widok[j][i]=Pola[y-1+i][x+j+1];
					}
				}
			break;
			case LEWO:
				for(int i=1; i<7; i++)
				{
					if(x-1<0)
					goto koniec;
					if(Pola[y][x-i]!=WOLNE && Pola[y][x-i]!=OTWARTE && Pola[y][x-i]!=OTWARTE1 && Pola[y][x-i]!=OTWARTE2 && Pola[y][x-i]!=META )
					break;
					glebokosc++;
				}
				for(int j=0; j<glebokosc; j++)
				{
					for(int i=0; i<3; i++)
					{
						if((y+1-i)>=0 && (x-j-1)>=0)
						Widok[j][i]=Pola[y+1-i][x-j-1];
					}
				}
			break;
		}
		koniec:
		//ustalanie g³ebokosci oraz widocznych pol
		gotoxy(PoczatekX+M+5,1);
				for(int i=0; i<30; i++)
		{
			for(int j=0; j<76; j++) 		//zerowanie
			{
				Trzy_D[i][j]=' ';
			}
		}
		int hL=15,hP=15,lP=5,lL=5,dlugoscL=0, dlugoscP=0; int zmienna=0;  //hL, hP - wysokosci  lP lL szerokosci scian, dlugoscP dlugoscL odleglosc od krawedzi
		int coPrawy, coLewy, coSrodkowy;     //zmienne 
		int jakaSciana;
		for(int i=0; i<glebokosc; i++)
		{
			zmienna=i;
			coPrawy=Sprawdz(Widok, i, 2);
		coLewy=Sprawdz(Widok, i,0);
			if(glebokosc==2)
			{	
				if(Sprawdz(Widok, i, 2)== WOLNE)	
				dlugoscP+=10;
				if(Sprawdz(Widok, i, 0)==WOLNE)
				dlugoscL+=10;
			}
			if(glebokosc==1)
			{	
				if(coPrawy==WOLNE || coPrawy==OTWARTE || coPrawy==META)	
				dlugoscP+=20;
				if(coLewy==WOLNE || coLewy==OTWARTE || coLewy==META)
				dlugoscL+=20;
				break;
			}
			switch( coLewy)//sciany z Lewej strony
			{
				case SCIANA:
				for(int x=15-hL; x<15+hL; x++)
				{
					if(x==15-hL || x==14+hL)
					{
						Trzy_D[x][dlugoscL]='+';
					}
					else 
					{
						Trzy_D[x][dlugoscL]='|';
					}
				}
			dlugoscL++;			
			for(int j=0; j<lL; j++)
			{
				if(j%2==0)
				{
					Trzy_D[15-hL][dlugoscL]='_';
					Trzy_D[13+hL][dlugoscL]='_';
				}
				else
				{
				Trzy_D[15-hL][dlugoscL]='-';
				Trzy_D[14+hL][dlugoscL]='-';
				}
				for(int k=16-hL;k<13+hL;k++)
				{
					jakaSciana=Widok[i][0];
					switch(jakaSciana)
					{
					case SCIANA1:
					Trzy_D[k][dlugoscL]='#';
					if(k==12+hL && j%2==1)
					Trzy_D[k+1][dlugoscL]='#';
					break;
					case SCIANA2:
					Trzy_D[k][dlugoscL]='&';
					if(k==12+hL && j%2==1)
					Trzy_D[k+1][dlugoscL]='&';
					break;
					case SCIANA3:
					Trzy_D[k][dlugoscL]='@';
					if(k==12+hL && j%2==1)
					Trzy_D[k+1][dlugoscL]='@';
					break;
					case SCIANA4:
					Trzy_D[k][dlugoscL]='%';
					if(k==12+hL && j%2==1)
					Trzy_D[k+1][dlugoscL]='%';
					break;
					case SCIANA5:
					Trzy_D[k][dlugoscL]='$';
					if(k==12+hL && j%2==1)
					Trzy_D[k+1][dlugoscL]='$';
					break;
					case ZAMKNIETE2:
					case ZAMKNIETE1:
						if(i<4 && j==0 && k==16-hL)
						{
					Trzy_D[15][dlugoscL+1]='|';
					Trzy_D[15][dlugoscL+2]='_';
					}
					break;					
					}
				}
				if(j%2==0 )
				hL--;
				dlugoscL++;
			}
			for(int x=15-hL; x<15+hL; x++)
			{
				Trzy_D[x][dlugoscL]='|';

			}	
			dlugoscL++;							
				break;
				case META:
				case WOLNE:
					if(i==6)
					{
						zmienna=i;
						break;
					}	
					if((Sprawdz(Widok,i+1,0)==WOLNE || Sprawdz(Widok,i+1,0)==OTWARTE || Sprawdz(Widok,i+1,0)==META )&& i+2<glebokosc)
					{
						if(i==0)
						{
						hL=hL-3;
						}
						else
						{
						hL=hL-2;							
						}
					}					
					else
					{								
					if(i!=0 && i!=6&& Sprawdz(Widok, i+1, 1)!=SCIANA)
					{
					hL=hL-2;
						Tekstury(Trzy_D, Widok, 16-hL, 14+hL, dlugoscL, dlugoscL+4, 0,i+1);						
						for(int z=0; z<4;z++)
						{
							Trzy_D[15-hL][dlugoscL]='-';
							Trzy_D[14+hL][dlugoscL]='-';
							dlugoscL++;												
						}
					}
					else
					{
						if(i==0)
						{
						dlugoscL=dlugoscL+2+3;
						hL=hL-3;
						}
						else
						{
						dlugoscL=dlugoscL+2+2;
						hL=hL-2;							
						}
						}
					}
				break;
				
			}
			
			switch(coPrawy) //sciany z Prawej
			{
				case SCIANA:
				for(int x=15-hP; x<15+hP; x++)
				{
				if(x==15-hP || x==14+hP)
				{
					Trzy_D[x][75-dlugoscP]='+';
				}
					else 
					{
				Trzy_D[x][75-dlugoscP]='|';
				}
				}
				dlugoscP++;
			
			for(int j=0; j<lP; j++)
			{
				if(j%2==0)
				{
					Trzy_D[15-hP][75-dlugoscP]='_';
					Trzy_D[13+hP][75-dlugoscP]='_';
				}
				else
				{
				Trzy_D[15-hP][75-dlugoscP]='-';
				Trzy_D[14+hP][75-dlugoscP]='-';
				}
				for(int k=16-hP;k<13+hP;k++)
				{
					jakaSciana=Widok[i][2];
					switch(jakaSciana)
					{
					case SCIANA1:
					Trzy_D[k][75-dlugoscP]='#';
					if(k==12+hP && j%2==1)
					Trzy_D[k+1][75-dlugoscP]='#';
					break;
					case SCIANA2:
					Trzy_D[k][75-dlugoscP]='&';
					if(k==12+hP && j%2==1)
					Trzy_D[k+1][75-dlugoscP]='&';
					break;
					case SCIANA3:
					Trzy_D[k][75-dlugoscP]='@';
					if(k==12+hP && j%2==1)
					Trzy_D[k+1][75-dlugoscP]='@';
					break;
					case SCIANA4:
					Trzy_D[k][75-dlugoscP]='%';
					if(k==12+hP && j%2==1)
					Trzy_D[k+1][75-dlugoscP]='%';
					break;
					case SCIANA5:
					Trzy_D[k][75-dlugoscP]='$';
					if(k==12+hP && j%2==1)
					Trzy_D[k+1][75-dlugoscP]='$';
					break;
					case ZAMKNIETE2:
					case ZAMKNIETE:
					case ZAMKNIETE1:
						if(i<4 && j==0 && k==16-hP)
						{
					Trzy_D[15][75-dlugoscP-1]='|';
					Trzy_D[15][75-dlugoscP-2]='_';
					}
					break;					
					}
				}
				if(j%2==0 )
				hP--;
				dlugoscP++;
			}
			
			for(int x=15-hP; x<15+hP; x++)
			{
				Trzy_D[x][75-dlugoscP]='|';

			}	
			dlugoscP++;						
				break;
				case META:
				case WOLNE:
					if(i==6)
					{
						zmienna=i;
						break;
					}
					if((Sprawdz(Widok,i+1,2)==WOLNE || Sprawdz(Widok,i+1,2)==META || Sprawdz(Widok,i+1,2)==OTWARTE) && i+2<glebokosc )
					{
						if(i==0)
						{
						hP=hP-3;
						}
						else
						{

						hP=hP-2;							
						}						
					}
					else
					{
					if(i!=0 && i!=6 &&Sprawdz(Widok, i+1,1)!=SCIANA)
					{
					hP=hP-2;
						Tekstury(Trzy_D, Widok, 16-hP, 14+hP, 75-dlugoscP-4, 75-dlugoscP+1, 2,i+1);						
						for(int z=0; z<4;z++)
						{
							Trzy_D[15-hP][75-dlugoscP]='-';
							Trzy_D[14+hP][75-dlugoscP]='-';
							dlugoscP++;
						}
					}
					else
					{
						if(i==0)
						{
						dlugoscP=dlugoscP+2+3;
						hP=hP-3;
						}
						else
						{
						dlugoscP=dlugoscP+2+2;
						hP=hP-2;							
						}
					}
					}
				break;
			}
		if(i==0)
		{
		lP=3; lL=3;
		}
		zmienna=i;
		if( Sprawdz(Widok, i+1,1)==SCIANA)
		{
		break;
		}
	}
	if(glebokosc==1)
	{	
		Tekstury(Trzy_D, Widok, 3, 26, dlugoscL, 76-dlugoscP, 1,0);			
		for(int i=dlugoscL; i<76-dlugoscP; i++)
		{
					Trzy_D[14-12][i]='_';
					Trzy_D[14+12][i]='-';		
		}
	}
			if( zmienna+1<7 && Sprawdz(Widok, zmienna+1, 1)==SCIANA) //sciana przed nami widoczna
			{
				if(Sprawdz(Widok, zmienna,0)==SCIANA && Sprawdz(Widok, zmienna, 2)== SCIANA)  //sciany po lewej i po prawej na koncu 
				{
					Tekstury(Trzy_D, Widok, 15-hL, 14+hP, dlugoscL, 76-dlugoscP, 1,zmienna+1);				
					for(int i=dlugoscL;i<76-dlugoscP; i++)
				{
					Trzy_D[14-hL][i]='_';
					Trzy_D[14+hP][i]='-';
				}
				}
				else
				{
					if(Sprawdz(Widok, zmienna,2)==SCIANA) //sciana tylko po prawej
					{
					Tekstury(Trzy_D, Widok, 15-hL, 14+hP, dlugoscL-4, 76-dlugoscP, 1,zmienna+1);		
					for(int i=75-dlugoscP;i>dlugoscL-5; i--)
					{
						Trzy_D[14-hL][i]='_';
						Trzy_D[14+hP][i]='-';
					}
					}
						else
						{
							if(Sprawdz(Widok, zmienna,0)==SCIANA) //sciana po lewej
							{
							Tekstury(Trzy_D, Widok, 15-hL, 14+hP, dlugoscL, 80-dlugoscP, 1,zmienna+1);								
								for(int i=dlugoscL;i<80-dlugoscP; i++)
								{
									Trzy_D[14-hL][i]='_';
									Trzy_D[14+hP][i]='-';
								}												
							}
						}
					}
					if(Sprawdz(Widok, zmienna,0)==WOLNE && Sprawdz(Widok, zmienna, 2)== WOLNE)
					{
					Tekstury(Trzy_D, Widok, 15-hL, 14+hP, dlugoscL-4, 80-dlugoscP, 1,zmienna+1);	
						for(int i=dlugoscL-4;i<80-dlugoscP; i++)
						{
							Trzy_D[14-hL][i]='_';
							Trzy_D[14+hP][i]='-';
						}
					}
				}
				if(zmienna==6)
				{
					if(Sprawdz(Widok, zmienna,0)==SCIANA) //sciana po lewej
					{
					for(int i=dlugoscL-1; i<76-dlugoscP; i++)
					{
						Trzy_D[14-hL][i]='_';
					}	
				}
					if(Sprawdz(Widok, zmienna,2)==SCIANA) //sciana po prawej
					{
					for(int i=dlugoscL; i<77-dlugoscP; i++)
					{
						Trzy_D[14+hP][i]='_';
					}	
				}	
				if(Sprawdz(Widok, zmienna,0)==WOLNE && Sprawdz(Widok, zmienna,2)==WOLNE)		//obydwa pola wolne przed zankiem glebokosci widzenia	
				{
					for(int i=dlugoscL; i<76-dlugoscP; i++)
					{
						Trzy_D[14][i]='_';
					}					
				}
				}		
		//wypisywanie
		for(int i=0; i<30; i++)
		{
			for(int j=0; j<76; j++)
			{
				cout<<Trzy_D[i][j];
			}
			gotoxy(PoczatekX+M+5,2+i);
		}
		//ramka
					textcolor(6);
		for(int i=0; i<31;i++)
		{
			gotoxy(PoczatekX+M+4,1+i);
				cout<<"|";		
		}
				for(int i=0; i<31;i++)
		{
			gotoxy(PoczatekX+M+4+77,1+i);
				cout<<"|";		
		}
	}
	bool czyPrawidlowo(int **Edytor, int M, int N)
	{
		int Start=0, Meta=0;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				if(Edytor[i][j]==START_EDYTOR)
				Start++;
				if(Edytor[i][j]==META_EDYTOR)
				Meta++;								
			if(i<N-1 && j<M-1 && Edytor[i][j+1]==WOLNE && Edytor[i+1][j]==WOLNE && Edytor[i+1][j+1]==WOLNE && Edytor[i][j]==WOLNE)	
			return 0;			
			}
		}
		if(Start!=1 || Meta!=1)
		return 0;
		return 1;
	}
	bool Edytor (int atrybut, int **Plansza, int **Edytor, int &kierunek, int &x, int &y, int &M, int &N, int &m_edytor,int &n_edytor, time_t &start, time_t koniec, int &ileRuchow, bool &EdytorZaczety, int &StartX, int &StartY,int &kierunekPoczatkowy, int &roznica)
	{
		od_nowa:
		int z,c;
		int aktualnieX=1, aktualnieY=1;
		int zn;
		if(EdytorZaczety==0)
		{		
		do
		{			
		clrscr();
		gotoxy(35,15);
		cout<<"Wprowadz szerokosc planszy od 1 do 50";
		gotoxy(40,16);
		cin>>m_edytor;
		cin.clear();
		cin.sync();
		}	while(m_edytor<=0 && m_edytor<=50);
		do
		{
		clrscr();
		gotoxy(35,15);
		cout<<"Wprowadz wysokosc planszy od 1 do 50";
		gotoxy(40,16);
		cin>>n_edytor;	
		cin.clear();
		cin.sync();
		}while(n_edytor<=0 && n_edytor<=50);
		for(int i=0;i<n_edytor;i++)
		{
			for(int j=0;j<m_edytor;j++)
			{
				Edytor[i][j]=WOLNE;
				if(i==0|| j==0 || i==n_edytor-1 || j==m_edytor-1)
				Edytor[i][j]=Sciana();
				
			}
		}
		}
		EdytorZaczety=1;
		int k=0;
		do
		{
			clrscr();
		Rysuj(Edytor,kierunek,aktualnieY,aktualnieX,m_edytor,n_edytor, atrybut,1);	
		zn=13;
		if(k==1)
	zn = getch();
		switch(zn)
		{
			case 'r':
				EdytorZaczety=0;
				goto od_nowa;
			case 0:
		zn = getch();	
		switch(zn)
			{
				case 0x50: //dó³
				if(aktualnieY<n_edytor-1)
				aktualnieY++;
				break;
				case 0x48: //góra
			if(aktualnieY>=1)
			aktualnieY--;
				break;
				case 0x4b: //lewo
			if(aktualnieX>=1)
			aktualnieX--;
				break;
				case 0x4d: //prawo
			if(aktualnieX<m_edytor-1)
			aktualnieX++;
				break;
			}
			break;
		case ' ':  //spacja
		{
		switch(Edytor[aktualnieY][aktualnieX])
		{
			case SCIANA1:
			case SCIANA2:
			case SCIANA3:
			case SCIANA4:
			case SCIANA5:
			case SCIANA:
			Edytor[aktualnieY][aktualnieX]=WOLNE;	
										if(aktualnieX==0 || aktualnieY==0 || aktualnieY==n_edytor-1 || aktualnieX==m_edytor-1)
										Edytor[aktualnieY][aktualnieX]=START_EDYTOR;
			break;
			case WOLNE:
			Edytor[aktualnieY][aktualnieX]=DRZWI_EDYTOR;
							if(aktualnieX==0 || aktualnieY==0 || aktualnieY==n_edytor-1 || aktualnieX==m_edytor-1)
							Edytor[aktualnieY][aktualnieX]=START_EDYTOR;
			break;
			case DRZWI_EDYTOR:
			Edytor[aktualnieY][aktualnieX]=Sciana();
			break;
			case START_EDYTOR:
			Edytor[aktualnieY][aktualnieX]=META_EDYTOR;
			break;
			case META_EDYTOR:
			Edytor[aktualnieY][aktualnieX]=Sciana();
		}
		}
			break;
			case 27: //esc
			goto wyjscie;
			break;
			case 's':
				ZapiszEdytor(Edytor,m_edytor,n_edytor);
				break;
			case 13 :
				if(czyPrawidlowo(Edytor, m_edytor, n_edytor)==1)
				{
				M=m_edytor; N=n_edytor; 
				for(int i=0;i<n_edytor;i++)
				{
					for(int j=0;j<m_edytor;j++)
					{
						if(k==1)
						{
						Plansza[i][j]=Edytor[i][j];
						switch(Plansza[i][j])
						{
							case DRZWI_EDYTOR:
							Plansza[i][j]=ZAMKNIETE;
							break;
							case META_EDYTOR:
							Plansza[i][j]=META;
							break;
							case START_EDYTOR:
							Plansza[i][j]=OBECNIE;
							x=StartX=j;
							y=StartY=i;
							if(i==0)
							kierunek=kierunekPoczatkowy=DOL;
							if(i==N-1)
							kierunek=kierunekPoczatkowy=GORA;
							if(j==0)
							kierunek=kierunekPoczatkowy=PRAWO;
							if(j==M-1)
							kierunek=kierunekPoczatkowy=LEWO;	
							break;
						}
						}
						else
						{	
						break;					
						}
					}
					}
					if(k==1)
					{
											time( & start);
					roznica=0; ileRuchow=0;
					EdytorZaczety=0;
					return 1;
					}
					if(k==0)
					{
										time( & start);
					EdytorZaczety=0;
					return 1;	
					}
					}
					break;
		}
		k=1;
		}while(1);
		wyjscie:
			EdytorZaczety=1;
			return 0;
	}
int main()
{
	srand(time(0));
	bool EdytorZaczety=0;
	int CzyGraEdytor=0, CzyEdytowanie;
	int Edytor_N=50, Edytor_M=50;
	int **Edytor_Pola;
	Edytor_Pola = new int *[Edytor_N];
	for(int i=0;i<Edytor_N;i++)
    Edytor_Pola[i] = new int[Edytor_M];
	char plik[50]={};
	int ileRuchow=0;
	int startY, startX;
	int roznica;
	time_t start, koniec;
	bool CzyGra=0;
	int N=50, M=50;
	int **Pola;
	Pola = new int *[N];
	for(int i=0;i<N;i++)
    Pola[i] = new int[M];
	char **trzy_d;
	trzy_d = new char *[30];
    for(int i=0;i<30;i++)
    trzy_d[i] = new char[76];
	int zn, x=66, y=22, attr = 7, attrZmieniony=7;	
	int kierunek ,kierunekPoczatkowy;
	settitle("Arkadiusz Ciosek 161340");
	textbackground(BLACK);
	N=10, M=25;	
	Edytor_N=0, Edytor_M=0;
	do {
		if(CzyGra==0 && CzyGraEdytor==0)
		{
		clrscr();	
		textcolor(7);;
		gotoxy(30+M, 3);
		cputs("strzalki = poruszanie");
		gotoxy(30+M, 13);
		cputs("q = wyjscie");
		gotoxy(30+M, 4);
		cputs("spacja = zmiana koloru");
		gotoxy(30+M, 5);
		cputs("d = otwieranie/zamykanie drzwi");
		gotoxy(30+M, 6);
		cputs("i = wczytanie domyslnego labiryntu");
		gotoxy(30+M, 7);
		cputs("h = pomoc");
		gotoxy(30+M, 8);
		cputs("e = wejscie do edytora");
		gotoxy(30+M, 9);
		cputs("p = wczytanie labiryntu z pliku");
		gotoxy(30+M, 10);
		cputs("s = zapis");
		gotoxy(30+M, 11);
		cputs("r = restart");
		gotoxy(30+M, 12);
		cputs("a = aktywacja animacji");
		}
		gotoxy(PoczatekX, PoczatekY);	
		if(CzyGra==1 || CzyGraEdytor==1)
		{
			textcolor(attrZmieniony);
			clrscr();
		Rysuj(Pola,kierunek,y,x,M,N, attrZmieniony,0);
		gotoxy(PoczatekX+M+8,24);
		RysujPerspektywistycznie(Pola,kierunek,y,x,M,N, trzy_d);
		textcolor(attr);
		}
		else
		{
			textcolor(2);
			gotoxy(15, 9);
			cout<<"Zapraszam do gry";
		}
		gotoxy(1,1);
		zn = getch();
		if(CzyGra==0)
		clrscr();
		switch(zn)
		{
			case 0:
		zn = getch();	
		switch(zn)
			{
				case 0x50: //dó³
				roznica= WykonajRuch(Pola, kierunek, TYL,x,y, M, N, koniec, start, ileRuchow,roznica);
				break;
				case 0x48: //góra
				roznica= WykonajRuch(Pola, kierunek, PRZOD,x,y,  M, N, koniec, start, ileRuchow, roznica);
				break;
				case 0x4b: //lewo
				kierunek=WykonajObrot(kierunek, WLEWO);
				break;
				case 0x4d: //prawo
				kierunek=WykonajObrot(kierunek, WPRAWO);
				break;
			}
			break;
		case ' ':
		 attrZmieniony = (attrZmieniony + 1) % 16;
			break;
		case 'd':
			Drzwi(Pola, kierunek,x,y);
			break;
		case 'i':
			EdytorZaczety=0;
			ileRuchow=0;
			GenerujDomyslny(Pola,kierunek, x,y,M,N, startY, startX, kierunekPoczatkowy);
			CzyGra=true;
			time( & start );
			break;
		case 'h':
				clrscr();
				gotoxy(27, 11);
		cputs("strzalki = poruszanie");
		gotoxy(27, 21);
		cputs("q = wyjscie");
		gotoxy(27,12);
		cputs("spacja = zmiana koloru");
				gotoxy(27, 14);
		cputs("d = otwieranie/zamykanie drzwi");
		gotoxy(27, 15);
		cputs("i = wczytanie domyslnego labiryntu");
				gotoxy(27, 16);
		cputs("h = pomoc");
		gotoxy(27, 17);
		cputs("e = wejscie do edytora");
				gotoxy(27, 18);
		cputs("p = wczytanie labiryntu z pliku");
		gotoxy(27, 19);
		cputs("s = zapis");
				gotoxy(27, 20);
		cputs("r = restart");
		gotoxy(27, 13);
		cputs("a = aktywacja animacji");
		if(getch()==0)
		getch();
		clrscr();
			break;
		case 'p':
			{
			if(Wczytaj(Pola, kierunek, x, y, M, N, startX, startY, kierunekPoczatkowy)==1)
			{
							ileRuchow=0;
			time( & start );
			clrscr();
			}
			else
			{
				if(Wczytaj(Pola, kierunek, x, y, M, N, startX, startY, kierunekPoczatkowy)==2)
				{
			for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				switch(Pola[i][j])
				{
					case WOLNE:
						Edytor_Pola[i][j]=WOLNE;
						break;
					case SCIANA1:
						case SCIANA2:
							case SCIANA3:
								case SCIANA4:
									case SCIANA5:
										case SCIANA:
						Edytor_Pola[i][j]=Sciana();
					break;
					case ZAMKNIETE:
						Edytor_Pola[i][j]=DRZWI_EDYTOR;						
					break;
					case OBECNIE:
					Edytor_Pola[i][j]=START_EDYTOR;
						break;						
						case META:
							Edytor_Pola[i][j]=META_EDYTOR;
							break;
				}
			}
		}
		Edytor_M=M; Edytor_N=N;
									EdytorZaczety=1;
										goto edytor;
										roznica=0;
										ileRuchow=0;
										
				}
			}
		}
			break;
		case 's':
			Zapisz(Pola,kierunek,x,y,M,N,startX,startY,kierunekPoczatkowy);
			break;
		case 'e':
						edytor:
							if(CzyGraEdytor==0)
				CzyGraEdytor=Edytor(attrZmieniony, Pola,Edytor_Pola, kierunek, x, y,M, N,Edytor_M, Edytor_N, start, koniec,ileRuchow, EdytorZaczety,startX,startY,kierunekPoczatkowy,roznica);	
			break;			
		case 'r':
			if(CzyGra==1 || CzyGraEdytor==1)
			{
				ResetujPlansze(Pola, kierunek, x, y, M, N, startX, startY, kierunekPoczatkowy);
				ileRuchow=0;
				roznica=0;
				time( & start );
			}
			break;
		case 'a':
			
			break;
			case 27:
				if(CzyGra==1 || CzyGraEdytor==1)
				{
					EdytorZaczety=0;
					CzyGra=0;
					if(CzyGraEdytor==1)
					EdytorZaczety=1;
					CzyGraEdytor=0;
					clrscr();
					M=25;
					time( & koniec);
					roznica+=(difftime(koniec, start));			
				}
			break;
	}
		if(Pola[y][x]==META && (CzyGra==1 || CzyGraEdytor==1))
		{
			clrscr();
			textcolor(9);;
			Wygrana(roznica, ileRuchow);
			CzyGra=0;
			CzyGraEdytor=0;
			roznica=0;
			ileRuchow=0;
			M=25;
		}
	} while (zn != 'q');
	return 0;
}

