#include "BFANDKMP.h"

//����BF˼������ƥ��,��s����posλ�ÿ�ʼѰ��ƥ��p����λ��
int BF(const char *s, const char *p, int pos)
{
	assert(s != NULL && p != NULL);

	int lens = strlen(s);//�ֱ���������ַ�������Ч����
	int lenp = strlen(p);

	if(lenp > lens )//�ȼ��ԭ�ַ������Ƿ���ڵ���Ŀ���ַ���
	{
		return -1;
	}
	int i = pos; //��posλ�ÿ�ʼѰ��ƥ��Ŀ���ַ�����λ�ã���Ϊ����Ŀ���ַ�����ֹһ�γ�����ԭ�ַ�����
	int j = 0;
	while( i < lens && j < lenp)
	{
		if( s[i] == p[j])//�������Ԫ����ȣ���Ƚϸ��Ե���һ���ַ�
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if( j == lenp)
	{
		return i - j; //���jԽ�磬�����p���е������ַ��Ѿ�ƥ����ϣ����ƥ��λ��
	}
	return -1;//���iԽ�������ƥ�䲻�ɹ�
}

//����KMP˼������ƥ��,��s����posλ�ÿ�ʼѰ��ƥ��p����λ��
void GetNext(const char *p, int *next) 
{
	//   ��Ϊ�ڵ������������KMP�����У��ڵ���֮ǰ�Ѿ����Թ�p��next����Ϊ�գ�
	//������������Բ������ж�����ָ���Ƿ�Ϊ��
	int i = 1;
	int k = 0;  //next����ǰ����ֵ��Ĭ�ϵ�ֵ
	int len = strlen(p);

	next[0] = -1;
	next[1] = 0;

	//����KMP˼����ƥ������Ӵ��ĳ��ȴ浽next��
	while( i + 1 < len )
	{
		if(p[k] == p[i] || k == -1)
		{
			next[i+1] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(const char *s, const char *p, int pos)
{
	assert(s != NULL && p != NULL);

	int lens = strlen(s);
	int lenp = strlen(p);
	if( lenp > lens)
	{
		return -1;
	}
    int i = pos ;   //   i������Դ�ַ�����pos���±꿪ʼ���ַ���������Ѱ��ƥ���Ŀ�Ĵ���ƥ��λ�á�
    int j = 0;      //pos��ֵʱ�û���������
	    
	int *next = (int *)malloc(sizeof(int) * strlen(p)); //ΪĿ�Ĵ���next��������ռ�
	assert( next != NULL);

	GetNext(p, next);
	while( i < lens && j < lenp)//��i��j����Խ����������ظ�ѭ��Ѱ��ƥ��λ��
	{
		if( j == -1 || s[i] == p[j])//   ��else����У�j�п�����Ϊ�ڻ���;��û����ȵ����Ӵ������˵�
		{                           //next[0]�����λ�ã�����j�п��ܻᱻ��ֵΪ��-1�����������if���
			i++;                    //���ж������ü��ϡ�j == -1��������ڽ�������j�����¸�ֵΪ0��
			j++;                    //Ȼ�����¿�ʼ��Ŀ�Ĵ���ͷ��Դ�ַ����Ƚ�Ѱ��ƥ��λ��(���Ի��ڳ�ʼ
		}                           //ʱ��next[0]��ֵΪ-1��Ϊ���������е������jֱ�ӻص�Ŀ�Ĵ���ͷλ��)
		else
		{
			j = next[j];
		}
	}
	free(next);          //free������return֮ǰ

	if( j == lenp)    //   ���Ŀ�Ĵ���Խ�磬֤��j�±�֮ǰ���ַ��Ѿ���Դ�ַ�����ƥ�䣬
	{                 //���Է�����Դ�ַ����п�ʼƥ���λ��
		return i - j;
	}
	return -1;        //   �������ѭ������������jԽ�磬�����ʱiԽ���ˣ�iԽ���֤���ڱ�����Դ�ַ���
	                  //����û���ҵ�ƥ���Ŀ���ַ��������Է��ش���ֵ-1
}

