typedef int elem_type; 
typedef struct node 
{
	elem_type data;
	struct node *next;
}node;

//1.��ʼ��������
void init_list(node *phead);

//2.�жϵ������Ƿ�Ϊ�գ���Ϊ����������true�����򷵻�false��
bool is_empty(node *phead);

//3.��ȡ��������
int get_length(node *phead);

//4.������ͷ�巨
bool insert_head(node *phead, elem_type value);

//5.������β�巨
bool insert_tail(node *phead, elem_type value);

//6.���ٵ�����
void destory_list(node *phead);

//7.��ʾ����ȫ������
void show_list(node *phead);

//8.����������ɾ�����
bool delnum_node(node *phead,elem_type value);

//9.�����������ý��
int getnum_node(node *phead,elem_type value);

//10.����λ��ɾ�����
bool delete_node(node *phead,int pos);

//11.����λ�ò�����
bool insert_node(node *phead,int pos,elem_type value);

//12.����λ�û�ý��
int get_node(node *phead,int pos);

//13.ͷɾ��
bool delete_head(node *phead);

//14.βɾ��
bool delete_tail(node *phead);