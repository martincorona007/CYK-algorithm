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

    grammar G[9];


    G[0].generator='S';
    G[0].generator2='C';
    G[0].generator3='A';

    G[1].generator='B';
    G[1].generator2='S';
    G[1].generator3='D';

    G[2].generator='R';
    G[2].generator2='K';
    G[2].generator3='B';

    G[3].generator='A';
    G[3].generator2='S';

    G[4].generator='D';
    G[4].generator2='R';

    G[5].generator='C';
    G[5].terminal='l';

    G[6].generator='K';
    G[6].terminal='c';

    G[7].generator='S';
    G[7].terminal='x';

    G[8].generator='R';
    G[8].terminal='t';

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
        n=length(w);


        while(i<=n){


                for(int x=0;x<9;x++){//searh on the struct grammar
                    if(G[x].terminal==w[a]){
                        //printf("%c",G[x].generator);
                        printf("\nconstruye el conjunto  %i,%i",i,1);
                        N[i][1]=buildset(G[x].generator);
                        a++;//run over the word
                        i++;
                    }


                }




        }
        printf("\n");
    /*
        printf("%s",G[1].generator);
        printf("%s",G[1].generator2);
        printf("%s",G[1].terminaloGenerator);
        */
//       print(aux);



return 2;
}
std::set<char> buildset(char r){
    std::set<char> aux;
    aux.insert(r);
    printf("  conjunto generado: ");
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

