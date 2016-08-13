#include <iostream>


using namespace std;

void menu()
{
	cout<<"\t\t\t\t** JUEGO AHORCADO **\n\n";
	
	cout<<"1. JUGAR"<<endl;
	cout<<"2. INSTRUCCIONES"<<endl<<endl;
	cout<<"9. SALIR"<<endl;
	
	cout<<endl<<"INGRESE OPCION: ";
}

void instrucciones()
{
	system("cls");
	cout<<"\t\t\t\t ** INSTRUCCIONES **\n\n";
	cout<<"EL JUEGO AHORCADO FUNCIONA DE LA SIGUIENTE FORMA:"<<endl;
	cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl<<endl;
}

int juego()
{
	string palabra;
	int x;
	system("cls");
	cout<<"\t\t\t\t ** AHORCADO **\n\n";
	cout<<"Digite la palabra a descubrir:  ";
	cin>>palabra;
	x=palabra.length();
	cout<<"\t\t\** la palabra es: **\n\n"<<palabra<<"** tamaño: "<<x<<" **\n\n";
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



