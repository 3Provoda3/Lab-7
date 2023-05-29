#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Функція для ініціалізації масиву випадковими числами
void initializeArray(int arr[])
{
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
}

// Функція для виведення масиву на екран
void printArray(int arr[])
{
    printf("Масив:\n");
    for (int i = 0; i < SIZE; i++)
    {
        int number = arr[i];
        if (number < 0)
        {
            printf("\x1B[35m%d\x1B[0m ", number);
        }
        else if (number > 0)
        {
            printf("\x1B[34m%d\x1B[0m ", number);
        }
        else
        {
            printf("%d ", number);
        }
    }
    printf("\n");
}

// Функція для підрахунку кількості додатних елементів масиву
int countPositiveElements(int arr[])
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > 0)
        {
            count++;
        }
    }
    return count;
}

// Функція для знаходження мінімального за модулем елемента та його індексу
void findMinAbsoluteElement(int arr[], int *minElement, int *minIndex)
{
    *minElement = abs(arr[0]);
    *minIndex = 0;

    for (int i = 1; i < SIZE; i++)
    {
        if (abs(arr[i]) < *minElement)
        {
            *minElement = abs(arr[i]);
            *minIndex = i;
        }
    }
}

// Функція для обчислення добутку елементів масиву, розташованих до мінімального за модулем елемента
int calculateProductBeforeMin(int arr[], int minIndex)
{
    int product = 1;
    for (int i = 0; i < minIndex; i++)
    {
        product *= arr[i];
    }
    return product;
}

int main()
{
    int arr[SIZE];
    initializeArray(arr);

    printArray(arr);

    int countPositive = countPositiveElements(arr);
    printf("Кількість додатних елементів: %d\n", countPositive);

    int minElement, minIndex;
    findMinAbsoluteElement(arr, &minElement, &minIndex);
    printf("Мінімальний за модулем елемент: ");
    if (arr[minIndex] < 0)
    {
        printf("\x1B[35m%d\x1B[0m\n", arr[minIndex]);
    }
    else if (arr[minIndex] > 0)
    {
        printf("\x1B[34m%d\x1B[0m\n", arr[minIndex]);
    }
    else
    {
        printf("%d\n", arr[minIndex]);
    }

    int productBeforeMin = calculateProductBeforeMin(arr, minIndex);
    printf("Добуток елементів до мінімального за модулем елемента: %d\n", productBeforeMin);

    return 0;
}
