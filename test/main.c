//
// Created by regoeco on 22/12/16.
//

#include <stdio.h>
typedef struct Chaining chaining;
typedef struct Class class;

struct Chaining {
    int r;
    char* (*letter)(char);
    int (*number)(int);
};
//Class
struct Class{
    // Methods interface
    chaining (*repeat)(int);
};

// Methods interface

chaining repeat(int);
int number(int n);
char* letter(char c);
// Construct
void init(class *c){
    c->repeat = repeat;
}

int main(){
    //objetc
    class d;
    init(&d);

    printf("%d", d.repeat(2).number(2));
    return 1;
}


chaining repeat(int r) {
    chaining s;


// Methods implementation
    int number(int n){
        if(n == 1){
            return 1*r;
        }else
            return 2*r;
    }
    char* letter(char c) {
        if(c == 'a'){
            return "hola";
        }else
            return "hello";
    }


    s.r = r;
    s.letter  = letter;
    s.number = number;


    return s;
}