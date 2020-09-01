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



/*
给出两个 非空 的链表用来表示两个非负的整数。其中它们各自的位数是按照 逆序 的方式存储的,
并且它们的每个节点只能存储 一位 数字。

如果我们将这两个数相加起来,则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外,这两个数都不会以 0 开头。

示例:

输入 (2 -> 4 -> 3) + (5 -> 6 -> 4)
输出 7 -> 0 -> 8
原因 342 + 465 = 807

题目来源:力扣<<LeetCode>>
链接:https://leetcode-cn.com/problems
著作权归领扣网络所有。商业转载请联系官方授权,非商业转载请注明出处。
*/


/*****************************************************
@funtion: addTwoNumbers
@description: sum of  two list node element
@param: l1 and l2 is the lists will add
@return: a new list
****************************************************/
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
    	l1 = l1 ? (temp += l1->data, l1->next) : l1;
    	l2 = l2 ? (temp += l2->data, l2->next) : l2;
    	cur->data = temp % 10;//取个位数
    	temp /= 10;//取十位数,下次和剩余的数相加,相对于向前进一位
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
