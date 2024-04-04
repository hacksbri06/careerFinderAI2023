#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include <string>

using namespace std;
// Rod's Version
class Clause
{
    public:
        string name;
        bool value;
        string thenName;
        string thenVal;
        bool checked;
        string field;

        void initClause(string, bool);
        void specialClause(string, bool, string, string);
        void fieldClause(string, string);
};

#endif