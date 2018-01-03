#include <stdio.h>
int float_to_int(float f)
{
	int f_new = *(int *)&f;  //��Ϊfloat���Ͳ�����λ������ת��������
	
	//ȡ����λ
	int sign;        
	sign = f_new >> 31;
	
	//��ȡָ��λ
	int ind1 = f_new & 0x7f800000;
	int ind2 = ind1 >> 23;
	int index = ind2 - 127;

	//�������Ϊ0
	if (index == -127)
	{
		return 0;
	}
    
	//��ȡβ��λ
	int last = f_new & 0x7fffff;
    
	//��β��λǰ���1
	last |= 0x00800000;

	//��ȡ����
	int t = last >> (24 - (index+1));

	//�жϷ���
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