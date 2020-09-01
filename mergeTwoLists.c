/**
Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};
*/
#include <stdio.h>
#include <stdlib.h>


/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例:

输入:1->2->4, 1->3->4
输出:1->1->2->3->4->4
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

题目来源:力扣<<LeetCode>>
链接:https://leetcode-cn.com/problems
著作权归领扣网络所有。商业转载请联系官方授权,非商业转载请注明出处。
*/



typedef int datatype;

typedef struct ListNode
{
	datatype data;
	struct ListNode *next;
}listnode, *linklist;


/*****************************************************
@funtion: mergeTwoLists
@description: merge two lists
@param: l1 and l2 is the lists will merge
@return: merged list
****************************************************/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	linklist head = NULL;
	linklist res = NULL;
	if((head = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc fail\n"); return head;
	}
	head->data = 0;
	head->next = NULL;
	res = head;
	l1 = l1->next;
	l2 = l2->next;
	while(l1 && l2)
	{
		if(l1->data <= l2->data)
		{
			res->next = l1;
			l1 = l1->next;
		}
		else
		{
			res->next = l2;
			l2 = l2->next;
		}
		res = res->next;
	}
	res->next = (l1 == NULL) ? l2 : l1;
	return head;
}


/*****************************************************
@funtion: list_show
@description: show the  linklist H 
@param: H is the linklist will show
@return: none
****************************************************/
void list_show(linklist H)
{
	while(H->next)
	{
		printf("%d ", H->next->data);
		H = H->next;
	}
	printf("\n");
}


/*****************************************************
@funtion: linklist_create
@description: create a linklist  
@param: nonde
@return: a new linklist
****************************************************/
linklist linklist_create(void)
{
	linklist H, r, p;
	datatype value;

	if( (H=(linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc fail\n"); return H;
	}
	H->data = 0;
	H->next = NULL;
	r = H;

	while(1)
	{
		printf("please input a number(-1 exit)\n");
		scanf("%d", &value);
		if(value == -1) break;
		if( (p=(linklist)malloc(sizeof(listnode))) == NULL )
		{
			printf("malloc fail\n"); return H;
		}
		p->data = value;
		p->next = r->next;
		r->next = p;
		r = p;
	}
	return H;
}



int main()
{
    linklist H1, H2, H3;
    H1 = linklist_create();
    list_show(H1);
    H2 = linklist_create();
    list_show(H2);
    printf("H: %p\n", H1);
    H3 = mergeTwoLists(H1, H2);
    list_show(H3);
    return 0;
}
