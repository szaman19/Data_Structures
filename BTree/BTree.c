#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct tnode {
   struct tnode * left;
   struct tnode * right;
   int value;
};

struct tnode * makeNode(int value);
void freeTree(struct tnode * t);

void insertVal(struct tnode * t, int value);
void prLVR(struct tnode * t);
void prRVL(struct tnode * t);
void printTree(struct tnode * t, char * prefix);

int main(int argc, char **argv) {
   int i;

   if (argc<2) {
		printf("You must specify at least one argument to %s\n",argv[0]);
		return 1;
	}
	struct tnode * root=makeNode(atoi(argv[1]));
   for(i=2; i<argc; i++) {
      int val=atoi(argv[i]);
      insertVal(root,val);
   }
   printf("In LVR order: ");
   prLVR(root);
   printf("\nIn RVL order: ");
   prRVL(root);
   printf("\nGraphic Representation...\n");
   printTree(root,"");
   freeTree(root);
   return 0;
}

struct tnode * makeNode(int value) {
   struct tnode * t = malloc(sizeof(struct tnode));
   t->value=value;
   t->left=NULL;
   t->right=NULL;
   return t;
}

void freeTree(struct tnode * t) {
   assert(t);
   if (t->left) freeTree(t->left);
   if (t->right) freeTree(t->right);
   free(t);
}

void insertVal(struct tnode * t, int value) {
	assert(t);
	/* Write code to insert value into tree t here */
  if((*t).value > value){
    if((*t).left){
        insertVal((*t).left, value);
    }else{
      struct tnode *temp = makeNode(value);
      (*t).left = temp;
    }

  }else{
    if((*t).right){
      insertVal((*t).right,value);
    }else{
      struct tnode *temp = makeNode(value);
      (*t).right = temp;
    }
  }
}

void prLVR(struct tnode * t) {
	assert(t);
   /* Write code to:
   	- prLVR the left sub-tree,
   	- print the value of the node,
   	- prLVR the right sub-tree
   */

   if ((*t).left) {
     /* code */
     prLVR((*t).left);

   }
   struct tnode *temp= &(*t);
    printf("%d ",(*temp).value );
   if ((*t).right) {
     /* code */
     prLVR((*t).right);
   }

}


void prRVL(struct tnode * t) {
	assert(t);
   /* Write code to:
   	- prRVL the right sub-tree,
   	- print the value of the node,
   	- prRVL the left sub-tree
   */

   if ((*t).right) {
     /* code */
     prRVL((*t).right);

   }
   struct tnode *temp= &(*t);
    printf("%d ",(*temp).value );
   if ((*t).left) {
     /* code */
     prRVL((*t).left);
   }
}

void printTree(struct tnode * t, char * prefix) {
	assert(t);
  size_t len = strlen(prefix);
  char *str2 = malloc(len + 1 + 2 );
  strcpy(str2, prefix);
  str2[len] = '|';
  str2[len + 1]=' ';
  str2[len + 2] = '\0';

 if((*t).right){
   printTree((*t).right, str2);
  }
printf("%s%d\n",str2,(*t).value );
  if((*t).left){
    printTree((*t).left, str2);
  }
}
