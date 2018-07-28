/*Student id :1702065*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void viewitem(int *,int *);
void insertitem(int *, int *);
void searchitem(int *, int *);
void deleteitem(int *, int *);
void sort_ascending(int *, int *);
void sort_descending(int *, int *);
void memory_location(int *, int *);
void clear_screen(void);


int main()
{
    int size,*p,*arr,x;
    printf("Enter the size of array = ");
    scanf("%d" ,&size);


    arr=(int *)malloc(size*sizeof(int));

    if(arr==NULL)
    {
        printf("No space available\n");
        exit(1);
    }

    printf("Enter %d elements :\n",size);
    for(p=arr; p<arr+size; p++)
    {
        scanf("%d", p);
    }
    printf("\n\n");

    do
    {
        printf("\nMenu options");
        printf("\n0.Exit");
        printf("\n1.View all items");
        printf("\n2.Insert new element");
        printf("\n3.Search an element");
        printf("\n4.Delete an element");
        printf("\n5.Sort elements in ascending order");
        printf("\n6.Sort elements in descending order");
        printf("\n7.Find memory location of an element\n");


        printf("\nEnter your option...\n");

        scanf("%d",&x);

        switch(x)
        {
        case 0:
            break;
        case 1:
            viewitem(arr,&size);
            break;
        case 2:
            insertitem(arr,&size);
            break;
        case 3:
            searchitem(arr,&size);
            break;
        case 4:
            deleteitem(arr,&size);
            break;
        case 5:
            sort_ascending(arr,&size);
            break;
        case 6:
            sort_descending(arr,&size);
            break;
        case 7:
            memory_location(arr,&size);
            break;
        default:
            printf("\nError in input; try again\n");
            clear_screen();

        }
    }while(x!=0);

    free(arr);


    return 0;

}


void viewitem(int *a,int *n)
{
    int i;
    printf("\nThe array:\n");
    for(i=0; i<*n; i++)
    {
        printf("%d ",*(a+i));

    }
    printf("\n");
    clear_screen();

}


void insertitem(int *a, int *n)
{
    int k,item,i,j;
    printf("\nEnter an element: ");
    scanf("%d",&item);
    printf("\nEnter the position you want to insert the element :");
    scanf("%d",&k);

    if(k>*n+1 || k<=0)
    {
        printf("The position is not within the array boundary\n\n");
    }
    else
    {
        for(j=*n-1; j>=k-1; j-- )
        {
            *(a+(j+1))=*(a+j);
        }

        *(a+(k-1))=item;
        *n=*n+1;
        printf("The element %d is inserted successfully at position %d:\n",item,k);
        printf("And the array: \n");

        for(i=0; i<*n; i++)
        {
            printf("%d ", *(a+i));

        }
        printf("\n");
    }

    clear_screen();
}


void searchitem(int *a, int *n)
{
    int item,loc;
    printf("Enter the element you want to search = ");
    scanf("%d",&item);

    *(a+*n)=item;

    loc=1;

    while(*(a+loc)!=item)
    {
        loc++;
    }

    if(loc==*n)
    {
        printf("Not found\n");
    }
    else
        printf("The element %d is at location %d\n",item,loc+1);
    clear_screen();
}


void deleteitem(int *a, int  *n)
{

    int item,loc;
    printf("Enter the element you want to delete = ");
    scanf("%d",&item);

    *(a+*n)=item;

    loc=0;

    while(a[loc]!=item)
    {
        loc++;
    }

    if(loc==*n)
    {
        printf("Element not found\n");
    }
    else
    {
        for(int i=loc; i<*n; i++)
            *(a+i)=*(a+(i+1));
        *n=*n-1;

    printf("The element %d is deleted successfully:\n",item);
    printf("And the array: \n");

    for(int i=0; i<*n; i++)
    {
        printf("%d ",*(a+i));
    }
    }
    printf("\n");
    clear_screen();
}


void sort_ascending(int *a, int  *n)
{
    int temp,i,j;
    for( i=1; i<*n; i++)
        for( j=0; j<*n-i; j++)
            if(*(a+(j+1))<*(a+j))
            {
                temp=*(a+(j+1));
                *(a+(j+1))=*(a+j);
                *(a+j)=temp;
            }

    printf("The sorted array is (ascending):\n");
    for(int i=0; i<*n; i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
    clear_screen();
}

void sort_descending(int *a, int  *n)
{
    int temp,i,j;
    for( i=1; i<*n; i++)
        for( j=0; j<*n-i; j++)
            if(*(a+(j+1))>*(a+j))
            {
                temp=*(a+(j+1));
                *(a+(j+1))=*(a+j);
                *(a+j)=temp;
            }


    printf("The sorted array is (descending):\n");
    for(int i=0; i<*n; i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
    clear_screen();
}

void memory_location(int *a, int *n)
{
    int loc,k;
    printf("Enter the index number(index starts from 1) of an element:");
    scanf("%d",&k);

    if(k>*n || k<=0)
    {
        printf("The index is not within the array boundary\n\n");
    }
    else
    {
        loc=(int)a+(sizeof(int)*((k-1)-0));
        printf("The memory location of the index %d is %d\n\n",k,loc);
    }

    clear_screen();
}

/*Student id :1702065*/

void clear_screen(void)
{
    printf("\n\npress any key to clear the screen");
    getch();
    system("cls");
}

/*Student id :1702065*/
