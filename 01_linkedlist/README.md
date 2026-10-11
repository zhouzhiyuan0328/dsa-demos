# 01 单链表
# 单链表（不带头结点）

## 已实现
- create_list
- print_list
- append
- delete_node
- reverse_list
- clear_list

## 核心模板
- 遍历：p = head; while (p) { ...; p = p->next; }
- 反转：prev/curr/next 三指针
- 删除：找前一个节点，改它的 next

## 易错点
- node->next = NULL 是初始化，不是接下一个
- malloc 内存是垃圾值，不初始化会崩
- free 之后要置 NULL
- 删头要单独处理，返回新 head
- reverse 返回 prev，不是 head

## 复杂度
- 遍历 O(n)
- 尾插 O(n)（无 tail），O(1)（有 tail）
- 反转 O(n) 时间，O(1) 空间
待补充
