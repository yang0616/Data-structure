#ifndef __BFANDKMP_H
#define __BFANDKMP_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

//����BF˼������ƥ��
int BF(const char *s, const char *p, int pos);//��s����posλ�ÿ�ʼѰ��ƥ��p����λ��

//����KMP˼������ƥ��
int KMP(const char *s, const char *p, int pos);//��s����posλ�ÿ�ʼѰ��ƥ��p����λ��

//Ѱ���ַ�����p��next����
void GetNext(const char *p, int *next);

#endif