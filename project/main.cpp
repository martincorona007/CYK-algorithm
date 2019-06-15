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
    char generator; //example S->AB generator=S generator2=A generator3=B
    char generator2;
    char generator3;
    char terminal;//example S->x generator=S terminal=x

};

bool CYK(grammar G[],char*);//the algorithm
int length(char*);//get the length of the word
void print(grammar G[]);
char getS(intset &on);//get the value of N[%i][%i] where is all generators
char step_seven(grammar G[],intset &a,intset &b);//step seven of the algorithm
std::set<char> buildset(char r);//add to the intset



int main()
{
    char W[15];
    std::cout << "Write the word: ";
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


    print(G);//print grammar
    val=CYK(G,W);
    if(val){
        printf("\n Accepted");
    }else{
        printf("\n Rejected");
    }
/*
    S 83 C 67    A 65   R 82    K 75    B 66    D 68    l 108   c 99     x 120 t 116
    */


    return 0;
}
bool CYK(grammar G[],char *w){
    int n=0;//length
    int a=0;//run over the word
    int i=1;//index
    char res;//get the generator from step_seven
        n=length(w);//get the length of the word

        while(i<=n){
            for(int x=3;x<7;x++){//specify where are the terminals on the grammar
                if(G[x].terminal==w[a]){//check if the word given is equals to the terminals on the grammar
                         N[i][1]=buildset(G[x].generator);//then insert in the set
                       a++;
                       i++;
                }
            }
        }
        for(int j=2;j<=n;j++){//index

            for(int ii=1;ii<=n-j+1;ii++){//index
                N[ii][j]=buildset(' ');
                for(int k=1;k<=j-1;k++){//index

                  res=step_seven(G,N[ii][k],N[ii+k][j-k]);//get generator from the grammar
            /*this conditional it's for no remplace the set by 0 */
                    if(res==0||res=='\n'){//check if res is equals to 0 or blank, this means that there's not generator
                        if(getS( N[ii][j])=='\0'|| getS( N[ii][j])==0){//Here i get what is on the set,and compare to 0 and black
                             N[ii][j]=buildset(' ');
                        }//if there is a generator on the set don't do nothing.
                    }else{


                        N[ii][j]=buildset(res);//save on the set
                    }
                }
            }
        }




return N[1][n].find('S')!=N[1][n].end();//check if reach on the last cell
}
char step_seven(grammar G[],intset &a,intset &b){

    intset::iterator i=a.begin();//iterator
    intset::iterator j=b.begin();//iterator


    while(i!=a.end()&&j!=b.end()){//iterate to the end
        for(int x=0;x<=2;x++){//specify where is the generator on the grammar

             if(G[x].generator2==*i && G[x].generator3==*j){//check generators on the grammar

                    return G[x].generator;//return
             }
        }




        i++;
        j++;

    }


    return '\0';//return black if the algorithm not found on the grammar

}
std::set<char> buildset(char r){
    std::set<char> aux;
    aux.insert(r);
return aux;
}
char getS(intset &on){
    intset::iterator i=on.begin();
    while(i!=on.end()){
        return *i;
        i++;
    }
}
void print(grammar G[]){

    for(int i=0;i<=2;i++){
        std::cout<<"\n"<<G[i].generator<<"->"<<G[i].generator2<<" "<<G[i].generator3;

    }
    for(int x=3;x<=6;x++){
        std::cout<<"\n"<<G[x].generator<<"->"<<G[x].terminal;

    }


}
int length(char *w){
    int i=0;
    while(w[i]!='\0'){
        i++;
    }
    return i;
}
