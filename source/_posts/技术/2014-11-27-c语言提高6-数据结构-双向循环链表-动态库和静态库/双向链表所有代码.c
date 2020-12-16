#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int data;
	struct node * next;
	struct node * per;
}Node;


//尾插法
Node * createListTail()
{
	//创建头结点
	Node * head = (Node*)malloc(sizeof(Node));
	Node *  cur = NULL;
	head->next = head;
	head->per = head;
	Node * tail = head;//确定尾节点
	int data;
	scanf("%d",&data);
	while (data)
	{
		cur = (Node*)malloc(sizeof(Node));
		cur->data = data;
		tail->next = cur;
		cur->per = tail;
		tail = cur;//将tail 移动到最后
		scanf("%d",&data);
	}
	//回环
	cur->next = head;
	head->per = cur;

	return head;
}

//头插法
Node  * createListHead()
{
	Node * head = (Node*)malloc(sizeof(Node));
	head->next = head;
	head->per = head;
	int data;
	scanf("%d",&data);
	while (data)
	{
		Node * cur = (Node*)malloc(sizeof(Node));
		cur->data = data;
                cur->next = head->next;
		cur->per = head;
		head->next = cur;
		cur->next->per = cur;
		scanf("%d", &data);
	}
	return head;
}

//遍历链表
void traveseList(Node *  head)
{
	Node * temp = head->next;//双向链表需要将头节点为标识节点
	while (temp!=head)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

//获取链表长度
int lenList(Node * head)
{
	int len = 0;
	Node * temp = head->next;
	while (temp!=head)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

//查找链表元素
Node * searchNode(Node * head,int findData)
{
	Node * temp = head->next;
	while (temp!=head)
	{
		if (temp->data == findData)
			break;
		temp = temp->next;
	}
	return temp;
}

//双向查询链表
Node * search2Node(Node * head, int findData)
{
	Node * lowNode = head->next;
	Node * highNode = head->per;
	while (lowNode!=highNode)//相等的时候表示结束
	{
		if (lowNode->data == findData)
			return lowNode;
		if (highNode->data == findData)
			return highNode;
		lowNode = lowNode->next;
		highNode = highNode->per;
	}
	return NULL;
}

//根据地址删除指定元素
void delNode(Node * head,Node * findNode)
{
	Node * temp = head->next;
	while (temp!=head)
	{
		if (temp == findNode)
		{
			temp->per->next = temp->next;
			temp->next->per = temp->per;
			free(findNode);
			break;
		}
		temp = temp->next;
	}
}

//对数值进行排序  交换数据
void sortListD(Node * head)
{
	int len = lenList(head);
	for (int i = 0; i < len-1; i++)
	{
		Node * temp = head->next;//冒泡排序 都是从0起点开始
		for (int j = 0; j < len-1-i; j++)
		{
			if (temp->data>temp->next->data)
			{
				temp->data ^= temp->next->data;
				temp->next->data ^= temp->data;
				temp->data ^= temp->next->data;
			}
			temp = temp->next;
		} 
	}
}

//对数值进行排序  交换指针
void sortListP(Node * head)
{
	Node * temp = NULL;
	int len = lenList(head);
	for (int i = 0; i < len - 1; i++)
	{ 
		Node * sh = head;
		Node * p = sh->next;
		Node  * q = p->next;   
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p->data>q->data)//画图交换
			{
				sh->next = q;
				q->per = sh;
				p->next = q->next;
				q->next = p;
				p->per = q;
				q->next->per = p; 

				temp = p;
				p = q;
				q = temp;
			}
			sh = sh->next;
			q = q->next;
			p = p->next;
		}
	}
}

//释放链表空间
void freeList(Node * head)
{
	Node  * temp = head->next;
	Node * pro = NULL;
	while (temp->next!=head)//判断下一个节点是否是头结点
	{
		pro = temp->next;
		free(temp);
		temp = pro;
	}
	free(head);
}

int main()
{
	//创建循环链表的时候   直接将头结点的next和per制为head就行 不要制为NULL
	//Node * head = createListTail();
	Node * head = createListHead();
	//sortListD(head);
	//sortListP(head);
	//traveseList(head);
	//freeList(head);
	printf("查找元素\n");
	//Node  * s_node = searchNode(head, 3);
	//if (s_node == head)
	//	printf("元素不存在!\n"); 
	//printf("元素存在!\n");
	Node  * s_node = search2Node(head, 3);
	if (s_node == NULL)
		printf("元素不存在!\n"); 
	else
		printf("元素存在!\n");
	
	delNode(head,s_node); 
	traveseList(head);
	return 0;
}
