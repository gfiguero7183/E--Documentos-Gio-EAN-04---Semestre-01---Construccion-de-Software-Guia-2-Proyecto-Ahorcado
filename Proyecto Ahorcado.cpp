#include <iostream>
#include <string>
#include <windows.h>

#define Banner 		gotoxy(30,0);cout<<"** JUEGO AHORCADO **"
#define Horca 		gotoxy(34,1);cout<<"============";gotoxy(35,2);cout<<"||        |";gotoxy(35,3);cout<<"||";gotoxy(35,4);cout<<"||";gotoxy(35,5);cout<<"||";gotoxy(35,6);cout<<"||";gotoxy(35,7);cout<<"||";gotoxy(35,8);cout<<"||";gotoxy(35,9);cout<<"||";gotoxy(35,10);cout<<"||";gotoxy(35,11);cout<<"||\n";
#define Separador 	for(int i=0;i<80;i++){cout<<"="; }

using namespace std;
int Tam, CErrada;
string palabra;
string RTA;
string Errada;

//Encontrada en el libro 380 principales funciones del Turbo C++ escrito por Cesar Becerra Santamaria; 
//con el fin de integrarla de forma apropiada en el código nos apoyamos en el vídeo publicado en: https://www.youtube.com/watch?v=WuEQW1j_lAk
void gotoxy(int x, int y) 	
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
	if(CErrada>=1)
	{
		//Cabeza
		gotoxy(44,3);cout<<"###";
		gotoxy(43,4);cout<<"#####";
		gotoxy(44,5);cout<<"###";	
	}
	if(CErrada>=2)
	{
		//tronco
		gotoxy(45,6);cout<<"#";
		gotoxy(45,7);cout<<"#";
		gotoxy(45,8);cout<<"#";		
	}
	if(CErrada>=3)
	{
		// brazo derecho
		gotoxy(46,7);cout<<"###";		
	}
	if(CErrada>=4)
	{
		// brazo izuierdo
		gotoxy(42,7);cout<<"###";		
	}
	if(CErrada>=5)
	{
		// pierna derecha
		gotoxy(44,9);cout<<"#";
		gotoxy(42,10);cout<<"##";		
	}
	if(CErrada>=6)
	{
		// pierna izuierda
		gotoxy(46,9);cout<<"#";
		gotoxy(47,10);cout<<"##";		
	}
}

void menu()
{
	Cabecera();
	CErrada=6;
	Cuerpo();
	gotoxy(1,14);
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
	cout<<"** \tEl cuerpo se dibuja en 6 partes (cabeza, tronco y extremidades),\n\tpor lo que el jugador solo tiene 6 posibilidades de fallar.\n\n\n";
}

int minMAY(int i)// COnvierte las minusculas en mayusculas
{
	if(i >= 97 && i<=122)
		return i-=32;
	if(i == -92)
		return -91;
}

int validacion(int letra)//Valida si la letra digitada se encuentra en las que contiene la palabra oculta y la envia al String RTA
{
	int control=0;
	for(int i=0;i<Tam;i++)
	{
		if(palabra.at(i)==letra)
		{
			RTA[i]=letra;
			control=1;
		}
	}
	if(control==0) //Letra errada, envia la letra al String Errada
	{
		Errada[CErrada]=letra;
		CErrada++;
		return 0;
	}else{
		return 1;
	}
}

void inciarRTA()// Inicializa RTA
{
	for(int i=0;i<Tam;i++)
	{
		if(palabra.at(i)==32)
		{
			RTA[i]=32;
		}else{
			RTA[i]=95;
		}
	}
}

int constLinRta(int T) // Muestra la linea de Respuesta y letras Erroneas
{
	gotoxy(40-((Tam*4)/2),13);
	for(int i=0;i<T;i++)
	{
		cout<<"["<<RTA[i]<<"] ";
	}
	gotoxy(0,14);
	Separador;
	Cuerpo();
	gotoxy(52,2);	
	cout<<"Letras Erradas : "<<CErrada<<"\n";
	for(int j=0;j<CErrada;j++)
	{
		gotoxy(55,j+4);
		cout<<j+1<<".\t"<<Errada[j]<<" ";
	}
}

int captletra() //Captura las letras para las respuestas
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

string captPalabra() //Captura la Palabra Oculta para adivinar
{
	getline(cin, palabra);
	int control, max=20;
	do
	{
		system("cls");
		Cabecera();
		gotoxy(1,13);
		cout<<"Digite la palabra a descubrir:  ";
		getline(cin, palabra);
		int TP=palabra.length();				
		if(TP<=0 || TP>max)//Valida la longitud de la Palabra oculta con la cual se va jugar
		{
			control=2;
			TP=0;
			system("cls");
			cout<<"\a\n\n\t**  ERROR **\n\nLA LONGITUD MINIMA PERMITIDA ES 1 LETRA\n\nLA LONGITUD MAXIMA PERMITIDA ES DE "<<max<<" LETRAS ENTRE A-Z\n\n";
			system("pause");
		}else{
			control=0;
		}
		
		for (int i = 0; i < TP; i++) //Valida uno por uno para confirmar que sea una letra, si es minuscula la envia para convertir en Mayuscula
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

//Desarrolla la parte Procedimental del juego, haciendo llamados a las funciones 
//confronta la palabra oculta con la que se esta ingresando letra por letra
//Presenta los mensajes en caso de ganar o perder
int juego() 
{
	string palabra;
	char letra;
	int z;
	int CCorrecta;
	Tam=0;
	CErrada=0;

	palabra=captPalabra();
	Tam=palabra.length();
	inciarRTA();
	do{
		letra=captletra();
		z=validacion(letra);
		constLinRta(Tam);
		if(z==1)
		{
			gotoxy(27,20);cout<<"** LETRA [ "<<letra<<" ] CORRECTA **\n\n";
		}else{
			gotoxy(26,20);cout<<"** LETRA [ "<<letra<<" ] INCORRECTA **\n\n";
		}
		for(int i=0;i<Tam;i++)
		{
			if(palabra[i]==RTA[i])
			{
				CCorrecta=1;
			}else{
				i=Tam;
				CCorrecta=0;
			}
		}
		system("pause");
	}while(CCorrecta!=1 && CErrada<6);
	if(CErrada>=6)
	{
		system("cls");
		Cabecera();
		Cuerpo();
		system ("color 4F");
		gotoxy(27,14);cout<<"** LO SIENTO HAS PERDIDO **";
		gotoxy(30,16);cout<<"LA PALABRA OCULTA ERA";
		gotoxy(40-((Tam+6)/2),18);cout<<"** "<<palabra<<" **\n\n";
		return 0;
	}
	system("cls");
	Cabecera();
	Cuerpo();
	system ("color 2F");
	gotoxy(30,14);
	cout<<"!!! FELICITACIONES !!!\n\n\t\t\tHAS ENCONTRADO LA PALABRA OCULTA:";
	gotoxy(40-((Tam+6)/2),18);cout<<"** "<<palabra<<" **\n\n";
	return 0;
}

int main()
{
	int op;
	do
	{
		system ("color 9F");
		menu(); 
		cin>>op;
		
		switch(op)
		{
			case 1:
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
