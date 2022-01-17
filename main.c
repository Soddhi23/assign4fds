#include  <stdio.h> 
#include  <stdlib.h> 
#include  <string.h>

struct member
{

char  name[20]; int prn;
int roll;
struct  member  *next;
};

struct member* create()
{
int  r,p; char  n[20];
struct  member  *head;
head  =  (struct  member*)malloc(sizeof(struct  member));
printf("Enter  Name,  PRN  and  Roll  number  of  President  of  the  club\n"); scanf("%s%d%d",n,&p,&r);
strcpy(head->name,n); head->prn  =  p;
head->roll = r; head->next  =  NULL; return  head;
}

void  add(int  m,struct  member  *head)
{
int  p,r; char  n[20];
struct  member  *temp;
for(int i=0;i<m;i++)
{
temp  =  (struct  member*)malloc(sizeof(struct  member)); printf("Enter  Name,  PRN  and  Roll  number  of  the  member\n"); scanf("%s%d%d",n,&p,&r);
strcpy(temp->name,n); temp->prn  =  p;
temp->roll  =  r; head->next  =  temp; head  =  temp;
}
}

void  display(struct  member  *head)
{
printf("Name\tPRN\t\tRoll\n"); while(head != NULL)
{
printf("%s\t\t%d\t\t%d\n",head->name,head->prn,head->roll); head  =  head->next;
}
}

void  addS(struct  member  *head)
{
int  r,p; char  n[20];
struct  member  *new;
new  =  (struct  member*)malloc(sizeof(struct  member));
printf("Enter  Name,  PRN  and  Roll  number  of  Secretory  of  the  club\n"); scanf("%s%d%d",n,&p,&r);
strcpy(new->name,n); new->prn  =  p;
new->roll = r; new->next  =  NULL;
while(head->next != NULL)
{
head  =  head->next;
}
head->next  =  new;
}

struct  member*  deleteP(struct  member  *head)
{
struct  member  *p; p  =  head->next; free(head); return  p;
}
 

void  deleteS(struct  member  *head)
{
int  counter  =0;
struct  member  *p  =  head; while(head->next != NULL)
{
head  =  head->next; counter++;
}
free(head); counter-=1; while(counter--)
{
p  =  p->next;
}
p->next  =  NULL;
}

void  deleteM(struct  member  *head,int  prn)
{
struct  member  *q; while(head->prn != prn)
{
q  =  head;
head  =  head->next;
}
q->next  =  head->next; free(head);
}

int  numberM(struct  member  *head)
{
struct  member  *p  =  head; int  counter=0;
while(p->next  !=  NULL)
{
p  =  p->next; counter++;
}
return  counter;
}

void  reverse(struct  member  *head)
{
struct  member  *p  =  head;

}
 

int main()
{
int  choice,m,p; struct  member  *head; do
{
printf("Menu\n"); printf("1.Create\n"); printf("2.Add  Member\n"); printf("3.Add  Secretary\n"); printf("4.Delete  President\n"); printf("5.Delete  Secretary\n"); printf("6.Delete  Member\n"); printf("7.Display\n"); printf("8.Reverse\n"); printf("9.Exit\n"); scanf("%d",&choice);

switch(choice)
{
case  1:
head = create(); break;

case  2:
printf("Enter  number  of  members:"); scanf("%d",&m);
add(m,head); break;

case  3: addS(head); break;

case  4:
head = deleteP(head); display(head);
break;

case  5: deleteS(head); display(head); break;

case  6:
printf("Eneter PRN number of the member to be deleted: "); scanf("%d",&p);
deleteM(head,p);
display(head); break;

case  7: display(head); break;

case  9: printf("Bye!!!\n"); break;

default:
printf("Enter  valid  number\n");
}
}while(choice!=9); 
return  0;
}
