/*
// Created by hn on 6/14/20.
*/
#include <stdio.h>
#include "cpp2c_defs.h"

extern const char* const ZN5Shelf7DEF_MSGE;
extern const char* ZN5Shelf7messageE;

static Box ZL8largeBox;
static Box ZGVZ8thisFuncvE5box99;
static Box ZGVZ8thatFuncvE5box88;

void Z8thisFuncv(){

    static size_t count = 0;

    printf("\n--- thisFunc() ---\n\n");

    if (!count++)
        ZN3BoxC1Eddd(&ZGVZ8thisFuncvE5box99, 99, 99, 99);

    ZN3BoxmLEd(&ZGVZ8thisFuncvE5box99, 10);
}

void Z8thatFuncv(){

    static size_t count = 0;

    printf("\n--- thatFunc() ---\n\n");

    if (!count++)
        ZN3BoxC1Eddd(&ZGVZ8thatFuncvE5box88, 88, 88, 88);

    ZN3BoxmLEd(&ZGVZ8thatFuncvE5box88 ,10);
}

void Z7doBoxesv()
{
    Box b1, b2, b3, b4;
    printf("\n--- Start Z7doBoxesv() ---\n\n");

    ZN3BoxC1Ed(&b1, 3);
    ZN3BoxC1Eddd(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.height * b1.width * b1.length);
    printf("b2 volume: %f\n", b2.height * b2.width * b2.length);

    ZN3BoxmLEd(&b1, 1.5);
    ZN3BoxmLEd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.height * b1.width * b1.length);
    printf("b2 volume: %f\n", b2.height * b2.width * b2.length);

    b3 = b2;

    b4 = b2;
    ZN3BoxmLEd(&b4, 3);

    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    ZN3BoxmLEd(&b3, 1.5);
    ZN3BoxmLEd(&b4, 0.5);
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End Z7doBoxesv() ---\n\n");

    ZN3BoxD1Ev(&b4);
    ZN3BoxD1Ev(&b3);
    ZN3BoxD1Ev(&b2);
    ZN3BoxD1Ev(&b1);
}


void Z9doShelvesv()
{
    Box aBox, tmp1, tmp2;
    Shelf aShelf;
    size_t i;
    printf("\n--- start Z9doShelvesv() ---\n\n");

    ZN3BoxC1Ed(&aBox, 5);

    for (i = 0; i < 3; ++i)
        ZN3BoxC1Ed(&aShelf.boxes[i], 1);

    ZNK5Shelf5printEv(&aShelf);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &ZL8largeBox);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    ZNK5Shelf5printEv(&aShelf);
    ZN5Shelf7messageE = "This is the total volume on the shelf:";
    ZNK5Shelf5printEv(&aShelf);
    ZN5Shelf7messageE = "Shelf's volume:";
    ZNK5Shelf5printEv(&aShelf);

    ZN3BoxC1Eddd(&tmp1, 2, 4, 6);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &tmp1);
    ZN3BoxD1Ev(&tmp1);

    ZN3BoxC1Ed(&tmp2, 2);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &tmp2);
    ZN3BoxD1Ev(&tmp2);

    ZNK5Shelf5printEv(&aShelf);

    printf("\n--- end Z9doShelvesv() ---\n\n");

    for (i = 0; i < 3; ++i)
        ZN3BoxD1Ev(&aShelf.boxes[3 - i - 1]);

    ZN3BoxD1Ev(&aBox);
}

int main()
{
    ZN3BoxC1Eddd(&ZL8largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    Z7doBoxesv();

    Z8thisFuncv();
    Z8thisFuncv();
    Z8thisFuncv();
    Z8thatFuncv();
    Z8thatFuncv();

    Z9doShelvesv();

    printf("\n--- End main() ---\n\n");

    ZN3BoxD1Ev(&ZGVZ8thatFuncvE5box88);
    ZN3BoxD1Ev(&ZGVZ8thisFuncvE5box99);
    ZN3BoxD1Ev(&ZL8largeBox);

    return 0;
}