#include <stdio.h>
int float_to_int(float f)
{
	int f_new = *(int *)&f;  //因为float类型不能移位，所以转换成整型
	
	//取符号位
	int sign;        
	sign = f_new >> 31;
	
	//提取指数位
	int ind1 = f_new & 0x7f800000;
	int ind2 = ind1 >> 23;
	int index = ind2 - 127;

	//如果输入为0
	if (index == -127)
	{
		return 0;
	}
    
	//提取尾数位
	int last = f_new & 0x7fffff;
    
	//在尾数位前面加1
	last |= 0x00800000;

	//提取整数
	int t = last >> (24 - (index+1));

	//判断符号
	if (sign)
	{
		t = -t;
	}

	return t;
}
void main()
{
	float f = 0;
	int res = float_to_int(f);
	printf("%d\n",res);
}