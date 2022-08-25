#ifndef __SPLITEN_HH
#define __SPLITEN_HH

#include "SplitTool.hh"

class SplitEn
: public SplitTool
{
public:
    SplitEn() { }
    ~SplitEn() { };
    vector<string> cut(const string &sentence) override; //分词函数
};

#endif