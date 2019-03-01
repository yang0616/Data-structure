#include "BFANDKMP.h"

int main()
{
    //测试KMP思想实现
	char s[] = "abcdesfsdfsdf";
	char p[] = "sfsd";
	
	printf("%d\n",KMP(s, p, 1));
	printf("%d\n",KMP(s, p, 6));
	printf("%d\n",KMP(s, p, 8));

	//测试BF思想实现
	//char s[] = "abcdesfsdfsdf";
	//char p[] = "sfsd";
	//printf("%d\n",BF(s, p, 2));
	//printf("%d\n",BF(s, p, 10));
	
	return 0;
}




