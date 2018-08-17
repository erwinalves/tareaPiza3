#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int ConvierteANumero(string valor){   
	int n = atoi(valor.c_str()); 
    return n; 
}

bool esNumero(string valor){
	int aux = atoi(valor.c_str());
	//if(aux==0){
	//	return false;
	//}
	//else{
		return true;
	//}
}

void mostrarMatriz(int matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

void extraerDatos(string argumento, string pos_i, string pos_j, string num){
	pos_i=argumento.substr(1,1);
	pos_j=argumento.substr(3,1);
	num=argumento.substr(5,1);
}

void agregarNumero(){

}

void verificar(){

}

int main(int argc, char* argv[]){
	int matriz[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			matriz[i][j]=0;

	string argumento=argv[1];
	string pos_i;
	string pos_j;
	string num;
	if (argumento.substr(0,1)=="[")
	{
		while(argumento!="")
		{
			//extraerDatos(argumento, pos_i, pos_j, num);
			pos_i=argumento.substr(1,1);
			//cout<<pos_i<<endl;
			pos_j=argumento.substr(3,1);
			//cout<<pos_j<<endl;
			num=argumento.substr(5,1);
			//cout<<num<<endl;
			if(esNumero(pos_i) && esNumero(pos_j) && esNumero(num))
			{
				//cout<<"si"<<endl;
				if(ConvierteANumero(pos_i)>=0 && ConvierteANumero(pos_i)<9)
				{
					if(ConvierteANumero(pos_j)>=0 && ConvierteANumero(pos_j)<9)
					{
						if(ConvierteANumero(num)>=1 && ConvierteANumero(num)<=9)
						{
							if (matriz[ConvierteANumero(pos_i)][ConvierteANumero(pos_j)]==0)
							{
								matriz[ConvierteANumero(pos_i)][ConvierteANumero(pos_j)]=ConvierteANumero(num);
							}
							else
							{
								cout<<"error de formato"<<endl;
							}
							//mostrarMatriz(matriz);
						}
						else
						{
							cout<<"error de formato"<<endl;
						}
					}
					else
					{
						cout<<"error de formato"<<endl;
					}
				}
				else
				{
					cout<<"error de formato"<<endl;
				}
			}
			else
			{
				cout<<"error de formato"<<endl;
			}
			argumento=argumento.substr(7);
		}
		mostrarMatriz(matriz);
	}
	else
	{
		cout<<"error de formato"<<endl;
	}
}
