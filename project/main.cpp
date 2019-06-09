#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <stdlib.h>


typedef struct grammar{
    char* generator;
    char* generator2;
    char* terminaloGenerator;

};

bool CYK(grammar G,char*);
int length(char*);

int main()
{
    char W[15];
    std::cout << "write the word ";
    std::cin>>W;

    printf("length %i",length(W));

    grammar G[9];


    G[0].generator="S";
    G[0].generator2="C";
    G[0].terminaloGenerator="A";

    G[1].generator="B";
    G[1].generator2="S";
    G[1].terminaloGenerator="D";

    G[2].generator="R";
    G[2].generator2="K";
    G[2].terminaloGenerator="B";

    G[3].generator="A";
    G[3].generator2="S";

    G[4].generator="D";
    G[4].generator2="R";

    G[5].generator="S";
    G[5].terminaloGenerator="x";

    G[6].generator="C";
    G[6].terminaloGenerator="l";

    G[7].generator="K";
    G[7].terminaloGenerator="c";

    G[8].generator="R";
    G[8].terminaloGenerator="t";

    CYK(*G,W);
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

    return 0;
}
bool CYK(grammar G,char *w){
return true;

}
int length(char *w){
    int i=0;
    while(w[i]!='\0'){
        i++;
    }
    return i;
}
