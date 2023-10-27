# Dynamic Memory Allocation

Dynamic Memory Allocation is done when the size of a data structure can be changed during runtime.

In C, <stdlib.h> library provides 4 functions to facilitate dynamic memory allocation :-

    1.  malloc()
    2.  calloc()
    3.  free()
    4.  realloc()


## 1. Malloc()
   malloc =  "memory allocation"

  It is used to dynamically allocate a specific size of block.
  It returns a pointer of type void which can be cast into a pointer of any form.
  It doesn’t Initialize memory at execution time so that it has initialized each block with the **default garbage value** initially.


If space is insufficient, allocation fails and returns a **NULL** pointer.

**Syntax of malloc() in C**

    ptr = (cast-type)malloc(byte-size);

![malloc() in C](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Malloc-function-in-c.png)

**Code**
```cpp
    #include<stdio.h>
    #include<stdlib.h>

    int main()
    {
        int n;
        scanf("%d", &n);

        //dynamic allocation of an array of n integers
        int* arr = (int*)malloc(n*sizeof(int));

        if(arr==NULL)
        {
            printf("Memory Not Allocated\n");
            return 0;
        }
        // for(int i=0;i<n;i++)
        //     arr[i] = i+1;

        //if not assigned, it will print garbage values only.
        for(int i=0;i<n;i++)
            printf("%d ", arr[i]);

        printf("\n");

        free(arr);
        
        return 0;
    }
```

## 2. Calloc()
   calloc = "contiguous allocation"

It is used to dynamically allocate the specified number of blocks of memory of the specified type.

it is very much similar to malloc() but has two different points and these are:

        1.It initializes each block with a default value ‘0’.
        2.It has two parameters or arguments as compare to malloc().

**Syntax of calloc() in C**

    ptr = (cast-type*)calloc(n, element-size);
    here, n is the no. of elements and element-size is the size of each element.

If space is insufficient, allocation fails and returns a **NULL** pointer.

![calloc() in C](https://media.geeksforgeeks.org/wp-content/cdn-uploads/calloc-function-in-c.png)


**Code**
```cpp
    #include<stdio.h>
    #include<stdlib.h>

    int main()
    {
        int n;
        scanf("%d", &n);

        int *arr;
        arr = (int*)calloc(n, 4);
        
        if(arr==NULL)
        {
            printf("Memory Not Allocated\n");
            return 0;
        }
        // for (int i = 0; i < n; i++)
        //     arr[i] = i+1;

        //if not assigned, all values will be 0
        for (size_t i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        free(arr);
        return 0;
    }
```

## Free() in C

“free” method in C is used to dynamically **de-allocate** the memory.
The memory allocated using functions malloc() and calloc() is not de-allocated on their own. Hence the free() method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.

**Syntax of free() in C**

    free(ptr);

![free() in C](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Free-function-in-c.png)

## Realloc() in C

if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to **dynamically re-allocate** memory.

re-allocation of memory maintains the already present value and new blocks will be initialized with the **default garbage value**.

**Syntax of realloc() in C**

    ptr = realloc(ptr, newSize);
    where ptr is reallocated with new size 'newSize'.

If space is insufficient, allocation fails and returns a **NULL** pointer.

![realloc() in C](https://media.geeksforgeeks.org/wp-content/cdn-uploads/realloc-function-in-c.png)

**Code**
```cpp
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
```


## END
