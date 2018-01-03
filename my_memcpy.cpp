#include <stdio.h>
#include <assert.h>
#include <string.h>

//内存拷贝
/*void *my_memcpy(void *des,void *src,int count)
{
	assert(des);
	assert(src);
	char *p = (char *)des;
	char *q = (char *)src;
	if (p <= q || p >= q + count)
	{
		while(count--)
		{
			p = q;
			p++;
			q++;
		}
	}
	else
	{
		q = q + count - 1;
		p = p + count - 1;
		while (count--)
		{
			p = q;
			p--;
			q--;
		}

	}
	return des;
}
void main()
{
	char p1[256] = "hello,world!";
    char p2[256] = {0};
    //my_memcpy(p2,p1,strlen(p1)+1);
    //printf("%s\n",p2);
    //my_memcpy(NULL,p1,strlen(p1)+1);
    //my_memcpy(p2,NULL,strlen(p1)+1);
    my_memcpy(p1+1,p1,strlen(p1)+1);
    printf("%s\n",p1);
    my_memcpy(p1,p1+1,strlen(p1)+1);
    printf("%s\n",p1);

}*/

//求the的个数
void main()
{
	char str[] = "the Thee The the tHe";
	char *temp = strtok(str," ");
	int count = 0;
	while(temp != NULL)
	{
		if (strcmp(temp,"the") == 0)
		{
			count++;
		}
		//printf("%s\n",temp);
		temp = strtok(NULL," ");
	}
	printf("%d\n",count);
}