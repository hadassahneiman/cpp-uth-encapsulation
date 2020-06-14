//
// Created by hn on 6/14/20.
//
#include <stdio.h>
#include "cpp2c_defs.h"

static Box largeBox;

void thisFunc(){

    static size_t count = 0;
    static Box box99;

    if (count == 3) {
        ZN3BoxD1Ev(&box99);
        return;
    }

    printf("\n--- thisFunc() ---\n\n");

    if (!count++)
        ZN3BoxC1Eddd(&box99, 99, 99, 99);

    ZN3BoxmLEd(&box99, 10);
}

void thatFunc(){
    static Box box88;
    static size_t count = 0;

    if (count == 2){
        ZN3BoxD1Ev(&box88);
        return;
    }

    printf("\n--- thatFunc() ---\n\n");
    if (!count++)
        ZN3BoxC1Eddd(&box88, 88, 88, 88);

    ZN3BoxmLEd(&box88 ,10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1;
    ZN3BoxC1Ed(&b1, 3);
    Box b2;
    ZN3BoxC1Eddd(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", 27.0);
    printf("b2 volume: %f\n", 120.0);

    ZN3BoxmLEd(&b1, 1.5);
    ZN3BoxmLEd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.height * b1.width * b1.length);
    printf("b2 volume: %f\n", b2.height * b2.width * b2.length);

    Box b3 = b2;

    Box b4 = b2;
    ZN3BoxmLEd(&b4, 3);

    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    ZN3BoxmLEd(&b3, 1.5);
    ZN3BoxmLEd(&b4, 0.5);
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    ZN3BoxD1Ev(&b4);
    ZN3BoxD1Ev(&b3);
    ZN3BoxD1Ev(&b2);
    ZN3BoxD1Ev(&b1);
}


void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    ZN3BoxC1Ed(&aBox, 5);

    Shelf aShelf;
    for (int i = 0; i < 3; ++i)
        ZN3BoxC2Ed(&aShelf.boxes[i]);

    ZNK5Shelf5printEv(&aShelf);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &largeBox);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    ZNK5Shelf5printEv(&aShelf);
    ZN5Shelf7messageE = "This is the total volume on the shelf:";
    ZNK5Shelf5printEv(&aShelf);
    ZN5Shelf7messageE = "Shelf's volume:";
    ZNK5Shelf5printEv(&aShelf);

    Box tmp2;
    ZN3BoxC1Eddd(&tmp2, 2, 4, 6);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &tmp2);
    ZN3BoxD1Ev(&tmp2);

    Box tmp3;
    ZN3BoxC1Ed(&tmp3, 2);
    ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &tmp3);
    ZN3BoxD1Ev(&tmp3);

    ZNK5Shelf5printEv(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    for (int i = 0; i < 3; ++i)
        ZN3BoxD1Ev(&aShelf.boxes[3 - i - 1]);

    ZN3BoxD1Ev(&aBox);
}

int main()
{
    ZN3BoxC1Eddd(&largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");

    thatFunc();
    thisFunc();
    ZN3BoxD1Ev(&largeBox);

    return 0;
}