#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <stdlib.h>
typedef std::set<std::string> intset;//definicion de tipo de dato,conjunto de eneteros
typedef std::map<int, intset>row;
typedef std::map<int, row> table;
table N;
typedef struct grammar{
    std::string generator;
    std::string generator2;
    std::string terminaloGenerator;

};

bool CYK(grammar G[],char*);
int length(char*);
void print(intset &a);
std::set<std::string> buildset(char r);

int main()
{
    char W[15];
    std::cout << "write the word ";
    std::cin>>W;

    printf("length %i",length(W));

    grammar G[9];


    G[0].generator='S';
    G[0].generator2='C';
    G[0].terminaloGenerator='A';

    G[1].generator='B';
    G[1].generator2='S';
    G[1].terminaloGenerator='D';

    G[2].generator='R';
    G[2].generator2='K';
    G[2].terminaloGenerator='B';

    G[3].generator='A';
    G[3].generator2='S';

    G[4].generator='D';
    G[4].generator2='R';

    G[5].generator=83;
    G[5].terminaloGenerator=120;

    G[6].generator='C';
    G[6].terminaloGenerator=108;

    G[7].generator=75;
    G[7].terminaloGenerator=99;

    G[8].generator=82;
    G[8].terminaloGenerator=116;

    CYK(G,W);
/*
    S 83
    C 67
    A 65
    R 82
    K 75
    B 66
    D 68
    l 108
    c 99
    x 120
    t 116

    */

printf("table \n\n");
	for (int i = 1;i < length(W);i++) {

		for (int j = 1;j < length(W);j++) {
			printf("\nt[%i,%i]", i, j);
			print(N[i][j]);
		}
	}
    return 0;
}
bool CYK(grammar G[],char *w){
    int n=0;//length
    int a=0;//run over the word
        n=length(w);
        printf(" x ");
        for(int i=1;i<n;i++){
                for(int x=0;x<9;x++){//searh on the struct grammar
                    if(G[x].terminaloGenerator==w[a]){
                        printf("%c",G[x].generator);
                        N[i][1]=buildset(G[x].generator);
                        a++;//run over the word

                    }
                }

            for(int j=2;j<n;j++){

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
std::set<std::string> buildset(std::string r){
    std::set<std::string> aux;
    aux.insert(r);
    printf("  conjunto generado: ");
    print(aux);
return aux;
}
void print(intset &a){
    intset::iterator i=a.begin();
    while(i!=a.end()){
        printf("%i ",*i);
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

