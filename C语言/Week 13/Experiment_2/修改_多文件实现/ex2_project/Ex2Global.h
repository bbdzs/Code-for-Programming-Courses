//Ex2global.h

#ifndef _Ex2GLOBAL_H_ 
#define _Ex2GLOBAL_H_

extern char fn[100];                                //输入文件名
extern char misword[100];                           //错误单词
extern char crtword[100];                           //正确单词
extern char newfn[100];                             //输出文件名
extern char text[200][50];                          //文章内容
extern int pun[200];                                //对应单词是否最后一位含标点 0否1是
extern int num;                                     //文章单词个数
extern int nummis;                                  //错误行数量

#endif // !_Ex2GLOBAL_H_