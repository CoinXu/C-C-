
#ifndef ADT_QUEUE
#define ADT_QUEUE

#include <stdbool.h>

// max queue
#define MAXQUEUE 10

/* define structure */
typedef int Item;

/**
 * 定义Queue节点结构
 * item 存储内容
 * node 存储下一个项目的指针
 */
typedef struct node {
    Item item;
    struct node *next;
} Node;

/**
 * 定义Queue结构
 * front 存储首项指针
 * rear 存储尾项指针
 * items 存储数量
 */
typedef struct queue {
    Node *front;
    Node *rear;
    int items;
} Queue;

/* define interface */

/**
 * 初始化队列
 * 将 pq 初始化为空队列
 */
void initialize(Queue *pq);

/**
 * 检测队列是否已满，返回True或False
 * 判断依据为 Queue->items == MAXQUEUE
 */
bool queue_is_full(const Queue *pq);

/**
 * 检测队列是否为空，返回True或False
 * 判断依据为 Queue->.items == 0
 */
bool queue_is_empty(const Queue *pq);

/**
 * 返回队列中的item数量
 */
int queue_item_count(const Queue *pq);

/**
 * 向队列尾端添加项目
 * 添加前检测是否已满
 * 添加成功，返回True
 * 添加失败，返回False
 */
bool en_queue(Item item, Queue *pq);

/**
 * 从队列首端移出项目
 * 如果队列非空，队列首端的项目复制到 *pitem，并从队列中移出，返回True。
 * 如果移除后队列为空，把队列重置为空队列。
 *
 * 如果队列为空，直接返回False
 */
bool de_queue(Item *pitem, Queue *pq);

/**
 * 清空队列
 */
void empty_the_queue(Queue *pq);

#endif