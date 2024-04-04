#include "Variable.h"

void Variable::initVar(string inName, string inPrompt){
    name = inName;
    prompt = inPrompt;
    instan = false;
    value = false;
}

void Variable::specialVar(string inName, bool inValue){
    name = inName;
    prompt = "";
    instan = true;
    value = inValue;
}

void Variable::initField(string inName, string inField){
    name = inName;
    prompt = "";
    instan = true;
    value = true;
    field = inField;
}

void Variable::initArea(string inName, string inArea){
    name = inName;
    prompt = "";
    instan = true;
    area = inArea;
}
