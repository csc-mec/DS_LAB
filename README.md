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
| Repeated Element | [TBD]() | [TBD](#repeated-element) |
| Second Largest | [TBD]() | [TBD](#second-largest) |
| Selection Sort | [Link](https://github.com/csc-mec/DS_LAB/blob/main/selection_sort.c) | [TBD](#selection-sort) |
| Insertion Sort | [Link](https://github.com/csc-mec/DS_LAB/blob/main/InsertionSort.c)| [TBD](#insertion-sort) |
| Polynomial Addition | [Link](https://github.com/csc-mec/DS_LAB/blob/main/polynomial_add.c) | [TBD](#polynomial-addition) |
| Stack | [Link](https://github.com/csc-mec/DS_LAB/blob/main/stack.c) | [TBD](#stack) |
| Queue | [Link](https://github.com/csc-mec/DS_LAB/blob/main/queue.c) | [TBD](#queue) |
| Triplet Representation | [TBD]() | [TBD](#triplet-representation) |
| Sparse Matrix Addition | [TBD]() | [TBD](#sparse-matrix-addition) |
| Circular queue | [TBD]() | [TBD](#circular-queue) |
| Priority queue | [TBD]() | [TBD](#priority-queue) |
| Double ended queue | [TBD]() | [TBD](#double-ended-queue) |
| Infix to postfix | [TBD]() | [TBD](#infix-to-postfix) |
| Postfix evaluation | [TBD]() | [TBD](#postfix-evaluation) |
| Linked list | [TBD]() | [Link](#linked-list) |
| Queue using linked list | [TBD]() | [TBD](#queue-using-linked-list) |
| Stack using linked list | [TBD]() | [TBD](#stack-using-linked-list) |
| Circular linked list | [TBD]() | [TBD](#circular-linked-list) |
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
```

