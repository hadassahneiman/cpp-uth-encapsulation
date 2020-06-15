/*
// Created by hn on 6/14/20.
*/

#ifndef CPP_UTH_ENCAPSULATION_HADASSAHNEIMAN_CPP2C_H
#define CPP_UTH_ENCAPSULATION_HADASSAHNEIMAN_CPP2C_H

/** Class Box **/

struct Box{
    double length;
    double width;
    double height;
};
typedef struct Box Box;

/*declarations of public methods of box*/

void ZN3BoxC1Ed(Box* const this, double dim);

void ZN3BoxC1Eddd(Box* const this, double l, double w, double h);

void ZN3BoxD1Ev(Box* constthis);

void ZN3BoxmLEd(Box* const this, double mult);

void ZNK3Box5printEv(const Box* const this);


/** Class Shelf **/

const char* const ZN5Shelf7DEF_MSGE;
const char* ZN5Shelf7messageE;

struct Shelf{
    Box boxes[3];
};
typedef struct Shelf Shelf;

/*declarations of public methods in shelf*/

void ZN5Shelf6setBoxEiRK3Box(Shelf* const this, int index, const Box* dims);

double ZNK5Shelf9getVolumeEv(const Shelf* const this);

void ZNK5Shelf5printEv(const Shelf* const this);

#endif