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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int temp = 0;
    linklist head = (linklist)malloc(sizeof(listnode));
    linklist cur = head;
    l1 = l1->next;
    l2 = l2->next;
    while(l1 || l2 || temp)
    {
    	cur->next = (linklist)malloc(sizeof(listnode));
    	cur = cur->next;
    	l1 = l1 ? (temp+=l1->data, l1->next) : l1;
    	l2 = l2 ? (temp+=l2->data, l2->next) : l2;
    	cur->data = temp % 10;//取个位数
    	temp /= 10;//取十位数
    }
    cur->next = l1 ? l2 : l1;
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
    H3 = addTwoNumbers(H1, H2);
    list_show(H3);
    return 0;
}
