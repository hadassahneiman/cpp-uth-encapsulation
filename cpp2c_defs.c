//
// Created by hn on 6/14/20.
//
#include <stdio.h>
#include "cpp2c_defs.h"

void ZN3BoxC2Ed(Box* this){
    this -> length = 1;
    this -> width = 1;
    this -> height = 1;
    ZNK3Box5printEv(this);
}

void ZN3BoxC1Ed(Box* this, double dim){
    this -> length = dim;
    this -> width = dim;
    this -> height = dim;
    ZNK3Box5printEv(this);
}

void ZN3BoxC1Eddd(Box *this, double l, double w, double h) {
    this -> length = l;
    this -> width = w;
    this -> height = h;
    ZNK3Box5printEv(this);
}

void ZN3BoxD1Ev(Box *this){
    printf("Box destructor, %f x %f x %f\n", this -> width, this -> height, this -> length);
}

void ZN3BoxmLEd(Box *this, double mult){
    this -> width *= mult;
    this -> height *= mult;
    this -> length *= mult;
}

void ZNK3Box5printEv(const Box *this){
    printf("Box: %f x %f x %f\n", this -> length, this -> width, this -> height);
}

//shelf definitions

const char* const ZN5Shelf7DEF_MSGE = "The total volume held on the shelf is";
const char* ZN5Shelf7messageE = "The total volume held on the shelf is";

void ZN5Shelf6setBoxEiRK3Box(Shelf *this, int index, const Box* dims){
    this -> boxes[index] = *dims;
}

double ZNK5Shelf9getVolumeEv(const Shelf *this){
    double vol = 0;

    for (size_t i = 0; i < 3; ++i)
        vol += this -> boxes[i].length * this -> boxes[i].height * this -> boxes[i].width;

    return vol;
}

void ZNK5Shelf5printEv(const Shelf *this){
    printf("%s %f\n", ZN5Shelf7messageE, ZNK5Shelf9getVolumeEv(this));
}
