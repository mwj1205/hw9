/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */
	printf("[----- [한민우] [2018038047] -----]\n");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)
{
	/* check pre conditions */
	if(ptr == NULL){ 
		printf("Binary search tree is empty.\n");
		return;
	}
}

void preorderTraversal(Node* ptr)
{
	/* check pre conditions */
	if(ptr == NULL){ 
		printf("Binary search tree is empty.\n");
		return;
	}
}

void postorderTraversal(Node* ptr)
{
	/* check pre conditions */
	if(ptr == NULL){ 
		printf("Binary search tree is empty.\n");
		return;
	}
}


int insert(Node* head, int key)
{
	/* check pre conditions */
	if(head == NULL){
		printf("Binary search tree is not initialized.\n");
		return 0;
	}
	
	Node* pnode = head->left;

	if(pnode == NULL){ // 트리가 공백상태면 노드 하나 바로 생성
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->key = key;
		newnode->left = newnode->right = NULL;
		head->left = newnode;
		return 0;
	}
	while(1){
		if(key < pnode->key){ // 입력받은 key가 더 작으면
			if(pnode->left == NULL){
				/* 노드 생성 */
				Node* newnode = (Node*)malloc(sizeof(Node));
				newnode->key = key;
				newnode->left = newnode->right = NULL;
				pnode->left = newnode; // 노드 삽입
				return 0;
			}
			pnode = pnode->left; // left child로 이동
		}
		else if(key > pnode->key){ // 입력받은 key가 더 크면
				if(pnode->right == NULL){
				/* 노드 생성 */
				Node* newnode = (Node*)malloc(sizeof(Node));
				newnode->key = key;
				newnode->left = newnode->right = NULL;
				pnode->right = newnode; // 노드 삽입
				return 0;
			}
			pnode = pnode->right; // right child로 이동
		}
		else if(key == pnode->key){
			printf("not allowed same key.");
			return 0;
		}
	}
}

int deleteLeafNode(Node* head, int key)
{
	/* check pre conditions */
	if(head == NULL){
		printf("Binary search tree is not initialized.\n");
		return 0;
	}
}

Node* searchRecursive(Node* ptr, int key)
{
	/* check pre conditions */
	if(ptr == NULL){ 
		return NULL;
	}
}

Node* searchIterative(Node* head, int key)
{
	/* check pre conditions */
	if(head == NULL){
		return NULL;
	}
}


int freeBST(Node* head)
{	
	/* check pre conditions */
	if(head == NULL){
		return 0;
	}
}





