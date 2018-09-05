#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector> 

using namespace std;

int ConvierteANumero(string valor){   
	int n = atoi(valor.c_str()); 
    return n; 
}

bool esNumero(string valor){
	if(valor.length()>1){
		return false;
	}
	else{
		if(valor[0]>47 && valor[0]<58){
			return true;
		}
		else{
			return false;
		}
	}
}

void mostrarMatriz(int matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool revisarValorFila(int i, int valor, int matriz[][9]){
    for(int j=0;j<9;j++){
        if(matriz[i][j]==valor){
            return true;
        }
    }
    return false;
}

bool revisarValorColumna(int j, int valor, int matriz[][9]){
    for(int i=0;i<9;i++){
        if(matriz[i][j]==valor){
            return true;
        }
    }
    return false;
}

bool revisarSubMatriz(int i, int j, int valor, int matriz[][9]){
    for(int ii=0;ii<i;ii++){
        for(int jj=0;jj<9;jj++){
            if(matriz[ii][jj]==valor){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]){

	//Para ingresar los datos, se ingresa por ejemplo: ./ejecutable "[1;2;3]" "[4;5;6]" "[7;8;9]"
	int matriz[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			matriz[i][j]=0;

	string argumento;
	string pos_i;
	string pos_j;
	string num;
	int cont=1;

	for(int i=1;i<argc;i++){
		argumento=argv[i];
		if (argumento.substr(0,1)=="[" && argumento.substr(6,1)=="]"){
			if(argumento.substr(2,1)==";" && argumento.substr(4,1)==";"){
				pos_i=argumento.substr(1,1);
				pos_j=argumento.substr(3,1);
				num=argumento.substr(5,1);
				if(esNumero(pos_i) && esNumero(pos_j) && esNumero(num)){
					while(argumento!=""){
						if(ConvierteANumero(pos_i)>=0 && ConvierteANumero(pos_i)<9){
							if(ConvierteANumero(pos_j)>=0 && ConvierteANumero(pos_j)<9){
								if(ConvierteANumero(num)>=1 && ConvierteANumero(num)<=9){
									if (matriz[ConvierteANumero(pos_i)][ConvierteANumero(pos_j)]==0){
										matriz[ConvierteANumero(pos_i)][ConvierteANumero(pos_j)]=ConvierteANumero(num);
										cont++;
									}
									else{
										cout<<"ya se ingreso este parametro: "<<argumento<<endl;
										mostrarMatriz(matriz);
									}
								}
								else{
									cout<<"error de formato"<<endl;
								}
							}
							else{
								cout<<"error de formato"<<endl;
							}
						}
						else{
							cout<<"error de formato"<<endl;
						}
						argumento=argumento.substr(7);
					}
				}
				else{
					cout<<"error de formato"<<endl;
				}
			}
			else{
				cout<<"error de formato"<<endl;
			}
		}
		else{
			cout<<"error de formato"<<endl;
		}
		if(cont==argc){
			mostrarMatriz(matriz);
			cout<<endl;	
		}
	}
}
