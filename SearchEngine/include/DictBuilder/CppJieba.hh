#ifndef __SPLITTOOLCPPJIEBA_H__
#define __SPLITTOOLCPPJIEBA_H__

#include "SplitTool.hh"
#include "../../lib/cppjieba/Jieba.hpp"
#include "Configuration.hh"
#include <string>
#include <vector>

using std::string;
using std::vector;

/*
const char * const DICT_PATH = getPath("DICT_PATH").c_str() 是危险的
getPath()返回的是值拷贝的临时变量
使用c_str()函数获取的是string内容的指针，但是临时变量会立即销毁导致指针失效
*/
const string DICT_PATH = getPath("DICT_PATH");  // 最大概率法(MPSegment: Max Probability)分词所使用的词典路径
const string HMM_PATH = getPath("HMM_PATH");  // 隐式马尔科夫模型(HMMSegment: Hidden Markov Model)分词所使用的词典路径
const string USER_DICT_PATH = getPath("USER_DICT_PATH");  // 用户自定义词典路径
const string IDF_PATH = getPath("IDF_PATH");  // IDF路径
const string STOP_WORD_PATH = getPath("STOP_WORD_PATH");  // 停用词路径

class CppJieba
: public SplitTool
{
public:
    CppJieba()
    : _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH) //初始化Jieba类对象
    {
        
    }

    ~CppJieba() {};

    vector<string> cut(const string &sentence) override; //分词函数

private:
    //Configuration &_conf;
    cppjieba::Jieba _jieba;
};

#endif
