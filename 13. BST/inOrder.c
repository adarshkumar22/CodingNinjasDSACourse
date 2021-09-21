#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
    int info;
    struct bstNode *left;
    struct bstNode *right;
};
typedef struct bstNode *BSTNODEPTR;

BSTNODEPTR newNode(int val)
{
    BSTNODEPTR t = (BSTNODEPTR)malloc(sizeof(struct bstNode));
    t->info = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

BSTNODEPTR insert(BSTNODEPTR rootNode, int data)
{
    if (rootNode == NULL)
        return newNode(data);

    if (data < rootNode->info)
        rootNode->left = insert(rootNode->left, data);

    else
        rootNode->right = insert(rootNode->right, data);

    return rootNode;
}

void inOrder(BSTNODEPTR root)
{
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->info);
    inOrder(root->right);
    return;
}

int main()
{
    int opt, data;
    BSTNODEPTR root = NULL;
    do
    {
        printf("\nDo you want to insert an element in B.S.T.\nEnter 1: YES\nEnter 2: NO\n\nTO use INORDER traversal\nEnter - 3\n\n");
        scanf("%d", &opt);

        if (opt == 1)
        {
            printf("Enter the value: ");
            scanf("%d", &data);
            if(root== NULL)
                root = insert(root, data);
            else {
                insert(root, data);
            }
        }
        else if (opt == 2)
        {
            printf("\n....EXIT....");
        }
        else if (opt == 3)
        {
            inOrder(root);
        }
        else
        {
            printf("\n...INCORRECT OPTION....try again...\n\n");
        }

    } while (opt != 2);

    return 0;
}