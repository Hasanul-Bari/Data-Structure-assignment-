/* Student id :1702065 */

#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

void viewitem(int a[],int & n);
void insertitem(int a[], int & n);
void searchitem(int a[], int & n);
void deleteitem(int a[], int & n);
void sort_ascending(int a[], int & n);
void sort_descending(int a[], int & n);
void memory_location(int a[], int & n);
void clear_screen(void);


int main()
{
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    int *arr=new int [n];
    cout<<"Enter "<<n<<" elements"<<endl;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    int x;

    do
    {
        cout<<endl<<endl<<"Menu options";
        cout<<endl<<"0.Exit";
        cout<<endl<<"1.View all elements";
        cout<<endl<<"2.Insert new element";
        cout<<endl<<"3.Search an element";
        cout<<endl<<"4.Delete an element";
        cout<<endl<<"5.Sort elements in ascending order";
        cout<<endl<<"6.Sort elements in descending order";
        cout<<endl<<"7.Find memory location of an element"<<endl;


        cout<<endl<<"Enter your option..."<<endl;

        cin>>x;

        switch(x)
        {
        case 0:
            break;
        case 1:
            viewitem(arr,n);
            break;
        case 2:
            insertitem(arr,n);
            break;
        case 3:
            searchitem(arr,n);
            break;
        case 4:
            deleteitem(arr,n);
            break;
        case 5:
            sort_ascending(arr,n);
            break;
        case 6:
            sort_descending(arr,n);
            break;
        case 7:
            memory_location(arr,n);
            break;
        default:
            cout<<endl<<"Error in input; try again"<<endl;
            clear_screen();

        }
    }while(x!=0);

    delete []arr;

    return 0;

}




void viewitem(int a[],int & n)
{
    cout<<endl<<"The array:"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    clear_screen();
}


void insertitem(int a[], int & n)
{
    int k,item;
    cout<<endl<<"Enter an element: ";
    cin>>item;
    cout<<endl<<"Enter the position you want to insert the element :";
    cin>>k;
    if(k>n+1 || k<=0)
    {
        cout<<"The position is not within the array boundary"<<endl<<endl;
    }

    else
    {
        for(int i=n; i>=k; i-- )
        {
            a[i+1]=a[i];
        }

        a[k]=item;
        n=n+1;
        cout<<"The element "<<item<<" is inserted successfully at position "<<k<<endl;
        cout<<"And the array :"<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }


    clear_screen();

}


void searchitem(int a[], int & n)
{
    int item,loc;
    cout<<"Enter the element you want to search = ";
    cin>>item;

    a[n+1]=item;

    loc=1;

    while(a[loc]!=item)
    {
        loc++;
    }

    if(loc==n+1)
    {
        cout<<"Element not found"<<endl;
    }
    else
        cout<<"The element "<<item<<" is at location "<<loc<<endl;
    clear_screen();
}


void deleteitem(int a[], int & n)
{

    int item,loc;
    cout<<"Enter the element you want to delete = ";
    cin>>item;

    a[n+1]=item;

    loc=1;

    while(a[loc]!=item)
    {
        loc++;
    }

    if(loc==n+1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        for(int i=loc; i<=n-1; i++)
            a[i]=a[i+1];
        n=n-1;
        cout<<"The element "<<item<<" is deleted successfully"<<endl;
        cout<<"And the array :"<<endl;
        for(int i=1; i<=n; i++)
            cout<<a[i]<<" ";
    }
    cout<<endl;
    clear_screen();
}


void sort_ascending(int a[], int & n)
{
    for(int i=1; i<n; i++)
        for(int j=1; j<=n-i; j++)
            if(a[j+1]<a[j])
                swap(a[j+1],a[j]);

    cout<<"The sorted array is (ascending):"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    clear_screen();
}

void sort_descending(int a[], int & n)
{
    for(int i=1; i<n; i++)
        for(int j=1; j<=n-i; j++)
            if(a[j+1]>a[j])
                swap(a[j+1],a[j]);

    cout<<"The sorted array is (descending):"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    clear_screen();
}

void memory_location(int a[], int & n)
{
    int loc,k;
    cout<<"Enter the index number(index starts from 1) of an element:";
    cin>>k;

    if(k>n || k<=0)
    {
        cout<<"The index is not within the array boundary"<<endl<<endl;
    }
    else
    {
        loc=(int)a+(sizeof(int)*(k-1));
        cout<<"The memory location of the index "<<k<<" is "<<loc<<endl<<endl;
    }

    clear_screen();

}
/* Student id :1702065 */
void clear_screen(void)
{
    cout<<endl<<endl<<"press any key to clear the screen:";
    getch();
    system("cls");
}
/* Student id :1702065 */
