#include <iostream>
#include <string>
#define Banner 	cout<<"\t\t\t\t** JUEGO AHORCADO **	\n\n"

using namespace std;

void menu()
{
	Banner;
	cout<<"\t\t\t\t     ==========		\n";
	cout<<"\t\t\t\t     |        |		\n";
	cout<<"\t\t\t\t     |       ###		\n";
	cout<<"\t\t\t\t     |      #####	\n";
	cout<<"\t\t\t\t     |       ###		\n";
	cout<<"\t\t\t\t     |        # 		\n";
	cout<<"\t\t\t\t     |     #######	\n";
	cout<<"\t\t\t\t     |        #		\n";
	cout<<"\t\t\t\t     |        #		\n";
	cout<<"\t\t\t\t     |       # #		\n";
	cout<<"\t\t\t\t     |      #   #	\n";
	cout<<"\t\t\t\t     |     ##   ## 	\n";
	cout<<"\t\t\t\t     |				\n";
	cout<<"\t\t\t\t =========			\n\n";
	
	cout<<"\t\t1. JUGAR\n";
	cout<<"\t\t2. INSTRUCCIONES\n\n";
	cout<<"\t\t9. SALIR\n";
	
	cout<<endl<<"\t\tINGRESE OPCION: ";
}

void instrucciones()
{
	system("cls");
	Banner;
	cout<<"EL JUEGO AHORCADO FUNCIONA DE LA SIGUIENTE FORMA:\n\n";
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

int captletra()
{
	string ltr;
	int i=0;
	int control=0;

	do
	{
		system("cls");
		Banner;	
		cout<<"\t\t Digite una letra entre A-Z: ";
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
				cout<<"\a\n\n\t**  ERROR **\n POR FAVOR DIGITE UNA SOLA LETRA ENTRE A-Z\n\n";
				system("pause");
			}
		}else{
			cout<<"\a\n\n\t**  ERROR **\n POR FAVOR DIGITE UNA SOLA LETRA ENTRE A-Z\n\n";
			system("pause");
		}
								
	}while(control!=1);

	return 0;
}

string captPalabra()
{
	string palabra;
	getline(cin, palabra);
	int control;
	do
	{
		system("cls");
		Banner;
		cout<<"\nDigite la palabra a descubrir:  ";
		getline(cin, palabra);
		cout<<"\n\n\n\nPalabra buscada: ***  "<<palabra<<endl;
		system("pause");
		
		
		for (int i = 0; i < palabra.length(); i++)
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
				cout<<"\a\n\n\t**  ERROR **\n POR FAVOR DIGITE UNA PALABRA QUE CONTENGA UNICAMENTE LETRAS ENTRE A-Z\n\n";
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

	palabra=captPalabra();
	letra=captletra();
	cout<<"\n\n\n\nPalabra buscada: ***  "<<palabra<<endl;
	cout<<"\n\nletra seleccionada: ***  "<<letra<<endl;
	//system("pause");
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
