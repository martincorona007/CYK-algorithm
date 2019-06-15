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
char getS(intset &on);
char step_seven(grammar G[],intset &a,intset &b);
std::set<char> buildset(char r);



int main()
{
    char W[15];
    std::cout << "write the word ";
    std::cin>>W;
    bool val;
    //printf("length %i",length(W));

    grammar G[7];


    G[0].generator=83;//S
    G[0].generator2=66;//B
    G[0].generator3=68;//A

    G[1].generator=82;//R
    G[1].generator2=75;//K
    G[1].generator3=68;//D

    G[2].generator=68;//D
    G[2].generator2=83;//S
    G[2].generator3=82;//R


    G[3].generator=66;//B
    G[3].terminal=108;//l

    G[4].generator=82;//R
    G[4].terminal=116;//t

    G[5].generator=75;//K
    G[5].terminal=99;//c

    G[6].generator=83;//S
    G[6].terminal=120;//x
    val=CYK(G,W);
    if(val){
        printf("\n accepted");
    }else{
        printf("\n rejected");
    }
/*
    S 83 C 67    A 65   R 82    K 75    B 66    D 68    l 108   c 99     x 120 t 116
    */

printf("\ntable \n\n");
	for (int i = 1;i <=length(W);i++) {

		for (int j = 1;j <= length(W);j++) {
            if((i==1&&j==2)|| (i==2&&j==2)){
                printf("\n\t t[%i,%i]", i, j);

            }else if(i==1&&j==3){
                printf("\n\t\t t[%i,%i]", i, j);

            }else{
             printf("\nt[%i,%i]", i, j);

            }


			print(N[i][j]);
		}
	}
    return 0;
}
bool CYK(grammar G[],char *w){
    int n=0;//length
    int a=0;//run over the word
    int i=1;
    char res;
        n=length(w);//get the length of the word

        while(i<=n){
            for(int x=3;x<7;x++){
                if(G[x].terminal==w[a]){
                     printf("\nconstruye el conjunto  %i,%i",i,1);
                        N[i][1]=buildset(G[x].generator);
                       a++;
                       i++;
                }
            }
        }
        for(int j=2;j<=n;j++){

            for(int ii=1;ii<=n-j+1;ii++){
                N[ii][j]=buildset(' ');
                for(int k=1;k<=j-1;k++){
                printf("\n in N[%i][%i] from N[%i]][%i]",ii,j,ii,k);

                res=step_seven(G,N[ii][k],N[ii+k][j-k]);

                if(res==0||res=='\n'){
                    if(getS( N[ii][j])=='\0'|| getS( N[ii][j])==0){
                         N[ii][j]=buildset(' ');
                    }
                }else{


                    N[ii][j]=buildset(res);
                }
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


return N[1][n].find('S')!=N[1][n].end();
}
char step_seven(grammar G[],intset &a,intset &b){

    intset::iterator i=a.begin();
    intset::iterator j=b.begin();


    while(i!=a.end()&&j!=b.end()){
        for(int x=0;x<=2;x++){
            printf("\t {%c %c}",*i,*j);
             if(G[x].generator2==*i && G[x].generator3==*j){
                   printf(" gen %c",G[x].generator);

                    return G[x].generator;
             }/*else{
                return (*k=='\0')?:*k;
             }*/
        }

         /*if(G[x].generator2!=*i && G[x].generator3!=*j){
               // printf(" gen %c",G[x].generator);

               return G[x].generator;
         }*/


        i++;
        j++;

    }

    /*while(i!=a.end()){
        printf("\nNii,k     %c ",*i);
        i++;
    }
    while(k!=b.end()){
        printf("\nNii+k,j-k %c ",*k);
        k++;
    }*/
    return '\0';

}
std::set<char> buildset(char r){
    std::set<char> aux;
    aux.insert(r);
    printf("\n conjunto generado: ");
    print(aux);
return aux;

}
char getS(intset &on){
    intset::iterator i=on.begin();
    while(i!=on.end()){
        //printf("%s ",*i);
        //std::cout<<*i;
        return *i;
        i++;
    }
}
void print(intset &a){
    intset::iterator i=a.begin();
    while(i!=a.end()){
        //printf("%s ",*i);
        std::cout<<*i;
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
