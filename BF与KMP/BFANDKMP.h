#ifndef __BFANDKMP_H
#define __BFANDKMP_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

//利用BF思想解决串匹配
int BF(const char *s, const char *p, int pos);//从s串的pos位置开始寻找匹配p串的位置

//利用KMP思想解决串匹配
int KMP(const char *s, const char *p, int pos);//从s串的pos位置开始寻找匹配p串的位置

//寻找字符数组p的next数组
void GetNext(const char *p, int *next);

#endif