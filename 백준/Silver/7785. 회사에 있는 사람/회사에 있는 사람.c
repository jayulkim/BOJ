#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
    char name[10];
    char inout[10];
}info;



int compare(const void* num1, const void* num2)
{
    info* a = (info*)num1;
    info* b = (info*)num2;
    return strcmp(a->name, b->name);

}

int lower_bound(info* ary, int size, char* key)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int cen = (start + end) / 2;
        if (strcmp(ary[cen].name, key) >= 0)
        {
            end = cen;
        }
        else
        {
            start = cen + 1;
        }
    }
    return end;
}

int upper_bound(info* ary, int size, char* key)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int cen = (start + end) / 2;
        if (strcmp(ary[cen].name, key) > 0)
        {
            end = cen;
        }
        else
        {
            start = cen + 1;
        }
    }
    return end;
}

int main(void)
{
   

   
    int num1 = 0;
    int index = 0;
    scanf("%d", &num1);
    info* list1 = (info*)malloc(sizeof(info) * num1);
    info *list2 = (info*)malloc(sizeof(info) * 1000000);

    info* list3 = (info*)malloc(sizeof(info) * 1000000);
    int index1 = 0;
    for (int i = 0; i < num1; i++)
    {
        scanf("%s %s", list1[i].name, list1[i].inout);

    }
    qsort(list1, num1, sizeof(info), compare);
   
    
    
    for (int i = 0; i < num1 - 1; i++)
    {
        
        if (strcmp(list1[i].name, list1[i + 1].name) != 0)
        {
             strcpy(list3[index1].name, list1[i].name);
             index1++;
        }
        
    }
    strcpy(list3[index1].name, list1[num1 - 1].name);
    
    for (int i = 0; i < index1; i++)
    {
        
        int result = (upper_bound(list1, num1, list3[i].name) - lower_bound(list1, num1, list3[i].name)) % 2;
        
        if (result == 1)
        {
            strcpy(list2[index].name, list3[i].name);
            index++;
        }
    }
    int result1 = (num1 - lower_bound(list1, num1, list3[index1].name)) % 2;

    if (result1 == 1)
    {
        strcpy(list2[index].name, list3[index1].name);

        qsort(list2, index + 1, sizeof(info), compare);

        for (int i = index; i >= 0; i--)
        {
            printf("%s\n", list2[i].name);
        }
    }
    else if (result1 == 0)
    {
        qsort(list2, index, sizeof(info), compare);

        for (int i = index - 1; i >= 0; i--)
        {
            printf("%s\n", list2[i].name);
        }
    }

   
    free(list1);
    free(list2);
    free(list3);



}
