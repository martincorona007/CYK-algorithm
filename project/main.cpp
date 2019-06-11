#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <stdlib.h>
typedef std::set<char> intset;//definicion de tipo de dato,conjunto de eneteros
typedef std::map<int, intset>row;
typedef std::map<int, row> table;
table N;
typedef struct grammar{
    char generator;
    char generator2;
    char generator3;
    char terminal;

};

bool CYK(grammar G[],char*);
int length(char*);
void print(intset &a);
std::set<char> buildset(char r);



int main()
{
    char W[15];
    std::cout << "write the word ";
    std::cin>>W;

    //printf("length %i",length(W));

    grammar G[8];


    G[0].generator=83;//S
    G[0].generator2=66;//B
    G[0].generator3=65;//A

    G[1].generator=82;//R
    G[1].generator2=75;//K
    G[1].generator3=68;//D

    G[2].generator=68;//D
    G[2].generator2=83;//S
    G[2].generator3=82;//R

    G[3].generator=65;//A
    G[3].generator2=83;//S
    G[3].generator3=82;//R

    G[4].generator=66;//B
    G[4].terminal=108;//l

    G[5].generator=82;//R
    G[5].terminal=116;//t

    G[6].generator=75;//K
    G[6].terminal=99;//c

    G[7].generator='S';//S
    G[7].terminal='x';//x

    CYK(G,W);
/*
    S 83 C 67    A 65   R 82    K 75    B 66    D 68    l 108   c 99     x 120 t 116

    */

printf("table \n\n");
	for (int i = 1;i <=length(W);i++) {

		for (int j = 1;j <= length(W);j++) {
			printf("\nt[%i,%i]", i, j);
			print(N[i][j]);
		}
	}
    return 0;
}
bool CYK(grammar G[],char *w){
    int n=0;//length
    int a=0;//run over the word
    int i=1;
        n=length(w);//get the length of the word

        while(i<=n){
            for(int x=4;x<8;x++){
                if(G[x].terminal==w[a]){
                     printf("\nconstruye el conjunto  %i,%i",i,1);
                        N[i][1]=buildset(G[x].generator);
                       a++;
                       i++;
                }
            }
        }
        /*
        for(int j=2;j<=n;j++){
            for(int ii=1;ii<n-j+1;ii++){
                N[ii][j]=buildset('0');
                for(int k=1;k<j-1;k++){/*
                    intset::iterator it;
                    it=intset.find(N[ii][k]);


                }
            }
        }*/



return 2;
}
std::set<char> buildset(char r){
    std::set<char> aux;
    aux.insert(r);
    printf(" conjunto generado: ");
    print(aux);
return aux;

}
void print(intset &a){
    intset::iterator i=a.begin();
    while(i!=a.end()){
        printf("%c ",*i);
        i++;
    }
}
int length(char *w){
    int i=0;
    while(w[i]!='\0'){
        i++;
    }
    return i;
}

