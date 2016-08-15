#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
 
char palabra[50]=("programacion"), rep[100], temp [100];
int longitud = 0, i, j=0, inicial=0, acierto=0, temporal=0, oport=6;
bool repetido=false, ganar=false;
 
class Juego{
private:
char word;
 
public:
 
void Ahorcado(){
  do{
   temporal=0;
   if(inicial==0){
     for(i=0;i<strlen(palabra);i++){
       if(palabra[i] == ' '){
         temp[i] = ' ';
         longitud++;
       }
       else{
        temp[i] = '_';
        longitud++;
       }
      }
     }
 
   inicial = 1;
   temp[longitud] = '\0';
   for(i=0;i<strlen(rep);i++){
    if(rep[i] == word){
     repetido = true;
     break;
    }
    else{
     repetido = false;
    }
   }
 
   if(repetido == false){
    for(i=0;i<strlen(palabra);i++){
     if(palabra[i] == word){
      temp[i] = word;
      acierto++;
      temporal = 1;
      }
     }
    }
 
    if(repetido == false){
     if(temporal == 0){
      oport = oport - 1;
     }
    }
    else{
     printf("Esa letra ya fue digitada");
     printf("\n\n");
    }
 
    printf("\n");
 
    for(i=0;i<strlen(temp);i++){
     printf(" %c ", temp[i]);
    }
 
    printf("\n");
 
    if(strcmp(palabra,temp) == 0){
     ganar = true;
     break;
    }
 
    printf("\n");
 
    printf("Letras acertadas: %d",acierto);
    printf("\n");
    printf("Oportunidades restantes: %d",oport);
    printf("\n");
    rep[j] = word;
    j++;
    printf("Digita una letra para adivinar la palabra:  ");
    scanf("\n%c",&word);
  }while(oport != 0);
 }
};
 
class Imprimir{
 private:
       string mensaje;
 public:
       void setmensaje(string a){
        mensaje = a;
       }
       string getmensaje(){
        return mensaje;
       }
};
 
int main()
{
    system("CLS");
    rep[0] = ' ';
    rep[1] = '\0';
 
    Juego Victima;
    Imprimir mostrar;
 
    Victima.Ahorcado();
 
    if(ganar){
     printf("\n\n");
     mostrar.setmensaje("¡¡Felicitaciones!! Adivinaste la palabra");
     cout<<mostrar.getmensaje();
    }
    else{
     printf("\n\n");
     mostrar.setmensaje("Perdiste =(, pero puedes volver a intentarlo");
     cout<<mostrar.getmensaje();
    }
 
    printf("\n\n");
    system("PAUSE");
    return 0;
}
