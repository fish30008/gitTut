#include <stdio.h>

// Константы для вычислений
#define PENSION_RATE 0.0135 // Накопительная ставка
#define MINIMUM_WAGE 4000   // Минимальная заработная плата
#define MIN_PENSION 2620    // Минимальная пенсия
#define FULL_STAZH_MALE_2024 34 // Полный стаж для мужчин с 1.07.2024
#define FULL_STAZH_FEMALE_2024 34 // Полный стаж для женщин с 1.07.2024
#define MIN_STAZH 15         // Минимальный стаж для пенсии
#define PENSION_AGE 60       // Пенсионный возраст для мужчин
#define PENSION_AGE_FEMALE 58 // Пенсионный возраст для женщин

// Структура для хранения информации о стаже и доходе
typedef struct {
    int years;
    int months;
} Stazh;

// Функция для вычисления размера пенсии
float calculatePension(int totalStazhYears, float vav) {
    return PENSION_RATE * totalStazhYears * vav;
}

// Функция для вычисления общего стажа в годах
float calculateTotalStazh(Stazh stazh) {
    return stazh.years + (stazh.months / 12.0);
}

int main() {
    // Ввод информации о стаже
    Stazh stazh;
    printf("Введите общий стаж (годы и месяцы через пробел): ");
    scanf("%d %d", &stazh.years, &stazh.months);

    // Ввод информации о доходе
    float vav;
    printf("Введите валоризированный среднемесячный застрахованный доход: ");
    scanf("%f", &vav);

    // Вычисление общего стажа в годах
    float totalStazhYears = calculateTotalStazh(stazh);

    // Вычисление размера пенсии
    float pension = calculatePension(totalStazhYears, vav);

    // Вывод размера пенсии
    printf("Размер пенсии составляет %.2f леев\n", pension);

    // Проверка на право на пенсию
    if (totalStazhYears >= MIN_STAZH) {
        printf("У вас есть право на пенсию.\n");
    } else {
        printf("У вас не достаточно стажа для пенсии.\n");
    }

    // Проверка на минимальный стаж для неполной пенсии
    if (totalStazhYears < MIN_STAZH) {
        float partialPension = MIN_PENSION * (totalStazhYears / MIN_STAZH);
        printf("Размер неполной пенсии составляет %.2f леев\n", partialPension);
    }

    // Проверка на пенсионный возраст
    if (stazh.years >= PENSION_AGE) {
        printf("Вы достигли пенсионного возраста.\n");
    }

    return 0;
}
