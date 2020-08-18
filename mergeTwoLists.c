/**
Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};
*/
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct ListNode
{
	datatype data;
	struct ListNode *next;
}listnode, *linklist;


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
			printf("23443\n");

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


void list_show(linklist H)
{
	while(H->next)
	{
		printf("%d ", H->next->data);
		H = H->next;
	}
	printf("\n");
}

linklist linklist_create()
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
