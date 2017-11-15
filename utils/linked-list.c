#include "linked-list.h"

/* 创建一个 node */
struct ListNode *createNode(int val, struct ListNode *next)
{
  struct ListNode *new_node = (struct ListNode *)malloc(sizeof(next));
  if(new_node == NULL) {
    printf("Error create a new node.\n");
    exit(0);
  }

  new_node->val = val;
  new_node->next = next;
  
  return new_node;
}

/* 在链表前插入一个节点 */
struct ListNode *prependNode(struct ListNode *head, int val)
{
  struct ListNode *new_node = createNode(val, head);
  head =  new_node;
  return head;
}

/* 在链表后插入一个节点 */
struct ListNode *appendNode(struct ListNode *head, int val)
{
  struct ListNode *cursor = head;
  while(cursor->next != NULL) {
    cursor = cursor->next;
  }

  struct ListNode *new_node = createNode(val, NULL);
  cursor->next = new_node;
  return head;
}

/* 打印链表以及内容 */
void printList(struct ListNode *head) {
  struct ListNode *cursor = head;
  printf("链表: ");
  while(cursor->next != NULL) {
    printf("[%d] -> ", cursor->val);
    cursor = cursor->next;
  }
  printf("[%d]\n", cursor->val);
}

/* 打印一个节点 */
void printListNode(struct ListNode *node) {
	printf("节点: [%d]\n", node->val);
}
