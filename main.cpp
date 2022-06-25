#include <conio.h>
#include <stdio.h>
#include <memory>
#include <string.h>
#include <stdlib.h>

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

int insert(struct node *firstnew){
    struct node *prev;
    int flag;
    prev = search(firstnew->num, &flag);

    if(list == NULL){
        list = firstnew;
        return;
    }

    if(flag == 1){
        return -1;
    }
    else{
        firstnew->next = prev->next;
        prev->next = firstnew;
    }
    return 0;
}

void display(){
    struct node *cur;
    auto n = 0;

    if(list == NULL){
        printf("List is empty\n");
        return;
    }
    printf("The phone records are -->");
    cur = list;
    for(cur = list; (cur);cur = cur->next){
        printf("Record no. %d -->",n+1);
        printf("Record Phone no. : %d",cur->num);
        printf("Person's Name : %s",cur->name);
        n++;
    }
}

int delnode(int id){
    struct node *prev, *temp;
    int flag = 0;

    prev = search(id, &flag);

    if(list == NULL){
        return -1;
    }

    if(prev == NULL){
        temp = list;
        list = list->next;
        free(temp);
    }
    else{
        temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
    return 0;
}

struct node *query(int id, char *flag, int toggle){
    struct node *cur, *prev;
    int x=0;

    if(list == NULL){
        return NULL;
    }

    if(toggle){
        for(prev=NULL,cur=list;(cur);prev=cur,cur=cur->next){
            if(cur->num == id){
                x=1;
                break;
            }
        }
    }
    else{
        for(prev=NULL,cur=list;(cur);prev=cur,cur=cur->next){
            if(strcmp(cur->name,flag)){
                x = 1;
                break;
            }
        }
    }
    if(x==0){
        printf("This number does not exist");
        return NULL;
    }
    return cur;
}

void copyToFile(){
    FILE *fp;
    struct node *cur;
    fp = fopen("phone.txt","w");

    cur = list;
    if(cur==NULL){
        printf("The phone directory is empty, nothing to write back...");
        return;
    }
    for(cur=list;(cur);cur=cur->next)
        fprintf(fp,"%d %s",cur->num,cur->name);
    fclose(fp);
}

void main(){
    int ch=0;
    int ans=0;
    int val = 0;
    char str[15];
    struct node *firstnew, *secondnew;

    system("CLS");

    fp = fopen("phone.txt", "r");

    if(fp==NULL){
        printf("The File can't be opened!!\n");
        getch();
        exit(1);
    }

    while(!feof(fp)){
        firstnew = getRecord();

        if(insert(firstnew)==-1){
            printf("Can't insert records !!! Error!!\n");
        }
        else{
            printf("Record Entered Successfully\n");
        }
    }
    getch();
    fclose(fp);

}
