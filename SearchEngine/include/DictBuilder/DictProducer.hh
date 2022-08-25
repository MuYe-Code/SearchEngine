#ifndef __DICTPRODUCER_H__
#define __DICTPRODUCER_H__
#include "Configuration.hh"
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using std::vector;
using std::string;
using std::set;
using std::unordered_map;
using std::pair;

class SplitTool;    //前向声明

class DictProducer
{
public:
    //DictProducer(Configuration & conf);
    DictProducer(Configuration & conf, SplitTool *splitTool);      //构造函数,专为中文处理
    ~DictProducer();
    void buildEnDict();     //创建英文字典
    void bulidCnDict();     //创建中文字典
    void buildIndex(const string &filepath);    //创建索引
    void storeDict(const string &filepath);     //将词典写入文件
    void storeIndex(const string &filepath);    //将索引写入文件

    void showFiles() const;     //查看文件路径，作为测试用
    void showDict() const;      //查看词典，作为测试用

private:
    void getFiles(string dir, vector<string> &files);   //获取预料文件目录下所有文件的绝对路径
    string cleanup_str(const string &word);             //针对英文单词大写转小写并过滤标点
    size_t getByteNum_UTF8(const char byte);            //获取utf-8编码下字符占据的字节数

private:
    Configuration & _conf;
    vector<string> _files;                      //语料库文件的绝对路径集合
    unordered_map<string,int> _dict;            //利用哈希表加速创建词典库
    unordered_map<string,set<int>> _index;      //字典索引,与词典文件行号对应
    SplitTool *_splitTool;                      //分词工具
};

#endif