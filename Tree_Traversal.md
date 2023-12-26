### Tree Traversal
```
PROGRAM TREE_TRAVERSAL

DEFINE STRUCTURE Node
    INTEGER key
    Node POINTER left
    Node POINTER right
END STRUCTURE

Node POINTER root = NULL
Node POINTER temp = NULL

PROCEDURE newNode(INTEGER key) RETURNS Node POINTER
    Node POINTER node = Allocate memory for Node
    node->key = key
    node->left = NULL
    node->right = NULL
    RETURN node
END PROCEDURE

PROCEDURE inorder(Node POINTER root)
    IF root != NULL THEN
        CALL inorder(root->left)
        PRINT root->key
        CALL inorder(root->right)
    END IF
END PROCEDURE

PROCEDURE preorder(Node POINTER root)
    IF root != NULL THEN
        PRINT root->key
        CALL preorder(root->left)
        CALL preorder(root->right)
    END IF
END PROCEDURE

PROCEDURE postorder(Node POINTER root)
    IF root != NULL THEN
        CALL postorder(root->left)
        CALL postorder(root->right)
        PRINT root->key
    END IF
END PROCEDURE

PROCEDURE delete(Node POINTER root, INTEGER key)
    IF root == NULL THEN
        RETURN
    END IF
    IF key < root->key THEN
        CALL delete(root->left, key)
    ELSE IF key > root->key THEN
        CALL delete(root->right, key)
    ELSE
        IF root->left == NULL AND root->right == NULL THEN
            FREE root
            root = NULL
        ELSE IF root->left == NULL THEN
            Node POINTER temp = root
            root = root->right
            FREE temp
        ELSE IF root->right == NULL THEN
            Node POINTER temp = root
            root = root->left
            FREE temp
        ELSE
            INTEGER temp = CALL minimum(root->right)
            root->key = temp
            CALL delete(root->right, temp)
        END IF
    END IF
END PROCEDURE

PROCEDURE insert(Node POINTER node, INTEGER key) RETURNS Node POINTER
    IF node == NULL THEN
        RETURN CALL newNode(key)
    END IF
    IF key < node->key THEN
        node->left = CALL insert(node->left, key)
    ELSE IF key > node->key THEN
        node->right = CALL insert(node->right, key)
    END IF
    RETURN node
END PROCEDURE

PROCEDURE search(Node POINTER root, INTEGER key) RETURNS Node POINTER
    IF root == NULL OR root->key == key THEN
        RETURN root
    END IF
    IF root->key < key THEN
        RETURN CALL search(root->right, key)
    END IF
    RETURN CALL search(root->left, key)
END PROCEDURE

PROCEDURE minimum(Node POINTER root) RETURNS INTEGER
    IF root == NULL THEN
        RETURN 0
    END IF
    WHILE root->left != NULL DO
        root = root->left
    END WHILE
    RETURN root->key
END PROCEDURE

PROCEDURE maximum(Node POINTER root) RETURNS INTEGER
    IF root == NULL THEN
        RETURN 0
    END IF
    WHILE root->right != NULL DO
        root = root->right
    END WHILE
    RETURN root->key
END PROCEDURE

PROCEDURE main() RETURNS INTEGER
    INTEGER ch, key
    WHILE TRUE DO
        PRINT "1.Insert 2.Search 3.Minimum 4.Maximum 5.Inorder 6.Preorder 7.Postorder 8.Delete 9.Exit"
        PRINT "Enter your choice:"
        READ ch
        CASE ch OF
            1:
                PRINT "Enter the key:"
                READ key
                root = CALL insert(root, key)
            2:
                PRINT "Enter the key:"
                READ key
                temp = CALL search(root, key)
                IF temp == NULL THEN
                    PRINT "Key not found"
                ELSE
                    PRINT "Key found"
                END IF
            3:
                PRINT "Minimum key is ", CALL minimum(root)
            4:
                PRINT "Maximum key is ", CALL maximum(root)
            5:
                CALL inorder(root)
            6:
                CALL preorder(root)
            7:
                CALL postorder(root)
            8:
                PRINT "Enter the key:"
                READ key
                CALL delete(root, key)
            9:
                EXIT program
            DEFAULT:
                PRINT "Invalid choice"
        END CASE
    END WHILE
    RETURN 0
END PROCEDURE
END PROGRAM
```
