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

        int *arr;
        arr = (int*)calloc(n, 4);

        if(arr == NULL)
        {
            printf("Memory Not Allocated\n");
            return 0;
        }
        
        // for (int i = 0; i < n; i++)
        // {
        //     arr[i] = i+1;
        // }

        for (size_t i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");

        free(arr);
        
        
    }
    return 0;
}