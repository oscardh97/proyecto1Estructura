#ifndef VARRAYLIST_H
#define VARRAYLIST_H

#include "fsarraylist.h"
#include "object.h"


class VArrayList : public FSArrayList{
 private:
    double delta;
    void resize();
 public:
    VArrayList(double);
    virtual ~VArrayList();
    virtual bool insert(Object*, int);
};

#endif // FSARRAYLIST_H
