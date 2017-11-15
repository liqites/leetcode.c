#include "leetcode.h"

struct ListNode{
  int val;
  struct ListNode *next;
};

struct ListNode *createNode(int val, struct ListNode *next);
struct ListNode *prependNode(struct ListNode *head, int val);
struct ListNode *appendNode(struct ListNode *head, int val);
void printList(struct ListNode *head);
void printListNode(struct ListNode *node);
