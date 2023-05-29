#include <stdio.h>
#include <math.h>

// Функція для обчислення площі трикутника за заданими координатами вершин
double Area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return 0.5 * fabs((x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1));
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    
    // Введення координат вершин першого трикутника
    printf("Введіть координати вершин першого трикутника (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // Обчислення площі першого трикутника
    double area1 = Area(x1, y1, x2, y2, x3, y3);
    
    // Введення координат вершин другого трикутника
    printf("Введіть координати вершин другого трикутника (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // Обчислення площі другого трикутника
    double area2 = Area(x1, y1, x2, y2, x3, y3);
    
    // Порівняння площ трикутників та виведення результату
    if (area1 > area2)
    {
        printf("Перший трикутник має більшу площу.\n");
    }
    else if (area2 > area1)
    {
        printf("Другий трикутник має більшу площу.\n");
    }
    else
    {
        printf("Обидва трикутники мають однакову площу.\n");
    }
    
    return 0;
}
