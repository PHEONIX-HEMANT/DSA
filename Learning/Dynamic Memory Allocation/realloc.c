#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    //dynamic allocation of an array of n integers
    int* arr = (int*)malloc(n*sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Not Allocated\n");
        return 0;
    }

    for(int i=0;i<n;i++)
        arr[i] = i+1;

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    printf("\nChanging the size to : ");
    int newsize;
    scanf("%d", &newsize);

    //reallocation to the new size
    arr = realloc(arr, newsize*sizeof(int));
    
    if(arr == NULL)
    {
        printf("Memory Not Allocated\n");
        return 0;
    }

    printf("After Changing the size:");
    for(int i=0;i<newsize;i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}