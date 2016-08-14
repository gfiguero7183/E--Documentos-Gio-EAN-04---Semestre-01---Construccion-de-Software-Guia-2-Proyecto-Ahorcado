#include <iostream>
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

int juego()
{
	string palabra;
	int x;
	system("cls");
	Banner;
	cout<<"\nDigite la palabra a descubrir:  ";
	cin>>palabra;
	x=palabra.length();
	cout<<"\n\n\n\n";
	system("pause");
	system("cls");
	Banner;	
	cout<<"\t\t ** la palabra es: "<<palabra<<" tamaño: "<<x<<" **\n\n";

	return 0;
}

int main()
{
	int dato,op,x;
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



