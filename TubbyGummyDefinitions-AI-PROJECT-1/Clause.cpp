#include "Clause.h"

void Clause::initClause(string inName, bool inValue){
    name = inName;
    value = inValue;
    checked = false;
}

void Clause::specialClause(string inName, bool inValue, string tName, string tVal){
    name = inName;
    value = inValue;
    thenName = tName;
    thenVal = tVal;
    checked = false;
}

void Clause::fieldClause(string inName, string inField){
    name = inName;
    field = inField;
    checked = false;
}
