#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

typedef struct info

{

    int number;

    int count;

}info;

info list[500005];

info list1[500005];

int ary[10000] = {0,};

int compare(const void *num1, const void *num2)

{

    info* a = (info*)num1;

    info* b = (info*)num2;

    

    if (a -> number > b-> number)

    {

        return 1;

    }

    else if (a-> number < b ->number)

    {

        return -1;

    }

    else

    {

        return 0;

    }

    

}

int compare1(const void *num1, const void *num2)

{

    info *a = (info*)num1;

    info *b = (info*)num2;

    if (a -> count > b -> count)

    {

        return 1;

    }

    else if (a ->count < b ->count)

    {

        return -1;

    }

    else

    {

        if (a->number > b-> number)

        {

            return -1;

        }

        else if (a -> number < b-> number)

        {

            return 1;

        }

        else

        {

            return 0;

        }

    }

}

int main(void)

{

    int num1 = 0;

    double num2 = 0;

    scanf("%d", &num1);

    double sum = 0;

    num2 = num1;

    for (int j=0;j<num1;j++)

    {

        scanf("%d",&list[j].number);

        sum += list[j].number;

        ary[5000 + list[j].number]++;

    }

    if (sum > 0)

    {

        double average = sum / num2;

        printf("%.0lf\n", average);

    }

    else if (sum < 0)

    {

        double average1 = fabs(sum) / num2;

        if ((average1 > -1 && average1 < 0) || (average1 < 1 && average1 > 0))

        {

            printf("0\n");

        }

        else

        {

            printf("%.0lf\n", -average1);

        }

        

    }

    else

    {

        printf("0\n");

    }

    qsort(list, num1,sizeof(info) ,compare);

    printf("%d\n", list[num1 / 2].number);

    list[num1].number = 5000;

    int bound = list[num1 - 1].number - list[0].number;

    

    int index = 0;

    for (int j = 0; j < num1;j++)

    {

        list[j].count = ary[5000 + list[j].number];

        if (list[j].number != list[j+1].number)

        {

            list1[index].number = list[j].number;

            list1[index].count = list[j].count;

            index++;

        }

       // printf("%d ", list[j].count);

    }

    

    qsort(list1, index, sizeof(info),compare1);

    for (int j = 0; j < index; j++)

    {

        

       // printf("%d %d\n", list1[j].number, list1[j].count);

    }

    if (list1[index - 1].count == list1[index - 2].count)

    {

        printf("%d\n", list1[index - 2].number);

    }

    else

    {

        printf("%d\n", list1[index-1].number);

    }

    printf("%d\n", bound);

}