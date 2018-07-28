
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int siz;
int *arr = (int*) malloc(siz * sizeof(int));
char s[87678];//
void view()
{
    int i;
    printf("Your array is: ");
    for(i=1; i<=siz; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void newelement()
{
    int item, pos, i,*s;
    printf("Enter the ITEM to be inserted: ");
    scanf("%d",&item);
    printf("Enter position of ITEM: ");
    scanf("%d",&pos);
    for(i=siz; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    s=&siz;
    //size=&size+1;
    *s=*s+1;
    view();
}
void search()
{
    int item,loc=0,i=1;
    printf("Enter an ITEM to be searched: ");
    scanf("%d",&item);
    for(i=1; i<=siz; i++)
    {
        if(arr[i]==item)
        {
            loc=i;
            printf("%d is found in location %d\n",item,loc);
        }
    }
    if(loc==0)
    {
        printf("ITEM not found");
    }
}
void del()
{
    int x=siz;
    int item,loc=0,i=1,j,ok=0;
    printf("Enter an ITEM to be deleted: ");
    scanf("%d",&item);
    for(i=1; i<=siz; i++)
    {
        if(ok==1 && i!=1){
            i--;
            ok=0;
        }
        if(arr[i]==item)
        {
            loc=i;
            for(j=loc; j<=siz-1; j++)
            {
                arr[j]=arr[j+1];
            }
            siz--;
            ok=1;
        }
    }
    if(loc==0)
    {
        printf("ITEM not found");
    }
    else
    {
        view();
    }
}
void asort()
{
    int i,j,swap;
    for (i=1; i<=siz-1; i++)
    {
        for (j=1; j<=siz-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }

    printf("Sorted list in ascending order:\n");

    view();
}

void dsort()
{
    int i,j,swap;
    for (i=1; i<=siz-1; i++)
    {
        for (j=1; j<=siz-i; j++)
        {
            if (arr[j]<arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }

    printf("Sorted list in descending order:\n");

    view();
}

void mem()
{
    int p,i,index,ad,loc;
    p=*arr+1;
    printf("Enter the index (N.B. index 1 means first element): ");
    scanf("%d",&index);
    index--;
    if(index>siz)
    {
        printf("Index should be from 0 to size-1. So, your given index is invalid.");
    }
    else
    {
        ad=p+sizeof(int)*index;
        printf("The %dth element is allocated in location %d",index+1,ad);
    }
}
void option_fun()
{
    int option;
    printf("Enter your choice:\n1. view\n2. insert\n3. search\n4. Delete\n5. ascending sorting\n6. Descending sorting\n7. memory allocation\n");
    while(scanf("%d",&option)!=0)
    {
        if(option==1)
        {
            view();
        }
        else if(option==2)
        {
            newelement();
        }
        else if(option==3)
        {
            search();
        }
        else if(option==4)
        {
            del();
        }
        else if(option==5)
        {
            asort();
        }
        else if(option==6)
        {
            dsort();
        }
        else if(option==7)
        {
            mem();
        }
    }
}
void more()
{
    int more;
    printf("Do you want to do perform more job? if YES, enter 1; otherwise enter 0: ");
    scanf("%d",&more);
    if(more==1)
    {
        system("cls");
        option_fun();
    }
    else
        exit;
}
int main()
{
    int i,decision,num=0;
    printf("Enter array size: ");
    gets(s);
    for(i=0;i<strlen(s);i++){
        if(s[i]<='9' && s[i]>='0'){
            num=num*10+s[i]-'0';
        }
        else{
            printf("it is a character\n");
            return 0;
        }
    }
    siz=num;
        printf("Enter array elements: ");
        for(i=1; i<=siz; i++)
        {
            scanf("%d",arr+i);
        }
        printf("Dear user, you can do some jobs with your array.. if you want to see the job menu, enter 1. otherwise enter 0\n");
        scanf("%d",&decision);
        if(decision==1)
        {
            option_fun();
        }
        else
            exit;
}


