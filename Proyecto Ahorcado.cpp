#include <iostream>
#include <string>
#include <windows.h>

#define Banner 	cout<<"\t\t\t\t** JUEGO AHORCADO **"
#define Horca 	cout<<"\n\t\t\t\t     ===========\n\t\t\t\t     ||        |		\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n\t\t\t\t     ||\n"
#define Separador 	for(int i=0;i<80;i++){cout<<"="; }

using namespace std;
int Tam, CCorrecta,CErrada;
string palabra;
string RTA;
string Errada;

void gotoxy(int x, int y) // tomada de https://www.youtube.com/watch?v=WuEQW1j_lAk
{
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Cabecera()
{
	Banner;
	Horca;
	Separador;
}

void Cuerpo()
{
	//cabeza
	gotoxy(46,3);cout<<"###";
	gotoxy(45,4);cout<<"#####";
	gotoxy(46,5);cout<<"###";
	//tronco
	gotoxy(47,6);cout<<"#";
	gotoxy(47,7);cout<<"#";
	gotoxy(47,8);cout<<"#";
	// brazo derecho
	gotoxy(48,7);cout<<"###";
	// brazo izuierdo
	gotoxy(44,7);cout<<"###";
	// pierna derecha
	gotoxy(46,9);cout<<"#";
	gotoxy(44,10);cout<<"##";
	// pierna izuierda
	gotoxy(48,9);cout<<"#";
	gotoxy(49,10);cout<<"##";
}

void menu()
{
	Cabecera();
	gotoxy(1,13);
	cout<<"\t\t1. JUGAR\n";
	cout<<"\t\t2. INSTRUCCIONES\n\n";
	cout<<"\t\t9. SALIR\n";
	
	cout<<endl<<"\t\tINGRESE OPCION: ";
}

void instrucciones()
{
	system("cls");
	Banner;
	cout<<"\n";
	Separador;
	cout<<"\nEL JUEGO AHORCADO FUNCIONA DE LA SIGUIENTE FORMA:\n\n";
	cout<<"El supervisor ingresa la palabra para adivinar. \n\n";
	cout<<"El jugador pide una letra. \n\n";
	cout<<"* \tSi acierta, se escribe la letra en todas las casillas de la misma letra.\n\n";	
	cout<<"* \tSi no acierta, se pone la letra bajo la horca \n\ty se dibuja una parte del cuerpo.\n\n";
	cout<<"* \tGana el jugador si descubre la palabra o frase oculta\n\n";
	cout<<"* \tPierde si se dibuja todo el cuerpo en la horca\n\n";
	cout<<"** \tEl cuerpo se dibuja en 6 partes (cabeza, tronco y extremidades),\n\tpor lo que el jugador tiene 6 posibilidades de fallar.\n\n\n";
}

int minMAY(int i)
{
	if(i >= 97 && i<=122)
		return i-=32;
	if(i == -92)
		return -91;
}

int validacion(int letra)
{
	int control=0;
	for(int i=0;i<Tam;i++)
	{
		if(palabra.at(i)==32)
		{
			RTA[i]=95;
			CCorrecta++;
		}
		if(palabra.at(i)==letra)
		{
			RTA[i]=letra;
			control=1;
			CCorrecta++;
		}
	}
	if(control==0)
	{
		CErrada++;
	}
}

int constLinRta(int T)
{
	gotoxy(5,13);
	for(int i=0;i<T;i++)
	{
		cout<<"["<<RTA[i]<<"] ";
	}
	gotoxy(0,14);
	Separador;
	cout<<RTA;
	cout<<"\n\tLetras Erradas : ";	
	cout<<Errada;
}

int captletra()
{
	string ltr;
	int i=0;
	int control=0;

	do
	{
		system("cls");
		Cabecera();
		constLinRta(Tam);
		gotoxy(1,17);
		cout<<"\n * Digite una letra entre A-Z: ";
		cin>>ltr;
		if(ltr.length()==1)
		{
			i=ltr.at(0);
			if(i >= 65 && i<=90 || i==-91)
			{
				control=1;
				return i;
			}		
			if(i >= 97 && i<=122 || i==-92)
			{
				control=1;
				return minMAY(i);
   			}else{
   				system("cls");
   				cout<<"\a\n\n\t**  ERROR **\n\nPOR FAVOR DIGITE UNA SOLA LETRA ENTRE\n\n";
				system("pause");
			}
		}else{
			system("cls");
			cout<<"\a\n\n\t**  ERROR **\n\nPOR FAVOR DIGITE UNA SOLA LETRA ENTRE\n\n";
			system("pause");
		}
	}while(control!=1);
	return 0;
}

string captPalabra()
{
	getline(cin, palabra);
	int control, max=16;
	do
	{
		system("cls");
		Cabecera();
		gotoxy(1,13);
		cout<<"Digite la palabra a descubrir:  ";
		getline(cin, palabra);
		int TP=palabra.length();		
		if(TP>max)
		{
			control=2;
			TP=0;
		}else{
			control=0;
		}
		
		for (int i = 0; i < TP; i++)
    	{	
	        int T = palabra.at(i);
			if(T >= 97 && T<=122 || T==-92)
			{
				T=minMAY(T);
				palabra.at(i)=T;
   			}
	        if(T >= 65 && T<=90 || T==-91 || T==32)
			{
				control=0;
			}else{
				control=2;
				i = palabra.length();
				system("cls");
				cout<<"\a\n\n\t**  ERROR **\n\nPOR FAVOR DIGITE UNA PALABRA QUE CONTENGA UNICAMENTE LETRAS ENTRE A-Z\n\n";
				system("pause");
			}	
    	}
	}while(control==2);
	return palabra;
}

int juego()
{
	string palabra;
	char letra;
	Tam=0;

	palabra=captPalabra();
	Tam=palabra.length();
	do{
		validacion(captletra());
		constLinRta(Tam);
		cout<<"\n\n\n\n# correcta: "<<CCorrecta<<"\t # Errada: "<<CErrada<<"\t Tam: "<<Tam<<"\n";
		system("pause");
	}while(CCorrecta<Tam && CErrada<6);
	if(CErrada>=6)
	{
		system("cls");
		Cabecera();
		Cuerpo();
		gotoxy(27,14);cout<<"** LO SIENTO HAS PERDIDO **";
		gotoxy(30,16);cout<<"LA PALABRA OCULTA ERA";
		gotoxy(40-((Tam+6)/2),18);cout<<"** "<<palabra<<" **\n\n";
		return 0;
	}
	system("cls");
	Cabecera();
	gotoxy(30,14);
	cout<<"!!! FELICITACIONES !!!\n\n\t\t\tHAS ENCONTRADO LA PALABRA OCULTA:";
	gotoxy(40-((Tam+6)/2),18);cout<<"** "<<palabra<<" **\n\n";
	return 0;
}

int main()
{
	int op;
	system ("color 9F");
	
	do
	{
		menu(); 
		cin>>op;
		
		switch(op)
		{
			case 1:
				CCorrecta=0;
				CErrada=0;
				juego();
				system("pause");			
			break;
			
			case 2:
				instrucciones();
				system("pause");			
			break;	
		}
		system("cls");
	}while(op!=9);
	return 0;
}
