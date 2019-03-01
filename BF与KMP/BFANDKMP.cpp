#include "BFANDKMP.h"

//利用BF思想解决串匹配,从s串的pos位置开始寻找匹配p串的位置
int BF(const char *s, const char *p, int pos)
{
	assert(s != NULL && p != NULL);

	int lens = strlen(s);//分别求出两个字符串的有效长度
	int lenp = strlen(p);

	if(lenp > lens )//先检查原字符长度是否大于等于目的字符串
	{
		return -1;
	}
	int i = pos; //从pos位置开始寻找匹配目的字符串的位置，因为可能目的字符串不止一次出现在原字符串中
	int j = 0;
	while( i < lens && j < lenp)
	{
		if( s[i] == p[j])//如果两个元素相等，则比较各自的下一个字符
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
		return i - j; //如果j越界，则代表p串中的所有字符已经匹配完毕，输出匹配位置
	}
	return -1;//如果i越界则代表匹配不成功
}

//利用KMP思想解决串匹配,从s串的pos位置开始寻找匹配p串的位置
void GetNext(const char *p, int *next) 
{
	//   因为在调用这个函数的KMP函数中，在调用之前已经断言过p和next不能为空，
	//所以在这里可以不用再判断两个指针是否为空
	int i = 1;
	int k = 0;  //next数组前两个值是默认的值
	int len = strlen(p);

	next[0] = -1;
	next[1] = 0;

	//利用KMP思想求匹配的真子串的长度存到next中
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
    int i = pos ;   //   i代表以源字符串中pos号下标开始到字符串结束中寻找匹配的目的串的匹配位置。
    int j = 0;      //pos的值时用户来决定的
	    
	int *next = (int *)malloc(sizeof(int) * strlen(p)); //为目的串的next数组申请空间
	assert( next != NULL);

	GetNext(p, next);
	while( i < lens && j < lenp)//在i和j都不越界的条件下重复循环寻找匹配位置
	{
		if( j == -1 || s[i] == p[j])//   在else语句中，j有可能因为在回退途中没有相等的真子串而回退到
		{                           //next[0]代表的位置，所以j有可能会被赋值为“-1”，因此这里if语句
			i++;                    //的判断条件得加上“j == -1”如果等于进入语句后j被重新赋值为0，
			j++;                    //然后重新开始从目的串的头与源字符串比较寻找匹配位置(所以会在初始
		}                           //时将next[0]赋值为-1是为了利用现有的语句让j直接回到目的串的头位置)
		else
		{
			j = next[j];
		}
	}
	free(next);          //free必须在return之前

	if( j == lenp)    //   如果目的串先越界，证明j下标之前的字符已经和源字符串相匹配，
	{                 //所以返回在源字符串中开始匹配的位置
		return i - j;
	}
	return -1;        //   如果跳出循环的条件不是j越界，则代表时i越界了，i越界就证明在遍历完源字符串
	                  //后还是没有找到匹配的目的字符串，所以返回错误值-1
}

