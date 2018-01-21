
#include<stdlib.h>
#include <stdio.h>
#include "link.h"

//1.��ʼ��������
void init_list(node *phead)
{
	phead->data = 0;
	phead->next = NULL;
}

//2.�жϵ������Ƿ�Ϊ�գ���Ϊ����������true�����򷵻�false��
bool is_empty(node *phead)
{
	return (phead->next != NULL);
}
//3.��ȡ��������
int get_length(node *phead)
{
	int count = 0;
	while (phead->next != NULL)
	{
		count++;
		phead = phead->next;
	}
	return count;
}
//4.������ͷ�巨
bool insert_head(node *phead, elem_type value)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = phead->next;
    phead->next = newnode;
	if(phead->next->data == value)
	{
		return true;
	}
	return false;
}
//5.������β�巨
bool insert_tail(node *phead, elem_type value)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	while (phead->next != NULL)
	{
		phead = phead->next;
	}
	newnode->next = phead->next;
	phead->next = newnode;
	if (phead->next->data == value)
	{
		return true;
	}
	else
		return false;
}
//6.���ٵ�����
void destory_list(node *phead)
{
	if (is_empty(phead))
	{
		free(phead->next);
	}
}
//7.��ʾ����ȫ������
void show_list(node *phead)
{
	phead = phead->next;
	while(phead != NULL)
	{
		printf("%d\n",phead->data);
		phead = phead->next;
	}
}
//8.����������ɾ�����
bool delnum_node(node *phead,elem_type value)
{
	if (getnum_node(phead,value) == -1)
	{
		return false;
	}
	while(phead->next->next != NULL)
	{
		if(phead->next->next->data != value)
		{
			phead = phead->next;
		}	
	}
	node *p = phead->next;
	phead->next = phead->next->next;
	free(p);
	return true;


}
//9.�����������ý��
int getnum_node(node *phead,elem_type value)
{
	while(phead->next != NULL)
	{
		if(phead->next->data == value)
		{
			return value;
		}
		else
		{
			phead = phead->next;
		}	
	}
	return -1;  //��ʾû���ҵ������
}
//10.����λ��ɾ�����
bool delete_node(node *phead,int pos)
{
	if (pos <= 0 || pos > get_length(phead))
	{
		printf("pos is error\n");
		return false;
	}
	else
	{
		for (int i=1;i<pos;i++)
		{
			phead = phead->next;
		}
		node *p = phead->next;
		phead->next = phead->next->next;
		free(p);
		return true;
	}
}
//11.����λ�ò�����
bool insert_node(node *phead,int pos,elem_type value)
{
	if (pos <= 0 || pos > get_length(phead))
	{
		printf("pos is error\n");
		return false;
	}
	else
	{
		node *newnode = (node *)malloc(sizeof(node));
		for (int i=1;i<pos;i++)
		{
			phead = phead->next;
		}
		newnode->data = value;
		newnode->next = phead->next;
		phead->next = newnode;
		return true;
	}
}
//12.����λ�û�ý��
int get_node(node *phead,int pos)
{
	if (pos <= 0 || pos > get_length(phead))
	{
		printf("pos is error\n");
		return -1;
	}
	else
	{
		for (int i=1;i<=pos;i++)
		{
			phead = phead->next;
		}
		return phead->data;
	}
}
//13.ͷɾ��
bool delete_head(node *phead)
{
	node *p = phead->next;
	phead->next = phead->next->next;
	free(p);
	/*if (p->data == phead->next->data)
	{
		return true;
	}*/
	return true;
}
//14.βɾ��
bool delete_tail(node *phead)
{
	while (phead->next->next != NULL)
	{
		phead = phead->next;
	}
	node *p = phead->next;
	phead->next = NULL;
	free(p);
	return true;
}