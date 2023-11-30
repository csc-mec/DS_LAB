<h1 align="center">DS LAB</h1>

## Contents
- [Contents](#contents)
- [Programs](#programs)
- [Psudocodes](#psudocodes)

## Programs
| Program | Code | Psudocode |
| :--- | :--- | :--- |
| Linear Search | [Link](https://github.com/csc-mec/DS_LAB/blob/main/linear_search.c) | [TBD](#linear-search) |
| Binary Search | [Link](https://github.com/csc-mec/DS_LAB/blob/main/binary_search.c) | [TBD](#binary-search) |
| Bubble Sort | [Link](https://github.com/csc-mec/DS_LAB/blob/main/bubble_sort.c) | [TBD](#bubble-sort) |
| Repeated Element | [Link](https://github.com/csc-mec/DS_LAB/blob/main/RepeatedElement.c) | [TBD](#repeated-element) |
| Second Largest | [Link](https://github.com/csc-mec/DS_LAB/blob/main/SecondLargest.c) | [TBD](#second-largest) |
| Selection Sort | [Link](https://github.com/csc-mec/DS_LAB/blob/main/selection_sort.c) | [TBD](#selection-sort) |
| Insertion Sort | [Link](https://github.com/csc-mec/DS_LAB/blob/main/InsertionSort.c)| [TBD](#insertion-sort) |
| Polynomial Addition | [Link](https://github.com/csc-mec/DS_LAB/blob/main/polynomial_add.c) | [TBD](#polynomial-addition) |
| Stack | [Link](https://github.com/csc-mec/DS_LAB/blob/main/stack.c) | [TBD](#stack) |
| Queue | [Link](https://github.com/csc-mec/DS_LAB/blob/main/queue.c) | [TBD](#queue) |
| Triplet Representation | [Link](https://github.com/csc-mec/DS_LAB/blob/main/SparseMatrix.c) | [TBD](#triplet-representation) |
| Sparse Matrix Addition | [Link](https://github.com/csc-mec/DS_LAB/blob/main/SparseMatrixAddition.c) | [TBD](#sparse-matrix-addition) |
| Circular queue | [Link](https://github.com/csc-mec/DS_LAB/blob/main/CircularQueue.c) | [TBD](#circular-queue) |
| Priority queue | [Link](https://github.com/csc-mec/DS_LAB/blob/main/PriorityQueue.c) | [TBD](#priority-queue) |
| Double ended queue | [Link](https://github.com/csc-mec/DS_LAB/blob/main/DoubleEndedQueue.c) | [TBD](#double-ended-queue) |
| Infix to postfix | [Link](https://github.com/csc-mec/DS_LAB/blob/main/Infix_to_Postfix.c) | [TBD](#infix-to-postfix) |
| Postfix evaluation | [Link](https://github.com/csc-mec/DS_LAB/blob/main/PostfixEvaluation.c) | [TBD](#postfix-evaluation) |
| Linked list | [Link](https://github.com/csc-mec/DS_LAB/blob/main/Linked_List_All.c) | [Link](#linked-list) |
| Queue using linked list | [Link](https://github.com/csc-mec/DS_LAB/blob/main/queue_using_linked_list.c) | [Link](#queue-using-linked-list) |
| Stack using linked list | [Link](https://github.com/csc-mec/DS_LAB/blob/main/StackLinkedList.c) | [Link](#stack-using-linked-list) |
| Circular linked list | [Link](https://github.com/csc-mec/DS_LAB/blob/main/CircularLinkedList.c) | [TBD](#circular-linked-list) |
| Doubly linked list | [TBD]() | [TBD](#doubly-linked-list) |


## Psudocodes

### Linked List
```psudocode
PROGRAM LINKEDLIST

PROCEDURE ADDFRONT ACCEPTING HEAD
    CREATE NEWNODE
    INPUT NEWNODE->DATA
    SET NEWNODE->NEXT = HEAD
    SET HEAD = NEWNODE
    RETURN HEAD
END PROCEDURE

PROCEDURE ADDREAR ACCEPTING HEAD
    CREATE NEWNODE
    INPUT NEWNODE->DATA
    SET NEWNODE->NEXT = NULL
    IF HEAD = NULL
        SET HEAD = NEWNODE
    ELSE
        SET CURRENT = HEAD
        WHILE CURRENT->NEXT != NULL
            SET CURRENT = CURRENT->NEXT
        END WHILE
        SET CURRENT->NEXT = NEWNODE
    END IF
    RETURN HEAD
END PROCEDURE

PROCEDURE DELETEFRONT ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "LIST IS EMPTY"
    ELSE
        SET TEMP = HEAD
        SET HEAD = HEAD->NEXT
        FREE TEMP
    END IF
    RETURN HEAD
END PROCEDURE

PROCEDURE DELETEREAR ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "LIST IS EMPTY"
    ELSE
        SET CURRENT = HEAD
        IF CURRENT->NEXT = NULL
            SET HEAD = NULL
            FREE CURRENT
        ELSE
           WHILE CURRENT->NEXT != NULL
                IF CURRENT->NEXT->NEXT = NULL
                    SET TEMP = CURRENT->NEXT
                    SET CURRENT->NEXT = NULL
                    FREE TEMP
                ELSE
                    SET CURRENT = CURRENT->NEXT
                END IF
            END WHILE
        END IF
    END IF
    RETURN HEAD
END PROCEDURE

PROCEDURE DISPLAY ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "LIST IS EMPTY"
    ELSE
        SET CURRENT = HEAD
        WHILE CURRENT != NULL
            PRINT CURRENT->DATA
            SET CURRENT = CURRENT->NEXT
        END WHILE
    END IF
END PROCEDURE

END PROGRAM
```
### Queue using linked list
```psudocode

PROGRAM QUEUEUSINGLINKEDLIST

PROCEDURE ENQUEUE ACCEPTING HEAD
    CREATE NEWNODE
    INPUT NEWNODE->DATA
    SET NEWNODE->NEXT = NULL
    IF HEAD = NULL
        SET HEAD = NEWNODE
    ELSE
        SET CURRENT = HEAD
        WHILE CURRENT->NEXT != NULL
            SET CURRENT = CURRENT->NEXT
        END WHILE
        SET CURRENT->NEXT = NEWNODE
    END IF
    RETURN HEAD
END PROCEDURE

PROCEDURE DEQUEUE ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "QUEUE IS EMPTY"
    ELSE
        SET TEMP = HEAD
        SET HEAD = HEAD->NEXT
        FREE TEMP
    END IF
    RETURN HEAD
END PROCEDURE

PROCEDURE DISPLAY ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "QUEUE IS EMPTY"
    ELSE
        SET CURRENT = HEAD
        WHILE CURRENT != NULL
            PRINT CURRENT->DATA
            SET CURRENT = CURRENT->NEXT
        END WHILE
    END IF
END PROCEDURE

END PROGRAM
```
### Stack using linked list
```psudocode
PROGRAM STACKUSINGLINKEDLIST

PROCEDURE PUSH ACCEPTING HEAD
    CREATE NEWNODE
    INPUT NEWNODE->DATA
    SET NEWNODE->NEXT = HEAD
    SET HEAD = NEWNODE
    RETURN HEAD
END PROCEDURE

PROCEDURE POP ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "STACK IS EMPTY"
    ELSE
        SET TEMP = HEAD
        SET HEAD = HEAD->NEXT
        FREE TEMP
    END IF
    RETURN HEAD
END PROCEDURE

PROCEDURE DISPLAY ACCEPTING HEAD
    IF HEAD = NULL
        PRINT "STACK IS EMPTY"
    ELSE
        SET CURRENT = HEAD
        WHILE CURRENT != NULL
            PRINT CURRENT->DATA
            SET CURRENT = CURRENT->NEXT
        END WHILE
    END IF
END PROCEDURE

END PROGRAM
```



