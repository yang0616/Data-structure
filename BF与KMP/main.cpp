#include "BFANDKMP.h"

int main()
{
    //����KMP˼��ʵ��
	char s[] = "abcdesfsdfsdf";
	char p[] = "sfsd";
	
	printf("%d\n",KMP(s, p, 1));
	printf("%d\n",KMP(s, p, 6));
	printf("%d\n",KMP(s, p, 8));

	//����BF˼��ʵ��
	//char s[] = "abcdesfsdfsdf";
	//char p[] = "sfsd";
	//printf("%d\n",BF(s, p, 2));
	//printf("%d\n",BF(s, p, 10));
	
	return 0;
}




