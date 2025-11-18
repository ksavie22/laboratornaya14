#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 100  // Максимальный размер массива


double calculate_value(double x) {
    return 1.8 * x * x - sin(10 * x);
}

double* full_elements(double* ptr_array, int n) {
    double start = 0.2;
    double end = 2.2;
    double step = (end - start) / (n - 1);

    printf("Заполнение массива значениями функции y = 1.8x^2 - sin(10x) на интервале [0.2; 2.2]\n");

    for (int i = 0; i < n; i++) {
        double x = start + i * step;
        ptr_array[i] = calculate_value(x);
    }
    return ptr_array;
}


int put_elements(double* ptr_array, int n) {
    printf("\nСодержимое массива (%d элементов):\n", n);
    printf("+--------+-----------+\n");
    printf("| Индекс |  Значение |\n");
    printf("+--------+-----------+\n");

    for (int i = 0; i < n; i++) {
        printf("| %6d | %9.3f |\n", i, ptr_array[i]);
    }
    printf("+--------+-----------+\n");
    return n;
}


double* calc_elements(double* ptr_array, int n) {
    int negative_count = 0;

    printf("\nОбработка массива\n");
   

    // Обнул отриц
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < 0) {
            negative_count++;
            ptr_array[i] = 0.0;
        }
    }

    printf("Обнулено отрицательных элементов: %d\n", negative_count);
    return ptr_array;
}

int main() {
    setlocale(LC_CTYPE, "RUS");
   
    double array[N];
    int size;

    
    printf("Введите размер массива (1 - %d) > ", N);
    scanf("%d", &size);

 
    if (size <= 0 || size > N) {
        printf("Ошибка: размер массива должен быть от 1 до %d\n", N);
        return 1;
    }

  
    printf("\n заполнение массива\n");
    full_elements(array, size);

    printf("\n исходный массив \n");
    put_elements(array, size);

    // Обр элем
    calc_elements(array, size);

    printf("\n массив после обработки \n");
    put_elements(array, size);

    return 0;
}