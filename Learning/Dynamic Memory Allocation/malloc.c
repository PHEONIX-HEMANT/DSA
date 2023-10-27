#include<stdio.h>
#include<stdlib.h>

int main()
{

    int t;
    scanf("%d", &t);

    while(t--)
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

        // for(int i=0;i<n;i++)
        //     arr[i] = i+1;

        for(int i=0;i<n;i++)
            printf("%d ", arr[i]);

        printf("\n");

        free(arr);
    }
    
    return 0;
}