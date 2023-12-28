PROGRAM TREE_TRAVERSAL

STRUCTURE Node
    INTEGER key
    Node POINTER left
    Node POINTER right

SET Node POINTER root = NULL
SET Node POINTER temp = NULL

PROCEDURE FUNCTION newNode(INTEGER key) RETURNS Node POINTER
    SET Node POINTER node = Allocate memory for Node
    SET node->key = key
    SET node->left = NULL
    SET node->right = NULL
    RETURN node
END PROCEDURE

PROCEDURE FUNCTION inorder(Node POINTER root)
    IF root != NULL
        CALL inorder(root->left)
        PRINT root->key
        CALL inorder(root->right)
    END IF
END PROCEDURE

PROCEDURE FUNCTION preorder(Node POINTER root)
    IF root != NULL
        PRINT root->key
        CALL preorder(root->left)
        CALL preorder(root->right)
    END IF
END PROCEDURE

PROCEDURE FUNCTION postorder(Node POINTER root)
    IF root != NULL
        CALL postorder(root->left)
        CALL postorder(root->right)
        PRINT root->key
    END IF
END PROCEDURE

PROCEDURE FUNCTION delete(Node POINTER root, INTEGER key)
    IF root == NULL
        RETURN
    END IF
    IF key < root->key
        SET root->left = CALL delete(root->left, key)
    ELSE IF key > root->key
        SET root->right = CALL delete(root->right, key)
    ELSE
        IF root->left == NULL AND root->right == NULL
            FREE root
            SET root = NULL
        ELSE IF root->left == NULL
            SET Node POINTER temp = root
            SET root = root->right
            FREE temp
        ELSE IF root->right == NULL
            SET Node POINTER temp = root
            SET root = root->left
            FREE temp
        ELSE
            SET INTEGER temp = CALL minimum(root->right)
            SET root->key = temp
            CALL delete(root->right, temp)
        END IF
    END IF
END PROCEDURE

PROCEDURE FUNCTION insert(Node POINTER node, INTEGER key) RETURNS Node POINTER
    IF node == NULL
        RETURN CALL newNode(key)
    END IF
    IF key < node->key
        SET node->left = CALL insert(node->left, key)
    ELSE IF key > node->key
        SET node->right = CALL insert(node->right, key)
    END IF
    RETURN node
END PROCEDURE

PROCEDURE FUNCTION search(Node POINTER root, INTEGER key) RETURNS Node POINTER
    IF root == NULL OR root->key == key
        RETURN root
    END IF
    IF root->key < key
        RETURN CALL search(root->right, key)
    END IF
    RETURN CALL search(root->left, key)
END PROCEDURE

PROCEDURE FUNCTION minimum(Node POINTER root) RETURNS INTEGER
    IF root == NULL
        RETURN 0
    END IF
    WHILE root->left != NULL
        SET root = root->left
    END WHILE
    RETURN root->key
END PROCEDURE

PROCEDURE FUNCTION maximum(Node POINTER root) RETURNS INTEGER
    IF root == NULL
        RETURN 0
    END IF
    WHILE root->right != NULL
        SET root = root->right
    END WHILE
    RETURN root->key
END PROCEDURE

PROCEDURE FUNCTION main() RETURNS INTEGER
    SET INTEGER ch, key
    WHILE TRUE
        PRINT "1.Insert 2.Search 3.Minimum 4.Maximum 5.Inorder 6.Preorder 7.Postorder         8.Delete 9.Exit"
        PRINT "Enter your choice:"
        READ ch
        SWITCH ch
            CASE 1:
                PRINT "Enter the key:"
                READ key
                SET root = CALL insert(root, key)
            CASE 2:
                PRINT "Enter the key:"
                READ key
                SET temp = CALL search(root, key)
                IF temp == NULL
                    PRINT "Key not found"
                ELSE
                    PRINT "Key found"
                END IF
            CASE 3:
                PRINT "Minimum key is ", CALL minimum(root)
            CASE 4:
                PRINT "Maximum key is ", CALL maximum(root)
            CASE 5:
                CALL inorder(root)
            CASE 6:
                CALL preorder(root)
            CASE 7:
                CALL postorder(root)
            CASE 8:
                PRINT "Enter the key:"
                READ key
                CALL delete(root, key)
            CASE 9:
                EXIT program
        END SWITCH
    RETURN 0
    END WHILE
END PROCEDURE
END PROGRAM
