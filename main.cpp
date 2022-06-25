#include <conio.h>
#include <stdio.h>
#include <memory>
#include <string.h>

struct node{
    int num;
    char name[15];
    struct node *next;
};
struct node *list;
FILE *fp;

struct node *getRecord(){
    struct node *temp,e;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Reached till here ...");
    getch();

    fflush(stdin);
    fread(&temp,sizeof(temp),1,fp);
    printf("%d %s",temp->num,temp->name);

    getch();
    temp->next = NULL;
    return temp;
}

struct node *getNode(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the person's phone number ---> ");
    scanf("%d",&temp->num);

    printf("Enter the person's name ---> ");
    scanf("%d",&temp->name);

    temp ->next = NULL;
    return temp;
    
}

struct node *search(int id, int *flag){
    struct node *cur, *prev;
    *flag = 0;

    if(list == NULL){
        return NULL;
}
    for(prev=NULL,cur=list;(cur);prev=cur,cur=cur->next){
        if(cur->num == id){
            *flag = 1;
            break;
        }
    }
    return prev;
}

int insert
