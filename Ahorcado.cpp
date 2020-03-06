/*
Nombres: Laura Victoria Villalobos Paredes y Jeison Felipe Cuenca Mojica
Programa: Ahorcado
Fecha: 06/03/2020-xx/xx/2020
*/

#include <string.h>
#include <iostream>
#include <wchar.h>

using namespace std;

//afuera del main para no andar poniendolo en todo lado varias veces
char palabra[50]=("la hiper mega frase"), rep[100], temp [100];
int longitud=0, i, j=0, inicial=0, acierto=0, temporal=0, oport=11;
bool repetido=false, ganar=false;//verificar sí si da, o si no :v

class Juego //Esto es para hacerle como una especie de nucleo al juego
{	
	private://acceso restringido	
	char word;	
	public://cualquiera puede acceder	
	void Ahorcado()//funcion que ejecutará el juego
	{	
		do
		{	
			temporal=0;	
			if(inicial==0)
			{	
	    		for(i=0;i<strlen(palabra);i++)
				{	
	    			if(palabra[i]==' ')
					{
						temp[i]=' ';	
	    				longitud++;	
					}	
	    			else
					{	
						temp[i]='_';	
	        			longitud++;
	    			}
	    		}
	    	}
			inicial=1;
			temp[longitud]='\0';
			for(i=0;i<strlen(rep);i++)
			{
				if(rep[i]==word)
				{
					repetido=true;
					break;
				}
				else
				{
					repetido=false;
				}
			}
			if(repetido==false)
			{
				for(i=0;i<strlen(palabra);i++)
				{
					if(palabra[i]==word)
					{
						temp[i]=word;
						acierto++;
						temporal=1;
					}
				}
			}
			if(repetido==false)
			{
				if(temporal==0)
				{
					oport=oport-1;
				}
			}
			else
			{
				cout<<"Esa letra ya fue digitada"<<endl<<endl;
			}
			cout<<endl;
			for(i=0;i<strlen(temp);i++)
			{
				cout<<" "<<temp[i];// aqui es cuando no hay letricas
			}
			cout<<endl;
			if(strcmp(palabra,temp)==0)
			{
				ganar=true;//manda a decir que si lo logró :v
				break;
			}
			cout<<endl;
			cout<<"Letras acertadas: "<<acierto<<endl;
			cout<<"Oportunidades restantes: "<<oport<<endl;
			rep[j]=word;
			j++;
			cout<<"Digita una letra para adivinar la palabra:  ";
			cin>>word;
			system("cls");
		}
		while(oport != 0);
	}
};

class Imprimir//mensajito perrón
{
	private:
	string mensaje;
	public:
	void setmensaje(string a)
	{
		mensaje=a;
	}
	string getmensaje()
	{
		return mensaje;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	system("cls");
	Juego Victima;//va a la parte en la que se abre el juego
	Imprimir mostrar;//va a la parte del mensaje
	Victima.Ahorcado();//se le asigna jugador a la funcion que acaba de llamar a la clase
	if(ganar)//si pasa a ser true salta este aviso
	{
		cout<<endl<<endl;
		mostrar.setmensaje("¡¡Chachi, lo conseguiste :3!!");
		cout<<mostrar.getmensaje();
	}
	else//si queda igual de falso
	{
		cout<<endl<<endl;
		mostrar.setmensaje("Sorry, perdiste =(, pero puedes volver a intentarlo");
		cout<<mostrar.getmensaje();
	}
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
