#include "solution.h"

 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 	int tmp = 0;
 	int carry = 0;
 	int stop = 0;
 	int set_head = 1;

 	struct ListNode *l1_pointer = l1;
 	struct ListNode *l2_pointer = l2;

 	struct ListNode *head = NULL;
 	struct ListNode *tail = head;


 	while(!stop) {

 		struct ListNode *node = (struct ListNode *)malloc(sizeof(*l1));
 		node->next = NULL;

 		if(l1_pointer == NULL && l2_pointer == NULL) {
 			stop = 1;
 			if(carry > 0) {
				node->val = carry;
				tail->next = node;
				tail = node;
 			}

 			continue;
 		}

 		tmp = carry;

 		if(l1_pointer != NULL) {
 			tmp += l1_pointer->val;
 		}
 		if (l2_pointer != NULL)
 		{
 			tmp += l2_pointer->val;
 		}

 		carry = tmp / 10;
 		tmp = tmp % 10;

 		node->val = tmp;

 		if(set_head) {
 			head = node;
 			tail = head;
 			set_head = 0;
 		} else {
 			tail->next = node;
 			tail = node;
 		}

 		if(l1_pointer != NULL) {
 			l1_pointer = l1_pointer->next;
 		}
 		if(l2_pointer != NULL) {
 			l2_pointer = l2_pointer->next;
 		}
 	};

 	return head;
 }
