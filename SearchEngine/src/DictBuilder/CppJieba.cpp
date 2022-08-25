#include "../../include/DictBuilder/CppJieba.hh"

vector<string> CppJieba::cut(const string &sentence){
    vector<string> words;
    _jieba.CutAll(sentence, words); // FullSegment
    return std::move(words);        //减少拷贝
}