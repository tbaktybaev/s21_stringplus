#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_sprintf.h"
#include "s21_string.h"

START_TEST(s21_trim_test_1) {
  char test_str_1[50] = "hello world"; /* Инициализация тестовых данных*/
  char test_trim_set_1[50] = "dh";
  char *trim_result_1 = (char *)(s21_trim(
      test_str_1, test_trim_set_1)); /*Вызов тестируемой функции*/
  ck_assert_str_eq("ello worl", trim_result_1); /* Проверка результата*/
  if (trim_result_1)
    free(trim_result_1); /* Освобождение памяти, если необходимо*/
}
END_TEST

START_TEST(s21_trim_test_2) {
  char test_str_2[50] = "123abc456xyz789";
  char test_trim_set_2[50] = "123456789";
  char *trim_result_2 = (char *)(s21_trim(test_str_2, test_trim_set_2));
  ck_assert_str_eq("abc456xyz", trim_result_2);
  if (trim_result_2) free(trim_result_2);
}
END_TEST

START_TEST(s21_trim_test_3) {
  char test_str_3[50] = "---abc---xyz----";
  char test_trim_set_3[50] = "-";
  char *trim_result_3 = (char *)(s21_trim(test_str_3, test_trim_set_3));
  ck_assert_str_eq("abc---xyz", trim_result_3);
  if (trim_result_3) free(trim_result_3);
}
END_TEST

START_TEST(s21_trim_test_4) {
  char test_str_4[50] = "*** Much Ado About Nothing ***";
  char test_trim_set_4[50] = "*?/ ";
  char *trim_result_4 = (char *)(s21_trim(test_str_4, test_trim_set_4));
  ck_assert_str_eq("Much Ado About Nothing", trim_result_4);
  if (trim_result_4) free(trim_result_4);
}
END_TEST

START_TEST(s21_trim_test_5) {
  char test_str_5[50] = "hello world";
  char test_trim_set_5[50] = "dh--";
  char *trim_result_5 = (char *)(s21_trim(test_str_5, test_trim_set_5));
  ck_assert_str_eq("ello worl", trim_result_5);
  if (trim_result_5) free(trim_result_5);
}
END_TEST

START_TEST(s21_trim_test_6) {
  char test_str_6[50] = "123abc456xyz789";
  char test_trim_set_6[50] = "12345678900000";
  char *trim_result_6 = (char *)(s21_trim(test_str_6, test_trim_set_6));
  ck_assert_str_eq("abc456xyz", trim_result_6);
  if (trim_result_6) free(trim_result_6);
}
END_TEST

START_TEST(s21_trim_test_7) {
  char test_str_7[50] = "---abc---xyz----";
  char test_trim_set_7[50] = "-?";
  char *trim_result_7 = (char *)(s21_trim(test_str_7, test_trim_set_7));
  ck_assert_str_eq("abc---xyz", trim_result_7);
  if (trim_result_7) free(trim_result_7);
}
END_TEST

START_TEST(s21_trim_test_8) {
  char test_str_8[50] = "*** Much Ado About Nothing ***";
  char test_trim_set_8[50] = "*_?/ ";
  char *trim_result_8 = (char *)(s21_trim(test_str_8, test_trim_set_8));
  ck_assert_str_eq("Much Ado About Nothing", trim_result_8);
  if (trim_result_8) free(trim_result_8);
}
END_TEST

START_TEST(s21_trim_test_9) {
  char test_str_9[50] = "hello world";
  char test_trim_set_9[50] = "--";
  char *trim_result_9 = (char *)(s21_trim(test_str_9, test_trim_set_9));
  ck_assert_str_eq("hello world", trim_result_9);
  if (trim_result_9) free(trim_result_9);
}
END_TEST

START_TEST(s21_trim_test_10) {
  char test_str_10[50] = "123abc456xyz789";
  char test_trim_set_10[50] = "0";
  char *trim_result_10 = (char *)(s21_trim(test_str_10, test_trim_set_10));
  ck_assert_str_eq("123abc456xyz789", trim_result_10);
  if (trim_result_10) free(trim_result_10);
}
END_TEST

START_TEST(s21_trim_test_11) {
  char test_str_11[50] = "";
  char test_trim_set_11[50] = "abc";
  char *trim_result_11 = (char *)(s21_trim(test_str_11, test_trim_set_11));
  ck_assert_str_eq("", trim_result_11);
  if (trim_result_11) free(trim_result_11);
}
END_TEST

START_TEST(s21_trim_test_12) {
  char test_str_12[50] = "";
  char test_trim_set_12[50] = "";
  char *trim_result_12 = (char *)(s21_trim(test_str_12, test_trim_set_12));
  ck_assert_str_eq("", trim_result_12);
  if (trim_result_12) free(trim_result_12);
}
END_TEST

START_TEST(s21_to_lower_test_1) {
  char test_str_1[64] = "123abc456xyz789"; /*Инициализируются тестовые данные*/
  char *lower_result_1 = (char *)(s21_to_lower(
      test_str_1)); /*Вызывается функция s21_to_lower() с передачей тестовой
                       строки в качестве аргумента. Результат сохраняется в
                       переменной lower_result_1.*/
  ck_assert_str_eq(
      "123abc456xyz789",
      lower_result_1); /*Проверяется, соответствует ли значение lower_result_1
                          ожидаемому результату "123abc456xyz789".*/
  if (lower_result_1)
    free(lower_result_1); /*Освобождается динамически выделенная память, если
                             была выделена.*/
}
END_TEST

START_TEST(s21_to_upper_test_1) {
  char test_str_1[64] = "123abc456xyz789"; /*Инициализируются тестовые данные:*/
  char *upper_result_1 = (char *)(s21_to_upper(
      test_str_1)); /*Вызывается функция s21_to_upper() с передачей тестовой
                       строки в качестве аргумента. Результат сохраняется в
                       переменной upper_result_1.*/
  ck_assert_str_eq(
      "123ABC456XYZ789",
      upper_result_1); /*Проверяется, соответствует ли значение upper_result_1
                          ожидаемому результату "123ABC456XYZ789".*/
  if (upper_result_1)
    free(upper_result_1); /*Освобождается динамически выделенная память, если
                             была выделена.*/
}
END_TEST

START_TEST(s21_to_lower_test_2) {
  char test_str_2[64] = "*** Much Ado About Nothing ***";
  char *lower_result_2 = (char *)(s21_to_lower(test_str_2));
  ck_assert_str_eq("*** much ado about nothing ***", lower_result_2);
  if (lower_result_2) free(lower_result_2);
}
END_TEST

START_TEST(s21_to_upper_test_2) {
  char test_str_2[64] = "*** Much Ado About Nothing ***";
  char *upper_result_2 = (char *)(s21_to_upper(test_str_2));
  ck_assert_str_eq("*** MUCH ADO ABOUT NOTHING ***", upper_result_2);
  if (upper_result_2) free(upper_result_2);
}
END_TEST

START_TEST(s21_to_lower_test_3) {
  char test_str_3[64] = "--";
  char *lower_result_3 = (char *)(s21_to_lower(test_str_3));
  ck_assert_str_eq("--", lower_result_3);
  if (lower_result_3) free(lower_result_3);
}
END_TEST

START_TEST(s21_to_upper_test_3) {
  char test_str_3[64] = "--";
  char *upper_result_3 = (char *)(s21_to_upper(test_str_3));
  ck_assert_str_eq("--", upper_result_3);
  if (upper_result_3) free(upper_result_3);
}
END_TEST

START_TEST(s21_to_lower_test_4) {
  char test_str_4[64] = "";
  char *lowt_4 = (char *)(s21_to_lower(test_str_4));
  ck_assert_str_eq("", lowt_4);
  if (lowt_4) free(lowt_4);
}
END_TEST

START_TEST(s21_to_upper_test_4) {
  char test_str_4[64] = "";
  char *upper_result_4 = (char *)(s21_to_upper(test_str_4));
  ck_assert_str_eq("", upper_result_4);
  if (upper_result_4) free(upper_result_4);
}
END_TEST

START_TEST(s21_to_lower_test_5) {
  char test_str_5[64] = "hello world";
  char *lower_result_5 = (char *)(s21_to_lower(test_str_5));
  ck_assert_str_eq("hello world", lower_result_5);
  if (lower_result_5) free(lower_result_5);
}
END_TEST

START_TEST(s21_to_upper_test_5) {
  char test_str_5[64] = "hello world";
  char *upper_result_5 = (char *)(s21_to_upper(test_str_5));
  ck_assert_str_eq("HELLO WORLD", upper_result_5);
  if (upper_result_5) free(upper_result_5);
}
END_TEST

START_TEST(s21_to_lower_test_6) {
  char test_str_6[64] = "HELLO, 21SCHOOL";
  char *lower_result_6 = (char *)(s21_to_lower(test_str_6));
  ck_assert_str_eq("hello, 21school", lower_result_6);
  if (lower_result_6) free(lower_result_6);
}
END_TEST

START_TEST(s21_to_upper_test_6) {
  char test_str_6[64] = "HELLO, 21SCHOOL";
  char *upper_result_6 = (char *)(s21_to_upper(test_str_6));
  ck_assert_str_eq("HELLO, 21SCHOOL", upper_result_6);
  if (upper_result_6) free(upper_result_6);
}
END_TEST

START_TEST(s21_to_lower_test_7) {
  char test_str_7[64] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
  char *lower_result_7 = (char *)(s21_to_lower(test_str_7));
  ck_assert_str_eq("lorem ipsum dolor sit amet, consectetur adipiscing elit",
                   lower_result_7);
  if (lower_result_7) free(lower_result_7);
}
END_TEST

START_TEST(s21_to_upper_test_7) {
  char test_str_7[64] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
  char *upper_result_7 = (char *)(s21_to_upper(test_str_7));
  ck_assert_str_eq("LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT",
                   upper_result_7);
  if (upper_result_7) free(upper_result_7);
}
END_TEST

START_TEST(s21_to_lower_test_8) {
  char test_str_8[64] = "---abc---xyz----";
  char *lower_result_8 = (char *)(s21_to_lower(test_str_8));
  ck_assert_str_eq("---abc---xyz----", lower_result_8);
  if (lower_result_8) free(lower_result_8);
}
END_TEST

START_TEST(s21_to_upper_test_8) {
  char test_str_8[64] = "---abc---xyz----";
  char *upper_result_8 = (char *)(s21_to_upper(test_str_8));
  ck_assert_str_eq("---ABC---XYZ----", upper_result_8);
  if (upper_result_8) free(upper_result_8);
}
END_TEST

START_TEST(s21_to_lower_test_9) {
  char test_str_9[64] = "&&&&&&&";
  char *lower_result_9 = (char *)(s21_to_lower(test_str_9));
  ck_assert_str_eq("&&&&&&&", lower_result_9);
  if (lower_result_9) free(lower_result_9);
}
END_TEST

START_TEST(s21_to_upper_test_9) {
  char test_str_9[64] = "&&&&&&&";
  char *upper_result_9 = (char *)(s21_to_upper(test_str_9));
  ck_assert_str_eq("&&&&&&&", upper_result_9);
  if (upper_result_9) free(upper_result_9);
}
END_TEST

START_TEST(
    s21_insert_test_1) {  // проверяет, что строка test_insertion_1 успешно
                          //   вставляется в строку test_str_1 на позицию 0.
  char test_str_1[50] = "123abc456xyz789";
  char test_insertion_1[50] = "0";
  char *insert_result_1 = (char *)(s21_insert(
      test_str_1, test_insertion_1,
      0));  //мы вызываем функцию s21_insert с аргументами test_str_1,
            //   test_insertion_1 и 0 (позиция, в которую мы хотим вставить
            //   строку test_insertion_1). Результат вставки сохраняем в
            //   указатель на массив символов insert_result_1
  ck_assert_str_eq(
      "0123abc456xyz789",
      insert_result_1);  //сравниваем строку insert_result_1 с ожидаемым
                         //   результатом "0123abc456xyz789". Если строки
                         //   совпадают, тест считается пройденным.
  if (insert_result_1)
    free(insert_result_1);  //свобождаем память, выделенную для insert_result_1,
                            //   чтобы избежать утечек памяти.
}
END_TEST

START_TEST(s21_insert_test_2) {
  char test_str_2[50] = "I Groot";
  char test_insertion_2[50] = "am ";
  char *insert_result_2 = (char *)(s21_insert(test_str_2, test_insertion_2, 2));
  ck_assert_str_eq("I am Groot", insert_result_2);
  if (insert_result_2) free(insert_result_2);
}
END_TEST

START_TEST(s21_insert_test_3) {
  char test_str_3[50] = "--";
  char test_insertion_3[50] = "";
  char *insert_result_3 = (char *)(s21_insert(test_str_3, test_insertion_3, 1));
  ck_assert_str_eq("--", insert_result_3);
  if (insert_result_3) free(insert_result_3);
}
END_TEST

START_TEST(s21_insert_test_4) {
  char test_str_4[50] = "";
  char test_insertion_4[50] = "aboba";
  char *insert_result_4 = (char *)(s21_insert(test_str_4, test_insertion_4, 0));
  ck_assert_str_eq("aboba", insert_result_4);
  if (insert_result_4) free(insert_result_4);
}
END_TEST

START_TEST(s21_insert_test_5) {
  char test_str_5[50] = "hello, !!!";
  char test_insertion_5[50] = "world";
  char *insert_result_5 = (char *)(s21_insert(test_str_5, test_insertion_5, 7));
  ck_assert_str_eq("hello, world!!!", insert_result_5);
  if (insert_result_5) free(insert_result_5);
}
END_TEST

START_TEST(s21_insert_test_6) {
  char test_str_6[50] = "HELLO, 21SCHOOL";
  char test_insertion_6[50] = "!!!";
  char *insert_result_6 =
      (char *)(s21_insert(test_str_6, test_insertion_6, 15));
  ck_assert_str_eq("HELLO, 21SCHOOL!!!", insert_result_6);
  if (insert_result_6) free(insert_result_6);
}
END_TEST

START_TEST(s21_insert_test_7) {
  char test_str_7[50] = "I Groot";
  char test_insertion_7[50] = "am ";
  char *insert_result_7 =
      (char *)(s21_insert(test_str_7, test_insertion_7, 20));
  ck_assert_ptr_null(insert_result_7);
  if (insert_result_7) free(insert_result_7);
}
END_TEST

START_TEST(memchr_1) {  //проверяет, что функция s21_memchr возвращает ожидаемый
                        //   результат при поиске символа 'A' в строке test1,
                        //   ограниченной первыми 11 символами.
  char *test1 =
      "Alla Halla Cat Dog";  //Создается указатель test1, который указывает на
                             //   строку "Alla Halla Cat Dog".

  ck_assert_ptr_eq(s21_memchr(test1, 'A', 11), memchr(test1, 'A', 11));  //С
  //помощью функции s21_memchr вызывается реализация функции memchr из
  //библиотеки s21. Первый аргумент - указатель test1 на строку для поиска,
  // второй аргумент - символ 'A', третий аргумент - число 11, ограничивающее
  //поиск на 11 символов. С помощью функции memchr из стандартной библиотеки
  //вызывается оригинальная функция memchr. Первый аргумент - указатель test1 на
  // строку для поиска, второй аргумент
  //- символ 'A', третий аргумент - число 11, ограничивающее поиск на 11
  //символов. сравнивает указатели, возвращаемые функциями s21_memchr и memchr.
  //Если они
  // равны, то тест считается пройденным, иначе - проваленным.
}
END_TEST

START_TEST(memchr_2) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'a', 8), memchr(test1, 'a', 8));
}
END_TEST

START_TEST(memchr_3) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'l', 11), memchr(test1, 'l', 11));
}
END_TEST

START_TEST(memchr_4) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_memchr(test2, 'W', 11), memchr(test2, 'W', 11));
}
END_TEST

START_TEST(memchr_5) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'A', 1), memchr(test1, 'A', 1));
}
END_TEST

START_TEST(memchr_6) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_memchr(test3, '5', 6), memchr(test3, '5', 6));
}
END_TEST

START_TEST(memchr_7) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, '2', 6), memchr(test1, '2', 6));
}
END_TEST

START_TEST(memchr_8) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_memchr(test3, '1', 1), memchr(test3, '1', 1));
}
END_TEST

START_TEST(memchr_9) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, '4', 6), memchr(test1, '4', 6));
}
END_TEST

START_TEST(memchr_10) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, '6', 6), memchr(test1, '6', 6));
}
END_TEST

START_TEST(
    memcmp_1) {  //данный тест проверяет, что обе функции s21_memcmp и memcmp
                 //   возвращают одинаковый результат сравнения для первых 11
                 //   символов строк test1 и test2. Если результаты не
                 //   совпадают, то тест будет считаться неудачным.
  char *test1 =
      "Alla Halla Cat Dog";  //объявляются и инициализируются две
                             //   переменные типа char*, test1 и test2,
                             //   которые содержат две разные строки.
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(
      s21_memcmp(test1, test2, 11) > 0,
      memcmp(test1, test2, 11) >
          0);  //выполняет сравнение результатов работы функций s21_memcmp и
               //   memcmp для первых 11 символов строк test1 и test2. Функция
               //   s21_memcmp сравнивает строки лексикографически и возвращает
               //   0, если строки равны, положительное число, если первая
               //   строка больше второй, и отрицательное число, если первая
               //   строка меньше второй. Функция memcmp выполняет байтовое
               //   сравнение строк и возвращает 0, если строки идентичны,
               //   отрицательное число, если первая строка меньше второй, и
               //   положительное число, если первая строка больше второй.
}
END_TEST

START_TEST(memcmp_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 11) > 0,
                    memcmp(test1, test2, 11) > 0);
}
END_TEST

START_TEST(memcmp_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 5) == 0,
                    memcmp(test1, test2, 5) == 0);
}
END_TEST

START_TEST(memcmp_4) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_memcmp(test3, test2, 2) < 0,
                    memcmp(test3, test2, 2) < 0);
}
END_TEST

START_TEST(memcmp_5) {
  int test4[] = {1, 2, 3, 4, 5};
  int test5[] = {1, 2, 3, 4, 6};
  ck_assert_uint_eq(s21_memcmp(test4, test5, 4) == 0,
                    memcmp(test4, test5, 4) == 0);
}
END_TEST

START_TEST(memcmp_6) {
  int test4[] = {1, 2, 3, 4, 5};
  int test5[] = {1, 2, 3, 4, 6};
  ck_assert_uint_eq(s21_memcmp(test4, test5, 3) < 0,
                    memcmp(test4, test5, 3) < 0);
}
END_TEST

START_TEST(memcmp_7) {
  char test7[] = "goga\0 job";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_memcmp(test7, test8, 2) == 0,
                    memcmp(test7, test8, 2) == 0);
}
END_TEST

START_TEST(memcmp_9) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test8, 3) < 0,
                    memcmp(test1, test8, 3) < 0);
}
END_TEST

START_TEST(memcmp_10) {
  char *test1 = "Alla Halla Cat Dog";
  ck_assert_uint_eq(s21_memcmp(test1, test1, 5) < 0,
                    memcmp(test1, test1, 5) < 0);
}
END_TEST

START_TEST(memcpy_1) {  //тест проверяет, что обе функции s21_memcpy и memcpy
                        //   правильно копируют первый символ строки test2 в
                        //   массив test0. Если результаты работы функций не
                        //   совпадают, то тест будет считаться неудачным.
  char *test2 =
      "Alla Halla Alla Walla";  //объявляются и инициализируются две переменные:
                                //   test2, которая является указателем на
                                //   строку
                                ///   "Alla Halla Alla Walla", и test0, которая
                                //  является массивом размером 10 элементов.
  char *test0[10];
  ck_assert_str_eq(
      s21_memcpy(test0, test2, 1),
      memcpy(test0, test2,
             1));  //выполняет сравнение результатов работы функций s21_memcpy и
                   //   memcpy для копирования первого символа из строки test2 в
                   //   массив test0. Функция s21_memcpy копирует указанное
                   //   количество байт из исходного массива в целевой массив,
                   //   возвращает указатель на целевой массив и изменяет его
                   //   содержимое. Функция memcpy выполняет аналогичную
                   //   операцию и возвращает указатель на целевой массив.
                   //   Функция ck_assert_str_eq сравнивает строки между собой.
}
END_TEST

START_TEST(memcpy_2) {
  char *test2 = "Alla Halla Alla Walla";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test2, 10), memcpy(test0, test2, 10));
}
END_TEST

START_TEST(memcpy_3) {
  char *test2 = "Alla Halla Alla Walla";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test2, 11), memcpy(test0, test2, 11));
}
END_TEST

START_TEST(memcpy_4) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test1, 6), memcpy(test0, test1, 6));
}
END_TEST

START_TEST(memcpy_5) {
  char *test3 = "123455";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test3, 2), memcpy(test0, test3, 2));
}
END_TEST

START_TEST(memcpy_6) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memcpy(test01, test3, 4), memcpy(test01, test3, 4));
}
END_TEST

START_TEST(memcpy_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memcpy(test01, test1, 11), memcpy(test01, test1, 11));
}
END_TEST

START_TEST(memcpy_8) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memcpy(test01, test1, 10), memcpy(test01, test1, 10));
}
END_TEST

START_TEST(
    memset_1) {  //данный тест проверяет, что обе функции s21_memset и
                 //   memset правильно устанавливают символ 'a' в первый
                 //   элемент массива test0. Если результаты работы функций
                 //   не совпадают, то тест будет считаться неудачным.
  char *test0[10];  //объявляется массив test0 размером 10 элементов
  ck_assert_str_eq(
      s21_memset(test0, 'a', 1),
      memset(
          test0, 'a',
          1));  //выполняет сравнение результатов работы функций s21_memset и
                //   memset для установки символа 'a' в первый элемент массива
                //   test0. Функция s21_memset устанавливает указанный символ в
                //   указанное количество байт в целевом массиве, возвращает
                //   указатель на целевой массив и изменяет его содержимое.
                //   Функция memset выполняет аналогичную операцию и возвращает
                //  указатель на целевой массив. Функция ck_assert_str_eq
                // сравнивает строки между собой.
}
END_TEST

START_TEST(memset_2) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 8), memset(test0, 'a', 8));
}
END_TEST

START_TEST(memset_3) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 7), memset(test0, 'a', 7));
}
END_TEST

START_TEST(memset_4) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 5), memset(test0, 'a', 5));
}
END_TEST

START_TEST(memset_5) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 1, 0), memset(test0, 1, 0));
}
END_TEST

START_TEST(memset_6) {
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memset(test01, 1, 0), memset(test01, 1, 0));
}
END_TEST

START_TEST(memset_7) {
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memset(test01, 1, 7), memset(test01, 1, 7));
}
END_TEST

START_TEST(memset_8) {
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memset(test01, 'a', 11), memset(test01, 'a', 11));
}
END_TEST

START_TEST(
    strncat_1) { /*данный тест проверяет, что обе функции s21_strncat и strncat
                    правильно объединяют строки test01 и test2, добавляя только
                    один символ из test2. Если результаты работы функций не
                    совпадают, то тест будет считаться неудачным*/
  char *test2 =
      "Alla Halla Alla Walla"; /*объявляются переменные test2 и test01. test2
                                  инициализируется строкой "Alla Halla Alla
                                  Walla", а test01 инициализируется строкой
                                  "Alla Halla Cat Dog".*/
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(
      s21_strncat(test01, test2, 1),
      strncat(test01, test2,
              1)); /*выполняет сравнение результатов работы функций s21_strncat
                      и strncat для объединения строк test01 и test2 с
                      ограничением на количество символов, добавляемых из test2.
                      Функция s21_strncat добавляет указанное количество
                      символов из строки test2 в конец строки test01 и
                      возвращает указатель на test01. Функция strncat выполняет
                      аналогичное действие и возвращает указатель на test01.
                      Функция ck_assert_str_eq сравнивает строки между собой.*/
}
END_TEST

START_TEST(strncat_2) {
  char *test2 = "Alla Halla Alla Walla";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test2, 10), strncat(test01, test2, 10));
}
END_TEST

START_TEST(strncat_3) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test3, 1), strncat(test01, test3, 1));
}
END_TEST

START_TEST(strncat_4) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test3, 0), strncat(test01, test3, 0));
}
END_TEST

START_TEST(strncat_5) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test3, 10), strncat(test01, test3, 10));
}
END_TEST

START_TEST(strchr_1) { /*данный тест проверяет, что обе функции s21_strchr и
                          strchr правильно находят первое вхождение символа 'A'
                          в строке test1. Если результаты работы функций не
                          совпадают, то тест будет считаться неудачным.*/
  char *test1 =
      "Alla Halla Cat Dog"; /*объявляется переменная test1 и инициализируется
                               строкой "Alla Halla Cat Dog".*/

  ck_assert_ptr_eq(
      s21_strchr(test1, 'A'),
      strchr(test1,
             'A')); /*выполняет сравнение результатов работы функций s21_strchr
                       и strchr. Функция s21_strchr ищет первое вхождение
                       символа 'A' в строке test1 и возвращает указатель на
                       найденный символ или NULL, если символ не найден. Функция
                       strchr выполняет аналогичное действие и возвращает
                       указатель на найденный символ или NULL. Функция
                       ck_assert_ptr_eq сравнивает указатели между собой.*/
}
END_TEST

START_TEST(strchr_2) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, 'a'), strchr(test1, 'a'));
}
END_TEST

START_TEST(strchr_3) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, 'l'), strchr(test1, 'l'));
}
END_TEST

START_TEST(strchr_4) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strchr(test2, 'W'), strchr(test2, 'W'));
}
END_TEST

START_TEST(strchr_5) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, 'A'), strchr(test1, 'A'));
}
END_TEST

START_TEST(strchr_6) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strchr(test3, '5'), strchr(test3, '5'));
}
END_TEST

START_TEST(strchr_7) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, '2'), strchr(test1, '2'));
}
END_TEST

START_TEST(strchr_8) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strchr(test3, '1'), strchr(test3, '1'));
}
END_TEST

START_TEST(strchr_9) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, '4'), strchr(test1, '4'));
}
END_TEST

START_TEST(strchr_10) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, '6'), strchr(test1, '6'));
}
END_TEST

START_TEST(strncmp_1) { /*данный тест проверяет, что обе функции s21_strncmp и
                           strncmp правильно сравнивают первые 2 символа строк
                           test1 и test2. Если результаты работы функций не
                           совпадают, то тест будет считаться неудачным.*/
  char *test1 =
      "Alla Halla Cat Dog"; /*объявляются две переменные test1 и test2 и
                               инициализируются строками "Alla Halla Cat Dog" и
                               "Alla Halla Alla Walla" соответственно.*/
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(
      s21_strncmp(test1, test2, 2),
      strncmp(test1, test2,
              2)); /* выполняет сравнение результатов работы функций s21_strncmp
                      и strncmp. Функция s21_strncmp сравнивает первые 2 символа
                      строки test1 с первыми 2 символами строки test2 и
                      возвращает результат сравнения (0, если строки равны,
                      отрицательное значение, если первая строка меньше по
                      алфавиту, положительное значение, если первая строка
                      больше по алфавиту). Функция strncmp выполняет аналогичное
                      действие и возвращает результат сравнения.*/
}
END_TEST

START_TEST(strncmp_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 11), strncmp(test1, test2, 11));
}
END_TEST

START_TEST(strncmp_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 14), strncmp(test1, test2, 14));
}
END_TEST

START_TEST(strncmp_4) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 18), strncmp(test1, test2, 18));
}
END_TEST

START_TEST(strncmp_5) {
  char test7[] = "goga\0 job";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strncmp(test7, test8, 9), strncmp(test7, test8, 9));
}
END_TEST

START_TEST(strncmp_6) {
  char test6[] = "\0";
  char test7[] = "goga\0 job";
  ck_assert_uint_eq(s21_strncmp(test6, test7, 1), strncmp(test6, test7, 1));
}
END_TEST

START_TEST(strncmp_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strncmp(test1, test8, 5), strncmp(test1, test8, 5));
}
END_TEST

START_TEST(strncpy_1) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test3, 10), strncpy(test01, test3, 10));
}
END_TEST

START_TEST(strncpy_2) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 11), strncpy(test01, test1, 11));
}
END_TEST

START_TEST(strncpy_3) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 100),
                   strncpy(test01, test1, 100));
}
END_TEST

START_TEST(strncpy_4) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test3, 4), strncpy(test01, test3, 4));
}
END_TEST

START_TEST(strncpy_5) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 2), strncpy(test01, test1, 2));
}
END_TEST

START_TEST(strncpy_6) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 1), strncpy(test01, test1, 1));
}
END_TEST

START_TEST(strncpy_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 0), strncpy(test01, test1, 0));
}
END_TEST

START_TEST(
    strcspn_1) {  //данный тест проверяет, что функции s21_strcspn и strcspn
                  //   правильно возвращают количество символов из строки test1,
                  //   которое не содержится в строке test2. Если результаты
                  //   работы функций не совпадают, то тест будет считаться
                  //   неудачным
  char *test1 =
      "Alla Halla Cat Dog";  //объявляются две переменные test1 и test2 и
                             //   инициализируются строками "Alla Halla Cat Dog"
                             //   и "Alla Halla Alla Walla" соответственно. Обе
                             //   переменные являются указателями на строку.
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(
      s21_strcspn(test1, test2),
      strcspn(
          test1,
          test2));  //выполняет сравнение результатов работы функций s21_strcspn
                    //   и strcspn. Функция s21_strcspn возвращает количество
                    //   символов из строки test1, которое не содержится в
                    //   строке test2. Функция strcspn выполняет аналогичное
                    //   действие. ck_assert_uint_eq проверяет, что оба
                    //   результаты равны
}
END_TEST

START_TEST(strcspn_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strcspn(test2, test1), strcspn(test2, test1));
}
END_TEST

START_TEST(strcspn_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strcspn(test1, test3), strcspn(test1, test3));
}
END_TEST

START_TEST(strcspn_4) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strcspn(test3, test2), strcspn(test3, test2));
}
END_TEST

START_TEST(strcspn_5) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strcspn(test2, test3), strcspn(test2, test3));
}
END_TEST

START_TEST(strcspn_6) {
  char test6[] = "\0";
  char test7[] = "goga\0 job";
  ck_assert_uint_eq(s21_strcspn(test6, test7), strcspn(test6, test7));
}
END_TEST

START_TEST(strcspn_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strcspn(test1, test8), strcspn(test1, test8));
}
END_TEST

START_TEST(strerror_1) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
} /*сравнивает строки, возвращаемые функциями s21_strerror и strerror, при
     аргументе 0. Функция s21_strerror возвращает строку, описывающую ошибку по
     переданному числовому коду ошибки. Функция strerror выполняет аналогичное
     действие. ck_assert_str_eq проверяет, что обе строки равны.*/
END_TEST

START_TEST(strerror_2) { ck_assert_str_eq(s21_strerror(2000), strerror(2000)); }
END_TEST

START_TEST(strerror_3) { ck_assert_str_eq(s21_strerror(10), strerror(10)); }
END_TEST

START_TEST(strerror_4) { ck_assert_str_eq(s21_strerror(-20), strerror(-20)); }
END_TEST

START_TEST(strerror_5) { ck_assert_str_eq(s21_strerror(5), strerror(5)); }
END_TEST

START_TEST(strerror_6) { ck_assert_str_eq(s21_strerror(105), strerror(105)); }
END_TEST

START_TEST(strerror_7) {
  ck_assert_str_eq(s21_strerror(-2005), strerror(-2005));
}
END_TEST

START_TEST(strerror_8) { ck_assert_str_eq(s21_strerror(56), strerror(56)); }
END_TEST

START_TEST(strerror_9) { ck_assert_str_eq(s21_strerror(44), strerror(44)); }
END_TEST

START_TEST(strerror_10) { ck_assert_str_eq(s21_strerror(76), strerror(76)); }
END_TEST

START_TEST(strlen_1) {
  char *test1 =
      "Alla Halla Cat Dog"; /*объявляется переменная test1 и инициализируется
                               строкой "Alla Halla Cat Dog". Переменная test1
                               является указателем на строку.*/
  ck_assert_uint_eq(
      s21_strlen(test1),
      strlen(test1)); /*выполняет сравнение результатов работы функций
                         s21_strlen и strlen. Функция s21_strlen возвращает
                         длину строки test1 (количество символов до завершающего
                         нуля), а функция strlen выполняет аналогичное действие.
                         ck_assert_uint_eq проверяет, что оба результаты равны*/
}
END_TEST

START_TEST(strlen_2) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strlen(test2), strlen(test2));
}
END_TEST

START_TEST(strlen_3) {
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strlen(test3), strlen(test3));
}
END_TEST

START_TEST(strlen_4) {
  char test6[] = "\0";
  ck_assert_uint_eq(s21_strlen(test6), strlen(test6));
}
END_TEST

START_TEST(strlen_5) {
  char test7[] = "goga\0 job";
  ck_assert_uint_eq(s21_strlen(test7), strlen(test7));
}
END_TEST

START_TEST(strlen_6) {
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strlen(test8), strlen(test8));
}
END_TEST

START_TEST(
    strpbrk_1) { /* данный тест проверяет, что функции s21_strpbrk и strpbrk
                    правильно находят первое вхождение символа из строки test2 в
                    строке test1. Если результаты работы функций не совпадают,
                    то тест будет считаться неудачным.*/
  char *test1 =
      "Alla Halla Cat Dog"; /*объявляются две переменные test1 и test2 и
                               инициализируются строками "Alla Halla Cat Dog" и
                               "Alla Halla Alla Walla" соответственно. Обе
                               переменные являются указателями на строки.*/
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(
      s21_strpbrk(test1, test2),
      strpbrk(test1,
              test2)); /*выполняет сравнение результатов работы функций
                          s21_strpbrk и strpbrk для строк test1 и test2. Функция
                          s21_strpbrk ищет первое вхождение любого символа из
                          строки test2 в строке test1 и возвращает указатель на
                          этот символ, а функция strpbrk выполняет аналогичное
                          действие. ck_assert_ptr_eq проверяет, что оба
                          результата равны (указывают на один и тот же символ
                          или на NULL, если не найдено совпадение).*/
}
END_TEST

START_TEST(strpbrk_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strpbrk(test2, test1), strpbrk(test2, test1));
}
END_TEST

START_TEST(strpbrk_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strpbrk(test1, test3), strpbrk(test1, test3));
}
END_TEST

START_TEST(strpbrk_4) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strpbrk(test3, test2), strpbrk(test3, test2));
}
END_TEST

START_TEST(strpbrk_5) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strpbrk(test2, test3), strpbrk(test2, test3));
}
END_TEST

START_TEST(strpbrk_6) {
  char test6[] = "\0";
  char test7[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strpbrk(test6, test7), strpbrk(test6, test7));
}
END_TEST

START_TEST(strpbrk_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strpbrk(test1, test8), strpbrk(test1, test8));
}
END_TEST

START_TEST(
    strrchr_1) {  //данный тест проверяет, что функции s21_strrchr и
                  //   strrchr правильно находят последнее вхождение символа
                  //   'a' в строке test1. Если результаты работы функций не
                  //   совпадают, то тест будет считаться неудачным.
  char *test1 =
      "Alla Halla Cat Dog";  //объявляется переменная test1 и инициализируется
                             //   строкой "Alla Halla Cat Dog". Переменная test1
                             //   является указателем на строку

  ck_assert_ptr_eq(
      s21_strrchr(test1, 'a'),
      strrchr(
          test1,
          'a'));  //выполняет сравнение результатов работы функций s21_strrchr и
                  //   strrchr для строки test1 и символа 'a'. Функция
                  //   s21_strrchr ищет последнее вхождение символа 'a' в строке
                  //   test1 и возвращает указатель на этот символ, а функция
                  //   strrchr выполняет аналогичное действие. ck_assert_ptr_eq
                  //   проверяет, что оба результата равны (указывают на один и
                  //   тот же символ или на NULL, если не найдено совпадение).
}
END_TEST

START_TEST(strrchr_2) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strrchr(test2, 'l'), strrchr(test2, 'l'));
}
END_TEST

START_TEST(strrchr_3) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strrchr(test3, '1'), strrchr(test3, '1'));
}
END_TEST

START_TEST(strrchr_4) {
  char test6[] = "\0";
  ck_assert_ptr_eq(s21_strrchr(test6, '1'), strrchr(test6, '1'));
}
END_TEST

START_TEST(strrchr_5) {
  char test7[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strrchr(test7, 'g'), strrchr(test7, 'g'));
}
END_TEST

START_TEST(strrchr_6) {
  char test8[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strrchr(test8, 'o'), strrchr(test8, 'o'));
}
END_TEST

START_TEST(strrchr_7) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strrchr(test3, 5), strrchr(test3, 5));
}
END_TEST

START_TEST(strrchr_8) {
  char *test1 = "Alla Halla Cat Dog";
  ck_assert_ptr_eq(s21_strrchr(test1, 'Q'), strrchr(test1, 'Q'));
}
END_TEST

START_TEST(strstr_1) { /*данный тест проверяет, что функции s21_strstr и strstr
                          правильно находят первое вхождение подстроки "all" в
                          строке test1. Если результаты работы функций не
                          совпадают, то тест будет считаться неудачным.*/
  char *test1 =
      "Alla Halla Cat Dog"; /*объявляется переменная test1 и инициализируется
                               строкой "Alla Halla Cat Dog". Переменная test1
                               является указателем на строку.*/

  ck_assert_ptr_eq(
      s21_strstr(test1, "all"),
      strstr(
          test1,
          "all")); /*выполняет сравнение результатов работы функций s21_strstr и
                      strstr для строки test1 и подстроки "all". Функция
                      s21_strstr ищет первое вхождение подстроки "all" в строке
                      test1 и возвращает указатель на эту подстроку, а функция
                      strstr выполняет аналогичное действие. ck_assert_ptr_eq
                      проверяет, что оба результата равны (указывают на одну и
                      ту же подстроку или на NULL, если не найдено совпадение)*/
}
END_TEST

START_TEST(strstr_2) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strstr(test2, "lla"), strstr(test2, "lla"));
}
END_TEST

START_TEST(strstr_3) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strstr(test3, "123"), strstr(test3, "123"));
}
END_TEST

START_TEST(strstr_4) {
  char test6[] = "\0";
  ck_assert_ptr_eq(s21_strstr(test6, "lla"), strstr(test6, "lla"));
}
END_TEST

START_TEST(strstr_5) {
  char test7[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strstr(test7, "gog"), strstr(test7, "gog"));
}
END_TEST

START_TEST(strstr_6) {
  char test7[] = "goga\0 job";
  char test8[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strstr(test8, test7), strstr(test8, test7));
}
END_TEST

START_TEST(sprintf_test_1) {
  char test_str_1[50] = "";
  char test_str_1_1[50] = "";
  s21_sprintf(test_str_1, "%-d", 0);
  sprintf(test_str_1_1, "%-d", 0);
  ck_assert_str_eq(test_str_1, test_str_1_1);
}
END_TEST

START_TEST(sprintf_test_2) {
  char test_str_2[50] = "";
  char test_str_2_2[50] = "";
  s21_sprintf(test_str_2, "%-d", 1);
  sprintf(test_str_2_2, "%-d", 1);
  ck_assert_str_eq(test_str_2, test_str_2_2);
}
END_TEST

START_TEST(sprintf_test_3) {
  char test_str_3[50] = "";
  char test_str_3_3[50] = "";
  s21_sprintf(test_str_3, "%-d", 10);
  sprintf(test_str_3_3, "%-d", 10);
  ck_assert_str_eq(test_str_3, test_str_3_3);
}
END_TEST

START_TEST(sprintf_test_4) {
  char test_str_4[50] = "";
  char test_str_4_4[50] = "";
  s21_sprintf(test_str_4, "%-d", 123456);
  sprintf(test_str_4_4, "%-d", 123456);
  ck_assert_str_eq(test_str_4, test_str_4_4);
}
END_TEST

START_TEST(sprintf_test_5) {
  char test_str_5[50] = "";
  char test_str_5_5[50] = "";
  s21_sprintf(test_str_5, "%-d", -67890123);
  sprintf(test_str_5_5, "%-d", -67890123);
  ck_assert_str_eq(test_str_5, test_str_5_5);
}
END_TEST

START_TEST(sprintf_test_6) {
  char test_str_6[50] = "";
  char test_str_6_6[50] = "";
  s21_sprintf(test_str_6, "%-d", 4343);
  sprintf(test_str_6_6, "%-d", 4343);
  ck_assert_str_eq(test_str_6, test_str_6_6);
}
END_TEST

START_TEST(sprintf_test_7) {
  char test_str_7[50] = "";
  char test_str_7_7[50] = "";
  s21_sprintf(test_str_7, "%-d", -1);
  sprintf(test_str_7_7, "%-d", -1);
  ck_assert_str_eq(test_str_7, test_str_7_7);
}
END_TEST

START_TEST(sprintf_test_8) {
  char test_str_8[50] = "";
  char test_str_8_8[50] = "";
  s21_sprintf(test_str_8, "%-d", -10);
  sprintf(test_str_8_8, "%-d", -10);
  ck_assert_str_eq(test_str_8, test_str_8_8);
}
END_TEST

START_TEST(sprintf_test_9) {
  char test_str_9[50] = "";
  char test_str_9_9[50] = "";
  s21_sprintf(test_str_9, "%-d", 43);
  sprintf(test_str_9_9, "%-d", 43);
  ck_assert_str_eq(test_str_9, test_str_9_9);
}
END_TEST

START_TEST(sprintf_test_10) {
  char test_str_10[50] = "";
  char test_str_10_10[50] = "";
  s21_sprintf(test_str_10, "%-i", 0);
  sprintf(test_str_10_10, "%-i", 0);
  ck_assert_str_eq(test_str_10, test_str_10_10);
}
END_TEST

START_TEST(sprintf_test_11) {
  char test_str_11[50] = "";
  char test_str_11_11[50] = "";
  s21_sprintf(test_str_11, "%-i", 1);
  sprintf(test_str_11_11, "%-i", 1);
  ck_assert_str_eq(test_str_11, test_str_11_11);
}
END_TEST

START_TEST(sprintf_test_12) {
  char test_str_12[50] = "";
  char test_str_12_12[50] = "";
  s21_sprintf(test_str_12, "%-i", 10);
  sprintf(test_str_12_12, "%-i", 10);
  ck_assert_str_eq(test_str_12, test_str_12_12);
}
END_TEST

START_TEST(sprintf_test_13) {
  char test_str_13[50] = "";
  char test_str_13_13[50] = "";
  s21_sprintf(test_str_13, "%-i", 123456);
  sprintf(test_str_13_13, "%-i", 123456);
  ck_assert_str_eq(test_str_13, test_str_13_13);
}
END_TEST

START_TEST(sprintf_test_14) {
  char test_str_14[50] = "";
  char test_str_14_14[50] = "";
  s21_sprintf(test_str_14, "%-i", -67890123);
  sprintf(test_str_14_14, "%-i", -67890123);
  ck_assert_str_eq(test_str_14, test_str_14_14);
}
END_TEST

START_TEST(sprintf_test_15) {
  char test_str_15[50] = "";
  char test_str_15_15[50] = "";
  s21_sprintf(test_str_15, "%-i", 4343);
  sprintf(test_str_15_15, "%-i", 4343);
  ck_assert_str_eq(test_str_15, test_str_15_15);
}
END_TEST

START_TEST(sprintf_test_16) {
  char test_str_16[50] = "";
  char test_str_16_16[50] = "";
  s21_sprintf(test_str_16, "%-i", -1);
  sprintf(test_str_16_16, "%-i", -1);
  ck_assert_str_eq(test_str_16, test_str_16_16);
}
END_TEST

START_TEST(sprintf_test_17) {
  char test_str_17[50] = "";
  char test_str_17_17[50] = "";
  s21_sprintf(test_str_17, "%-i", -10);
  sprintf(test_str_17_17, "%-i", -10);
  ck_assert_str_eq(test_str_17, test_str_17_17);
}
END_TEST

START_TEST(sprintf_test_18) {
  char test_str_18[50] = "";
  char test_str_18_18[50] = "";
  s21_sprintf(test_str_18, "%-i", 43);
  sprintf(test_str_18_18, "%-i", 43);
  ck_assert_str_eq(test_str_18, test_str_18_18);
}
END_TEST

START_TEST(sprintf_test_19) {
  char test_str_19[50] = "";
  char test_str_19_19[50] = "";
  s21_sprintf(test_str_19, "%-o", 0);
  sprintf(test_str_19_19, "%-o", 0);
  ck_assert_str_eq(test_str_19, test_str_19_19);
}
END_TEST

START_TEST(sprintf_test_20) {
  char test_str_20[50] = "";
  char test_str_20_20[50] = "";
  s21_sprintf(test_str_20, "%-o", 1);
  sprintf(test_str_20_20, "%-o", 1);
  ck_assert_str_eq(test_str_20, test_str_20_20);
}
END_TEST

START_TEST(sprintf_test_21) {
  char test_str_21[50] = "";
  char test_str_21_21[50] = "";
  s21_sprintf(test_str_21, "%-o", 10);
  sprintf(test_str_21_21, "%-o", 10);
  ck_assert_str_eq(test_str_21, test_str_21_21);
}
END_TEST

START_TEST(sprintf_test_22) {
  char test_str_22[50] = "";
  char test_str_22_22[50] = "";
  s21_sprintf(test_str_22, "%-o", 123456);
  sprintf(test_str_22_22, "%-o", 123456);
  ck_assert_str_eq(test_str_22, test_str_22_22);
}
END_TEST

START_TEST(sprintf_test_23) {
  char test_str_23[50] = "";
  char test_str_23_23[50] = "";
  s21_sprintf(test_str_23, "%-o", -67890123);
  sprintf(test_str_23_23, "%-o", -67890123);
  ck_assert_str_eq(test_str_23, test_str_23_23);
}
END_TEST

START_TEST(sprintf_test_24) {
  char test_str_24[50] = "";
  char test_str_24_24[50] = "";
  s21_sprintf(test_str_24, "%-o", 4343);
  sprintf(test_str_24_24, "%-o", 4343);
  ck_assert_str_eq(test_str_24, test_str_24_24);
}
END_TEST

START_TEST(sprintf_test_25) {
  char test_str_25[50] = "";
  char test_str_25_25[50] = "";
  s21_sprintf(test_str_25, "%-o", -1);
  sprintf(test_str_25_25, "%-o", -1);
  ck_assert_str_eq(test_str_25, test_str_25_25);
}
END_TEST

START_TEST(sprintf_test_26) {
  char test_str_26[50] = "";
  char test_str_26_26[50] = "";
  s21_sprintf(test_str_26, "%-o", -10);
  sprintf(test_str_26_26, "%-o", -10);
  ck_assert_str_eq(test_str_26, test_str_26_26);
}
END_TEST

START_TEST(sprintf_test_27) {
  char test_str_27[50] = "";
  char test_str_27_27[50] = "";
  s21_sprintf(test_str_27, "%-o", 43);
  sprintf(test_str_27_27, "%-o", 43);
  ck_assert_str_eq(test_str_27, test_str_27_27);
}
END_TEST

START_TEST(sprintf_test_28) {
  char test_str_28[50] = "";
  char test_str_28_28[50] = "";
  s21_sprintf(test_str_28, "%-u", 0);
  sprintf(test_str_28_28, "%-u", 0);
  ck_assert_str_eq(test_str_28, test_str_28_28);
}
END_TEST

START_TEST(sprintf_test_29) {
  char test_str_29[50] = "";
  char test_str_29_29[50] = "";
  s21_sprintf(test_str_29, "%-u", 1);
  sprintf(test_str_29_29, "%-u", 1);
  ck_assert_str_eq(test_str_29, test_str_29_29);
}
END_TEST

START_TEST(sprintf_test_30) {
  char test_str_30[50] = "";
  char test_str_30_30[50] = "";
  s21_sprintf(test_str_30, "%-u", 10);
  sprintf(test_str_30_30, "%-u", 10);
  ck_assert_str_eq(test_str_30, test_str_30_30);
}
END_TEST

START_TEST(sprintf_test_31) {
  char test_str_31[50] = "";
  char test_str_31_31[50] = "";
  s21_sprintf(test_str_31, "%-u", 123456);
  sprintf(test_str_31_31, "%-u", 123456);
  ck_assert_str_eq(test_str_31, test_str_31_31);
}
END_TEST

START_TEST(sprintf_test_32) {
  char test_str_32[50] = "";
  char test_str_32_32[50] = "";
  s21_sprintf(test_str_32, "%-u", -67890123);
  sprintf(test_str_32_32, "%-u", -67890123);
  ck_assert_str_eq(test_str_32, test_str_32_32);
}
END_TEST

START_TEST(sprintf_test_33) {
  char test_str_33[50] = "";
  char test_str_33_33[50] = "";
  s21_sprintf(test_str_33, "%-u", 4343);
  sprintf(test_str_33_33, "%-u", 4343);
  ck_assert_str_eq(test_str_33, test_str_33_33);
}
END_TEST

START_TEST(sprintf_test_34) {
  char test_str_34[50] = "";
  char test_str_34_34[50] = "";
  s21_sprintf(test_str_34, "%-u", -1);
  sprintf(test_str_34_34, "%-u", -1);
  ck_assert_str_eq(test_str_34, test_str_34_34);
}
END_TEST

START_TEST(sprintf_test_35) {
  char test_str_35[50] = "";
  char test_str_35_35[50] = "";
  s21_sprintf(test_str_35, "%-u", -10);
  sprintf(test_str_35_35, "%-u", -10);
  ck_assert_str_eq(test_str_35, test_str_35_35);
}
END_TEST

START_TEST(sprintf_test_36) {
  char test_str_36[50] = "";
  char test_str_36_36[50] = "";
  s21_sprintf(test_str_36, "%-u", 43);
  sprintf(test_str_36_36, "%-u", 43);
  ck_assert_str_eq(test_str_36, test_str_36_36);
}
END_TEST

START_TEST(sprintf_test_37) {
  char test_str_37[50] = "";
  char test_str_37_37[50] = "";
  s21_sprintf(test_str_37, "%-x", 0);
  sprintf(test_str_37_37, "%-x", 0);
  ck_assert_str_eq(test_str_37, test_str_37_37);
}
END_TEST

START_TEST(sprintf_test_38) {
  char test_str_38[50] = "";
  char test_str_38_38[50] = "";
  s21_sprintf(test_str_38, "%-x", 1);
  sprintf(test_str_38_38, "%-x", 1);
  ck_assert_str_eq(test_str_38, test_str_38_38);
}
END_TEST

START_TEST(sprintf_test_39) {
  char test_str_39[50] = "";
  char test_str_39_39[50] = "";
  s21_sprintf(test_str_39, "%-x", 10);
  sprintf(test_str_39_39, "%-x", 10);
  ck_assert_str_eq(test_str_39, test_str_39_39);
}
END_TEST

START_TEST(sprintf_test_40) {
  char test_str_40[50] = "";
  char test_str_40_40[50] = "";
  s21_sprintf(test_str_40, "%-x", 123456);
  sprintf(test_str_40_40, "%-x", 123456);
  ck_assert_str_eq(test_str_40, test_str_40_40);
}
END_TEST

START_TEST(sprintf_test_41) {
  char test_str_41[50] = "";
  char test_str_41_41[50] = "";
  s21_sprintf(test_str_41, "%-x", -67890123);
  sprintf(test_str_41_41, "%-x", -67890123);
  ck_assert_str_eq(test_str_41, test_str_41_41);
}
END_TEST

START_TEST(sprintf_test_42) {
  char test_str_42[50] = "";
  char test_str_42_42[50] = "";
  s21_sprintf(test_str_42, "%-x", 4343);
  sprintf(test_str_42_42, "%-x", 4343);
  ck_assert_str_eq(test_str_42, test_str_42_42);
}
END_TEST

START_TEST(sprintf_test_43) {
  char test_str_43[50] = "";
  char test_str_43_43[50] = "";
  s21_sprintf(test_str_43, "%-x", -1);
  sprintf(test_str_43_43, "%-x", -1);
  ck_assert_str_eq(test_str_43, test_str_43_43);
}
END_TEST

START_TEST(sprintf_test_44) {
  char test_str_44[50] = "";
  char test_str_44_44[50] = "";
  s21_sprintf(test_str_44, "%-x", -10);
  sprintf(test_str_44_44, "%-x", -10);
  ck_assert_str_eq(test_str_44, test_str_44_44);
}
END_TEST

START_TEST(sprintf_test_45) {
  char test_str_45[50] = "";
  char test_str_45_45[50] = "";
  s21_sprintf(test_str_45, "%-x", 43);
  sprintf(test_str_45_45, "%-x", 43);
  ck_assert_str_eq(test_str_45, test_str_45_45);
}
END_TEST

START_TEST(sprintf_test_46) {
  char test_str_46[50] = "";
  char test_str_46_46[50] = "";
  s21_sprintf(test_str_46, "%-X", 0);
  sprintf(test_str_46_46, "%-X", 0);
  ck_assert_str_eq(test_str_46, test_str_46_46);
}
END_TEST

START_TEST(sprintf_test_47) {
  char test_str_47[50] = "";
  char test_str_47_47[50] = "";
  s21_sprintf(test_str_47, "%-X", 1);
  sprintf(test_str_47_47, "%-X", 1);
  ck_assert_str_eq(test_str_47, test_str_47_47);
}
END_TEST

START_TEST(sprintf_test_48) {
  char test_str_48[50] = "";
  char test_str_48_48[50] = "";
  s21_sprintf(test_str_48, "%-X", 10);
  sprintf(test_str_48_48, "%-X", 10);
  ck_assert_str_eq(test_str_48, test_str_48_48);
}
END_TEST

START_TEST(sprintf_test_49) {
  char test_str_49[50] = "";
  char test_str_49_49[50] = "";
  s21_sprintf(test_str_49, "%-X", 123456);
  sprintf(test_str_49_49, "%-X", 123456);
  ck_assert_str_eq(test_str_49, test_str_49_49);
}
END_TEST

START_TEST(sprintf_test_50) {
  char test_str_50[50] = "";
  char test_str_50_50[50] = "";
  s21_sprintf(test_str_50, "%-X", -67890123);
  sprintf(test_str_50_50, "%-X", -67890123);
  ck_assert_str_eq(test_str_50, test_str_50_50);
}
END_TEST

START_TEST(sprintf_test_51) {
  char test_str_51[50] = "";
  char test_str_51_51[50] = "";
  s21_sprintf(test_str_51, "%-X", 4343);
  sprintf(test_str_51_51, "%-X", 4343);
  ck_assert_str_eq(test_str_51, test_str_51_51);
}
END_TEST

START_TEST(sprintf_test_52) {
  char test_str_52[50] = "";
  char test_str_52_52[50] = "";
  s21_sprintf(test_str_52, "%-X", -1);
  sprintf(test_str_52_52, "%-X", -1);
  ck_assert_str_eq(test_str_52, test_str_52_52);
}
END_TEST

START_TEST(sprintf_test_53) {
  char test_str_53[50] = "";
  char test_str_53_53[50] = "";
  s21_sprintf(test_str_53, "%-X", -10);
  sprintf(test_str_53_53, "%-X", -10);
  ck_assert_str_eq(test_str_53, test_str_53_53);
}
END_TEST

START_TEST(sprintf_test_54) {
  char test_str_54[50] = "";
  char test_str_54_54[50] = "";
  s21_sprintf(test_str_54, "%-X", 43);
  sprintf(test_str_54_54, "%-X", 43);
  ck_assert_str_eq(test_str_54, test_str_54_54);
}
END_TEST

START_TEST(sprintf_test_55) {
  char test_str_55[50] = "";
  char test_str_55_55[50] = "";
  s21_sprintf(test_str_55, "%+d", 0);
  sprintf(test_str_55_55, "%+d", 0);
  ck_assert_str_eq(test_str_55, test_str_55_55);
}
END_TEST

START_TEST(sprintf_test_56) {
  char test_str_56[50] = "";
  char test_str_56_56[50] = "";
  s21_sprintf(test_str_56, "%+d", 1);
  sprintf(test_str_56_56, "%+d", 1);
  ck_assert_str_eq(test_str_56, test_str_56_56);
}
END_TEST

START_TEST(sprintf_test_57) {
  char test_str_57[50] = "";
  char test_str_57_57[50] = "";
  s21_sprintf(test_str_57, "%+d", 10);
  sprintf(test_str_57_57, "%+d", 10);
  ck_assert_str_eq(test_str_57, test_str_57_57);
}
END_TEST

START_TEST(sprintf_test_58) {
  char test_str_58[50] = "";
  char test_str_58_58[50] = "";
  s21_sprintf(test_str_58, "%+d", 123456);
  sprintf(test_str_58_58, "%+d", 123456);
  ck_assert_str_eq(test_str_58, test_str_58_58);
}
END_TEST

START_TEST(sprintf_test_59) {
  char test_str_59[50] = "";
  char test_str_59_59[50] = "";
  s21_sprintf(test_str_59, "%+d", -67890123);
  sprintf(test_str_59_59, "%+d", -67890123);
  ck_assert_str_eq(test_str_59, test_str_59_59);
}
END_TEST

START_TEST(sprintf_test_60) {
  char test_str_60[50] = "";
  char test_str_60_60[50] = "";
  s21_sprintf(test_str_60, "%+d", 4343);
  sprintf(test_str_60_60, "%+d", 4343);
  ck_assert_str_eq(test_str_60, test_str_60_60);
}
END_TEST

START_TEST(sprintf_test_61) {
  char test_str_61[50] = "";
  char test_str_61_61[50] = "";
  s21_sprintf(test_str_61, "%+d", -1);
  sprintf(test_str_61_61, "%+d", -1);
  ck_assert_str_eq(test_str_61, test_str_61_61);
}
END_TEST

START_TEST(sprintf_test_62) {
  char test_str_62[50] = "";
  char test_str_62_62[50] = "";
  s21_sprintf(test_str_62, "%+d", -10);
  sprintf(test_str_62_62, "%+d", -10);
  ck_assert_str_eq(test_str_62, test_str_62_62);
}
END_TEST

START_TEST(sprintf_test_63) {
  char test_str_63[50] = "";
  char test_str_63_63[50] = "";
  s21_sprintf(test_str_63, "%+d", 43);
  sprintf(test_str_63_63, "%+d", 43);
  ck_assert_str_eq(test_str_63, test_str_63_63);
}
END_TEST

START_TEST(sprintf_test_64) {
  char test_str_64[50] = "";
  char test_str_64_64[50] = "";
  s21_sprintf(test_str_64, "%+i", 0);
  sprintf(test_str_64_64, "%+i", 0);
  ck_assert_str_eq(test_str_64, test_str_64_64);
}
END_TEST

START_TEST(sprintf_test_65) {
  char test_str_65[50] = "";
  char test_str_65_65[50] = "";
  s21_sprintf(test_str_65, "%+i", 1);
  sprintf(test_str_65_65, "%+i", 1);
  ck_assert_str_eq(test_str_65, test_str_65_65);
}
END_TEST

START_TEST(sprintf_test_66) {
  char test_str_66[50] = "";
  char test_str_66_66[50] = "";
  s21_sprintf(test_str_66, "%+i", 10);
  sprintf(test_str_66_66, "%+i", 10);
  ck_assert_str_eq(test_str_66, test_str_66_66);
}
END_TEST

START_TEST(sprintf_test_67) {
  char test_str_67[50] = "";
  char test_str_67_67[50] = "";
  s21_sprintf(test_str_67, "%+i", 123456);
  sprintf(test_str_67_67, "%+i", 123456);
  ck_assert_str_eq(test_str_67, test_str_67_67);
}
END_TEST

START_TEST(sprintf_test_68) {
  char test_str_68[50] = "";
  char test_str_68_68[50] = "";
  s21_sprintf(test_str_68, "%+i", -67890123);
  sprintf(test_str_68_68, "%+i", -67890123);
  ck_assert_str_eq(test_str_68, test_str_68_68);
}
END_TEST

START_TEST(sprintf_test_69) {
  char test_str_69[50] = "";
  char test_str_69_69[50] = "";
  s21_sprintf(test_str_69, "%+i", 4343);
  sprintf(test_str_69_69, "%+i", 4343);
  ck_assert_str_eq(test_str_69, test_str_69_69);
}
END_TEST

START_TEST(sprintf_test_70) {
  char test_str_70[50] = "";
  char test_str_70_70[50] = "";
  s21_sprintf(test_str_70, "%+i", -1);
  sprintf(test_str_70_70, "%+i", -1);
  ck_assert_str_eq(test_str_70, test_str_70_70);
}
END_TEST

START_TEST(sprintf_test_71) {
  char test_str_71[50] = "";
  char test_str_71_71[50] = "";
  s21_sprintf(test_str_71, "%+i", -10);
  sprintf(test_str_71_71, "%+i", -10);
  ck_assert_str_eq(test_str_71, test_str_71_71);
}
END_TEST

START_TEST(sprintf_test_72) {
  char test_str_72[50] = "";
  char test_str_72_72[50] = "";
  s21_sprintf(test_str_72, "%+i", 43);
  sprintf(test_str_72_72, "%+i", 43);
  ck_assert_str_eq(test_str_72, test_str_72_72);
}
END_TEST

START_TEST(sprintf_test_73) {
  char test_str_73[50] = "";
  char test_str_73_73[50] = "";
  s21_sprintf(test_str_73, "%+o", 0);
  sprintf(test_str_73_73, "%+o", 0);
  ck_assert_str_eq(test_str_73, test_str_73_73);
}
END_TEST

START_TEST(sprintf_test_74) {
  char test_str_74[50] = "";
  char test_str_74_74[50] = "";
  s21_sprintf(test_str_74, "%+o", 1);
  sprintf(test_str_74_74, "%+o", 1);
  ck_assert_str_eq(test_str_74, test_str_74_74);
}
END_TEST

START_TEST(sprintf_test_75) {
  char test_str_75[50] = "";
  char test_str_75_75[50] = "";
  s21_sprintf(test_str_75, "%+o", 10);
  sprintf(test_str_75_75, "%+o", 10);
  ck_assert_str_eq(test_str_75, test_str_75_75);
}
END_TEST

START_TEST(sprintf_test_76) {
  char test_str_76[50] = "";
  char test_str_76_76[50] = "";
  s21_sprintf(test_str_76, "%+o", 123456);
  sprintf(test_str_76_76, "%+o", 123456);
  ck_assert_str_eq(test_str_76, test_str_76_76);
}
END_TEST

START_TEST(sprintf_test_77) {
  char test_str_77[50] = "";
  char test_str_77_77[50] = "";
  s21_sprintf(test_str_77, "%+o", -67890123);
  sprintf(test_str_77_77, "%+o", -67890123);
  ck_assert_str_eq(test_str_77, test_str_77_77);
}
END_TEST

START_TEST(sprintf_test_78) {
  char test_str_78[50] = "";
  char test_str_78_78[50] = "";
  s21_sprintf(test_str_78, "%+o", 4343);
  sprintf(test_str_78_78, "%+o", 4343);
  ck_assert_str_eq(test_str_78, test_str_78_78);
}
END_TEST

START_TEST(sprintf_test_79) {
  char test_str_79[50] = "";
  char test_str_79_79[50] = "";
  s21_sprintf(test_str_79, "%+o", -1);
  sprintf(test_str_79_79, "%+o", -1);
  ck_assert_str_eq(test_str_79, test_str_79_79);
}
END_TEST

START_TEST(sprintf_test_80) {
  char test_str_80[50] = "";
  char test_str_80_80[50] = "";
  s21_sprintf(test_str_80, "%+o", -10);
  sprintf(test_str_80_80, "%+o", -10);
  ck_assert_str_eq(test_str_80, test_str_80_80);
}
END_TEST

START_TEST(sprintf_test_81) {
  char test_str_81[50] = "";
  char test_str_81_81[50] = "";
  s21_sprintf(test_str_81, "%+o", 43);
  sprintf(test_str_81_81, "%+o", 43);
  ck_assert_str_eq(test_str_81, test_str_81_81);
}
END_TEST

START_TEST(sprintf_test_82) {
  char test_str_82[50] = "";
  char test_str_82_82[50] = "";
  s21_sprintf(test_str_82, "%+u", 0);
  sprintf(test_str_82_82, "%+u", 0);
  ck_assert_str_eq(test_str_82, test_str_82_82);
}
END_TEST

START_TEST(sprintf_test_83) {
  char test_str_83[50] = "";
  char test_str_83_83[50] = "";
  s21_sprintf(test_str_83, "%+u", 1);
  sprintf(test_str_83_83, "%+u", 1);
  ck_assert_str_eq(test_str_83, test_str_83_83);
}
END_TEST

START_TEST(sprintf_test_84) {
  char test_str_84[50] = "";
  char test_str_84_84[50] = "";
  s21_sprintf(test_str_84, "%+u", 10);
  sprintf(test_str_84_84, "%+u", 10);
  ck_assert_str_eq(test_str_84, test_str_84_84);
}
END_TEST

START_TEST(sprintf_test_85) {
  char test_str_85[50] = "";
  char test_str_85_85[50] = "";
  s21_sprintf(test_str_85, "%+u", 123456);
  sprintf(test_str_85_85, "%+u", 123456);
  ck_assert_str_eq(test_str_85, test_str_85_85);
}
END_TEST

START_TEST(sprintf_test_86) {
  char test_str_86[50] = "";
  char test_str_86_86[50] = "";
  s21_sprintf(test_str_86, "%+u", -67890123);
  sprintf(test_str_86_86, "%+u", -67890123);
  ck_assert_str_eq(test_str_86, test_str_86_86);
}
END_TEST

START_TEST(sprintf_test_87) {
  char test_str_87[50] = "";
  char test_str_87_87[50] = "";
  s21_sprintf(test_str_87, "%+u", 4343);
  sprintf(test_str_87_87, "%+u", 4343);
  ck_assert_str_eq(test_str_87, test_str_87_87);
}
END_TEST

START_TEST(sprintf_test_88) {
  char test_str_88[50] = "";
  char test_str_88_88[50] = "";
  s21_sprintf(test_str_88, "%+u", -1);
  sprintf(test_str_88_88, "%+u", -1);
  ck_assert_str_eq(test_str_88, test_str_88_88);
}
END_TEST

START_TEST(sprintf_test_89) {
  char test_str_89[50] = "";
  char test_str_89_89[50] = "";
  s21_sprintf(test_str_89, "%+u", -10);
  sprintf(test_str_89_89, "%+u", -10);
  ck_assert_str_eq(test_str_89, test_str_89_89);
}
END_TEST

START_TEST(sprintf_test_90) {
  char test_str_90[50] = "";
  char test_str_90_90[50] = "";
  s21_sprintf(test_str_90, "%+u", 43);
  sprintf(test_str_90_90, "%+u", 43);
  ck_assert_str_eq(test_str_90, test_str_90_90);
}
END_TEST

START_TEST(sprintf_test_91) {
  char test_str_91[50] = "";
  char test_str_91_91[50] = "";
  s21_sprintf(test_str_91, "%+x", 0);
  sprintf(test_str_91_91, "%+x", 0);
  ck_assert_str_eq(test_str_91, test_str_91_91);
}
END_TEST

START_TEST(sprintf_test_92) {
  char test_str_92[50] = "";
  char test_str_92_92[50] = "";
  s21_sprintf(test_str_92, "%+x", 1);
  sprintf(test_str_92_92, "%+x", 1);
  ck_assert_str_eq(test_str_92, test_str_92_92);
}
END_TEST

START_TEST(sprintf_test_93) {
  char test_str_93[50] = "";
  char test_str_93_93[50] = "";
  s21_sprintf(test_str_93, "%+x", 10);
  sprintf(test_str_93_93, "%+x", 10);
  ck_assert_str_eq(test_str_93, test_str_93_93);
}
END_TEST

START_TEST(sprintf_test_94) {
  char test_str_94[50] = "";
  char test_str_94_94[50] = "";
  s21_sprintf(test_str_94, "%+x", 123456);
  sprintf(test_str_94_94, "%+x", 123456);
  ck_assert_str_eq(test_str_94, test_str_94_94);
}
END_TEST

START_TEST(sprintf_test_95) {
  char test_str_95[50] = "";
  char test_str_95_95[50] = "";
  s21_sprintf(test_str_95, "%+x", -67890123);
  sprintf(test_str_95_95, "%+x", -67890123);
  ck_assert_str_eq(test_str_95, test_str_95_95);
}
END_TEST

START_TEST(sprintf_test_96) {
  char test_str_96[50] = "";
  char test_str_96_96[50] = "";
  s21_sprintf(test_str_96, "%+x", 4343);
  sprintf(test_str_96_96, "%+x", 4343);
  ck_assert_str_eq(test_str_96, test_str_96_96);
}
END_TEST

START_TEST(sprintf_test_97) {
  char test_str_97[50] = "";
  char test_str_97_97[50] = "";
  s21_sprintf(test_str_97, "%+x", -1);
  sprintf(test_str_97_97, "%+x", -1);
  ck_assert_str_eq(test_str_97, test_str_97_97);
}
END_TEST

START_TEST(sprintf_test_98) {
  char test_str_98[50] = "";
  char test_str_98_98[50] = "";
  s21_sprintf(test_str_98, "%+x", -10);
  sprintf(test_str_98_98, "%+x", -10);
  ck_assert_str_eq(test_str_98, test_str_98_98);
}
END_TEST

START_TEST(sprintf_test_99) {
  char test_str_99[50] = "";
  char test_str_99_99[50] = "";
  s21_sprintf(test_str_99, "%+x", 43);
  sprintf(test_str_99_99, "%+x", 43);
  ck_assert_str_eq(test_str_99, test_str_99_99);
}
END_TEST

START_TEST(sprintf_test_100) {
  char test_str_100[50] = "";
  char test_str_100_100[50] = "";
  s21_sprintf(test_str_100, "%+X", 0);
  sprintf(test_str_100_100, "%+X", 0);
  ck_assert_str_eq(test_str_100, test_str_100_100);
}
END_TEST

START_TEST(sprintf_test_101) {
  char test_str_101[50] = "";
  char test_str_101_101[50] = "";
  s21_sprintf(test_str_101, "%+X", 1);
  sprintf(test_str_101_101, "%+X", 1);
  ck_assert_str_eq(test_str_101, test_str_101_101);
}
END_TEST

START_TEST(sprintf_test_102) {
  char test_str_102[50] = "";
  char test_str_102_102[50] = "";
  s21_sprintf(test_str_102, "%+X", 10);
  sprintf(test_str_102_102, "%+X", 10);
  ck_assert_str_eq(test_str_102, test_str_102_102);
}
END_TEST

START_TEST(sprintf_test_103) {
  char test_str_103[50] = "";
  char test_str_103_103[50] = "";
  s21_sprintf(test_str_103, "%+X", 123456);
  sprintf(test_str_103_103, "%+X", 123456);
  ck_assert_str_eq(test_str_103, test_str_103_103);
}
END_TEST

START_TEST(sprintf_test_104) {
  char test_str_104[50] = "";
  char test_str_104_104[50] = "";
  s21_sprintf(test_str_104, "%+X", -67890123);
  sprintf(test_str_104_104, "%+X", -67890123);
  ck_assert_str_eq(test_str_104, test_str_104_104);
}
END_TEST

START_TEST(sprintf_test_105) {
  char test_str_105[50] = "";
  char test_str_105_105[50] = "";
  s21_sprintf(test_str_105, "%+X", 4343);
  sprintf(test_str_105_105, "%+X", 4343);
  ck_assert_str_eq(test_str_105, test_str_105_105);
}
END_TEST

START_TEST(sprintf_test_106) {
  char test_str_106[50] = "";
  char test_str_106_106[50] = "";
  s21_sprintf(test_str_106, "%+X", -1);
  sprintf(test_str_106_106, "%+X", -1);
  ck_assert_str_eq(test_str_106, test_str_106_106);
}
END_TEST

START_TEST(sprintf_test_107) {
  char test_str_107[50] = "";
  char test_str_107_107[50] = "";
  s21_sprintf(test_str_107, "%+X", -10);
  sprintf(test_str_107_107, "%+X", -10);
  ck_assert_str_eq(test_str_107, test_str_107_107);
}
END_TEST

START_TEST(sprintf_test_108) {
  char test_str_108[50] = "";
  char test_str_108_108[50] = "";
  s21_sprintf(test_str_108, "%+X", 43);
  sprintf(test_str_108_108, "%+X", 43);
  ck_assert_str_eq(test_str_108, test_str_108_108);
}
END_TEST

START_TEST(sprintf_test_109) {
  char test_str_109[50] = "";
  char test_str_109_109[50] = "";
  s21_sprintf(test_str_109, "% d", 0);
  sprintf(test_str_109_109, "% d", 0);
  ck_assert_str_eq(test_str_109, test_str_109_109);
}
END_TEST

START_TEST(sprintf_test_110) {
  char test_str_110[50] = "";
  char test_str_110_110[50] = "";
  s21_sprintf(test_str_110, "% d", 1);
  sprintf(test_str_110_110, "% d", 1);
  ck_assert_str_eq(test_str_110, test_str_110_110);
}
END_TEST

START_TEST(sprintf_test_111) {
  char test_str_111[50] = "";
  char test_str_111_111[50] = "";
  s21_sprintf(test_str_111, "% d", 10);
  sprintf(test_str_111_111, "% d", 10);
  ck_assert_str_eq(test_str_111, test_str_111_111);
}
END_TEST

START_TEST(sprintf_test_112) {
  char test_str_112[50] = "";
  char test_str_112_112[50] = "";
  s21_sprintf(test_str_112, "% d", 123456);
  sprintf(test_str_112_112, "% d", 123456);
  ck_assert_str_eq(test_str_112, test_str_112_112);
}
END_TEST

START_TEST(sprintf_test_113) {
  char test_str_113[50] = "";
  char test_str_113_113[50] = "";
  s21_sprintf(test_str_113, "% d", -67890123);
  sprintf(test_str_113_113, "% d", -67890123);
  ck_assert_str_eq(test_str_113, test_str_113_113);
}
END_TEST

START_TEST(sprintf_test_114) {
  char test_str_114[50] = "";
  char test_str_114_114[50] = "";
  s21_sprintf(test_str_114, "% d", 4343);
  sprintf(test_str_114_114, "% d", 4343);
  ck_assert_str_eq(test_str_114, test_str_114_114);
}
END_TEST

START_TEST(sprintf_test_115) {
  char test_str_115[50] = "";
  char test_str_115_115[50] = "";
  s21_sprintf(test_str_115, "% d", -1);
  sprintf(test_str_115_115, "% d", -1);
  ck_assert_str_eq(test_str_115, test_str_115_115);
}
END_TEST

START_TEST(sprintf_test_116) {
  char test_str_116[50] = "";
  char test_str_116_116[50] = "";
  s21_sprintf(test_str_116, "% d", -10);
  sprintf(test_str_116_116, "% d", -10);
  ck_assert_str_eq(test_str_116, test_str_116_116);
}
END_TEST

START_TEST(sprintf_test_117) {
  char test_str_117[50] = "";
  char test_str_117_117[50] = "";
  s21_sprintf(test_str_117, "% d", 43);
  sprintf(test_str_117_117, "% d", 43);
  ck_assert_str_eq(test_str_117, test_str_117_117);
}
END_TEST

START_TEST(sprintf_test_118) {
  char test_str_118[50] = "";
  char test_str_118_118[50] = "";
  s21_sprintf(test_str_118, "% i", 0);
  sprintf(test_str_118_118, "% i", 0);
  ck_assert_str_eq(test_str_118, test_str_118_118);
}
END_TEST

START_TEST(sprintf_test_119) {
  char test_str_119[50] = "";
  char test_str_119_119[50] = "";
  s21_sprintf(test_str_119, "% i", 1);
  sprintf(test_str_119_119, "% i", 1);
  ck_assert_str_eq(test_str_119, test_str_119_119);
}
END_TEST

START_TEST(sprintf_test_120) {
  char test_str_120[50] = "";
  char test_str_120_120[50] = "";
  s21_sprintf(test_str_120, "% i", 10);
  sprintf(test_str_120_120, "% i", 10);
  ck_assert_str_eq(test_str_120, test_str_120_120);
}
END_TEST

START_TEST(sprintf_test_121) {
  char test_str_121[50] = "";
  char test_str_121_121[50] = "";
  s21_sprintf(test_str_121, "% i", 123456);
  sprintf(test_str_121_121, "% i", 123456);
  ck_assert_str_eq(test_str_121, test_str_121_121);
}
END_TEST

START_TEST(sprintf_test_122) {
  char test_str_122[50] = "";
  char test_str_122_122[50] = "";
  s21_sprintf(test_str_122, "% i", -67890123);
  sprintf(test_str_122_122, "% i", -67890123);
  ck_assert_str_eq(test_str_122, test_str_122_122);
}
END_TEST

START_TEST(sprintf_test_123) {
  char test_str_123[50] = "";
  char test_str_123_123[50] = "";
  s21_sprintf(test_str_123, "% i", 4343);
  sprintf(test_str_123_123, "% i", 4343);
  ck_assert_str_eq(test_str_123, test_str_123_123);
}
END_TEST

START_TEST(sprintf_test_124) {
  char test_str_124[50] = "";
  char test_str_124_124[50] = "";
  s21_sprintf(test_str_124, "% i", -1);
  sprintf(test_str_124_124, "% i", -1);
  ck_assert_str_eq(test_str_124, test_str_124_124);
}
END_TEST

START_TEST(sprintf_test_125) {
  char test_str_125[50] = "";
  char test_str_125_125[50] = "";
  s21_sprintf(test_str_125, "% i", -10);
  sprintf(test_str_125_125, "% i", -10);
  ck_assert_str_eq(test_str_125, test_str_125_125);
}
END_TEST

START_TEST(sprintf_test_126) {
  char test_str_126[50] = "";
  char test_str_126_126[50] = "";
  s21_sprintf(test_str_126, "% i", 43);
  sprintf(test_str_126_126, "% i", 43);
  ck_assert_str_eq(test_str_126, test_str_126_126);
}
END_TEST

START_TEST(sprintf_test_127) {
  char test_str_127[50] = "";
  char test_str_127_127[50] = "";
  s21_sprintf(test_str_127, "% o", 0);
  sprintf(test_str_127_127, "% o", 0);
  ck_assert_str_eq(test_str_127, test_str_127_127);
}
END_TEST

START_TEST(sprintf_test_128) {
  char test_str_128[50] = "";
  char test_str_128_128[50] = "";
  s21_sprintf(test_str_128, "% o", 1);
  sprintf(test_str_128_128, "% o", 1);
  ck_assert_str_eq(test_str_128, test_str_128_128);
}
END_TEST

START_TEST(sprintf_test_129) {
  char test_str_129[50] = "";
  char test_str_129_129[50] = "";
  s21_sprintf(test_str_129, "% o", 10);
  sprintf(test_str_129_129, "% o", 10);
  ck_assert_str_eq(test_str_129, test_str_129_129);
}
END_TEST

START_TEST(sprintf_test_130) {
  char test_str_130[50] = "";
  char test_str_130_130[50] = "";
  s21_sprintf(test_str_130, "% o", 123456);
  sprintf(test_str_130_130, "% o", 123456);
  ck_assert_str_eq(test_str_130, test_str_130_130);
}
END_TEST

START_TEST(sprintf_test_131) {
  char test_str_131[50] = "";
  char test_str_131_131[50] = "";
  s21_sprintf(test_str_131, "% o", -67890123);
  sprintf(test_str_131_131, "% o", -67890123);
  ck_assert_str_eq(test_str_131, test_str_131_131);
}
END_TEST

START_TEST(sprintf_test_132) {
  char test_str_132[50] = "";
  char test_str_132_132[50] = "";
  s21_sprintf(test_str_132, "% o", 4343);
  sprintf(test_str_132_132, "% o", 4343);
  ck_assert_str_eq(test_str_132, test_str_132_132);
}
END_TEST

START_TEST(sprintf_test_133) {
  char test_str_133[50] = "";
  char test_str_133_133[50] = "";
  s21_sprintf(test_str_133, "% o", -1);
  sprintf(test_str_133_133, "% o", -1);
  ck_assert_str_eq(test_str_133, test_str_133_133);
}
END_TEST

START_TEST(sprintf_test_134) {
  char test_str_134[50] = "";
  char test_str_134_134[50] = "";
  s21_sprintf(test_str_134, "% o", -10);
  sprintf(test_str_134_134, "% o", -10);
  ck_assert_str_eq(test_str_134, test_str_134_134);
}
END_TEST

START_TEST(sprintf_test_135) {
  char test_str_135[50] = "";
  char test_str_135_135[50] = "";
  s21_sprintf(test_str_135, "% o", 43);
  sprintf(test_str_135_135, "% o", 43);
  ck_assert_str_eq(test_str_135, test_str_135_135);
}
END_TEST

START_TEST(sprintf_test_136) {
  char test_str_136[50] = "";
  char test_str_136_136[50] = "";
  s21_sprintf(test_str_136, "% u", 0);
  sprintf(test_str_136_136, "% u", 0);
  ck_assert_str_eq(test_str_136, test_str_136_136);
}
END_TEST

START_TEST(sprintf_test_137) {
  char test_str_137[50] = "";
  char test_str_137_137[50] = "";
  s21_sprintf(test_str_137, "% u", 1);
  sprintf(test_str_137_137, "% u", 1);
  ck_assert_str_eq(test_str_137, test_str_137_137);
}
END_TEST

START_TEST(sprintf_test_138) {
  char test_str_138[50] = "";
  char test_str_138_138[50] = "";
  s21_sprintf(test_str_138, "% u", 10);
  sprintf(test_str_138_138, "% u", 10);
  ck_assert_str_eq(test_str_138, test_str_138_138);
}
END_TEST

START_TEST(sprintf_test_139) {
  char test_str_139[50] = "";
  char test_str_139_139[50] = "";
  s21_sprintf(test_str_139, "% u", 123456);
  sprintf(test_str_139_139, "% u", 123456);
  ck_assert_str_eq(test_str_139, test_str_139_139);
}
END_TEST

START_TEST(sprintf_test_140) {
  char test_str_140[50] = "";
  char test_str_140_140[50] = "";
  s21_sprintf(test_str_140, "% u", -67890123);
  sprintf(test_str_140_140, "% u", -67890123);
  ck_assert_str_eq(test_str_140, test_str_140_140);
}
END_TEST

START_TEST(sprintf_test_141) {
  char test_str_141[50] = "";
  char test_str_141_141[50] = "";
  s21_sprintf(test_str_141, "% u", 4343);
  sprintf(test_str_141_141, "% u", 4343);
  ck_assert_str_eq(test_str_141, test_str_141_141);
}
END_TEST

START_TEST(sprintf_test_142) {
  char test_str_142[50] = "";
  char test_str_142_142[50] = "";
  s21_sprintf(test_str_142, "% u", -1);
  sprintf(test_str_142_142, "% u", -1);
  ck_assert_str_eq(test_str_142, test_str_142_142);
}
END_TEST

START_TEST(sprintf_test_143) {
  char test_str_143[50] = "";
  char test_str_143_143[50] = "";
  s21_sprintf(test_str_143, "% u", -10);
  sprintf(test_str_143_143, "% u", -10);
  ck_assert_str_eq(test_str_143, test_str_143_143);
}
END_TEST

START_TEST(sprintf_test_144) {
  char test_str_144[50] = "";
  char test_str_144_144[50] = "";
  s21_sprintf(test_str_144, "% u", 43);
  sprintf(test_str_144_144, "% u", 43);
  ck_assert_str_eq(test_str_144, test_str_144_144);
}
END_TEST

START_TEST(sprintf_test_145) {
  char test_str_145[50] = "";
  char test_str_145_145[50] = "";
  s21_sprintf(test_str_145, "% x", 0);
  sprintf(test_str_145_145, "% x", 0);
  ck_assert_str_eq(test_str_145, test_str_145_145);
}
END_TEST

START_TEST(sprintf_test_146) {
  char test_str_146[50] = "";
  char test_str_146_146[50] = "";
  s21_sprintf(test_str_146, "% x", 1);
  sprintf(test_str_146_146, "% x", 1);
  ck_assert_str_eq(test_str_146, test_str_146_146);
}
END_TEST

START_TEST(sprintf_test_147) {
  char test_str_147[50] = "";
  char test_str_147_147[50] = "";
  s21_sprintf(test_str_147, "% x", 10);
  sprintf(test_str_147_147, "% x", 10);
  ck_assert_str_eq(test_str_147, test_str_147_147);
}
END_TEST

START_TEST(sprintf_test_148) {
  char test_str_148[50] = "";
  char test_str_148_148[50] = "";
  s21_sprintf(test_str_148, "% x", 123456);
  sprintf(test_str_148_148, "% x", 123456);
  ck_assert_str_eq(test_str_148, test_str_148_148);
}
END_TEST

START_TEST(sprintf_test_149) {
  char test_str_149[50] = "";
  char test_str_149_149[50] = "";
  s21_sprintf(test_str_149, "% x", -67890123);
  sprintf(test_str_149_149, "% x", -67890123);
  ck_assert_str_eq(test_str_149, test_str_149_149);
}
END_TEST

START_TEST(sprintf_test_150) {
  char test_str_150[50] = "";
  char test_str_150_150[50] = "";
  s21_sprintf(test_str_150, "% x", 4343);
  sprintf(test_str_150_150, "% x", 4343);
  ck_assert_str_eq(test_str_150, test_str_150_150);
}
END_TEST

START_TEST(sprintf_test_151) {
  char test_str_151[50] = "";
  char test_str_151_151[50] = "";
  s21_sprintf(test_str_151, "% x", -1);
  sprintf(test_str_151_151, "% x", -1);
  ck_assert_str_eq(test_str_151, test_str_151_151);
}
END_TEST

START_TEST(sprintf_test_152) {
  char test_str_152[50] = "";
  char test_str_152_152[50] = "";
  s21_sprintf(test_str_152, "% x", -10);
  sprintf(test_str_152_152, "% x", -10);
  ck_assert_str_eq(test_str_152, test_str_152_152);
}
END_TEST

START_TEST(sprintf_test_153) {
  char test_str_153[50] = "";
  char test_str_153_153[50] = "";
  s21_sprintf(test_str_153, "% x", 43);
  sprintf(test_str_153_153, "% x", 43);
  ck_assert_str_eq(test_str_153, test_str_153_153);
}
END_TEST

START_TEST(sprintf_test_154) {
  char test_str_154[50] = "";
  char test_str_154_154[50] = "";
  s21_sprintf(test_str_154, "% X", 0);
  sprintf(test_str_154_154, "% X", 0);
  ck_assert_str_eq(test_str_154, test_str_154_154);
}
END_TEST

START_TEST(sprintf_test_155) {
  char test_str_155[50] = "";
  char test_str_155_155[50] = "";
  s21_sprintf(test_str_155, "% X", 1);
  sprintf(test_str_155_155, "% X", 1);
  ck_assert_str_eq(test_str_155, test_str_155_155);
}
END_TEST

START_TEST(sprintf_test_156) {
  char test_str_156[50] = "";
  char test_str_156_156[50] = "";
  s21_sprintf(test_str_156, "% X", 10);
  sprintf(test_str_156_156, "% X", 10);
  ck_assert_str_eq(test_str_156, test_str_156_156);
}
END_TEST

START_TEST(sprintf_test_157) {
  char test_str_157[50] = "";
  char test_str_157_157[50] = "";
  s21_sprintf(test_str_157, "% X", 123456);
  sprintf(test_str_157_157, "% X", 123456);
  ck_assert_str_eq(test_str_157, test_str_157_157);
}
END_TEST

START_TEST(sprintf_test_158) {
  char test_str_158[50] = "";
  char test_str_158_158[50] = "";
  s21_sprintf(test_str_158, "% X", -67890123);
  sprintf(test_str_158_158, "% X", -67890123);
  ck_assert_str_eq(test_str_158, test_str_158_158);
}
END_TEST

START_TEST(sprintf_test_159) {
  char test_str_159[50] = "";
  char test_str_159_159[50] = "";
  s21_sprintf(test_str_159, "% X", 4343);
  sprintf(test_str_159_159, "% X", 4343);
  ck_assert_str_eq(test_str_159, test_str_159_159);
}
END_TEST

START_TEST(sprintf_test_160) {
  char test_str_160[50] = "";
  char test_str_160_160[50] = "";
  s21_sprintf(test_str_160, "% X", -1);
  sprintf(test_str_160_160, "% X", -1);
  ck_assert_str_eq(test_str_160, test_str_160_160);
}
END_TEST

START_TEST(sprintf_test_161) {
  char test_str_161[50] = "";
  char test_str_161_161[50] = "";
  s21_sprintf(test_str_161, "% X", -10);
  sprintf(test_str_161_161, "% X", -10);
  ck_assert_str_eq(test_str_161, test_str_161_161);
}
END_TEST

START_TEST(sprintf_test_162) {
  char test_str_162[50] = "";
  char test_str_162_162[50] = "";
  s21_sprintf(test_str_162, "% X", 43);
  sprintf(test_str_162_162, "% X", 43);
  ck_assert_str_eq(test_str_162, test_str_162_162);
}
END_TEST

START_TEST(sprintf_test_163) {
  char test_str_163[50] = "";
  char test_str_163_163[50] = "";
  s21_sprintf(test_str_163, "%#d", 0);
  sprintf(test_str_163_163, "%#d", 0);
  ck_assert_str_eq(test_str_163, test_str_163_163);
}
END_TEST

START_TEST(sprintf_test_164) {
  char test_str_164[50] = "";
  char test_str_164_164[50] = "";
  s21_sprintf(test_str_164, "%#d", 1);
  sprintf(test_str_164_164, "%#d", 1);
  ck_assert_str_eq(test_str_164, test_str_164_164);
}
END_TEST

START_TEST(sprintf_test_165) {
  char test_str_165[50] = "";
  char test_str_165_165[50] = "";
  s21_sprintf(test_str_165, "%#d", 10);
  sprintf(test_str_165_165, "%#d", 10);
  ck_assert_str_eq(test_str_165, test_str_165_165);
}
END_TEST

START_TEST(sprintf_test_166) {
  char test_str_166[50] = "";
  char test_str_166_166[50] = "";
  s21_sprintf(test_str_166, "%#d", 123456);
  sprintf(test_str_166_166, "%#d", 123456);
  ck_assert_str_eq(test_str_166, test_str_166_166);
}
END_TEST

START_TEST(sprintf_test_167) {
  char test_str_167[50] = "";
  char test_str_167_167[50] = "";
  s21_sprintf(test_str_167, "%#d", -67890123);
  sprintf(test_str_167_167, "%#d", -67890123);
  ck_assert_str_eq(test_str_167, test_str_167_167);
}
END_TEST

START_TEST(sprintf_test_168) {
  char test_str_168[50] = "";
  char test_str_168_168[50] = "";
  s21_sprintf(test_str_168, "%#d", 4343);
  sprintf(test_str_168_168, "%#d", 4343);
  ck_assert_str_eq(test_str_168, test_str_168_168);
}
END_TEST

START_TEST(sprintf_test_169) {
  char test_str_169[50] = "";
  char test_str_169_169[50] = "";
  s21_sprintf(test_str_169, "%#d", -1);
  sprintf(test_str_169_169, "%#d", -1);
  ck_assert_str_eq(test_str_169, test_str_169_169);
}
END_TEST

START_TEST(sprintf_test_170) {
  char test_str_170[50] = "";
  char test_str_170_170[50] = "";
  s21_sprintf(test_str_170, "%#d", -10);
  sprintf(test_str_170_170, "%#d", -10);
  ck_assert_str_eq(test_str_170, test_str_170_170);
}
END_TEST

START_TEST(sprintf_test_171) {
  char test_str_171[50] = "";
  char test_str_171_171[50] = "";
  s21_sprintf(test_str_171, "%#d", 43);
  sprintf(test_str_171_171, "%#d", 43);
  ck_assert_str_eq(test_str_171, test_str_171_171);
}
END_TEST

START_TEST(sprintf_test_172) {
  char test_str_172[50] = "";
  char test_str_172_172[50] = "";
  s21_sprintf(test_str_172, "%#i", 0);
  sprintf(test_str_172_172, "%#i", 0);
  ck_assert_str_eq(test_str_172, test_str_172_172);
}
END_TEST

START_TEST(sprintf_test_173) {
  char test_str_173[50] = "";
  char test_str_173_173[50] = "";
  s21_sprintf(test_str_173, "%#i", 1);
  sprintf(test_str_173_173, "%#i", 1);
  ck_assert_str_eq(test_str_173, test_str_173_173);
}
END_TEST

START_TEST(sprintf_test_174) {
  char test_str_174[50] = "";
  char test_str_174_174[50] = "";
  s21_sprintf(test_str_174, "%#i", 10);
  sprintf(test_str_174_174, "%#i", 10);
  ck_assert_str_eq(test_str_174, test_str_174_174);
}
END_TEST

START_TEST(sprintf_test_175) {
  char test_str_175[50] = "";
  char test_str_175_175[50] = "";
  s21_sprintf(test_str_175, "%#i", 123456);
  sprintf(test_str_175_175, "%#i", 123456);
  ck_assert_str_eq(test_str_175, test_str_175_175);
}
END_TEST

START_TEST(sprintf_test_176) {
  char test_str_176[50] = "";
  char test_str_176_176[50] = "";
  s21_sprintf(test_str_176, "%#i", -67890123);
  sprintf(test_str_176_176, "%#i", -67890123);
  ck_assert_str_eq(test_str_176, test_str_176_176);
}
END_TEST

START_TEST(sprintf_test_177) {
  char test_str_177[50] = "";
  char test_str_177_177[50] = "";
  s21_sprintf(test_str_177, "%#i", 4343);
  sprintf(test_str_177_177, "%#i", 4343);
  ck_assert_str_eq(test_str_177, test_str_177_177);
}
END_TEST

START_TEST(sprintf_test_178) {
  char test_str_178[50] = "";
  char test_str_178_178[50] = "";
  s21_sprintf(test_str_178, "%#i", -1);
  sprintf(test_str_178_178, "%#i", -1);
  ck_assert_str_eq(test_str_178, test_str_178_178);
}
END_TEST

START_TEST(sprintf_test_179) {
  char test_str_179[50] = "";
  char test_str_179_179[50] = "";
  s21_sprintf(test_str_179, "%#i", -10);
  sprintf(test_str_179_179, "%#i", -10);
  ck_assert_str_eq(test_str_179, test_str_179_179);
}
END_TEST

START_TEST(sprintf_test_180) {
  char test_str_180[50] = "";
  char test_str_180_180[50] = "";
  s21_sprintf(test_str_180, "%#i", 43);
  sprintf(test_str_180_180, "%#i", 43);
  ck_assert_str_eq(test_str_180, test_str_180_180);
}
END_TEST

START_TEST(sprintf_test_181) {
  char test_str_181[50] = "";
  char test_str_181_181[50] = "";
  s21_sprintf(test_str_181, "%#o", 0);
  sprintf(test_str_181_181, "%#o", 0);
  ck_assert_str_eq(test_str_181, test_str_181_181);
}
END_TEST

START_TEST(sprintf_test_182) {
  char test_str_182[50] = "";
  char test_str_182_182[50] = "";
  s21_sprintf(test_str_182, "%#o", 1);
  sprintf(test_str_182_182, "%#o", 1);
  ck_assert_str_eq(test_str_182, test_str_182_182);
}
END_TEST

START_TEST(sprintf_test_183) {
  char test_str_183[50] = "";
  char test_str_183_183[50] = "";
  s21_sprintf(test_str_183, "%#o", 10);
  sprintf(test_str_183_183, "%#o", 10);
  ck_assert_str_eq(test_str_183, test_str_183_183);
}
END_TEST

START_TEST(sprintf_test_184) {
  char test_str_184[50] = "";
  char test_str_184_184[50] = "";
  s21_sprintf(test_str_184, "%#o", 123456);
  sprintf(test_str_184_184, "%#o", 123456);
  ck_assert_str_eq(test_str_184, test_str_184_184);
}
END_TEST

START_TEST(sprintf_test_185) {
  char test_str_185[50] = "";
  char test_str_185_185[50] = "";
  s21_sprintf(test_str_185, "%#o", -67890123);
  sprintf(test_str_185_185, "%#o", -67890123);
  ck_assert_str_eq(test_str_185, test_str_185_185);
}
END_TEST

START_TEST(sprintf_test_186) {
  char test_str_186[50] = "";
  char test_str_186_186[50] = "";
  s21_sprintf(test_str_186, "%#o", 4343);
  sprintf(test_str_186_186, "%#o", 4343);
  ck_assert_str_eq(test_str_186, test_str_186_186);
}
END_TEST

START_TEST(sprintf_test_187) {
  char test_str_187[50] = "";
  char test_str_187_187[50] = "";
  s21_sprintf(test_str_187, "%#o", -1);
  sprintf(test_str_187_187, "%#o", -1);
  ck_assert_str_eq(test_str_187, test_str_187_187);
}
END_TEST

START_TEST(sprintf_test_188) {
  char test_str_188[50] = "";
  char test_str_188_188[50] = "";
  s21_sprintf(test_str_188, "%#o", -10);
  sprintf(test_str_188_188, "%#o", -10);
  ck_assert_str_eq(test_str_188, test_str_188_188);
}
END_TEST

START_TEST(sprintf_test_189) {
  char test_str_189[50] = "";
  char test_str_189_189[50] = "";
  s21_sprintf(test_str_189, "%#o", 43);
  sprintf(test_str_189_189, "%#o", 43);
  ck_assert_str_eq(test_str_189, test_str_189_189);
}
END_TEST

START_TEST(sprintf_test_190) {
  char test_str_190[50] = "";
  char test_str_190_190[50] = "";
  s21_sprintf(test_str_190, "%#u", 0);
  sprintf(test_str_190_190, "%#u", 0);
  ck_assert_str_eq(test_str_190, test_str_190_190);
}
END_TEST

START_TEST(sprintf_test_191) {
  char test_str_191[50] = "";
  char test_str_191_191[50] = "";
  s21_sprintf(test_str_191, "%#u", 1);
  sprintf(test_str_191_191, "%#u", 1);
  ck_assert_str_eq(test_str_191, test_str_191_191);
}
END_TEST

START_TEST(sprintf_test_192) {
  char test_str_192[50] = "";
  char test_str_192_192[50] = "";
  s21_sprintf(test_str_192, "%#u", 10);
  sprintf(test_str_192_192, "%#u", 10);
  ck_assert_str_eq(test_str_192, test_str_192_192);
}
END_TEST

START_TEST(sprintf_test_193) {
  char test_str_193[50] = "";
  char test_str_193_193[50] = "";
  s21_sprintf(test_str_193, "%#u", 123456);
  sprintf(test_str_193_193, "%#u", 123456);
  ck_assert_str_eq(test_str_193, test_str_193_193);
}
END_TEST

START_TEST(sprintf_test_194) {
  char test_str_194[50] = "";
  char test_str_194_194[50] = "";
  s21_sprintf(test_str_194, "%#u", -67890123);
  sprintf(test_str_194_194, "%#u", -67890123);
  ck_assert_str_eq(test_str_194, test_str_194_194);
}
END_TEST

START_TEST(sprintf_test_195) {
  char test_str_195[50] = "";
  char test_str_195_195[50] = "";
  s21_sprintf(test_str_195, "%#u", 4343);
  sprintf(test_str_195_195, "%#u", 4343);
  ck_assert_str_eq(test_str_195, test_str_195_195);
}
END_TEST

START_TEST(sprintf_test_196) {
  char test_str_196[50] = "";
  char test_str_196_196[50] = "";
  s21_sprintf(test_str_196, "%#u", -1);
  sprintf(test_str_196_196, "%#u", -1);
  ck_assert_str_eq(test_str_196, test_str_196_196);
}
END_TEST

START_TEST(sprintf_test_197) {
  char test_str_197[50] = "";
  char test_str_197_197[50] = "";
  s21_sprintf(test_str_197, "%#u", -10);
  sprintf(test_str_197_197, "%#u", -10);
  ck_assert_str_eq(test_str_197, test_str_197_197);
}
END_TEST

START_TEST(sprintf_test_198) {
  char test_str_198[50] = "";
  char test_str_198_198[50] = "";
  s21_sprintf(test_str_198, "%#u", 43);
  sprintf(test_str_198_198, "%#u", 43);
  ck_assert_str_eq(test_str_198, test_str_198_198);
}
END_TEST

START_TEST(sprintf_test_199) {
  char test_str_199[50] = "";
  char test_str_199_199[50] = "";
  s21_sprintf(test_str_199, "%#x", 0);
  sprintf(test_str_199_199, "%#x", 0);
  ck_assert_str_eq(test_str_199, test_str_199_199);
}
END_TEST

START_TEST(sprintf_test_200) {
  char test_str_200[50] = "";
  char test_str_200_200[50] = "";
  s21_sprintf(test_str_200, "%#x", 1);
  sprintf(test_str_200_200, "%#x", 1);
  ck_assert_str_eq(test_str_200, test_str_200_200);
}
END_TEST

START_TEST(sprintf_test_201) {
  char test_str_201[50] = "";
  char test_str_201_201[50] = "";
  s21_sprintf(test_str_201, "%#x", 10);
  sprintf(test_str_201_201, "%#x", 10);
  ck_assert_str_eq(test_str_201, test_str_201_201);
}
END_TEST

START_TEST(sprintf_test_202) {
  char test_str_202[50] = "";
  char test_str_202_202[50] = "";
  s21_sprintf(test_str_202, "%#x", 123456);
  sprintf(test_str_202_202, "%#x", 123456);
  ck_assert_str_eq(test_str_202, test_str_202_202);
}
END_TEST

START_TEST(sprintf_test_203) {
  char test_str_203[50] = "";
  char test_str_203_203[50] = "";
  s21_sprintf(test_str_203, "%#x", -67890123);
  sprintf(test_str_203_203, "%#x", -67890123);
  ck_assert_str_eq(test_str_203, test_str_203_203);
}
END_TEST

START_TEST(sprintf_test_204) {
  char test_str_204[50] = "";
  char test_str_204_204[50] = "";
  s21_sprintf(test_str_204, "%#x", 4343);
  sprintf(test_str_204_204, "%#x", 4343);
  ck_assert_str_eq(test_str_204, test_str_204_204);
}
END_TEST

START_TEST(sprintf_test_205) {
  char test_str_205[50] = "";
  char test_str_205_205[50] = "";
  s21_sprintf(test_str_205, "%#x", -1);
  sprintf(test_str_205_205, "%#x", -1);
  ck_assert_str_eq(test_str_205, test_str_205_205);
}
END_TEST

START_TEST(sprintf_test_206) {
  char test_str_206[50] = "";
  char test_str_206_206[50] = "";
  s21_sprintf(test_str_206, "%#x", -10);
  sprintf(test_str_206_206, "%#x", -10);
  ck_assert_str_eq(test_str_206, test_str_206_206);
}
END_TEST

START_TEST(sprintf_test_207) {
  char test_str_207[50] = "";
  char test_str_207_207[50] = "";
  s21_sprintf(test_str_207, "%#x", 43);
  sprintf(test_str_207_207, "%#x", 43);
  ck_assert_str_eq(test_str_207, test_str_207_207);
}
END_TEST

START_TEST(sprintf_test_208) {
  char test_str_208[50] = "";
  char test_str_208_208[50] = "";
  s21_sprintf(test_str_208, "%#X", 0);
  sprintf(test_str_208_208, "%#X", 0);
  ck_assert_str_eq(test_str_208, test_str_208_208);
}
END_TEST

START_TEST(sprintf_test_209) {
  char test_str_209[50] = "";
  char test_str_209_209[50] = "";
  s21_sprintf(test_str_209, "%#X", 1);
  sprintf(test_str_209_209, "%#X", 1);
  ck_assert_str_eq(test_str_209, test_str_209_209);
}
END_TEST

START_TEST(sprintf_test_210) {
  char test_str_210[50] = "";
  char test_str_210_210[50] = "";
  s21_sprintf(test_str_210, "%#X", 10);
  sprintf(test_str_210_210, "%#X", 10);
  ck_assert_str_eq(test_str_210, test_str_210_210);
}
END_TEST

START_TEST(sprintf_test_211) {
  char test_str_211[50] = "";
  char test_str_211_211[50] = "";
  s21_sprintf(test_str_211, "%#X", 123456);
  sprintf(test_str_211_211, "%#X", 123456);
  ck_assert_str_eq(test_str_211, test_str_211_211);
}
END_TEST

START_TEST(sprintf_test_212) {
  char test_str_212[50] = "";
  char test_str_212_212[50] = "";
  s21_sprintf(test_str_212, "%#X", -67890123);
  sprintf(test_str_212_212, "%#X", -67890123);
  ck_assert_str_eq(test_str_212, test_str_212_212);
}
END_TEST

START_TEST(sprintf_test_213) {
  char test_str_213[50] = "";
  char test_str_213_213[50] = "";
  s21_sprintf(test_str_213, "%#X", 4343);
  sprintf(test_str_213_213, "%#X", 4343);
  ck_assert_str_eq(test_str_213, test_str_213_213);
}
END_TEST

START_TEST(sprintf_test_214) {
  char test_str_214[50] = "";
  char test_str_214_214[50] = "";
  s21_sprintf(test_str_214, "%#X", -1);
  sprintf(test_str_214_214, "%#X", -1);
  ck_assert_str_eq(test_str_214, test_str_214_214);
}
END_TEST

START_TEST(sprintf_test_215) {
  char test_str_215[50] = "";
  char test_str_215_215[50] = "";
  s21_sprintf(test_str_215, "%#X", -10);
  sprintf(test_str_215_215, "%#X", -10);
  ck_assert_str_eq(test_str_215, test_str_215_215);
}
END_TEST

START_TEST(sprintf_test_216) {
  char test_str_216[50] = "";
  char test_str_216_216[50] = "";
  s21_sprintf(test_str_216, "%#X", 43);
  sprintf(test_str_216_216, "%#X", 43);
  ck_assert_str_eq(test_str_216, test_str_216_216);
}
END_TEST

START_TEST(sprintf_test_217) {
  char test_str_217[50] = "";
  char test_str_217_217[50] = "";
  s21_sprintf(test_str_217, "%0d", 0);
  sprintf(test_str_217_217, "%0d", 0);
  ck_assert_str_eq(test_str_217, test_str_217_217);
}
END_TEST

START_TEST(sprintf_test_218) {
  char test_str_218[50] = "";
  char test_str_218_218[50] = "";
  s21_sprintf(test_str_218, "%0d", 1);
  sprintf(test_str_218_218, "%0d", 1);
  ck_assert_str_eq(test_str_218, test_str_218_218);
}
END_TEST

START_TEST(sprintf_test_219) {
  char test_str_219[50] = "";
  char test_str_219_219[50] = "";
  s21_sprintf(test_str_219, "%0d", 10);
  sprintf(test_str_219_219, "%0d", 10);
  ck_assert_str_eq(test_str_219, test_str_219_219);
}
END_TEST

START_TEST(sprintf_test_220) {
  char test_str_220[50] = "";
  char test_str_220_220[50] = "";
  s21_sprintf(test_str_220, "%0d", 123456);
  sprintf(test_str_220_220, "%0d", 123456);
  ck_assert_str_eq(test_str_220, test_str_220_220);
}
END_TEST

START_TEST(sprintf_test_221) {
  char test_str_221[50] = "";
  char test_str_221_221[50] = "";
  s21_sprintf(test_str_221, "%0d", -67890123);
  sprintf(test_str_221_221, "%0d", -67890123);
  ck_assert_str_eq(test_str_221, test_str_221_221);
}
END_TEST

START_TEST(sprintf_test_222) {
  char test_str_222[50] = "";
  char test_str_222_222[50] = "";
  s21_sprintf(test_str_222, "%0d", 4343);
  sprintf(test_str_222_222, "%0d", 4343);
  ck_assert_str_eq(test_str_222, test_str_222_222);
}
END_TEST

START_TEST(sprintf_test_223) {
  char test_str_223[50] = "";
  char test_str_223_223[50] = "";
  s21_sprintf(test_str_223, "%0d", -1);
  sprintf(test_str_223_223, "%0d", -1);
  ck_assert_str_eq(test_str_223, test_str_223_223);
}
END_TEST

START_TEST(sprintf_test_224) {
  char test_str_224[50] = "";
  char test_str_224_224[50] = "";
  s21_sprintf(test_str_224, "%0d", -10);
  sprintf(test_str_224_224, "%0d", -10);
  ck_assert_str_eq(test_str_224, test_str_224_224);
}
END_TEST

START_TEST(sprintf_test_225) {
  char test_str_225[50] = "";
  char test_str_225_225[50] = "";
  s21_sprintf(test_str_225, "%0d", 43);
  sprintf(test_str_225_225, "%0d", 43);
  ck_assert_str_eq(test_str_225, test_str_225_225);
}
END_TEST

START_TEST(sprintf_test_226) {
  char test_str_226[50] = "";
  char test_str_226_226[50] = "";
  s21_sprintf(test_str_226, "%0i", 0);
  sprintf(test_str_226_226, "%0i", 0);
  ck_assert_str_eq(test_str_226, test_str_226_226);
}
END_TEST

START_TEST(sprintf_test_227) {
  char test_str_227[50] = "";
  char test_str_227_227[50] = "";
  s21_sprintf(test_str_227, "%0i", 1);
  sprintf(test_str_227_227, "%0i", 1);
  ck_assert_str_eq(test_str_227, test_str_227_227);
}
END_TEST

START_TEST(sprintf_test_228) {
  char test_str_228[50] = "";
  char test_str_228_228[50] = "";
  s21_sprintf(test_str_228, "%0i", 10);
  sprintf(test_str_228_228, "%0i", 10);
  ck_assert_str_eq(test_str_228, test_str_228_228);
}
END_TEST

START_TEST(sprintf_test_229) {
  char test_str_229[50] = "";
  char test_str_229_229[50] = "";
  s21_sprintf(test_str_229, "%0i", 123456);
  sprintf(test_str_229_229, "%0i", 123456);
  ck_assert_str_eq(test_str_229, test_str_229_229);
}
END_TEST

START_TEST(sprintf_test_230) {
  char test_str_230[50] = "";
  char test_str_230_230[50] = "";
  s21_sprintf(test_str_230, "%0i", -67890123);
  sprintf(test_str_230_230, "%0i", -67890123);
  ck_assert_str_eq(test_str_230, test_str_230_230);
}
END_TEST

START_TEST(sprintf_test_231) {
  char test_str_231[50] = "";
  char test_str_231_231[50] = "";
  s21_sprintf(test_str_231, "%0i", 4343);
  sprintf(test_str_231_231, "%0i", 4343);
  ck_assert_str_eq(test_str_231, test_str_231_231);
}
END_TEST

START_TEST(sprintf_test_232) {
  char test_str_232[50] = "";
  char test_str_232_232[50] = "";
  s21_sprintf(test_str_232, "%0i", -1);
  sprintf(test_str_232_232, "%0i", -1);
  ck_assert_str_eq(test_str_232, test_str_232_232);
}
END_TEST

START_TEST(sprintf_test_233) {
  char test_str_233[50] = "";
  char test_str_233_233[50] = "";
  s21_sprintf(test_str_233, "%0i", -10);
  sprintf(test_str_233_233, "%0i", -10);
  ck_assert_str_eq(test_str_233, test_str_233_233);
}
END_TEST

START_TEST(sprintf_test_234) {
  char test_str_234[50] = "";
  char test_str_234_234[50] = "";
  s21_sprintf(test_str_234, "%0i", 43);
  sprintf(test_str_234_234, "%0i", 43);
  ck_assert_str_eq(test_str_234, test_str_234_234);
}
END_TEST

START_TEST(sprintf_test_235) {
  char test_str_235[50] = "";
  char test_str_235_235[50] = "";
  s21_sprintf(test_str_235, "%0o", 0);
  sprintf(test_str_235_235, "%0o", 0);
  ck_assert_str_eq(test_str_235, test_str_235_235);
}
END_TEST

START_TEST(sprintf_test_236) {
  char test_str_236[50] = "";
  char test_str_236_236[50] = "";
  s21_sprintf(test_str_236, "%0o", 1);
  sprintf(test_str_236_236, "%0o", 1);
  ck_assert_str_eq(test_str_236, test_str_236_236);
}
END_TEST

START_TEST(sprintf_test_237) {
  char test_str_237[50] = "";
  char test_str_237_237[50] = "";
  s21_sprintf(test_str_237, "%0o", 10);
  sprintf(test_str_237_237, "%0o", 10);
  ck_assert_str_eq(test_str_237, test_str_237_237);
}
END_TEST

START_TEST(sprintf_test_238) {
  char test_str_238[50] = "";
  char test_str_238_238[50] = "";
  s21_sprintf(test_str_238, "%0o", 123456);
  sprintf(test_str_238_238, "%0o", 123456);
  ck_assert_str_eq(test_str_238, test_str_238_238);
}
END_TEST

START_TEST(sprintf_test_239) {
  char test_str_239[50] = "";
  char test_str_239_239[50] = "";
  s21_sprintf(test_str_239, "%0o", -67890123);
  sprintf(test_str_239_239, "%0o", -67890123);
  ck_assert_str_eq(test_str_239, test_str_239_239);
}
END_TEST

START_TEST(sprintf_test_240) {
  char test_str_240[50] = "";
  char test_str_240_240[50] = "";
  s21_sprintf(test_str_240, "%0o", 4343);
  sprintf(test_str_240_240, "%0o", 4343);
  ck_assert_str_eq(test_str_240, test_str_240_240);
}
END_TEST

START_TEST(sprintf_test_241) {
  char test_str_241[50] = "";
  char test_str_241_241[50] = "";
  s21_sprintf(test_str_241, "%0o", -1);
  sprintf(test_str_241_241, "%0o", -1);
  ck_assert_str_eq(test_str_241, test_str_241_241);
}
END_TEST

START_TEST(sprintf_test_242) {
  char test_str_242[50] = "";
  char test_str_242_242[50] = "";
  s21_sprintf(test_str_242, "%0o", -10);
  sprintf(test_str_242_242, "%0o", -10);
  ck_assert_str_eq(test_str_242, test_str_242_242);
}
END_TEST

START_TEST(sprintf_test_243) {
  char test_str_243[50] = "";
  char test_str_243_243[50] = "";
  s21_sprintf(test_str_243, "%0o", 43);
  sprintf(test_str_243_243, "%0o", 43);
  ck_assert_str_eq(test_str_243, test_str_243_243);
}
END_TEST

START_TEST(sprintf_test_244) {
  char test_str_244[50] = "";
  char test_str_244_244[50] = "";
  s21_sprintf(test_str_244, "%0u", 0);
  sprintf(test_str_244_244, "%0u", 0);
  ck_assert_str_eq(test_str_244, test_str_244_244);
}
END_TEST

START_TEST(sprintf_test_245) {
  char test_str_245[50] = "";
  char test_str_245_245[50] = "";
  s21_sprintf(test_str_245, "%0u", 1);
  sprintf(test_str_245_245, "%0u", 1);
  ck_assert_str_eq(test_str_245, test_str_245_245);
}
END_TEST

START_TEST(sprintf_test_246) {
  char test_str_246[50] = "";
  char test_str_246_246[50] = "";
  s21_sprintf(test_str_246, "%0u", 10);
  sprintf(test_str_246_246, "%0u", 10);
  ck_assert_str_eq(test_str_246, test_str_246_246);
}
END_TEST

START_TEST(sprintf_test_247) {
  char test_str_247[50] = "";
  char test_str_247_247[50] = "";
  s21_sprintf(test_str_247, "%0u", 123456);
  sprintf(test_str_247_247, "%0u", 123456);
  ck_assert_str_eq(test_str_247, test_str_247_247);
}
END_TEST

START_TEST(sprintf_test_248) {
  char test_str_248[50] = "";
  char test_str_248_248[50] = "";
  s21_sprintf(test_str_248, "%0u", -67890123);
  sprintf(test_str_248_248, "%0u", -67890123);
  ck_assert_str_eq(test_str_248, test_str_248_248);
}
END_TEST

START_TEST(sprintf_test_249) {
  char test_str_249[50] = "";
  char test_str_249_249[50] = "";
  s21_sprintf(test_str_249, "%0u", 4343);
  sprintf(test_str_249_249, "%0u", 4343);
  ck_assert_str_eq(test_str_249, test_str_249_249);
}
END_TEST

START_TEST(sprintf_test_250) {
  char test_str_250[50] = "";
  char test_str_250_250[50] = "";
  s21_sprintf(test_str_250, "%0u", -1);
  sprintf(test_str_250_250, "%0u", -1);
  ck_assert_str_eq(test_str_250, test_str_250_250);
}
END_TEST

START_TEST(sprintf_test_251) {
  char test_str_251[50] = "";
  char test_str_251_251[50] = "";
  s21_sprintf(test_str_251, "%0u", -10);
  sprintf(test_str_251_251, "%0u", -10);
  ck_assert_str_eq(test_str_251, test_str_251_251);
}
END_TEST

START_TEST(sprintf_test_252) {
  char test_str_252[50] = "";
  char test_str_252_252[50] = "";
  s21_sprintf(test_str_252, "%0u", 43);
  sprintf(test_str_252_252, "%0u", 43);
  ck_assert_str_eq(test_str_252, test_str_252_252);
}
END_TEST

START_TEST(sprintf_test_253) {
  char test_str_253[50] = "";
  char test_str_253_253[50] = "";
  s21_sprintf(test_str_253, "%0x", 0);
  sprintf(test_str_253_253, "%0x", 0);
  ck_assert_str_eq(test_str_253, test_str_253_253);
}
END_TEST

START_TEST(sprintf_test_254) {
  char test_str_254[50] = "";
  char test_str_254_254[50] = "";
  s21_sprintf(test_str_254, "%0x", 1);
  sprintf(test_str_254_254, "%0x", 1);
  ck_assert_str_eq(test_str_254, test_str_254_254);
}
END_TEST

START_TEST(sprintf_test_255) {
  char test_str_255[50] = "";
  char test_str_255_255[50] = "";
  s21_sprintf(test_str_255, "%0x", 10);
  sprintf(test_str_255_255, "%0x", 10);
  ck_assert_str_eq(test_str_255, test_str_255_255);
}
END_TEST

START_TEST(sprintf_test_256) {
  char test_str_256[50] = "";
  char test_str_256_256[50] = "";
  s21_sprintf(test_str_256, "%0x", 123456);
  sprintf(test_str_256_256, "%0x", 123456);
  ck_assert_str_eq(test_str_256, test_str_256_256);
}
END_TEST

START_TEST(sprintf_test_257) {
  char test_str_257[50] = "";
  char test_str_257_257[50] = "";
  s21_sprintf(test_str_257, "%0x", -67890123);
  sprintf(test_str_257_257, "%0x", -67890123);
  ck_assert_str_eq(test_str_257, test_str_257_257);
}
END_TEST

START_TEST(sprintf_test_258) {
  char test_str_258[50] = "";
  char test_str_258_258[50] = "";
  s21_sprintf(test_str_258, "%0x", 4343);
  sprintf(test_str_258_258, "%0x", 4343);
  ck_assert_str_eq(test_str_258, test_str_258_258);
}
END_TEST

START_TEST(sprintf_test_259) {
  char test_str_259[50] = "";
  char test_str_259_259[50] = "";
  s21_sprintf(test_str_259, "%0x", -1);
  sprintf(test_str_259_259, "%0x", -1);
  ck_assert_str_eq(test_str_259, test_str_259_259);
}
END_TEST

START_TEST(sprintf_test_260) {
  char test_str_260[50] = "";
  char test_str_260_260[50] = "";
  s21_sprintf(test_str_260, "%0x", -10);
  sprintf(test_str_260_260, "%0x", -10);
  ck_assert_str_eq(test_str_260, test_str_260_260);
}
END_TEST

START_TEST(sprintf_test_261) {
  char test_str_261[50] = "";
  char test_str_261_261[50] = "";
  s21_sprintf(test_str_261, "%0x", 43);
  sprintf(test_str_261_261, "%0x", 43);
  ck_assert_str_eq(test_str_261, test_str_261_261);
}
END_TEST

START_TEST(sprintf_test_262) {
  char test_str_262[50] = "";
  char test_str_262_262[50] = "";
  s21_sprintf(test_str_262, "%0X", 0);
  sprintf(test_str_262_262, "%0X", 0);
  ck_assert_str_eq(test_str_262, test_str_262_262);
}
END_TEST

START_TEST(sprintf_test_263) {
  char test_str_263[50] = "";
  char test_str_263_263[50] = "";
  s21_sprintf(test_str_263, "%0X", 1);
  sprintf(test_str_263_263, "%0X", 1);
  ck_assert_str_eq(test_str_263, test_str_263_263);
}
END_TEST

START_TEST(sprintf_test_264) {
  char test_str_264[50] = "";
  char test_str_264_264[50] = "";
  s21_sprintf(test_str_264, "%0X", 10);
  sprintf(test_str_264_264, "%0X", 10);
  ck_assert_str_eq(test_str_264, test_str_264_264);
}
END_TEST

START_TEST(sprintf_test_265) {
  char test_str_265[50] = "";
  char test_str_265_265[50] = "";
  s21_sprintf(test_str_265, "%0X", 123456);
  sprintf(test_str_265_265, "%0X", 123456);
  ck_assert_str_eq(test_str_265, test_str_265_265);
}
END_TEST

START_TEST(sprintf_test_266) {
  char test_str_266[50] = "";
  char test_str_266_266[50] = "";
  s21_sprintf(test_str_266, "%0X", -67890123);
  sprintf(test_str_266_266, "%0X", -67890123);
  ck_assert_str_eq(test_str_266, test_str_266_266);
}
END_TEST

START_TEST(sprintf_test_267) {
  char test_str_267[50] = "";
  char test_str_267_267[50] = "";
  s21_sprintf(test_str_267, "%0X", 4343);
  sprintf(test_str_267_267, "%0X", 4343);
  ck_assert_str_eq(test_str_267, test_str_267_267);
}
END_TEST

START_TEST(sprintf_test_268) {
  char test_str_268[50] = "";
  char test_str_268_268[50] = "";
  s21_sprintf(test_str_268, "%0X", -1);
  sprintf(test_str_268_268, "%0X", -1);
  ck_assert_str_eq(test_str_268, test_str_268_268);
}
END_TEST

START_TEST(sprintf_test_269) {
  char test_str_269[50] = "";
  char test_str_269_269[50] = "";
  s21_sprintf(test_str_269, "%0X", -10);
  sprintf(test_str_269_269, "%0X", -10);
  ck_assert_str_eq(test_str_269, test_str_269_269);
}
END_TEST

START_TEST(sprintf_test_270) {
  char test_str_270[50] = "";
  char test_str_270_270[50] = "";
  s21_sprintf(test_str_270, "%0X", 43);
  sprintf(test_str_270_270, "%0X", 43);
  ck_assert_str_eq(test_str_270, test_str_270_270);
}
END_TEST

START_TEST(sprintf_test_271) {
  char test_str_271[50] = "";
  char test_str_271_271[50] = "";
  s21_sprintf(test_str_271, "%0d", 0);
  sprintf(test_str_271_271, "%0d", 0);
  ck_assert_str_eq(test_str_271, test_str_271_271);
}
END_TEST

START_TEST(sprintf_test_272) {
  char test_str_272[50] = "";
  char test_str_272_272[50] = "";
  s21_sprintf(test_str_272, "%0d", 1);
  sprintf(test_str_272_272, "%0d", 1);
  ck_assert_str_eq(test_str_272, test_str_272_272);
}
END_TEST

START_TEST(sprintf_test_273) {
  char test_str_273[50] = "";
  char test_str_273_273[50] = "";
  s21_sprintf(test_str_273, "%0d", 10);
  sprintf(test_str_273_273, "%0d", 10);
  ck_assert_str_eq(test_str_273, test_str_273_273);
}
END_TEST

START_TEST(sprintf_test_274) {
  char test_str_274[50] = "";
  char test_str_274_274[50] = "";
  s21_sprintf(test_str_274, "%0d", 123456);
  sprintf(test_str_274_274, "%0d", 123456);
  ck_assert_str_eq(test_str_274, test_str_274_274);
}
END_TEST

START_TEST(sprintf_test_275) {
  char test_str_275[50] = "";
  char test_str_275_275[50] = "";
  s21_sprintf(test_str_275, "%0d", -67890123);
  sprintf(test_str_275_275, "%0d", -67890123);
  ck_assert_str_eq(test_str_275, test_str_275_275);
}
END_TEST

START_TEST(sprintf_test_276) {
  char test_str_276[50] = "";
  char test_str_276_276[50] = "";
  s21_sprintf(test_str_276, "%0d", 4343);
  sprintf(test_str_276_276, "%0d", 4343);
  ck_assert_str_eq(test_str_276, test_str_276_276);
}
END_TEST

START_TEST(sprintf_test_277) {
  char test_str_277[50] = "";
  char test_str_277_277[50] = "";
  s21_sprintf(test_str_277, "%0d", -1);
  sprintf(test_str_277_277, "%0d", -1);
  ck_assert_str_eq(test_str_277, test_str_277_277);
}
END_TEST

START_TEST(sprintf_test_278) {
  char test_str_278[50] = "";
  char test_str_278_278[50] = "";
  s21_sprintf(test_str_278, "%0d", -10);
  sprintf(test_str_278_278, "%0d", -10);
  ck_assert_str_eq(test_str_278, test_str_278_278);
}
END_TEST

START_TEST(sprintf_test_279) {
  char test_str_279[50] = "";
  char test_str_279_279[50] = "";
  s21_sprintf(test_str_279, "%0d", 43);
  sprintf(test_str_279_279, "%0d", 43);
  ck_assert_str_eq(test_str_279, test_str_279_279);
}
END_TEST

START_TEST(sprintf_test_280) {
  char test_str_280[50] = "";
  char test_str_280_280[50] = "";
  s21_sprintf(test_str_280, "%0i", 0);
  sprintf(test_str_280_280, "%0i", 0);
  ck_assert_str_eq(test_str_280, test_str_280_280);
}
END_TEST

START_TEST(sprintf_test_281) {
  char test_str_281[50] = "";
  char test_str_281_281[50] = "";
  s21_sprintf(test_str_281, "%0i", 1);
  sprintf(test_str_281_281, "%0i", 1);
  ck_assert_str_eq(test_str_281, test_str_281_281);
}
END_TEST

START_TEST(sprintf_test_282) {
  char test_str_282[50] = "";
  char test_str_282_282[50] = "";
  s21_sprintf(test_str_282, "%0i", 10);
  sprintf(test_str_282_282, "%0i", 10);
  ck_assert_str_eq(test_str_282, test_str_282_282);
}
END_TEST

START_TEST(sprintf_test_283) {
  char test_str_283[50] = "";
  char test_str_283_283[50] = "";
  s21_sprintf(test_str_283, "%0i", 123456);
  sprintf(test_str_283_283, "%0i", 123456);
  ck_assert_str_eq(test_str_283, test_str_283_283);
}
END_TEST

START_TEST(sprintf_test_284) {
  char test_str_284[50] = "";
  char test_str_284_284[50] = "";
  s21_sprintf(test_str_284, "%0i", -67890123);
  sprintf(test_str_284_284, "%0i", -67890123);
  ck_assert_str_eq(test_str_284, test_str_284_284);
}
END_TEST

START_TEST(sprintf_test_285) {
  char test_str_285[50] = "";
  char test_str_285_285[50] = "";
  s21_sprintf(test_str_285, "%0i", 4343);
  sprintf(test_str_285_285, "%0i", 4343);
  ck_assert_str_eq(test_str_285, test_str_285_285);
}
END_TEST

START_TEST(sprintf_test_286) {
  char test_str_286[50] = "";
  char test_str_286_286[50] = "";
  s21_sprintf(test_str_286, "%0i", -1);
  sprintf(test_str_286_286, "%0i", -1);
  ck_assert_str_eq(test_str_286, test_str_286_286);
}
END_TEST

START_TEST(sprintf_test_287) {
  char test_str_287[50] = "";
  char test_str_287_287[50] = "";
  s21_sprintf(test_str_287, "%0i", -10);
  sprintf(test_str_287_287, "%0i", -10);
  ck_assert_str_eq(test_str_287, test_str_287_287);
}
END_TEST

START_TEST(sprintf_test_288) {
  char test_str_288[50] = "";
  char test_str_288_288[50] = "";
  s21_sprintf(test_str_288, "%0i", 43);
  sprintf(test_str_288_288, "%0i", 43);
  ck_assert_str_eq(test_str_288, test_str_288_288);
}
END_TEST

START_TEST(sprintf_test_289) {
  char test_str_289[50] = "";
  char test_str_289_289[50] = "";
  s21_sprintf(test_str_289, "%0o", 0);
  sprintf(test_str_289_289, "%0o", 0);
  ck_assert_str_eq(test_str_289, test_str_289_289);
}
END_TEST

START_TEST(sprintf_test_290) {
  char test_str_290[50] = "";
  char test_str_290_290[50] = "";
  s21_sprintf(test_str_290, "%0o", 1);
  sprintf(test_str_290_290, "%0o", 1);
  ck_assert_str_eq(test_str_290, test_str_290_290);
}
END_TEST

START_TEST(sprintf_test_291) {
  char test_str_291[50] = "";
  char test_str_291_291[50] = "";
  s21_sprintf(test_str_291, "%0o", 10);
  sprintf(test_str_291_291, "%0o", 10);
  ck_assert_str_eq(test_str_291, test_str_291_291);
}
END_TEST

START_TEST(sprintf_test_292) {
  char test_str_292[50] = "";
  char test_str_292_292[50] = "";
  s21_sprintf(test_str_292, "%0o", 123456);
  sprintf(test_str_292_292, "%0o", 123456);
  ck_assert_str_eq(test_str_292, test_str_292_292);
}
END_TEST

START_TEST(sprintf_test_293) {
  char test_str_293[50] = "";
  char test_str_293_293[50] = "";
  s21_sprintf(test_str_293, "%0o", -67890123);
  sprintf(test_str_293_293, "%0o", -67890123);
  ck_assert_str_eq(test_str_293, test_str_293_293);
}
END_TEST

START_TEST(sprintf_test_294) {
  char test_str_294[50] = "";
  char test_str_294_294[50] = "";
  s21_sprintf(test_str_294, "%0o", 4343);
  sprintf(test_str_294_294, "%0o", 4343);
  ck_assert_str_eq(test_str_294, test_str_294_294);
}
END_TEST

START_TEST(sprintf_test_295) {
  char test_str_295[50] = "";
  char test_str_295_295[50] = "";
  s21_sprintf(test_str_295, "%0o", -1);
  sprintf(test_str_295_295, "%0o", -1);
  ck_assert_str_eq(test_str_295, test_str_295_295);
}
END_TEST

START_TEST(sprintf_test_296) {
  char test_str_296[50] = "";
  char test_str_296_296[50] = "";
  s21_sprintf(test_str_296, "%0o", -10);
  sprintf(test_str_296_296, "%0o", -10);
  ck_assert_str_eq(test_str_296, test_str_296_296);
}
END_TEST

START_TEST(sprintf_test_297) {
  char test_str_297[50] = "";
  char test_str_297_297[50] = "";
  s21_sprintf(test_str_297, "%0o", 43);
  sprintf(test_str_297_297, "%0o", 43);
  ck_assert_str_eq(test_str_297, test_str_297_297);
}
END_TEST

START_TEST(sprintf_test_298) {
  char test_str_298[50] = "";
  char test_str_298_298[50] = "";
  s21_sprintf(test_str_298, "%0u", 0);
  sprintf(test_str_298_298, "%0u", 0);
  ck_assert_str_eq(test_str_298, test_str_298_298);
}
END_TEST

START_TEST(sprintf_test_299) {
  char test_str_299[50] = "";
  char test_str_299_299[50] = "";
  s21_sprintf(test_str_299, "%0u", 1);
  sprintf(test_str_299_299, "%0u", 1);
  ck_assert_str_eq(test_str_299, test_str_299_299);
}
END_TEST

START_TEST(sprintf_test_300) {
  char test_str_300[50] = "";
  char test_str_300_300[50] = "";
  s21_sprintf(test_str_300, "%0u", 10);
  sprintf(test_str_300_300, "%0u", 10);
  ck_assert_str_eq(test_str_300, test_str_300_300);
}
END_TEST

START_TEST(sprintf_test_301) {
  char test_str_301[50] = "";
  char test_str_301_301[50] = "";
  s21_sprintf(test_str_301, "%0u", 123456);
  sprintf(test_str_301_301, "%0u", 123456);
  ck_assert_str_eq(test_str_301, test_str_301_301);
}
END_TEST

START_TEST(sprintf_test_302) {
  char test_str_302[50] = "";
  char test_str_302_302[50] = "";
  s21_sprintf(test_str_302, "%0u", -67890123);
  sprintf(test_str_302_302, "%0u", -67890123);
  ck_assert_str_eq(test_str_302, test_str_302_302);
}
END_TEST

START_TEST(sprintf_test_303) {
  char test_str_303[50] = "";
  char test_str_303_303[50] = "";
  s21_sprintf(test_str_303, "%0u", 4343);
  sprintf(test_str_303_303, "%0u", 4343);
  ck_assert_str_eq(test_str_303, test_str_303_303);
}
END_TEST

START_TEST(sprintf_test_304) {
  char test_str_304[50] = "";
  char test_str_304_304[50] = "";
  s21_sprintf(test_str_304, "%0u", -1);
  sprintf(test_str_304_304, "%0u", -1);
  ck_assert_str_eq(test_str_304, test_str_304_304);
}
END_TEST

START_TEST(sprintf_test_305) {
  char test_str_305[50] = "";
  char test_str_305_305[50] = "";
  s21_sprintf(test_str_305, "%0u", -10);
  sprintf(test_str_305_305, "%0u", -10);
  ck_assert_str_eq(test_str_305, test_str_305_305);
}
END_TEST

START_TEST(sprintf_test_306) {
  char test_str_306[50] = "";
  char test_str_306_306[50] = "";
  s21_sprintf(test_str_306, "%0u", 43);
  sprintf(test_str_306_306, "%0u", 43);
  ck_assert_str_eq(test_str_306, test_str_306_306);
}
END_TEST

START_TEST(sprintf_test_307) {
  char test_str_307[50] = "";
  char test_str_307_307[50] = "";
  s21_sprintf(test_str_307, "%0x", 0);
  sprintf(test_str_307_307, "%0x", 0);
  ck_assert_str_eq(test_str_307, test_str_307_307);
}
END_TEST

START_TEST(sprintf_test_308) {
  char test_str_308[50] = "";
  char test_str_308_308[50] = "";
  s21_sprintf(test_str_308, "%0x", 1);
  sprintf(test_str_308_308, "%0x", 1);
  ck_assert_str_eq(test_str_308, test_str_308_308);
}
END_TEST

START_TEST(sprintf_test_309) {
  char test_str_309[50] = "";
  char test_str_309_309[50] = "";
  s21_sprintf(test_str_309, "%0x", 10);
  sprintf(test_str_309_309, "%0x", 10);
  ck_assert_str_eq(test_str_309, test_str_309_309);
}
END_TEST

START_TEST(sprintf_test_310) {
  char test_str_310[50] = "";
  char test_str_310_310[50] = "";
  s21_sprintf(test_str_310, "%0x", 123456);
  sprintf(test_str_310_310, "%0x", 123456);
  ck_assert_str_eq(test_str_310, test_str_310_310);
}
END_TEST

START_TEST(sprintf_test_311) {
  char test_str_311[50] = "";
  char test_str_311_311[50] = "";
  s21_sprintf(test_str_311, "%0x", -67890123);
  sprintf(test_str_311_311, "%0x", -67890123);
  ck_assert_str_eq(test_str_311, test_str_311_311);
}
END_TEST

START_TEST(sprintf_test_312) {
  char test_str_312[50] = "";
  char test_str_312_312[50] = "";
  s21_sprintf(test_str_312, "%0x", 4343);
  sprintf(test_str_312_312, "%0x", 4343);
  ck_assert_str_eq(test_str_312, test_str_312_312);
}
END_TEST

START_TEST(sprintf_test_313) {
  char test_str_313[50] = "";
  char test_str_313_313[50] = "";
  s21_sprintf(test_str_313, "%0x", -1);
  sprintf(test_str_313_313, "%0x", -1);
  ck_assert_str_eq(test_str_313, test_str_313_313);
}
END_TEST

START_TEST(sprintf_test_314) {
  char test_str_314[50] = "";
  char test_str_314_314[50] = "";
  s21_sprintf(test_str_314, "%0x", -10);
  sprintf(test_str_314_314, "%0x", -10);
  ck_assert_str_eq(test_str_314, test_str_314_314);
}
END_TEST

START_TEST(sprintf_test_315) {
  char test_str_315[50] = "";
  char test_str_315_315[50] = "";
  s21_sprintf(test_str_315, "%0x", 43);
  sprintf(test_str_315_315, "%0x", 43);
  ck_assert_str_eq(test_str_315, test_str_315_315);
}
END_TEST

START_TEST(sprintf_test_316) {
  char test_str_316[50] = "";
  char test_str_316_316[50] = "";
  s21_sprintf(test_str_316, "%0X", 0);
  sprintf(test_str_316_316, "%0X", 0);
  ck_assert_str_eq(test_str_316, test_str_316_316);
}
END_TEST

START_TEST(sprintf_test_317) {
  char test_str_317[50] = "";
  char test_str_317_317[50] = "";
  s21_sprintf(test_str_317, "%0X", 1);
  sprintf(test_str_317_317, "%0X", 1);
  ck_assert_str_eq(test_str_317, test_str_317_317);
}
END_TEST

START_TEST(sprintf_test_318) {
  char test_str_318[50] = "";
  char test_str_318_318[50] = "";
  s21_sprintf(test_str_318, "%0X", 10);
  sprintf(test_str_318_318, "%0X", 10);
  ck_assert_str_eq(test_str_318, test_str_318_318);
}
END_TEST

START_TEST(sprintf_test_319) {
  char test_str_319[50] = "";
  char test_str_319_319[50] = "";
  s21_sprintf(test_str_319, "%0X", 123456);
  sprintf(test_str_319_319, "%0X", 123456);
  ck_assert_str_eq(test_str_319, test_str_319_319);
}
END_TEST

START_TEST(sprintf_test_320) {
  char test_str_320[50] = "";
  char test_str_320_320[50] = "";
  s21_sprintf(test_str_320, "%0X", -67890123);
  sprintf(test_str_320_320, "%0X", -67890123);
  ck_assert_str_eq(test_str_320, test_str_320_320);
}
END_TEST

START_TEST(sprintf_test_321) {
  char test_str_321[50] = "";
  char test_str_321_321[50] = "";
  s21_sprintf(test_str_321, "%0X", 4343);
  sprintf(test_str_321_321, "%0X", 4343);
  ck_assert_str_eq(test_str_321, test_str_321_321);
}
END_TEST

START_TEST(sprintf_test_322) {
  char test_str_322[50] = "";
  char test_str_322_322[50] = "";
  s21_sprintf(test_str_322, "%0X", -1);
  sprintf(test_str_322_322, "%0X", -1);
  ck_assert_str_eq(test_str_322, test_str_322_322);
}
END_TEST

START_TEST(sprintf_test_323) {
  char test_str_323[50] = "";
  char test_str_323_323[50] = "";
  s21_sprintf(test_str_323, "%0X", -10);
  sprintf(test_str_323_323, "%0X", -10);
  ck_assert_str_eq(test_str_323, test_str_323_323);
}
END_TEST

START_TEST(sprintf_test_324) {
  char test_str_324[50] = "";
  char test_str_324_324[50] = "";
  s21_sprintf(test_str_324, "%0X", 43);
  sprintf(test_str_324_324, "%0X", 43);
  ck_assert_str_eq(test_str_324, test_str_324_324);
}
END_TEST

START_TEST(sprintf_test_325) {
  char test_str_325[50] = "";
  char test_str_325_325[50] = "";
  s21_sprintf(test_str_325, "%10d", 0);
  sprintf(test_str_325_325, "%10d", 0);
  ck_assert_str_eq(test_str_325, test_str_325_325);
}
END_TEST

START_TEST(sprintf_test_326) {
  char test_str_326[50] = "";
  char test_str_326_326[50] = "";
  s21_sprintf(test_str_326, "%10d", 1);
  sprintf(test_str_326_326, "%10d", 1);
  ck_assert_str_eq(test_str_326, test_str_326_326);
}
END_TEST

START_TEST(sprintf_test_327) {
  char test_str_327[50] = "";
  char test_str_327_327[50] = "";
  s21_sprintf(test_str_327, "%10d", 10);
  sprintf(test_str_327_327, "%10d", 10);
  ck_assert_str_eq(test_str_327, test_str_327_327);
}
END_TEST

START_TEST(sprintf_test_328) {
  char test_str_328[50] = "";
  char test_str_328_328[50] = "";
  s21_sprintf(test_str_328, "%10d", 123456);
  sprintf(test_str_328_328, "%10d", 123456);
  ck_assert_str_eq(test_str_328, test_str_328_328);
}
END_TEST

START_TEST(sprintf_test_329) {
  char test_str_329[50] = "";
  char test_str_329_329[50] = "";
  s21_sprintf(test_str_329, "%10d", -67890123);
  sprintf(test_str_329_329, "%10d", -67890123);
  ck_assert_str_eq(test_str_329, test_str_329_329);
}
END_TEST

START_TEST(sprintf_test_330) {
  char test_str_330[50] = "";
  char test_str_330_330[50] = "";
  s21_sprintf(test_str_330, "%10d", 4343);
  sprintf(test_str_330_330, "%10d", 4343);
  ck_assert_str_eq(test_str_330, test_str_330_330);
}
END_TEST

START_TEST(sprintf_test_331) {
  char test_str_331[50] = "";
  char test_str_331_331[50] = "";
  s21_sprintf(test_str_331, "%10d", -1);
  sprintf(test_str_331_331, "%10d", -1);
  ck_assert_str_eq(test_str_331, test_str_331_331);
}
END_TEST

START_TEST(sprintf_test_332) {
  char test_str_332[50] = "";
  char test_str_332_332[50] = "";
  s21_sprintf(test_str_332, "%10d", -10);
  sprintf(test_str_332_332, "%10d", -10);
  ck_assert_str_eq(test_str_332, test_str_332_332);
}
END_TEST

START_TEST(sprintf_test_333) {
  char test_str_333[50] = "";
  char test_str_333_333[50] = "";
  s21_sprintf(test_str_333, "%10d", 43);
  sprintf(test_str_333_333, "%10d", 43);
  ck_assert_str_eq(test_str_333, test_str_333_333);
}
END_TEST

START_TEST(sprintf_test_334) {
  char test_str_334[50] = "";
  char test_str_334_334[50] = "";
  s21_sprintf(test_str_334, "%10i", 0);
  sprintf(test_str_334_334, "%10i", 0);
  ck_assert_str_eq(test_str_334, test_str_334_334);
}
END_TEST

START_TEST(sprintf_test_335) {
  char test_str_335[50] = "";
  char test_str_335_335[50] = "";
  s21_sprintf(test_str_335, "%10i", 1);
  sprintf(test_str_335_335, "%10i", 1);
  ck_assert_str_eq(test_str_335, test_str_335_335);
}
END_TEST

START_TEST(sprintf_test_336) {
  char test_str_336[50] = "";
  char test_str_336_336[50] = "";
  s21_sprintf(test_str_336, "%10i", 10);
  sprintf(test_str_336_336, "%10i", 10);
  ck_assert_str_eq(test_str_336, test_str_336_336);
}
END_TEST

START_TEST(sprintf_test_337) {
  char test_str_337[50] = "";
  char test_str_337_337[50] = "";
  s21_sprintf(test_str_337, "%10i", 123456);
  sprintf(test_str_337_337, "%10i", 123456);
  ck_assert_str_eq(test_str_337, test_str_337_337);
}
END_TEST

START_TEST(sprintf_test_338) {
  char test_str_338[50] = "";
  char test_str_338_338[50] = "";
  s21_sprintf(test_str_338, "%10i", -67890123);
  sprintf(test_str_338_338, "%10i", -67890123);
  ck_assert_str_eq(test_str_338, test_str_338_338);
}
END_TEST

START_TEST(sprintf_test_339) {
  char test_str_339[50] = "";
  char test_str_339_339[50] = "";
  s21_sprintf(test_str_339, "%10i", 4343);
  sprintf(test_str_339_339, "%10i", 4343);
  ck_assert_str_eq(test_str_339, test_str_339_339);
}
END_TEST

START_TEST(sprintf_test_340) {
  char test_str_340[50] = "";
  char test_str_340_340[50] = "";
  s21_sprintf(test_str_340, "%10i", -1);
  sprintf(test_str_340_340, "%10i", -1);
  ck_assert_str_eq(test_str_340, test_str_340_340);
}
END_TEST

START_TEST(sprintf_test_341) {
  char test_str_341[50] = "";
  char test_str_341_341[50] = "";
  s21_sprintf(test_str_341, "%10i", -10);
  sprintf(test_str_341_341, "%10i", -10);
  ck_assert_str_eq(test_str_341, test_str_341_341);
}
END_TEST

START_TEST(sprintf_test_342) {
  char test_str_342[50] = "";
  char test_str_342_342[50] = "";
  s21_sprintf(test_str_342, "%10i", 43);
  sprintf(test_str_342_342, "%10i", 43);
  ck_assert_str_eq(test_str_342, test_str_342_342);
}
END_TEST

START_TEST(sprintf_test_343) {
  char test_str_343[50] = "";
  char test_str_343_343[50] = "";
  s21_sprintf(test_str_343, "%10o", 0);
  sprintf(test_str_343_343, "%10o", 0);
  ck_assert_str_eq(test_str_343, test_str_343_343);
}
END_TEST

START_TEST(sprintf_test_344) {
  char test_str_344[50] = "";
  char test_str_344_344[50] = "";
  s21_sprintf(test_str_344, "%10o", 1);
  sprintf(test_str_344_344, "%10o", 1);
  ck_assert_str_eq(test_str_344, test_str_344_344);
}
END_TEST

START_TEST(sprintf_test_345) {
  char test_str_345[50] = "";
  char test_str_345_345[50] = "";
  s21_sprintf(test_str_345, "%10o", 10);
  sprintf(test_str_345_345, "%10o", 10);
  ck_assert_str_eq(test_str_345, test_str_345_345);
}
END_TEST

START_TEST(sprintf_test_346) {
  char test_str_346[50] = "";
  char test_str_346_346[50] = "";
  s21_sprintf(test_str_346, "%10o", 123456);
  sprintf(test_str_346_346, "%10o", 123456);
  ck_assert_str_eq(test_str_346, test_str_346_346);
}
END_TEST

START_TEST(sprintf_test_347) {
  char test_str_347[50] = "";
  char test_str_347_347[50] = "";
  s21_sprintf(test_str_347, "%10o", -67890123);
  sprintf(test_str_347_347, "%10o", -67890123);
  ck_assert_str_eq(test_str_347, test_str_347_347);
}
END_TEST

START_TEST(sprintf_test_348) {
  char test_str_348[50] = "";
  char test_str_348_348[50] = "";
  s21_sprintf(test_str_348, "%10o", 4343);
  sprintf(test_str_348_348, "%10o", 4343);
  ck_assert_str_eq(test_str_348, test_str_348_348);
}
END_TEST

START_TEST(sprintf_test_349) {
  char test_str_349[50] = "";
  char test_str_349_349[50] = "";
  s21_sprintf(test_str_349, "%10o", -1);
  sprintf(test_str_349_349, "%10o", -1);
  ck_assert_str_eq(test_str_349, test_str_349_349);
}
END_TEST

START_TEST(sprintf_test_350) {
  char test_str_350[50] = "";
  char test_str_350_350[50] = "";
  s21_sprintf(test_str_350, "%10o", -10);
  sprintf(test_str_350_350, "%10o", -10);
  ck_assert_str_eq(test_str_350, test_str_350_350);
}
END_TEST

START_TEST(sprintf_test_351) {
  char test_str_351[50] = "";
  char test_str_351_351[50] = "";
  s21_sprintf(test_str_351, "%10o", 43);
  sprintf(test_str_351_351, "%10o", 43);
  ck_assert_str_eq(test_str_351, test_str_351_351);
}
END_TEST

START_TEST(sprintf_test_352) {
  char test_str_352[50] = "";
  char test_str_352_352[50] = "";
  s21_sprintf(test_str_352, "%10u", 0);
  sprintf(test_str_352_352, "%10u", 0);
  ck_assert_str_eq(test_str_352, test_str_352_352);
}
END_TEST

START_TEST(sprintf_test_353) {
  char test_str_353[50] = "";
  char test_str_353_353[50] = "";
  s21_sprintf(test_str_353, "%10u", 1);
  sprintf(test_str_353_353, "%10u", 1);
  ck_assert_str_eq(test_str_353, test_str_353_353);
}
END_TEST

START_TEST(sprintf_test_354) {
  char test_str_354[50] = "";
  char test_str_354_354[50] = "";
  s21_sprintf(test_str_354, "%10u", 10);
  sprintf(test_str_354_354, "%10u", 10);
  ck_assert_str_eq(test_str_354, test_str_354_354);
}
END_TEST

START_TEST(sprintf_test_355) {
  char test_str_355[50] = "";
  char test_str_355_355[50] = "";
  s21_sprintf(test_str_355, "%10u", 123456);
  sprintf(test_str_355_355, "%10u", 123456);
  ck_assert_str_eq(test_str_355, test_str_355_355);
}
END_TEST

START_TEST(sprintf_test_356) {
  char test_str_356[50] = "";
  char test_str_356_356[50] = "";
  s21_sprintf(test_str_356, "%10u", -67890123);
  sprintf(test_str_356_356, "%10u", -67890123);
  ck_assert_str_eq(test_str_356, test_str_356_356);
}
END_TEST

START_TEST(sprintf_test_357) {
  char test_str_357[50] = "";
  char test_str_357_357[50] = "";
  s21_sprintf(test_str_357, "%10u", 4343);
  sprintf(test_str_357_357, "%10u", 4343);
  ck_assert_str_eq(test_str_357, test_str_357_357);
}
END_TEST

START_TEST(sprintf_test_358) {
  char test_str_358[50] = "";
  char test_str_358_358[50] = "";
  s21_sprintf(test_str_358, "%10u", -1);
  sprintf(test_str_358_358, "%10u", -1);
  ck_assert_str_eq(test_str_358, test_str_358_358);
}
END_TEST

START_TEST(sprintf_test_359) {
  char test_str_359[50] = "";
  char test_str_359_359[50] = "";
  s21_sprintf(test_str_359, "%10u", -10);
  sprintf(test_str_359_359, "%10u", -10);
  ck_assert_str_eq(test_str_359, test_str_359_359);
}
END_TEST

START_TEST(sprintf_test_360) {
  char test_str_360[50] = "";
  char test_str_360_360[50] = "";
  s21_sprintf(test_str_360, "%10u", 43);
  sprintf(test_str_360_360, "%10u", 43);
  ck_assert_str_eq(test_str_360, test_str_360_360);
}
END_TEST

START_TEST(sprintf_test_361) {
  char test_str_361[50] = "";
  char test_str_361_361[50] = "";
  s21_sprintf(test_str_361, "%10x", 0);
  sprintf(test_str_361_361, "%10x", 0);
  ck_assert_str_eq(test_str_361, test_str_361_361);
}
END_TEST

START_TEST(sprintf_test_362) {
  char test_str_362[50] = "";
  char test_str_362_362[50] = "";
  s21_sprintf(test_str_362, "%10x", 1);
  sprintf(test_str_362_362, "%10x", 1);
  ck_assert_str_eq(test_str_362, test_str_362_362);
}
END_TEST

START_TEST(sprintf_test_363) {
  char test_str_363[50] = "";
  char test_str_363_363[50] = "";
  s21_sprintf(test_str_363, "%10x", 10);
  sprintf(test_str_363_363, "%10x", 10);
  ck_assert_str_eq(test_str_363, test_str_363_363);
}
END_TEST

START_TEST(sprintf_test_364) {
  char test_str_364[50] = "";
  char test_str_364_364[50] = "";
  s21_sprintf(test_str_364, "%10x", 123456);
  sprintf(test_str_364_364, "%10x", 123456);
  ck_assert_str_eq(test_str_364, test_str_364_364);
}
END_TEST

START_TEST(sprintf_test_365) {
  char test_str_365[50] = "";
  char test_str_365_365[50] = "";
  s21_sprintf(test_str_365, "%10x", -67890123);
  sprintf(test_str_365_365, "%10x", -67890123);
  ck_assert_str_eq(test_str_365, test_str_365_365);
}
END_TEST

START_TEST(sprintf_test_366) {
  char test_str_366[50] = "";
  char test_str_366_366[50] = "";
  s21_sprintf(test_str_366, "%10x", 4343);
  sprintf(test_str_366_366, "%10x", 4343);
  ck_assert_str_eq(test_str_366, test_str_366_366);
}
END_TEST

START_TEST(sprintf_test_367) {
  char test_str_367[50] = "";
  char test_str_367_367[50] = "";
  s21_sprintf(test_str_367, "%10x", -1);
  sprintf(test_str_367_367, "%10x", -1);
  ck_assert_str_eq(test_str_367, test_str_367_367);
}
END_TEST

START_TEST(sprintf_test_368) {
  char test_str_368[50] = "";
  char test_str_368_368[50] = "";
  s21_sprintf(test_str_368, "%10x", -10);
  sprintf(test_str_368_368, "%10x", -10);
  ck_assert_str_eq(test_str_368, test_str_368_368);
}
END_TEST

START_TEST(sprintf_test_369) {
  char test_str_369[50] = "";
  char test_str_369_369[50] = "";
  s21_sprintf(test_str_369, "%10x", 43);
  sprintf(test_str_369_369, "%10x", 43);
  ck_assert_str_eq(test_str_369, test_str_369_369);
}
END_TEST

START_TEST(sprintf_test_370) {
  char test_str_370[50] = "";
  char test_str_370_370[50] = "";
  s21_sprintf(test_str_370, "%10X", 0);
  sprintf(test_str_370_370, "%10X", 0);
  ck_assert_str_eq(test_str_370, test_str_370_370);
}
END_TEST

START_TEST(sprintf_test_371) {
  char test_str_371[50] = "";
  char test_str_371_371[50] = "";
  s21_sprintf(test_str_371, "%10X", 1);
  sprintf(test_str_371_371, "%10X", 1);
  ck_assert_str_eq(test_str_371, test_str_371_371);
}
END_TEST

START_TEST(sprintf_test_372) {
  char test_str_372[50] = "";
  char test_str_372_372[50] = "";
  s21_sprintf(test_str_372, "%10X", 10);
  sprintf(test_str_372_372, "%10X", 10);
  ck_assert_str_eq(test_str_372, test_str_372_372);
}
END_TEST

START_TEST(sprintf_test_373) {
  char test_str_373[50] = "";
  char test_str_373_373[50] = "";
  s21_sprintf(test_str_373, "%10X", 123456);
  sprintf(test_str_373_373, "%10X", 123456);
  ck_assert_str_eq(test_str_373, test_str_373_373);
}
END_TEST

START_TEST(sprintf_test_374) {
  char test_str_374[50] = "";
  char test_str_374_374[50] = "";
  s21_sprintf(test_str_374, "%10X", -67890123);
  sprintf(test_str_374_374, "%10X", -67890123);
  ck_assert_str_eq(test_str_374, test_str_374_374);
}
END_TEST

START_TEST(sprintf_test_375) {
  char test_str_375[50] = "";
  char test_str_375_375[50] = "";
  s21_sprintf(test_str_375, "%10X", 4343);
  sprintf(test_str_375_375, "%10X", 4343);
  ck_assert_str_eq(test_str_375, test_str_375_375);
}
END_TEST

START_TEST(sprintf_test_376) {
  char test_str_376[50] = "";
  char test_str_376_376[50] = "";
  s21_sprintf(test_str_376, "%10X", -1);
  sprintf(test_str_376_376, "%10X", -1);
  ck_assert_str_eq(test_str_376, test_str_376_376);
}
END_TEST

START_TEST(sprintf_test_377) {
  char test_str_377[50] = "";
  char test_str_377_377[50] = "";
  s21_sprintf(test_str_377, "%10X", -10);
  sprintf(test_str_377_377, "%10X", -10);
  ck_assert_str_eq(test_str_377, test_str_377_377);
}
END_TEST

START_TEST(sprintf_test_378) {
  char test_str_378[50] = "";
  char test_str_378_378[50] = "";
  s21_sprintf(test_str_378, "%10X", 43);
  sprintf(test_str_378_378, "%10X", 43);
  ck_assert_str_eq(test_str_378, test_str_378_378);
}
END_TEST

START_TEST(sprintf_test_379) {
  char test_str_379[50] = "";
  char test_str_379_379[50] = "";
  s21_sprintf(test_str_379, "%20d", 0);
  sprintf(test_str_379_379, "%20d", 0);
  ck_assert_str_eq(test_str_379, test_str_379_379);
}
END_TEST

START_TEST(sprintf_test_380) {
  char test_str_380[50] = "";
  char test_str_380_380[50] = "";
  s21_sprintf(test_str_380, "%20d", 1);
  sprintf(test_str_380_380, "%20d", 1);
  ck_assert_str_eq(test_str_380, test_str_380_380);
}
END_TEST

START_TEST(sprintf_test_381) {
  char test_str_381[50] = "";
  char test_str_381_381[50] = "";
  s21_sprintf(test_str_381, "%20d", 10);
  sprintf(test_str_381_381, "%20d", 10);
  ck_assert_str_eq(test_str_381, test_str_381_381);
}
END_TEST

START_TEST(sprintf_test_382) {
  char test_str_382[50] = "";
  char test_str_382_382[50] = "";
  s21_sprintf(test_str_382, "%20d", 123456);
  sprintf(test_str_382_382, "%20d", 123456);
  ck_assert_str_eq(test_str_382, test_str_382_382);
}
END_TEST

START_TEST(sprintf_test_383) {
  char test_str_383[50] = "";
  char test_str_383_383[50] = "";
  s21_sprintf(test_str_383, "%20d", -67890123);
  sprintf(test_str_383_383, "%20d", -67890123);
  ck_assert_str_eq(test_str_383, test_str_383_383);
}
END_TEST

START_TEST(sprintf_test_384) {
  char test_str_384[50] = "";
  char test_str_384_384[50] = "";
  s21_sprintf(test_str_384, "%20d", 4343);
  sprintf(test_str_384_384, "%20d", 4343);
  ck_assert_str_eq(test_str_384, test_str_384_384);
}
END_TEST

START_TEST(sprintf_test_385) {
  char test_str_385[50] = "";
  char test_str_385_385[50] = "";
  s21_sprintf(test_str_385, "%20d", -1);
  sprintf(test_str_385_385, "%20d", -1);
  ck_assert_str_eq(test_str_385, test_str_385_385);
}
END_TEST

START_TEST(sprintf_test_386) {
  char test_str_386[50] = "";
  char test_str_386_386[50] = "";
  s21_sprintf(test_str_386, "%20d", -10);
  sprintf(test_str_386_386, "%20d", -10);
  ck_assert_str_eq(test_str_386, test_str_386_386);
}
END_TEST

START_TEST(sprintf_test_387) {
  char test_str_387[50] = "";
  char test_str_387_387[50] = "";
  s21_sprintf(test_str_387, "%20d", 43);
  sprintf(test_str_387_387, "%20d", 43);
  ck_assert_str_eq(test_str_387, test_str_387_387);
}
END_TEST

START_TEST(sprintf_test_388) {
  char test_str_388[50] = "";
  char test_str_388_388[50] = "";
  s21_sprintf(test_str_388, "%20i", 0);
  sprintf(test_str_388_388, "%20i", 0);
  ck_assert_str_eq(test_str_388, test_str_388_388);
}
END_TEST

START_TEST(sprintf_test_389) {
  char test_str_389[50] = "";
  char test_str_389_389[50] = "";
  s21_sprintf(test_str_389, "%20i", 1);
  sprintf(test_str_389_389, "%20i", 1);
  ck_assert_str_eq(test_str_389, test_str_389_389);
}
END_TEST

START_TEST(sprintf_test_390) {
  char test_str_390[50] = "";
  char test_str_390_390[50] = "";
  s21_sprintf(test_str_390, "%20i", 10);
  sprintf(test_str_390_390, "%20i", 10);
  ck_assert_str_eq(test_str_390, test_str_390_390);
}
END_TEST

START_TEST(sprintf_test_391) {
  char test_str_391[50] = "";
  char test_str_391_391[50] = "";
  s21_sprintf(test_str_391, "%20i", 123456);
  sprintf(test_str_391_391, "%20i", 123456);
  ck_assert_str_eq(test_str_391, test_str_391_391);
}
END_TEST

START_TEST(sprintf_test_392) {
  char test_str_392[50] = "";
  char test_str_392_392[50] = "";
  s21_sprintf(test_str_392, "%20i", -67890123);
  sprintf(test_str_392_392, "%20i", -67890123);
  ck_assert_str_eq(test_str_392, test_str_392_392);
}
END_TEST

START_TEST(sprintf_test_393) {
  char test_str_393[50] = "";
  char test_str_393_393[50] = "";
  s21_sprintf(test_str_393, "%20i", 4343);
  sprintf(test_str_393_393, "%20i", 4343);
  ck_assert_str_eq(test_str_393, test_str_393_393);
}
END_TEST

START_TEST(sprintf_test_394) {
  char test_str_394[50] = "";
  char test_str_394_394[50] = "";
  s21_sprintf(test_str_394, "%20i", -1);
  sprintf(test_str_394_394, "%20i", -1);
  ck_assert_str_eq(test_str_394, test_str_394_394);
}
END_TEST

START_TEST(sprintf_test_395) {
  char test_str_395[50] = "";
  char test_str_395_395[50] = "";
  s21_sprintf(test_str_395, "%20i", -10);
  sprintf(test_str_395_395, "%20i", -10);
  ck_assert_str_eq(test_str_395, test_str_395_395);
}
END_TEST

START_TEST(sprintf_test_396) {
  char test_str_396[50] = "";
  char test_str_396_396[50] = "";
  s21_sprintf(test_str_396, "%20i", 43);
  sprintf(test_str_396_396, "%20i", 43);
  ck_assert_str_eq(test_str_396, test_str_396_396);
}
END_TEST

START_TEST(sprintf_test_397) {
  char test_str_397[50] = "";
  char test_str_397_397[50] = "";
  s21_sprintf(test_str_397, "%20o", 0);
  sprintf(test_str_397_397, "%20o", 0);
  ck_assert_str_eq(test_str_397, test_str_397_397);
}
END_TEST

START_TEST(sprintf_test_398) {
  char test_str_398[50] = "";
  char test_str_398_398[50] = "";
  s21_sprintf(test_str_398, "%20o", 1);
  sprintf(test_str_398_398, "%20o", 1);
  ck_assert_str_eq(test_str_398, test_str_398_398);
}
END_TEST

START_TEST(sprintf_test_399) {
  char test_str_399[50] = "";
  char test_str_399_399[50] = "";
  s21_sprintf(test_str_399, "%20o", 10);
  sprintf(test_str_399_399, "%20o", 10);
  ck_assert_str_eq(test_str_399, test_str_399_399);
}
END_TEST

START_TEST(sprintf_test_400) {
  char test_str_400[50] = "";
  char test_str_400_400[50] = "";
  s21_sprintf(test_str_400, "%20o", 123456);
  sprintf(test_str_400_400, "%20o", 123456);
  ck_assert_str_eq(test_str_400, test_str_400_400);
}
END_TEST

START_TEST(sprintf_test_401) {
  char test_str_401[50] = "";
  char test_str_401_401[50] = "";
  s21_sprintf(test_str_401, "%20o", -67890123);
  sprintf(test_str_401_401, "%20o", -67890123);
  ck_assert_str_eq(test_str_401, test_str_401_401);
}
END_TEST

START_TEST(sprintf_test_402) {
  char test_str_402[50] = "";
  char test_str_402_402[50] = "";
  s21_sprintf(test_str_402, "%20o", 4343);
  sprintf(test_str_402_402, "%20o", 4343);
  ck_assert_str_eq(test_str_402, test_str_402_402);
}
END_TEST

START_TEST(sprintf_test_403) {
  char test_str_403[50] = "";
  char test_str_403_403[50] = "";
  s21_sprintf(test_str_403, "%20o", -1);
  sprintf(test_str_403_403, "%20o", -1);
  ck_assert_str_eq(test_str_403, test_str_403_403);
}
END_TEST

START_TEST(sprintf_test_404) {
  char test_str_404[50] = "";
  char test_str_404_404[50] = "";
  s21_sprintf(test_str_404, "%20o", -10);
  sprintf(test_str_404_404, "%20o", -10);
  ck_assert_str_eq(test_str_404, test_str_404_404);
}
END_TEST

START_TEST(sprintf_test_405) {
  char test_str_405[50] = "";
  char test_str_405_405[50] = "";
  s21_sprintf(test_str_405, "%20o", 43);
  sprintf(test_str_405_405, "%20o", 43);
  ck_assert_str_eq(test_str_405, test_str_405_405);
}
END_TEST

START_TEST(sprintf_test_406) {
  char test_str_406[50] = "";
  char test_str_406_406[50] = "";
  s21_sprintf(test_str_406, "%20u", 0);
  sprintf(test_str_406_406, "%20u", 0);
  ck_assert_str_eq(test_str_406, test_str_406_406);
}
END_TEST

START_TEST(sprintf_test_407) {
  char test_str_407[50] = "";
  char test_str_407_407[50] = "";
  s21_sprintf(test_str_407, "%20u", 1);
  sprintf(test_str_407_407, "%20u", 1);
  ck_assert_str_eq(test_str_407, test_str_407_407);
}
END_TEST

START_TEST(sprintf_test_408) {
  char test_str_408[50] = "";
  char test_str_408_408[50] = "";
  s21_sprintf(test_str_408, "%20u", 10);
  sprintf(test_str_408_408, "%20u", 10);
  ck_assert_str_eq(test_str_408, test_str_408_408);
}
END_TEST

START_TEST(sprintf_test_409) {
  char test_str_409[50] = "";
  char test_str_409_409[50] = "";
  s21_sprintf(test_str_409, "%20u", 123456);
  sprintf(test_str_409_409, "%20u", 123456);
  ck_assert_str_eq(test_str_409, test_str_409_409);
}
END_TEST

START_TEST(sprintf_test_410) {
  char test_str_410[50] = "";
  char test_str_410_410[50] = "";
  s21_sprintf(test_str_410, "%20u", -67890123);
  sprintf(test_str_410_410, "%20u", -67890123);
  ck_assert_str_eq(test_str_410, test_str_410_410);
}
END_TEST

START_TEST(sprintf_test_411) {
  char test_str_411[50] = "";
  char test_str_411_411[50] = "";
  s21_sprintf(test_str_411, "%20u", 4343);
  sprintf(test_str_411_411, "%20u", 4343);
  ck_assert_str_eq(test_str_411, test_str_411_411);
}
END_TEST

START_TEST(sprintf_test_412) {
  char test_str_412[50] = "";
  char test_str_412_412[50] = "";
  s21_sprintf(test_str_412, "%20u", -1);
  sprintf(test_str_412_412, "%20u", -1);
  ck_assert_str_eq(test_str_412, test_str_412_412);
}
END_TEST

START_TEST(sprintf_test_413) {
  char test_str_413[50] = "";
  char test_str_413_413[50] = "";
  s21_sprintf(test_str_413, "%20u", -10);
  sprintf(test_str_413_413, "%20u", -10);
  ck_assert_str_eq(test_str_413, test_str_413_413);
}
END_TEST

START_TEST(sprintf_test_414) {
  char test_str_414[50] = "";
  char test_str_414_414[50] = "";
  s21_sprintf(test_str_414, "%20u", 43);
  sprintf(test_str_414_414, "%20u", 43);
  ck_assert_str_eq(test_str_414, test_str_414_414);
}
END_TEST

START_TEST(sprintf_test_415) {
  char test_str_415[50] = "";
  char test_str_415_415[50] = "";
  s21_sprintf(test_str_415, "%20x", 0);
  sprintf(test_str_415_415, "%20x", 0);
  ck_assert_str_eq(test_str_415, test_str_415_415);
}
END_TEST

START_TEST(sprintf_test_416) {
  char test_str_416[50] = "";
  char test_str_416_416[50] = "";
  s21_sprintf(test_str_416, "%20x", 1);
  sprintf(test_str_416_416, "%20x", 1);
  ck_assert_str_eq(test_str_416, test_str_416_416);
}
END_TEST

START_TEST(sprintf_test_417) {
  char test_str_417[50] = "";
  char test_str_417_417[50] = "";
  s21_sprintf(test_str_417, "%20x", 10);
  sprintf(test_str_417_417, "%20x", 10);
  ck_assert_str_eq(test_str_417, test_str_417_417);
}
END_TEST

START_TEST(sprintf_test_418) {
  char test_str_418[50] = "";
  char test_str_418_418[50] = "";
  s21_sprintf(test_str_418, "%20x", 123456);
  sprintf(test_str_418_418, "%20x", 123456);
  ck_assert_str_eq(test_str_418, test_str_418_418);
}
END_TEST

START_TEST(sprintf_test_419) {
  char test_str_419[50] = "";
  char test_str_419_419[50] = "";
  s21_sprintf(test_str_419, "%20x", -67890123);
  sprintf(test_str_419_419, "%20x", -67890123);
  ck_assert_str_eq(test_str_419, test_str_419_419);
}
END_TEST

START_TEST(sprintf_test_420) {
  char test_str_420[50] = "";
  char test_str_420_420[50] = "";
  s21_sprintf(test_str_420, "%20x", 4343);
  sprintf(test_str_420_420, "%20x", 4343);
  ck_assert_str_eq(test_str_420, test_str_420_420);
}
END_TEST

START_TEST(sprintf_test_421) {
  char test_str_421[50] = "";
  char test_str_421_421[50] = "";
  s21_sprintf(test_str_421, "%20x", -1);
  sprintf(test_str_421_421, "%20x", -1);
  ck_assert_str_eq(test_str_421, test_str_421_421);
}
END_TEST

START_TEST(sprintf_test_422) {
  char test_str_422[50] = "";
  char test_str_422_422[50] = "";
  s21_sprintf(test_str_422, "%20x", -10);
  sprintf(test_str_422_422, "%20x", -10);
  ck_assert_str_eq(test_str_422, test_str_422_422);
}
END_TEST

START_TEST(sprintf_test_423) {
  char test_str_423[50] = "";
  char test_str_423_423[50] = "";
  s21_sprintf(test_str_423, "%20x", 43);
  sprintf(test_str_423_423, "%20x", 43);
  ck_assert_str_eq(test_str_423, test_str_423_423);
}
END_TEST

START_TEST(sprintf_test_424) {
  char test_str_424[50] = "";
  char test_str_424_424[50] = "";
  s21_sprintf(test_str_424, "%20X", 0);
  sprintf(test_str_424_424, "%20X", 0);
  ck_assert_str_eq(test_str_424, test_str_424_424);
}
END_TEST

START_TEST(sprintf_test_425) {
  char test_str_425[50] = "";
  char test_str_425_425[50] = "";
  s21_sprintf(test_str_425, "%20X", 1);
  sprintf(test_str_425_425, "%20X", 1);
  ck_assert_str_eq(test_str_425, test_str_425_425);
}
END_TEST

START_TEST(sprintf_test_426) {
  char test_str_426[50] = "";
  char test_str_426_426[50] = "";
  s21_sprintf(test_str_426, "%20X", 10);
  sprintf(test_str_426_426, "%20X", 10);
  ck_assert_str_eq(test_str_426, test_str_426_426);
}
END_TEST

START_TEST(sprintf_test_427) {
  char test_str_427[50] = "";
  char test_str_427_427[50] = "";
  s21_sprintf(test_str_427, "%20X", 123456);
  sprintf(test_str_427_427, "%20X", 123456);
  ck_assert_str_eq(test_str_427, test_str_427_427);
}
END_TEST

START_TEST(sprintf_test_428) {
  char test_str_428[50] = "";
  char test_str_428_428[50] = "";
  s21_sprintf(test_str_428, "%20X", -67890123);
  sprintf(test_str_428_428, "%20X", -67890123);
  ck_assert_str_eq(test_str_428, test_str_428_428);
}
END_TEST

START_TEST(sprintf_test_429) {
  char test_str_429[50] = "";
  char test_str_429_429[50] = "";
  s21_sprintf(test_str_429, "%20X", 4343);
  sprintf(test_str_429_429, "%20X", 4343);
  ck_assert_str_eq(test_str_429, test_str_429_429);
}
END_TEST

START_TEST(sprintf_test_430) {
  char test_str_430[50] = "";
  char test_str_430_430[50] = "";
  s21_sprintf(test_str_430, "%20X", -1);
  sprintf(test_str_430_430, "%20X", -1);
  ck_assert_str_eq(test_str_430, test_str_430_430);
}
END_TEST

START_TEST(sprintf_test_431) {
  char test_str_431[50] = "";
  char test_str_431_431[50] = "";
  s21_sprintf(test_str_431, "%20X", -10);
  sprintf(test_str_431_431, "%20X", -10);
  ck_assert_str_eq(test_str_431, test_str_431_431);
}
END_TEST

START_TEST(sprintf_test_432) {
  char test_str_432[50] = "";
  char test_str_432_432[50] = "";
  s21_sprintf(test_str_432, "%20X", 43);
  sprintf(test_str_432_432, "%20X", 43);
  ck_assert_str_eq(test_str_432, test_str_432_432);
}
END_TEST

START_TEST(sprintf_test_433) {
  char test_str_433[50] = "";
  char test_str_433_433[50] = "";
  s21_sprintf(test_str_433, "%-10d", 0);
  sprintf(test_str_433_433, "%-10d", 0);
  ck_assert_str_eq(test_str_433, test_str_433_433);
}
END_TEST

START_TEST(sprintf_test_434) {
  char test_str_434[50] = "";
  char test_str_434_434[50] = "";
  s21_sprintf(test_str_434, "%-10d", 1);
  sprintf(test_str_434_434, "%-10d", 1);
  ck_assert_str_eq(test_str_434, test_str_434_434);
}
END_TEST

START_TEST(sprintf_test_435) {
  char test_str_435[50] = "";
  char test_str_435_435[50] = "";
  s21_sprintf(test_str_435, "%-10d", 10);
  sprintf(test_str_435_435, "%-10d", 10);
  ck_assert_str_eq(test_str_435, test_str_435_435);
}
END_TEST

START_TEST(sprintf_test_436) {
  char test_str_436[50] = "";
  char test_str_436_436[50] = "";
  s21_sprintf(test_str_436, "%-10d", 123456);
  sprintf(test_str_436_436, "%-10d", 123456);
  ck_assert_str_eq(test_str_436, test_str_436_436);
}
END_TEST

START_TEST(sprintf_test_437) {
  char test_str_437[50] = "";
  char test_str_437_437[50] = "";
  s21_sprintf(test_str_437, "%-10d", -67890123);
  sprintf(test_str_437_437, "%-10d", -67890123);
  ck_assert_str_eq(test_str_437, test_str_437_437);
}
END_TEST

START_TEST(sprintf_test_438) {
  char test_str_438[50] = "";
  char test_str_438_438[50] = "";
  s21_sprintf(test_str_438, "%-10d", 4343);
  sprintf(test_str_438_438, "%-10d", 4343);
  ck_assert_str_eq(test_str_438, test_str_438_438);
}
END_TEST

START_TEST(sprintf_test_439) {
  char test_str_439[50] = "";
  char test_str_439_439[50] = "";
  s21_sprintf(test_str_439, "%-10d", -1);
  sprintf(test_str_439_439, "%-10d", -1);
  ck_assert_str_eq(test_str_439, test_str_439_439);
}
END_TEST

START_TEST(sprintf_test_440) {
  char test_str_440[50] = "";
  char test_str_440_440[50] = "";
  s21_sprintf(test_str_440, "%-10d", -10);
  sprintf(test_str_440_440, "%-10d", -10);
  ck_assert_str_eq(test_str_440, test_str_440_440);
}
END_TEST

START_TEST(sprintf_test_441) {
  char test_str_441[50] = "";
  char test_str_441_441[50] = "";
  s21_sprintf(test_str_441, "%-10d", 43);
  sprintf(test_str_441_441, "%-10d", 43);
  ck_assert_str_eq(test_str_441, test_str_441_441);
}
END_TEST

START_TEST(sprintf_test_442) {
  char test_str_442[50] = "";
  char test_str_442_442[50] = "";
  s21_sprintf(test_str_442, "%-10i", 0);
  sprintf(test_str_442_442, "%-10i", 0);
  ck_assert_str_eq(test_str_442, test_str_442_442);
}
END_TEST

START_TEST(sprintf_test_443) {
  char test_str_443[50] = "";
  char test_str_443_443[50] = "";
  s21_sprintf(test_str_443, "%-10i", 1);
  sprintf(test_str_443_443, "%-10i", 1);
  ck_assert_str_eq(test_str_443, test_str_443_443);
}
END_TEST

START_TEST(sprintf_test_444) {
  char test_str_444[50] = "";
  char test_str_444_444[50] = "";
  s21_sprintf(test_str_444, "%-10i", 10);
  sprintf(test_str_444_444, "%-10i", 10);
  ck_assert_str_eq(test_str_444, test_str_444_444);
}
END_TEST

START_TEST(sprintf_test_445) {
  char test_str_445[50] = "";
  char test_str_445_445[50] = "";
  s21_sprintf(test_str_445, "%-10i", 123456);
  sprintf(test_str_445_445, "%-10i", 123456);
  ck_assert_str_eq(test_str_445, test_str_445_445);
}
END_TEST

START_TEST(sprintf_test_446) {
  char test_str_446[50] = "";
  char test_str_446_446[50] = "";
  s21_sprintf(test_str_446, "%-10i", -67890123);
  sprintf(test_str_446_446, "%-10i", -67890123);
  ck_assert_str_eq(test_str_446, test_str_446_446);
}
END_TEST

START_TEST(sprintf_test_447) {
  char test_str_447[50] = "";
  char test_str_447_447[50] = "";
  s21_sprintf(test_str_447, "%-10i", 4343);
  sprintf(test_str_447_447, "%-10i", 4343);
  ck_assert_str_eq(test_str_447, test_str_447_447);
}
END_TEST

START_TEST(sprintf_test_448) {
  char test_str_448[50] = "";
  char test_str_448_448[50] = "";
  s21_sprintf(test_str_448, "%-10i", -1);
  sprintf(test_str_448_448, "%-10i", -1);
  ck_assert_str_eq(test_str_448, test_str_448_448);
}
END_TEST

START_TEST(sprintf_test_449) {
  char test_str_449[50] = "";
  char test_str_449_449[50] = "";
  s21_sprintf(test_str_449, "%-10i", -10);
  sprintf(test_str_449_449, "%-10i", -10);
  ck_assert_str_eq(test_str_449, test_str_449_449);
}
END_TEST

START_TEST(sprintf_test_450) {
  char test_str_450[50] = "";
  char test_str_450_450[50] = "";
  s21_sprintf(test_str_450, "%-10i", 43);
  sprintf(test_str_450_450, "%-10i", 43);
  ck_assert_str_eq(test_str_450, test_str_450_450);
}
END_TEST

START_TEST(sprintf_test_451) {
  char test_str_451[50] = "";
  char test_str_451_451[50] = "";
  s21_sprintf(test_str_451, "%-10o", 0);
  sprintf(test_str_451_451, "%-10o", 0);
  ck_assert_str_eq(test_str_451, test_str_451_451);
}
END_TEST

START_TEST(sprintf_test_452) {
  char test_str_452[50] = "";
  char test_str_452_452[50] = "";
  s21_sprintf(test_str_452, "%-10o", 1);
  sprintf(test_str_452_452, "%-10o", 1);
  ck_assert_str_eq(test_str_452, test_str_452_452);
}
END_TEST

START_TEST(sprintf_test_453) {
  char test_str_453[50] = "";
  char test_str_453_453[50] = "";
  s21_sprintf(test_str_453, "%-10o", 10);
  sprintf(test_str_453_453, "%-10o", 10);
  ck_assert_str_eq(test_str_453, test_str_453_453);
}
END_TEST

START_TEST(sprintf_test_454) {
  char test_str_454[50] = "";
  char test_str_454_454[50] = "";
  s21_sprintf(test_str_454, "%-10o", 123456);
  sprintf(test_str_454_454, "%-10o", 123456);
  ck_assert_str_eq(test_str_454, test_str_454_454);
}
END_TEST

START_TEST(sprintf_test_455) {
  char test_str_455[50] = "";
  char test_str_455_455[50] = "";
  s21_sprintf(test_str_455, "%-10o", -67890123);
  sprintf(test_str_455_455, "%-10o", -67890123);
  ck_assert_str_eq(test_str_455, test_str_455_455);
}
END_TEST

START_TEST(sprintf_test_456) {
  char test_str_456[50] = "";
  char test_str_456_456[50] = "";
  s21_sprintf(test_str_456, "%-10o", 4343);
  sprintf(test_str_456_456, "%-10o", 4343);
  ck_assert_str_eq(test_str_456, test_str_456_456);
}
END_TEST

START_TEST(sprintf_test_457) {
  char test_str_457[50] = "";
  char test_str_457_457[50] = "";
  s21_sprintf(test_str_457, "%-10o", -1);
  sprintf(test_str_457_457, "%-10o", -1);
  ck_assert_str_eq(test_str_457, test_str_457_457);
}
END_TEST

START_TEST(sprintf_test_458) {
  char test_str_458[50] = "";
  char test_str_458_458[50] = "";
  s21_sprintf(test_str_458, "%-10o", -10);
  sprintf(test_str_458_458, "%-10o", -10);
  ck_assert_str_eq(test_str_458, test_str_458_458);
}
END_TEST

START_TEST(sprintf_test_459) {
  char test_str_459[50] = "";
  char test_str_459_459[50] = "";
  s21_sprintf(test_str_459, "%-10o", 43);
  sprintf(test_str_459_459, "%-10o", 43);
  ck_assert_str_eq(test_str_459, test_str_459_459);
}
END_TEST

START_TEST(sprintf_test_460) {
  char test_str_460[50] = "";
  char test_str_460_460[50] = "";
  s21_sprintf(test_str_460, "%-10u", 0);
  sprintf(test_str_460_460, "%-10u", 0);
  ck_assert_str_eq(test_str_460, test_str_460_460);
}
END_TEST

START_TEST(sprintf_test_461) {
  char test_str_461[50] = "";
  char test_str_461_461[50] = "";
  s21_sprintf(test_str_461, "%-10u", 1);
  sprintf(test_str_461_461, "%-10u", 1);
  ck_assert_str_eq(test_str_461, test_str_461_461);
}
END_TEST

START_TEST(sprintf_test_462) {
  char test_str_462[50] = "";
  char test_str_462_462[50] = "";
  s21_sprintf(test_str_462, "%-10u", 10);
  sprintf(test_str_462_462, "%-10u", 10);
  ck_assert_str_eq(test_str_462, test_str_462_462);
}
END_TEST

START_TEST(sprintf_test_463) {
  char test_str_463[50] = "";
  char test_str_463_463[50] = "";
  s21_sprintf(test_str_463, "%-10u", 123456);
  sprintf(test_str_463_463, "%-10u", 123456);
  ck_assert_str_eq(test_str_463, test_str_463_463);
}
END_TEST

START_TEST(sprintf_test_464) {
  char test_str_464[50] = "";
  char test_str_464_464[50] = "";
  s21_sprintf(test_str_464, "%-10u", -67890123);
  sprintf(test_str_464_464, "%-10u", -67890123);
  ck_assert_str_eq(test_str_464, test_str_464_464);
}
END_TEST

START_TEST(sprintf_test_465) {
  char test_str_465[50] = "";
  char test_str_465_465[50] = "";
  s21_sprintf(test_str_465, "%-10u", 4343);
  sprintf(test_str_465_465, "%-10u", 4343);
  ck_assert_str_eq(test_str_465, test_str_465_465);
}
END_TEST

START_TEST(sprintf_test_466) {
  char test_str_466[50] = "";
  char test_str_466_466[50] = "";
  s21_sprintf(test_str_466, "%-10u", -1);
  sprintf(test_str_466_466, "%-10u", -1);
  ck_assert_str_eq(test_str_466, test_str_466_466);
}
END_TEST

START_TEST(sprintf_test_467) {
  char test_str_467[50] = "";
  char test_str_467_467[50] = "";
  s21_sprintf(test_str_467, "%-10u", -10);
  sprintf(test_str_467_467, "%-10u", -10);
  ck_assert_str_eq(test_str_467, test_str_467_467);
}
END_TEST

START_TEST(sprintf_test_468) {
  char test_str_468[50] = "";
  char test_str_468_468[50] = "";
  s21_sprintf(test_str_468, "%-10u", 43);
  sprintf(test_str_468_468, "%-10u", 43);
  ck_assert_str_eq(test_str_468, test_str_468_468);
}
END_TEST

START_TEST(sprintf_test_469) {
  char test_str_469[50] = "";
  char test_str_469_469[50] = "";
  s21_sprintf(test_str_469, "%-10x", 0);
  sprintf(test_str_469_469, "%-10x", 0);
  ck_assert_str_eq(test_str_469, test_str_469_469);
}
END_TEST

START_TEST(sprintf_test_470) {
  char test_str_470[50] = "";
  char test_str_470_470[50] = "";
  s21_sprintf(test_str_470, "%-10x", 1);
  sprintf(test_str_470_470, "%-10x", 1);
  ck_assert_str_eq(test_str_470, test_str_470_470);
}
END_TEST

START_TEST(sprintf_test_471) {
  char test_str_471[50] = "";
  char test_str_471_471[50] = "";
  s21_sprintf(test_str_471, "%-10x", 10);
  sprintf(test_str_471_471, "%-10x", 10);
  ck_assert_str_eq(test_str_471, test_str_471_471);
}
END_TEST

START_TEST(sprintf_test_472) {
  char test_str_472[50] = "";
  char test_str_472_472[50] = "";
  s21_sprintf(test_str_472, "%-10x", 123456);
  sprintf(test_str_472_472, "%-10x", 123456);
  ck_assert_str_eq(test_str_472, test_str_472_472);
}
END_TEST

START_TEST(sprintf_test_473) {
  char test_str_473[50] = "";
  char test_str_473_473[50] = "";
  s21_sprintf(test_str_473, "%-10x", -67890123);
  sprintf(test_str_473_473, "%-10x", -67890123);
  ck_assert_str_eq(test_str_473, test_str_473_473);
}
END_TEST

START_TEST(sprintf_test_474) {
  char test_str_474[50] = "";
  char test_str_474_474[50] = "";
  s21_sprintf(test_str_474, "%-10x", 4343);
  sprintf(test_str_474_474, "%-10x", 4343);
  ck_assert_str_eq(test_str_474, test_str_474_474);
}
END_TEST

START_TEST(sprintf_test_475) {
  char test_str_475[50] = "";
  char test_str_475_475[50] = "";
  s21_sprintf(test_str_475, "%-10x", -1);
  sprintf(test_str_475_475, "%-10x", -1);
  ck_assert_str_eq(test_str_475, test_str_475_475);
}
END_TEST

START_TEST(sprintf_test_476) {
  char test_str_476[50] = "";
  char test_str_476_476[50] = "";
  s21_sprintf(test_str_476, "%-10x", -10);
  sprintf(test_str_476_476, "%-10x", -10);
  ck_assert_str_eq(test_str_476, test_str_476_476);
}
END_TEST

START_TEST(sprintf_test_477) {
  char test_str_477[50] = "";
  char test_str_477_477[50] = "";
  s21_sprintf(test_str_477, "%-10x", 43);
  sprintf(test_str_477_477, "%-10x", 43);
  ck_assert_str_eq(test_str_477, test_str_477_477);
}
END_TEST

START_TEST(sprintf_test_478) {
  char test_str_478[50] = "";
  char test_str_478_478[50] = "";
  s21_sprintf(test_str_478, "%-10X", 0);
  sprintf(test_str_478_478, "%-10X", 0);
  ck_assert_str_eq(test_str_478, test_str_478_478);
}
END_TEST

START_TEST(sprintf_test_479) {
  char test_str_479[50] = "";
  char test_str_479_479[50] = "";
  s21_sprintf(test_str_479, "%-10X", 1);
  sprintf(test_str_479_479, "%-10X", 1);
  ck_assert_str_eq(test_str_479, test_str_479_479);
}
END_TEST

START_TEST(sprintf_test_480) {
  char test_str_480[50] = "";
  char test_str_480_480[50] = "";
  s21_sprintf(test_str_480, "%-10X", 10);
  sprintf(test_str_480_480, "%-10X", 10);
  ck_assert_str_eq(test_str_480, test_str_480_480);
}
END_TEST

START_TEST(sprintf_test_481) {
  char test_str_481[50] = "";
  char test_str_481_481[50] = "";
  s21_sprintf(test_str_481, "%-10X", 123456);
  sprintf(test_str_481_481, "%-10X", 123456);
  ck_assert_str_eq(test_str_481, test_str_481_481);
}
END_TEST

START_TEST(sprintf_test_482) {
  char test_str_482[50] = "";
  char test_str_482_482[50] = "";
  s21_sprintf(test_str_482, "%-10X", -67890123);
  sprintf(test_str_482_482, "%-10X", -67890123);
  ck_assert_str_eq(test_str_482, test_str_482_482);
}
END_TEST

START_TEST(sprintf_test_483) {
  char test_str_483[50] = "";
  char test_str_483_483[50] = "";
  s21_sprintf(test_str_483, "%-10X", 4343);
  sprintf(test_str_483_483, "%-10X", 4343);
  ck_assert_str_eq(test_str_483, test_str_483_483);
}
END_TEST

START_TEST(sprintf_test_484) {
  char test_str_484[50] = "";
  char test_str_484_484[50] = "";
  s21_sprintf(test_str_484, "%-10X", -1);
  sprintf(test_str_484_484, "%-10X", -1);
  ck_assert_str_eq(test_str_484, test_str_484_484);
}
END_TEST

START_TEST(sprintf_test_485) {
  char test_str_485[50] = "";
  char test_str_485_485[50] = "";
  s21_sprintf(test_str_485, "%-10X", -10);
  sprintf(test_str_485_485, "%-10X", -10);
  ck_assert_str_eq(test_str_485, test_str_485_485);
}
END_TEST

START_TEST(sprintf_test_486) {
  char test_str_486[50] = "";
  char test_str_486_486[50] = "";
  s21_sprintf(test_str_486, "%-10X", 43);
  sprintf(test_str_486_486, "%-10X", 43);
  ck_assert_str_eq(test_str_486, test_str_486_486);
}
END_TEST

START_TEST(sprintf_test_487) {
  char test_str_487[50] = "";
  char test_str_487_487[50] = "";
  s21_sprintf(test_str_487, "%-20d", 0);
  sprintf(test_str_487_487, "%-20d", 0);
  ck_assert_str_eq(test_str_487, test_str_487_487);
}
END_TEST

START_TEST(sprintf_test_488) {
  char test_str_488[50] = "";
  char test_str_488_488[50] = "";
  s21_sprintf(test_str_488, "%-20d", 1);
  sprintf(test_str_488_488, "%-20d", 1);
  ck_assert_str_eq(test_str_488, test_str_488_488);
}
END_TEST

START_TEST(sprintf_test_489) {
  char test_str_489[50] = "";
  char test_str_489_489[50] = "";
  s21_sprintf(test_str_489, "%-20d", 10);
  sprintf(test_str_489_489, "%-20d", 10);
  ck_assert_str_eq(test_str_489, test_str_489_489);
}
END_TEST

START_TEST(sprintf_test_490) {
  char test_str_490[50] = "";
  char test_str_490_490[50] = "";
  s21_sprintf(test_str_490, "%-20d", 123456);
  sprintf(test_str_490_490, "%-20d", 123456);
  ck_assert_str_eq(test_str_490, test_str_490_490);
}
END_TEST

START_TEST(sprintf_test_491) {
  char test_str_491[50] = "";
  char test_str_491_491[50] = "";
  s21_sprintf(test_str_491, "%-20d", -67890123);
  sprintf(test_str_491_491, "%-20d", -67890123);
  ck_assert_str_eq(test_str_491, test_str_491_491);
}
END_TEST

START_TEST(sprintf_test_492) {
  char test_str_492[50] = "";
  char test_str_492_492[50] = "";
  s21_sprintf(test_str_492, "%-20d", 4343);
  sprintf(test_str_492_492, "%-20d", 4343);
  ck_assert_str_eq(test_str_492, test_str_492_492);
}
END_TEST

START_TEST(sprintf_test_493) {
  char test_str_493[50] = "";
  char test_str_493_493[50] = "";
  s21_sprintf(test_str_493, "%-20d", -1);
  sprintf(test_str_493_493, "%-20d", -1);
  ck_assert_str_eq(test_str_493, test_str_493_493);
}
END_TEST

START_TEST(sprintf_test_494) {
  char test_str_494[50] = "";
  char test_str_494_494[50] = "";
  s21_sprintf(test_str_494, "%-20d", -10);
  sprintf(test_str_494_494, "%-20d", -10);
  ck_assert_str_eq(test_str_494, test_str_494_494);
}
END_TEST

START_TEST(sprintf_test_495) {
  char test_str_495[50] = "";
  char test_str_495_495[50] = "";
  s21_sprintf(test_str_495, "%-20d", 43);
  sprintf(test_str_495_495, "%-20d", 43);
  ck_assert_str_eq(test_str_495, test_str_495_495);
}
END_TEST

START_TEST(sprintf_test_496) {
  char test_str_496[50] = "";
  char test_str_496_496[50] = "";
  s21_sprintf(test_str_496, "%-20i", 0);
  sprintf(test_str_496_496, "%-20i", 0);
  ck_assert_str_eq(test_str_496, test_str_496_496);
}
END_TEST

START_TEST(sprintf_test_497) {
  char test_str_497[50] = "";
  char test_str_497_497[50] = "";
  s21_sprintf(test_str_497, "%-20i", 1);
  sprintf(test_str_497_497, "%-20i", 1);
  ck_assert_str_eq(test_str_497, test_str_497_497);
}
END_TEST

START_TEST(sprintf_test_498) {
  char test_str_498[50] = "";
  char test_str_498_498[50] = "";
  s21_sprintf(test_str_498, "%-20i", 10);
  sprintf(test_str_498_498, "%-20i", 10);
  ck_assert_str_eq(test_str_498, test_str_498_498);
}
END_TEST

START_TEST(sprintf_test_499) {
  char test_str_499[50] = "";
  char test_str_499_499[50] = "";
  s21_sprintf(test_str_499, "%-20i", 123456);
  sprintf(test_str_499_499, "%-20i", 123456);
  ck_assert_str_eq(test_str_499, test_str_499_499);
}
END_TEST

START_TEST(sprintf_test_500) {
  char test_str_500[50] = "";
  char test_str_500_500[50] = "";
  s21_sprintf(test_str_500, "%-20i", -67890123);
  sprintf(test_str_500_500, "%-20i", -67890123);
  ck_assert_str_eq(test_str_500, test_str_500_500);
}
END_TEST

START_TEST(sprintf_test_501) {
  char test_str_501[50] = "";
  char test_str_501_501[50] = "";
  s21_sprintf(test_str_501, "%-20i", 4343);
  sprintf(test_str_501_501, "%-20i", 4343);
  ck_assert_str_eq(test_str_501, test_str_501_501);
}
END_TEST

START_TEST(sprintf_test_502) {
  char test_str_502[50] = "";
  char test_str_502_502[50] = "";
  s21_sprintf(test_str_502, "%-20i", -1);
  sprintf(test_str_502_502, "%-20i", -1);
  ck_assert_str_eq(test_str_502, test_str_502_502);
}
END_TEST

START_TEST(sprintf_test_503) {
  char test_str_503[50] = "";
  char test_str_503_503[50] = "";
  s21_sprintf(test_str_503, "%-20i", -10);
  sprintf(test_str_503_503, "%-20i", -10);
  ck_assert_str_eq(test_str_503, test_str_503_503);
}
END_TEST

START_TEST(sprintf_test_504) {
  char test_str_504[50] = "";
  char test_str_504_504[50] = "";
  s21_sprintf(test_str_504, "%-20i", 43);
  sprintf(test_str_504_504, "%-20i", 43);
  ck_assert_str_eq(test_str_504, test_str_504_504);
}
END_TEST

START_TEST(sprintf_test_505) {
  char test_str_505[50] = "";
  char test_str_505_505[50] = "";
  s21_sprintf(test_str_505, "%-20o", 0);
  sprintf(test_str_505_505, "%-20o", 0);
  ck_assert_str_eq(test_str_505, test_str_505_505);
}
END_TEST

START_TEST(sprintf_test_506) {
  char test_str_506[50] = "";
  char test_str_506_506[50] = "";
  s21_sprintf(test_str_506, "%-20o", 1);
  sprintf(test_str_506_506, "%-20o", 1);
  ck_assert_str_eq(test_str_506, test_str_506_506);
}
END_TEST

START_TEST(sprintf_test_507) {
  char test_str_507[50] = "";
  char test_str_507_507[50] = "";
  s21_sprintf(test_str_507, "%-20o", 10);
  sprintf(test_str_507_507, "%-20o", 10);
  ck_assert_str_eq(test_str_507, test_str_507_507);
}
END_TEST

START_TEST(sprintf_test_508) {
  char test_str_508[50] = "";
  char test_str_508_508[50] = "";
  s21_sprintf(test_str_508, "%-20o", 123456);
  sprintf(test_str_508_508, "%-20o", 123456);
  ck_assert_str_eq(test_str_508, test_str_508_508);
}
END_TEST

START_TEST(sprintf_test_509) {
  char test_str_509[50] = "";
  char test_str_509_509[50] = "";
  s21_sprintf(test_str_509, "%-20o", -67890123);
  sprintf(test_str_509_509, "%-20o", -67890123);
  ck_assert_str_eq(test_str_509, test_str_509_509);
}
END_TEST

START_TEST(sprintf_test_510) {
  char test_str_510[50] = "";
  char test_str_510_510[50] = "";
  s21_sprintf(test_str_510, "%-20o", 4343);
  sprintf(test_str_510_510, "%-20o", 4343);
  ck_assert_str_eq(test_str_510, test_str_510_510);
}
END_TEST

START_TEST(sprintf_test_511) {
  char test_str_511[50] = "";
  char test_str_511_511[50] = "";
  s21_sprintf(test_str_511, "%-20o", -1);
  sprintf(test_str_511_511, "%-20o", -1);
  ck_assert_str_eq(test_str_511, test_str_511_511);
}
END_TEST

START_TEST(sprintf_test_512) {
  char test_str_512[50] = "";
  char test_str_512_512[50] = "";
  s21_sprintf(test_str_512, "%-20o", -10);
  sprintf(test_str_512_512, "%-20o", -10);
  ck_assert_str_eq(test_str_512, test_str_512_512);
}
END_TEST

START_TEST(sprintf_test_513) {
  char test_str_513[50] = "";
  char test_str_513_513[50] = "";
  s21_sprintf(test_str_513, "%-20o", 43);
  sprintf(test_str_513_513, "%-20o", 43);
  ck_assert_str_eq(test_str_513, test_str_513_513);
}
END_TEST

START_TEST(sprintf_test_514) {
  char test_str_514[50] = "";
  char test_str_514_514[50] = "";
  s21_sprintf(test_str_514, "%-20u", 0);
  sprintf(test_str_514_514, "%-20u", 0);
  ck_assert_str_eq(test_str_514, test_str_514_514);
}
END_TEST

START_TEST(sprintf_test_515) {
  char test_str_515[50] = "";
  char test_str_515_515[50] = "";
  s21_sprintf(test_str_515, "%-20u", 1);
  sprintf(test_str_515_515, "%-20u", 1);
  ck_assert_str_eq(test_str_515, test_str_515_515);
}
END_TEST

START_TEST(sprintf_test_516) {
  char test_str_516[50] = "";
  char test_str_516_516[50] = "";
  s21_sprintf(test_str_516, "%-20u", 10);
  sprintf(test_str_516_516, "%-20u", 10);
  ck_assert_str_eq(test_str_516, test_str_516_516);
}
END_TEST

START_TEST(sprintf_test_517) {
  char test_str_517[50] = "";
  char test_str_517_517[50] = "";
  s21_sprintf(test_str_517, "%-20u", 123456);
  sprintf(test_str_517_517, "%-20u", 123456);
  ck_assert_str_eq(test_str_517, test_str_517_517);
}
END_TEST

START_TEST(sprintf_test_518) {
  char test_str_518[50] = "";
  char test_str_518_518[50] = "";
  s21_sprintf(test_str_518, "%-20u", -67890123);
  sprintf(test_str_518_518, "%-20u", -67890123);
  ck_assert_str_eq(test_str_518, test_str_518_518);
}
END_TEST

START_TEST(sprintf_test_519) {
  char test_str_519[50] = "";
  char test_str_519_519[50] = "";
  s21_sprintf(test_str_519, "%-20u", 4343);
  sprintf(test_str_519_519, "%-20u", 4343);
  ck_assert_str_eq(test_str_519, test_str_519_519);
}
END_TEST

START_TEST(sprintf_test_520) {
  char test_str_520[50] = "";
  char test_str_520_520[50] = "";
  s21_sprintf(test_str_520, "%-20u", -1);
  sprintf(test_str_520_520, "%-20u", -1);
  ck_assert_str_eq(test_str_520, test_str_520_520);
}
END_TEST

START_TEST(sprintf_test_521) {
  char test_str_521[50] = "";
  char test_str_521_521[50] = "";
  s21_sprintf(test_str_521, "%-20u", -10);
  sprintf(test_str_521_521, "%-20u", -10);
  ck_assert_str_eq(test_str_521, test_str_521_521);
}
END_TEST

START_TEST(sprintf_test_522) {
  char test_str_522[50] = "";
  char test_str_522_522[50] = "";
  s21_sprintf(test_str_522, "%-20u", 43);
  sprintf(test_str_522_522, "%-20u", 43);
  ck_assert_str_eq(test_str_522, test_str_522_522);
}
END_TEST

START_TEST(sprintf_test_523) {
  char test_str_523[50] = "";
  char test_str_523_523[50] = "";
  s21_sprintf(test_str_523, "%-20x", 0);
  sprintf(test_str_523_523, "%-20x", 0);
  ck_assert_str_eq(test_str_523, test_str_523_523);
}
END_TEST

START_TEST(sprintf_test_524) {
  char test_str_524[50] = "";
  char test_str_524_524[50] = "";
  s21_sprintf(test_str_524, "%-20x", 1);
  sprintf(test_str_524_524, "%-20x", 1);
  ck_assert_str_eq(test_str_524, test_str_524_524);
}
END_TEST

START_TEST(sprintf_test_525) {
  char test_str_525[50] = "";
  char test_str_525_525[50] = "";
  s21_sprintf(test_str_525, "%-20x", 10);
  sprintf(test_str_525_525, "%-20x", 10);
  ck_assert_str_eq(test_str_525, test_str_525_525);
}
END_TEST

START_TEST(sprintf_test_526) {
  char test_str_526[50] = "";
  char test_str_526_526[50] = "";
  s21_sprintf(test_str_526, "%-20x", 123456);
  sprintf(test_str_526_526, "%-20x", 123456);
  ck_assert_str_eq(test_str_526, test_str_526_526);
}
END_TEST

START_TEST(sprintf_test_527) {
  char test_str_527[50] = "";
  char test_str_527_527[50] = "";
  s21_sprintf(test_str_527, "%-20x", -67890123);
  sprintf(test_str_527_527, "%-20x", -67890123);
  ck_assert_str_eq(test_str_527, test_str_527_527);
}
END_TEST

START_TEST(sprintf_test_528) {
  char test_str_528[50] = "";
  char test_str_528_528[50] = "";
  s21_sprintf(test_str_528, "%-20x", 4343);
  sprintf(test_str_528_528, "%-20x", 4343);
  ck_assert_str_eq(test_str_528, test_str_528_528);
}
END_TEST

START_TEST(sprintf_test_529) {
  char test_str_529[50] = "";
  char test_str_529_529[50] = "";
  s21_sprintf(test_str_529, "%-20x", -1);
  sprintf(test_str_529_529, "%-20x", -1);
  ck_assert_str_eq(test_str_529, test_str_529_529);
}
END_TEST

START_TEST(sprintf_test_530) {
  char test_str_530[50] = "";
  char test_str_530_530[50] = "";
  s21_sprintf(test_str_530, "%-20x", -10);
  sprintf(test_str_530_530, "%-20x", -10);
  ck_assert_str_eq(test_str_530, test_str_530_530);
}
END_TEST

START_TEST(sprintf_test_531) {
  char test_str_531[50] = "";
  char test_str_531_531[50] = "";
  s21_sprintf(test_str_531, "%-20x", 43);
  sprintf(test_str_531_531, "%-20x", 43);
  ck_assert_str_eq(test_str_531, test_str_531_531);
}
END_TEST

START_TEST(sprintf_test_532) {
  char test_str_532[50] = "";
  char test_str_532_532[50] = "";
  s21_sprintf(test_str_532, "%-20X", 0);
  sprintf(test_str_532_532, "%-20X", 0);
  ck_assert_str_eq(test_str_532, test_str_532_532);
}
END_TEST

START_TEST(sprintf_test_533) {
  char test_str_533[50] = "";
  char test_str_533_533[50] = "";
  s21_sprintf(test_str_533, "%-20X", 1);
  sprintf(test_str_533_533, "%-20X", 1);
  ck_assert_str_eq(test_str_533, test_str_533_533);
}
END_TEST

START_TEST(sprintf_test_534) {
  char test_str_534[50] = "";
  char test_str_534_534[50] = "";
  s21_sprintf(test_str_534, "%-20X", 10);
  sprintf(test_str_534_534, "%-20X", 10);
  ck_assert_str_eq(test_str_534, test_str_534_534);
}
END_TEST

START_TEST(sprintf_test_535) {
  char test_str_535[50] = "";
  char test_str_535_535[50] = "";
  s21_sprintf(test_str_535, "%-20X", 123456);
  sprintf(test_str_535_535, "%-20X", 123456);
  ck_assert_str_eq(test_str_535, test_str_535_535);
}
END_TEST

START_TEST(sprintf_test_536) {
  char test_str_536[50] = "";
  char test_str_536_536[50] = "";
  s21_sprintf(test_str_536, "%-20X", -67890123);
  sprintf(test_str_536_536, "%-20X", -67890123);
  ck_assert_str_eq(test_str_536, test_str_536_536);
}
END_TEST

START_TEST(sprintf_test_537) {
  char test_str_537[50] = "";
  char test_str_537_537[50] = "";
  s21_sprintf(test_str_537, "%-20X", 4343);
  sprintf(test_str_537_537, "%-20X", 4343);
  ck_assert_str_eq(test_str_537, test_str_537_537);
}
END_TEST

START_TEST(sprintf_test_538) {
  char test_str_538[50] = "";
  char test_str_538_538[50] = "";
  s21_sprintf(test_str_538, "%-20X", -1);
  sprintf(test_str_538_538, "%-20X", -1);
  ck_assert_str_eq(test_str_538, test_str_538_538);
}
END_TEST

START_TEST(sprintf_test_539) {
  char test_str_539[50] = "";
  char test_str_539_539[50] = "";
  s21_sprintf(test_str_539, "%-20X", -10);
  sprintf(test_str_539_539, "%-20X", -10);
  ck_assert_str_eq(test_str_539, test_str_539_539);
}
END_TEST

START_TEST(sprintf_test_540) {
  char test_str_540[50] = "";
  char test_str_540_540[50] = "";
  s21_sprintf(test_str_540, "%-20X", 43);
  sprintf(test_str_540_540, "%-20X", 43);
  ck_assert_str_eq(test_str_540, test_str_540_540);
}
END_TEST

START_TEST(sprintf_test_541) {
  char test_str_541[50] = "";
  char test_str_541_541[50] = "";
  s21_sprintf(test_str_541, "%*d", 0, 0);
  sprintf(test_str_541_541, "%*d", 0, 0);
  ck_assert_str_eq(test_str_541, test_str_541_541);
}
END_TEST

START_TEST(sprintf_test_542) {
  char test_str_542[50] = "";
  char test_str_542_542[50] = "";
  s21_sprintf(test_str_542, "%*d", 0, 1);
  sprintf(test_str_542_542, "%*d", 0, 1);
  ck_assert_str_eq(test_str_542, test_str_542_542);
}
END_TEST

START_TEST(sprintf_test_543) {
  char test_str_543[50] = "";
  char test_str_543_543[50] = "";
  s21_sprintf(test_str_543, "%*d", 0, 10);
  sprintf(test_str_543_543, "%*d", 0, 10);
  ck_assert_str_eq(test_str_543, test_str_543_543);
}
END_TEST

START_TEST(sprintf_test_544) {
  char test_str_544[50] = "";
  char test_str_544_544[50] = "";
  s21_sprintf(test_str_544, "%*d", 0, 123456);
  sprintf(test_str_544_544, "%*d", 0, 123456);
  ck_assert_str_eq(test_str_544, test_str_544_544);
}
END_TEST

START_TEST(sprintf_test_545) {
  char test_str_545[50] = "";
  char test_str_545_545[50] = "";
  s21_sprintf(test_str_545, "%*d", 0, -67890123);
  sprintf(test_str_545_545, "%*d", 0, -67890123);
  ck_assert_str_eq(test_str_545, test_str_545_545);
}
END_TEST

START_TEST(sprintf_test_546) {
  char test_str_546[50] = "";
  char test_str_546_546[50] = "";
  s21_sprintf(test_str_546, "%*d", 0, 4343);
  sprintf(test_str_546_546, "%*d", 0, 4343);
  ck_assert_str_eq(test_str_546, test_str_546_546);
}
END_TEST

START_TEST(sprintf_test_547) {
  char test_str_547[50] = "";
  char test_str_547_547[50] = "";
  s21_sprintf(test_str_547, "%*d", 0, -1);
  sprintf(test_str_547_547, "%*d", 0, -1);
  ck_assert_str_eq(test_str_547, test_str_547_547);
}
END_TEST

START_TEST(sprintf_test_548) {
  char test_str_548[50] = "";
  char test_str_548_548[50] = "";
  s21_sprintf(test_str_548, "%*d", 0, -10);
  sprintf(test_str_548_548, "%*d", 0, -10);
  ck_assert_str_eq(test_str_548, test_str_548_548);
}
END_TEST

START_TEST(sprintf_test_549) {
  char test_str_549[50] = "";
  char test_str_549_549[50] = "";
  s21_sprintf(test_str_549, "%*d", 0, 43);
  sprintf(test_str_549_549, "%*d", 0, 43);
  ck_assert_str_eq(test_str_549, test_str_549_549);
}
END_TEST

START_TEST(sprintf_test_550) {
  char test_str_550[50] = "";
  char test_str_550_550[50] = "";
  s21_sprintf(test_str_550, "%*i", 0, 0);
  sprintf(test_str_550_550, "%*i", 0, 0);
  ck_assert_str_eq(test_str_550, test_str_550_550);
}
END_TEST

START_TEST(sprintf_test_551) {
  char test_str_551[50] = "";
  char test_str_551_551[50] = "";
  s21_sprintf(test_str_551, "%*i", 0, 1);
  sprintf(test_str_551_551, "%*i", 0, 1);
  ck_assert_str_eq(test_str_551, test_str_551_551);
}
END_TEST

START_TEST(sprintf_test_552) {
  char test_str_552[50] = "";
  char test_str_552_552[50] = "";
  s21_sprintf(test_str_552, "%*i", 0, 10);
  sprintf(test_str_552_552, "%*i", 0, 10);
  ck_assert_str_eq(test_str_552, test_str_552_552);
}
END_TEST

START_TEST(sprintf_test_553) {
  char test_str_553[50] = "";
  char test_str_553_553[50] = "";
  s21_sprintf(test_str_553, "%*i", 0, 123456);
  sprintf(test_str_553_553, "%*i", 0, 123456);
  ck_assert_str_eq(test_str_553, test_str_553_553);
}
END_TEST

START_TEST(sprintf_test_554) {
  char test_str_554[50] = "";
  char test_str_554_554[50] = "";
  s21_sprintf(test_str_554, "%*i", 0, -67890123);
  sprintf(test_str_554_554, "%*i", 0, -67890123);
  ck_assert_str_eq(test_str_554, test_str_554_554);
}
END_TEST

START_TEST(sprintf_test_555) {
  char test_str_555[50] = "";
  char test_str_555_555[50] = "";
  s21_sprintf(test_str_555, "%*i", 0, 4343);
  sprintf(test_str_555_555, "%*i", 0, 4343);
  ck_assert_str_eq(test_str_555, test_str_555_555);
}
END_TEST

START_TEST(sprintf_test_556) {
  char test_str_556[50] = "";
  char test_str_556_556[50] = "";
  s21_sprintf(test_str_556, "%*i", 0, -1);
  sprintf(test_str_556_556, "%*i", 0, -1);
  ck_assert_str_eq(test_str_556, test_str_556_556);
}
END_TEST

START_TEST(sprintf_test_557) {
  char test_str_557[50] = "";
  char test_str_557_557[50] = "";
  s21_sprintf(test_str_557, "%*i", 0, -10);
  sprintf(test_str_557_557, "%*i", 0, -10);
  ck_assert_str_eq(test_str_557, test_str_557_557);
}
END_TEST

START_TEST(sprintf_test_558) {
  char test_str_558[50] = "";
  char test_str_558_558[50] = "";
  s21_sprintf(test_str_558, "%*i", 0, 43);
  sprintf(test_str_558_558, "%*i", 0, 43);
  ck_assert_str_eq(test_str_558, test_str_558_558);
}
END_TEST

START_TEST(sprintf_test_559) {
  char test_str_559[50] = "";
  char test_str_559_559[50] = "";
  s21_sprintf(test_str_559, "%*o", 0, 0);
  sprintf(test_str_559_559, "%*o", 0, 0);
  ck_assert_str_eq(test_str_559, test_str_559_559);
}
END_TEST

START_TEST(sprintf_test_560) {
  char test_str_560[50] = "";
  char test_str_560_560[50] = "";
  s21_sprintf(test_str_560, "%*o", 0, 1);
  sprintf(test_str_560_560, "%*o", 0, 1);
  ck_assert_str_eq(test_str_560, test_str_560_560);
}
END_TEST

START_TEST(sprintf_test_561) {
  char test_str_561[50] = "";
  char test_str_561_561[50] = "";
  s21_sprintf(test_str_561, "%*o", 0, 10);
  sprintf(test_str_561_561, "%*o", 0, 10);
  ck_assert_str_eq(test_str_561, test_str_561_561);
}
END_TEST

START_TEST(sprintf_test_562) {
  char test_str_562[50] = "";
  char test_str_562_562[50] = "";
  s21_sprintf(test_str_562, "%*o", 0, 123456);
  sprintf(test_str_562_562, "%*o", 0, 123456);
  ck_assert_str_eq(test_str_562, test_str_562_562);
}
END_TEST

START_TEST(sprintf_test_563) {
  char test_str_563[50] = "";
  char test_str_563_563[50] = "";
  s21_sprintf(test_str_563, "%*o", 0, -67890123);
  sprintf(test_str_563_563, "%*o", 0, -67890123);
  ck_assert_str_eq(test_str_563, test_str_563_563);
}
END_TEST

START_TEST(sprintf_test_564) {
  char test_str_564[50] = "";
  char test_str_564_564[50] = "";
  s21_sprintf(test_str_564, "%*o", 0, 4343);
  sprintf(test_str_564_564, "%*o", 0, 4343);
  ck_assert_str_eq(test_str_564, test_str_564_564);
}
END_TEST

START_TEST(sprintf_test_565) {
  char test_str_565[50] = "";
  char test_str_565_565[50] = "";
  s21_sprintf(test_str_565, "%*o", 0, -1);
  sprintf(test_str_565_565, "%*o", 0, -1);
  ck_assert_str_eq(test_str_565, test_str_565_565);
}
END_TEST

START_TEST(sprintf_test_566) {
  char test_str_566[50] = "";
  char test_str_566_566[50] = "";
  s21_sprintf(test_str_566, "%*o", 0, -10);
  sprintf(test_str_566_566, "%*o", 0, -10);
  ck_assert_str_eq(test_str_566, test_str_566_566);
}
END_TEST

START_TEST(sprintf_test_567) {
  char test_str_567[50] = "";
  char test_str_567_567[50] = "";
  s21_sprintf(test_str_567, "%*o", 0, 43);
  sprintf(test_str_567_567, "%*o", 0, 43);
  ck_assert_str_eq(test_str_567, test_str_567_567);
}
END_TEST

START_TEST(sprintf_test_568) {
  char test_str_568[50] = "";
  char test_str_568_568[50] = "";
  s21_sprintf(test_str_568, "%*u", 0, 0);
  sprintf(test_str_568_568, "%*u", 0, 0);
  ck_assert_str_eq(test_str_568, test_str_568_568);
}
END_TEST

START_TEST(sprintf_test_569) {
  char test_str_569[50] = "";
  char test_str_569_569[50] = "";
  s21_sprintf(test_str_569, "%*u", 0, 1);
  sprintf(test_str_569_569, "%*u", 0, 1);
  ck_assert_str_eq(test_str_569, test_str_569_569);
}
END_TEST

START_TEST(sprintf_test_570) {
  char test_str_570[50] = "";
  char test_str_570_570[50] = "";
  s21_sprintf(test_str_570, "%*u", 0, 10);
  sprintf(test_str_570_570, "%*u", 0, 10);
  ck_assert_str_eq(test_str_570, test_str_570_570);
}
END_TEST

START_TEST(sprintf_test_571) {
  char test_str_571[50] = "";
  char test_str_571_571[50] = "";
  s21_sprintf(test_str_571, "%*u", 0, 123456);
  sprintf(test_str_571_571, "%*u", 0, 123456);
  ck_assert_str_eq(test_str_571, test_str_571_571);
}
END_TEST

START_TEST(sprintf_test_572) {
  char test_str_572[50] = "";
  char test_str_572_572[50] = "";
  s21_sprintf(test_str_572, "%*u", 0, -67890123);
  sprintf(test_str_572_572, "%*u", 0, -67890123);
  ck_assert_str_eq(test_str_572, test_str_572_572);
}
END_TEST

START_TEST(sprintf_test_573) {
  char test_str_573[50] = "";
  char test_str_573_573[50] = "";
  s21_sprintf(test_str_573, "%*u", 0, 4343);
  sprintf(test_str_573_573, "%*u", 0, 4343);
  ck_assert_str_eq(test_str_573, test_str_573_573);
}
END_TEST

START_TEST(sprintf_test_574) {
  char test_str_574[50] = "";
  char test_str_574_574[50] = "";
  s21_sprintf(test_str_574, "%*u", 0, -1);
  sprintf(test_str_574_574, "%*u", 0, -1);
  ck_assert_str_eq(test_str_574, test_str_574_574);
}
END_TEST

START_TEST(sprintf_test_575) {
  char test_str_575[50] = "";
  char test_str_575_575[50] = "";
  s21_sprintf(test_str_575, "%*u", 0, -10);
  sprintf(test_str_575_575, "%*u", 0, -10);
  ck_assert_str_eq(test_str_575, test_str_575_575);
}
END_TEST

START_TEST(sprintf_test_576) {
  char test_str_576[50] = "";
  char test_str_576_576[50] = "";
  s21_sprintf(test_str_576, "%*u", 0, 43);
  sprintf(test_str_576_576, "%*u", 0, 43);
  ck_assert_str_eq(test_str_576, test_str_576_576);
}
END_TEST

START_TEST(sprintf_test_577) {
  char test_str_577[50] = "";
  char test_str_577_577[50] = "";
  s21_sprintf(test_str_577, "%*x", 0, 0);
  sprintf(test_str_577_577, "%*x", 0, 0);
  ck_assert_str_eq(test_str_577, test_str_577_577);
}
END_TEST

START_TEST(sprintf_test_578) {
  char test_str_578[50] = "";
  char test_str_578_578[50] = "";
  s21_sprintf(test_str_578, "%*x", 0, 1);
  sprintf(test_str_578_578, "%*x", 0, 1);
  ck_assert_str_eq(test_str_578, test_str_578_578);
}
END_TEST

START_TEST(sprintf_test_579) {
  char test_str_579[50] = "";
  char test_str_579_579[50] = "";
  s21_sprintf(test_str_579, "%*x", 0, 10);
  sprintf(test_str_579_579, "%*x", 0, 10);
  ck_assert_str_eq(test_str_579, test_str_579_579);
}
END_TEST

START_TEST(sprintf_test_580) {
  char test_str_580[50] = "";
  char test_str_580_580[50] = "";
  s21_sprintf(test_str_580, "%*x", 0, 123456);
  sprintf(test_str_580_580, "%*x", 0, 123456);
  ck_assert_str_eq(test_str_580, test_str_580_580);
}
END_TEST

START_TEST(sprintf_test_581) {
  char test_str_581[50] = "";
  char test_str_581_581[50] = "";
  s21_sprintf(test_str_581, "%*x", 0, -67890123);
  sprintf(test_str_581_581, "%*x", 0, -67890123);
  ck_assert_str_eq(test_str_581, test_str_581_581);
}
END_TEST

START_TEST(sprintf_test_582) {
  char test_str_582[50] = "";
  char test_str_582_582[50] = "";
  s21_sprintf(test_str_582, "%*x", 0, 4343);
  sprintf(test_str_582_582, "%*x", 0, 4343);
  ck_assert_str_eq(test_str_582, test_str_582_582);
}
END_TEST

START_TEST(sprintf_test_583) {
  char test_str_583[50] = "";
  char test_str_583_583[50] = "";
  s21_sprintf(test_str_583, "%*x", 0, -1);
  sprintf(test_str_583_583, "%*x", 0, -1);
  ck_assert_str_eq(test_str_583, test_str_583_583);
}
END_TEST

START_TEST(sprintf_test_584) {
  char test_str_584[50] = "";
  char test_str_584_584[50] = "";
  s21_sprintf(test_str_584, "%*x", 0, -10);
  sprintf(test_str_584_584, "%*x", 0, -10);
  ck_assert_str_eq(test_str_584, test_str_584_584);
}
END_TEST

START_TEST(sprintf_test_585) {
  char test_str_585[50] = "";
  char test_str_585_585[50] = "";
  s21_sprintf(test_str_585, "%*x", 0, 43);
  sprintf(test_str_585_585, "%*x", 0, 43);
  ck_assert_str_eq(test_str_585, test_str_585_585);
}
END_TEST

START_TEST(sprintf_test_586) {
  char test_str_586[50] = "";
  char test_str_586_586[50] = "";
  s21_sprintf(test_str_586, "%*X", 0, 0);
  sprintf(test_str_586_586, "%*X", 0, 0);
  ck_assert_str_eq(test_str_586, test_str_586_586);
}
END_TEST

START_TEST(sprintf_test_587) {
  char test_str_587[50] = "";
  char test_str_587_587[50] = "";
  s21_sprintf(test_str_587, "%*X", 0, 1);
  sprintf(test_str_587_587, "%*X", 0, 1);
  ck_assert_str_eq(test_str_587, test_str_587_587);
}
END_TEST

START_TEST(sprintf_test_588) {
  char test_str_588[50] = "";
  char test_str_588_588[50] = "";
  s21_sprintf(test_str_588, "%*X", 0, 10);
  sprintf(test_str_588_588, "%*X", 0, 10);
  ck_assert_str_eq(test_str_588, test_str_588_588);
}
END_TEST

START_TEST(sprintf_test_589) {
  char test_str_589[50] = "";
  char test_str_589_589[50] = "";
  s21_sprintf(test_str_589, "%*X", 0, 123456);
  sprintf(test_str_589_589, "%*X", 0, 123456);
  ck_assert_str_eq(test_str_589, test_str_589_589);
}
END_TEST

START_TEST(sprintf_test_590) {
  char test_str_590[50] = "";
  char test_str_590_590[50] = "";
  s21_sprintf(test_str_590, "%*X", 0, -67890123);
  sprintf(test_str_590_590, "%*X", 0, -67890123);
  ck_assert_str_eq(test_str_590, test_str_590_590);
}
END_TEST

START_TEST(sprintf_test_591) {
  char test_str_591[50] = "";
  char test_str_591_591[50] = "";
  s21_sprintf(test_str_591, "%*X", 0, 4343);
  sprintf(test_str_591_591, "%*X", 0, 4343);
  ck_assert_str_eq(test_str_591, test_str_591_591);
}
END_TEST

START_TEST(sprintf_test_592) {
  char test_str_592[50] = "";
  char test_str_592_592[50] = "";
  s21_sprintf(test_str_592, "%*X", 0, -1);
  sprintf(test_str_592_592, "%*X", 0, -1);
  ck_assert_str_eq(test_str_592, test_str_592_592);
}
END_TEST

START_TEST(sprintf_test_593) {
  char test_str_593[50] = "";
  char test_str_593_593[50] = "";
  s21_sprintf(test_str_593, "%*X", 0, -10);
  sprintf(test_str_593_593, "%*X", 0, -10);
  ck_assert_str_eq(test_str_593, test_str_593_593);
}
END_TEST

START_TEST(sprintf_test_594) {
  char test_str_594[50] = "";
  char test_str_594_594[50] = "";
  s21_sprintf(test_str_594, "%*X", 0, 43);
  sprintf(test_str_594_594, "%*X", 0, 43);
  ck_assert_str_eq(test_str_594, test_str_594_594);
}
END_TEST

START_TEST(sprintf_test_595) {
  char test_str_595[50] = "";
  char test_str_595_595[50] = "";
  s21_sprintf(test_str_595, "%*d", 10, 0);
  sprintf(test_str_595_595, "%*d", 10, 0);
  ck_assert_str_eq(test_str_595, test_str_595_595);
}
END_TEST

START_TEST(sprintf_test_596) {
  char test_str_596[50] = "";
  char test_str_596_596[50] = "";
  s21_sprintf(test_str_596, "%*d", 10, 1);
  sprintf(test_str_596_596, "%*d", 10, 1);
  ck_assert_str_eq(test_str_596, test_str_596_596);
}
END_TEST

START_TEST(sprintf_test_597) {
  char test_str_597[50] = "";
  char test_str_597_597[50] = "";
  s21_sprintf(test_str_597, "%*d", 10, 10);
  sprintf(test_str_597_597, "%*d", 10, 10);
  ck_assert_str_eq(test_str_597, test_str_597_597);
}
END_TEST

START_TEST(sprintf_test_598) {
  char test_str_598[50] = "";
  char test_str_598_598[50] = "";
  s21_sprintf(test_str_598, "%*d", 10, 123456);
  sprintf(test_str_598_598, "%*d", 10, 123456);
  ck_assert_str_eq(test_str_598, test_str_598_598);
}
END_TEST

START_TEST(sprintf_test_599) {
  char test_str_599[50] = "";
  char test_str_599_599[50] = "";
  s21_sprintf(test_str_599, "%*d", 10, -67890123);
  sprintf(test_str_599_599, "%*d", 10, -67890123);
  ck_assert_str_eq(test_str_599, test_str_599_599);
}
END_TEST

START_TEST(sprintf_test_600) {
  char test_str_600[50] = "";
  char test_str_600_600[50] = "";
  s21_sprintf(test_str_600, "%*d", 10, 4343);
  sprintf(test_str_600_600, "%*d", 10, 4343);
  ck_assert_str_eq(test_str_600, test_str_600_600);
}
END_TEST

START_TEST(sprintf_test_601) {
  char test_str_601[50] = "";
  char test_str_601_601[50] = "";
  s21_sprintf(test_str_601, "%*d", 10, -1);
  sprintf(test_str_601_601, "%*d", 10, -1);
  ck_assert_str_eq(test_str_601, test_str_601_601);
}
END_TEST

START_TEST(sprintf_test_602) {
  char test_str_602[50] = "";
  char test_str_602_602[50] = "";
  s21_sprintf(test_str_602, "%*d", 10, -10);
  sprintf(test_str_602_602, "%*d", 10, -10);
  ck_assert_str_eq(test_str_602, test_str_602_602);
}
END_TEST

START_TEST(sprintf_test_603) {
  char test_str_603[50] = "";
  char test_str_603_603[50] = "";
  s21_sprintf(test_str_603, "%*d", 10, 43);
  sprintf(test_str_603_603, "%*d", 10, 43);
  ck_assert_str_eq(test_str_603, test_str_603_603);
}
END_TEST

START_TEST(sprintf_test_604) {
  char test_str_604[50] = "";
  char test_str_604_604[50] = "";
  s21_sprintf(test_str_604, "%*i", 10, 0);
  sprintf(test_str_604_604, "%*i", 10, 0);
  ck_assert_str_eq(test_str_604, test_str_604_604);
}
END_TEST

START_TEST(sprintf_test_605) {
  char test_str_605[50] = "";
  char test_str_605_605[50] = "";
  s21_sprintf(test_str_605, "%*i", 10, 1);
  sprintf(test_str_605_605, "%*i", 10, 1);
  ck_assert_str_eq(test_str_605, test_str_605_605);
}
END_TEST

START_TEST(sprintf_test_606) {
  char test_str_606[50] = "";
  char test_str_606_606[50] = "";
  s21_sprintf(test_str_606, "%*i", 10, 10);
  sprintf(test_str_606_606, "%*i", 10, 10);
  ck_assert_str_eq(test_str_606, test_str_606_606);
}
END_TEST

START_TEST(sprintf_test_607) {
  char test_str_607[50] = "";
  char test_str_607_607[50] = "";
  s21_sprintf(test_str_607, "%*i", 10, 123456);
  sprintf(test_str_607_607, "%*i", 10, 123456);
  ck_assert_str_eq(test_str_607, test_str_607_607);
}
END_TEST

START_TEST(sprintf_test_608) {
  char test_str_608[50] = "";
  char test_str_608_608[50] = "";
  s21_sprintf(test_str_608, "%*i", 10, -67890123);
  sprintf(test_str_608_608, "%*i", 10, -67890123);
  ck_assert_str_eq(test_str_608, test_str_608_608);
}
END_TEST

START_TEST(sprintf_test_609) {
  char test_str_609[50] = "";
  char test_str_609_609[50] = "";
  s21_sprintf(test_str_609, "%*i", 10, 4343);
  sprintf(test_str_609_609, "%*i", 10, 4343);
  ck_assert_str_eq(test_str_609, test_str_609_609);
}
END_TEST

START_TEST(sprintf_test_610) {
  char test_str_610[50] = "";
  char test_str_610_610[50] = "";
  s21_sprintf(test_str_610, "%*i", 10, -1);
  sprintf(test_str_610_610, "%*i", 10, -1);
  ck_assert_str_eq(test_str_610, test_str_610_610);
}
END_TEST

START_TEST(sprintf_test_611) {
  char test_str_611[50] = "";
  char test_str_611_611[50] = "";
  s21_sprintf(test_str_611, "%*i", 10, -10);
  sprintf(test_str_611_611, "%*i", 10, -10);
  ck_assert_str_eq(test_str_611, test_str_611_611);
}
END_TEST

START_TEST(sprintf_test_612) {
  char test_str_612[50] = "";
  char test_str_612_612[50] = "";
  s21_sprintf(test_str_612, "%*i", 10, 43);
  sprintf(test_str_612_612, "%*i", 10, 43);
  ck_assert_str_eq(test_str_612, test_str_612_612);
}
END_TEST

START_TEST(sprintf_test_613) {
  char test_str_613[50] = "";
  char test_str_613_613[50] = "";
  s21_sprintf(test_str_613, "%*o", 10, 0);
  sprintf(test_str_613_613, "%*o", 10, 0);
  ck_assert_str_eq(test_str_613, test_str_613_613);
}
END_TEST

START_TEST(sprintf_test_614) {
  char test_str_614[50] = "";
  char test_str_614_614[50] = "";
  s21_sprintf(test_str_614, "%*o", 10, 1);
  sprintf(test_str_614_614, "%*o", 10, 1);
  ck_assert_str_eq(test_str_614, test_str_614_614);
}
END_TEST

START_TEST(sprintf_test_615) {
  char test_str_615[50] = "";
  char test_str_615_615[50] = "";
  s21_sprintf(test_str_615, "%*o", 10, 10);
  sprintf(test_str_615_615, "%*o", 10, 10);
  ck_assert_str_eq(test_str_615, test_str_615_615);
}
END_TEST

START_TEST(sprintf_test_616) {
  char test_str_616[50] = "";
  char test_str_616_616[50] = "";
  s21_sprintf(test_str_616, "%*o", 10, 123456);
  sprintf(test_str_616_616, "%*o", 10, 123456);
  ck_assert_str_eq(test_str_616, test_str_616_616);
}
END_TEST

START_TEST(sprintf_test_617) {
  char test_str_617[50] = "";
  char test_str_617_617[50] = "";
  s21_sprintf(test_str_617, "%*o", 10, -67890123);
  sprintf(test_str_617_617, "%*o", 10, -67890123);
  ck_assert_str_eq(test_str_617, test_str_617_617);
}
END_TEST

START_TEST(sprintf_test_618) {
  char test_str_618[50] = "";
  char test_str_618_618[50] = "";
  s21_sprintf(test_str_618, "%*o", 10, 4343);
  sprintf(test_str_618_618, "%*o", 10, 4343);
  ck_assert_str_eq(test_str_618, test_str_618_618);
}
END_TEST

START_TEST(sprintf_test_619) {
  char test_str_619[50] = "";
  char test_str_619_619[50] = "";
  s21_sprintf(test_str_619, "%*o", 10, -1);
  sprintf(test_str_619_619, "%*o", 10, -1);
  ck_assert_str_eq(test_str_619, test_str_619_619);
}
END_TEST

START_TEST(sprintf_test_620) {
  char test_str_620[50] = "";
  char test_str_620_620[50] = "";
  s21_sprintf(test_str_620, "%*o", 10, -10);
  sprintf(test_str_620_620, "%*o", 10, -10);
  ck_assert_str_eq(test_str_620, test_str_620_620);
}
END_TEST

START_TEST(sprintf_test_621) {
  char test_str_621[50] = "";
  char test_str_621_621[50] = "";
  s21_sprintf(test_str_621, "%*o", 10, 43);
  sprintf(test_str_621_621, "%*o", 10, 43);
  ck_assert_str_eq(test_str_621, test_str_621_621);
}
END_TEST

START_TEST(sprintf_test_622) {
  char test_str_622[50] = "";
  char test_str_622_622[50] = "";
  s21_sprintf(test_str_622, "%*u", 10, 0);
  sprintf(test_str_622_622, "%*u", 10, 0);
  ck_assert_str_eq(test_str_622, test_str_622_622);
}
END_TEST

START_TEST(sprintf_test_623) {
  char test_str_623[50] = "";
  char test_str_623_623[50] = "";
  s21_sprintf(test_str_623, "%*u", 10, 1);
  sprintf(test_str_623_623, "%*u", 10, 1);
  ck_assert_str_eq(test_str_623, test_str_623_623);
}
END_TEST

START_TEST(sprintf_test_624) {
  char test_str_624[50] = "";
  char test_str_624_624[50] = "";
  s21_sprintf(test_str_624, "%*u", 10, 10);
  sprintf(test_str_624_624, "%*u", 10, 10);
  ck_assert_str_eq(test_str_624, test_str_624_624);
}
END_TEST

START_TEST(sprintf_test_625) {
  char test_str_625[50] = "";
  char test_str_625_625[50] = "";
  s21_sprintf(test_str_625, "%*u", 10, 123456);
  sprintf(test_str_625_625, "%*u", 10, 123456);
  ck_assert_str_eq(test_str_625, test_str_625_625);
}
END_TEST

START_TEST(sprintf_test_626) {
  char test_str_626[50] = "";
  char test_str_626_626[50] = "";
  s21_sprintf(test_str_626, "%*u", 10, -67890123);
  sprintf(test_str_626_626, "%*u", 10, -67890123);
  ck_assert_str_eq(test_str_626, test_str_626_626);
}
END_TEST

START_TEST(sprintf_test_627) {
  char test_str_627[50] = "";
  char test_str_627_627[50] = "";
  s21_sprintf(test_str_627, "%*u", 10, 4343);
  sprintf(test_str_627_627, "%*u", 10, 4343);
  ck_assert_str_eq(test_str_627, test_str_627_627);
}
END_TEST

START_TEST(sprintf_test_628) {
  char test_str_628[50] = "";
  char test_str_628_628[50] = "";
  s21_sprintf(test_str_628, "%*u", 10, -1);
  sprintf(test_str_628_628, "%*u", 10, -1);
  ck_assert_str_eq(test_str_628, test_str_628_628);
}
END_TEST

START_TEST(sprintf_test_629) {
  char test_str_629[50] = "";
  char test_str_629_629[50] = "";
  s21_sprintf(test_str_629, "%*u", 10, -10);
  sprintf(test_str_629_629, "%*u", 10, -10);
  ck_assert_str_eq(test_str_629, test_str_629_629);
}
END_TEST

START_TEST(sprintf_test_630) {
  char test_str_630[50] = "";
  char test_str_630_630[50] = "";
  s21_sprintf(test_str_630, "%*u", 10, 43);
  sprintf(test_str_630_630, "%*u", 10, 43);
  ck_assert_str_eq(test_str_630, test_str_630_630);
}
END_TEST

START_TEST(sprintf_test_631) {
  char test_str_631[50] = "";
  char test_str_631_631[50] = "";
  s21_sprintf(test_str_631, "%*x", 10, 0);
  sprintf(test_str_631_631, "%*x", 10, 0);
  ck_assert_str_eq(test_str_631, test_str_631_631);
}
END_TEST

START_TEST(sprintf_test_632) {
  char test_str_632[50] = "";
  char test_str_632_632[50] = "";
  s21_sprintf(test_str_632, "%*x", 10, 1);
  sprintf(test_str_632_632, "%*x", 10, 1);
  ck_assert_str_eq(test_str_632, test_str_632_632);
}
END_TEST

START_TEST(sprintf_test_633) {
  char test_str_633[50] = "";
  char test_str_633_633[50] = "";
  s21_sprintf(test_str_633, "%*x", 10, 10);
  sprintf(test_str_633_633, "%*x", 10, 10);
  ck_assert_str_eq(test_str_633, test_str_633_633);
}
END_TEST

START_TEST(sprintf_test_634) {
  char test_str_634[50] = "";
  char test_str_634_634[50] = "";
  s21_sprintf(test_str_634, "%*x", 10, 123456);
  sprintf(test_str_634_634, "%*x", 10, 123456);
  ck_assert_str_eq(test_str_634, test_str_634_634);
}
END_TEST

START_TEST(sprintf_test_635) {
  char test_str_635[50] = "";
  char test_str_635_635[50] = "";
  s21_sprintf(test_str_635, "%*x", 10, -67890123);
  sprintf(test_str_635_635, "%*x", 10, -67890123);
  ck_assert_str_eq(test_str_635, test_str_635_635);
}
END_TEST

START_TEST(sprintf_test_636) {
  char test_str_636[50] = "";
  char test_str_636_636[50] = "";
  s21_sprintf(test_str_636, "%*x", 10, 4343);
  sprintf(test_str_636_636, "%*x", 10, 4343);
  ck_assert_str_eq(test_str_636, test_str_636_636);
}
END_TEST

START_TEST(sprintf_test_637) {
  char test_str_637[50] = "";
  char test_str_637_637[50] = "";
  s21_sprintf(test_str_637, "%*x", 10, -1);
  sprintf(test_str_637_637, "%*x", 10, -1);
  ck_assert_str_eq(test_str_637, test_str_637_637);
}
END_TEST

START_TEST(sprintf_test_638) {
  char test_str_638[50] = "";
  char test_str_638_638[50] = "";
  s21_sprintf(test_str_638, "%*x", 10, -10);
  sprintf(test_str_638_638, "%*x", 10, -10);
  ck_assert_str_eq(test_str_638, test_str_638_638);
}
END_TEST

START_TEST(sprintf_test_639) {
  char test_str_639[50] = "";
  char test_str_639_639[50] = "";
  s21_sprintf(test_str_639, "%*x", 10, 43);
  sprintf(test_str_639_639, "%*x", 10, 43);
  ck_assert_str_eq(test_str_639, test_str_639_639);
}
END_TEST

START_TEST(sprintf_test_640) {
  char test_str_640[50] = "";
  char test_str_640_640[50] = "";
  s21_sprintf(test_str_640, "%*X", 10, 0);
  sprintf(test_str_640_640, "%*X", 10, 0);
  ck_assert_str_eq(test_str_640, test_str_640_640);
}
END_TEST

START_TEST(sprintf_test_641) {
  char test_str_641[50] = "";
  char test_str_641_641[50] = "";
  s21_sprintf(test_str_641, "%*X", 10, 1);
  sprintf(test_str_641_641, "%*X", 10, 1);
  ck_assert_str_eq(test_str_641, test_str_641_641);
}
END_TEST

START_TEST(sprintf_test_642) {
  char test_str_642[50] = "";
  char test_str_642_642[50] = "";
  s21_sprintf(test_str_642, "%*X", 10, 10);
  sprintf(test_str_642_642, "%*X", 10, 10);
  ck_assert_str_eq(test_str_642, test_str_642_642);
}
END_TEST

START_TEST(sprintf_test_643) {
  char test_str_643[50] = "";
  char test_str_643_643[50] = "";
  s21_sprintf(test_str_643, "%*X", 10, 123456);
  sprintf(test_str_643_643, "%*X", 10, 123456);
  ck_assert_str_eq(test_str_643, test_str_643_643);
}
END_TEST

START_TEST(sprintf_test_644) {
  char test_str_644[50] = "";
  char test_str_644_644[50] = "";
  s21_sprintf(test_str_644, "%*X", 10, -67890123);
  sprintf(test_str_644_644, "%*X", 10, -67890123);
  ck_assert_str_eq(test_str_644, test_str_644_644);
}
END_TEST

START_TEST(sprintf_test_645) {
  char test_str_645[50] = "";
  char test_str_645_645[50] = "";
  s21_sprintf(test_str_645, "%*X", 10, 4343);
  sprintf(test_str_645_645, "%*X", 10, 4343);
  ck_assert_str_eq(test_str_645, test_str_645_645);
}
END_TEST

START_TEST(sprintf_test_646) {
  char test_str_646[50] = "";
  char test_str_646_646[50] = "";
  s21_sprintf(test_str_646, "%*X", 10, -1);
  sprintf(test_str_646_646, "%*X", 10, -1);
  ck_assert_str_eq(test_str_646, test_str_646_646);
}
END_TEST

START_TEST(sprintf_test_647) {
  char test_str_647[50] = "";
  char test_str_647_647[50] = "";
  s21_sprintf(test_str_647, "%*X", 10, -10);
  sprintf(test_str_647_647, "%*X", 10, -10);
  ck_assert_str_eq(test_str_647, test_str_647_647);
}
END_TEST

START_TEST(sprintf_test_648) {
  char test_str_648[50] = "";
  char test_str_648_648[50] = "";
  s21_sprintf(test_str_648, "%*X", 10, 43);
  sprintf(test_str_648_648, "%*X", 10, 43);
  ck_assert_str_eq(test_str_648, test_str_648_648);
}
END_TEST

START_TEST(sprintf_test_649) {
  char test_str_649[50] = "";
  char test_str_649_649[50] = "";
  s21_sprintf(test_str_649, "%*d", 20, 0);
  sprintf(test_str_649_649, "%*d", 20, 0);
  ck_assert_str_eq(test_str_649, test_str_649_649);
}
END_TEST

START_TEST(sprintf_test_650) {
  char test_str_650[50] = "";
  char test_str_650_650[50] = "";
  s21_sprintf(test_str_650, "%*d", 20, 1);
  sprintf(test_str_650_650, "%*d", 20, 1);
  ck_assert_str_eq(test_str_650, test_str_650_650);
}
END_TEST

START_TEST(sprintf_test_651) {
  char test_str_651[50] = "";
  char test_str_651_651[50] = "";
  s21_sprintf(test_str_651, "%*d", 20, 10);
  sprintf(test_str_651_651, "%*d", 20, 10);
  ck_assert_str_eq(test_str_651, test_str_651_651);
}
END_TEST

START_TEST(sprintf_test_652) {
  char test_str_652[50] = "";
  char test_str_652_652[50] = "";
  s21_sprintf(test_str_652, "%*d", 20, 123456);
  sprintf(test_str_652_652, "%*d", 20, 123456);
  ck_assert_str_eq(test_str_652, test_str_652_652);
}
END_TEST

START_TEST(sprintf_test_653) {
  char test_str_653[50] = "";
  char test_str_653_653[50] = "";
  s21_sprintf(test_str_653, "%*d", 20, -67890123);
  sprintf(test_str_653_653, "%*d", 20, -67890123);
  ck_assert_str_eq(test_str_653, test_str_653_653);
}
END_TEST

START_TEST(sprintf_test_654) {
  char test_str_654[50] = "";
  char test_str_654_654[50] = "";
  s21_sprintf(test_str_654, "%*d", 20, 4343);
  sprintf(test_str_654_654, "%*d", 20, 4343);
  ck_assert_str_eq(test_str_654, test_str_654_654);
}
END_TEST

START_TEST(sprintf_test_655) {
  char test_str_655[50] = "";
  char test_str_655_655[50] = "";
  s21_sprintf(test_str_655, "%*d", 20, -1);
  sprintf(test_str_655_655, "%*d", 20, -1);
  ck_assert_str_eq(test_str_655, test_str_655_655);
}
END_TEST

START_TEST(sprintf_test_656) {
  char test_str_656[50] = "";
  char test_str_656_656[50] = "";
  s21_sprintf(test_str_656, "%*d", 20, -10);
  sprintf(test_str_656_656, "%*d", 20, -10);
  ck_assert_str_eq(test_str_656, test_str_656_656);
}
END_TEST

START_TEST(sprintf_test_657) {
  char test_str_657[50] = "";
  char test_str_657_657[50] = "";
  s21_sprintf(test_str_657, "%*d", 20, 43);
  sprintf(test_str_657_657, "%*d", 20, 43);
  ck_assert_str_eq(test_str_657, test_str_657_657);
}
END_TEST

START_TEST(sprintf_test_658) {
  char test_str_658[50] = "";
  char test_str_658_658[50] = "";
  s21_sprintf(test_str_658, "%*i", 20, 0);
  sprintf(test_str_658_658, "%*i", 20, 0);
  ck_assert_str_eq(test_str_658, test_str_658_658);
}
END_TEST

START_TEST(sprintf_test_659) {
  char test_str_659[50] = "";
  char test_str_659_659[50] = "";
  s21_sprintf(test_str_659, "%*i", 20, 1);
  sprintf(test_str_659_659, "%*i", 20, 1);
  ck_assert_str_eq(test_str_659, test_str_659_659);
}
END_TEST

START_TEST(sprintf_test_660) {
  char test_str_660[50] = "";
  char test_str_660_660[50] = "";
  s21_sprintf(test_str_660, "%*i", 20, 10);
  sprintf(test_str_660_660, "%*i", 20, 10);
  ck_assert_str_eq(test_str_660, test_str_660_660);
}
END_TEST

START_TEST(sprintf_test_661) {
  char test_str_661[50] = "";
  char test_str_661_661[50] = "";
  s21_sprintf(test_str_661, "%*i", 20, 123456);
  sprintf(test_str_661_661, "%*i", 20, 123456);
  ck_assert_str_eq(test_str_661, test_str_661_661);
}
END_TEST

START_TEST(sprintf_test_662) {
  char test_str_662[50] = "";
  char test_str_662_662[50] = "";
  s21_sprintf(test_str_662, "%*i", 20, -67890123);
  sprintf(test_str_662_662, "%*i", 20, -67890123);
  ck_assert_str_eq(test_str_662, test_str_662_662);
}
END_TEST

START_TEST(sprintf_test_663) {
  char test_str_663[50] = "";
  char test_str_663_663[50] = "";
  s21_sprintf(test_str_663, "%*i", 20, 4343);
  sprintf(test_str_663_663, "%*i", 20, 4343);
  ck_assert_str_eq(test_str_663, test_str_663_663);
}
END_TEST

START_TEST(sprintf_test_664) {
  char test_str_664[50] = "";
  char test_str_664_664[50] = "";
  s21_sprintf(test_str_664, "%*i", 20, -1);
  sprintf(test_str_664_664, "%*i", 20, -1);
  ck_assert_str_eq(test_str_664, test_str_664_664);
}
END_TEST

START_TEST(sprintf_test_665) {
  char test_str_665[50] = "";
  char test_str_665_665[50] = "";
  s21_sprintf(test_str_665, "%*i", 20, -10);
  sprintf(test_str_665_665, "%*i", 20, -10);
  ck_assert_str_eq(test_str_665, test_str_665_665);
}
END_TEST

START_TEST(sprintf_test_666) {
  char test_str_666[50] = "";
  char test_str_666_666[50] = "";
  s21_sprintf(test_str_666, "%*i", 20, 43);
  sprintf(test_str_666_666, "%*i", 20, 43);
  ck_assert_str_eq(test_str_666, test_str_666_666);
}
END_TEST

START_TEST(sprintf_test_667) {
  char test_str_667[50] = "";
  char test_str_667_667[50] = "";
  s21_sprintf(test_str_667, "%*o", 20, 0);
  sprintf(test_str_667_667, "%*o", 20, 0);
  ck_assert_str_eq(test_str_667, test_str_667_667);
}
END_TEST

START_TEST(sprintf_test_668) {
  char test_str_668[50] = "";
  char test_str_668_668[50] = "";
  s21_sprintf(test_str_668, "%*o", 20, 1);
  sprintf(test_str_668_668, "%*o", 20, 1);
  ck_assert_str_eq(test_str_668, test_str_668_668);
}
END_TEST

START_TEST(sprintf_test_669) {
  char test_str_669[50] = "";
  char test_str_669_669[50] = "";
  s21_sprintf(test_str_669, "%*o", 20, 10);
  sprintf(test_str_669_669, "%*o", 20, 10);
  ck_assert_str_eq(test_str_669, test_str_669_669);
}
END_TEST

START_TEST(sprintf_test_670) {
  char test_str_670[50] = "";
  char test_str_670_670[50] = "";
  s21_sprintf(test_str_670, "%*o", 20, 123456);
  sprintf(test_str_670_670, "%*o", 20, 123456);
  ck_assert_str_eq(test_str_670, test_str_670_670);
}
END_TEST

START_TEST(sprintf_test_671) {
  char test_str_671[50] = "";
  char test_str_671_671[50] = "";
  s21_sprintf(test_str_671, "%*o", 20, -67890123);
  sprintf(test_str_671_671, "%*o", 20, -67890123);
  ck_assert_str_eq(test_str_671, test_str_671_671);
}
END_TEST

START_TEST(sprintf_test_672) {
  char test_str_672[50] = "";
  char test_str_672_672[50] = "";
  s21_sprintf(test_str_672, "%*o", 20, 4343);
  sprintf(test_str_672_672, "%*o", 20, 4343);
  ck_assert_str_eq(test_str_672, test_str_672_672);
}
END_TEST

START_TEST(sprintf_test_673) {
  char test_str_673[50] = "";
  char test_str_673_673[50] = "";
  s21_sprintf(test_str_673, "%*o", 20, -1);
  sprintf(test_str_673_673, "%*o", 20, -1);
  ck_assert_str_eq(test_str_673, test_str_673_673);
}
END_TEST

START_TEST(sprintf_test_674) {
  char test_str_674[50] = "";
  char test_str_674_674[50] = "";
  s21_sprintf(test_str_674, "%*o", 20, -10);
  sprintf(test_str_674_674, "%*o", 20, -10);
  ck_assert_str_eq(test_str_674, test_str_674_674);
}
END_TEST

START_TEST(sprintf_test_675) {
  char test_str_675[50] = "";
  char test_str_675_675[50] = "";
  s21_sprintf(test_str_675, "%*o", 20, 43);
  sprintf(test_str_675_675, "%*o", 20, 43);
  ck_assert_str_eq(test_str_675, test_str_675_675);
}
END_TEST

START_TEST(sprintf_test_676) {
  char test_str_676[50] = "";
  char test_str_676_676[50] = "";
  s21_sprintf(test_str_676, "%*u", 20, 0);
  sprintf(test_str_676_676, "%*u", 20, 0);
  ck_assert_str_eq(test_str_676, test_str_676_676);
}
END_TEST

START_TEST(sprintf_test_677) {
  char test_str_677[50] = "";
  char test_str_677_677[50] = "";
  s21_sprintf(test_str_677, "%*u", 20, 1);
  sprintf(test_str_677_677, "%*u", 20, 1);
  ck_assert_str_eq(test_str_677, test_str_677_677);
}
END_TEST

START_TEST(sprintf_test_678) {
  char test_str_678[50] = "";
  char test_str_678_678[50] = "";
  s21_sprintf(test_str_678, "%*u", 20, 10);
  sprintf(test_str_678_678, "%*u", 20, 10);
  ck_assert_str_eq(test_str_678, test_str_678_678);
}
END_TEST

START_TEST(sprintf_test_679) {
  char test_str_679[50] = "";
  char test_str_679_679[50] = "";
  s21_sprintf(test_str_679, "%*u", 20, 123456);
  sprintf(test_str_679_679, "%*u", 20, 123456);
  ck_assert_str_eq(test_str_679, test_str_679_679);
}
END_TEST

START_TEST(sprintf_test_680) {
  char test_str_680[50] = "";
  char test_str_680_680[50] = "";
  s21_sprintf(test_str_680, "%*u", 20, -67890123);
  sprintf(test_str_680_680, "%*u", 20, -67890123);
  ck_assert_str_eq(test_str_680, test_str_680_680);
}
END_TEST

START_TEST(sprintf_test_681) {
  char test_str_681[50] = "";
  char test_str_681_681[50] = "";
  s21_sprintf(test_str_681, "%*u", 20, 4343);
  sprintf(test_str_681_681, "%*u", 20, 4343);
  ck_assert_str_eq(test_str_681, test_str_681_681);
}
END_TEST

START_TEST(sprintf_test_682) {
  char test_str_682[50] = "";
  char test_str_682_682[50] = "";
  s21_sprintf(test_str_682, "%*u", 20, -1);
  sprintf(test_str_682_682, "%*u", 20, -1);
  ck_assert_str_eq(test_str_682, test_str_682_682);
}
END_TEST

START_TEST(sprintf_test_683) {
  char test_str_683[50] = "";
  char test_str_683_683[50] = "";
  s21_sprintf(test_str_683, "%*u", 20, -10);
  sprintf(test_str_683_683, "%*u", 20, -10);
  ck_assert_str_eq(test_str_683, test_str_683_683);
}
END_TEST

START_TEST(sprintf_test_684) {
  char test_str_684[50] = "";
  char test_str_684_684[50] = "";
  s21_sprintf(test_str_684, "%*u", 20, 43);
  sprintf(test_str_684_684, "%*u", 20, 43);
  ck_assert_str_eq(test_str_684, test_str_684_684);
}
END_TEST

START_TEST(sprintf_test_685) {
  char test_str_685[50] = "";
  char test_str_685_685[50] = "";
  s21_sprintf(test_str_685, "%*x", 20, 0);
  sprintf(test_str_685_685, "%*x", 20, 0);
  ck_assert_str_eq(test_str_685, test_str_685_685);
}
END_TEST

START_TEST(sprintf_test_686) {
  char test_str_686[50] = "";
  char test_str_686_686[50] = "";
  s21_sprintf(test_str_686, "%*x", 20, 1);
  sprintf(test_str_686_686, "%*x", 20, 1);
  ck_assert_str_eq(test_str_686, test_str_686_686);
}
END_TEST

START_TEST(sprintf_test_687) {
  char test_str_687[50] = "";
  char test_str_687_687[50] = "";
  s21_sprintf(test_str_687, "%*x", 20, 10);
  sprintf(test_str_687_687, "%*x", 20, 10);
  ck_assert_str_eq(test_str_687, test_str_687_687);
}
END_TEST

START_TEST(sprintf_test_688) {
  char test_str_688[50] = "";
  char test_str_688_688[50] = "";
  s21_sprintf(test_str_688, "%*x", 20, 123456);
  sprintf(test_str_688_688, "%*x", 20, 123456);
  ck_assert_str_eq(test_str_688, test_str_688_688);
}
END_TEST

START_TEST(sprintf_test_689) {
  char test_str_689[50] = "";
  char test_str_689_689[50] = "";
  s21_sprintf(test_str_689, "%*x", 20, -67890123);
  sprintf(test_str_689_689, "%*x", 20, -67890123);
  ck_assert_str_eq(test_str_689, test_str_689_689);
}
END_TEST

START_TEST(sprintf_test_690) {
  char test_str_690[50] = "";
  char test_str_690_690[50] = "";
  s21_sprintf(test_str_690, "%*x", 20, 4343);
  sprintf(test_str_690_690, "%*x", 20, 4343);
  ck_assert_str_eq(test_str_690, test_str_690_690);
}
END_TEST

START_TEST(sprintf_test_691) {
  char test_str_691[50] = "";
  char test_str_691_691[50] = "";
  s21_sprintf(test_str_691, "%*x", 20, -1);
  sprintf(test_str_691_691, "%*x", 20, -1);
  ck_assert_str_eq(test_str_691, test_str_691_691);
}
END_TEST

START_TEST(sprintf_test_692) {
  char test_str_692[50] = "";
  char test_str_692_692[50] = "";
  s21_sprintf(test_str_692, "%*x", 20, -10);
  sprintf(test_str_692_692, "%*x", 20, -10);
  ck_assert_str_eq(test_str_692, test_str_692_692);
}
END_TEST

START_TEST(sprintf_test_693) {
  char test_str_693[50] = "";
  char test_str_693_693[50] = "";
  s21_sprintf(test_str_693, "%*x", 20, 43);
  sprintf(test_str_693_693, "%*x", 20, 43);
  ck_assert_str_eq(test_str_693, test_str_693_693);
}
END_TEST

START_TEST(sprintf_test_694) {
  char test_str_694[50] = "";
  char test_str_694_694[50] = "";
  s21_sprintf(test_str_694, "%*X", 20, 0);
  sprintf(test_str_694_694, "%*X", 20, 0);
  ck_assert_str_eq(test_str_694, test_str_694_694);
}
END_TEST

START_TEST(sprintf_test_695) {
  char test_str_695[50] = "";
  char test_str_695_695[50] = "";
  s21_sprintf(test_str_695, "%*X", 20, 1);
  sprintf(test_str_695_695, "%*X", 20, 1);
  ck_assert_str_eq(test_str_695, test_str_695_695);
}
END_TEST

START_TEST(sprintf_test_696) {
  char test_str_696[50] = "";
  char test_str_696_696[50] = "";
  s21_sprintf(test_str_696, "%*X", 20, 10);
  sprintf(test_str_696_696, "%*X", 20, 10);
  ck_assert_str_eq(test_str_696, test_str_696_696);
}
END_TEST

START_TEST(sprintf_test_697) {
  char test_str_697[50] = "";
  char test_str_697_697[50] = "";
  s21_sprintf(test_str_697, "%*X", 20, 123456);
  sprintf(test_str_697_697, "%*X", 20, 123456);
  ck_assert_str_eq(test_str_697, test_str_697_697);
}
END_TEST

START_TEST(sprintf_test_698) {
  char test_str_698[50] = "";
  char test_str_698_698[50] = "";
  s21_sprintf(test_str_698, "%*X", 20, -67890123);
  sprintf(test_str_698_698, "%*X", 20, -67890123);
  ck_assert_str_eq(test_str_698, test_str_698_698);
}
END_TEST

START_TEST(sprintf_test_699) {
  char test_str_699[50] = "";
  char test_str_699_699[50] = "";
  s21_sprintf(test_str_699, "%*X", 20, 4343);
  sprintf(test_str_699_699, "%*X", 20, 4343);
  ck_assert_str_eq(test_str_699, test_str_699_699);
}
END_TEST

START_TEST(sprintf_test_700) {
  char test_str_700[50] = "";
  char test_str_700_700[50] = "";
  s21_sprintf(test_str_700, "%*X", 20, -1);
  sprintf(test_str_700_700, "%*X", 20, -1);
  ck_assert_str_eq(test_str_700, test_str_700_700);
}
END_TEST

START_TEST(sprintf_test_701) {
  char test_str_701[50] = "";
  char test_str_701_701[50] = "";
  s21_sprintf(test_str_701, "%*X", 20, -10);
  sprintf(test_str_701_701, "%*X", 20, -10);
  ck_assert_str_eq(test_str_701, test_str_701_701);
}
END_TEST

START_TEST(sprintf_test_702) {
  char test_str_702[50] = "";
  char test_str_702_702[50] = "";
  s21_sprintf(test_str_702, "%*X", 20, 43);
  sprintf(test_str_702_702, "%*X", 20, 43);
  ck_assert_str_eq(test_str_702, test_str_702_702);
}
END_TEST

START_TEST(sprintf_test_703) {
  char test_str_703[50] = "";
  char test_str_703_703[50] = "";
  s21_sprintf(test_str_703, "%*d", -10, 0);
  sprintf(test_str_703_703, "%*d", -10, 0);
  ck_assert_str_eq(test_str_703, test_str_703_703);
}
END_TEST

START_TEST(sprintf_test_704) {
  char test_str_704[50] = "";
  char test_str_704_704[50] = "";
  s21_sprintf(test_str_704, "%*d", -10, 1);
  sprintf(test_str_704_704, "%*d", -10, 1);
  ck_assert_str_eq(test_str_704, test_str_704_704);
}
END_TEST

START_TEST(sprintf_test_705) {
  char test_str_705[50] = "";
  char test_str_705_705[50] = "";
  s21_sprintf(test_str_705, "%*d", -10, 10);
  sprintf(test_str_705_705, "%*d", -10, 10);
  ck_assert_str_eq(test_str_705, test_str_705_705);
}
END_TEST

START_TEST(sprintf_test_706) {
  char test_str_706[50] = "";
  char test_str_706_706[50] = "";
  s21_sprintf(test_str_706, "%*d", -10, 123456);
  sprintf(test_str_706_706, "%*d", -10, 123456);
  ck_assert_str_eq(test_str_706, test_str_706_706);
}
END_TEST

START_TEST(sprintf_test_707) {
  char test_str_707[50] = "";
  char test_str_707_707[50] = "";
  s21_sprintf(test_str_707, "%*d", -10, -67890123);
  sprintf(test_str_707_707, "%*d", -10, -67890123);
  ck_assert_str_eq(test_str_707, test_str_707_707);
}
END_TEST

START_TEST(sprintf_test_708) {
  char test_str_708[50] = "";
  char test_str_708_708[50] = "";
  s21_sprintf(test_str_708, "%*d", -10, 4343);
  sprintf(test_str_708_708, "%*d", -10, 4343);
  ck_assert_str_eq(test_str_708, test_str_708_708);
}
END_TEST

START_TEST(sprintf_test_709) {
  char test_str_709[50] = "";
  char test_str_709_709[50] = "";
  s21_sprintf(test_str_709, "%*d", -10, -1);
  sprintf(test_str_709_709, "%*d", -10, -1);
  ck_assert_str_eq(test_str_709, test_str_709_709);
}
END_TEST

START_TEST(sprintf_test_710) {
  char test_str_710[50] = "";
  char test_str_710_710[50] = "";
  s21_sprintf(test_str_710, "%*d", -10, -10);
  sprintf(test_str_710_710, "%*d", -10, -10);
  ck_assert_str_eq(test_str_710, test_str_710_710);
}
END_TEST

START_TEST(sprintf_test_711) {
  char test_str_711[50] = "";
  char test_str_711_711[50] = "";
  s21_sprintf(test_str_711, "%*d", -10, 43);
  sprintf(test_str_711_711, "%*d", -10, 43);
  ck_assert_str_eq(test_str_711, test_str_711_711);
}
END_TEST

START_TEST(sprintf_test_712) {
  char test_str_712[50] = "";
  char test_str_712_712[50] = "";
  s21_sprintf(test_str_712, "%*i", -10, 0);
  sprintf(test_str_712_712, "%*i", -10, 0);
  ck_assert_str_eq(test_str_712, test_str_712_712);
}
END_TEST

START_TEST(sprintf_test_713) {
  char test_str_713[50] = "";
  char test_str_713_713[50] = "";
  s21_sprintf(test_str_713, "%*i", -10, 1);
  sprintf(test_str_713_713, "%*i", -10, 1);
  ck_assert_str_eq(test_str_713, test_str_713_713);
}
END_TEST

START_TEST(sprintf_test_714) {
  char test_str_714[50] = "";
  char test_str_714_714[50] = "";
  s21_sprintf(test_str_714, "%*i", -10, 10);
  sprintf(test_str_714_714, "%*i", -10, 10);
  ck_assert_str_eq(test_str_714, test_str_714_714);
}
END_TEST

START_TEST(sprintf_test_715) {
  char test_str_715[50] = "";
  char test_str_715_715[50] = "";
  s21_sprintf(test_str_715, "%*i", -10, 123456);
  sprintf(test_str_715_715, "%*i", -10, 123456);
  ck_assert_str_eq(test_str_715, test_str_715_715);
}
END_TEST

START_TEST(sprintf_test_716) {
  char test_str_716[50] = "";
  char test_str_716_716[50] = "";
  s21_sprintf(test_str_716, "%*i", -10, -67890123);
  sprintf(test_str_716_716, "%*i", -10, -67890123);
  ck_assert_str_eq(test_str_716, test_str_716_716);
}
END_TEST

START_TEST(sprintf_test_717) {
  char test_str_717[50] = "";
  char test_str_717_717[50] = "";
  s21_sprintf(test_str_717, "%*i", -10, 4343);
  sprintf(test_str_717_717, "%*i", -10, 4343);
  ck_assert_str_eq(test_str_717, test_str_717_717);
}
END_TEST

START_TEST(sprintf_test_718) {
  char test_str_718[50] = "";
  char test_str_718_718[50] = "";
  s21_sprintf(test_str_718, "%*i", -10, -1);
  sprintf(test_str_718_718, "%*i", -10, -1);
  ck_assert_str_eq(test_str_718, test_str_718_718);
}
END_TEST

START_TEST(sprintf_test_719) {
  char test_str_719[50] = "";
  char test_str_719_719[50] = "";
  s21_sprintf(test_str_719, "%*i", -10, -10);
  sprintf(test_str_719_719, "%*i", -10, -10);
  ck_assert_str_eq(test_str_719, test_str_719_719);
}
END_TEST

START_TEST(sprintf_test_720) {
  char test_str_720[50] = "";
  char test_str_720_720[50] = "";
  s21_sprintf(test_str_720, "%*i", -10, 43);
  sprintf(test_str_720_720, "%*i", -10, 43);
  ck_assert_str_eq(test_str_720, test_str_720_720);
}
END_TEST

START_TEST(sprintf_test_721) {
  char test_str_721[50] = "";
  char test_str_721_721[50] = "";
  s21_sprintf(test_str_721, "%*o", -10, 0);
  sprintf(test_str_721_721, "%*o", -10, 0);
  ck_assert_str_eq(test_str_721, test_str_721_721);
}
END_TEST

START_TEST(sprintf_test_722) {
  char test_str_722[50] = "";
  char test_str_722_722[50] = "";
  s21_sprintf(test_str_722, "%*o", -10, 1);
  sprintf(test_str_722_722, "%*o", -10, 1);
  ck_assert_str_eq(test_str_722, test_str_722_722);
}
END_TEST

START_TEST(sprintf_test_723) {
  char test_str_723[50] = "";
  char test_str_723_723[50] = "";
  s21_sprintf(test_str_723, "%*o", -10, 10);
  sprintf(test_str_723_723, "%*o", -10, 10);
  ck_assert_str_eq(test_str_723, test_str_723_723);
}
END_TEST

START_TEST(sprintf_test_724) {
  char test_str_724[50] = "";
  char test_str_724_724[50] = "";
  s21_sprintf(test_str_724, "%*o", -10, 123456);
  sprintf(test_str_724_724, "%*o", -10, 123456);
  ck_assert_str_eq(test_str_724, test_str_724_724);
}
END_TEST

START_TEST(sprintf_test_725) {
  char test_str_725[50] = "";
  char test_str_725_725[50] = "";
  s21_sprintf(test_str_725, "%*o", -10, -67890123);
  sprintf(test_str_725_725, "%*o", -10, -67890123);
  ck_assert_str_eq(test_str_725, test_str_725_725);
}
END_TEST

START_TEST(sprintf_test_726) {
  char test_str_726[50] = "";
  char test_str_726_726[50] = "";
  s21_sprintf(test_str_726, "%*o", -10, 4343);
  sprintf(test_str_726_726, "%*o", -10, 4343);
  ck_assert_str_eq(test_str_726, test_str_726_726);
}
END_TEST

START_TEST(sprintf_test_727) {
  char test_str_727[50] = "";
  char test_str_727_727[50] = "";
  s21_sprintf(test_str_727, "%*o", -10, -1);
  sprintf(test_str_727_727, "%*o", -10, -1);
  ck_assert_str_eq(test_str_727, test_str_727_727);
}
END_TEST

START_TEST(sprintf_test_728) {
  char test_str_728[50] = "";
  char test_str_728_728[50] = "";
  s21_sprintf(test_str_728, "%*o", -10, -10);
  sprintf(test_str_728_728, "%*o", -10, -10);
  ck_assert_str_eq(test_str_728, test_str_728_728);
}
END_TEST

START_TEST(sprintf_test_729) {
  char test_str_729[50] = "";
  char test_str_729_729[50] = "";
  s21_sprintf(test_str_729, "%*o", -10, 43);
  sprintf(test_str_729_729, "%*o", -10, 43);
  ck_assert_str_eq(test_str_729, test_str_729_729);
}
END_TEST

START_TEST(sprintf_test_730) {
  char test_str_730[50] = "";
  char test_str_730_730[50] = "";
  s21_sprintf(test_str_730, "%*u", -10, 0);
  sprintf(test_str_730_730, "%*u", -10, 0);
  ck_assert_str_eq(test_str_730, test_str_730_730);
}
END_TEST

START_TEST(sprintf_test_731) {
  char test_str_731[50] = "";
  char test_str_731_731[50] = "";
  s21_sprintf(test_str_731, "%*u", -10, 1);
  sprintf(test_str_731_731, "%*u", -10, 1);
  ck_assert_str_eq(test_str_731, test_str_731_731);
}
END_TEST

START_TEST(sprintf_test_732) {
  char test_str_732[50] = "";
  char test_str_732_732[50] = "";
  s21_sprintf(test_str_732, "%*u", -10, 10);
  sprintf(test_str_732_732, "%*u", -10, 10);
  ck_assert_str_eq(test_str_732, test_str_732_732);
}
END_TEST

START_TEST(sprintf_test_733) {
  char test_str_733[50] = "";
  char test_str_733_733[50] = "";
  s21_sprintf(test_str_733, "%*u", -10, 123456);
  sprintf(test_str_733_733, "%*u", -10, 123456);
  ck_assert_str_eq(test_str_733, test_str_733_733);
}
END_TEST

START_TEST(sprintf_test_734) {
  char test_str_734[50] = "";
  char test_str_734_734[50] = "";
  s21_sprintf(test_str_734, "%*u", -10, -67890123);
  sprintf(test_str_734_734, "%*u", -10, -67890123);
  ck_assert_str_eq(test_str_734, test_str_734_734);
}
END_TEST

START_TEST(sprintf_test_735) {
  char test_str_735[50] = "";
  char test_str_735_735[50] = "";
  s21_sprintf(test_str_735, "%*u", -10, 4343);
  sprintf(test_str_735_735, "%*u", -10, 4343);
  ck_assert_str_eq(test_str_735, test_str_735_735);
}
END_TEST

START_TEST(sprintf_test_736) {
  char test_str_736[50] = "";
  char test_str_736_736[50] = "";
  s21_sprintf(test_str_736, "%*u", -10, -1);
  sprintf(test_str_736_736, "%*u", -10, -1);
  ck_assert_str_eq(test_str_736, test_str_736_736);
}
END_TEST

START_TEST(sprintf_test_737) {
  char test_str_737[50] = "";
  char test_str_737_737[50] = "";
  s21_sprintf(test_str_737, "%*u", -10, -10);
  sprintf(test_str_737_737, "%*u", -10, -10);
  ck_assert_str_eq(test_str_737, test_str_737_737);
}
END_TEST

START_TEST(sprintf_test_738) {
  char test_str_738[50] = "";
  char test_str_738_738[50] = "";
  s21_sprintf(test_str_738, "%*u", -10, 43);
  sprintf(test_str_738_738, "%*u", -10, 43);
  ck_assert_str_eq(test_str_738, test_str_738_738);
}
END_TEST

START_TEST(sprintf_test_739) {
  char test_str_739[50] = "";
  char test_str_739_739[50] = "";
  s21_sprintf(test_str_739, "%*x", -10, 0);
  sprintf(test_str_739_739, "%*x", -10, 0);
  ck_assert_str_eq(test_str_739, test_str_739_739);
}
END_TEST

START_TEST(sprintf_test_740) {
  char test_str_740[50] = "";
  char test_str_740_740[50] = "";
  s21_sprintf(test_str_740, "%*x", -10, 1);
  sprintf(test_str_740_740, "%*x", -10, 1);
  ck_assert_str_eq(test_str_740, test_str_740_740);
}
END_TEST

START_TEST(sprintf_test_741) {
  char test_str_741[50] = "";
  char test_str_741_741[50] = "";
  s21_sprintf(test_str_741, "%*x", -10, 10);
  sprintf(test_str_741_741, "%*x", -10, 10);
  ck_assert_str_eq(test_str_741, test_str_741_741);
}
END_TEST

START_TEST(sprintf_test_742) {
  char test_str_742[50] = "";
  char test_str_742_742[50] = "";
  s21_sprintf(test_str_742, "%*x", -10, 123456);
  sprintf(test_str_742_742, "%*x", -10, 123456);
  ck_assert_str_eq(test_str_742, test_str_742_742);
}
END_TEST

START_TEST(sprintf_test_743) {
  char test_str_743[50] = "";
  char test_str_743_743[50] = "";
  s21_sprintf(test_str_743, "%*x", -10, -67890123);
  sprintf(test_str_743_743, "%*x", -10, -67890123);
  ck_assert_str_eq(test_str_743, test_str_743_743);
}
END_TEST

START_TEST(sprintf_test_744) {
  char test_str_744[50] = "";
  char test_str_744_744[50] = "";
  s21_sprintf(test_str_744, "%*x", -10, 4343);
  sprintf(test_str_744_744, "%*x", -10, 4343);
  ck_assert_str_eq(test_str_744, test_str_744_744);
}
END_TEST

START_TEST(sprintf_test_745) {
  char test_str_745[50] = "";
  char test_str_745_745[50] = "";
  s21_sprintf(test_str_745, "%*x", -10, -1);
  sprintf(test_str_745_745, "%*x", -10, -1);
  ck_assert_str_eq(test_str_745, test_str_745_745);
}
END_TEST

START_TEST(sprintf_test_746) {
  char test_str_746[50] = "";
  char test_str_746_746[50] = "";
  s21_sprintf(test_str_746, "%*x", -10, -10);
  sprintf(test_str_746_746, "%*x", -10, -10);
  ck_assert_str_eq(test_str_746, test_str_746_746);
}
END_TEST

START_TEST(sprintf_test_747) {
  char test_str_747[50] = "";
  char test_str_747_747[50] = "";
  s21_sprintf(test_str_747, "%*x", -10, 43);
  sprintf(test_str_747_747, "%*x", -10, 43);
  ck_assert_str_eq(test_str_747, test_str_747_747);
}
END_TEST

START_TEST(sprintf_test_748) {
  char test_str_748[50] = "";
  char test_str_748_748[50] = "";
  s21_sprintf(test_str_748, "%*X", -10, 0);
  sprintf(test_str_748_748, "%*X", -10, 0);
  ck_assert_str_eq(test_str_748, test_str_748_748);
}
END_TEST

START_TEST(sprintf_test_749) {
  char test_str_749[50] = "";
  char test_str_749_749[50] = "";
  s21_sprintf(test_str_749, "%*X", -10, 1);
  sprintf(test_str_749_749, "%*X", -10, 1);
  ck_assert_str_eq(test_str_749, test_str_749_749);
}
END_TEST

START_TEST(sprintf_test_750) {
  char test_str_750[50] = "";
  char test_str_750_750[50] = "";
  s21_sprintf(test_str_750, "%*X", -10, 10);
  sprintf(test_str_750_750, "%*X", -10, 10);
  ck_assert_str_eq(test_str_750, test_str_750_750);
}
END_TEST

START_TEST(sprintf_test_751) {
  char test_str_751[50] = "";
  char test_str_751_751[50] = "";
  s21_sprintf(test_str_751, "%*X", -10, 123456);
  sprintf(test_str_751_751, "%*X", -10, 123456);
  ck_assert_str_eq(test_str_751, test_str_751_751);
}
END_TEST

START_TEST(sprintf_test_752) {
  char test_str_752[50] = "";
  char test_str_752_752[50] = "";
  s21_sprintf(test_str_752, "%*X", -10, -67890123);
  sprintf(test_str_752_752, "%*X", -10, -67890123);
  ck_assert_str_eq(test_str_752, test_str_752_752);
}
END_TEST

START_TEST(sprintf_test_753) {
  char test_str_753[50] = "";
  char test_str_753_753[50] = "";
  s21_sprintf(test_str_753, "%*X", -10, 4343);
  sprintf(test_str_753_753, "%*X", -10, 4343);
  ck_assert_str_eq(test_str_753, test_str_753_753);
}
END_TEST

START_TEST(sprintf_test_754) {
  char test_str_754[50] = "";
  char test_str_754_754[50] = "";
  s21_sprintf(test_str_754, "%*X", -10, -1);
  sprintf(test_str_754_754, "%*X", -10, -1);
  ck_assert_str_eq(test_str_754, test_str_754_754);
}
END_TEST

START_TEST(sprintf_test_755) {
  char test_str_755[50] = "";
  char test_str_755_755[50] = "";
  s21_sprintf(test_str_755, "%*X", -10, -10);
  sprintf(test_str_755_755, "%*X", -10, -10);
  ck_assert_str_eq(test_str_755, test_str_755_755);
}
END_TEST

START_TEST(sprintf_test_756) {
  char test_str_756[50] = "";
  char test_str_756_756[50] = "";
  s21_sprintf(test_str_756, "%*X", -10, 43);
  sprintf(test_str_756_756, "%*X", -10, 43);
  ck_assert_str_eq(test_str_756, test_str_756_756);
}
END_TEST

START_TEST(sprintf_test_757) {
  char test_str_757[50] = "";
  char test_str_757_757[50] = "";
  s21_sprintf(test_str_757, "%*d", -20, 0);
  sprintf(test_str_757_757, "%*d", -20, 0);
  ck_assert_str_eq(test_str_757, test_str_757_757);
}
END_TEST

START_TEST(sprintf_test_758) {
  char test_str_758[50] = "";
  char test_str_758_758[50] = "";
  s21_sprintf(test_str_758, "%*d", -20, 1);
  sprintf(test_str_758_758, "%*d", -20, 1);
  ck_assert_str_eq(test_str_758, test_str_758_758);
}
END_TEST

START_TEST(sprintf_test_759) {
  char test_str_759[50] = "";
  char test_str_759_759[50] = "";
  s21_sprintf(test_str_759, "%*d", -20, 10);
  sprintf(test_str_759_759, "%*d", -20, 10);
  ck_assert_str_eq(test_str_759, test_str_759_759);
}
END_TEST

START_TEST(sprintf_test_760) {
  char test_str_760[50] = "";
  char test_str_760_760[50] = "";
  s21_sprintf(test_str_760, "%*d", -20, 123456);
  sprintf(test_str_760_760, "%*d", -20, 123456);
  ck_assert_str_eq(test_str_760, test_str_760_760);
}
END_TEST

START_TEST(sprintf_test_761) {
  char test_str_761[50] = "";
  char test_str_761_761[50] = "";
  s21_sprintf(test_str_761, "%*d", -20, -67890123);
  sprintf(test_str_761_761, "%*d", -20, -67890123);
  ck_assert_str_eq(test_str_761, test_str_761_761);
}
END_TEST

START_TEST(sprintf_test_762) {
  char test_str_762[50] = "";
  char test_str_762_762[50] = "";
  s21_sprintf(test_str_762, "%*d", -20, 4343);
  sprintf(test_str_762_762, "%*d", -20, 4343);
  ck_assert_str_eq(test_str_762, test_str_762_762);
}
END_TEST

START_TEST(sprintf_test_763) {
  char test_str_763[50] = "";
  char test_str_763_763[50] = "";
  s21_sprintf(test_str_763, "%*d", -20, -1);
  sprintf(test_str_763_763, "%*d", -20, -1);
  ck_assert_str_eq(test_str_763, test_str_763_763);
}
END_TEST

START_TEST(sprintf_test_764) {
  char test_str_764[50] = "";
  char test_str_764_764[50] = "";
  s21_sprintf(test_str_764, "%*d", -20, -10);
  sprintf(test_str_764_764, "%*d", -20, -10);
  ck_assert_str_eq(test_str_764, test_str_764_764);
}
END_TEST

START_TEST(sprintf_test_765) {
  char test_str_765[50] = "";
  char test_str_765_765[50] = "";
  s21_sprintf(test_str_765, "%*d", -20, 43);
  sprintf(test_str_765_765, "%*d", -20, 43);
  ck_assert_str_eq(test_str_765, test_str_765_765);
}
END_TEST

START_TEST(sprintf_test_766) {
  char test_str_766[50] = "";
  char test_str_766_766[50] = "";
  s21_sprintf(test_str_766, "%*i", -20, 0);
  sprintf(test_str_766_766, "%*i", -20, 0);
  ck_assert_str_eq(test_str_766, test_str_766_766);
}
END_TEST

START_TEST(sprintf_test_767) {
  char test_str_767[50] = "";
  char test_str_767_767[50] = "";
  s21_sprintf(test_str_767, "%*i", -20, 1);
  sprintf(test_str_767_767, "%*i", -20, 1);
  ck_assert_str_eq(test_str_767, test_str_767_767);
}
END_TEST

START_TEST(sprintf_test_768) {
  char test_str_768[50] = "";
  char test_str_768_768[50] = "";
  s21_sprintf(test_str_768, "%*i", -20, 10);
  sprintf(test_str_768_768, "%*i", -20, 10);
  ck_assert_str_eq(test_str_768, test_str_768_768);
}
END_TEST

START_TEST(sprintf_test_769) {
  char test_str_769[50] = "";
  char test_str_769_769[50] = "";
  s21_sprintf(test_str_769, "%*i", -20, 123456);
  sprintf(test_str_769_769, "%*i", -20, 123456);
  ck_assert_str_eq(test_str_769, test_str_769_769);
}
END_TEST

START_TEST(sprintf_test_770) {
  char test_str_770[50] = "";
  char test_str_770_770[50] = "";
  s21_sprintf(test_str_770, "%*i", -20, -67890123);
  sprintf(test_str_770_770, "%*i", -20, -67890123);
  ck_assert_str_eq(test_str_770, test_str_770_770);
}
END_TEST

START_TEST(sprintf_test_771) {
  char test_str_771[50] = "";
  char test_str_771_771[50] = "";
  s21_sprintf(test_str_771, "%*i", -20, 4343);
  sprintf(test_str_771_771, "%*i", -20, 4343);
  ck_assert_str_eq(test_str_771, test_str_771_771);
}
END_TEST

START_TEST(sprintf_test_772) {
  char test_str_772[50] = "";
  char test_str_772_772[50] = "";
  s21_sprintf(test_str_772, "%*i", -20, -1);
  sprintf(test_str_772_772, "%*i", -20, -1);
  ck_assert_str_eq(test_str_772, test_str_772_772);
}
END_TEST

START_TEST(sprintf_test_773) {
  char test_str_773[50] = "";
  char test_str_773_773[50] = "";
  s21_sprintf(test_str_773, "%*i", -20, -10);
  sprintf(test_str_773_773, "%*i", -20, -10);
  ck_assert_str_eq(test_str_773, test_str_773_773);
}
END_TEST

START_TEST(sprintf_test_774) {
  char test_str_774[50] = "";
  char test_str_774_774[50] = "";
  s21_sprintf(test_str_774, "%*i", -20, 43);
  sprintf(test_str_774_774, "%*i", -20, 43);
  ck_assert_str_eq(test_str_774, test_str_774_774);
}
END_TEST

START_TEST(sprintf_test_775) {
  char test_str_775[50] = "";
  char test_str_775_775[50] = "";
  s21_sprintf(test_str_775, "%*o", -20, 0);
  sprintf(test_str_775_775, "%*o", -20, 0);
  ck_assert_str_eq(test_str_775, test_str_775_775);
}
END_TEST

START_TEST(sprintf_test_776) {
  char test_str_776[50] = "";
  char test_str_776_776[50] = "";
  s21_sprintf(test_str_776, "%*o", -20, 1);
  sprintf(test_str_776_776, "%*o", -20, 1);
  ck_assert_str_eq(test_str_776, test_str_776_776);
}
END_TEST

START_TEST(sprintf_test_777) {
  char test_str_777[50] = "";
  char test_str_777_777[50] = "";
  s21_sprintf(test_str_777, "%*o", -20, 10);
  sprintf(test_str_777_777, "%*o", -20, 10);
  ck_assert_str_eq(test_str_777, test_str_777_777);
}
END_TEST

START_TEST(sprintf_test_778) {
  char test_str_778[50] = "";
  char test_str_778_778[50] = "";
  s21_sprintf(test_str_778, "%*o", -20, 123456);
  sprintf(test_str_778_778, "%*o", -20, 123456);
  ck_assert_str_eq(test_str_778, test_str_778_778);
}
END_TEST

START_TEST(sprintf_test_779) {
  char test_str_779[50] = "";
  char test_str_779_779[50] = "";
  s21_sprintf(test_str_779, "%*o", -20, -67890123);
  sprintf(test_str_779_779, "%*o", -20, -67890123);
  ck_assert_str_eq(test_str_779, test_str_779_779);
}
END_TEST

START_TEST(sprintf_test_780) {
  char test_str_780[50] = "";
  char test_str_780_780[50] = "";
  s21_sprintf(test_str_780, "%*o", -20, 4343);
  sprintf(test_str_780_780, "%*o", -20, 4343);
  ck_assert_str_eq(test_str_780, test_str_780_780);
}
END_TEST

START_TEST(sprintf_test_781) {
  char test_str_781[50] = "";
  char test_str_781_781[50] = "";
  s21_sprintf(test_str_781, "%*o", -20, -1);
  sprintf(test_str_781_781, "%*o", -20, -1);
  ck_assert_str_eq(test_str_781, test_str_781_781);
}
END_TEST

START_TEST(sprintf_test_782) {
  char test_str_782[50] = "";
  char test_str_782_782[50] = "";
  s21_sprintf(test_str_782, "%*o", -20, -10);
  sprintf(test_str_782_782, "%*o", -20, -10);
  ck_assert_str_eq(test_str_782, test_str_782_782);
}
END_TEST

START_TEST(sprintf_test_783) {
  char test_str_783[50] = "";
  char test_str_783_783[50] = "";
  s21_sprintf(test_str_783, "%*o", -20, 43);
  sprintf(test_str_783_783, "%*o", -20, 43);
  ck_assert_str_eq(test_str_783, test_str_783_783);
}
END_TEST

START_TEST(sprintf_test_784) {
  char test_str_784[50] = "";
  char test_str_784_784[50] = "";
  s21_sprintf(test_str_784, "%*u", -20, 0);
  sprintf(test_str_784_784, "%*u", -20, 0);
  ck_assert_str_eq(test_str_784, test_str_784_784);
}
END_TEST

START_TEST(sprintf_test_785) {
  char test_str_785[50] = "";
  char test_str_785_785[50] = "";
  s21_sprintf(test_str_785, "%*u", -20, 1);
  sprintf(test_str_785_785, "%*u", -20, 1);
  ck_assert_str_eq(test_str_785, test_str_785_785);
}
END_TEST

START_TEST(sprintf_test_786) {
  char test_str_786[50] = "";
  char test_str_786_786[50] = "";
  s21_sprintf(test_str_786, "%*u", -20, 10);
  sprintf(test_str_786_786, "%*u", -20, 10);
  ck_assert_str_eq(test_str_786, test_str_786_786);
}
END_TEST

START_TEST(sprintf_test_787) {
  char test_str_787[50] = "";
  char test_str_787_787[50] = "";
  s21_sprintf(test_str_787, "%*u", -20, 123456);
  sprintf(test_str_787_787, "%*u", -20, 123456);
  ck_assert_str_eq(test_str_787, test_str_787_787);
}
END_TEST

START_TEST(sprintf_test_788) {
  char test_str_788[50] = "";
  char test_str_788_788[50] = "";
  s21_sprintf(test_str_788, "%*u", -20, -67890123);
  sprintf(test_str_788_788, "%*u", -20, -67890123);
  ck_assert_str_eq(test_str_788, test_str_788_788);
}
END_TEST

START_TEST(sprintf_test_789) {
  char test_str_789[50] = "";
  char test_str_789_789[50] = "";
  s21_sprintf(test_str_789, "%*u", -20, 4343);
  sprintf(test_str_789_789, "%*u", -20, 4343);
  ck_assert_str_eq(test_str_789, test_str_789_789);
}
END_TEST

START_TEST(sprintf_test_790) {
  char test_str_790[50] = "";
  char test_str_790_790[50] = "";
  s21_sprintf(test_str_790, "%*u", -20, -1);
  sprintf(test_str_790_790, "%*u", -20, -1);
  ck_assert_str_eq(test_str_790, test_str_790_790);
}
END_TEST

START_TEST(sprintf_test_791) {
  char test_str_791[50] = "";
  char test_str_791_791[50] = "";
  s21_sprintf(test_str_791, "%*u", -20, -10);
  sprintf(test_str_791_791, "%*u", -20, -10);
  ck_assert_str_eq(test_str_791, test_str_791_791);
}
END_TEST

START_TEST(sprintf_test_792) {
  char test_str_792[50] = "";
  char test_str_792_792[50] = "";
  s21_sprintf(test_str_792, "%*u", -20, 43);
  sprintf(test_str_792_792, "%*u", -20, 43);
  ck_assert_str_eq(test_str_792, test_str_792_792);
}
END_TEST

START_TEST(sprintf_test_793) {
  char test_str_793[50] = "";
  char test_str_793_793[50] = "";
  s21_sprintf(test_str_793, "%*x", -20, 0);
  sprintf(test_str_793_793, "%*x", -20, 0);
  ck_assert_str_eq(test_str_793, test_str_793_793);
}
END_TEST

START_TEST(sprintf_test_794) {
  char test_str_794[50] = "";
  char test_str_794_794[50] = "";
  s21_sprintf(test_str_794, "%*x", -20, 1);
  sprintf(test_str_794_794, "%*x", -20, 1);
  ck_assert_str_eq(test_str_794, test_str_794_794);
}
END_TEST

START_TEST(sprintf_test_795) {
  char test_str_795[50] = "";
  char test_str_795_795[50] = "";
  s21_sprintf(test_str_795, "%*x", -20, 10);
  sprintf(test_str_795_795, "%*x", -20, 10);
  ck_assert_str_eq(test_str_795, test_str_795_795);
}
END_TEST

START_TEST(sprintf_test_796) {
  char test_str_796[50] = "";
  char test_str_796_796[50] = "";
  s21_sprintf(test_str_796, "%*x", -20, 123456);
  sprintf(test_str_796_796, "%*x", -20, 123456);
  ck_assert_str_eq(test_str_796, test_str_796_796);
}
END_TEST

START_TEST(sprintf_test_797) {
  char test_str_797[50] = "";
  char test_str_797_797[50] = "";
  s21_sprintf(test_str_797, "%*x", -20, -67890123);
  sprintf(test_str_797_797, "%*x", -20, -67890123);
  ck_assert_str_eq(test_str_797, test_str_797_797);
}
END_TEST

START_TEST(sprintf_test_798) {
  char test_str_798[50] = "";
  char test_str_798_798[50] = "";
  s21_sprintf(test_str_798, "%*x", -20, 4343);
  sprintf(test_str_798_798, "%*x", -20, 4343);
  ck_assert_str_eq(test_str_798, test_str_798_798);
}
END_TEST

START_TEST(sprintf_test_799) {
  char test_str_799[50] = "";
  char test_str_799_799[50] = "";
  s21_sprintf(test_str_799, "%*x", -20, -1);
  sprintf(test_str_799_799, "%*x", -20, -1);
  ck_assert_str_eq(test_str_799, test_str_799_799);
}
END_TEST

START_TEST(sprintf_test_800) {
  char test_str_800[50] = "";
  char test_str_800_800[50] = "";
  s21_sprintf(test_str_800, "%*x", -20, -10);
  sprintf(test_str_800_800, "%*x", -20, -10);
  ck_assert_str_eq(test_str_800, test_str_800_800);
}
END_TEST

START_TEST(sprintf_test_801) {
  char test_str_801[50] = "";
  char test_str_801_801[50] = "";
  s21_sprintf(test_str_801, "%*x", -20, 43);
  sprintf(test_str_801_801, "%*x", -20, 43);
  ck_assert_str_eq(test_str_801, test_str_801_801);
}
END_TEST

START_TEST(sprintf_test_802) {
  char test_str_802[50] = "";
  char test_str_802_802[50] = "";
  s21_sprintf(test_str_802, "%*X", -20, 0);
  sprintf(test_str_802_802, "%*X", -20, 0);
  ck_assert_str_eq(test_str_802, test_str_802_802);
}
END_TEST

START_TEST(sprintf_test_803) {
  char test_str_803[50] = "";
  char test_str_803_803[50] = "";
  s21_sprintf(test_str_803, "%*X", -20, 1);
  sprintf(test_str_803_803, "%*X", -20, 1);
  ck_assert_str_eq(test_str_803, test_str_803_803);
}
END_TEST

START_TEST(sprintf_test_804) {
  char test_str_804[50] = "";
  char test_str_804_804[50] = "";
  s21_sprintf(test_str_804, "%*X", -20, 10);
  sprintf(test_str_804_804, "%*X", -20, 10);
  ck_assert_str_eq(test_str_804, test_str_804_804);
}
END_TEST

START_TEST(sprintf_test_805) {
  char test_str_805[50] = "";
  char test_str_805_805[50] = "";
  s21_sprintf(test_str_805, "%*X", -20, 123456);
  sprintf(test_str_805_805, "%*X", -20, 123456);
  ck_assert_str_eq(test_str_805, test_str_805_805);
}
END_TEST

START_TEST(sprintf_test_806) {
  char test_str_806[50] = "";
  char test_str_806_806[50] = "";
  s21_sprintf(test_str_806, "%*X", -20, -67890123);
  sprintf(test_str_806_806, "%*X", -20, -67890123);
  ck_assert_str_eq(test_str_806, test_str_806_806);
}
END_TEST

START_TEST(sprintf_test_807) {
  char test_str_807[50] = "";
  char test_str_807_807[50] = "";
  s21_sprintf(test_str_807, "%*X", -20, 4343);
  sprintf(test_str_807_807, "%*X", -20, 4343);
  ck_assert_str_eq(test_str_807, test_str_807_807);
}
END_TEST

START_TEST(sprintf_test_808) {
  char test_str_808[50] = "";
  char test_str_808_808[50] = "";
  s21_sprintf(test_str_808, "%*X", -20, -1);
  sprintf(test_str_808_808, "%*X", -20, -1);
  ck_assert_str_eq(test_str_808, test_str_808_808);
}
END_TEST

START_TEST(sprintf_test_809) {
  char test_str_809[50] = "";
  char test_str_809_809[50] = "";
  s21_sprintf(test_str_809, "%*X", -20, -10);
  sprintf(test_str_809_809, "%*X", -20, -10);
  ck_assert_str_eq(test_str_809, test_str_809_809);
}
END_TEST

START_TEST(sprintf_test_810) {
  char test_str_810[50] = "";
  char test_str_810_810[50] = "";
  s21_sprintf(test_str_810, "%*X", -20, 43);
  sprintf(test_str_810_810, "%*X", -20, 43);
  ck_assert_str_eq(test_str_810, test_str_810_810);
}
END_TEST

START_TEST(sprintf_test_811) {
  char test_str_811[50] = "";
  char test_str_811_811[50] = "";
  s21_sprintf(test_str_811, "%.0d", 0);
  sprintf(test_str_811_811, "%.0d", 0);
  ck_assert_str_eq(test_str_811, test_str_811_811);
}
END_TEST

START_TEST(sprintf_test_812) {
  char test_str_812[50] = "";
  char test_str_812_812[50] = "";
  s21_sprintf(test_str_812, "%.0d", 1);
  sprintf(test_str_812_812, "%.0d", 1);
  ck_assert_str_eq(test_str_812, test_str_812_812);
}
END_TEST

START_TEST(sprintf_test_813) {
  char test_str_813[50] = "";
  char test_str_813_813[50] = "";
  s21_sprintf(test_str_813, "%.0d", 10);
  sprintf(test_str_813_813, "%.0d", 10);
  ck_assert_str_eq(test_str_813, test_str_813_813);
}
END_TEST

START_TEST(sprintf_test_814) {
  char test_str_814[50] = "";
  char test_str_814_814[50] = "";
  s21_sprintf(test_str_814, "%.0d", 123456);
  sprintf(test_str_814_814, "%.0d", 123456);
  ck_assert_str_eq(test_str_814, test_str_814_814);
}
END_TEST

START_TEST(sprintf_test_815) {
  char test_str_815[50] = "";
  char test_str_815_815[50] = "";
  s21_sprintf(test_str_815, "%.0d", -67890123);
  sprintf(test_str_815_815, "%.0d", -67890123);
  ck_assert_str_eq(test_str_815, test_str_815_815);
}
END_TEST

START_TEST(sprintf_test_816) {
  char test_str_816[50] = "";
  char test_str_816_816[50] = "";
  s21_sprintf(test_str_816, "%.0d", 4343);
  sprintf(test_str_816_816, "%.0d", 4343);
  ck_assert_str_eq(test_str_816, test_str_816_816);
}
END_TEST

START_TEST(sprintf_test_817) {
  char test_str_817[50] = "";
  char test_str_817_817[50] = "";
  s21_sprintf(test_str_817, "%.0d", -1);
  sprintf(test_str_817_817, "%.0d", -1);
  ck_assert_str_eq(test_str_817, test_str_817_817);
}
END_TEST

START_TEST(sprintf_test_818) {
  char test_str_818[50] = "";
  char test_str_818_818[50] = "";
  s21_sprintf(test_str_818, "%.0d", -10);
  sprintf(test_str_818_818, "%.0d", -10);
  ck_assert_str_eq(test_str_818, test_str_818_818);
}
END_TEST

START_TEST(sprintf_test_819) {
  char test_str_819[50] = "";
  char test_str_819_819[50] = "";
  s21_sprintf(test_str_819, "%.0d", 43);
  sprintf(test_str_819_819, "%.0d", 43);
  ck_assert_str_eq(test_str_819, test_str_819_819);
}
END_TEST

START_TEST(sprintf_test_820) {
  char test_str_820[50] = "";
  char test_str_820_820[50] = "";
  s21_sprintf(test_str_820, "%.0i", 0);
  sprintf(test_str_820_820, "%.0i", 0);
  ck_assert_str_eq(test_str_820, test_str_820_820);
}
END_TEST

START_TEST(sprintf_test_821) {
  char test_str_821[50] = "";
  char test_str_821_821[50] = "";
  s21_sprintf(test_str_821, "%.0i", 1);
  sprintf(test_str_821_821, "%.0i", 1);
  ck_assert_str_eq(test_str_821, test_str_821_821);
}
END_TEST

START_TEST(sprintf_test_822) {
  char test_str_822[50] = "";
  char test_str_822_822[50] = "";
  s21_sprintf(test_str_822, "%.0i", 10);
  sprintf(test_str_822_822, "%.0i", 10);
  ck_assert_str_eq(test_str_822, test_str_822_822);
}
END_TEST

START_TEST(sprintf_test_823) {
  char test_str_823[50] = "";
  char test_str_823_823[50] = "";
  s21_sprintf(test_str_823, "%.0i", 123456);
  sprintf(test_str_823_823, "%.0i", 123456);
  ck_assert_str_eq(test_str_823, test_str_823_823);
}
END_TEST

START_TEST(sprintf_test_824) {
  char test_str_824[50] = "";
  char test_str_824_824[50] = "";
  s21_sprintf(test_str_824, "%.0i", -67890123);
  sprintf(test_str_824_824, "%.0i", -67890123);
  ck_assert_str_eq(test_str_824, test_str_824_824);
}
END_TEST

START_TEST(sprintf_test_825) {
  char test_str_825[50] = "";
  char test_str_825_825[50] = "";
  s21_sprintf(test_str_825, "%.0i", 4343);
  sprintf(test_str_825_825, "%.0i", 4343);
  ck_assert_str_eq(test_str_825, test_str_825_825);
}
END_TEST

START_TEST(sprintf_test_826) {
  char test_str_826[50] = "";
  char test_str_826_826[50] = "";
  s21_sprintf(test_str_826, "%.0i", -1);
  sprintf(test_str_826_826, "%.0i", -1);
  ck_assert_str_eq(test_str_826, test_str_826_826);
}
END_TEST

START_TEST(sprintf_test_827) {
  char test_str_827[50] = "";
  char test_str_827_827[50] = "";
  s21_sprintf(test_str_827, "%.0i", -10);
  sprintf(test_str_827_827, "%.0i", -10);
  ck_assert_str_eq(test_str_827, test_str_827_827);
}
END_TEST

START_TEST(sprintf_test_828) {
  char test_str_828[50] = "";
  char test_str_828_828[50] = "";
  s21_sprintf(test_str_828, "%.0i", 43);
  sprintf(test_str_828_828, "%.0i", 43);
  ck_assert_str_eq(test_str_828, test_str_828_828);
}
END_TEST

START_TEST(sprintf_test_829) {
  char test_str_829[50] = "";
  char test_str_829_829[50] = "";
  s21_sprintf(test_str_829, "%.0o", 0);
  sprintf(test_str_829_829, "%.0o", 0);
  ck_assert_str_eq(test_str_829, test_str_829_829);
}
END_TEST

START_TEST(sprintf_test_830) {
  char test_str_830[50] = "";
  char test_str_830_830[50] = "";
  s21_sprintf(test_str_830, "%.0o", 1);
  sprintf(test_str_830_830, "%.0o", 1);
  ck_assert_str_eq(test_str_830, test_str_830_830);
}
END_TEST

START_TEST(sprintf_test_831) {
  char test_str_831[50] = "";
  char test_str_831_831[50] = "";
  s21_sprintf(test_str_831, "%.0o", 10);
  sprintf(test_str_831_831, "%.0o", 10);
  ck_assert_str_eq(test_str_831, test_str_831_831);
}
END_TEST

START_TEST(sprintf_test_832) {
  char test_str_832[50] = "";
  char test_str_832_832[50] = "";
  s21_sprintf(test_str_832, "%.0o", 123456);
  sprintf(test_str_832_832, "%.0o", 123456);
  ck_assert_str_eq(test_str_832, test_str_832_832);
}
END_TEST

START_TEST(sprintf_test_833) {
  char test_str_833[50] = "";
  char test_str_833_833[50] = "";
  s21_sprintf(test_str_833, "%.0o", -67890123);
  sprintf(test_str_833_833, "%.0o", -67890123);
  ck_assert_str_eq(test_str_833, test_str_833_833);
}
END_TEST

START_TEST(sprintf_test_834) {
  char test_str_834[50] = "";
  char test_str_834_834[50] = "";
  s21_sprintf(test_str_834, "%.0o", 4343);
  sprintf(test_str_834_834, "%.0o", 4343);
  ck_assert_str_eq(test_str_834, test_str_834_834);
}
END_TEST

START_TEST(sprintf_test_835) {
  char test_str_835[50] = "";
  char test_str_835_835[50] = "";
  s21_sprintf(test_str_835, "%.0o", -1);
  sprintf(test_str_835_835, "%.0o", -1);
  ck_assert_str_eq(test_str_835, test_str_835_835);
}
END_TEST

START_TEST(sprintf_test_836) {
  char test_str_836[50] = "";
  char test_str_836_836[50] = "";
  s21_sprintf(test_str_836, "%.0o", -10);
  sprintf(test_str_836_836, "%.0o", -10);
  ck_assert_str_eq(test_str_836, test_str_836_836);
}
END_TEST

START_TEST(sprintf_test_837) {
  char test_str_837[50] = "";
  char test_str_837_837[50] = "";
  s21_sprintf(test_str_837, "%.0o", 43);
  sprintf(test_str_837_837, "%.0o", 43);
  ck_assert_str_eq(test_str_837, test_str_837_837);
}
END_TEST

START_TEST(sprintf_test_838) {
  char test_str_838[50] = "";
  char test_str_838_838[50] = "";
  s21_sprintf(test_str_838, "%.0u", 0);
  sprintf(test_str_838_838, "%.0u", 0);
  ck_assert_str_eq(test_str_838, test_str_838_838);
}
END_TEST

START_TEST(sprintf_test_839) {
  char test_str_839[50] = "";
  char test_str_839_839[50] = "";
  s21_sprintf(test_str_839, "%.0u", 1);
  sprintf(test_str_839_839, "%.0u", 1);
  ck_assert_str_eq(test_str_839, test_str_839_839);
}
END_TEST

START_TEST(sprintf_test_840) {
  char test_str_840[50] = "";
  char test_str_840_840[50] = "";
  s21_sprintf(test_str_840, "%.0u", 10);
  sprintf(test_str_840_840, "%.0u", 10);
  ck_assert_str_eq(test_str_840, test_str_840_840);
}
END_TEST

START_TEST(sprintf_test_841) {
  char test_str_841[50] = "";
  char test_str_841_841[50] = "";
  s21_sprintf(test_str_841, "%.0u", 123456);
  sprintf(test_str_841_841, "%.0u", 123456);
  ck_assert_str_eq(test_str_841, test_str_841_841);
}
END_TEST

START_TEST(sprintf_test_842) {
  char test_str_842[50] = "";
  char test_str_842_842[50] = "";
  s21_sprintf(test_str_842, "%.0u", -67890123);
  sprintf(test_str_842_842, "%.0u", -67890123);
  ck_assert_str_eq(test_str_842, test_str_842_842);
}
END_TEST

START_TEST(sprintf_test_843) {
  char test_str_843[50] = "";
  char test_str_843_843[50] = "";
  s21_sprintf(test_str_843, "%.0u", 4343);
  sprintf(test_str_843_843, "%.0u", 4343);
  ck_assert_str_eq(test_str_843, test_str_843_843);
}
END_TEST

START_TEST(sprintf_test_844) {
  char test_str_844[50] = "";
  char test_str_844_844[50] = "";
  s21_sprintf(test_str_844, "%.0u", -1);
  sprintf(test_str_844_844, "%.0u", -1);
  ck_assert_str_eq(test_str_844, test_str_844_844);
}
END_TEST

START_TEST(sprintf_test_845) {
  char test_str_845[50] = "";
  char test_str_845_845[50] = "";
  s21_sprintf(test_str_845, "%.0u", -10);
  sprintf(test_str_845_845, "%.0u", -10);
  ck_assert_str_eq(test_str_845, test_str_845_845);
}
END_TEST

START_TEST(sprintf_test_846) {
  char test_str_846[50] = "";
  char test_str_846_846[50] = "";
  s21_sprintf(test_str_846, "%.0u", 43);
  sprintf(test_str_846_846, "%.0u", 43);
  ck_assert_str_eq(test_str_846, test_str_846_846);
}
END_TEST

START_TEST(sprintf_test_847) {
  char test_str_847[50] = "";
  char test_str_847_847[50] = "";
  s21_sprintf(test_str_847, "%.0x", 0);
  sprintf(test_str_847_847, "%.0x", 0);
  ck_assert_str_eq(test_str_847, test_str_847_847);
}
END_TEST

START_TEST(sprintf_test_848) {
  char test_str_848[50] = "";
  char test_str_848_848[50] = "";
  s21_sprintf(test_str_848, "%.0x", 1);
  sprintf(test_str_848_848, "%.0x", 1);
  ck_assert_str_eq(test_str_848, test_str_848_848);
}
END_TEST

START_TEST(sprintf_test_849) {
  char test_str_849[50] = "";
  char test_str_849_849[50] = "";
  s21_sprintf(test_str_849, "%.0x", 10);
  sprintf(test_str_849_849, "%.0x", 10);
  ck_assert_str_eq(test_str_849, test_str_849_849);
}
END_TEST

START_TEST(sprintf_test_850) {
  char test_str_850[50] = "";
  char test_str_850_850[50] = "";
  s21_sprintf(test_str_850, "%.0x", 123456);
  sprintf(test_str_850_850, "%.0x", 123456);
  ck_assert_str_eq(test_str_850, test_str_850_850);
}
END_TEST

START_TEST(sprintf_test_851) {
  char test_str_851[50] = "";
  char test_str_851_851[50] = "";
  s21_sprintf(test_str_851, "%.0x", -67890123);
  sprintf(test_str_851_851, "%.0x", -67890123);
  ck_assert_str_eq(test_str_851, test_str_851_851);
}
END_TEST

START_TEST(sprintf_test_852) {
  char test_str_852[50] = "";
  char test_str_852_852[50] = "";
  s21_sprintf(test_str_852, "%.0x", 4343);
  sprintf(test_str_852_852, "%.0x", 4343);
  ck_assert_str_eq(test_str_852, test_str_852_852);
}
END_TEST

START_TEST(sprintf_test_853) {
  char test_str_853[50] = "";
  char test_str_853_853[50] = "";
  s21_sprintf(test_str_853, "%.0x", -1);
  sprintf(test_str_853_853, "%.0x", -1);
  ck_assert_str_eq(test_str_853, test_str_853_853);
}
END_TEST

START_TEST(sprintf_test_854) {
  char test_str_854[50] = "";
  char test_str_854_854[50] = "";
  s21_sprintf(test_str_854, "%.0x", -10);
  sprintf(test_str_854_854, "%.0x", -10);
  ck_assert_str_eq(test_str_854, test_str_854_854);
}
END_TEST

START_TEST(sprintf_test_855) {
  char test_str_855[50] = "";
  char test_str_855_855[50] = "";
  s21_sprintf(test_str_855, "%.0x", 43);
  sprintf(test_str_855_855, "%.0x", 43);
  ck_assert_str_eq(test_str_855, test_str_855_855);
}
END_TEST

START_TEST(sprintf_test_856) {
  char test_str_856[50] = "";
  char test_str_856_856[50] = "";
  s21_sprintf(test_str_856, "%.0X", 0);
  sprintf(test_str_856_856, "%.0X", 0);
  ck_assert_str_eq(test_str_856, test_str_856_856);
}
END_TEST

START_TEST(sprintf_test_857) {
  char test_str_857[50] = "";
  char test_str_857_857[50] = "";
  s21_sprintf(test_str_857, "%.0X", 1);
  sprintf(test_str_857_857, "%.0X", 1);
  ck_assert_str_eq(test_str_857, test_str_857_857);
}
END_TEST

START_TEST(sprintf_test_858) {
  char test_str_858[50] = "";
  char test_str_858_858[50] = "";
  s21_sprintf(test_str_858, "%.0X", 10);
  sprintf(test_str_858_858, "%.0X", 10);
  ck_assert_str_eq(test_str_858, test_str_858_858);
}
END_TEST

START_TEST(sprintf_test_859) {
  char test_str_859[50] = "";
  char test_str_859_859[50] = "";
  s21_sprintf(test_str_859, "%.0X", 123456);
  sprintf(test_str_859_859, "%.0X", 123456);
  ck_assert_str_eq(test_str_859, test_str_859_859);
}
END_TEST

START_TEST(sprintf_test_860) {
  char test_str_860[50] = "";
  char test_str_860_860[50] = "";
  s21_sprintf(test_str_860, "%.0X", -67890123);
  sprintf(test_str_860_860, "%.0X", -67890123);
  ck_assert_str_eq(test_str_860, test_str_860_860);
}
END_TEST

START_TEST(sprintf_test_861) {
  char test_str_861[50] = "";
  char test_str_861_861[50] = "";
  s21_sprintf(test_str_861, "%.0X", 4343);
  sprintf(test_str_861_861, "%.0X", 4343);
  ck_assert_str_eq(test_str_861, test_str_861_861);
}
END_TEST

START_TEST(sprintf_test_862) {
  char test_str_862[50] = "";
  char test_str_862_862[50] = "";
  s21_sprintf(test_str_862, "%.0X", -1);
  sprintf(test_str_862_862, "%.0X", -1);
  ck_assert_str_eq(test_str_862, test_str_862_862);
}
END_TEST

START_TEST(sprintf_test_863) {
  char test_str_863[50] = "";
  char test_str_863_863[50] = "";
  s21_sprintf(test_str_863, "%.0X", -10);
  sprintf(test_str_863_863, "%.0X", -10);
  ck_assert_str_eq(test_str_863, test_str_863_863);
}
END_TEST

START_TEST(sprintf_test_864) {
  char test_str_864[50] = "";
  char test_str_864_864[50] = "";
  s21_sprintf(test_str_864, "%.0X", 43);
  sprintf(test_str_864_864, "%.0X", 43);
  ck_assert_str_eq(test_str_864, test_str_864_864);
}
END_TEST

START_TEST(sprintf_test_865) {
  char test_str_865[50] = "";
  char test_str_865_865[50] = "";
  s21_sprintf(test_str_865, "%.10d", 0);
  sprintf(test_str_865_865, "%.10d", 0);
  ck_assert_str_eq(test_str_865, test_str_865_865);
}
END_TEST

START_TEST(sprintf_test_866) {
  char test_str_866[50] = "";
  char test_str_866_866[50] = "";
  s21_sprintf(test_str_866, "%.10d", 1);
  sprintf(test_str_866_866, "%.10d", 1);
  ck_assert_str_eq(test_str_866, test_str_866_866);
}
END_TEST

START_TEST(sprintf_test_867) {
  char test_str_867[50] = "";
  char test_str_867_867[50] = "";
  s21_sprintf(test_str_867, "%.10d", 10);
  sprintf(test_str_867_867, "%.10d", 10);
  ck_assert_str_eq(test_str_867, test_str_867_867);
}
END_TEST

START_TEST(sprintf_test_868) {
  char test_str_868[50] = "";
  char test_str_868_868[50] = "";
  s21_sprintf(test_str_868, "%.10d", 123456);
  sprintf(test_str_868_868, "%.10d", 123456);
  ck_assert_str_eq(test_str_868, test_str_868_868);
}
END_TEST

START_TEST(sprintf_test_869) {
  char test_str_869[50] = "";
  char test_str_869_869[50] = "";
  s21_sprintf(test_str_869, "%.10d", -67890123);
  sprintf(test_str_869_869, "%.10d", -67890123);
  ck_assert_str_eq(test_str_869, test_str_869_869);
}
END_TEST

START_TEST(sprintf_test_870) {
  char test_str_870[50] = "";
  char test_str_870_870[50] = "";
  s21_sprintf(test_str_870, "%.10d", 4343);
  sprintf(test_str_870_870, "%.10d", 4343);
  ck_assert_str_eq(test_str_870, test_str_870_870);
}
END_TEST

START_TEST(sprintf_test_871) {
  char test_str_871[50] = "";
  char test_str_871_871[50] = "";
  s21_sprintf(test_str_871, "%.10d", -1);
  sprintf(test_str_871_871, "%.10d", -1);
  ck_assert_str_eq(test_str_871, test_str_871_871);
}
END_TEST

START_TEST(sprintf_test_872) {
  char test_str_872[50] = "";
  char test_str_872_872[50] = "";
  s21_sprintf(test_str_872, "%.10d", -10);
  sprintf(test_str_872_872, "%.10d", -10);
  ck_assert_str_eq(test_str_872, test_str_872_872);
}
END_TEST

START_TEST(sprintf_test_873) {
  char test_str_873[50] = "";
  char test_str_873_873[50] = "";
  s21_sprintf(test_str_873, "%.10d", 43);
  sprintf(test_str_873_873, "%.10d", 43);
  ck_assert_str_eq(test_str_873, test_str_873_873);
}
END_TEST

START_TEST(sprintf_test_874) {
  char test_str_874[50] = "";
  char test_str_874_874[50] = "";
  s21_sprintf(test_str_874, "%.10i", 0);
  sprintf(test_str_874_874, "%.10i", 0);
  ck_assert_str_eq(test_str_874, test_str_874_874);
}
END_TEST

START_TEST(sprintf_test_875) {
  char test_str_875[50] = "";
  char test_str_875_875[50] = "";
  s21_sprintf(test_str_875, "%.10i", 1);
  sprintf(test_str_875_875, "%.10i", 1);
  ck_assert_str_eq(test_str_875, test_str_875_875);
}
END_TEST

START_TEST(sprintf_test_876) {
  char test_str_876[50] = "";
  char test_str_876_876[50] = "";
  s21_sprintf(test_str_876, "%.10i", 10);
  sprintf(test_str_876_876, "%.10i", 10);
  ck_assert_str_eq(test_str_876, test_str_876_876);
}
END_TEST

START_TEST(sprintf_test_877) {
  char test_str_877[50] = "";
  char test_str_877_877[50] = "";
  s21_sprintf(test_str_877, "%.10i", 123456);
  sprintf(test_str_877_877, "%.10i", 123456);
  ck_assert_str_eq(test_str_877, test_str_877_877);
}
END_TEST

START_TEST(sprintf_test_878) {
  char test_str_878[50] = "";
  char test_str_878_878[50] = "";
  s21_sprintf(test_str_878, "%.10i", -67890123);
  sprintf(test_str_878_878, "%.10i", -67890123);
  ck_assert_str_eq(test_str_878, test_str_878_878);
}
END_TEST

START_TEST(sprintf_test_879) {
  char test_str_879[50] = "";
  char test_str_879_879[50] = "";
  s21_sprintf(test_str_879, "%.10i", 4343);
  sprintf(test_str_879_879, "%.10i", 4343);
  ck_assert_str_eq(test_str_879, test_str_879_879);
}
END_TEST

START_TEST(sprintf_test_880) {
  char test_str_880[50] = "";
  char test_str_880_880[50] = "";
  s21_sprintf(test_str_880, "%.10i", -1);
  sprintf(test_str_880_880, "%.10i", -1);
  ck_assert_str_eq(test_str_880, test_str_880_880);
}
END_TEST

START_TEST(sprintf_test_881) {
  char test_str_881[50] = "";
  char test_str_881_881[50] = "";
  s21_sprintf(test_str_881, "%.10i", -10);
  sprintf(test_str_881_881, "%.10i", -10);
  ck_assert_str_eq(test_str_881, test_str_881_881);
}
END_TEST

START_TEST(sprintf_test_882) {
  char test_str_882[50] = "";
  char test_str_882_882[50] = "";
  s21_sprintf(test_str_882, "%.10i", 43);
  sprintf(test_str_882_882, "%.10i", 43);
  ck_assert_str_eq(test_str_882, test_str_882_882);
}
END_TEST

START_TEST(sprintf_test_883) {
  char test_str_883[50] = "";
  char test_str_883_883[50] = "";
  s21_sprintf(test_str_883, "%.10o", 0);
  sprintf(test_str_883_883, "%.10o", 0);
  ck_assert_str_eq(test_str_883, test_str_883_883);
}
END_TEST

START_TEST(sprintf_test_884) {
  char test_str_884[50] = "";
  char test_str_884_884[50] = "";
  s21_sprintf(test_str_884, "%.10o", 1);
  sprintf(test_str_884_884, "%.10o", 1);
  ck_assert_str_eq(test_str_884, test_str_884_884);
}
END_TEST

START_TEST(sprintf_test_885) {
  char test_str_885[50] = "";
  char test_str_885_885[50] = "";
  s21_sprintf(test_str_885, "%.10o", 10);
  sprintf(test_str_885_885, "%.10o", 10);
  ck_assert_str_eq(test_str_885, test_str_885_885);
}
END_TEST

START_TEST(sprintf_test_886) {
  char test_str_886[50] = "";
  char test_str_886_886[50] = "";
  s21_sprintf(test_str_886, "%.10o", 123456);
  sprintf(test_str_886_886, "%.10o", 123456);
  ck_assert_str_eq(test_str_886, test_str_886_886);
}
END_TEST

START_TEST(sprintf_test_887) {
  char test_str_887[50] = "";
  char test_str_887_887[50] = "";
  s21_sprintf(test_str_887, "%.10o", -67890123);
  sprintf(test_str_887_887, "%.10o", -67890123);
  ck_assert_str_eq(test_str_887, test_str_887_887);
}
END_TEST

START_TEST(sprintf_test_888) {
  char test_str_888[50] = "";
  char test_str_888_888[50] = "";
  s21_sprintf(test_str_888, "%.10o", 4343);
  sprintf(test_str_888_888, "%.10o", 4343);
  ck_assert_str_eq(test_str_888, test_str_888_888);
}
END_TEST

START_TEST(sprintf_test_889) {
  char test_str_889[50] = "";
  char test_str_889_889[50] = "";
  s21_sprintf(test_str_889, "%.10o", -1);
  sprintf(test_str_889_889, "%.10o", -1);
  ck_assert_str_eq(test_str_889, test_str_889_889);
}
END_TEST

START_TEST(sprintf_test_890) {
  char test_str_890[50] = "";
  char test_str_890_890[50] = "";
  s21_sprintf(test_str_890, "%.10o", -10);
  sprintf(test_str_890_890, "%.10o", -10);
  ck_assert_str_eq(test_str_890, test_str_890_890);
}
END_TEST

START_TEST(sprintf_test_891) {
  char test_str_891[50] = "";
  char test_str_891_891[50] = "";
  s21_sprintf(test_str_891, "%.10o", 43);
  sprintf(test_str_891_891, "%.10o", 43);
  ck_assert_str_eq(test_str_891, test_str_891_891);
}
END_TEST

START_TEST(sprintf_test_892) {
  char test_str_892[50] = "";
  char test_str_892_892[50] = "";
  s21_sprintf(test_str_892, "%.10u", 0);
  sprintf(test_str_892_892, "%.10u", 0);
  ck_assert_str_eq(test_str_892, test_str_892_892);
}
END_TEST

START_TEST(sprintf_test_893) {
  char test_str_893[50] = "";
  char test_str_893_893[50] = "";
  s21_sprintf(test_str_893, "%.10u", 1);
  sprintf(test_str_893_893, "%.10u", 1);
  ck_assert_str_eq(test_str_893, test_str_893_893);
}
END_TEST

START_TEST(sprintf_test_894) {
  char test_str_894[50] = "";
  char test_str_894_894[50] = "";
  s21_sprintf(test_str_894, "%.10u", 10);
  sprintf(test_str_894_894, "%.10u", 10);
  ck_assert_str_eq(test_str_894, test_str_894_894);
}
END_TEST

START_TEST(sprintf_test_895) {
  char test_str_895[50] = "";
  char test_str_895_895[50] = "";
  s21_sprintf(test_str_895, "%.10u", 123456);
  sprintf(test_str_895_895, "%.10u", 123456);
  ck_assert_str_eq(test_str_895, test_str_895_895);
}
END_TEST

START_TEST(sprintf_test_896) {
  char test_str_896[50] = "";
  char test_str_896_896[50] = "";
  s21_sprintf(test_str_896, "%.10u", -67890123);
  sprintf(test_str_896_896, "%.10u", -67890123);
  ck_assert_str_eq(test_str_896, test_str_896_896);
}
END_TEST

START_TEST(sprintf_test_897) {
  char test_str_897[50] = "";
  char test_str_897_897[50] = "";
  s21_sprintf(test_str_897, "%.10u", 4343);
  sprintf(test_str_897_897, "%.10u", 4343);
  ck_assert_str_eq(test_str_897, test_str_897_897);
}
END_TEST

START_TEST(sprintf_test_898) {
  char test_str_898[50] = "";
  char test_str_898_898[50] = "";
  s21_sprintf(test_str_898, "%.10u", -1);
  sprintf(test_str_898_898, "%.10u", -1);
  ck_assert_str_eq(test_str_898, test_str_898_898);
}
END_TEST

START_TEST(sprintf_test_899) {
  char test_str_899[50] = "";
  char test_str_899_899[50] = "";
  s21_sprintf(test_str_899, "%.10u", -10);
  sprintf(test_str_899_899, "%.10u", -10);
  ck_assert_str_eq(test_str_899, test_str_899_899);
}
END_TEST

START_TEST(sprintf_test_900) {
  char test_str_900[50] = "";
  char test_str_900_900[50] = "";
  s21_sprintf(test_str_900, "%.10u", 43);
  sprintf(test_str_900_900, "%.10u", 43);
  ck_assert_str_eq(test_str_900, test_str_900_900);
}
END_TEST

START_TEST(sprintf_test_901) {
  char test_str_901[50] = "";
  char test_str_901_901[50] = "";
  s21_sprintf(test_str_901, "%.10x", 0);
  sprintf(test_str_901_901, "%.10x", 0);
  ck_assert_str_eq(test_str_901, test_str_901_901);
}
END_TEST

START_TEST(sprintf_test_902) {
  char test_str_902[50] = "";
  char test_str_902_902[50] = "";
  s21_sprintf(test_str_902, "%.10x", 1);
  sprintf(test_str_902_902, "%.10x", 1);
  ck_assert_str_eq(test_str_902, test_str_902_902);
}
END_TEST

START_TEST(sprintf_test_903) {
  char test_str_903[50] = "";
  char test_str_903_903[50] = "";
  s21_sprintf(test_str_903, "%.10x", 10);
  sprintf(test_str_903_903, "%.10x", 10);
  ck_assert_str_eq(test_str_903, test_str_903_903);
}
END_TEST

START_TEST(sprintf_test_904) {
  char test_str_904[50] = "";
  char test_str_904_904[50] = "";
  s21_sprintf(test_str_904, "%.10x", 123456);
  sprintf(test_str_904_904, "%.10x", 123456);
  ck_assert_str_eq(test_str_904, test_str_904_904);
}
END_TEST

START_TEST(sprintf_test_905) {
  char test_str_905[50] = "";
  char test_str_905_905[50] = "";
  s21_sprintf(test_str_905, "%.10x", -67890123);
  sprintf(test_str_905_905, "%.10x", -67890123);
  ck_assert_str_eq(test_str_905, test_str_905_905);
}
END_TEST

START_TEST(sprintf_test_906) {
  char test_str_906[50] = "";
  char test_str_906_906[50] = "";
  s21_sprintf(test_str_906, "%.10x", 4343);
  sprintf(test_str_906_906, "%.10x", 4343);
  ck_assert_str_eq(test_str_906, test_str_906_906);
}
END_TEST

START_TEST(sprintf_test_907) {
  char test_str_907[50] = "";
  char test_str_907_907[50] = "";
  s21_sprintf(test_str_907, "%.10x", -1);
  sprintf(test_str_907_907, "%.10x", -1);
  ck_assert_str_eq(test_str_907, test_str_907_907);
}
END_TEST

START_TEST(sprintf_test_908) {
  char test_str_908[50] = "";
  char test_str_908_908[50] = "";
  s21_sprintf(test_str_908, "%.10x", -10);
  sprintf(test_str_908_908, "%.10x", -10);
  ck_assert_str_eq(test_str_908, test_str_908_908);
}
END_TEST

START_TEST(sprintf_test_909) {
  char test_str_909[50] = "";
  char test_str_909_909[50] = "";
  s21_sprintf(test_str_909, "%.10x", 43);
  sprintf(test_str_909_909, "%.10x", 43);
  ck_assert_str_eq(test_str_909, test_str_909_909);
}
END_TEST

START_TEST(sprintf_test_910) {
  char test_str_910[50] = "";
  char test_str_910_910[50] = "";
  s21_sprintf(test_str_910, "%.10X", 0);
  sprintf(test_str_910_910, "%.10X", 0);
  ck_assert_str_eq(test_str_910, test_str_910_910);
}
END_TEST

START_TEST(sprintf_test_911) {
  char test_str_911[50] = "";
  char test_str_911_911[50] = "";
  s21_sprintf(test_str_911, "%.10X", 1);
  sprintf(test_str_911_911, "%.10X", 1);
  ck_assert_str_eq(test_str_911, test_str_911_911);
}
END_TEST

START_TEST(sprintf_test_912) {
  char test_str_912[50] = "";
  char test_str_912_912[50] = "";
  s21_sprintf(test_str_912, "%.10X", 10);
  sprintf(test_str_912_912, "%.10X", 10);
  ck_assert_str_eq(test_str_912, test_str_912_912);
}
END_TEST

START_TEST(sprintf_test_913) {
  char test_str_913[50] = "";
  char test_str_913_913[50] = "";
  s21_sprintf(test_str_913, "%.10X", 123456);
  sprintf(test_str_913_913, "%.10X", 123456);
  ck_assert_str_eq(test_str_913, test_str_913_913);
}
END_TEST

START_TEST(sprintf_test_914) {
  char test_str_914[50] = "";
  char test_str_914_914[50] = "";
  s21_sprintf(test_str_914, "%.10X", -67890123);
  sprintf(test_str_914_914, "%.10X", -67890123);
  ck_assert_str_eq(test_str_914, test_str_914_914);
}
END_TEST

START_TEST(sprintf_test_915) {
  char test_str_915[50] = "";
  char test_str_915_915[50] = "";
  s21_sprintf(test_str_915, "%.10X", 4343);
  sprintf(test_str_915_915, "%.10X", 4343);
  ck_assert_str_eq(test_str_915, test_str_915_915);
}
END_TEST

START_TEST(sprintf_test_916) {
  char test_str_916[50] = "";
  char test_str_916_916[50] = "";
  s21_sprintf(test_str_916, "%.10X", -1);
  sprintf(test_str_916_916, "%.10X", -1);
  ck_assert_str_eq(test_str_916, test_str_916_916);
}
END_TEST

START_TEST(sprintf_test_917) {
  char test_str_917[50] = "";
  char test_str_917_917[50] = "";
  s21_sprintf(test_str_917, "%.10X", -10);
  sprintf(test_str_917_917, "%.10X", -10);
  ck_assert_str_eq(test_str_917, test_str_917_917);
}
END_TEST

START_TEST(sprintf_test_918) {
  char test_str_918[50] = "";
  char test_str_918_918[50] = "";
  s21_sprintf(test_str_918, "%.10X", 43);
  sprintf(test_str_918_918, "%.10X", 43);
  ck_assert_str_eq(test_str_918, test_str_918_918);
}
END_TEST

START_TEST(sprintf_test_919) {
  char test_str_919[50] = "";
  char test_str_919_919[50] = "";
  s21_sprintf(test_str_919, "%.20d", 0);
  sprintf(test_str_919_919, "%.20d", 0);
  ck_assert_str_eq(test_str_919, test_str_919_919);
}
END_TEST

START_TEST(sprintf_test_920) {
  char test_str_920[50] = "";
  char test_str_920_920[50] = "";
  s21_sprintf(test_str_920, "%.20d", 1);
  sprintf(test_str_920_920, "%.20d", 1);
  ck_assert_str_eq(test_str_920, test_str_920_920);
}
END_TEST

START_TEST(sprintf_test_921) {
  char test_str_921[50] = "";
  char test_str_921_921[50] = "";
  s21_sprintf(test_str_921, "%.20d", 10);
  sprintf(test_str_921_921, "%.20d", 10);
  ck_assert_str_eq(test_str_921, test_str_921_921);
}
END_TEST

START_TEST(sprintf_test_922) {
  char test_str_922[50] = "";
  char test_str_922_922[50] = "";
  s21_sprintf(test_str_922, "%.20d", 123456);
  sprintf(test_str_922_922, "%.20d", 123456);
  ck_assert_str_eq(test_str_922, test_str_922_922);
}
END_TEST

START_TEST(sprintf_test_923) {
  char test_str_923[50] = "";
  char test_str_923_923[50] = "";
  s21_sprintf(test_str_923, "%.20d", -67890123);
  sprintf(test_str_923_923, "%.20d", -67890123);
  ck_assert_str_eq(test_str_923, test_str_923_923);
}
END_TEST

START_TEST(sprintf_test_924) {
  char test_str_924[50] = "";
  char test_str_924_924[50] = "";
  s21_sprintf(test_str_924, "%.20d", 4343);
  sprintf(test_str_924_924, "%.20d", 4343);
  ck_assert_str_eq(test_str_924, test_str_924_924);
}
END_TEST

START_TEST(sprintf_test_925) {
  char test_str_925[50] = "";
  char test_str_925_925[50] = "";
  s21_sprintf(test_str_925, "%.20d", -1);
  sprintf(test_str_925_925, "%.20d", -1);
  ck_assert_str_eq(test_str_925, test_str_925_925);
}
END_TEST

START_TEST(sprintf_test_926) {
  char test_str_926[50] = "";
  char test_str_926_926[50] = "";
  s21_sprintf(test_str_926, "%.20d", -10);
  sprintf(test_str_926_926, "%.20d", -10);
  ck_assert_str_eq(test_str_926, test_str_926_926);
}
END_TEST

START_TEST(sprintf_test_927) {
  char test_str_927[50] = "";
  char test_str_927_927[50] = "";
  s21_sprintf(test_str_927, "%.20d", 43);
  sprintf(test_str_927_927, "%.20d", 43);
  ck_assert_str_eq(test_str_927, test_str_927_927);
}
END_TEST

START_TEST(sprintf_test_928) {
  char test_str_928[50] = "";
  char test_str_928_928[50] = "";
  s21_sprintf(test_str_928, "%.20i", 0);
  sprintf(test_str_928_928, "%.20i", 0);
  ck_assert_str_eq(test_str_928, test_str_928_928);
}
END_TEST

START_TEST(sprintf_test_929) {
  char test_str_929[50] = "";
  char test_str_929_929[50] = "";
  s21_sprintf(test_str_929, "%.20i", 1);
  sprintf(test_str_929_929, "%.20i", 1);
  ck_assert_str_eq(test_str_929, test_str_929_929);
}
END_TEST

START_TEST(sprintf_test_930) {
  char test_str_930[50] = "";
  char test_str_930_930[50] = "";
  s21_sprintf(test_str_930, "%.20i", 10);
  sprintf(test_str_930_930, "%.20i", 10);
  ck_assert_str_eq(test_str_930, test_str_930_930);
}
END_TEST

START_TEST(sprintf_test_931) {
  char test_str_931[50] = "";
  char test_str_931_931[50] = "";
  s21_sprintf(test_str_931, "%.20i", 123456);
  sprintf(test_str_931_931, "%.20i", 123456);
  ck_assert_str_eq(test_str_931, test_str_931_931);
}
END_TEST

START_TEST(sprintf_test_932) {
  char test_str_932[50] = "";
  char test_str_932_932[50] = "";
  s21_sprintf(test_str_932, "%.20i", -67890123);
  sprintf(test_str_932_932, "%.20i", -67890123);
  ck_assert_str_eq(test_str_932, test_str_932_932);
}
END_TEST

START_TEST(sprintf_test_933) {
  char test_str_933[50] = "";
  char test_str_933_933[50] = "";
  s21_sprintf(test_str_933, "%.20i", 4343);
  sprintf(test_str_933_933, "%.20i", 4343);
  ck_assert_str_eq(test_str_933, test_str_933_933);
}
END_TEST

START_TEST(sprintf_test_934) {
  char test_str_934[50] = "";
  char test_str_934_934[50] = "";
  s21_sprintf(test_str_934, "%.20i", -1);
  sprintf(test_str_934_934, "%.20i", -1);
  ck_assert_str_eq(test_str_934, test_str_934_934);
}
END_TEST

START_TEST(sprintf_test_935) {
  char test_str_935[50] = "";
  char test_str_935_935[50] = "";
  s21_sprintf(test_str_935, "%.20i", -10);
  sprintf(test_str_935_935, "%.20i", -10);
  ck_assert_str_eq(test_str_935, test_str_935_935);
}
END_TEST

START_TEST(sprintf_test_936) {
  char test_str_936[50] = "";
  char test_str_936_936[50] = "";
  s21_sprintf(test_str_936, "%.20i", 43);
  sprintf(test_str_936_936, "%.20i", 43);
  ck_assert_str_eq(test_str_936, test_str_936_936);
}
END_TEST

START_TEST(sprintf_test_937) {
  char test_str_937[50] = "";
  char test_str_937_937[50] = "";
  s21_sprintf(test_str_937, "%.20o", 0);
  sprintf(test_str_937_937, "%.20o", 0);
  ck_assert_str_eq(test_str_937, test_str_937_937);
}
END_TEST

START_TEST(sprintf_test_938) {
  char test_str_938[50] = "";
  char test_str_938_938[50] = "";
  s21_sprintf(test_str_938, "%.20o", 1);
  sprintf(test_str_938_938, "%.20o", 1);
  ck_assert_str_eq(test_str_938, test_str_938_938);
}
END_TEST

START_TEST(sprintf_test_939) {
  char test_str_939[50] = "";
  char test_str_939_939[50] = "";
  s21_sprintf(test_str_939, "%.20o", 10);
  sprintf(test_str_939_939, "%.20o", 10);
  ck_assert_str_eq(test_str_939, test_str_939_939);
}
END_TEST

START_TEST(sprintf_test_940) {
  char test_str_940[50] = "";
  char test_str_940_940[50] = "";
  s21_sprintf(test_str_940, "%.20o", 123456);
  sprintf(test_str_940_940, "%.20o", 123456);
  ck_assert_str_eq(test_str_940, test_str_940_940);
}
END_TEST

START_TEST(sprintf_test_941) {
  char test_str_941[50] = "";
  char test_str_941_941[50] = "";
  s21_sprintf(test_str_941, "%.20o", -67890123);
  sprintf(test_str_941_941, "%.20o", -67890123);
  ck_assert_str_eq(test_str_941, test_str_941_941);
}
END_TEST

START_TEST(sprintf_test_942) {
  char test_str_942[50] = "";
  char test_str_942_942[50] = "";
  s21_sprintf(test_str_942, "%.20o", 4343);
  sprintf(test_str_942_942, "%.20o", 4343);
  ck_assert_str_eq(test_str_942, test_str_942_942);
}
END_TEST

START_TEST(sprintf_test_943) {
  char test_str_943[50] = "";
  char test_str_943_943[50] = "";
  s21_sprintf(test_str_943, "%.20o", -1);
  sprintf(test_str_943_943, "%.20o", -1);
  ck_assert_str_eq(test_str_943, test_str_943_943);
}
END_TEST

START_TEST(sprintf_test_944) {
  char test_str_944[50] = "";
  char test_str_944_944[50] = "";
  s21_sprintf(test_str_944, "%.20o", -10);
  sprintf(test_str_944_944, "%.20o", -10);
  ck_assert_str_eq(test_str_944, test_str_944_944);
}
END_TEST

START_TEST(sprintf_test_945) {
  char test_str_945[50] = "";
  char test_str_945_945[50] = "";
  s21_sprintf(test_str_945, "%.20o", 43);
  sprintf(test_str_945_945, "%.20o", 43);
  ck_assert_str_eq(test_str_945, test_str_945_945);
}
END_TEST

START_TEST(sprintf_test_946) {
  char test_str_946[50] = "";
  char test_str_946_946[50] = "";
  s21_sprintf(test_str_946, "%.20u", 0);
  sprintf(test_str_946_946, "%.20u", 0);
  ck_assert_str_eq(test_str_946, test_str_946_946);
}
END_TEST

START_TEST(sprintf_test_947) {
  char test_str_947[50] = "";
  char test_str_947_947[50] = "";
  s21_sprintf(test_str_947, "%.20u", 1);
  sprintf(test_str_947_947, "%.20u", 1);
  ck_assert_str_eq(test_str_947, test_str_947_947);
}
END_TEST

START_TEST(sprintf_test_948) {
  char test_str_948[50] = "";
  char test_str_948_948[50] = "";
  s21_sprintf(test_str_948, "%.20u", 10);
  sprintf(test_str_948_948, "%.20u", 10);
  ck_assert_str_eq(test_str_948, test_str_948_948);
}
END_TEST

START_TEST(sprintf_test_949) {
  char test_str_949[50] = "";
  char test_str_949_949[50] = "";
  s21_sprintf(test_str_949, "%.20u", 123456);
  sprintf(test_str_949_949, "%.20u", 123456);
  ck_assert_str_eq(test_str_949, test_str_949_949);
}
END_TEST

START_TEST(sprintf_test_950) {
  char test_str_950[50] = "";
  char test_str_950_950[50] = "";
  s21_sprintf(test_str_950, "%.20u", -67890123);
  sprintf(test_str_950_950, "%.20u", -67890123);
  ck_assert_str_eq(test_str_950, test_str_950_950);
}
END_TEST

START_TEST(sprintf_test_951) {
  char test_str_951[50] = "";
  char test_str_951_951[50] = "";
  s21_sprintf(test_str_951, "%.20u", 4343);
  sprintf(test_str_951_951, "%.20u", 4343);
  ck_assert_str_eq(test_str_951, test_str_951_951);
}
END_TEST

START_TEST(sprintf_test_952) {
  char test_str_952[50] = "";
  char test_str_952_952[50] = "";
  s21_sprintf(test_str_952, "%.20u", -1);
  sprintf(test_str_952_952, "%.20u", -1);
  ck_assert_str_eq(test_str_952, test_str_952_952);
}
END_TEST

START_TEST(sprintf_test_953) {
  char test_str_953[50] = "";
  char test_str_953_953[50] = "";
  s21_sprintf(test_str_953, "%.20u", -10);
  sprintf(test_str_953_953, "%.20u", -10);
  ck_assert_str_eq(test_str_953, test_str_953_953);
}
END_TEST

START_TEST(sprintf_test_954) {
  char test_str_954[50] = "";
  char test_str_954_954[50] = "";
  s21_sprintf(test_str_954, "%.20u", 43);
  sprintf(test_str_954_954, "%.20u", 43);
  ck_assert_str_eq(test_str_954, test_str_954_954);
}
END_TEST

START_TEST(sprintf_test_955) {
  char test_str_955[50] = "";
  char test_str_955_955[50] = "";
  s21_sprintf(test_str_955, "%.20x", 0);
  sprintf(test_str_955_955, "%.20x", 0);
  ck_assert_str_eq(test_str_955, test_str_955_955);
}
END_TEST

START_TEST(sprintf_test_956) {
  char test_str_956[50] = "";
  char test_str_956_956[50] = "";
  s21_sprintf(test_str_956, "%.20x", 1);
  sprintf(test_str_956_956, "%.20x", 1);
  ck_assert_str_eq(test_str_956, test_str_956_956);
}
END_TEST

START_TEST(sprintf_test_957) {
  char test_str_957[50] = "";
  char test_str_957_957[50] = "";
  s21_sprintf(test_str_957, "%.20x", 10);
  sprintf(test_str_957_957, "%.20x", 10);
  ck_assert_str_eq(test_str_957, test_str_957_957);
}
END_TEST

START_TEST(sprintf_test_958) {
  char test_str_958[50] = "";
  char test_str_958_958[50] = "";
  s21_sprintf(test_str_958, "%.20x", 123456);
  sprintf(test_str_958_958, "%.20x", 123456);
  ck_assert_str_eq(test_str_958, test_str_958_958);
}
END_TEST

START_TEST(sprintf_test_959) {
  char test_str_959[50] = "";
  char test_str_959_959[50] = "";
  s21_sprintf(test_str_959, "%.20x", -67890123);
  sprintf(test_str_959_959, "%.20x", -67890123);
  ck_assert_str_eq(test_str_959, test_str_959_959);
}
END_TEST

START_TEST(sprintf_test_960) {
  char test_str_960[50] = "";
  char test_str_960_960[50] = "";
  s21_sprintf(test_str_960, "%.20x", 4343);
  sprintf(test_str_960_960, "%.20x", 4343);
  ck_assert_str_eq(test_str_960, test_str_960_960);
}
END_TEST

START_TEST(sprintf_test_961) {
  char test_str_961[50] = "";
  char test_str_961_961[50] = "";
  s21_sprintf(test_str_961, "%.20x", -1);
  sprintf(test_str_961_961, "%.20x", -1);
  ck_assert_str_eq(test_str_961, test_str_961_961);
}
END_TEST

START_TEST(sprintf_test_962) {
  char test_str_962[50] = "";
  char test_str_962_962[50] = "";
  s21_sprintf(test_str_962, "%.20x", -10);
  sprintf(test_str_962_962, "%.20x", -10);
  ck_assert_str_eq(test_str_962, test_str_962_962);
}
END_TEST

START_TEST(sprintf_test_963) {
  char test_str_963[50] = "";
  char test_str_963_963[50] = "";
  s21_sprintf(test_str_963, "%.20x", 43);
  sprintf(test_str_963_963, "%.20x", 43);
  ck_assert_str_eq(test_str_963, test_str_963_963);
}
END_TEST

START_TEST(sprintf_test_964) {
  char test_str_964[50] = "";
  char test_str_964_964[50] = "";
  s21_sprintf(test_str_964, "%.20X", 0);
  sprintf(test_str_964_964, "%.20X", 0);
  ck_assert_str_eq(test_str_964, test_str_964_964);
}
END_TEST

START_TEST(sprintf_test_965) {
  char test_str_965[50] = "";
  char test_str_965_965[50] = "";
  s21_sprintf(test_str_965, "%.20X", 1);
  sprintf(test_str_965_965, "%.20X", 1);
  ck_assert_str_eq(test_str_965, test_str_965_965);
}
END_TEST

START_TEST(sprintf_test_966) {
  char test_str_966[50] = "";
  char test_str_966_966[50] = "";
  s21_sprintf(test_str_966, "%.20X", 10);
  sprintf(test_str_966_966, "%.20X", 10);
  ck_assert_str_eq(test_str_966, test_str_966_966);
}
END_TEST

START_TEST(sprintf_test_967) {
  char test_str_967[50] = "";
  char test_str_967_967[50] = "";
  s21_sprintf(test_str_967, "%.20X", 123456);
  sprintf(test_str_967_967, "%.20X", 123456);
  ck_assert_str_eq(test_str_967, test_str_967_967);
}
END_TEST

START_TEST(sprintf_test_968) {
  char test_str_968[50] = "";
  char test_str_968_968[50] = "";
  s21_sprintf(test_str_968, "%.20X", -67890123);
  sprintf(test_str_968_968, "%.20X", -67890123);
  ck_assert_str_eq(test_str_968, test_str_968_968);
}
END_TEST

START_TEST(sprintf_test_969) {
  char test_str_969[50] = "";
  char test_str_969_969[50] = "";
  s21_sprintf(test_str_969, "%.20X", 4343);
  sprintf(test_str_969_969, "%.20X", 4343);
  ck_assert_str_eq(test_str_969, test_str_969_969);
}
END_TEST

START_TEST(sprintf_test_970) {
  char test_str_970[50] = "";
  char test_str_970_970[50] = "";
  s21_sprintf(test_str_970, "%.20X", -1);
  sprintf(test_str_970_970, "%.20X", -1);
  ck_assert_str_eq(test_str_970, test_str_970_970);
}
END_TEST

START_TEST(sprintf_test_971) {
  char test_str_971[50] = "";
  char test_str_971_971[50] = "";
  s21_sprintf(test_str_971, "%.20X", -10);
  sprintf(test_str_971_971, "%.20X", -10);
  ck_assert_str_eq(test_str_971, test_str_971_971);
}
END_TEST

START_TEST(sprintf_test_972) {
  char test_str_972[50] = "";
  char test_str_972_972[50] = "";
  s21_sprintf(test_str_972, "%.20X", 43);
  sprintf(test_str_972_972, "%.20X", 43);
  ck_assert_str_eq(test_str_972, test_str_972_972);
}
END_TEST

START_TEST(sprintf_test_973) {
  char test_str_973[50] = "";
  char test_str_973_973[50] = "";
  s21_sprintf(test_str_973, "%.-10d", 0);
  sprintf(test_str_973_973, "%.-10d", 0);
  ck_assert_str_eq(test_str_973, test_str_973_973);
}
END_TEST

START_TEST(sprintf_test_974) {
  char test_str_974[50] = "";
  char test_str_974_974[50] = "";
  s21_sprintf(test_str_974, "%.-10d", 1);
  sprintf(test_str_974_974, "%.-10d", 1);
  ck_assert_str_eq(test_str_974, test_str_974_974);
}
END_TEST

START_TEST(sprintf_test_975) {
  char test_str_975[50] = "";
  char test_str_975_975[50] = "";
  s21_sprintf(test_str_975, "%.-10d", 10);
  sprintf(test_str_975_975, "%.-10d", 10);
  ck_assert_str_eq(test_str_975, test_str_975_975);
}
END_TEST

START_TEST(sprintf_test_976) {
  char test_str_976[50] = "";
  char test_str_976_976[50] = "";
  s21_sprintf(test_str_976, "%.-10d", 123456);
  sprintf(test_str_976_976, "%.-10d", 123456);
  ck_assert_str_eq(test_str_976, test_str_976_976);
}
END_TEST

START_TEST(sprintf_test_977) {
  char test_str_977[50] = "";
  char test_str_977_977[50] = "";
  s21_sprintf(test_str_977, "%.-10d", -67890123);
  sprintf(test_str_977_977, "%.-10d", -67890123);
  ck_assert_str_eq(test_str_977, test_str_977_977);
}
END_TEST

START_TEST(sprintf_test_978) {
  char test_str_978[50] = "";
  char test_str_978_978[50] = "";
  s21_sprintf(test_str_978, "%.-10d", 4343);
  sprintf(test_str_978_978, "%.-10d", 4343);
  ck_assert_str_eq(test_str_978, test_str_978_978);
}
END_TEST

START_TEST(sprintf_test_979) {
  char test_str_979[50] = "";
  char test_str_979_979[50] = "";
  s21_sprintf(test_str_979, "%.-10d", -1);
  sprintf(test_str_979_979, "%.-10d", -1);
  ck_assert_str_eq(test_str_979, test_str_979_979);
}
END_TEST

START_TEST(sprintf_test_980) {
  char test_str_980[50] = "";
  char test_str_980_980[50] = "";
  s21_sprintf(test_str_980, "%.-10d", -10);
  sprintf(test_str_980_980, "%.-10d", -10);
  ck_assert_str_eq(test_str_980, test_str_980_980);
}
END_TEST

START_TEST(sprintf_test_981) {
  char test_str_981[50] = "";
  char test_str_981_981[50] = "";
  s21_sprintf(test_str_981, "%.-10d", 43);
  sprintf(test_str_981_981, "%.-10d", 43);
  ck_assert_str_eq(test_str_981, test_str_981_981);
}
END_TEST

START_TEST(sprintf_test_982) {
  char test_str_982[50] = "";
  char test_str_982_982[50] = "";
  s21_sprintf(test_str_982, "%.-10i", 0);
  sprintf(test_str_982_982, "%.-10i", 0);
  ck_assert_str_eq(test_str_982, test_str_982_982);
}
END_TEST

START_TEST(sprintf_test_983) {
  char test_str_983[50] = "";
  char test_str_983_983[50] = "";
  s21_sprintf(test_str_983, "%.-10i", 1);
  sprintf(test_str_983_983, "%.-10i", 1);
  ck_assert_str_eq(test_str_983, test_str_983_983);
}
END_TEST

START_TEST(sprintf_test_984) {
  char test_str_984[50] = "";
  char test_str_984_984[50] = "";
  s21_sprintf(test_str_984, "%.-10i", 10);
  sprintf(test_str_984_984, "%.-10i", 10);
  ck_assert_str_eq(test_str_984, test_str_984_984);
}
END_TEST

START_TEST(sprintf_test_985) {
  char test_str_985[50] = "";
  char test_str_985_985[50] = "";
  s21_sprintf(test_str_985, "%.-10i", 123456);
  sprintf(test_str_985_985, "%.-10i", 123456);
  ck_assert_str_eq(test_str_985, test_str_985_985);
}
END_TEST

START_TEST(sprintf_test_986) {
  char test_str_986[50] = "";
  char test_str_986_986[50] = "";
  s21_sprintf(test_str_986, "%.-10i", -67890123);
  sprintf(test_str_986_986, "%.-10i", -67890123);
  ck_assert_str_eq(test_str_986, test_str_986_986);
}
END_TEST

START_TEST(sprintf_test_987) {
  char test_str_987[50] = "";
  char test_str_987_987[50] = "";
  s21_sprintf(test_str_987, "%.-10i", 4343);
  sprintf(test_str_987_987, "%.-10i", 4343);
  ck_assert_str_eq(test_str_987, test_str_987_987);
}
END_TEST

START_TEST(sprintf_test_988) {
  char test_str_988[50] = "";
  char test_str_988_988[50] = "";
  s21_sprintf(test_str_988, "%.-10i", -1);
  sprintf(test_str_988_988, "%.-10i", -1);
  ck_assert_str_eq(test_str_988, test_str_988_988);
}
END_TEST

START_TEST(sprintf_test_989) {
  char test_str_989[50] = "";
  char test_str_989_989[50] = "";
  s21_sprintf(test_str_989, "%.-10i", -10);
  sprintf(test_str_989_989, "%.-10i", -10);
  ck_assert_str_eq(test_str_989, test_str_989_989);
}
END_TEST

START_TEST(sprintf_test_990) {
  char test_str_990[50] = "";
  char test_str_990_990[50] = "";
  s21_sprintf(test_str_990, "%.-10i", 43);
  sprintf(test_str_990_990, "%.-10i", 43);
  ck_assert_str_eq(test_str_990, test_str_990_990);
}
END_TEST

START_TEST(sprintf_test_991) {
  char test_str_991[50] = "";
  char test_str_991_991[50] = "";
  s21_sprintf(test_str_991, "%.-10o", 0);
  sprintf(test_str_991_991, "%.-10o", 0);
  ck_assert_str_eq(test_str_991, test_str_991_991);
}
END_TEST

START_TEST(sprintf_test_992) {
  char test_str_992[50] = "";
  char test_str_992_992[50] = "";
  s21_sprintf(test_str_992, "%.-10o", 1);
  sprintf(test_str_992_992, "%.-10o", 1);
  ck_assert_str_eq(test_str_992, test_str_992_992);
}
END_TEST

START_TEST(sprintf_test_993) {
  char test_str_993[50] = "";
  char test_str_993_993[50] = "";
  s21_sprintf(test_str_993, "%.-10o", 10);
  sprintf(test_str_993_993, "%.-10o", 10);
  ck_assert_str_eq(test_str_993, test_str_993_993);
}
END_TEST

START_TEST(sprintf_test_994) {
  char test_str_994[50] = "";
  char test_str_994_994[50] = "";
  s21_sprintf(test_str_994, "%.-10o", 123456);
  sprintf(test_str_994_994, "%.-10o", 123456);
  ck_assert_str_eq(test_str_994, test_str_994_994);
}
END_TEST

START_TEST(sprintf_test_995) {
  char test_str_995[50] = "";
  char test_str_995_995[50] = "";
  s21_sprintf(test_str_995, "%.-10o", -67890123);
  sprintf(test_str_995_995, "%.-10o", -67890123);
  ck_assert_str_eq(test_str_995, test_str_995_995);
}
END_TEST

START_TEST(sprintf_test_996) {
  char test_str_996[50] = "";
  char test_str_996_996[50] = "";
  s21_sprintf(test_str_996, "%.-10o", 4343);
  sprintf(test_str_996_996, "%.-10o", 4343);
  ck_assert_str_eq(test_str_996, test_str_996_996);
}
END_TEST

START_TEST(sprintf_test_997) {
  char test_str_997[50] = "";
  char test_str_997_997[50] = "";
  s21_sprintf(test_str_997, "%.-10o", -1);
  sprintf(test_str_997_997, "%.-10o", -1);
  ck_assert_str_eq(test_str_997, test_str_997_997);
}
END_TEST

START_TEST(sprintf_test_998) {
  char test_str_998[50] = "";
  char test_str_998_998[50] = "";
  s21_sprintf(test_str_998, "%.-10o", -10);
  sprintf(test_str_998_998, "%.-10o", -10);
  ck_assert_str_eq(test_str_998, test_str_998_998);
}
END_TEST

START_TEST(sprintf_test_999) {
  char test_str_999[50] = "";
  char test_str_999_999[50] = "";
  s21_sprintf(test_str_999, "%.-10o", 43);
  sprintf(test_str_999_999, "%.-10o", 43);
  ck_assert_str_eq(test_str_999, test_str_999_999);
}
END_TEST

START_TEST(sprintf_test_1000) {
  char test_str_1000[50] = "";
  char test_str_1000_1000[50] = "";
  s21_sprintf(test_str_1000, "%.-10u", 0);
  sprintf(test_str_1000_1000, "%.-10u", 0);
  ck_assert_str_eq(test_str_1000, test_str_1000_1000);
}
END_TEST

START_TEST(sprintf_test_1001) {
  char test_str_1001[50] = "";
  char test_str_1001_1001[50] = "";
  s21_sprintf(test_str_1001, "%.-10u", 1);
  sprintf(test_str_1001_1001, "%.-10u", 1);
  ck_assert_str_eq(test_str_1001, test_str_1001_1001);
}
END_TEST

START_TEST(sprintf_test_1002) {
  char test_str_1002[50] = "";
  char test_str_1002_1002[50] = "";
  s21_sprintf(test_str_1002, "%.-10u", 10);
  sprintf(test_str_1002_1002, "%.-10u", 10);
  ck_assert_str_eq(test_str_1002, test_str_1002_1002);
}
END_TEST

START_TEST(sprintf_test_1003) {
  char test_str_1003[50] = "";
  char test_str_1003_1003[50] = "";
  s21_sprintf(test_str_1003, "%.-10u", 123456);
  sprintf(test_str_1003_1003, "%.-10u", 123456);
  ck_assert_str_eq(test_str_1003, test_str_1003_1003);
}
END_TEST

START_TEST(sprintf_test_1004) {
  char test_str_1004[50] = "";
  char test_str_1004_1004[50] = "";
  s21_sprintf(test_str_1004, "%.-10u", -67890123);
  sprintf(test_str_1004_1004, "%.-10u", -67890123);
  ck_assert_str_eq(test_str_1004, test_str_1004_1004);
}
END_TEST

START_TEST(sprintf_test_1005) {
  char test_str_1005[50] = "";
  char test_str_1005_1005[50] = "";
  s21_sprintf(test_str_1005, "%.-10u", 4343);
  sprintf(test_str_1005_1005, "%.-10u", 4343);
  ck_assert_str_eq(test_str_1005, test_str_1005_1005);
}
END_TEST

START_TEST(sprintf_test_1006) {
  char test_str_1006[50] = "";
  char test_str_1006_1006[50] = "";
  s21_sprintf(test_str_1006, "%.-10u", -1);
  sprintf(test_str_1006_1006, "%.-10u", -1);
  ck_assert_str_eq(test_str_1006, test_str_1006_1006);
}
END_TEST

START_TEST(sprintf_test_1007) {
  char test_str_1007[50] = "";
  char test_str_1007_1007[50] = "";
  s21_sprintf(test_str_1007, "%.-10u", -10);
  sprintf(test_str_1007_1007, "%.-10u", -10);
  ck_assert_str_eq(test_str_1007, test_str_1007_1007);
}
END_TEST

START_TEST(sprintf_test_1008) {
  char test_str_1008[50] = "";
  char test_str_1008_1008[50] = "";
  s21_sprintf(test_str_1008, "%.-10u", 43);
  sprintf(test_str_1008_1008, "%.-10u", 43);
  ck_assert_str_eq(test_str_1008, test_str_1008_1008);
}
END_TEST

START_TEST(sprintf_test_1009) {
  char test_str_1009[50] = "";
  char test_str_1009_1009[50] = "";
  s21_sprintf(test_str_1009, "%.-10x", 0);
  sprintf(test_str_1009_1009, "%.-10x", 0);
  ck_assert_str_eq(test_str_1009, test_str_1009_1009);
}
END_TEST

START_TEST(sprintf_test_1010) {
  char test_str_1010[50] = "";
  char test_str_1010_1010[50] = "";
  s21_sprintf(test_str_1010, "%.-10x", 1);
  sprintf(test_str_1010_1010, "%.-10x", 1);
  ck_assert_str_eq(test_str_1010, test_str_1010_1010);
}
END_TEST

START_TEST(sprintf_test_1011) {
  char test_str_1011[50] = "";
  char test_str_1011_1011[50] = "";
  s21_sprintf(test_str_1011, "%.-10x", 10);
  sprintf(test_str_1011_1011, "%.-10x", 10);
  ck_assert_str_eq(test_str_1011, test_str_1011_1011);
}
END_TEST

START_TEST(sprintf_test_1012) {
  char test_str_1012[50] = "";
  char test_str_1012_1012[50] = "";
  s21_sprintf(test_str_1012, "%.-10x", 123456);
  sprintf(test_str_1012_1012, "%.-10x", 123456);
  ck_assert_str_eq(test_str_1012, test_str_1012_1012);
}
END_TEST

START_TEST(sprintf_test_1013) {
  char test_str_1013[50] = "";
  char test_str_1013_1013[50] = "";
  s21_sprintf(test_str_1013, "%.-10x", -67890123);
  sprintf(test_str_1013_1013, "%.-10x", -67890123);
  ck_assert_str_eq(test_str_1013, test_str_1013_1013);
}
END_TEST

START_TEST(sprintf_test_1014) {
  char test_str_1014[50] = "";
  char test_str_1014_1014[50] = "";
  s21_sprintf(test_str_1014, "%.-10x", 4343);
  sprintf(test_str_1014_1014, "%.-10x", 4343);
  ck_assert_str_eq(test_str_1014, test_str_1014_1014);
}
END_TEST

START_TEST(sprintf_test_1015) {
  char test_str_1015[50] = "";
  char test_str_1015_1015[50] = "";
  s21_sprintf(test_str_1015, "%.-10x", -1);
  sprintf(test_str_1015_1015, "%.-10x", -1);
  ck_assert_str_eq(test_str_1015, test_str_1015_1015);
}
END_TEST

START_TEST(sprintf_test_1016) {
  char test_str_1016[50] = "";
  char test_str_1016_1016[50] = "";
  s21_sprintf(test_str_1016, "%.-10x", -10);
  sprintf(test_str_1016_1016, "%.-10x", -10);
  ck_assert_str_eq(test_str_1016, test_str_1016_1016);
}
END_TEST

START_TEST(sprintf_test_1017) {
  char test_str_1017[50] = "";
  char test_str_1017_1017[50] = "";
  s21_sprintf(test_str_1017, "%.-10x", 43);
  sprintf(test_str_1017_1017, "%.-10x", 43);
  ck_assert_str_eq(test_str_1017, test_str_1017_1017);
}
END_TEST

START_TEST(sprintf_test_1018) {
  char test_str_1018[50] = "";
  char test_str_1018_1018[50] = "";
  s21_sprintf(test_str_1018, "%.-10X", 0);
  sprintf(test_str_1018_1018, "%.-10X", 0);
  ck_assert_str_eq(test_str_1018, test_str_1018_1018);
}
END_TEST

START_TEST(sprintf_test_1019) {
  char test_str_1019[50] = "";
  char test_str_1019_1019[50] = "";
  s21_sprintf(test_str_1019, "%.-10X", 1);
  sprintf(test_str_1019_1019, "%.-10X", 1);
  ck_assert_str_eq(test_str_1019, test_str_1019_1019);
}
END_TEST

START_TEST(sprintf_test_1020) {
  char test_str_1020[50] = "";
  char test_str_1020_1020[50] = "";
  s21_sprintf(test_str_1020, "%.-10X", 10);
  sprintf(test_str_1020_1020, "%.-10X", 10);
  ck_assert_str_eq(test_str_1020, test_str_1020_1020);
}
END_TEST

START_TEST(sprintf_test_1021) {
  char test_str_1021[50] = "";
  char test_str_1021_1021[50] = "";
  s21_sprintf(test_str_1021, "%.-10X", 123456);
  sprintf(test_str_1021_1021, "%.-10X", 123456);
  ck_assert_str_eq(test_str_1021, test_str_1021_1021);
}
END_TEST

START_TEST(sprintf_test_1022) {
  char test_str_1022[50] = "";
  char test_str_1022_1022[50] = "";
  s21_sprintf(test_str_1022, "%.-10X", -67890123);
  sprintf(test_str_1022_1022, "%.-10X", -67890123);
  ck_assert_str_eq(test_str_1022, test_str_1022_1022);
}
END_TEST

START_TEST(sprintf_test_1023) {
  char test_str_1023[50] = "";
  char test_str_1023_1023[50] = "";
  s21_sprintf(test_str_1023, "%.-10X", 4343);
  sprintf(test_str_1023_1023, "%.-10X", 4343);
  ck_assert_str_eq(test_str_1023, test_str_1023_1023);
}
END_TEST

START_TEST(sprintf_test_1024) {
  char test_str_1024[50] = "";
  char test_str_1024_1024[50] = "";
  s21_sprintf(test_str_1024, "%.-10X", -1);
  sprintf(test_str_1024_1024, "%.-10X", -1);
  ck_assert_str_eq(test_str_1024, test_str_1024_1024);
}
END_TEST

START_TEST(sprintf_test_1025) {
  char test_str_1025[50] = "";
  char test_str_1025_1025[50] = "";
  s21_sprintf(test_str_1025, "%.-10X", -10);
  sprintf(test_str_1025_1025, "%.-10X", -10);
  ck_assert_str_eq(test_str_1025, test_str_1025_1025);
}
END_TEST

START_TEST(sprintf_test_1026) {
  char test_str_1026[50] = "";
  char test_str_1026_1026[50] = "";
  s21_sprintf(test_str_1026, "%.-10X", 43);
  sprintf(test_str_1026_1026, "%.-10X", 43);
  ck_assert_str_eq(test_str_1026, test_str_1026_1026);
}
END_TEST

START_TEST(sprintf_test_1027) {
  char test_str_1027[50] = "";
  char test_str_1027_1027[50] = "";
  s21_sprintf(test_str_1027, "%.-20d", 0);
  sprintf(test_str_1027_1027, "%.-20d", 0);
  ck_assert_str_eq(test_str_1027, test_str_1027_1027);
}
END_TEST

START_TEST(sprintf_test_1028) {
  char test_str_1028[50] = "";
  char test_str_1028_1028[50] = "";
  s21_sprintf(test_str_1028, "%.-20d", 1);
  sprintf(test_str_1028_1028, "%.-20d", 1);
  ck_assert_str_eq(test_str_1028, test_str_1028_1028);
}
END_TEST

START_TEST(sprintf_test_1029) {
  char test_str_1029[50] = "";
  char test_str_1029_1029[50] = "";
  s21_sprintf(test_str_1029, "%.-20d", 10);
  sprintf(test_str_1029_1029, "%.-20d", 10);
  ck_assert_str_eq(test_str_1029, test_str_1029_1029);
}
END_TEST

START_TEST(sprintf_test_1030) {
  char test_str_1030[50] = "";
  char test_str_1030_1030[50] = "";
  s21_sprintf(test_str_1030, "%.-20d", 123456);
  sprintf(test_str_1030_1030, "%.-20d", 123456);
  ck_assert_str_eq(test_str_1030, test_str_1030_1030);
}
END_TEST

START_TEST(sprintf_test_1031) {
  char test_str_1031[50] = "";
  char test_str_1031_1031[50] = "";
  s21_sprintf(test_str_1031, "%.-20d", -67890123);
  sprintf(test_str_1031_1031, "%.-20d", -67890123);
  ck_assert_str_eq(test_str_1031, test_str_1031_1031);
}
END_TEST

START_TEST(sprintf_test_1032) {
  char test_str_1032[50] = "";
  char test_str_1032_1032[50] = "";
  s21_sprintf(test_str_1032, "%.-20d", 4343);
  sprintf(test_str_1032_1032, "%.-20d", 4343);
  ck_assert_str_eq(test_str_1032, test_str_1032_1032);
}
END_TEST

START_TEST(sprintf_test_1033) {
  char test_str_1033[50] = "";
  char test_str_1033_1033[50] = "";
  s21_sprintf(test_str_1033, "%.-20d", -1);
  sprintf(test_str_1033_1033, "%.-20d", -1);
  ck_assert_str_eq(test_str_1033, test_str_1033_1033);
}
END_TEST

START_TEST(sprintf_test_1034) {
  char test_str_1034[50] = "";
  char test_str_1034_1034[50] = "";
  s21_sprintf(test_str_1034, "%.-20d", -10);
  sprintf(test_str_1034_1034, "%.-20d", -10);
  ck_assert_str_eq(test_str_1034, test_str_1034_1034);
}
END_TEST

START_TEST(sprintf_test_1035) {
  char test_str_1035[50] = "";
  char test_str_1035_1035[50] = "";
  s21_sprintf(test_str_1035, "%.-20d", 43);
  sprintf(test_str_1035_1035, "%.-20d", 43);
  ck_assert_str_eq(test_str_1035, test_str_1035_1035);
}
END_TEST

START_TEST(sprintf_test_1036) {
  char test_str_1036[50] = "";
  char test_str_1036_1036[50] = "";
  s21_sprintf(test_str_1036, "%.-20i", 0);
  sprintf(test_str_1036_1036, "%.-20i", 0);
  ck_assert_str_eq(test_str_1036, test_str_1036_1036);
}
END_TEST

START_TEST(sprintf_test_1037) {
  char test_str_1037[50] = "";
  char test_str_1037_1037[50] = "";
  s21_sprintf(test_str_1037, "%.-20i", 1);
  sprintf(test_str_1037_1037, "%.-20i", 1);
  ck_assert_str_eq(test_str_1037, test_str_1037_1037);
}
END_TEST

START_TEST(sprintf_test_1038) {
  char test_str_1038[50] = "";
  char test_str_1038_1038[50] = "";
  s21_sprintf(test_str_1038, "%.-20i", 10);
  sprintf(test_str_1038_1038, "%.-20i", 10);
  ck_assert_str_eq(test_str_1038, test_str_1038_1038);
}
END_TEST

START_TEST(sprintf_test_1039) {
  char test_str_1039[50] = "";
  char test_str_1039_1039[50] = "";
  s21_sprintf(test_str_1039, "%.-20i", 123456);
  sprintf(test_str_1039_1039, "%.-20i", 123456);
  ck_assert_str_eq(test_str_1039, test_str_1039_1039);
}
END_TEST

START_TEST(sprintf_test_1040) {
  char test_str_1040[50] = "";
  char test_str_1040_1040[50] = "";
  s21_sprintf(test_str_1040, "%.-20i", -67890123);
  sprintf(test_str_1040_1040, "%.-20i", -67890123);
  ck_assert_str_eq(test_str_1040, test_str_1040_1040);
}
END_TEST

START_TEST(sprintf_test_1041) {
  char test_str_1041[50] = "";
  char test_str_1041_1041[50] = "";
  s21_sprintf(test_str_1041, "%.-20i", 4343);
  sprintf(test_str_1041_1041, "%.-20i", 4343);
  ck_assert_str_eq(test_str_1041, test_str_1041_1041);
}
END_TEST

START_TEST(sprintf_test_1042) {
  char test_str_1042[50] = "";
  char test_str_1042_1042[50] = "";
  s21_sprintf(test_str_1042, "%.-20i", -1);
  sprintf(test_str_1042_1042, "%.-20i", -1);
  ck_assert_str_eq(test_str_1042, test_str_1042_1042);
}
END_TEST

START_TEST(sprintf_test_1043) {
  char test_str_1043[50] = "";
  char test_str_1043_1043[50] = "";
  s21_sprintf(test_str_1043, "%.-20i", -10);
  sprintf(test_str_1043_1043, "%.-20i", -10);
  ck_assert_str_eq(test_str_1043, test_str_1043_1043);
}
END_TEST

START_TEST(sprintf_test_1044) {
  char test_str_1044[50] = "";
  char test_str_1044_1044[50] = "";
  s21_sprintf(test_str_1044, "%.-20i", 43);
  sprintf(test_str_1044_1044, "%.-20i", 43);
  ck_assert_str_eq(test_str_1044, test_str_1044_1044);
}
END_TEST

START_TEST(sprintf_test_1045) {
  char test_str_1045[50] = "";
  char test_str_1045_1045[50] = "";
  s21_sprintf(test_str_1045, "%.-20o", 0);
  sprintf(test_str_1045_1045, "%.-20o", 0);
  ck_assert_str_eq(test_str_1045, test_str_1045_1045);
}
END_TEST

START_TEST(sprintf_test_1046) {
  char test_str_1046[50] = "";
  char test_str_1046_1046[50] = "";
  s21_sprintf(test_str_1046, "%.-20o", 1);
  sprintf(test_str_1046_1046, "%.-20o", 1);
  ck_assert_str_eq(test_str_1046, test_str_1046_1046);
}
END_TEST

START_TEST(sprintf_test_1047) {
  char test_str_1047[50] = "";
  char test_str_1047_1047[50] = "";
  s21_sprintf(test_str_1047, "%.-20o", 10);
  sprintf(test_str_1047_1047, "%.-20o", 10);
  ck_assert_str_eq(test_str_1047, test_str_1047_1047);
}
END_TEST

START_TEST(sprintf_test_1048) {
  char test_str_1048[50] = "";
  char test_str_1048_1048[50] = "";
  s21_sprintf(test_str_1048, "%.-20o", 123456);
  sprintf(test_str_1048_1048, "%.-20o", 123456);
  ck_assert_str_eq(test_str_1048, test_str_1048_1048);
}
END_TEST

START_TEST(sprintf_test_1049) {
  char test_str_1049[50] = "";
  char test_str_1049_1049[50] = "";
  s21_sprintf(test_str_1049, "%.-20o", -67890123);
  sprintf(test_str_1049_1049, "%.-20o", -67890123);
  ck_assert_str_eq(test_str_1049, test_str_1049_1049);
}
END_TEST

START_TEST(sprintf_test_1050) {
  char test_str_1050[50] = "";
  char test_str_1050_1050[50] = "";
  s21_sprintf(test_str_1050, "%.-20o", 4343);
  sprintf(test_str_1050_1050, "%.-20o", 4343);
  ck_assert_str_eq(test_str_1050, test_str_1050_1050);
}
END_TEST

START_TEST(sprintf_test_1051) {
  char test_str_1051[50] = "";
  char test_str_1051_1051[50] = "";
  s21_sprintf(test_str_1051, "%.-20o", -1);
  sprintf(test_str_1051_1051, "%.-20o", -1);
  ck_assert_str_eq(test_str_1051, test_str_1051_1051);
}
END_TEST

START_TEST(sprintf_test_1052) {
  char test_str_1052[50] = "";
  char test_str_1052_1052[50] = "";
  s21_sprintf(test_str_1052, "%.-20o", -10);
  sprintf(test_str_1052_1052, "%.-20o", -10);
  ck_assert_str_eq(test_str_1052, test_str_1052_1052);
}
END_TEST

START_TEST(sprintf_test_1053) {
  char test_str_1053[50] = "";
  char test_str_1053_1053[50] = "";
  s21_sprintf(test_str_1053, "%.-20o", 43);
  sprintf(test_str_1053_1053, "%.-20o", 43);
  ck_assert_str_eq(test_str_1053, test_str_1053_1053);
}
END_TEST

START_TEST(sprintf_test_1054) {
  char test_str_1054[50] = "";
  char test_str_1054_1054[50] = "";
  s21_sprintf(test_str_1054, "%.-20u", 0);
  sprintf(test_str_1054_1054, "%.-20u", 0);
  ck_assert_str_eq(test_str_1054, test_str_1054_1054);
}
END_TEST

START_TEST(sprintf_test_1055) {
  char test_str_1055[50] = "";
  char test_str_1055_1055[50] = "";
  s21_sprintf(test_str_1055, "%.-20u", 1);
  sprintf(test_str_1055_1055, "%.-20u", 1);
  ck_assert_str_eq(test_str_1055, test_str_1055_1055);
}
END_TEST

START_TEST(sprintf_test_1056) {
  char test_str_1056[50] = "";
  char test_str_1056_1056[50] = "";
  s21_sprintf(test_str_1056, "%.-20u", 10);
  sprintf(test_str_1056_1056, "%.-20u", 10);
  ck_assert_str_eq(test_str_1056, test_str_1056_1056);
}
END_TEST

START_TEST(sprintf_test_1057) {
  char test_str_1057[50] = "";
  char test_str_1057_1057[50] = "";
  s21_sprintf(test_str_1057, "%.-20u", 123456);
  sprintf(test_str_1057_1057, "%.-20u", 123456);
  ck_assert_str_eq(test_str_1057, test_str_1057_1057);
}
END_TEST

START_TEST(sprintf_test_1058) {
  char test_str_1058[50] = "";
  char test_str_1058_1058[50] = "";
  s21_sprintf(test_str_1058, "%.-20u", -67890123);
  sprintf(test_str_1058_1058, "%.-20u", -67890123);
  ck_assert_str_eq(test_str_1058, test_str_1058_1058);
}
END_TEST

START_TEST(sprintf_test_1059) {
  char test_str_1059[50] = "";
  char test_str_1059_1059[50] = "";
  s21_sprintf(test_str_1059, "%.-20u", 4343);
  sprintf(test_str_1059_1059, "%.-20u", 4343);
  ck_assert_str_eq(test_str_1059, test_str_1059_1059);
}
END_TEST

START_TEST(sprintf_test_1060) {
  char test_str_1060[50] = "";
  char test_str_1060_1060[50] = "";
  s21_sprintf(test_str_1060, "%.-20u", -1);
  sprintf(test_str_1060_1060, "%.-20u", -1);
  ck_assert_str_eq(test_str_1060, test_str_1060_1060);
}
END_TEST

START_TEST(sprintf_test_1061) {
  char test_str_1061[50] = "";
  char test_str_1061_1061[50] = "";
  s21_sprintf(test_str_1061, "%.-20u", -10);
  sprintf(test_str_1061_1061, "%.-20u", -10);
  ck_assert_str_eq(test_str_1061, test_str_1061_1061);
}
END_TEST

START_TEST(sprintf_test_1062) {
  char test_str_1062[50] = "";
  char test_str_1062_1062[50] = "";
  s21_sprintf(test_str_1062, "%.-20u", 43);
  sprintf(test_str_1062_1062, "%.-20u", 43);
  ck_assert_str_eq(test_str_1062, test_str_1062_1062);
}
END_TEST

START_TEST(sprintf_test_1063) {
  char test_str_1063[50] = "";
  char test_str_1063_1063[50] = "";
  s21_sprintf(test_str_1063, "%.-20x", 0);
  sprintf(test_str_1063_1063, "%.-20x", 0);
  ck_assert_str_eq(test_str_1063, test_str_1063_1063);
}
END_TEST

START_TEST(sprintf_test_1064) {
  char test_str_1064[50] = "";
  char test_str_1064_1064[50] = "";
  s21_sprintf(test_str_1064, "%.-20x", 1);
  sprintf(test_str_1064_1064, "%.-20x", 1);
  ck_assert_str_eq(test_str_1064, test_str_1064_1064);
}
END_TEST

START_TEST(sprintf_test_1065) {
  char test_str_1065[50] = "";
  char test_str_1065_1065[50] = "";
  s21_sprintf(test_str_1065, "%.-20x", 10);
  sprintf(test_str_1065_1065, "%.-20x", 10);
  ck_assert_str_eq(test_str_1065, test_str_1065_1065);
}
END_TEST

START_TEST(sprintf_test_1066) {
  char test_str_1066[50] = "";
  char test_str_1066_1066[50] = "";
  s21_sprintf(test_str_1066, "%.-20x", 123456);
  sprintf(test_str_1066_1066, "%.-20x", 123456);
  ck_assert_str_eq(test_str_1066, test_str_1066_1066);
}
END_TEST

START_TEST(sprintf_test_1067) {
  char test_str_1067[50] = "";
  char test_str_1067_1067[50] = "";
  s21_sprintf(test_str_1067, "%.-20x", -67890123);
  sprintf(test_str_1067_1067, "%.-20x", -67890123);
  ck_assert_str_eq(test_str_1067, test_str_1067_1067);
}
END_TEST

START_TEST(sprintf_test_1068) {
  char test_str_1068[50] = "";
  char test_str_1068_1068[50] = "";
  s21_sprintf(test_str_1068, "%.-20x", 4343);
  sprintf(test_str_1068_1068, "%.-20x", 4343);
  ck_assert_str_eq(test_str_1068, test_str_1068_1068);
}
END_TEST

START_TEST(sprintf_test_1069) {
  char test_str_1069[50] = "";
  char test_str_1069_1069[50] = "";
  s21_sprintf(test_str_1069, "%.-20x", -1);
  sprintf(test_str_1069_1069, "%.-20x", -1);
  ck_assert_str_eq(test_str_1069, test_str_1069_1069);
}
END_TEST

START_TEST(sprintf_test_1070) {
  char test_str_1070[50] = "";
  char test_str_1070_1070[50] = "";
  s21_sprintf(test_str_1070, "%.-20x", -10);
  sprintf(test_str_1070_1070, "%.-20x", -10);
  ck_assert_str_eq(test_str_1070, test_str_1070_1070);
}
END_TEST

START_TEST(sprintf_test_1071) {
  char test_str_1071[50] = "";
  char test_str_1071_1071[50] = "";
  s21_sprintf(test_str_1071, "%.-20x", 43);
  sprintf(test_str_1071_1071, "%.-20x", 43);
  ck_assert_str_eq(test_str_1071, test_str_1071_1071);
}
END_TEST

START_TEST(sprintf_test_1072) {
  char test_str_1072[50] = "";
  char test_str_1072_1072[50] = "";
  s21_sprintf(test_str_1072, "%.-20X", 0);
  sprintf(test_str_1072_1072, "%.-20X", 0);
  ck_assert_str_eq(test_str_1072, test_str_1072_1072);
}
END_TEST

START_TEST(sprintf_test_1073) {
  char test_str_1073[50] = "";
  char test_str_1073_1073[50] = "";
  s21_sprintf(test_str_1073, "%.-20X", 1);
  sprintf(test_str_1073_1073, "%.-20X", 1);
  ck_assert_str_eq(test_str_1073, test_str_1073_1073);
}
END_TEST

START_TEST(sprintf_test_1074) {
  char test_str_1074[50] = "";
  char test_str_1074_1074[50] = "";
  s21_sprintf(test_str_1074, "%.-20X", 10);
  sprintf(test_str_1074_1074, "%.-20X", 10);
  ck_assert_str_eq(test_str_1074, test_str_1074_1074);
}
END_TEST

START_TEST(sprintf_test_1075) {
  char test_str_1075[50] = "";
  char test_str_1075_1075[50] = "";
  s21_sprintf(test_str_1075, "%.-20X", 123456);
  sprintf(test_str_1075_1075, "%.-20X", 123456);
  ck_assert_str_eq(test_str_1075, test_str_1075_1075);
}
END_TEST

START_TEST(sprintf_test_1076) {
  char test_str_1076[50] = "";
  char test_str_1076_1076[50] = "";
  s21_sprintf(test_str_1076, "%.-20X", -67890123);
  sprintf(test_str_1076_1076, "%.-20X", -67890123);
  ck_assert_str_eq(test_str_1076, test_str_1076_1076);
}
END_TEST

START_TEST(sprintf_test_1077) {
  char test_str_1077[50] = "";
  char test_str_1077_1077[50] = "";
  s21_sprintf(test_str_1077, "%.-20X", 4343);
  sprintf(test_str_1077_1077, "%.-20X", 4343);
  ck_assert_str_eq(test_str_1077, test_str_1077_1077);
}
END_TEST

START_TEST(sprintf_test_1078) {
  char test_str_1078[50] = "";
  char test_str_1078_1078[50] = "";
  s21_sprintf(test_str_1078, "%.-20X", -1);
  sprintf(test_str_1078_1078, "%.-20X", -1);
  ck_assert_str_eq(test_str_1078, test_str_1078_1078);
}
END_TEST

START_TEST(sprintf_test_1079) {
  char test_str_1079[50] = "";
  char test_str_1079_1079[50] = "";
  s21_sprintf(test_str_1079, "%.-20X", -10);
  sprintf(test_str_1079_1079, "%.-20X", -10);
  ck_assert_str_eq(test_str_1079, test_str_1079_1079);
}
END_TEST

START_TEST(sprintf_test_1080) {
  char test_str_1080[50] = "";
  char test_str_1080_1080[50] = "";
  s21_sprintf(test_str_1080, "%.-20X", 43);
  sprintf(test_str_1080_1080, "%.-20X", 43);
  ck_assert_str_eq(test_str_1080, test_str_1080_1080);
}
END_TEST

START_TEST(sprintf_test_1081) {
  char test_str_1081[50] = "";
  char test_str_1081_1081[50] = "";
  s21_sprintf(test_str_1081, "%hd", 0);
  sprintf(test_str_1081_1081, "%hd", 0);
  ck_assert_str_eq(test_str_1081, test_str_1081_1081);
}
END_TEST

START_TEST(sprintf_test_1082) {
  char test_str_1082[50] = "";
  char test_str_1082_1082[50] = "";
  s21_sprintf(test_str_1082, "%hd", 1);
  sprintf(test_str_1082_1082, "%hd", 1);
  ck_assert_str_eq(test_str_1082, test_str_1082_1082);
}
END_TEST

START_TEST(sprintf_test_1083) {
  char test_str_1083[50] = "";
  char test_str_1083_1083[50] = "";
  s21_sprintf(test_str_1083, "%hd", 10);
  sprintf(test_str_1083_1083, "%hd", 10);
  ck_assert_str_eq(test_str_1083, test_str_1083_1083);
}
END_TEST

START_TEST(sprintf_test_1084) {
  char test_str_1084[50] = "";
  char test_str_1084_1084[50] = "";
  s21_sprintf(test_str_1084, "%hd", 123456);
  sprintf(test_str_1084_1084, "%hd", 123456);
  ck_assert_str_eq(test_str_1084, test_str_1084_1084);
}
END_TEST

START_TEST(sprintf_test_1085) {
  char test_str_1085[50] = "";
  char test_str_1085_1085[50] = "";
  s21_sprintf(test_str_1085, "%hd", -678901);
  sprintf(test_str_1085_1085, "%hd", -678901);
  ck_assert_str_eq(test_str_1085, test_str_1085_1085);
}
END_TEST

START_TEST(sprintf_test_1086) {
  char test_str_1086[50] = "";
  char test_str_1086_1086[50] = "";
  s21_sprintf(test_str_1086, "%hd", 4343);
  sprintf(test_str_1086_1086, "%hd", 4343);
  ck_assert_str_eq(test_str_1086, test_str_1086_1086);
}
END_TEST

START_TEST(sprintf_test_1087) {
  char test_str_1087[50] = "";
  char test_str_1087_1087[50] = "";
  s21_sprintf(test_str_1087, "%hd", -1);
  sprintf(test_str_1087_1087, "%hd", -1);
  ck_assert_str_eq(test_str_1087, test_str_1087_1087);
}
END_TEST

START_TEST(sprintf_test_1088) {
  char test_str_1088[50] = "";
  char test_str_1088_1088[50] = "";
  s21_sprintf(test_str_1088, "%hd", -10);
  sprintf(test_str_1088_1088, "%hd", -10);
  ck_assert_str_eq(test_str_1088, test_str_1088_1088);
}
END_TEST

START_TEST(sprintf_test_1089) {
  char test_str_1089[50] = "";
  char test_str_1089_1089[50] = "";
  s21_sprintf(test_str_1089, "%hd", 43);
  sprintf(test_str_1089_1089, "%hd", 43);
  ck_assert_str_eq(test_str_1089, test_str_1089_1089);
}
END_TEST

START_TEST(sprintf_test_1090) {
  char test_str_1090[50] = "";
  char test_str_1090_1090[50] = "";
  s21_sprintf(test_str_1090, "%hi", 0);
  sprintf(test_str_1090_1090, "%hi", 0);
  ck_assert_str_eq(test_str_1090, test_str_1090_1090);
}
END_TEST

START_TEST(sprintf_test_1091) {
  char test_str_1091[50] = "";
  char test_str_1091_1091[50] = "";
  s21_sprintf(test_str_1091, "%hi", 1);
  sprintf(test_str_1091_1091, "%hi", 1);
  ck_assert_str_eq(test_str_1091, test_str_1091_1091);
}
END_TEST

START_TEST(sprintf_test_1092) {
  char test_str_1092[50] = "";
  char test_str_1092_1092[50] = "";
  s21_sprintf(test_str_1092, "%hi", 10);
  sprintf(test_str_1092_1092, "%hi", 10);
  ck_assert_str_eq(test_str_1092, test_str_1092_1092);
}
END_TEST

START_TEST(sprintf_test_1093) {
  char test_str_1093[50] = "";
  char test_str_1093_1093[50] = "";
  s21_sprintf(test_str_1093, "%hi", 123456);
  sprintf(test_str_1093_1093, "%hi", 123456);
  ck_assert_str_eq(test_str_1093, test_str_1093_1093);
}
END_TEST

START_TEST(sprintf_test_1094) {
  char test_str_1094[50] = "";
  char test_str_1094_1094[50] = "";
  s21_sprintf(test_str_1094, "%hi", -678901);
  sprintf(test_str_1094_1094, "%hi", -678901);
  ck_assert_str_eq(test_str_1094, test_str_1094_1094);
}
END_TEST

START_TEST(sprintf_test_1095) {
  char test_str_1095[50] = "";
  char test_str_1095_1095[50] = "";
  s21_sprintf(test_str_1095, "%hi", 4343);
  sprintf(test_str_1095_1095, "%hi", 4343);
  ck_assert_str_eq(test_str_1095, test_str_1095_1095);
}
END_TEST

START_TEST(sprintf_test_1096) {
  char test_str_1096[50] = "";
  char test_str_1096_1096[50] = "";
  s21_sprintf(test_str_1096, "%hi", -1);
  sprintf(test_str_1096_1096, "%hi", -1);
  ck_assert_str_eq(test_str_1096, test_str_1096_1096);
}
END_TEST

START_TEST(sprintf_test_1097) {
  char test_str_1097[50] = "";
  char test_str_1097_1097[50] = "";
  s21_sprintf(test_str_1097, "%hi", -10);
  sprintf(test_str_1097_1097, "%hi", -10);
  ck_assert_str_eq(test_str_1097, test_str_1097_1097);
}
END_TEST

START_TEST(sprintf_test_1098) {
  char test_str_1098[50] = "";
  char test_str_1098_1098[50] = "";
  s21_sprintf(test_str_1098, "%hi", 43);
  sprintf(test_str_1098_1098, "%hi", 43);
  ck_assert_str_eq(test_str_1098, test_str_1098_1098);
}
END_TEST

START_TEST(sprintf_test_1099) {
  char test_str_1099[50] = "";
  char test_str_1099_1099[50] = "";
  s21_sprintf(test_str_1099, "%ho", 0);
  sprintf(test_str_1099_1099, "%ho", 0);
  ck_assert_str_eq(test_str_1099, test_str_1099_1099);
}
END_TEST

START_TEST(sprintf_test_1100) {
  char test_str_1100[50] = "";
  char test_str_1100_1100[50] = "";
  s21_sprintf(test_str_1100, "%ho", 1);
  sprintf(test_str_1100_1100, "%ho", 1);
  ck_assert_str_eq(test_str_1100, test_str_1100_1100);
}
END_TEST

START_TEST(sprintf_test_1101) {
  char test_str_1101[50] = "";
  char test_str_1101_1101[50] = "";
  s21_sprintf(test_str_1101, "%ho", 10);
  sprintf(test_str_1101_1101, "%ho", 10);
  ck_assert_str_eq(test_str_1101, test_str_1101_1101);
}
END_TEST

START_TEST(sprintf_test_1102) {
  char test_str_1102[50] = "";
  char test_str_1102_1102[50] = "";
  s21_sprintf(test_str_1102, "%ho", 123456);
  sprintf(test_str_1102_1102, "%ho", 123456);
  ck_assert_str_eq(test_str_1102, test_str_1102_1102);
}
END_TEST

START_TEST(sprintf_test_1103) {
  char test_str_1103[50] = "";
  char test_str_1103_1103[50] = "";
  s21_sprintf(test_str_1103, "%ho", -678901);
  sprintf(test_str_1103_1103, "%ho", -678901);
  ck_assert_str_eq(test_str_1103, test_str_1103_1103);
}
END_TEST

START_TEST(sprintf_test_1104) {
  char test_str_1104[50] = "";
  char test_str_1104_1104[50] = "";
  s21_sprintf(test_str_1104, "%ho", 4343);
  sprintf(test_str_1104_1104, "%ho", 4343);
  ck_assert_str_eq(test_str_1104, test_str_1104_1104);
}
END_TEST

START_TEST(sprintf_test_1105) {
  char test_str_1105[50] = "";
  char test_str_1105_1105[50] = "";
  s21_sprintf(test_str_1105, "%ho", -1);
  sprintf(test_str_1105_1105, "%ho", -1);
  ck_assert_str_eq(test_str_1105, test_str_1105_1105);
}
END_TEST

START_TEST(sprintf_test_1106) {
  char test_str_1106[50] = "";
  char test_str_1106_1106[50] = "";
  s21_sprintf(test_str_1106, "%ho", -10);
  sprintf(test_str_1106_1106, "%ho", -10);
  ck_assert_str_eq(test_str_1106, test_str_1106_1106);
}
END_TEST

START_TEST(sprintf_test_1107) {
  char test_str_1107[50] = "";
  char test_str_1107_1107[50] = "";
  s21_sprintf(test_str_1107, "%ho", 43);
  sprintf(test_str_1107_1107, "%ho", 43);
  ck_assert_str_eq(test_str_1107, test_str_1107_1107);
}
END_TEST

START_TEST(sprintf_test_1108) {
  char test_str_1108[50] = "";
  char test_str_1108_1108[50] = "";
  s21_sprintf(test_str_1108, "%hu", 0);
  sprintf(test_str_1108_1108, "%hu", 0);
  ck_assert_str_eq(test_str_1108, test_str_1108_1108);
}
END_TEST

START_TEST(sprintf_test_1109) {
  char test_str_1109[50] = "";
  char test_str_1109_1109[50] = "";
  s21_sprintf(test_str_1109, "%hu", 1);
  sprintf(test_str_1109_1109, "%hu", 1);
  ck_assert_str_eq(test_str_1109, test_str_1109_1109);
}
END_TEST

START_TEST(sprintf_test_1110) {
  char test_str_1110[50] = "";
  char test_str_1110_1110[50] = "";
  s21_sprintf(test_str_1110, "%hu", 10);
  sprintf(test_str_1110_1110, "%hu", 10);
  ck_assert_str_eq(test_str_1110, test_str_1110_1110);
}
END_TEST

START_TEST(sprintf_test_1111) {
  char test_str_1111[50] = "";
  char test_str_1111_1111[50] = "";
  s21_sprintf(test_str_1111, "%hu", 123456);
  sprintf(test_str_1111_1111, "%hu", 123456);
  ck_assert_str_eq(test_str_1111, test_str_1111_1111);
}
END_TEST

START_TEST(sprintf_test_1112) {
  char test_str_1112[50] = "";
  char test_str_1112_1112[50] = "";
  s21_sprintf(test_str_1112, "%hu", -678901);
  sprintf(test_str_1112_1112, "%hu", -678901);
  ck_assert_str_eq(test_str_1112, test_str_1112_1112);
}
END_TEST

START_TEST(sprintf_test_1113) {
  char test_str_1113[50] = "";
  char test_str_1113_1113[50] = "";
  s21_sprintf(test_str_1113, "%hu", 4343);
  sprintf(test_str_1113_1113, "%hu", 4343);
  ck_assert_str_eq(test_str_1113, test_str_1113_1113);
}
END_TEST

START_TEST(sprintf_test_1114) {
  char test_str_1114[50] = "";
  char test_str_1114_1114[50] = "";
  s21_sprintf(test_str_1114, "%hu", -1);
  sprintf(test_str_1114_1114, "%hu", -1);
  ck_assert_str_eq(test_str_1114, test_str_1114_1114);
}
END_TEST

START_TEST(sprintf_test_1115) {
  char test_str_1115[50] = "";
  char test_str_1115_1115[50] = "";
  s21_sprintf(test_str_1115, "%hu", -10);
  sprintf(test_str_1115_1115, "%hu", -10);
  ck_assert_str_eq(test_str_1115, test_str_1115_1115);
}
END_TEST

START_TEST(sprintf_test_1116) {
  char test_str_1116[50] = "";
  char test_str_1116_1116[50] = "";
  s21_sprintf(test_str_1116, "%hu", 43);
  sprintf(test_str_1116_1116, "%hu", 43);
  ck_assert_str_eq(test_str_1116, test_str_1116_1116);
}
END_TEST

START_TEST(sprintf_test_1117) {
  char test_str_1117[50] = "";
  char test_str_1117_1117[50] = "";
  s21_sprintf(test_str_1117, "%hx", 0);
  sprintf(test_str_1117_1117, "%hx", 0);
  ck_assert_str_eq(test_str_1117, test_str_1117_1117);
}
END_TEST

START_TEST(sprintf_test_1118) {
  char test_str_1118[50] = "";
  char test_str_1118_1118[50] = "";
  s21_sprintf(test_str_1118, "%hx", 1);
  sprintf(test_str_1118_1118, "%hx", 1);
  ck_assert_str_eq(test_str_1118, test_str_1118_1118);
}
END_TEST

START_TEST(sprintf_test_1119) {
  char test_str_1119[50] = "";
  char test_str_1119_1119[50] = "";
  s21_sprintf(test_str_1119, "%hx", 10);
  sprintf(test_str_1119_1119, "%hx", 10);
  ck_assert_str_eq(test_str_1119, test_str_1119_1119);
}
END_TEST

START_TEST(sprintf_test_1120) {
  char test_str_1120[50] = "";
  char test_str_1120_1120[50] = "";
  s21_sprintf(test_str_1120, "%hx", 123456);
  sprintf(test_str_1120_1120, "%hx", 123456);
  ck_assert_str_eq(test_str_1120, test_str_1120_1120);
}
END_TEST

START_TEST(sprintf_test_1121) {
  char test_str_1121[50] = "";
  char test_str_1121_1121[50] = "";
  s21_sprintf(test_str_1121, "%hx", -678901);
  sprintf(test_str_1121_1121, "%hx", -678901);
  ck_assert_str_eq(test_str_1121, test_str_1121_1121);
}
END_TEST

START_TEST(sprintf_test_1122) {
  char test_str_1122[50] = "";
  char test_str_1122_1122[50] = "";
  s21_sprintf(test_str_1122, "%hx", 4343);
  sprintf(test_str_1122_1122, "%hx", 4343);
  ck_assert_str_eq(test_str_1122, test_str_1122_1122);
}
END_TEST

START_TEST(sprintf_test_1123) {
  char test_str_1123[50] = "";
  char test_str_1123_1123[50] = "";
  s21_sprintf(test_str_1123, "%hx", -1);
  sprintf(test_str_1123_1123, "%hx", -1);
  ck_assert_str_eq(test_str_1123, test_str_1123_1123);
}
END_TEST

START_TEST(sprintf_test_1124) {
  char test_str_1124[50] = "";
  char test_str_1124_1124[50] = "";
  s21_sprintf(test_str_1124, "%hx", -10);
  sprintf(test_str_1124_1124, "%hx", -10);
  ck_assert_str_eq(test_str_1124, test_str_1124_1124);
}
END_TEST

START_TEST(sprintf_test_1125) {
  char test_str_1125[50] = "";
  char test_str_1125_1125[50] = "";
  s21_sprintf(test_str_1125, "%hx", 43);
  sprintf(test_str_1125_1125, "%hx", 43);
  ck_assert_str_eq(test_str_1125, test_str_1125_1125);
}
END_TEST

START_TEST(sprintf_test_1126) {
  char test_str_1126[50] = "";
  char test_str_1126_1126[50] = "";
  s21_sprintf(test_str_1126, "%hX", 0);
  sprintf(test_str_1126_1126, "%hX", 0);
  ck_assert_str_eq(test_str_1126, test_str_1126_1126);
}
END_TEST

START_TEST(sprintf_test_1127) {
  char test_str_1127[50] = "";
  char test_str_1127_1127[50] = "";
  s21_sprintf(test_str_1127, "%hX", 1);
  sprintf(test_str_1127_1127, "%hX", 1);
  ck_assert_str_eq(test_str_1127, test_str_1127_1127);
}
END_TEST

START_TEST(sprintf_test_1128) {
  char test_str_1128[50] = "";
  char test_str_1128_1128[50] = "";
  s21_sprintf(test_str_1128, "%hX", 10);
  sprintf(test_str_1128_1128, "%hX", 10);
  ck_assert_str_eq(test_str_1128, test_str_1128_1128);
}
END_TEST

START_TEST(sprintf_test_1129) {
  char test_str_1129[50] = "";
  char test_str_1129_1129[50] = "";
  s21_sprintf(test_str_1129, "%hX", 123456);
  sprintf(test_str_1129_1129, "%hX", 123456);
  ck_assert_str_eq(test_str_1129, test_str_1129_1129);
}
END_TEST

START_TEST(sprintf_test_1130) {
  char test_str_1130[50] = "";
  char test_str_1130_1130[50] = "";
  s21_sprintf(test_str_1130, "%hX", -678901);
  sprintf(test_str_1130_1130, "%hX", -678901);
  ck_assert_str_eq(test_str_1130, test_str_1130_1130);
}
END_TEST

START_TEST(sprintf_test_1131) {
  char test_str_1131[50] = "";
  char test_str_1131_1131[50] = "";
  s21_sprintf(test_str_1131, "%hX", 4343);
  sprintf(test_str_1131_1131, "%hX", 4343);
  ck_assert_str_eq(test_str_1131, test_str_1131_1131);
}
END_TEST

START_TEST(sprintf_test_1132) {
  char test_str_1132[50] = "";
  char test_str_1132_1132[50] = "";
  s21_sprintf(test_str_1132, "%hX", -1);
  sprintf(test_str_1132_1132, "%hX", -1);
  ck_assert_str_eq(test_str_1132, test_str_1132_1132);
}
END_TEST

START_TEST(sprintf_test_1133) {
  char test_str_1133[50] = "";
  char test_str_1133_1133[50] = "";
  s21_sprintf(test_str_1133, "%hX", -10);
  sprintf(test_str_1133_1133, "%hX", -10);
  ck_assert_str_eq(test_str_1133, test_str_1133_1133);
}
END_TEST

START_TEST(sprintf_test_1134) {
  char test_str_1134[50] = "";
  char test_str_1134_1134[50] = "";
  s21_sprintf(test_str_1134, "%hX", 43);
  sprintf(test_str_1134_1134, "%hX", 43);
  ck_assert_str_eq(test_str_1134, test_str_1134_1134);
}
END_TEST

START_TEST(sprintf_test_1135) {
  char test_str_1135[50] = "";
  char test_str_1135_1135[50] = "";
  s21_sprintf(test_str_1135, "%ld", 0);
  sprintf(test_str_1135_1135, "%ld", 0);
  ck_assert_str_eq(test_str_1135, test_str_1135_1135);
}
END_TEST

START_TEST(sprintf_test_1136) {
  char test_str_1136[50] = "";
  char test_str_1136_1136[50] = "";
  s21_sprintf(test_str_1136, "%ld", 1);
  sprintf(test_str_1136_1136, "%ld", 1);
  ck_assert_str_eq(test_str_1136, test_str_1136_1136);
}
END_TEST

START_TEST(sprintf_test_1137) {
  char test_str_1137[50] = "";
  char test_str_1137_1137[50] = "";
  s21_sprintf(test_str_1137, "%ld", 10);
  sprintf(test_str_1137_1137, "%ld", 10);
  ck_assert_str_eq(test_str_1137, test_str_1137_1137);
}
END_TEST

START_TEST(sprintf_test_1138) {
  char test_str_1138[50] = "";
  char test_str_1138_1138[50] = "";
  s21_sprintf(test_str_1138, "%ld", 123456);
  sprintf(test_str_1138_1138, "%ld", 123456);
  ck_assert_str_eq(test_str_1138, test_str_1138_1138);
}
END_TEST

START_TEST(sprintf_test_1139) {
  char test_str_1139[50] = "";
  char test_str_1139_1139[50] = "";
  s21_sprintf(test_str_1139, "%ld", -678901);
  sprintf(test_str_1139_1139, "%ld", -678901);
  ck_assert_str_eq(test_str_1139, test_str_1139_1139);
}
END_TEST

START_TEST(sprintf_test_1140) {
  char test_str_1140[50] = "";
  char test_str_1140_1140[50] = "";
  s21_sprintf(test_str_1140, "%ld", 4343);
  sprintf(test_str_1140_1140, "%ld", 4343);
  ck_assert_str_eq(test_str_1140, test_str_1140_1140);
}
END_TEST

START_TEST(sprintf_test_1141) {
  char test_str_1141[50] = "";
  char test_str_1141_1141[50] = "";
  s21_sprintf(test_str_1141, "%ld", -1);
  sprintf(test_str_1141_1141, "%ld", -1);
  ck_assert_str_eq(test_str_1141, test_str_1141_1141);
}
END_TEST

START_TEST(sprintf_test_1142) {
  char test_str_1142[50] = "";
  char test_str_1142_1142[50] = "";
  s21_sprintf(test_str_1142, "%ld", -10);
  sprintf(test_str_1142_1142, "%ld", -10);
  ck_assert_str_eq(test_str_1142, test_str_1142_1142);
}
END_TEST

START_TEST(sprintf_test_1143) {
  char test_str_1143[50] = "";
  char test_str_1143_1143[50] = "";
  s21_sprintf(test_str_1143, "%ld", 43);
  sprintf(test_str_1143_1143, "%ld", 43);
  ck_assert_str_eq(test_str_1143, test_str_1143_1143);
}
END_TEST

START_TEST(sprintf_test_1144) {
  char test_str_1144[50] = "";
  char test_str_1144_1144[50] = "";
  s21_sprintf(test_str_1144, "%li", 0);
  sprintf(test_str_1144_1144, "%li", 0);
  ck_assert_str_eq(test_str_1144, test_str_1144_1144);
}
END_TEST

START_TEST(sprintf_test_1145) {
  char test_str_1145[50] = "";
  char test_str_1145_1145[50] = "";
  s21_sprintf(test_str_1145, "%li", 1);
  sprintf(test_str_1145_1145, "%li", 1);
  ck_assert_str_eq(test_str_1145, test_str_1145_1145);
}
END_TEST

START_TEST(sprintf_test_1146) {
  char test_str_1146[50] = "";
  char test_str_1146_1146[50] = "";
  s21_sprintf(test_str_1146, "%li", 10);
  sprintf(test_str_1146_1146, "%li", 10);
  ck_assert_str_eq(test_str_1146, test_str_1146_1146);
}
END_TEST

START_TEST(sprintf_test_1147) {
  char test_str_1147[50] = "";
  char test_str_1147_1147[50] = "";
  s21_sprintf(test_str_1147, "%li", 123456);
  sprintf(test_str_1147_1147, "%li", 123456);
  ck_assert_str_eq(test_str_1147, test_str_1147_1147);
}
END_TEST

START_TEST(sprintf_test_1148) {
  char test_str_1148[50] = "";
  char test_str_1148_1148[50] = "";
  s21_sprintf(test_str_1148, "%li", -678901);
  sprintf(test_str_1148_1148, "%li", -678901);
  ck_assert_str_eq(test_str_1148, test_str_1148_1148);
}
END_TEST

START_TEST(sprintf_test_1149) {
  char test_str_1149[50] = "";
  char test_str_1149_1149[50] = "";
  s21_sprintf(test_str_1149, "%li", 4343);
  sprintf(test_str_1149_1149, "%li", 4343);
  ck_assert_str_eq(test_str_1149, test_str_1149_1149);
}
END_TEST

START_TEST(sprintf_test_1150) {
  char test_str_1150[50] = "";
  char test_str_1150_1150[50] = "";
  s21_sprintf(test_str_1150, "%li", -1);
  sprintf(test_str_1150_1150, "%li", -1);
  ck_assert_str_eq(test_str_1150, test_str_1150_1150);
}
END_TEST

START_TEST(sprintf_test_1151) {
  char test_str_1151[50] = "";
  char test_str_1151_1151[50] = "";
  s21_sprintf(test_str_1151, "%li", -10);
  sprintf(test_str_1151_1151, "%li", -10);
  ck_assert_str_eq(test_str_1151, test_str_1151_1151);
}
END_TEST

START_TEST(sprintf_test_1152) {
  char test_str_1152[50] = "";
  char test_str_1152_1152[50] = "";
  s21_sprintf(test_str_1152, "%li", 43);
  sprintf(test_str_1152_1152, "%li", 43);
  ck_assert_str_eq(test_str_1152, test_str_1152_1152);
}
END_TEST

START_TEST(sprintf_test_1153) {
  char test_str_1153[50] = "";
  char test_str_1153_1153[50] = "";
  s21_sprintf(test_str_1153, "%lo", 0);
  sprintf(test_str_1153_1153, "%lo", 0);
  ck_assert_str_eq(test_str_1153, test_str_1153_1153);
}
END_TEST

START_TEST(sprintf_test_1154) {
  char test_str_1154[50] = "";
  char test_str_1154_1154[50] = "";
  s21_sprintf(test_str_1154, "%lo", 1);
  sprintf(test_str_1154_1154, "%lo", 1);
  ck_assert_str_eq(test_str_1154, test_str_1154_1154);
}
END_TEST

START_TEST(sprintf_test_1155) {
  char test_str_1155[50] = "";
  char test_str_1155_1155[50] = "";
  s21_sprintf(test_str_1155, "%lo", 10);
  sprintf(test_str_1155_1155, "%lo", 10);
  ck_assert_str_eq(test_str_1155, test_str_1155_1155);
}
END_TEST

START_TEST(sprintf_test_1156) {
  char test_str_1156[50] = "";
  char test_str_1156_1156[50] = "";
  s21_sprintf(test_str_1156, "%lo", 123456);
  sprintf(test_str_1156_1156, "%lo", 123456);
  ck_assert_str_eq(test_str_1156, test_str_1156_1156);
}
END_TEST

START_TEST(sprintf_test_1157) {
  char test_str_1157[50] = "";
  char test_str_1157_1157[50] = "";
  s21_sprintf(test_str_1157, "%lo", -678901);
  sprintf(test_str_1157_1157, "%lo", -678901);
  ck_assert_str_eq(test_str_1157, test_str_1157_1157);
}
END_TEST

START_TEST(sprintf_test_1158) {
  char test_str_1158[50] = "";
  char test_str_1158_1158[50] = "";
  s21_sprintf(test_str_1158, "%lo", 4343);
  sprintf(test_str_1158_1158, "%lo", 4343);
  ck_assert_str_eq(test_str_1158, test_str_1158_1158);
}
END_TEST

START_TEST(sprintf_test_1159) {
  char test_str_1159[50] = "";
  char test_str_1159_1159[50] = "";
  s21_sprintf(test_str_1159, "%lo", -1);
  sprintf(test_str_1159_1159, "%lo", -1);
  ck_assert_str_eq(test_str_1159, test_str_1159_1159);
}
END_TEST

START_TEST(sprintf_test_1160) {
  char test_str_1160[50] = "";
  char test_str_1160_1160[50] = "";
  s21_sprintf(test_str_1160, "%lo", -10);
  sprintf(test_str_1160_1160, "%lo", -10);
  ck_assert_str_eq(test_str_1160, test_str_1160_1160);
}
END_TEST

START_TEST(sprintf_test_1161) {
  char test_str_1161[50] = "";
  char test_str_1161_1161[50] = "";
  s21_sprintf(test_str_1161, "%lo", 43);
  sprintf(test_str_1161_1161, "%lo", 43);
  ck_assert_str_eq(test_str_1161, test_str_1161_1161);
}
END_TEST

START_TEST(sprintf_test_1162) {
  char test_str_1162[50] = "";
  char test_str_1162_1162[50] = "";
  s21_sprintf(test_str_1162, "%lu", 0);
  sprintf(test_str_1162_1162, "%lu", 0);
  ck_assert_str_eq(test_str_1162, test_str_1162_1162);
}
END_TEST

START_TEST(sprintf_test_1163) {
  char test_str_1163[50] = "";
  char test_str_1163_1163[50] = "";
  s21_sprintf(test_str_1163, "%lu", 1);
  sprintf(test_str_1163_1163, "%lu", 1);
  ck_assert_str_eq(test_str_1163, test_str_1163_1163);
}
END_TEST

START_TEST(sprintf_test_1164) {
  char test_str_1164[50] = "";
  char test_str_1164_1164[50] = "";
  s21_sprintf(test_str_1164, "%lu", 10);
  sprintf(test_str_1164_1164, "%lu", 10);
  ck_assert_str_eq(test_str_1164, test_str_1164_1164);
}
END_TEST

START_TEST(sprintf_test_1165) {
  char test_str_1165[50] = "";
  char test_str_1165_1165[50] = "";
  s21_sprintf(test_str_1165, "%lu", 123456);
  sprintf(test_str_1165_1165, "%lu", 123456);
  ck_assert_str_eq(test_str_1165, test_str_1165_1165);
}
END_TEST

START_TEST(sprintf_test_1166) {
  char test_str_1166[50] = "";
  char test_str_1166_1166[50] = "";
  s21_sprintf(test_str_1166, "%lu", -678901);
  sprintf(test_str_1166_1166, "%lu", -678901);
  ck_assert_str_eq(test_str_1166, test_str_1166_1166);
}
END_TEST

START_TEST(sprintf_test_1167) {
  char test_str_1167[50] = "";
  char test_str_1167_1167[50] = "";
  s21_sprintf(test_str_1167, "%lu", 4343);
  sprintf(test_str_1167_1167, "%lu", 4343);
  ck_assert_str_eq(test_str_1167, test_str_1167_1167);
}
END_TEST

START_TEST(sprintf_test_1168) {
  char test_str_1168[50] = "";
  char test_str_1168_1168[50] = "";
  s21_sprintf(test_str_1168, "%lu", -1);
  sprintf(test_str_1168_1168, "%lu", -1);
  ck_assert_str_eq(test_str_1168, test_str_1168_1168);
}
END_TEST

START_TEST(sprintf_test_1169) {
  char test_str_1169[50] = "";
  char test_str_1169_1169[50] = "";
  s21_sprintf(test_str_1169, "%lu", -10);
  sprintf(test_str_1169_1169, "%lu", -10);
  ck_assert_str_eq(test_str_1169, test_str_1169_1169);
}
END_TEST

START_TEST(sprintf_test_1170) {
  char test_str_1170[50] = "";
  char test_str_1170_1170[50] = "";
  s21_sprintf(test_str_1170, "%lu", 43);
  sprintf(test_str_1170_1170, "%lu", 43);
  ck_assert_str_eq(test_str_1170, test_str_1170_1170);
}
END_TEST

START_TEST(sprintf_test_1171) {
  char test_str_1171[50] = "";
  char test_str_1171_1171[50] = "";
  s21_sprintf(test_str_1171, "%lx", 0);
  sprintf(test_str_1171_1171, "%lx", 0);
  ck_assert_str_eq(test_str_1171, test_str_1171_1171);
}
END_TEST

START_TEST(sprintf_test_1172) {
  char test_str_1172[50] = "";
  char test_str_1172_1172[50] = "";
  s21_sprintf(test_str_1172, "%lx", 1);
  sprintf(test_str_1172_1172, "%lx", 1);
  ck_assert_str_eq(test_str_1172, test_str_1172_1172);
}
END_TEST

START_TEST(sprintf_test_1173) {
  char test_str_1173[50] = "";
  char test_str_1173_1173[50] = "";
  s21_sprintf(test_str_1173, "%lx", 10);
  sprintf(test_str_1173_1173, "%lx", 10);
  ck_assert_str_eq(test_str_1173, test_str_1173_1173);
}
END_TEST

START_TEST(sprintf_test_1174) {
  char test_str_1174[50] = "";
  char test_str_1174_1174[50] = "";
  s21_sprintf(test_str_1174, "%lx", 123456);
  sprintf(test_str_1174_1174, "%lx", 123456);
  ck_assert_str_eq(test_str_1174, test_str_1174_1174);
}
END_TEST

START_TEST(sprintf_test_1175) {
  char test_str_1175[50] = "";
  char test_str_1175_1175[50] = "";
  s21_sprintf(test_str_1175, "%lx", -678901);
  sprintf(test_str_1175_1175, "%lx", -678901);
  ck_assert_str_eq(test_str_1175, test_str_1175_1175);
}
END_TEST

START_TEST(sprintf_test_1176) {
  char test_str_1176[50] = "";
  char test_str_1176_1176[50] = "";
  s21_sprintf(test_str_1176, "%lx", 4343);
  sprintf(test_str_1176_1176, "%lx", 4343);
  ck_assert_str_eq(test_str_1176, test_str_1176_1176);
}
END_TEST

START_TEST(sprintf_test_1177) {
  char test_str_1177[50] = "";
  char test_str_1177_1177[50] = "";
  s21_sprintf(test_str_1177, "%lx", -1);
  sprintf(test_str_1177_1177, "%lx", -1);
  ck_assert_str_eq(test_str_1177, test_str_1177_1177);
}
END_TEST

START_TEST(sprintf_test_1178) {
  char test_str_1178[50] = "";
  char test_str_1178_1178[50] = "";
  s21_sprintf(test_str_1178, "%lx", -10);
  sprintf(test_str_1178_1178, "%lx", -10);
  ck_assert_str_eq(test_str_1178, test_str_1178_1178);
}
END_TEST

START_TEST(sprintf_test_1179) {
  char test_str_1179[50] = "";
  char test_str_1179_1179[50] = "";
  s21_sprintf(test_str_1179, "%lx", 43);
  sprintf(test_str_1179_1179, "%lx", 43);
  ck_assert_str_eq(test_str_1179, test_str_1179_1179);
}
END_TEST

START_TEST(sprintf_test_1180) {
  char test_str_1180[50] = "";
  char test_str_1180_1180[50] = "";
  s21_sprintf(test_str_1180, "%lX", 0);
  sprintf(test_str_1180_1180, "%lX", 0);
  ck_assert_str_eq(test_str_1180, test_str_1180_1180);
}
END_TEST

START_TEST(sprintf_test_1181) {
  char test_str_1181[50] = "";
  char test_str_1181_1181[50] = "";
  s21_sprintf(test_str_1181, "%lX", 1);
  sprintf(test_str_1181_1181, "%lX", 1);
  ck_assert_str_eq(test_str_1181, test_str_1181_1181);
}
END_TEST

START_TEST(sprintf_test_1182) {
  char test_str_1182[50] = "";
  char test_str_1182_1182[50] = "";
  s21_sprintf(test_str_1182, "%lX", 10);
  sprintf(test_str_1182_1182, "%lX", 10);
  ck_assert_str_eq(test_str_1182, test_str_1182_1182);
}
END_TEST

START_TEST(sprintf_test_1183) {
  char test_str_1183[50] = "";
  char test_str_1183_1183[50] = "";
  s21_sprintf(test_str_1183, "%lX", 123456);
  sprintf(test_str_1183_1183, "%lX", 123456);
  ck_assert_str_eq(test_str_1183, test_str_1183_1183);
}
END_TEST

START_TEST(sprintf_test_1184) {
  char test_str_1184[50] = "";
  char test_str_1184_1184[50] = "";
  s21_sprintf(test_str_1184, "%lX", -678901);
  sprintf(test_str_1184_1184, "%lX", -678901);
  ck_assert_str_eq(test_str_1184, test_str_1184_1184);
}
END_TEST

START_TEST(sprintf_test_1185) {
  char test_str_1185[50] = "";
  char test_str_1185_1185[50] = "";
  s21_sprintf(test_str_1185, "%lX", 4343);
  sprintf(test_str_1185_1185, "%lX", 4343);
  ck_assert_str_eq(test_str_1185, test_str_1185_1185);
}
END_TEST

START_TEST(sprintf_test_1186) {
  char test_str_1186[50] = "";
  char test_str_1186_1186[50] = "";
  s21_sprintf(test_str_1186, "%lX", -1);
  sprintf(test_str_1186_1186, "%lX", -1);
  ck_assert_str_eq(test_str_1186, test_str_1186_1186);
}
END_TEST

START_TEST(sprintf_test_1187) {
  char test_str_1187[50] = "";
  char test_str_1187_1187[50] = "";
  s21_sprintf(test_str_1187, "%lX", -10);
  sprintf(test_str_1187_1187, "%lX", -10);
  ck_assert_str_eq(test_str_1187, test_str_1187_1187);
}
END_TEST

START_TEST(sprintf_test_1188) {
  char test_str_1188[50] = "";
  char test_str_1188_1188[50] = "";
  s21_sprintf(test_str_1188, "%lX", 43);
  sprintf(test_str_1188_1188, "%lX", 43);
  ck_assert_str_eq(test_str_1188, test_str_1188_1188);
}
END_TEST

START_TEST(sprintf_test_1189) {
  char test_str_1189[50] = "";
  char test_str_1189_1189[50] = "";
  s21_sprintf(test_str_1189, "%-s", "1234567");
  sprintf(test_str_1189_1189, "%-s", "1234567");
  ck_assert_str_eq(test_str_1189, test_str_1189_1189);
}
END_TEST

START_TEST(sprintf_test_1190) {
  char test_str_1190[50] = "";
  char test_str_1190_1190[50] = "";
  s21_sprintf(test_str_1190, "%-s", "dffdsfsf");
  sprintf(test_str_1190_1190, "%-s", "dffdsfsf");
  ck_assert_str_eq(test_str_1190, test_str_1190_1190);
}
END_TEST

START_TEST(sprintf_test_1191) {
  char test_str_1191[50] = "";
  char test_str_1191_1191[50] = "";
  s21_sprintf(test_str_1191, "%-s", "");
  sprintf(test_str_1191_1191, "%-s", "");
  ck_assert_str_eq(test_str_1191, test_str_1191_1191);
}
END_TEST

START_TEST(sprintf_test_1192) {
  char test_str_1192[50] = "";
  char test_str_1192_1192[50] = "";
  s21_sprintf(test_str_1192, "%-s", "eefwfweweffwefw");
  sprintf(test_str_1192_1192, "%-s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1192, test_str_1192_1192);
}
END_TEST

START_TEST(sprintf_test_1193) {
  char test_str_1193[50] = "";
  char test_str_1193_1193[50] = "";
  s21_sprintf(test_str_1193, "%+s", "1234567");
  sprintf(test_str_1193_1193, "%+s", "1234567");
  ck_assert_str_eq(test_str_1193, test_str_1193_1193);
}
END_TEST

START_TEST(sprintf_test_1194) {
  char test_str_1194[50] = "";
  char test_str_1194_1194[50] = "";
  s21_sprintf(test_str_1194, "%+s", "dffdsfsf");
  sprintf(test_str_1194_1194, "%+s", "dffdsfsf");
  ck_assert_str_eq(test_str_1194, test_str_1194_1194);
}
END_TEST

START_TEST(sprintf_test_1195) {
  char test_str_1195[50] = "";
  char test_str_1195_1195[50] = "";
  s21_sprintf(test_str_1195, "%+s", "");
  sprintf(test_str_1195_1195, "%+s", "");
  ck_assert_str_eq(test_str_1195, test_str_1195_1195);
}
END_TEST

START_TEST(sprintf_test_1196) {
  char test_str_1196[50] = "";
  char test_str_1196_1196[50] = "";
  s21_sprintf(test_str_1196, "%+s", "eefwfweweffwefw");
  sprintf(test_str_1196_1196, "%+s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1196, test_str_1196_1196);
}
END_TEST

START_TEST(sprintf_test_1197) {
  char test_str_1197[50] = "";
  char test_str_1197_1197[50] = "";
  s21_sprintf(test_str_1197, "%s", "1234567");
  sprintf(test_str_1197_1197, "%s", "1234567");
  ck_assert_str_eq(test_str_1197, test_str_1197_1197);
}
END_TEST

START_TEST(sprintf_test_1198) {
  char test_str_1198[50] = "";
  char test_str_1198_1198[50] = "";
  s21_sprintf(test_str_1198, "%s", "dffdsfsf");
  sprintf(test_str_1198_1198, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1198, test_str_1198_1198);
}
END_TEST

START_TEST(sprintf_test_1199) {
  char test_str_1199[50] = "";
  char test_str_1199_1199[50] = "";
  s21_sprintf(test_str_1199, "%s", "");
  sprintf(test_str_1199_1199, "%s", "");
  ck_assert_str_eq(test_str_1199, test_str_1199_1199);
}
END_TEST

START_TEST(sprintf_test_1200) {
  char test_str_1200[50] = "";
  char test_str_1200_1200[50] = "";
  s21_sprintf(test_str_1200, "%s", "eefwfweweffwefw");
  sprintf(test_str_1200_1200, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1200, test_str_1200_1200);
}
END_TEST

START_TEST(sprintf_test_1201) {
  char test_str_1201[50] = "";
  char test_str_1201_1201[50] = "";
  s21_sprintf(test_str_1201, "%#s", "1234567");
  sprintf(test_str_1201_1201, "%#s", "1234567");
  ck_assert_str_eq(test_str_1201, test_str_1201_1201);
}
END_TEST

START_TEST(sprintf_test_1202) {
  char test_str_1202[50] = "";
  char test_str_1202_1202[50] = "";
  s21_sprintf(test_str_1202, "%#s", "dffdsfsf");
  sprintf(test_str_1202_1202, "%#s", "dffdsfsf");
  ck_assert_str_eq(test_str_1202, test_str_1202_1202);
}
END_TEST

START_TEST(sprintf_test_1203) {
  char test_str_1203[50] = "";
  char test_str_1203_1203[50] = "";
  s21_sprintf(test_str_1203, "%#s", "");
  sprintf(test_str_1203_1203, "%#s", "");
  ck_assert_str_eq(test_str_1203, test_str_1203_1203);
}
END_TEST

START_TEST(sprintf_test_1204) {
  char test_str_1204[50] = "";
  char test_str_1204_1204[50] = "";
  s21_sprintf(test_str_1204, "%#s", "eefwfweweffwefw");
  sprintf(test_str_1204_1204, "%#s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1204, test_str_1204_1204);
}
END_TEST

START_TEST(sprintf_test_1205) {
  char test_str_1205[50] = "";
  char test_str_1205_1205[50] = "";
  s21_sprintf(test_str_1205, "%0s", "1234567");
  sprintf(test_str_1205_1205, "%0s", "1234567");
  ck_assert_str_eq(test_str_1205, test_str_1205_1205);
}
END_TEST

START_TEST(sprintf_test_1206) {
  char test_str_1206[50] = "";
  char test_str_1206_1206[50] = "";
  s21_sprintf(test_str_1206, "%0s", "dffdsfsf");
  sprintf(test_str_1206_1206, "%0s", "dffdsfsf");
  ck_assert_str_eq(test_str_1206, test_str_1206_1206);
}
END_TEST

START_TEST(sprintf_test_1207) {
  char test_str_1207[50] = "";
  char test_str_1207_1207[50] = "";
  s21_sprintf(test_str_1207, "%0s", "");
  sprintf(test_str_1207_1207, "%0s", "");
  ck_assert_str_eq(test_str_1207, test_str_1207_1207);
}
END_TEST

START_TEST(sprintf_test_1208) {
  char test_str_1208[50] = "";
  char test_str_1208_1208[50] = "";
  s21_sprintf(test_str_1208, "%0s", "eefwfweweffwefw");
  sprintf(test_str_1208_1208, "%0s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1208, test_str_1208_1208);
}
END_TEST

START_TEST(sprintf_test_1209) {
  char test_str_1209[50] = "";
  char test_str_1209_1209[50] = "";
  s21_sprintf(test_str_1209, "%20s", "1234567");
  sprintf(test_str_1209_1209, "%20s", "1234567");
  ck_assert_str_eq(test_str_1209, test_str_1209_1209);
}
END_TEST

START_TEST(sprintf_test_1210) {
  char test_str_1210[50] = "";
  char test_str_1210_1210[50] = "";
  s21_sprintf(test_str_1210, "%20s", "dffdsfsf");
  sprintf(test_str_1210_1210, "%20s", "dffdsfsf");
  ck_assert_str_eq(test_str_1210, test_str_1210_1210);
}
END_TEST

START_TEST(sprintf_test_1211) {
  char test_str_1211[50] = "";
  char test_str_1211_1211[50] = "";
  s21_sprintf(test_str_1211, "%20s", "");
  sprintf(test_str_1211_1211, "%20s", "");
  ck_assert_str_eq(test_str_1211, test_str_1211_1211);
}
END_TEST

START_TEST(sprintf_test_1212) {
  char test_str_1212[50] = "";
  char test_str_1212_1212[50] = "";
  s21_sprintf(test_str_1212, "%20s", "eefwfweweffwefw");
  sprintf(test_str_1212_1212, "%20s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1212, test_str_1212_1212);
}
END_TEST

START_TEST(sprintf_test_1213) {
  char test_str_1213[50] = "";
  char test_str_1213_1213[50] = "";
  s21_sprintf(test_str_1213, "%0s", "1234567");
  sprintf(test_str_1213_1213, "%0s", "1234567");
  ck_assert_str_eq(test_str_1213, test_str_1213_1213);
}
END_TEST

START_TEST(sprintf_test_1214) {
  char test_str_1214[50] = "";
  char test_str_1214_1214[50] = "";
  s21_sprintf(test_str_1214, "%0s", "dffdsfsf");
  sprintf(test_str_1214_1214, "%0s", "dffdsfsf");
  ck_assert_str_eq(test_str_1214, test_str_1214_1214);
}
END_TEST

START_TEST(sprintf_test_1215) {
  char test_str_1215[50] = "";
  char test_str_1215_1215[50] = "";
  s21_sprintf(test_str_1215, "%0s", "");
  sprintf(test_str_1215_1215, "%0s", "");
  ck_assert_str_eq(test_str_1215, test_str_1215_1215);
}
END_TEST

START_TEST(sprintf_test_1216) {
  char test_str_1216[50] = "";
  char test_str_1216_1216[50] = "";
  s21_sprintf(test_str_1216, "%0s", "eefwfweweffwefw");
  sprintf(test_str_1216_1216, "%0s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1216, test_str_1216_1216);
}
END_TEST

START_TEST(sprintf_test_1217) {
  char test_str_1217[50] = "";
  char test_str_1217_1217[50] = "";
  s21_sprintf(test_str_1217, "%.0s", "1234567");
  sprintf(test_str_1217_1217, "%.0s", "1234567");
  ck_assert_str_eq(test_str_1217, test_str_1217_1217);
}
END_TEST

START_TEST(sprintf_test_1218) {
  char test_str_1218[50] = "";
  char test_str_1218_1218[50] = "";
  s21_sprintf(test_str_1218, "%.0s", "dffdsfsf");
  sprintf(test_str_1218_1218, "%.0s", "dffdsfsf");
  ck_assert_str_eq(test_str_1218, test_str_1218_1218);
}
END_TEST

START_TEST(sprintf_test_1219) {
  char test_str_1219[50] = "";
  char test_str_1219_1219[50] = "";
  s21_sprintf(test_str_1219, "%.0s", "");
  sprintf(test_str_1219_1219, "%.0s", "");
  ck_assert_str_eq(test_str_1219, test_str_1219_1219);
}
END_TEST

START_TEST(sprintf_test_1220) {
  char test_str_1220[50] = "";
  char test_str_1220_1220[50] = "";
  s21_sprintf(test_str_1220, "%.0s", "eefwfweweffwefw");
  sprintf(test_str_1220_1220, "%.0s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1220, test_str_1220_1220);
}
END_TEST

START_TEST(sprintf_test_1221) {
  char test_str_1221[50] = "";
  char test_str_1221_1221[50] = "";
  s21_sprintf(test_str_1221, "%10s", "1234567");
  sprintf(test_str_1221_1221, "%10s", "1234567");
  ck_assert_str_eq(test_str_1221, test_str_1221_1221);
}
END_TEST

START_TEST(sprintf_test_1222) {
  char test_str_1222[50] = "";
  char test_str_1222_1222[50] = "";
  s21_sprintf(test_str_1222, "%10s", "dffdsfsf");
  sprintf(test_str_1222_1222, "%10s", "dffdsfsf");
  ck_assert_str_eq(test_str_1222, test_str_1222_1222);
}
END_TEST

START_TEST(sprintf_test_1223) {
  char test_str_1223[50] = "";
  char test_str_1223_1223[50] = "";
  s21_sprintf(test_str_1223, "%10s", "");
  sprintf(test_str_1223_1223, "%10s", "");
  ck_assert_str_eq(test_str_1223, test_str_1223_1223);
}
END_TEST

START_TEST(sprintf_test_1224) {
  char test_str_1224[50] = "";
  char test_str_1224_1224[50] = "";
  s21_sprintf(test_str_1224, "%10s", "eefwfweweffwefw");
  sprintf(test_str_1224_1224, "%10s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1224, test_str_1224_1224);
}
END_TEST

START_TEST(sprintf_test_1225) {
  char test_str_1225[50] = "";
  char test_str_1225_1225[50] = "";
  s21_sprintf(test_str_1225, "%-10s", "1234567");
  sprintf(test_str_1225_1225, "%-10s", "1234567");
  ck_assert_str_eq(test_str_1225, test_str_1225_1225);
}
END_TEST

START_TEST(sprintf_test_1226) {
  char test_str_1226[50] = "";
  char test_str_1226_1226[50] = "";
  s21_sprintf(test_str_1226, "%-10s", "dffdsfsf");
  sprintf(test_str_1226_1226, "%-10s", "dffdsfsf");
  ck_assert_str_eq(test_str_1226, test_str_1226_1226);
}
END_TEST

START_TEST(sprintf_test_1227) {
  char test_str_1227[50] = "";
  char test_str_1227_1227[50] = "";
  s21_sprintf(test_str_1227, "%-10s", "");
  sprintf(test_str_1227_1227, "%-10s", "");
  ck_assert_str_eq(test_str_1227, test_str_1227_1227);
}
END_TEST

START_TEST(sprintf_test_1228) {
  char test_str_1228[50] = "";
  char test_str_1228_1228[50] = "";
  s21_sprintf(test_str_1228, "%-10s", "eefwfweweffwefw");
  sprintf(test_str_1228_1228, "%-10s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1228, test_str_1228_1228);
}
END_TEST

START_TEST(sprintf_test_1229) {
  char test_str_1229[50] = "";
  char test_str_1229_1229[50] = "";
  int int_test_str_1229[50] = {0, 0, 0, 0, 0};
  int int_test_str_1229_1229[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1229, "dsdsdsds %-n", int_test_str_1229);
  sprintf(test_str_1229_1229, "dsdsdsds %-n", int_test_str_1229_1229);
  ck_assert_int_eq(int_test_str_1229[0], int_test_str_1229_1229[0]);
}
END_TEST

START_TEST(sprintf_test_1230) {
  char test_str_1230[50] = "";
  char test_str_1230_1230[50] = "";
  int int_test_str_1230[50] = {0, 0, 0, 0, 0};
  int int_test_str_1230_1230[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1230, "dsdsdsds %+n", int_test_str_1230);
  sprintf(test_str_1230_1230, "dsdsdsds %+n", int_test_str_1230_1230);
  ck_assert_int_eq(int_test_str_1230[0], int_test_str_1230_1230[0]);
}
END_TEST

START_TEST(sprintf_test_1231) {
  char test_str_1231[50] = "";
  char test_str_1231_1231[50] = "";
  int int_test_str_1231[50] = {0, 0, 0, 0, 0};
  int int_test_str_1231_1231[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1231, "dsdsdsds %n", int_test_str_1231);
  sprintf(test_str_1231_1231, "dsdsdsds %n", int_test_str_1231_1231);
  ck_assert_int_eq(int_test_str_1231[0], int_test_str_1231_1231[0]);
}
END_TEST

START_TEST(sprintf_test_1232) {
  char test_str_1232[50] = "";
  char test_str_1232_1232[50] = "";
  int int_test_str_1232[50] = {0, 0, 0, 0, 0};
  int int_test_str_1232_1232[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1232, "dsdsdsds %#n", int_test_str_1232);
  sprintf(test_str_1232_1232, "dsdsdsds %#n", int_test_str_1232_1232);
  ck_assert_int_eq(int_test_str_1232[0], int_test_str_1232_1232[0]);
}
END_TEST

START_TEST(sprintf_test_1233) {
  char test_str_1233[50] = "";
  char test_str_1233_1233[50] = "";
  int int_test_str_1233[50] = {0, 0, 0, 0, 0};
  int int_test_str_1233_1233[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1233, "dsdsdsds %0n", int_test_str_1233);
  sprintf(test_str_1233_1233, "dsdsdsds %0n", int_test_str_1233_1233);
  ck_assert_int_eq(int_test_str_1233[0], int_test_str_1233_1233[0]);
}
END_TEST

START_TEST(sprintf_test_1234) {
  char test_str_1234[50] = "";
  char test_str_1234_1234[50] = "";
  int int_test_str_1234[50] = {0, 0, 0, 0, 0};
  int int_test_str_1234_1234[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1234, "dsdsdsds %20n", int_test_str_1234);
  sprintf(test_str_1234_1234, "dsdsdsds %20n", int_test_str_1234_1234);
  ck_assert_int_eq(int_test_str_1234[0], int_test_str_1234_1234[0]);
}
END_TEST

START_TEST(sprintf_test_1235) {
  char test_str_1235[50] = "";
  char test_str_1235_1235[50] = "";
  int int_test_str_1235[50] = {0, 0, 0, 0, 0};
  int int_test_str_1235_1235[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1235, "dsdsdsds %0n", int_test_str_1235);
  sprintf(test_str_1235_1235, "dsdsdsds %0n", int_test_str_1235_1235);
  ck_assert_int_eq(int_test_str_1235[0], int_test_str_1235_1235[0]);
}
END_TEST

START_TEST(sprintf_test_1236) {
  char test_str_1236[50] = "";
  char test_str_1236_1236[50] = "";
  int int_test_str_1236[50] = {0, 0, 0, 0, 0};
  int int_test_str_1236_1236[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1236, "dsdsdsds %.0n", int_test_str_1236);
  sprintf(test_str_1236_1236, "dsdsdsds %.0n", int_test_str_1236_1236);
  ck_assert_int_eq(int_test_str_1236[0], int_test_str_1236_1236[0]);
}
END_TEST

START_TEST(sprintf_test_1237) {
  char test_str_1237[50] = "";
  char test_str_1237_1237[50] = "";
  int int_test_str_1237[50] = {0, 0, 0, 0, 0};
  int int_test_str_1237_1237[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1237, "dsdsdsds %10n", int_test_str_1237);
  sprintf(test_str_1237_1237, "dsdsdsds %10n", int_test_str_1237_1237);
  ck_assert_int_eq(int_test_str_1237[0], int_test_str_1237_1237[0]);
}
END_TEST

START_TEST(sprintf_test_1238) {
  char test_str_1238[50] = "";
  char test_str_1238_1238[50] = "";
  int int_test_str_1238[50] = {0, 0, 0, 0, 0};
  int int_test_str_1238_1238[50] = {0, 0, 0, 0, 0};
  s21_sprintf(test_str_1238, "dsdsdsds %-10n", int_test_str_1238);
  sprintf(test_str_1238_1238, "dsdsdsds %-10n", int_test_str_1238_1238);
  ck_assert_int_eq(int_test_str_1238[0], int_test_str_1238_1238[0]);
}
END_TEST

START_TEST(sprintf_test_1239) {
  char test_pointer1239[50];
  char test_str_1239[50] = "";
  char test_str_1239_1239[50] = "";
  s21_sprintf(test_str_1239, "%-p", test_pointer1239);
  sprintf(test_str_1239_1239, "%-p", test_pointer1239);
  ck_assert_str_eq(test_str_1239, test_str_1239_1239);
}
END_TEST

START_TEST(sprintf_test_1240) {
  char test_pointer1240[50];
  char test_str_1240[50] = "";
  char test_str_1240_1240[50] = "";
  s21_sprintf(test_str_1240, "%+p", test_pointer1240);
  sprintf(test_str_1240_1240, "%+p", test_pointer1240);
  ck_assert_str_eq(test_str_1240, test_str_1240_1240);
}
END_TEST

START_TEST(sprintf_test_1241) {
  char test_pointer1241[50];
  char test_str_1241[50] = "";
  char test_str_1241_1241[50] = "";
  s21_sprintf(test_str_1241, "%p", test_pointer1241);
  sprintf(test_str_1241_1241, "%p", test_pointer1241);
  ck_assert_str_eq(test_str_1241, test_str_1241_1241);
}
END_TEST

START_TEST(sprintf_test_1242) {
  char test_pointer1242[50];
  char test_str_1242[50] = "";
  char test_str_1242_1242[50] = "";
  s21_sprintf(test_str_1242, "%#p", test_pointer1242);
  sprintf(test_str_1242_1242, "%#p", test_pointer1242);
  ck_assert_str_eq(test_str_1242, test_str_1242_1242);
}
END_TEST

START_TEST(sprintf_test_1243) {
  char test_pointer1243[50];
  char test_str_1243[50] = "";
  char test_str_1243_1243[50] = "";
  s21_sprintf(test_str_1243, "%0p", test_pointer1243);
  sprintf(test_str_1243_1243, "%0p", test_pointer1243);
  ck_assert_str_eq(test_str_1243, test_str_1243_1243);
}
END_TEST

START_TEST(sprintf_test_1244) {
  char test_pointer1244[50];
  char test_str_1244[50] = "";
  char test_str_1244_1244[50] = "";
  s21_sprintf(test_str_1244, "%20p", test_pointer1244);
  sprintf(test_str_1244_1244, "%20p", test_pointer1244);
  ck_assert_str_eq(test_str_1244, test_str_1244_1244);
}
END_TEST

START_TEST(sprintf_test_1245) {
  char test_pointer1245[50];
  char test_str_1245[50] = "";
  char test_str_1245_1245[50] = "";
  s21_sprintf(test_str_1245, "%0p", test_pointer1245);
  sprintf(test_str_1245_1245, "%0p", test_pointer1245);
  ck_assert_str_eq(test_str_1245, test_str_1245_1245);
}
END_TEST

START_TEST(sprintf_test_1246) {
  char test_pointer1246[50];
  char test_str_1246[50] = "";
  char test_str_1246_1246[50] = "";
  s21_sprintf(test_str_1246, "%.0p", test_pointer1246);
  sprintf(test_str_1246_1246, "%.0p", test_pointer1246);
  ck_assert_str_eq(test_str_1246, test_str_1246_1246);
}
END_TEST

START_TEST(sprintf_test_1247) {
  char test_pointer1247[50];
  char test_str_1247[50] = "";
  char test_str_1247_1247[50] = "";
  s21_sprintf(test_str_1247, "%10p", test_pointer1247);
  sprintf(test_str_1247_1247, "%10p", test_pointer1247);
  ck_assert_str_eq(test_str_1247, test_str_1247_1247);
}
END_TEST

START_TEST(sprintf_test_1248) {
  char test_pointer1248[50];
  char test_str_1248[50] = "";
  char test_str_1248_1248[50] = "";
  s21_sprintf(test_str_1248, "%-10p", test_pointer1248);
  sprintf(test_str_1248_1248, "%-10p", test_pointer1248);
  ck_assert_str_eq(test_str_1248, test_str_1248_1248);
}
END_TEST

START_TEST(sprintf_test_1249) {
  char test_str_1249[50] = "";
  char test_str_1249_1249[50] = "";
  s21_sprintf(test_str_1249, "%-c", 'a');
  sprintf(test_str_1249_1249, "%-c", 'a');
  ck_assert_str_eq(test_str_1249, test_str_1249_1249);
}
END_TEST

START_TEST(sprintf_test_1250) {
  char test_str_1250[50] = "";
  char test_str_1250_1250[50] = "";
  s21_sprintf(test_str_1250, "%-c", ' ');
  sprintf(test_str_1250_1250, "%-c", ' ');
  ck_assert_str_eq(test_str_1250, test_str_1250_1250);
}
END_TEST

START_TEST(sprintf_test_1251) {
  char test_str_1251[50] = "";
  char test_str_1251_1251[50] = "";
  s21_sprintf(test_str_1251, "%-c", ' ');
  sprintf(test_str_1251_1251, "%-c", ' ');
  ck_assert_str_eq(test_str_1251, test_str_1251_1251);
}
END_TEST

START_TEST(sprintf_test_1252) {
  char test_str_1252[50] = "";
  char test_str_1252_1252[50] = "";
  s21_sprintf(test_str_1252, "%-c", '1');
  sprintf(test_str_1252_1252, "%-c", '1');
  ck_assert_str_eq(test_str_1252, test_str_1252_1252);
}
END_TEST

START_TEST(sprintf_test_1253) {
  char test_str_1253[50] = "";
  char test_str_1253_1253[50] = "";
  s21_sprintf(test_str_1253, "%+c", 'a');
  sprintf(test_str_1253_1253, "%+c", 'a');
  ck_assert_str_eq(test_str_1253, test_str_1253_1253);
}
END_TEST

START_TEST(sprintf_test_1254) {
  char test_str_1254[50] = "";
  char test_str_1254_1254[50] = "";
  s21_sprintf(test_str_1254, "%+c", ' ');
  sprintf(test_str_1254_1254, "%+c", ' ');
  ck_assert_str_eq(test_str_1254, test_str_1254_1254);
}
END_TEST

START_TEST(sprintf_test_1255) {
  char test_str_1255[50] = "";
  char test_str_1255_1255[50] = "";
  s21_sprintf(test_str_1255, "%+c", ' ');
  sprintf(test_str_1255_1255, "%+c", ' ');
  ck_assert_str_eq(test_str_1255, test_str_1255_1255);
}
END_TEST

START_TEST(sprintf_test_1256) {
  char test_str_1256[50] = "";
  char test_str_1256_1256[50] = "";
  s21_sprintf(test_str_1256, "%+c", '1');
  sprintf(test_str_1256_1256, "%+c", '1');
  ck_assert_str_eq(test_str_1256, test_str_1256_1256);
}
END_TEST

START_TEST(sprintf_test_1257) {
  char test_str_1257[50] = "";
  char test_str_1257_1257[50] = "";
  s21_sprintf(test_str_1257, "%c", 'a');
  sprintf(test_str_1257_1257, "%c", 'a');
  ck_assert_str_eq(test_str_1257, test_str_1257_1257);
}
END_TEST

START_TEST(sprintf_test_1258) {
  char test_str_1258[50] = "";
  char test_str_1258_1258[50] = "";
  s21_sprintf(test_str_1258, "%c", ' ');
  sprintf(test_str_1258_1258, "%c", ' ');
  ck_assert_str_eq(test_str_1258, test_str_1258_1258);
}
END_TEST

START_TEST(sprintf_test_1259) {
  char test_str_1259[50] = "";
  char test_str_1259_1259[50] = "";
  s21_sprintf(test_str_1259, "%c", ' ');
  sprintf(test_str_1259_1259, "%c", ' ');
  ck_assert_str_eq(test_str_1259, test_str_1259_1259);
}
END_TEST

START_TEST(sprintf_test_1260) {
  char test_str_1260[50] = "";
  char test_str_1260_1260[50] = "";
  s21_sprintf(test_str_1260, "%c", '1');
  sprintf(test_str_1260_1260, "%c", '1');
  ck_assert_str_eq(test_str_1260, test_str_1260_1260);
}
END_TEST

START_TEST(sprintf_test_1261) {
  char test_str_1261[50] = "";
  char test_str_1261_1261[50] = "";
  s21_sprintf(test_str_1261, "%#c", 'a');
  sprintf(test_str_1261_1261, "%#c", 'a');
  ck_assert_str_eq(test_str_1261, test_str_1261_1261);
}
END_TEST

START_TEST(sprintf_test_1262) {
  char test_str_1262[50] = "";
  char test_str_1262_1262[50] = "";
  s21_sprintf(test_str_1262, "%#c", ' ');
  sprintf(test_str_1262_1262, "%#c", ' ');
  ck_assert_str_eq(test_str_1262, test_str_1262_1262);
}
END_TEST

START_TEST(sprintf_test_1263) {
  char test_str_1263[50] = "";
  char test_str_1263_1263[50] = "";
  s21_sprintf(test_str_1263, "%#c", ' ');
  sprintf(test_str_1263_1263, "%#c", ' ');
  ck_assert_str_eq(test_str_1263, test_str_1263_1263);
}
END_TEST

START_TEST(sprintf_test_1264) {
  char test_str_1264[50] = "";
  char test_str_1264_1264[50] = "";
  s21_sprintf(test_str_1264, "%#c", '1');
  sprintf(test_str_1264_1264, "%#c", '1');
  ck_assert_str_eq(test_str_1264, test_str_1264_1264);
}
END_TEST

START_TEST(sprintf_test_1265) {
  char test_str_1265[50] = "";
  char test_str_1265_1265[50] = "";
  s21_sprintf(test_str_1265, "%0c", 'a');
  sprintf(test_str_1265_1265, "%0c", 'a');
  ck_assert_str_eq(test_str_1265, test_str_1265_1265);
}
END_TEST

START_TEST(sprintf_test_1266) {
  char test_str_1266[50] = "";
  char test_str_1266_1266[50] = "";
  s21_sprintf(test_str_1266, "%0c", ' ');
  sprintf(test_str_1266_1266, "%0c", ' ');
  ck_assert_str_eq(test_str_1266, test_str_1266_1266);
}
END_TEST

START_TEST(sprintf_test_1267) {
  char test_str_1267[50] = "";
  char test_str_1267_1267[50] = "";
  s21_sprintf(test_str_1267, "%0c", ' ');
  sprintf(test_str_1267_1267, "%0c", ' ');
  ck_assert_str_eq(test_str_1267, test_str_1267_1267);
}
END_TEST

START_TEST(sprintf_test_1268) {
  char test_str_1268[50] = "";
  char test_str_1268_1268[50] = "";
  s21_sprintf(test_str_1268, "%0c", '1');
  sprintf(test_str_1268_1268, "%0c", '1');
  ck_assert_str_eq(test_str_1268, test_str_1268_1268);
}
END_TEST

START_TEST(sprintf_test_1269) {
  char test_str_1269[50] = "";
  char test_str_1269_1269[50] = "";
  s21_sprintf(test_str_1269, "%20c", 'a');
  sprintf(test_str_1269_1269, "%20c", 'a');
  ck_assert_str_eq(test_str_1269, test_str_1269_1269);
}
END_TEST

START_TEST(sprintf_test_1270) {
  char test_str_1270[50] = "";
  char test_str_1270_1270[50] = "";
  s21_sprintf(test_str_1270, "%20c", ' ');
  sprintf(test_str_1270_1270, "%20c", ' ');
  ck_assert_str_eq(test_str_1270, test_str_1270_1270);
}
END_TEST

START_TEST(sprintf_test_1271) {
  char test_str_1271[50] = "";
  char test_str_1271_1271[50] = "";
  s21_sprintf(test_str_1271, "%20c", ' ');
  sprintf(test_str_1271_1271, "%20c", ' ');
  ck_assert_str_eq(test_str_1271, test_str_1271_1271);
}
END_TEST

START_TEST(sprintf_test_1272) {
  char test_str_1272[50] = "";
  char test_str_1272_1272[50] = "";
  s21_sprintf(test_str_1272, "%20c", '1');
  sprintf(test_str_1272_1272, "%20c", '1');
  ck_assert_str_eq(test_str_1272, test_str_1272_1272);
}
END_TEST

START_TEST(sprintf_test_1273) {
  char test_str_1273[50] = "";
  char test_str_1273_1273[50] = "";
  s21_sprintf(test_str_1273, "%0c", 'a');
  sprintf(test_str_1273_1273, "%0c", 'a');
  ck_assert_str_eq(test_str_1273, test_str_1273_1273);
}
END_TEST

START_TEST(sprintf_test_1274) {
  char test_str_1274[50] = "";
  char test_str_1274_1274[50] = "";
  s21_sprintf(test_str_1274, "%0c", ' ');
  sprintf(test_str_1274_1274, "%0c", ' ');
  ck_assert_str_eq(test_str_1274, test_str_1274_1274);
}
END_TEST

START_TEST(sprintf_test_1275) {
  char test_str_1275[50] = "";
  char test_str_1275_1275[50] = "";
  s21_sprintf(test_str_1275, "%0c", ' ');
  sprintf(test_str_1275_1275, "%0c", ' ');
  ck_assert_str_eq(test_str_1275, test_str_1275_1275);
}
END_TEST

START_TEST(sprintf_test_1276) {
  char test_str_1276[50] = "";
  char test_str_1276_1276[50] = "";
  s21_sprintf(test_str_1276, "%0c", '1');
  sprintf(test_str_1276_1276, "%0c", '1');
  ck_assert_str_eq(test_str_1276, test_str_1276_1276);
}
END_TEST

START_TEST(sprintf_test_1277) {
  char test_str_1277[50] = "";
  char test_str_1277_1277[50] = "";
  s21_sprintf(test_str_1277, "%.0c", 'a');
  sprintf(test_str_1277_1277, "%.0c", 'a');
  ck_assert_str_eq(test_str_1277, test_str_1277_1277);
}
END_TEST

START_TEST(sprintf_test_1278) {
  char test_str_1278[50] = "";
  char test_str_1278_1278[50] = "";
  s21_sprintf(test_str_1278, "%.0c", ' ');
  sprintf(test_str_1278_1278, "%.0c", ' ');
  ck_assert_str_eq(test_str_1278, test_str_1278_1278);
}
END_TEST

START_TEST(sprintf_test_1279) {
  char test_str_1279[50] = "";
  char test_str_1279_1279[50] = "";
  s21_sprintf(test_str_1279, "%.0c", ' ');
  sprintf(test_str_1279_1279, "%.0c", ' ');
  ck_assert_str_eq(test_str_1279, test_str_1279_1279);
}
END_TEST

START_TEST(sprintf_test_1280) {
  char test_str_1280[50] = "";
  char test_str_1280_1280[50] = "";
  s21_sprintf(test_str_1280, "%.0c", '1');
  sprintf(test_str_1280_1280, "%.0c", '1');
  ck_assert_str_eq(test_str_1280, test_str_1280_1280);
}
END_TEST

START_TEST(sprintf_test_1281) {
  char test_str_1281[50] = "";
  char test_str_1281_1281[50] = "";
  s21_sprintf(test_str_1281, "%10c", 'a');
  sprintf(test_str_1281_1281, "%10c", 'a');
  ck_assert_str_eq(test_str_1281, test_str_1281_1281);
}
END_TEST

START_TEST(sprintf_test_1282) {
  char test_str_1282[50] = "";
  char test_str_1282_1282[50] = "";
  s21_sprintf(test_str_1282, "%10c", ' ');
  sprintf(test_str_1282_1282, "%10c", ' ');
  ck_assert_str_eq(test_str_1282, test_str_1282_1282);
}
END_TEST

START_TEST(sprintf_test_1283) {
  char test_str_1283[50] = "";
  char test_str_1283_1283[50] = "";
  s21_sprintf(test_str_1283, "%10c", ' ');
  sprintf(test_str_1283_1283, "%10c", ' ');
  ck_assert_str_eq(test_str_1283, test_str_1283_1283);
}
END_TEST

START_TEST(sprintf_test_1284) {
  char test_str_1284[50] = "";
  char test_str_1284_1284[50] = "";
  s21_sprintf(test_str_1284, "%10c", '1');
  sprintf(test_str_1284_1284, "%10c", '1');
  ck_assert_str_eq(test_str_1284, test_str_1284_1284);
}
END_TEST

START_TEST(sprintf_test_1285) {
  char test_str_1285[50] = "";
  char test_str_1285_1285[50] = "";
  s21_sprintf(test_str_1285, "%-10c", 'a');
  sprintf(test_str_1285_1285, "%-10c", 'a');
  ck_assert_str_eq(test_str_1285, test_str_1285_1285);
}
END_TEST

START_TEST(sprintf_test_1286) {
  char test_str_1286[50] = "";
  char test_str_1286_1286[50] = "";
  s21_sprintf(test_str_1286, "%-10c", ' ');
  sprintf(test_str_1286_1286, "%-10c", ' ');
  ck_assert_str_eq(test_str_1286, test_str_1286_1286);
}
END_TEST

START_TEST(sprintf_test_1287) {
  char test_str_1287[50] = "";
  char test_str_1287_1287[50] = "";
  s21_sprintf(test_str_1287, "%-10c", ' ');
  sprintf(test_str_1287_1287, "%-10c", ' ');
  ck_assert_str_eq(test_str_1287, test_str_1287_1287);
}
END_TEST

START_TEST(sprintf_test_1288) {
  char test_str_1288[50] = "";
  char test_str_1288_1288[50] = "";
  s21_sprintf(test_str_1288, "%-10c", '1');
  sprintf(test_str_1288_1288, "%-10c", '1');
  ck_assert_str_eq(test_str_1288, test_str_1288_1288);
}
END_TEST

START_TEST(sprintf_test_1289) {
  char test_str_1289[50] = "";
  char test_str_1289_1289[50] = "";
  s21_sprintf(test_str_1289, "%-f", 0.0);
  sprintf(test_str_1289_1289, "%-f", 0.0);
  ck_assert_str_eq(test_str_1289, test_str_1289_1289);
}
END_TEST

START_TEST(sprintf_test_1290) {
  char test_str_1290[50] = "";
  char test_str_1290_1290[50] = "";
  s21_sprintf(test_str_1290, "%-f", 123456789.0);
  sprintf(test_str_1290_1290, "%-f", 123456789.0);
  ck_assert_str_eq(test_str_1290, test_str_1290_1290);
}
END_TEST

START_TEST(sprintf_test_1291) {
  char test_str_1291[50] = "";
  char test_str_1291_1291[50] = "";
  s21_sprintf(test_str_1291, "%-f", 0.123456789);
  sprintf(test_str_1291_1291, "%-f", 0.123456789);
  ck_assert_str_eq(test_str_1291, test_str_1291_1291);
}
END_TEST

START_TEST(sprintf_test_1292) {
  char test_str_1292[50] = "";
  char test_str_1292_1292[50] = "";
  s21_sprintf(test_str_1292, "%-f", -123456789.0);
  sprintf(test_str_1292_1292, "%-f", -123456789.0);
  ck_assert_str_eq(test_str_1292, test_str_1292_1292);
}
END_TEST

START_TEST(sprintf_test_1293) {
  char test_str_1293[50] = "";
  char test_str_1293_1293[50] = "";
  s21_sprintf(test_str_1293, "%-f", -0.123456789);
  sprintf(test_str_1293_1293, "%-f", -0.123456789);
  ck_assert_str_eq(test_str_1293, test_str_1293_1293);
}
END_TEST

START_TEST(sprintf_test_1294) {
  char test_str_1294[50] = "";
  char test_str_1294_1294[50] = "";
  s21_sprintf(test_str_1294, "%-f", 123456789.12345679);
  sprintf(test_str_1294_1294, "%-f", 123456789.12345679);
  ck_assert_str_eq(test_str_1294, test_str_1294_1294);
}
END_TEST

START_TEST(sprintf_test_1295) {
  char test_str_1295[50] = "";
  char test_str_1295_1295[50] = "";
  s21_sprintf(test_str_1295, "%-f", -123456789.12345678);
  sprintf(test_str_1295_1295, "%-f", -123456789.12345678);
  ck_assert_str_eq(test_str_1295, test_str_1295_1295);
}
END_TEST

START_TEST(sprintf_test_1296) {
  char test_str_1296[50] = "";
  char test_str_1296_1296[50] = "";
  s21_sprintf(test_str_1296, "%-f", 1.23e-09);
  sprintf(test_str_1296_1296, "%-f", 1.23e-09);
  ck_assert_str_eq(test_str_1296, test_str_1296_1296);
}
END_TEST

START_TEST(sprintf_test_1297) {
  char test_str_1297[50] = "";
  char test_str_1297_1297[50] = "";
  s21_sprintf(test_str_1297, "%-f", 1.23e-09);
  sprintf(test_str_1297_1297, "%-f", 1.23e-09);
  ck_assert_str_eq(test_str_1297, test_str_1297_1297);
}
END_TEST

START_TEST(sprintf_test_1298) {
  char test_str_1298[50] = "";
  char test_str_1298_1298[50] = "";
  s21_sprintf(test_str_1298, "%+f", 0.0);
  sprintf(test_str_1298_1298, "%+f", 0.0);
  ck_assert_str_eq(test_str_1298, test_str_1298_1298);
}
END_TEST

START_TEST(sprintf_test_1299) {
  char test_str_1299[50] = "";
  char test_str_1299_1299[50] = "";
  s21_sprintf(test_str_1299, "%+f", 123456789.0);
  sprintf(test_str_1299_1299, "%+f", 123456789.0);
  ck_assert_str_eq(test_str_1299, test_str_1299_1299);
}
END_TEST

START_TEST(sprintf_test_1300) {
  char test_str_1300[50] = "";
  char test_str_1300_1300[50] = "";
  s21_sprintf(test_str_1300, "%+f", 0.123456789);
  sprintf(test_str_1300_1300, "%+f", 0.123456789);
  ck_assert_str_eq(test_str_1300, test_str_1300_1300);
}
END_TEST

START_TEST(sprintf_test_1301) {
  char test_str_1301[50] = "";
  char test_str_1301_1301[50] = "";
  s21_sprintf(test_str_1301, "%+f", -123456789.0);
  sprintf(test_str_1301_1301, "%+f", -123456789.0);
  ck_assert_str_eq(test_str_1301, test_str_1301_1301);
}
END_TEST

START_TEST(sprintf_test_1302) {
  char test_str_1302[50] = "";
  char test_str_1302_1302[50] = "";
  s21_sprintf(test_str_1302, "%+f", -0.123456789);
  sprintf(test_str_1302_1302, "%+f", -0.123456789);
  ck_assert_str_eq(test_str_1302, test_str_1302_1302);
}
END_TEST

START_TEST(sprintf_test_1303) {
  char test_str_1303[50] = "";
  char test_str_1303_1303[50] = "";
  s21_sprintf(test_str_1303, "%+f", 123456789.12345679);
  sprintf(test_str_1303_1303, "%+f", 123456789.12345679);
  ck_assert_str_eq(test_str_1303, test_str_1303_1303);
}
END_TEST

START_TEST(sprintf_test_1304) {
  char test_str_1304[50] = "";
  char test_str_1304_1304[50] = "";
  s21_sprintf(test_str_1304, "%+f", -123456789.12345678);
  sprintf(test_str_1304_1304, "%+f", -123456789.12345678);
  ck_assert_str_eq(test_str_1304, test_str_1304_1304);
}
END_TEST

START_TEST(sprintf_test_1305) {
  char test_str_1305[50] = "";
  char test_str_1305_1305[50] = "";
  s21_sprintf(test_str_1305, "%+f", 1.23e-09);
  sprintf(test_str_1305_1305, "%+f", 1.23e-09);
  ck_assert_str_eq(test_str_1305, test_str_1305_1305);
}
END_TEST

START_TEST(sprintf_test_1306) {
  char test_str_1306[50] = "";
  char test_str_1306_1306[50] = "";
  s21_sprintf(test_str_1306, "%+f", 1.23e-09);
  sprintf(test_str_1306_1306, "%+f", 1.23e-09);
  ck_assert_str_eq(test_str_1306, test_str_1306_1306);
}
END_TEST

START_TEST(sprintf_test_1307) {
  char test_str_1307[50] = "";
  char test_str_1307_1307[50] = "";
  s21_sprintf(test_str_1307, "% f", 0.0);
  sprintf(test_str_1307_1307, "% f", 0.0);
  ck_assert_str_eq(test_str_1307, test_str_1307_1307);
}
END_TEST

START_TEST(sprintf_test_1308) {
  char test_str_1308[50] = "";
  char test_str_1308_1308[50] = "";
  s21_sprintf(test_str_1308, "% f", 123456789.0);
  sprintf(test_str_1308_1308, "% f", 123456789.0);
  ck_assert_str_eq(test_str_1308, test_str_1308_1308);
}
END_TEST

START_TEST(sprintf_test_1309) {
  char test_str_1309[50] = "";
  char test_str_1309_1309[50] = "";
  s21_sprintf(test_str_1309, "% f", 0.123456789);
  sprintf(test_str_1309_1309, "% f", 0.123456789);
  ck_assert_str_eq(test_str_1309, test_str_1309_1309);
}
END_TEST

START_TEST(sprintf_test_1310) {
  char test_str_1310[50] = "";
  char test_str_1310_1310[50] = "";
  s21_sprintf(test_str_1310, "% f", -123456789.0);
  sprintf(test_str_1310_1310, "% f", -123456789.0);
  ck_assert_str_eq(test_str_1310, test_str_1310_1310);
}
END_TEST

START_TEST(sprintf_test_1311) {
  char test_str_1311[50] = "";
  char test_str_1311_1311[50] = "";
  s21_sprintf(test_str_1311, "% f", -0.123456789);
  sprintf(test_str_1311_1311, "% f", -0.123456789);
  ck_assert_str_eq(test_str_1311, test_str_1311_1311);
}
END_TEST

START_TEST(sprintf_test_1312) {
  char test_str_1312[50] = "";
  char test_str_1312_1312[50] = "";
  s21_sprintf(test_str_1312, "% f", 123456789.12345679);
  sprintf(test_str_1312_1312, "% f", 123456789.12345679);
  ck_assert_str_eq(test_str_1312, test_str_1312_1312);
}
END_TEST

START_TEST(sprintf_test_1313) {
  char test_str_1313[50] = "";
  char test_str_1313_1313[50] = "";
  s21_sprintf(test_str_1313, "% f", -123456789.12345678);
  sprintf(test_str_1313_1313, "% f", -123456789.12345678);
  ck_assert_str_eq(test_str_1313, test_str_1313_1313);
}
END_TEST

START_TEST(sprintf_test_1314) {
  char test_str_1314[50] = "";
  char test_str_1314_1314[50] = "";
  s21_sprintf(test_str_1314, "% f", 1.23e-09);
  sprintf(test_str_1314_1314, "% f", 1.23e-09);
  ck_assert_str_eq(test_str_1314, test_str_1314_1314);
}
END_TEST

START_TEST(sprintf_test_1315) {
  char test_str_1315[50] = "";
  char test_str_1315_1315[50] = "";
  s21_sprintf(test_str_1315, "% f", 1.23e-09);
  sprintf(test_str_1315_1315, "% f", 1.23e-09);
  ck_assert_str_eq(test_str_1315, test_str_1315_1315);
}
END_TEST

START_TEST(sprintf_test_1316) {
  char test_str_1316[50] = "";
  char test_str_1316_1316[50] = "";
  s21_sprintf(test_str_1316, "%#f", 0.0);
  sprintf(test_str_1316_1316, "%#f", 0.0);
  ck_assert_str_eq(test_str_1316, test_str_1316_1316);
}
END_TEST

START_TEST(sprintf_test_1317) {
  char test_str_1317[50] = "";
  char test_str_1317_1317[50] = "";
  s21_sprintf(test_str_1317, "%#f", 123456789.0);
  sprintf(test_str_1317_1317, "%#f", 123456789.0);
  ck_assert_str_eq(test_str_1317, test_str_1317_1317);
}
END_TEST

START_TEST(sprintf_test_1318) {
  char test_str_1318[50] = "";
  char test_str_1318_1318[50] = "";
  s21_sprintf(test_str_1318, "%#f", 0.123456789);
  sprintf(test_str_1318_1318, "%#f", 0.123456789);
  ck_assert_str_eq(test_str_1318, test_str_1318_1318);
}
END_TEST

START_TEST(sprintf_test_1319) {
  char test_str_1319[50] = "";
  char test_str_1319_1319[50] = "";
  s21_sprintf(test_str_1319, "%#f", -123456789.0);
  sprintf(test_str_1319_1319, "%#f", -123456789.0);
  ck_assert_str_eq(test_str_1319, test_str_1319_1319);
}
END_TEST

START_TEST(sprintf_test_1320) {
  char test_str_1320[50] = "";
  char test_str_1320_1320[50] = "";
  s21_sprintf(test_str_1320, "%#f", -0.123456789);
  sprintf(test_str_1320_1320, "%#f", -0.123456789);
  ck_assert_str_eq(test_str_1320, test_str_1320_1320);
}
END_TEST

START_TEST(sprintf_test_1321) {
  char test_str_1321[50] = "";
  char test_str_1321_1321[50] = "";
  s21_sprintf(test_str_1321, "%#f", 123456789.12345679);
  sprintf(test_str_1321_1321, "%#f", 123456789.12345679);
  ck_assert_str_eq(test_str_1321, test_str_1321_1321);
}
END_TEST

START_TEST(sprintf_test_1322) {
  char test_str_1322[50] = "";
  char test_str_1322_1322[50] = "";
  s21_sprintf(test_str_1322, "%#f", -123456789.12345678);
  sprintf(test_str_1322_1322, "%#f", -123456789.12345678);
  ck_assert_str_eq(test_str_1322, test_str_1322_1322);
}
END_TEST

START_TEST(sprintf_test_1323) {
  char test_str_1323[50] = "";
  char test_str_1323_1323[50] = "";
  s21_sprintf(test_str_1323, "%#f", 1.23e-09);
  sprintf(test_str_1323_1323, "%#f", 1.23e-09);
  ck_assert_str_eq(test_str_1323, test_str_1323_1323);
}
END_TEST

START_TEST(sprintf_test_1324) {
  char test_str_1324[50] = "";
  char test_str_1324_1324[50] = "";
  s21_sprintf(test_str_1324, "%#f", 1.23e-09);
  sprintf(test_str_1324_1324, "%#f", 1.23e-09);
  ck_assert_str_eq(test_str_1324, test_str_1324_1324);
}
END_TEST

START_TEST(sprintf_test_1325) {
  char test_str_1325[50] = "";
  char test_str_1325_1325[50] = "";
  s21_sprintf(test_str_1325, "%0f", 0.0);
  sprintf(test_str_1325_1325, "%0f", 0.0);
  ck_assert_str_eq(test_str_1325, test_str_1325_1325);
}
END_TEST

START_TEST(sprintf_test_1326) {
  char test_str_1326[50] = "";
  char test_str_1326_1326[50] = "";
  s21_sprintf(test_str_1326, "%0f", 123456789.0);
  sprintf(test_str_1326_1326, "%0f", 123456789.0);
  ck_assert_str_eq(test_str_1326, test_str_1326_1326);
}
END_TEST

START_TEST(sprintf_test_1327) {
  char test_str_1327[50] = "";
  char test_str_1327_1327[50] = "";
  s21_sprintf(test_str_1327, "%0f", 0.123456789);
  sprintf(test_str_1327_1327, "%0f", 0.123456789);
  ck_assert_str_eq(test_str_1327, test_str_1327_1327);
}
END_TEST

START_TEST(sprintf_test_1328) {
  char test_str_1328[50] = "";
  char test_str_1328_1328[50] = "";
  s21_sprintf(test_str_1328, "%0f", -123456789.0);
  sprintf(test_str_1328_1328, "%0f", -123456789.0);
  ck_assert_str_eq(test_str_1328, test_str_1328_1328);
}
END_TEST

START_TEST(sprintf_test_1329) {
  char test_str_1329[50] = "";
  char test_str_1329_1329[50] = "";
  s21_sprintf(test_str_1329, "%0f", -0.123456789);
  sprintf(test_str_1329_1329, "%0f", -0.123456789);
  ck_assert_str_eq(test_str_1329, test_str_1329_1329);
}
END_TEST

START_TEST(sprintf_test_1330) {
  char test_str_1330[50] = "";
  char test_str_1330_1330[50] = "";
  s21_sprintf(test_str_1330, "%0f", 123456789.12345679);
  sprintf(test_str_1330_1330, "%0f", 123456789.12345679);
  ck_assert_str_eq(test_str_1330, test_str_1330_1330);
}
END_TEST

START_TEST(sprintf_test_1331) {
  char test_str_1331[50] = "";
  char test_str_1331_1331[50] = "";
  s21_sprintf(test_str_1331, "%0f", -123456789.12345678);
  sprintf(test_str_1331_1331, "%0f", -123456789.12345678);
  ck_assert_str_eq(test_str_1331, test_str_1331_1331);
}
END_TEST

START_TEST(sprintf_test_1332) {
  char test_str_1332[50] = "";
  char test_str_1332_1332[50] = "";
  s21_sprintf(test_str_1332, "%0f", 1.23e-09);
  sprintf(test_str_1332_1332, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1332, test_str_1332_1332);
}
END_TEST

START_TEST(sprintf_test_1333) {
  char test_str_1333[50] = "";
  char test_str_1333_1333[50] = "";
  s21_sprintf(test_str_1333, "%0f", 1.23e-09);
  sprintf(test_str_1333_1333, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1333, test_str_1333_1333);
}
END_TEST

START_TEST(sprintf_test_1334) {
  char test_str_1334[50] = "";
  char test_str_1334_1334[50] = "";
  s21_sprintf(test_str_1334, "%0f", 0.0);
  sprintf(test_str_1334_1334, "%0f", 0.0);
  ck_assert_str_eq(test_str_1334, test_str_1334_1334);
}
END_TEST

START_TEST(sprintf_test_1335) {
  char test_str_1335[50] = "";
  char test_str_1335_1335[50] = "";
  s21_sprintf(test_str_1335, "%0f", 123456789.0);
  sprintf(test_str_1335_1335, "%0f", 123456789.0);
  ck_assert_str_eq(test_str_1335, test_str_1335_1335);
}
END_TEST

START_TEST(sprintf_test_1336) {
  char test_str_1336[50] = "";
  char test_str_1336_1336[50] = "";
  s21_sprintf(test_str_1336, "%0f", 0.123456789);
  sprintf(test_str_1336_1336, "%0f", 0.123456789);
  ck_assert_str_eq(test_str_1336, test_str_1336_1336);
}
END_TEST

START_TEST(sprintf_test_1337) {
  char test_str_1337[50] = "";
  char test_str_1337_1337[50] = "";
  s21_sprintf(test_str_1337, "%0f", -123456789.0);
  sprintf(test_str_1337_1337, "%0f", -123456789.0);
  ck_assert_str_eq(test_str_1337, test_str_1337_1337);
}
END_TEST

START_TEST(sprintf_test_1338) {
  char test_str_1338[50] = "";
  char test_str_1338_1338[50] = "";
  s21_sprintf(test_str_1338, "%0f", -0.123456789);
  sprintf(test_str_1338_1338, "%0f", -0.123456789);
  ck_assert_str_eq(test_str_1338, test_str_1338_1338);
}
END_TEST

START_TEST(sprintf_test_1339) {
  char test_str_1339[50] = "";
  char test_str_1339_1339[50] = "";
  s21_sprintf(test_str_1339, "%0f", 123456789.12345679);
  sprintf(test_str_1339_1339, "%0f", 123456789.12345679);
  ck_assert_str_eq(test_str_1339, test_str_1339_1339);
}
END_TEST

START_TEST(sprintf_test_1340) {
  char test_str_1340[50] = "";
  char test_str_1340_1340[50] = "";
  s21_sprintf(test_str_1340, "%0f", -123456789.12345678);
  sprintf(test_str_1340_1340, "%0f", -123456789.12345678);
  ck_assert_str_eq(test_str_1340, test_str_1340_1340);
}
END_TEST

START_TEST(sprintf_test_1341) {
  char test_str_1341[50] = "";
  char test_str_1341_1341[50] = "";
  s21_sprintf(test_str_1341, "%0f", 1.23e-09);
  sprintf(test_str_1341_1341, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1341, test_str_1341_1341);
}
END_TEST

START_TEST(sprintf_test_1342) {
  char test_str_1342[50] = "";
  char test_str_1342_1342[50] = "";
  s21_sprintf(test_str_1342, "%0f", 1.23e-09);
  sprintf(test_str_1342_1342, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1342, test_str_1342_1342);
}
END_TEST

START_TEST(sprintf_test_1343) {
  char test_str_1343[50] = "";
  char test_str_1343_1343[50] = "";
  s21_sprintf(test_str_1343, "%10f", 0.0);
  sprintf(test_str_1343_1343, "%10f", 0.0);
  ck_assert_str_eq(test_str_1343, test_str_1343_1343);
}
END_TEST

START_TEST(sprintf_test_1344) {
  char test_str_1344[50] = "";
  char test_str_1344_1344[50] = "";
  s21_sprintf(test_str_1344, "%10f", 123456789.0);
  sprintf(test_str_1344_1344, "%10f", 123456789.0);
  ck_assert_str_eq(test_str_1344, test_str_1344_1344);
}
END_TEST

START_TEST(sprintf_test_1345) {
  char test_str_1345[50] = "";
  char test_str_1345_1345[50] = "";
  s21_sprintf(test_str_1345, "%10f", 0.123456789);
  sprintf(test_str_1345_1345, "%10f", 0.123456789);
  ck_assert_str_eq(test_str_1345, test_str_1345_1345);
}
END_TEST

START_TEST(sprintf_test_1346) {
  char test_str_1346[50] = "";
  char test_str_1346_1346[50] = "";
  s21_sprintf(test_str_1346, "%10f", -123456789.0);
  sprintf(test_str_1346_1346, "%10f", -123456789.0);
  ck_assert_str_eq(test_str_1346, test_str_1346_1346);
}
END_TEST

START_TEST(sprintf_test_1347) {
  char test_str_1347[50] = "";
  char test_str_1347_1347[50] = "";
  s21_sprintf(test_str_1347, "%10f", -0.123456789);
  sprintf(test_str_1347_1347, "%10f", -0.123456789);
  ck_assert_str_eq(test_str_1347, test_str_1347_1347);
}
END_TEST

START_TEST(sprintf_test_1348) {
  char test_str_1348[50] = "";
  char test_str_1348_1348[50] = "";
  s21_sprintf(test_str_1348, "%10f", 123456789.12345679);
  sprintf(test_str_1348_1348, "%10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1348, test_str_1348_1348);
}
END_TEST

START_TEST(sprintf_test_1349) {
  char test_str_1349[50] = "";
  char test_str_1349_1349[50] = "";
  s21_sprintf(test_str_1349, "%10f", -123456789.12345678);
  sprintf(test_str_1349_1349, "%10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1349, test_str_1349_1349);
}
END_TEST

START_TEST(sprintf_test_1350) {
  char test_str_1350[50] = "";
  char test_str_1350_1350[50] = "";
  s21_sprintf(test_str_1350, "%10f", 1.23e-09);
  sprintf(test_str_1350_1350, "%10f", 1.23e-09);
  ck_assert_str_eq(test_str_1350, test_str_1350_1350);
}
END_TEST

START_TEST(sprintf_test_1351) {
  char test_str_1351[50] = "";
  char test_str_1351_1351[50] = "";
  s21_sprintf(test_str_1351, "%10f", 1.23e-09);
  sprintf(test_str_1351_1351, "%10f", 1.23e-09);
  ck_assert_str_eq(test_str_1351, test_str_1351_1351);
}
END_TEST

START_TEST(sprintf_test_1352) {
  char test_str_1352[50] = "";
  char test_str_1352_1352[50] = "";
  s21_sprintf(test_str_1352, "%20f", 0.0);
  sprintf(test_str_1352_1352, "%20f", 0.0);
  ck_assert_str_eq(test_str_1352, test_str_1352_1352);
}
END_TEST

START_TEST(sprintf_test_1353) {
  char test_str_1353[50] = "";
  char test_str_1353_1353[50] = "";
  s21_sprintf(test_str_1353, "%20f", 123456789.0);
  sprintf(test_str_1353_1353, "%20f", 123456789.0);
  ck_assert_str_eq(test_str_1353, test_str_1353_1353);
}
END_TEST

START_TEST(sprintf_test_1354) {
  char test_str_1354[50] = "";
  char test_str_1354_1354[50] = "";
  s21_sprintf(test_str_1354, "%20f", 0.123456789);
  sprintf(test_str_1354_1354, "%20f", 0.123456789);
  ck_assert_str_eq(test_str_1354, test_str_1354_1354);
}
END_TEST

START_TEST(sprintf_test_1355) {
  char test_str_1355[50] = "";
  char test_str_1355_1355[50] = "";
  s21_sprintf(test_str_1355, "%20f", -123456789.0);
  sprintf(test_str_1355_1355, "%20f", -123456789.0);
  ck_assert_str_eq(test_str_1355, test_str_1355_1355);
}
END_TEST

START_TEST(sprintf_test_1356) {
  char test_str_1356[50] = "";
  char test_str_1356_1356[50] = "";
  s21_sprintf(test_str_1356, "%20f", -0.123456789);
  sprintf(test_str_1356_1356, "%20f", -0.123456789);
  ck_assert_str_eq(test_str_1356, test_str_1356_1356);
}
END_TEST

START_TEST(sprintf_test_1357) {
  char test_str_1357[50] = "";
  char test_str_1357_1357[50] = "";
  s21_sprintf(test_str_1357, "%20f", 123456789.12345679);
  sprintf(test_str_1357_1357, "%20f", 123456789.12345679);
  ck_assert_str_eq(test_str_1357, test_str_1357_1357);
}
END_TEST

START_TEST(sprintf_test_1358) {
  char test_str_1358[50] = "";
  char test_str_1358_1358[50] = "";
  s21_sprintf(test_str_1358, "%20f", -123456789.12345678);
  sprintf(test_str_1358_1358, "%20f", -123456789.12345678);
  ck_assert_str_eq(test_str_1358, test_str_1358_1358);
}
END_TEST

START_TEST(sprintf_test_1359) {
  char test_str_1359[50] = "";
  char test_str_1359_1359[50] = "";
  s21_sprintf(test_str_1359, "%20f", 1.23e-09);
  sprintf(test_str_1359_1359, "%20f", 1.23e-09);
  ck_assert_str_eq(test_str_1359, test_str_1359_1359);
}
END_TEST

START_TEST(sprintf_test_1360) {
  char test_str_1360[50] = "";
  char test_str_1360_1360[50] = "";
  s21_sprintf(test_str_1360, "%20f", 1.23e-09);
  sprintf(test_str_1360_1360, "%20f", 1.23e-09);
  ck_assert_str_eq(test_str_1360, test_str_1360_1360);
}
END_TEST

START_TEST(sprintf_test_1361) {
  char test_str_1361[50] = "";
  char test_str_1361_1361[50] = "";
  s21_sprintf(test_str_1361, "%-10f", 0.0);
  sprintf(test_str_1361_1361, "%-10f", 0.0);
  ck_assert_str_eq(test_str_1361, test_str_1361_1361);
}
END_TEST

START_TEST(sprintf_test_1362) {
  char test_str_1362[50] = "";
  char test_str_1362_1362[50] = "";
  s21_sprintf(test_str_1362, "%-10f", 123456789.0);
  sprintf(test_str_1362_1362, "%-10f", 123456789.0);
  ck_assert_str_eq(test_str_1362, test_str_1362_1362);
}
END_TEST

START_TEST(sprintf_test_1363) {
  char test_str_1363[50] = "";
  char test_str_1363_1363[50] = "";
  s21_sprintf(test_str_1363, "%-10f", 0.123456789);
  sprintf(test_str_1363_1363, "%-10f", 0.123456789);
  ck_assert_str_eq(test_str_1363, test_str_1363_1363);
}
END_TEST

START_TEST(sprintf_test_1364) {
  char test_str_1364[50] = "";
  char test_str_1364_1364[50] = "";
  s21_sprintf(test_str_1364, "%-10f", -123456789.0);
  sprintf(test_str_1364_1364, "%-10f", -123456789.0);
  ck_assert_str_eq(test_str_1364, test_str_1364_1364);
}
END_TEST

START_TEST(sprintf_test_1365) {
  char test_str_1365[50] = "";
  char test_str_1365_1365[50] = "";
  s21_sprintf(test_str_1365, "%-10f", -0.123456789);
  sprintf(test_str_1365_1365, "%-10f", -0.123456789);
  ck_assert_str_eq(test_str_1365, test_str_1365_1365);
}
END_TEST

START_TEST(sprintf_test_1366) {
  char test_str_1366[50] = "";
  char test_str_1366_1366[50] = "";
  s21_sprintf(test_str_1366, "%-10f", 123456789.12345679);
  sprintf(test_str_1366_1366, "%-10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1366, test_str_1366_1366);
}
END_TEST

START_TEST(sprintf_test_1367) {
  char test_str_1367[50] = "";
  char test_str_1367_1367[50] = "";
  s21_sprintf(test_str_1367, "%-10f", -123456789.12345678);
  sprintf(test_str_1367_1367, "%-10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1367, test_str_1367_1367);
}
END_TEST

START_TEST(sprintf_test_1368) {
  char test_str_1368[50] = "";
  char test_str_1368_1368[50] = "";
  s21_sprintf(test_str_1368, "%-10f", 1.23e-09);
  sprintf(test_str_1368_1368, "%-10f", 1.23e-09);
  ck_assert_str_eq(test_str_1368, test_str_1368_1368);
}
END_TEST

START_TEST(sprintf_test_1369) {
  char test_str_1369[50] = "";
  char test_str_1369_1369[50] = "";
  s21_sprintf(test_str_1369, "%-10f", 1.23e-09);
  sprintf(test_str_1369_1369, "%-10f", 1.23e-09);
  ck_assert_str_eq(test_str_1369, test_str_1369_1369);
}
END_TEST

START_TEST(sprintf_test_1370) {
  char test_str_1370[50] = "";
  char test_str_1370_1370[50] = "";
  s21_sprintf(test_str_1370, "%-20f", 0.0);
  sprintf(test_str_1370_1370, "%-20f", 0.0);
  ck_assert_str_eq(test_str_1370, test_str_1370_1370);
}
END_TEST

START_TEST(sprintf_test_1371) {
  char test_str_1371[50] = "";
  char test_str_1371_1371[50] = "";
  s21_sprintf(test_str_1371, "%-20f", 123456789.0);
  sprintf(test_str_1371_1371, "%-20f", 123456789.0);
  ck_assert_str_eq(test_str_1371, test_str_1371_1371);
}
END_TEST

START_TEST(sprintf_test_1372) {
  char test_str_1372[50] = "";
  char test_str_1372_1372[50] = "";
  s21_sprintf(test_str_1372, "%-20f", 0.123456789);
  sprintf(test_str_1372_1372, "%-20f", 0.123456789);
  ck_assert_str_eq(test_str_1372, test_str_1372_1372);
}
END_TEST

START_TEST(sprintf_test_1373) {
  char test_str_1373[50] = "";
  char test_str_1373_1373[50] = "";
  s21_sprintf(test_str_1373, "%-20f", -123456789.0);
  sprintf(test_str_1373_1373, "%-20f", -123456789.0);
  ck_assert_str_eq(test_str_1373, test_str_1373_1373);
}
END_TEST

START_TEST(sprintf_test_1374) {
  char test_str_1374[50] = "";
  char test_str_1374_1374[50] = "";
  s21_sprintf(test_str_1374, "%-20f", -0.123456789);
  sprintf(test_str_1374_1374, "%-20f", -0.123456789);
  ck_assert_str_eq(test_str_1374, test_str_1374_1374);
}
END_TEST

START_TEST(sprintf_test_1375) {
  char test_str_1375[50] = "";
  char test_str_1375_1375[50] = "";
  s21_sprintf(test_str_1375, "%-20f", 123456789.12345679);
  sprintf(test_str_1375_1375, "%-20f", 123456789.12345679);
  ck_assert_str_eq(test_str_1375, test_str_1375_1375);
}
END_TEST

START_TEST(sprintf_test_1376) {
  char test_str_1376[50] = "";
  char test_str_1376_1376[50] = "";
  s21_sprintf(test_str_1376, "%-20f", -123456789.12345678);
  sprintf(test_str_1376_1376, "%-20f", -123456789.12345678);
  ck_assert_str_eq(test_str_1376, test_str_1376_1376);
}
END_TEST

START_TEST(sprintf_test_1377) {
  char test_str_1377[50] = "";
  char test_str_1377_1377[50] = "";
  s21_sprintf(test_str_1377, "%-20f", 1.23e-09);
  sprintf(test_str_1377_1377, "%-20f", 1.23e-09);
  ck_assert_str_eq(test_str_1377, test_str_1377_1377);
}
END_TEST

START_TEST(sprintf_test_1378) {
  char test_str_1378[50] = "";
  char test_str_1378_1378[50] = "";
  s21_sprintf(test_str_1378, "%-20f", 1.23e-09);
  sprintf(test_str_1378_1378, "%-20f", 1.23e-09);
  ck_assert_str_eq(test_str_1378, test_str_1378_1378);
}
END_TEST

START_TEST(sprintf_test_1379) {
  char test_str_1379[50] = "";
  char test_str_1379_1379[50] = "";
  s21_sprintf(test_str_1379, "%*f", 0, 0.0);
  sprintf(test_str_1379_1379, "%*f", 0, 0.0);
  ck_assert_str_eq(test_str_1379, test_str_1379_1379);
}
END_TEST

START_TEST(sprintf_test_1380) {
  char test_str_1380[50] = "";
  char test_str_1380_1380[50] = "";
  s21_sprintf(test_str_1380, "%*f", 0, 123456789.0);
  sprintf(test_str_1380_1380, "%*f", 0, 123456789.0);
  ck_assert_str_eq(test_str_1380, test_str_1380_1380);
}
END_TEST

START_TEST(sprintf_test_1381) {
  char test_str_1381[50] = "";
  char test_str_1381_1381[50] = "";
  s21_sprintf(test_str_1381, "%*f", 0, 0.123456789);
  sprintf(test_str_1381_1381, "%*f", 0, 0.123456789);
  ck_assert_str_eq(test_str_1381, test_str_1381_1381);
}
END_TEST

START_TEST(sprintf_test_1382) {
  char test_str_1382[50] = "";
  char test_str_1382_1382[50] = "";
  s21_sprintf(test_str_1382, "%*f", 0, -123456789.0);
  sprintf(test_str_1382_1382, "%*f", 0, -123456789.0);
  ck_assert_str_eq(test_str_1382, test_str_1382_1382);
}
END_TEST

START_TEST(sprintf_test_1383) {
  char test_str_1383[50] = "";
  char test_str_1383_1383[50] = "";
  s21_sprintf(test_str_1383, "%*f", 0, -0.123456789);
  sprintf(test_str_1383_1383, "%*f", 0, -0.123456789);
  ck_assert_str_eq(test_str_1383, test_str_1383_1383);
}
END_TEST

START_TEST(sprintf_test_1384) {
  char test_str_1384[50] = "";
  char test_str_1384_1384[50] = "";
  s21_sprintf(test_str_1384, "%*f", 0, 123456789.12345679);
  sprintf(test_str_1384_1384, "%*f", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_1384, test_str_1384_1384);
}
END_TEST

START_TEST(sprintf_test_1385) {
  char test_str_1385[50] = "";
  char test_str_1385_1385[50] = "";
  s21_sprintf(test_str_1385, "%*f", 0, -123456789.12345678);
  sprintf(test_str_1385_1385, "%*f", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_1385, test_str_1385_1385);
}
END_TEST

START_TEST(sprintf_test_1386) {
  char test_str_1386[50] = "";
  char test_str_1386_1386[50] = "";
  s21_sprintf(test_str_1386, "%*f", 0, 1.23e-09);
  sprintf(test_str_1386_1386, "%*f", 0, 1.23e-09);
  ck_assert_str_eq(test_str_1386, test_str_1386_1386);
}
END_TEST

START_TEST(sprintf_test_1387) {
  char test_str_1387[50] = "";
  char test_str_1387_1387[50] = "";
  s21_sprintf(test_str_1387, "%*f", 0, 1.23e-09);
  sprintf(test_str_1387_1387, "%*f", 0, 1.23e-09);
  ck_assert_str_eq(test_str_1387, test_str_1387_1387);
}
END_TEST

START_TEST(sprintf_test_1388) {
  char test_str_1388[50] = "";
  char test_str_1388_1388[50] = "";
  s21_sprintf(test_str_1388, "%*f", 10, 0.0);
  sprintf(test_str_1388_1388, "%*f", 10, 0.0);
  ck_assert_str_eq(test_str_1388, test_str_1388_1388);
}
END_TEST

START_TEST(sprintf_test_1389) {
  char test_str_1389[50] = "";
  char test_str_1389_1389[50] = "";
  s21_sprintf(test_str_1389, "%*f", 10, 123456789.0);
  sprintf(test_str_1389_1389, "%*f", 10, 123456789.0);
  ck_assert_str_eq(test_str_1389, test_str_1389_1389);
}
END_TEST

START_TEST(sprintf_test_1390) {
  char test_str_1390[50] = "";
  char test_str_1390_1390[50] = "";
  s21_sprintf(test_str_1390, "%*f", 10, 0.123456789);
  sprintf(test_str_1390_1390, "%*f", 10, 0.123456789);
  ck_assert_str_eq(test_str_1390, test_str_1390_1390);
}
END_TEST

START_TEST(sprintf_test_1391) {
  char test_str_1391[50] = "";
  char test_str_1391_1391[50] = "";
  s21_sprintf(test_str_1391, "%*f", 10, -123456789.0);
  sprintf(test_str_1391_1391, "%*f", 10, -123456789.0);
  ck_assert_str_eq(test_str_1391, test_str_1391_1391);
}
END_TEST

START_TEST(sprintf_test_1392) {
  char test_str_1392[50] = "";
  char test_str_1392_1392[50] = "";
  s21_sprintf(test_str_1392, "%*f", 10, -0.123456789);
  sprintf(test_str_1392_1392, "%*f", 10, -0.123456789);
  ck_assert_str_eq(test_str_1392, test_str_1392_1392);
}
END_TEST

START_TEST(sprintf_test_1393) {
  char test_str_1393[50] = "";
  char test_str_1393_1393[50] = "";
  s21_sprintf(test_str_1393, "%*f", 10, 123456789.12345679);
  sprintf(test_str_1393_1393, "%*f", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_1393, test_str_1393_1393);
}
END_TEST

START_TEST(sprintf_test_1394) {
  char test_str_1394[50] = "";
  char test_str_1394_1394[50] = "";
  s21_sprintf(test_str_1394, "%*f", 10, -123456789.12345678);
  sprintf(test_str_1394_1394, "%*f", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_1394, test_str_1394_1394);
}
END_TEST

START_TEST(sprintf_test_1395) {
  char test_str_1395[50] = "";
  char test_str_1395_1395[50] = "";
  s21_sprintf(test_str_1395, "%*f", 10, 1.23e-09);
  sprintf(test_str_1395_1395, "%*f", 10, 1.23e-09);
  ck_assert_str_eq(test_str_1395, test_str_1395_1395);
}
END_TEST

START_TEST(sprintf_test_1396) {
  char test_str_1396[50] = "";
  char test_str_1396_1396[50] = "";
  s21_sprintf(test_str_1396, "%*f", 10, 1.23e-09);
  sprintf(test_str_1396_1396, "%*f", 10, 1.23e-09);
  ck_assert_str_eq(test_str_1396, test_str_1396_1396);
}
END_TEST

START_TEST(sprintf_test_1397) {
  char test_str_1397[50] = "";
  char test_str_1397_1397[50] = "";
  s21_sprintf(test_str_1397, "%*f", 20, 0.0);
  sprintf(test_str_1397_1397, "%*f", 20, 0.0);
  ck_assert_str_eq(test_str_1397, test_str_1397_1397);
}
END_TEST

START_TEST(sprintf_test_1398) {
  char test_str_1398[50] = "";
  char test_str_1398_1398[50] = "";
  s21_sprintf(test_str_1398, "%*f", 20, 123456789.0);
  sprintf(test_str_1398_1398, "%*f", 20, 123456789.0);
  ck_assert_str_eq(test_str_1398, test_str_1398_1398);
}
END_TEST

START_TEST(sprintf_test_1399) {
  char test_str_1399[50] = "";
  char test_str_1399_1399[50] = "";
  s21_sprintf(test_str_1399, "%*f", 20, 0.123456789);
  sprintf(test_str_1399_1399, "%*f", 20, 0.123456789);
  ck_assert_str_eq(test_str_1399, test_str_1399_1399);
}
END_TEST

START_TEST(sprintf_test_1400) {
  char test_str_1400[50] = "";
  char test_str_1400_1400[50] = "";
  s21_sprintf(test_str_1400, "%*f", 20, -123456789.0);
  sprintf(test_str_1400_1400, "%*f", 20, -123456789.0);
  ck_assert_str_eq(test_str_1400, test_str_1400_1400);
}
END_TEST

START_TEST(sprintf_test_1401) {
  char test_str_1401[50] = "";
  char test_str_1401_1401[50] = "";
  s21_sprintf(test_str_1401, "%*f", 20, -0.123456789);
  sprintf(test_str_1401_1401, "%*f", 20, -0.123456789);
  ck_assert_str_eq(test_str_1401, test_str_1401_1401);
}
END_TEST

START_TEST(sprintf_test_1402) {
  char test_str_1402[50] = "";
  char test_str_1402_1402[50] = "";
  s21_sprintf(test_str_1402, "%*f", 20, 123456789.12345679);
  sprintf(test_str_1402_1402, "%*f", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_1402, test_str_1402_1402);
}
END_TEST

START_TEST(sprintf_test_1403) {
  char test_str_1403[50] = "";
  char test_str_1403_1403[50] = "";
  s21_sprintf(test_str_1403, "%*f", 20, -123456789.12345678);
  sprintf(test_str_1403_1403, "%*f", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_1403, test_str_1403_1403);
}
END_TEST

START_TEST(sprintf_test_1404) {
  char test_str_1404[50] = "";
  char test_str_1404_1404[50] = "";
  s21_sprintf(test_str_1404, "%*f", 20, 1.23e-09);
  sprintf(test_str_1404_1404, "%*f", 20, 1.23e-09);
  ck_assert_str_eq(test_str_1404, test_str_1404_1404);
}
END_TEST

START_TEST(sprintf_test_1405) {
  char test_str_1405[50] = "";
  char test_str_1405_1405[50] = "";
  s21_sprintf(test_str_1405, "%*f", 20, 1.23e-09);
  sprintf(test_str_1405_1405, "%*f", 20, 1.23e-09);
  ck_assert_str_eq(test_str_1405, test_str_1405_1405);
}
END_TEST

START_TEST(sprintf_test_1406) {
  char test_str_1406[50] = "";
  char test_str_1406_1406[50] = "";
  s21_sprintf(test_str_1406, "%*f", -10, 0.0);
  sprintf(test_str_1406_1406, "%*f", -10, 0.0);
  ck_assert_str_eq(test_str_1406, test_str_1406_1406);
}
END_TEST

START_TEST(sprintf_test_1407) {
  char test_str_1407[50] = "";
  char test_str_1407_1407[50] = "";
  s21_sprintf(test_str_1407, "%*f", -10, 123456789.0);
  sprintf(test_str_1407_1407, "%*f", -10, 123456789.0);
  ck_assert_str_eq(test_str_1407, test_str_1407_1407);
}
END_TEST

START_TEST(sprintf_test_1408) {
  char test_str_1408[50] = "";
  char test_str_1408_1408[50] = "";
  s21_sprintf(test_str_1408, "%*f", -10, 0.123456789);
  sprintf(test_str_1408_1408, "%*f", -10, 0.123456789);
  ck_assert_str_eq(test_str_1408, test_str_1408_1408);
}
END_TEST

START_TEST(sprintf_test_1409) {
  char test_str_1409[50] = "";
  char test_str_1409_1409[50] = "";
  s21_sprintf(test_str_1409, "%*f", -10, -123456789.0);
  sprintf(test_str_1409_1409, "%*f", -10, -123456789.0);
  ck_assert_str_eq(test_str_1409, test_str_1409_1409);
}
END_TEST

START_TEST(sprintf_test_1410) {
  char test_str_1410[50] = "";
  char test_str_1410_1410[50] = "";
  s21_sprintf(test_str_1410, "%*f", -10, -0.123456789);
  sprintf(test_str_1410_1410, "%*f", -10, -0.123456789);
  ck_assert_str_eq(test_str_1410, test_str_1410_1410);
}
END_TEST

START_TEST(sprintf_test_1411) {
  char test_str_1411[50] = "";
  char test_str_1411_1411[50] = "";
  s21_sprintf(test_str_1411, "%*f", -10, 123456789.12345679);
  sprintf(test_str_1411_1411, "%*f", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_1411, test_str_1411_1411);
}
END_TEST

START_TEST(sprintf_test_1412) {
  char test_str_1412[50] = "";
  char test_str_1412_1412[50] = "";
  s21_sprintf(test_str_1412, "%*f", -10, -123456789.12345678);
  sprintf(test_str_1412_1412, "%*f", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_1412, test_str_1412_1412);
}
END_TEST

START_TEST(sprintf_test_1413) {
  char test_str_1413[50] = "";
  char test_str_1413_1413[50] = "";
  s21_sprintf(test_str_1413, "%*f", -10, 1.23e-09);
  sprintf(test_str_1413_1413, "%*f", -10, 1.23e-09);
  ck_assert_str_eq(test_str_1413, test_str_1413_1413);
}
END_TEST

START_TEST(sprintf_test_1414) {
  char test_str_1414[50] = "";
  char test_str_1414_1414[50] = "";
  s21_sprintf(test_str_1414, "%*f", -10, 1.23e-09);
  sprintf(test_str_1414_1414, "%*f", -10, 1.23e-09);
  ck_assert_str_eq(test_str_1414, test_str_1414_1414);
}
END_TEST

START_TEST(sprintf_test_1415) {
  char test_str_1415[50] = "";
  char test_str_1415_1415[50] = "";
  s21_sprintf(test_str_1415, "%*f", -20, 0.0);
  sprintf(test_str_1415_1415, "%*f", -20, 0.0);
  ck_assert_str_eq(test_str_1415, test_str_1415_1415);
}
END_TEST

START_TEST(sprintf_test_1416) {
  char test_str_1416[50] = "";
  char test_str_1416_1416[50] = "";
  s21_sprintf(test_str_1416, "%*f", -20, 123456789.0);
  sprintf(test_str_1416_1416, "%*f", -20, 123456789.0);
  ck_assert_str_eq(test_str_1416, test_str_1416_1416);
}
END_TEST

START_TEST(sprintf_test_1417) {
  char test_str_1417[50] = "";
  char test_str_1417_1417[50] = "";
  s21_sprintf(test_str_1417, "%*f", -20, 0.123456789);
  sprintf(test_str_1417_1417, "%*f", -20, 0.123456789);
  ck_assert_str_eq(test_str_1417, test_str_1417_1417);
}
END_TEST

START_TEST(sprintf_test_1418) {
  char test_str_1418[50] = "";
  char test_str_1418_1418[50] = "";
  s21_sprintf(test_str_1418, "%*f", -20, -123456789.0);
  sprintf(test_str_1418_1418, "%*f", -20, -123456789.0);
  ck_assert_str_eq(test_str_1418, test_str_1418_1418);
}
END_TEST

START_TEST(sprintf_test_1419) {
  char test_str_1419[50] = "";
  char test_str_1419_1419[50] = "";
  s21_sprintf(test_str_1419, "%*f", -20, -0.123456789);
  sprintf(test_str_1419_1419, "%*f", -20, -0.123456789);
  ck_assert_str_eq(test_str_1419, test_str_1419_1419);
}
END_TEST

START_TEST(sprintf_test_1420) {
  char test_str_1420[50] = "";
  char test_str_1420_1420[50] = "";
  s21_sprintf(test_str_1420, "%*f", -20, 123456789.12345679);
  sprintf(test_str_1420_1420, "%*f", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_1420, test_str_1420_1420);
}
END_TEST

START_TEST(sprintf_test_1421) {
  char test_str_1421[50] = "";
  char test_str_1421_1421[50] = "";
  s21_sprintf(test_str_1421, "%*f", -20, -123456789.12345678);
  sprintf(test_str_1421_1421, "%*f", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_1421, test_str_1421_1421);
}
END_TEST

START_TEST(sprintf_test_1422) {
  char test_str_1422[50] = "";
  char test_str_1422_1422[50] = "";
  s21_sprintf(test_str_1422, "%*f", -20, 1.23e-09);
  sprintf(test_str_1422_1422, "%*f", -20, 1.23e-09);
  ck_assert_str_eq(test_str_1422, test_str_1422_1422);
}
END_TEST

START_TEST(sprintf_test_1423) {
  char test_str_1423[50] = "";
  char test_str_1423_1423[50] = "";
  s21_sprintf(test_str_1423, "%*f", -20, 1.23e-09);
  sprintf(test_str_1423_1423, "%*f", -20, 1.23e-09);
  ck_assert_str_eq(test_str_1423, test_str_1423_1423);
}
END_TEST

START_TEST(sprintf_test_1424) {
  char test_str_1424[50] = "";
  char test_str_1424_1424[50] = "";
  s21_sprintf(test_str_1424, "%.10f", 0.0);
  sprintf(test_str_1424_1424, "%.10f", 0.0);
  ck_assert_str_eq(test_str_1424, test_str_1424_1424);
}
END_TEST

START_TEST(sprintf_test_1425) {
  char test_str_1425[50] = "";
  char test_str_1425_1425[50] = "";
  s21_sprintf(test_str_1425, "%.10f", 123456789.0);
  sprintf(test_str_1425_1425, "%.10f", 123456789.0);
  ck_assert_str_eq(test_str_1425, test_str_1425_1425);
}
END_TEST

START_TEST(sprintf_test_1426) {
  char test_str_1426[50] = "";
  char test_str_1426_1426[50] = "";
  s21_sprintf(test_str_1426, "%.10f", 0.123456789);
  sprintf(test_str_1426_1426, "%.10f", 0.123456789);
  ck_assert_str_eq(test_str_1426, test_str_1426_1426);
}
END_TEST

START_TEST(sprintf_test_1427) {
  char test_str_1427[50] = "";
  char test_str_1427_1427[50] = "";
  s21_sprintf(test_str_1427, "%.10f", -123456789.0);
  sprintf(test_str_1427_1427, "%.10f", -123456789.0);
  ck_assert_str_eq(test_str_1427, test_str_1427_1427);
}
END_TEST

START_TEST(sprintf_test_1428) {
  char test_str_1428[50] = "";
  char test_str_1428_1428[50] = "";
  s21_sprintf(test_str_1428, "%.10f", -0.123456789);
  sprintf(test_str_1428_1428, "%.10f", -0.123456789);
  ck_assert_str_eq(test_str_1428, test_str_1428_1428);
}
END_TEST

START_TEST(sprintf_test_1429) {
  char test_str_1429[50] = "";
  char test_str_1429_1429[50] = "";
  s21_sprintf(test_str_1429, "%.10f", 123456789.12345679);
  sprintf(test_str_1429_1429, "%.10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1429, test_str_1429_1429);
}
END_TEST

START_TEST(sprintf_test_1430) {
  char test_str_1430[50] = "";
  char test_str_1430_1430[50] = "";
  s21_sprintf(test_str_1430, "%.10f", -123456789.12345678);
  sprintf(test_str_1430_1430, "%.10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1430, test_str_1430_1430);
}
END_TEST

START_TEST(sprintf_test_1431) {
  char test_str_1431[50] = "";
  char test_str_1431_1431[50] = "";
  s21_sprintf(test_str_1431, "%.10f", 1.23e-09);
  sprintf(test_str_1431_1431, "%.10f", 1.23e-09);
  ck_assert_str_eq(test_str_1431, test_str_1431_1431);
}
END_TEST

START_TEST(sprintf_test_1432) {
  char test_str_1432[50] = "";
  char test_str_1432_1432[50] = "";
  s21_sprintf(test_str_1432, "%.10f", 1.23e-09);
  sprintf(test_str_1432_1432, "%.10f", 1.23e-09);
  ck_assert_str_eq(test_str_1432, test_str_1432_1432);
}
END_TEST

START_TEST(sprintf_test_1433) {
  char test_str_1433[50] = "";
  char test_str_1433_1433[50] = "";
  s21_sprintf(test_str_1433, "%.14f", 0.0);
  sprintf(test_str_1433_1433, "%.14f", 0.0);
  ck_assert_str_eq(test_str_1433, test_str_1433_1433);
}
END_TEST

START_TEST(sprintf_test_1434) {
  char test_str_1434[50] = "";
  char test_str_1434_1434[50] = "";
  s21_sprintf(test_str_1434, "%.14f", 123456789.0);
  sprintf(test_str_1434_1434, "%.14f", 123456789.0);
  ck_assert_str_eq(test_str_1434, test_str_1434_1434);
}
END_TEST

START_TEST(sprintf_test_1435) {
  char test_str_1435[50] = "";
  char test_str_1435_1435[50] = "";
  s21_sprintf(test_str_1435, "%.14f", 0.123456789);
  sprintf(test_str_1435_1435, "%.14f", 0.123456789);
  ck_assert_str_eq(test_str_1435, test_str_1435_1435);
}
END_TEST

START_TEST(sprintf_test_1436) {
  char test_str_1436[50] = "";
  char test_str_1436_1436[50] = "";
  s21_sprintf(test_str_1436, "%.14f", -123456789.0);
  sprintf(test_str_1436_1436, "%.14f", -123456789.0);
  ck_assert_str_eq(test_str_1436, test_str_1436_1436);
}
END_TEST

START_TEST(sprintf_test_1437) {
  char test_str_1437[50] = "";
  char test_str_1437_1437[50] = "";
  s21_sprintf(test_str_1437, "%.14f", -0.123456789);
  sprintf(test_str_1437_1437, "%.14f", -0.123456789);
  ck_assert_str_eq(test_str_1437, test_str_1437_1437);
}
END_TEST

START_TEST(sprintf_test_1438) {
  char test_str_1438[50] = "";
  char test_str_1438_1438[50] = "";
  s21_sprintf(test_str_1438, "%.14f", 123456789.12345679);
  sprintf(test_str_1438_1438, "%.14f", 123456789.12345679);
  ck_assert_str_eq(test_str_1438, test_str_1438_1438);
}
END_TEST

START_TEST(sprintf_test_1439) {
  char test_str_1439[50] = "";
  char test_str_1439_1439[50] = "";
  s21_sprintf(test_str_1439, "%.14f", -123456789.12345678);
  sprintf(test_str_1439_1439, "%.14f", -123456789.12345678);
  ck_assert_str_eq(test_str_1439, test_str_1439_1439);
}
END_TEST

START_TEST(sprintf_test_1440) {
  char test_str_1440[50] = "";
  char test_str_1440_1440[50] = "";
  s21_sprintf(test_str_1440, "%.14f", 1.23e-09);
  sprintf(test_str_1440_1440, "%.14f", 1.23e-09);
  ck_assert_str_eq(test_str_1440, test_str_1440_1440);
}
END_TEST

START_TEST(sprintf_test_1441) {
  char test_str_1441[50] = "";
  char test_str_1441_1441[50] = "";
  s21_sprintf(test_str_1441, "%.14f", 1.23e-09);
  sprintf(test_str_1441_1441, "%.14f", 1.23e-09);
  ck_assert_str_eq(test_str_1441, test_str_1441_1441);
}
END_TEST

START_TEST(sprintf_test_1442) {
  char test_str_1442[50] = "";
  char test_str_1442_1442[50] = "";
  s21_sprintf(test_str_1442, "%.1f", 0.0);
  sprintf(test_str_1442_1442, "%.1f", 0.0);
  ck_assert_str_eq(test_str_1442, test_str_1442_1442);
}
END_TEST

START_TEST(sprintf_test_1443) {
  char test_str_1443[50] = "";
  char test_str_1443_1443[50] = "";
  s21_sprintf(test_str_1443, "%.1f", 123456789.0);
  sprintf(test_str_1443_1443, "%.1f", 123456789.0);
  ck_assert_str_eq(test_str_1443, test_str_1443_1443);
}
END_TEST

START_TEST(sprintf_test_1444) {
  char test_str_1444[50] = "";
  char test_str_1444_1444[50] = "";
  s21_sprintf(test_str_1444, "%.1f", 0.123456789);
  sprintf(test_str_1444_1444, "%.1f", 0.123456789);
  ck_assert_str_eq(test_str_1444, test_str_1444_1444);
}
END_TEST

START_TEST(sprintf_test_1445) {
  char test_str_1445[50] = "";
  char test_str_1445_1445[50] = "";
  s21_sprintf(test_str_1445, "%.1f", -123456789.0);
  sprintf(test_str_1445_1445, "%.1f", -123456789.0);
  ck_assert_str_eq(test_str_1445, test_str_1445_1445);
}
END_TEST

START_TEST(sprintf_test_1446) {
  char test_str_1446[50] = "";
  char test_str_1446_1446[50] = "";
  s21_sprintf(test_str_1446, "%.1f", -0.123456789);
  sprintf(test_str_1446_1446, "%.1f", -0.123456789);
  ck_assert_str_eq(test_str_1446, test_str_1446_1446);
}
END_TEST

START_TEST(sprintf_test_1447) {
  char test_str_1447[50] = "";
  char test_str_1447_1447[50] = "";
  s21_sprintf(test_str_1447, "%.1f", 123456789.12345679);
  sprintf(test_str_1447_1447, "%.1f", 123456789.12345679);
  ck_assert_str_eq(test_str_1447, test_str_1447_1447);
}
END_TEST

START_TEST(sprintf_test_1448) {
  char test_str_1448[50] = "";
  char test_str_1448_1448[50] = "";
  s21_sprintf(test_str_1448, "%.1f", -123456789.12345678);
  sprintf(test_str_1448_1448, "%.1f", -123456789.12345678);
  ck_assert_str_eq(test_str_1448, test_str_1448_1448);
}
END_TEST

START_TEST(sprintf_test_1449) {
  char test_str_1449[50] = "";
  char test_str_1449_1449[50] = "";
  s21_sprintf(test_str_1449, "%.1f", 1.23e-09);
  sprintf(test_str_1449_1449, "%.1f", 1.23e-09);
  ck_assert_str_eq(test_str_1449, test_str_1449_1449);
}
END_TEST

START_TEST(sprintf_test_1450) {
  char test_str_1450[50] = "";
  char test_str_1450_1450[50] = "";
  s21_sprintf(test_str_1450, "%.1f", 1.23e-09);
  sprintf(test_str_1450_1450, "%.1f", 1.23e-09);
  ck_assert_str_eq(test_str_1450, test_str_1450_1450);
}
END_TEST

START_TEST(sprintf_test_1451) {
  char test_str_1451[50] = "";
  char test_str_1451_1451[50] = "";
  s21_sprintf(test_str_1451, "%Lf", (long double)0.0);
  sprintf(test_str_1451_1451, "%Lf", (long double)0.0);
  ck_assert_str_eq(test_str_1451, test_str_1451_1451);
}
END_TEST

START_TEST(sprintf_test_1452) {
  char test_str_1452[50] = "";
  char test_str_1452_1452[50] = "";
  s21_sprintf(test_str_1452, "%Lf", (long double)123456789.0);
  sprintf(test_str_1452_1452, "%Lf", (long double)123456789.0);
  ck_assert_str_eq(test_str_1452, test_str_1452_1452);
}
END_TEST

START_TEST(sprintf_test_1453) {
  char test_str_1453[50] = "";
  char test_str_1453_1453[50] = "";
  s21_sprintf(test_str_1453, "%Lf", (long double)0.123456789);
  sprintf(test_str_1453_1453, "%Lf", (long double)0.123456789);
  ck_assert_str_eq(test_str_1453, test_str_1453_1453);
}
END_TEST

START_TEST(sprintf_test_1454) {
  char test_str_1454[50] = "";
  char test_str_1454_1454[50] = "";
  s21_sprintf(test_str_1454, "%Lf", (long double)-123456789.0);
  sprintf(test_str_1454_1454, "%Lf", (long double)-123456789.0);
  ck_assert_str_eq(test_str_1454, test_str_1454_1454);
}
END_TEST

START_TEST(sprintf_test_1455) {
  char test_str_1455[50] = "";
  char test_str_1455_1455[50] = "";
  s21_sprintf(test_str_1455, "%Lf", (long double)-0.123456789);
  sprintf(test_str_1455_1455, "%Lf", (long double)-0.123456789);
  ck_assert_str_eq(test_str_1455, test_str_1455_1455);
}
END_TEST

START_TEST(sprintf_test_1456) {
  char test_str_1456[50] = "";
  char test_str_1456_1456[50] = "";
  s21_sprintf(test_str_1456, "%Lf", (long double)123456789.12345679);
  sprintf(test_str_1456_1456, "%Lf", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_1456, test_str_1456_1456);
}
END_TEST

START_TEST(sprintf_test_1457) {
  char test_str_1457[50] = "";
  char test_str_1457_1457[50] = "";
  s21_sprintf(test_str_1457, "%Lf", (long double)-123456789.12345678);
  sprintf(test_str_1457_1457, "%Lf", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_1457, test_str_1457_1457);
}
END_TEST

START_TEST(sprintf_test_1458) {
  char test_str_1458[50] = "";
  char test_str_1458_1458[50] = "";
  s21_sprintf(test_str_1458, "%Lf", (long double)1.23e-09);
  sprintf(test_str_1458_1458, "%Lf", (long double)1.23e-09);
  ck_assert_str_eq(test_str_1458, test_str_1458_1458);
}
END_TEST

START_TEST(sprintf_test_1459) {
  char test_str_1459[50] = "";
  char test_str_1459_1459[50] = "";
  s21_sprintf(test_str_1459, "%Lf", (long double)1.23e-09);
  sprintf(test_str_1459_1459, "%Lf", (long double)1.23e-09);
  ck_assert_str_eq(test_str_1459, test_str_1459_1459);
}
END_TEST

START_TEST(sprintf_test_1460) {
  char test_str_1460[50] = "";
  char test_str_1460_1460[50] = "";
  s21_sprintf(test_str_1460, "%-e", 0.0);
  sprintf(test_str_1460_1460, "%-e", 0.0);
  ck_assert_str_eq(test_str_1460, test_str_1460_1460);
}
END_TEST

START_TEST(sprintf_test_1461) {
  char test_str_1461[50] = "";
  char test_str_1461_1461[50] = "";
  s21_sprintf(test_str_1461, "%-e", 123456789.0);
  sprintf(test_str_1461_1461, "%-e", 123456789.0);
  ck_assert_str_eq(test_str_1461, test_str_1461_1461);
}
END_TEST

START_TEST(sprintf_test_1462) {
  char test_str_1462[50] = "";
  char test_str_1462_1462[50] = "";
  s21_sprintf(test_str_1462, "%-e", 0.123456789);
  sprintf(test_str_1462_1462, "%-e", 0.123456789);
  ck_assert_str_eq(test_str_1462, test_str_1462_1462);
}
END_TEST

START_TEST(sprintf_test_1463) {
  char test_str_1463[50] = "";
  char test_str_1463_1463[50] = "";
  s21_sprintf(test_str_1463, "%-e", -123456789.0);
  sprintf(test_str_1463_1463, "%-e", -123456789.0);
  ck_assert_str_eq(test_str_1463, test_str_1463_1463);
}
END_TEST

START_TEST(sprintf_test_1464) {
  char test_str_1464[50] = "";
  char test_str_1464_1464[50] = "";
  s21_sprintf(test_str_1464, "%-e", -0.123456789);
  sprintf(test_str_1464_1464, "%-e", -0.123456789);
  ck_assert_str_eq(test_str_1464, test_str_1464_1464);
}
END_TEST

START_TEST(sprintf_test_1465) {
  char test_str_1465[50] = "";
  char test_str_1465_1465[50] = "";
  s21_sprintf(test_str_1465, "%-e", 123456789.12345679);
  sprintf(test_str_1465_1465, "%-e", 123456789.12345679);
  ck_assert_str_eq(test_str_1465, test_str_1465_1465);
}
END_TEST

START_TEST(sprintf_test_1466) {
  char test_str_1466[50] = "";
  char test_str_1466_1466[50] = "";
  s21_sprintf(test_str_1466, "%-e", -123456789.12345678);
  sprintf(test_str_1466_1466, "%-e", -123456789.12345678);
  ck_assert_str_eq(test_str_1466, test_str_1466_1466);
}
END_TEST

START_TEST(sprintf_test_1467) {
  char test_str_1467[50] = "";
  char test_str_1467_1467[50] = "";
  s21_sprintf(test_str_1467, "%-e", 1.23e-09);
  sprintf(test_str_1467_1467, "%-e", 1.23e-09);
  ck_assert_str_eq(test_str_1467, test_str_1467_1467);
}
END_TEST

START_TEST(sprintf_test_1468) {
  char test_str_1468[50] = "";
  char test_str_1468_1468[50] = "";
  s21_sprintf(test_str_1468, "%-e", 1.23e-09);
  sprintf(test_str_1468_1468, "%-e", 1.23e-09);
  ck_assert_str_eq(test_str_1468, test_str_1468_1468);
}
END_TEST

START_TEST(sprintf_test_1469) {
  char test_str_1469[50] = "";
  char test_str_1469_1469[50] = "";
  s21_sprintf(test_str_1469, "%-E", 0.0);
  sprintf(test_str_1469_1469, "%-E", 0.0);
  ck_assert_str_eq(test_str_1469, test_str_1469_1469);
}
END_TEST

START_TEST(sprintf_test_1470) {
  char test_str_1470[50] = "";
  char test_str_1470_1470[50] = "";
  s21_sprintf(test_str_1470, "%-E", 123456789.0);
  sprintf(test_str_1470_1470, "%-E", 123456789.0);
  ck_assert_str_eq(test_str_1470, test_str_1470_1470);
}
END_TEST

START_TEST(sprintf_test_1471) {
  char test_str_1471[50] = "";
  char test_str_1471_1471[50] = "";
  s21_sprintf(test_str_1471, "%-E", 0.123456789);
  sprintf(test_str_1471_1471, "%-E", 0.123456789);
  ck_assert_str_eq(test_str_1471, test_str_1471_1471);
}
END_TEST

START_TEST(sprintf_test_1472) {
  char test_str_1472[50] = "";
  char test_str_1472_1472[50] = "";
  s21_sprintf(test_str_1472, "%-E", -123456789.0);
  sprintf(test_str_1472_1472, "%-E", -123456789.0);
  ck_assert_str_eq(test_str_1472, test_str_1472_1472);
}
END_TEST

START_TEST(sprintf_test_1473) {
  char test_str_1473[50] = "";
  char test_str_1473_1473[50] = "";
  s21_sprintf(test_str_1473, "%-E", -0.123456789);
  sprintf(test_str_1473_1473, "%-E", -0.123456789);
  ck_assert_str_eq(test_str_1473, test_str_1473_1473);
}
END_TEST

START_TEST(sprintf_test_1474) {
  char test_str_1474[50] = "";
  char test_str_1474_1474[50] = "";
  s21_sprintf(test_str_1474, "%-E", 123456789.12345679);
  sprintf(test_str_1474_1474, "%-E", 123456789.12345679);
  ck_assert_str_eq(test_str_1474, test_str_1474_1474);
}
END_TEST

START_TEST(sprintf_test_1475) {
  char test_str_1475[50] = "";
  char test_str_1475_1475[50] = "";
  s21_sprintf(test_str_1475, "%-E", -123456789.12345678);
  sprintf(test_str_1475_1475, "%-E", -123456789.12345678);
  ck_assert_str_eq(test_str_1475, test_str_1475_1475);
}
END_TEST

START_TEST(sprintf_test_1476) {
  char test_str_1476[50] = "";
  char test_str_1476_1476[50] = "";
  s21_sprintf(test_str_1476, "%-E", 1.23e-09);
  sprintf(test_str_1476_1476, "%-E", 1.23e-09);
  ck_assert_str_eq(test_str_1476, test_str_1476_1476);
}
END_TEST

START_TEST(sprintf_test_1477) {
  char test_str_1477[50] = "";
  char test_str_1477_1477[50] = "";
  s21_sprintf(test_str_1477, "%-E", 1.23e-09);
  sprintf(test_str_1477_1477, "%-E", 1.23e-09);
  ck_assert_str_eq(test_str_1477, test_str_1477_1477);
}
END_TEST

START_TEST(sprintf_test_1478) {
  char test_str_1478[50] = "";
  char test_str_1478_1478[50] = "";
  s21_sprintf(test_str_1478, "%+e", 0.0);
  sprintf(test_str_1478_1478, "%+e", 0.0);
  ck_assert_str_eq(test_str_1478, test_str_1478_1478);
}
END_TEST

START_TEST(sprintf_test_1479) {
  char test_str_1479[50] = "";
  char test_str_1479_1479[50] = "";
  s21_sprintf(test_str_1479, "%+e", 123456789.0);
  sprintf(test_str_1479_1479, "%+e", 123456789.0);
  ck_assert_str_eq(test_str_1479, test_str_1479_1479);
}
END_TEST

START_TEST(sprintf_test_1480) {
  char test_str_1480[50] = "";
  char test_str_1480_1480[50] = "";
  s21_sprintf(test_str_1480, "%+e", 0.123456789);
  sprintf(test_str_1480_1480, "%+e", 0.123456789);
  ck_assert_str_eq(test_str_1480, test_str_1480_1480);
}
END_TEST

START_TEST(sprintf_test_1481) {
  char test_str_1481[50] = "";
  char test_str_1481_1481[50] = "";
  s21_sprintf(test_str_1481, "%+e", -123456789.0);
  sprintf(test_str_1481_1481, "%+e", -123456789.0);
  ck_assert_str_eq(test_str_1481, test_str_1481_1481);
}
END_TEST

START_TEST(sprintf_test_1482) {
  char test_str_1482[50] = "";
  char test_str_1482_1482[50] = "";
  s21_sprintf(test_str_1482, "%+e", -0.123456789);
  sprintf(test_str_1482_1482, "%+e", -0.123456789);
  ck_assert_str_eq(test_str_1482, test_str_1482_1482);
}
END_TEST

START_TEST(sprintf_test_1483) {
  char test_str_1483[50] = "";
  char test_str_1483_1483[50] = "";
  s21_sprintf(test_str_1483, "%+e", 123456789.12345679);
  sprintf(test_str_1483_1483, "%+e", 123456789.12345679);
  ck_assert_str_eq(test_str_1483, test_str_1483_1483);
}
END_TEST

START_TEST(sprintf_test_1484) {
  char test_str_1484[50] = "";
  char test_str_1484_1484[50] = "";
  s21_sprintf(test_str_1484, "%+e", -123456789.12345678);
  sprintf(test_str_1484_1484, "%+e", -123456789.12345678);
  ck_assert_str_eq(test_str_1484, test_str_1484_1484);
}
END_TEST

START_TEST(sprintf_test_1485) {
  char test_str_1485[50] = "";
  char test_str_1485_1485[50] = "";
  s21_sprintf(test_str_1485, "%+e", 1.23e-09);
  sprintf(test_str_1485_1485, "%+e", 1.23e-09);
  ck_assert_str_eq(test_str_1485, test_str_1485_1485);
}
END_TEST

START_TEST(sprintf_test_1486) {
  char test_str_1486[50] = "";
  char test_str_1486_1486[50] = "";
  s21_sprintf(test_str_1486, "%+e", 1.23e-09);
  sprintf(test_str_1486_1486, "%+e", 1.23e-09);
  ck_assert_str_eq(test_str_1486, test_str_1486_1486);
}
END_TEST

START_TEST(sprintf_test_1487) {
  char test_str_1487[50] = "";
  char test_str_1487_1487[50] = "";
  s21_sprintf(test_str_1487, "%+E", 0.0);
  sprintf(test_str_1487_1487, "%+E", 0.0);
  ck_assert_str_eq(test_str_1487, test_str_1487_1487);
}
END_TEST

START_TEST(sprintf_test_1488) {
  char test_str_1488[50] = "";
  char test_str_1488_1488[50] = "";
  s21_sprintf(test_str_1488, "%+E", 123456789.0);
  sprintf(test_str_1488_1488, "%+E", 123456789.0);
  ck_assert_str_eq(test_str_1488, test_str_1488_1488);
}
END_TEST

START_TEST(sprintf_test_1489) {
  char test_str_1489[50] = "";
  char test_str_1489_1489[50] = "";
  s21_sprintf(test_str_1489, "%+E", 0.123456789);
  sprintf(test_str_1489_1489, "%+E", 0.123456789);
  ck_assert_str_eq(test_str_1489, test_str_1489_1489);
}
END_TEST

START_TEST(sprintf_test_1490) {
  char test_str_1490[50] = "";
  char test_str_1490_1490[50] = "";
  s21_sprintf(test_str_1490, "%+E", -123456789.0);
  sprintf(test_str_1490_1490, "%+E", -123456789.0);
  ck_assert_str_eq(test_str_1490, test_str_1490_1490);
}
END_TEST

START_TEST(sprintf_test_1491) {
  char test_str_1491[50] = "";
  char test_str_1491_1491[50] = "";
  s21_sprintf(test_str_1491, "%+E", -0.123456789);
  sprintf(test_str_1491_1491, "%+E", -0.123456789);
  ck_assert_str_eq(test_str_1491, test_str_1491_1491);
}
END_TEST

START_TEST(sprintf_test_1492) {
  char test_str_1492[50] = "";
  char test_str_1492_1492[50] = "";
  s21_sprintf(test_str_1492, "%+E", 123456789.12345679);
  sprintf(test_str_1492_1492, "%+E", 123456789.12345679);
  ck_assert_str_eq(test_str_1492, test_str_1492_1492);
}
END_TEST

START_TEST(sprintf_test_1493) {
  char test_str_1493[50] = "";
  char test_str_1493_1493[50] = "";
  s21_sprintf(test_str_1493, "%+E", -123456789.12345678);
  sprintf(test_str_1493_1493, "%+E", -123456789.12345678);
  ck_assert_str_eq(test_str_1493, test_str_1493_1493);
}
END_TEST

START_TEST(sprintf_test_1494) {
  char test_str_1494[50] = "";
  char test_str_1494_1494[50] = "";
  s21_sprintf(test_str_1494, "%+E", 1.23e-09);
  sprintf(test_str_1494_1494, "%+E", 1.23e-09);
  ck_assert_str_eq(test_str_1494, test_str_1494_1494);
}
END_TEST

START_TEST(sprintf_test_1495) {
  char test_str_1495[50] = "";
  char test_str_1495_1495[50] = "";
  s21_sprintf(test_str_1495, "%+E", 1.23e-09);
  sprintf(test_str_1495_1495, "%+E", 1.23e-09);
  ck_assert_str_eq(test_str_1495, test_str_1495_1495);
}
END_TEST

START_TEST(sprintf_test_1496) {
  char test_str_1496[50] = "";
  char test_str_1496_1496[50] = "";
  s21_sprintf(test_str_1496, "% e", 0.0);
  sprintf(test_str_1496_1496, "% e", 0.0);
  ck_assert_str_eq(test_str_1496, test_str_1496_1496);
}
END_TEST

START_TEST(sprintf_test_1497) {
  char test_str_1497[50] = "";
  char test_str_1497_1497[50] = "";
  s21_sprintf(test_str_1497, "% e", 123456789.0);
  sprintf(test_str_1497_1497, "% e", 123456789.0);
  ck_assert_str_eq(test_str_1497, test_str_1497_1497);
}
END_TEST

START_TEST(sprintf_test_1498) {
  char test_str_1498[50] = "";
  char test_str_1498_1498[50] = "";
  s21_sprintf(test_str_1498, "% e", 0.123456789);
  sprintf(test_str_1498_1498, "% e", 0.123456789);
  ck_assert_str_eq(test_str_1498, test_str_1498_1498);
}
END_TEST

START_TEST(sprintf_test_1499) {
  char test_str_1499[50] = "";
  char test_str_1499_1499[50] = "";
  s21_sprintf(test_str_1499, "% e", -123456789.0);
  sprintf(test_str_1499_1499, "% e", -123456789.0);
  ck_assert_str_eq(test_str_1499, test_str_1499_1499);
}
END_TEST

START_TEST(sprintf_test_1500) {
  char test_str_1500[50] = "";
  char test_str_1500_1500[50] = "";
  s21_sprintf(test_str_1500, "% e", -0.123456789);
  sprintf(test_str_1500_1500, "% e", -0.123456789);
  ck_assert_str_eq(test_str_1500, test_str_1500_1500);
}
END_TEST

START_TEST(sprintf_test_1501) {
  char test_str_1501[50] = "";
  char test_str_1501_1501[50] = "";
  s21_sprintf(test_str_1501, "% e", 123456789.12345679);
  sprintf(test_str_1501_1501, "% e", 123456789.12345679);
  ck_assert_str_eq(test_str_1501, test_str_1501_1501);
}
END_TEST

START_TEST(sprintf_test_1502) {
  char test_str_1502[50] = "";
  char test_str_1502_1502[50] = "";
  s21_sprintf(test_str_1502, "% e", -123456789.12345678);
  sprintf(test_str_1502_1502, "% e", -123456789.12345678);
  ck_assert_str_eq(test_str_1502, test_str_1502_1502);
}
END_TEST

START_TEST(sprintf_test_1503) {
  char test_str_1503[50] = "";
  char test_str_1503_1503[50] = "";
  s21_sprintf(test_str_1503, "% e", 1.23e-09);
  sprintf(test_str_1503_1503, "% e", 1.23e-09);
  ck_assert_str_eq(test_str_1503, test_str_1503_1503);
}
END_TEST

START_TEST(sprintf_test_1504) {
  char test_str_1504[50] = "";
  char test_str_1504_1504[50] = "";
  s21_sprintf(test_str_1504, "% e", 1.23e-09);
  sprintf(test_str_1504_1504, "% e", 1.23e-09);
  ck_assert_str_eq(test_str_1504, test_str_1504_1504);
}
END_TEST

START_TEST(sprintf_test_1505) {
  char test_str_1505[50] = "";
  char test_str_1505_1505[50] = "";
  s21_sprintf(test_str_1505, "% E", 0.0);
  sprintf(test_str_1505_1505, "% E", 0.0);
  ck_assert_str_eq(test_str_1505, test_str_1505_1505);
}
END_TEST

START_TEST(sprintf_test_1506) {
  char test_str_1506[50] = "";
  char test_str_1506_1506[50] = "";
  s21_sprintf(test_str_1506, "% E", 123456789.0);
  sprintf(test_str_1506_1506, "% E", 123456789.0);
  ck_assert_str_eq(test_str_1506, test_str_1506_1506);
}
END_TEST

START_TEST(sprintf_test_1507) {
  char test_str_1507[50] = "";
  char test_str_1507_1507[50] = "";
  s21_sprintf(test_str_1507, "% E", 0.123456789);
  sprintf(test_str_1507_1507, "% E", 0.123456789);
  ck_assert_str_eq(test_str_1507, test_str_1507_1507);
}
END_TEST

START_TEST(sprintf_test_1508) {
  char test_str_1508[50] = "";
  char test_str_1508_1508[50] = "";
  s21_sprintf(test_str_1508, "% E", -123456789.0);
  sprintf(test_str_1508_1508, "% E", -123456789.0);
  ck_assert_str_eq(test_str_1508, test_str_1508_1508);
}
END_TEST

START_TEST(sprintf_test_1509) {
  char test_str_1509[50] = "";
  char test_str_1509_1509[50] = "";
  s21_sprintf(test_str_1509, "% E", -0.123456789);
  sprintf(test_str_1509_1509, "% E", -0.123456789);
  ck_assert_str_eq(test_str_1509, test_str_1509_1509);
}
END_TEST

START_TEST(sprintf_test_1510) {
  char test_str_1510[50] = "";
  char test_str_1510_1510[50] = "";
  s21_sprintf(test_str_1510, "% E", 123456789.12345679);
  sprintf(test_str_1510_1510, "% E", 123456789.12345679);
  ck_assert_str_eq(test_str_1510, test_str_1510_1510);
}
END_TEST

START_TEST(sprintf_test_1511) {
  char test_str_1511[50] = "";
  char test_str_1511_1511[50] = "";
  s21_sprintf(test_str_1511, "% E", -123456789.12345678);
  sprintf(test_str_1511_1511, "% E", -123456789.12345678);
  ck_assert_str_eq(test_str_1511, test_str_1511_1511);
}
END_TEST

START_TEST(sprintf_test_1512) {
  char test_str_1512[50] = "";
  char test_str_1512_1512[50] = "";
  s21_sprintf(test_str_1512, "% E", 1.23e-09);
  sprintf(test_str_1512_1512, "% E", 1.23e-09);
  ck_assert_str_eq(test_str_1512, test_str_1512_1512);
}
END_TEST

START_TEST(sprintf_test_1513) {
  char test_str_1513[50] = "";
  char test_str_1513_1513[50] = "";
  s21_sprintf(test_str_1513, "% E", 1.23e-09);
  sprintf(test_str_1513_1513, "% E", 1.23e-09);
  ck_assert_str_eq(test_str_1513, test_str_1513_1513);
}
END_TEST

START_TEST(sprintf_test_1514) {
  char test_str_1514[50] = "";
  char test_str_1514_1514[50] = "";
  s21_sprintf(test_str_1514, "%#e", 0.0);
  sprintf(test_str_1514_1514, "%#e", 0.0);
  ck_assert_str_eq(test_str_1514, test_str_1514_1514);
}
END_TEST

START_TEST(sprintf_test_1515) {
  char test_str_1515[50] = "";
  char test_str_1515_1515[50] = "";
  s21_sprintf(test_str_1515, "%#e", 123456789.0);
  sprintf(test_str_1515_1515, "%#e", 123456789.0);
  ck_assert_str_eq(test_str_1515, test_str_1515_1515);
}
END_TEST

START_TEST(sprintf_test_1516) {
  char test_str_1516[50] = "";
  char test_str_1516_1516[50] = "";
  s21_sprintf(test_str_1516, "%#e", 0.123456789);
  sprintf(test_str_1516_1516, "%#e", 0.123456789);
  ck_assert_str_eq(test_str_1516, test_str_1516_1516);
}
END_TEST

START_TEST(sprintf_test_1517) {
  char test_str_1517[50] = "";
  char test_str_1517_1517[50] = "";
  s21_sprintf(test_str_1517, "%#e", -123456789.0);
  sprintf(test_str_1517_1517, "%#e", -123456789.0);
  ck_assert_str_eq(test_str_1517, test_str_1517_1517);
}
END_TEST

START_TEST(sprintf_test_1518) {
  char test_str_1518[50] = "";
  char test_str_1518_1518[50] = "";
  s21_sprintf(test_str_1518, "%#e", -0.123456789);
  sprintf(test_str_1518_1518, "%#e", -0.123456789);
  ck_assert_str_eq(test_str_1518, test_str_1518_1518);
}
END_TEST

START_TEST(sprintf_test_1519) {
  char test_str_1519[50] = "";
  char test_str_1519_1519[50] = "";
  s21_sprintf(test_str_1519, "%#e", 123456789.12345679);
  sprintf(test_str_1519_1519, "%#e", 123456789.12345679);
  ck_assert_str_eq(test_str_1519, test_str_1519_1519);
}
END_TEST

START_TEST(sprintf_test_1520) {
  char test_str_1520[50] = "";
  char test_str_1520_1520[50] = "";
  s21_sprintf(test_str_1520, "%#e", -123456789.12345678);
  sprintf(test_str_1520_1520, "%#e", -123456789.12345678);
  ck_assert_str_eq(test_str_1520, test_str_1520_1520);
}
END_TEST

START_TEST(sprintf_test_1521) {
  char test_str_1521[50] = "";
  char test_str_1521_1521[50] = "";
  s21_sprintf(test_str_1521, "%#e", 1.23e-09);
  sprintf(test_str_1521_1521, "%#e", 1.23e-09);
  ck_assert_str_eq(test_str_1521, test_str_1521_1521);
}
END_TEST

START_TEST(sprintf_test_1522) {
  char test_str_1522[50] = "";
  char test_str_1522_1522[50] = "";
  s21_sprintf(test_str_1522, "%#e", 1.23e-09);
  sprintf(test_str_1522_1522, "%#e", 1.23e-09);
  ck_assert_str_eq(test_str_1522, test_str_1522_1522);
}
END_TEST

START_TEST(sprintf_test_1523) {
  char test_str_1523[50] = "";
  char test_str_1523_1523[50] = "";
  s21_sprintf(test_str_1523, "%#E", 0.0);
  sprintf(test_str_1523_1523, "%#E", 0.0);
  ck_assert_str_eq(test_str_1523, test_str_1523_1523);
}
END_TEST

START_TEST(sprintf_test_1524) {
  char test_str_1524[50] = "";
  char test_str_1524_1524[50] = "";
  s21_sprintf(test_str_1524, "%#E", 123456789.0);
  sprintf(test_str_1524_1524, "%#E", 123456789.0);
  ck_assert_str_eq(test_str_1524, test_str_1524_1524);
}
END_TEST

START_TEST(sprintf_test_1525) {
  char test_str_1525[50] = "";
  char test_str_1525_1525[50] = "";
  s21_sprintf(test_str_1525, "%#E", 0.123456789);
  sprintf(test_str_1525_1525, "%#E", 0.123456789);
  ck_assert_str_eq(test_str_1525, test_str_1525_1525);
}
END_TEST

START_TEST(sprintf_test_1526) {
  char test_str_1526[50] = "";
  char test_str_1526_1526[50] = "";
  s21_sprintf(test_str_1526, "%#E", -123456789.0);
  sprintf(test_str_1526_1526, "%#E", -123456789.0);
  ck_assert_str_eq(test_str_1526, test_str_1526_1526);
}
END_TEST

START_TEST(sprintf_test_1527) {
  char test_str_1527[50] = "";
  char test_str_1527_1527[50] = "";
  s21_sprintf(test_str_1527, "%#E", -0.123456789);
  sprintf(test_str_1527_1527, "%#E", -0.123456789);
  ck_assert_str_eq(test_str_1527, test_str_1527_1527);
}
END_TEST

START_TEST(sprintf_test_1528) {
  char test_str_1528[50] = "";
  char test_str_1528_1528[50] = "";
  s21_sprintf(test_str_1528, "%#E", 123456789.12345679);
  sprintf(test_str_1528_1528, "%#E", 123456789.12345679);
  ck_assert_str_eq(test_str_1528, test_str_1528_1528);
}
END_TEST

START_TEST(sprintf_test_1529) {
  char test_str_1529[50] = "";
  char test_str_1529_1529[50] = "";
  s21_sprintf(test_str_1529, "%#E", -123456789.12345678);
  sprintf(test_str_1529_1529, "%#E", -123456789.12345678);
  ck_assert_str_eq(test_str_1529, test_str_1529_1529);
}
END_TEST

START_TEST(sprintf_test_1530) {
  char test_str_1530[50] = "";
  char test_str_1530_1530[50] = "";
  s21_sprintf(test_str_1530, "%#E", 1.23e-09);
  sprintf(test_str_1530_1530, "%#E", 1.23e-09);
  ck_assert_str_eq(test_str_1530, test_str_1530_1530);
}
END_TEST

START_TEST(sprintf_test_1531) {
  char test_str_1531[50] = "";
  char test_str_1531_1531[50] = "";
  s21_sprintf(test_str_1531, "%#E", 1.23e-09);
  sprintf(test_str_1531_1531, "%#E", 1.23e-09);
  ck_assert_str_eq(test_str_1531, test_str_1531_1531);
}
END_TEST

START_TEST(sprintf_test_1532) {
  char test_str_1532[50] = "";
  char test_str_1532_1532[50] = "";
  s21_sprintf(test_str_1532, "%0e", 0.0);
  sprintf(test_str_1532_1532, "%0e", 0.0);
  ck_assert_str_eq(test_str_1532, test_str_1532_1532);
}
END_TEST

START_TEST(sprintf_test_1533) {
  char test_str_1533[50] = "";
  char test_str_1533_1533[50] = "";
  s21_sprintf(test_str_1533, "%0e", 123456789.0);
  sprintf(test_str_1533_1533, "%0e", 123456789.0);
  ck_assert_str_eq(test_str_1533, test_str_1533_1533);
}
END_TEST

START_TEST(sprintf_test_1534) {
  char test_str_1534[50] = "";
  char test_str_1534_1534[50] = "";
  s21_sprintf(test_str_1534, "%0e", 0.123456789);
  sprintf(test_str_1534_1534, "%0e", 0.123456789);
  ck_assert_str_eq(test_str_1534, test_str_1534_1534);
}
END_TEST

START_TEST(sprintf_test_1535) {
  char test_str_1535[50] = "";
  char test_str_1535_1535[50] = "";
  s21_sprintf(test_str_1535, "%0e", -123456789.0);
  sprintf(test_str_1535_1535, "%0e", -123456789.0);
  ck_assert_str_eq(test_str_1535, test_str_1535_1535);
}
END_TEST

START_TEST(sprintf_test_1536) {
  char test_str_1536[50] = "";
  char test_str_1536_1536[50] = "";
  s21_sprintf(test_str_1536, "%0e", -0.123456789);
  sprintf(test_str_1536_1536, "%0e", -0.123456789);
  ck_assert_str_eq(test_str_1536, test_str_1536_1536);
}
END_TEST

START_TEST(sprintf_test_1537) {
  char test_str_1537[50] = "";
  char test_str_1537_1537[50] = "";
  s21_sprintf(test_str_1537, "%0e", 123456789.12345679);
  sprintf(test_str_1537_1537, "%0e", 123456789.12345679);
  ck_assert_str_eq(test_str_1537, test_str_1537_1537);
}
END_TEST

START_TEST(sprintf_test_1538) {
  char test_str_1538[50] = "";
  char test_str_1538_1538[50] = "";
  s21_sprintf(test_str_1538, "%0e", -123456789.12345678);
  sprintf(test_str_1538_1538, "%0e", -123456789.12345678);
  ck_assert_str_eq(test_str_1538, test_str_1538_1538);
}
END_TEST

START_TEST(sprintf_test_1539) {
  char test_str_1539[50] = "";
  char test_str_1539_1539[50] = "";
  s21_sprintf(test_str_1539, "%0e", 1.23e-09);
  sprintf(test_str_1539_1539, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1539, test_str_1539_1539);
}
END_TEST

START_TEST(sprintf_test_1540) {
  char test_str_1540[50] = "";
  char test_str_1540_1540[50] = "";
  s21_sprintf(test_str_1540, "%0e", 1.23e-09);
  sprintf(test_str_1540_1540, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1540, test_str_1540_1540);
}
END_TEST

START_TEST(sprintf_test_1541) {
  char test_str_1541[50] = "";
  char test_str_1541_1541[50] = "";
  s21_sprintf(test_str_1541, "%0E", 0.0);
  sprintf(test_str_1541_1541, "%0E", 0.0);
  ck_assert_str_eq(test_str_1541, test_str_1541_1541);
}
END_TEST

START_TEST(sprintf_test_1542) {
  char test_str_1542[50] = "";
  char test_str_1542_1542[50] = "";
  s21_sprintf(test_str_1542, "%0E", 123456789.0);
  sprintf(test_str_1542_1542, "%0E", 123456789.0);
  ck_assert_str_eq(test_str_1542, test_str_1542_1542);
}
END_TEST

START_TEST(sprintf_test_1543) {
  char test_str_1543[50] = "";
  char test_str_1543_1543[50] = "";
  s21_sprintf(test_str_1543, "%0E", 0.123456789);
  sprintf(test_str_1543_1543, "%0E", 0.123456789);
  ck_assert_str_eq(test_str_1543, test_str_1543_1543);
}
END_TEST

START_TEST(sprintf_test_1544) {
  char test_str_1544[50] = "";
  char test_str_1544_1544[50] = "";
  s21_sprintf(test_str_1544, "%0E", -123456789.0);
  sprintf(test_str_1544_1544, "%0E", -123456789.0);
  ck_assert_str_eq(test_str_1544, test_str_1544_1544);
}
END_TEST

START_TEST(sprintf_test_1545) {
  char test_str_1545[50] = "";
  char test_str_1545_1545[50] = "";
  s21_sprintf(test_str_1545, "%0E", -0.123456789);
  sprintf(test_str_1545_1545, "%0E", -0.123456789);
  ck_assert_str_eq(test_str_1545, test_str_1545_1545);
}
END_TEST

START_TEST(sprintf_test_1546) {
  char test_str_1546[50] = "";
  char test_str_1546_1546[50] = "";
  s21_sprintf(test_str_1546, "%0E", 123456789.12345679);
  sprintf(test_str_1546_1546, "%0E", 123456789.12345679);
  ck_assert_str_eq(test_str_1546, test_str_1546_1546);
}
END_TEST

START_TEST(sprintf_test_1547) {
  char test_str_1547[50] = "";
  char test_str_1547_1547[50] = "";
  s21_sprintf(test_str_1547, "%0E", -123456789.12345678);
  sprintf(test_str_1547_1547, "%0E", -123456789.12345678);
  ck_assert_str_eq(test_str_1547, test_str_1547_1547);
}
END_TEST

START_TEST(sprintf_test_1548) {
  char test_str_1548[50] = "";
  char test_str_1548_1548[50] = "";
  s21_sprintf(test_str_1548, "%0E", 1.23e-09);
  sprintf(test_str_1548_1548, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1548, test_str_1548_1548);
}
END_TEST

START_TEST(sprintf_test_1549) {
  char test_str_1549[50] = "";
  char test_str_1549_1549[50] = "";
  s21_sprintf(test_str_1549, "%0E", 1.23e-09);
  sprintf(test_str_1549_1549, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1549, test_str_1549_1549);
}
END_TEST

START_TEST(sprintf_test_1550) {
  char test_str_1550[50] = "";
  char test_str_1550_1550[50] = "";
  s21_sprintf(test_str_1550, "%0e", 0.0);
  sprintf(test_str_1550_1550, "%0e", 0.0);
  ck_assert_str_eq(test_str_1550, test_str_1550_1550);
}
END_TEST

START_TEST(sprintf_test_1551) {
  char test_str_1551[50] = "";
  char test_str_1551_1551[50] = "";
  s21_sprintf(test_str_1551, "%0e", 123456789.0);
  sprintf(test_str_1551_1551, "%0e", 123456789.0);
  ck_assert_str_eq(test_str_1551, test_str_1551_1551);
}
END_TEST

START_TEST(sprintf_test_1552) {
  char test_str_1552[50] = "";
  char test_str_1552_1552[50] = "";
  s21_sprintf(test_str_1552, "%0e", 0.123456789);
  sprintf(test_str_1552_1552, "%0e", 0.123456789);
  ck_assert_str_eq(test_str_1552, test_str_1552_1552);
}
END_TEST

START_TEST(sprintf_test_1553) {
  char test_str_1553[50] = "";
  char test_str_1553_1553[50] = "";
  s21_sprintf(test_str_1553, "%0e", -123456789.0);
  sprintf(test_str_1553_1553, "%0e", -123456789.0);
  ck_assert_str_eq(test_str_1553, test_str_1553_1553);
}
END_TEST

START_TEST(sprintf_test_1554) {
  char test_str_1554[50] = "";
  char test_str_1554_1554[50] = "";
  s21_sprintf(test_str_1554, "%0e", -0.123456789);
  sprintf(test_str_1554_1554, "%0e", -0.123456789);
  ck_assert_str_eq(test_str_1554, test_str_1554_1554);
}
END_TEST

START_TEST(sprintf_test_1555) {
  char test_str_1555[50] = "";
  char test_str_1555_1555[50] = "";
  s21_sprintf(test_str_1555, "%0e", 123456789.12345679);
  sprintf(test_str_1555_1555, "%0e", 123456789.12345679);
  ck_assert_str_eq(test_str_1555, test_str_1555_1555);
}
END_TEST

START_TEST(sprintf_test_1556) {
  char test_str_1556[50] = "";
  char test_str_1556_1556[50] = "";
  s21_sprintf(test_str_1556, "%0e", -123456789.12345678);
  sprintf(test_str_1556_1556, "%0e", -123456789.12345678);
  ck_assert_str_eq(test_str_1556, test_str_1556_1556);
}
END_TEST

START_TEST(sprintf_test_1557) {
  char test_str_1557[50] = "";
  char test_str_1557_1557[50] = "";
  s21_sprintf(test_str_1557, "%0e", 1.23e-09);
  sprintf(test_str_1557_1557, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1557, test_str_1557_1557);
}
END_TEST

START_TEST(sprintf_test_1558) {
  char test_str_1558[50] = "";
  char test_str_1558_1558[50] = "";
  s21_sprintf(test_str_1558, "%0e", 1.23e-09);
  sprintf(test_str_1558_1558, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1558, test_str_1558_1558);
}
END_TEST

START_TEST(sprintf_test_1559) {
  char test_str_1559[50] = "";
  char test_str_1559_1559[50] = "";
  s21_sprintf(test_str_1559, "%0E", 0.0);
  sprintf(test_str_1559_1559, "%0E", 0.0);
  ck_assert_str_eq(test_str_1559, test_str_1559_1559);
}
END_TEST

START_TEST(sprintf_test_1560) {
  char test_str_1560[50] = "";
  char test_str_1560_1560[50] = "";
  s21_sprintf(test_str_1560, "%0E", 123456789.0);
  sprintf(test_str_1560_1560, "%0E", 123456789.0);
  ck_assert_str_eq(test_str_1560, test_str_1560_1560);
}
END_TEST

START_TEST(sprintf_test_1561) {
  char test_str_1561[50] = "";
  char test_str_1561_1561[50] = "";
  s21_sprintf(test_str_1561, "%0E", 0.123456789);
  sprintf(test_str_1561_1561, "%0E", 0.123456789);
  ck_assert_str_eq(test_str_1561, test_str_1561_1561);
}
END_TEST

START_TEST(sprintf_test_1562) {
  char test_str_1562[50] = "";
  char test_str_1562_1562[50] = "";
  s21_sprintf(test_str_1562, "%0E", -123456789.0);
  sprintf(test_str_1562_1562, "%0E", -123456789.0);
  ck_assert_str_eq(test_str_1562, test_str_1562_1562);
}
END_TEST

START_TEST(sprintf_test_1563) {
  char test_str_1563[50] = "";
  char test_str_1563_1563[50] = "";
  s21_sprintf(test_str_1563, "%0E", -0.123456789);
  sprintf(test_str_1563_1563, "%0E", -0.123456789);
  ck_assert_str_eq(test_str_1563, test_str_1563_1563);
}
END_TEST

START_TEST(sprintf_test_1564) {
  char test_str_1564[50] = "";
  char test_str_1564_1564[50] = "";
  s21_sprintf(test_str_1564, "%0E", 123456789.12345679);
  sprintf(test_str_1564_1564, "%0E", 123456789.12345679);
  ck_assert_str_eq(test_str_1564, test_str_1564_1564);
}
END_TEST

START_TEST(sprintf_test_1565) {
  char test_str_1565[50] = "";
  char test_str_1565_1565[50] = "";
  s21_sprintf(test_str_1565, "%0E", -123456789.12345678);
  sprintf(test_str_1565_1565, "%0E", -123456789.12345678);
  ck_assert_str_eq(test_str_1565, test_str_1565_1565);
}
END_TEST

START_TEST(sprintf_test_1566) {
  char test_str_1566[50] = "";
  char test_str_1566_1566[50] = "";
  s21_sprintf(test_str_1566, "%0E", 1.23e-09);
  sprintf(test_str_1566_1566, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1566, test_str_1566_1566);
}
END_TEST

START_TEST(sprintf_test_1567) {
  char test_str_1567[50] = "";
  char test_str_1567_1567[50] = "";
  s21_sprintf(test_str_1567, "%0E", 1.23e-09);
  sprintf(test_str_1567_1567, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1567, test_str_1567_1567);
}
END_TEST

START_TEST(sprintf_test_1568) {
  char test_str_1568[50] = "";
  char test_str_1568_1568[50] = "";
  s21_sprintf(test_str_1568, "%10e", 0.0);
  sprintf(test_str_1568_1568, "%10e", 0.0);
  ck_assert_str_eq(test_str_1568, test_str_1568_1568);
}
END_TEST

START_TEST(sprintf_test_1569) {
  char test_str_1569[50] = "";
  char test_str_1569_1569[50] = "";
  s21_sprintf(test_str_1569, "%10e", 123456789.0);
  sprintf(test_str_1569_1569, "%10e", 123456789.0);
  ck_assert_str_eq(test_str_1569, test_str_1569_1569);
}
END_TEST

START_TEST(sprintf_test_1570) {
  char test_str_1570[50] = "";
  char test_str_1570_1570[50] = "";
  s21_sprintf(test_str_1570, "%10e", 0.123456789);
  sprintf(test_str_1570_1570, "%10e", 0.123456789);
  ck_assert_str_eq(test_str_1570, test_str_1570_1570);
}
END_TEST

START_TEST(sprintf_test_1571) {
  char test_str_1571[50] = "";
  char test_str_1571_1571[50] = "";
  s21_sprintf(test_str_1571, "%10e", -123456789.0);
  sprintf(test_str_1571_1571, "%10e", -123456789.0);
  ck_assert_str_eq(test_str_1571, test_str_1571_1571);
}
END_TEST

START_TEST(sprintf_test_1572) {
  char test_str_1572[50] = "";
  char test_str_1572_1572[50] = "";
  s21_sprintf(test_str_1572, "%10e", -0.123456789);
  sprintf(test_str_1572_1572, "%10e", -0.123456789);
  ck_assert_str_eq(test_str_1572, test_str_1572_1572);
}
END_TEST

START_TEST(sprintf_test_1573) {
  char test_str_1573[50] = "";
  char test_str_1573_1573[50] = "";
  s21_sprintf(test_str_1573, "%10e", 123456789.12345679);
  sprintf(test_str_1573_1573, "%10e", 123456789.12345679);
  ck_assert_str_eq(test_str_1573, test_str_1573_1573);
}
END_TEST

START_TEST(sprintf_test_1574) {
  char test_str_1574[50] = "";
  char test_str_1574_1574[50] = "";
  s21_sprintf(test_str_1574, "%10e", -123456789.12345678);
  sprintf(test_str_1574_1574, "%10e", -123456789.12345678);
  ck_assert_str_eq(test_str_1574, test_str_1574_1574);
}
END_TEST

START_TEST(sprintf_test_1575) {
  char test_str_1575[50] = "";
  char test_str_1575_1575[50] = "";
  s21_sprintf(test_str_1575, "%10e", 1.23e-09);
  sprintf(test_str_1575_1575, "%10e", 1.23e-09);
  ck_assert_str_eq(test_str_1575, test_str_1575_1575);
}
END_TEST

START_TEST(sprintf_test_1576) {
  char test_str_1576[50] = "";
  char test_str_1576_1576[50] = "";
  s21_sprintf(test_str_1576, "%10e", 1.23e-09);
  sprintf(test_str_1576_1576, "%10e", 1.23e-09);
  ck_assert_str_eq(test_str_1576, test_str_1576_1576);
}
END_TEST

START_TEST(sprintf_test_1577) {
  char test_str_1577[50] = "";
  char test_str_1577_1577[50] = "";
  s21_sprintf(test_str_1577, "%10E", 0.0);
  sprintf(test_str_1577_1577, "%10E", 0.0);
  ck_assert_str_eq(test_str_1577, test_str_1577_1577);
}
END_TEST

START_TEST(sprintf_test_1578) {
  char test_str_1578[50] = "";
  char test_str_1578_1578[50] = "";
  s21_sprintf(test_str_1578, "%10E", 123456789.0);
  sprintf(test_str_1578_1578, "%10E", 123456789.0);
  ck_assert_str_eq(test_str_1578, test_str_1578_1578);
}
END_TEST

START_TEST(sprintf_test_1579) {
  char test_str_1579[50] = "";
  char test_str_1579_1579[50] = "";
  s21_sprintf(test_str_1579, "%10E", 0.123456789);
  sprintf(test_str_1579_1579, "%10E", 0.123456789);
  ck_assert_str_eq(test_str_1579, test_str_1579_1579);
}
END_TEST

START_TEST(sprintf_test_1580) {
  char test_str_1580[50] = "";
  char test_str_1580_1580[50] = "";
  s21_sprintf(test_str_1580, "%10E", -123456789.0);
  sprintf(test_str_1580_1580, "%10E", -123456789.0);
  ck_assert_str_eq(test_str_1580, test_str_1580_1580);
}
END_TEST

START_TEST(sprintf_test_1581) {
  char test_str_1581[50] = "";
  char test_str_1581_1581[50] = "";
  s21_sprintf(test_str_1581, "%10E", -0.123456789);
  sprintf(test_str_1581_1581, "%10E", -0.123456789);
  ck_assert_str_eq(test_str_1581, test_str_1581_1581);
}
END_TEST

START_TEST(sprintf_test_1582) {
  char test_str_1582[50] = "";
  char test_str_1582_1582[50] = "";
  s21_sprintf(test_str_1582, "%10E", 123456789.12345679);
  sprintf(test_str_1582_1582, "%10E", 123456789.12345679);
  ck_assert_str_eq(test_str_1582, test_str_1582_1582);
}
END_TEST

START_TEST(sprintf_test_1583) {
  char test_str_1583[50] = "";
  char test_str_1583_1583[50] = "";
  s21_sprintf(test_str_1583, "%10E", -123456789.12345678);
  sprintf(test_str_1583_1583, "%10E", -123456789.12345678);
  ck_assert_str_eq(test_str_1583, test_str_1583_1583);
}
END_TEST

START_TEST(sprintf_test_1584) {
  char test_str_1584[50] = "";
  char test_str_1584_1584[50] = "";
  s21_sprintf(test_str_1584, "%10E", 1.23e-09);
  sprintf(test_str_1584_1584, "%10E", 1.23e-09);
  ck_assert_str_eq(test_str_1584, test_str_1584_1584);
}
END_TEST

START_TEST(sprintf_test_1585) {
  char test_str_1585[50] = "";
  char test_str_1585_1585[50] = "";
  s21_sprintf(test_str_1585, "%10E", 1.23e-09);
  sprintf(test_str_1585_1585, "%10E", 1.23e-09);
  ck_assert_str_eq(test_str_1585, test_str_1585_1585);
}
END_TEST

START_TEST(sprintf_test_1586) {
  char test_str_1586[50] = "";
  char test_str_1586_1586[50] = "";
  s21_sprintf(test_str_1586, "%20e", 0.0);
  sprintf(test_str_1586_1586, "%20e", 0.0);
  ck_assert_str_eq(test_str_1586, test_str_1586_1586);
}
END_TEST

START_TEST(sprintf_test_1587) {
  char test_str_1587[50] = "";
  char test_str_1587_1587[50] = "";
  s21_sprintf(test_str_1587, "%20e", 123456789.0);
  sprintf(test_str_1587_1587, "%20e", 123456789.0);
  ck_assert_str_eq(test_str_1587, test_str_1587_1587);
}
END_TEST

START_TEST(sprintf_test_1588) {
  char test_str_1588[50] = "";
  char test_str_1588_1588[50] = "";
  s21_sprintf(test_str_1588, "%20e", 0.123456789);
  sprintf(test_str_1588_1588, "%20e", 0.123456789);
  ck_assert_str_eq(test_str_1588, test_str_1588_1588);
}
END_TEST

START_TEST(sprintf_test_1589) {
  char test_str_1589[50] = "";
  char test_str_1589_1589[50] = "";
  s21_sprintf(test_str_1589, "%20e", -123456789.0);
  sprintf(test_str_1589_1589, "%20e", -123456789.0);
  ck_assert_str_eq(test_str_1589, test_str_1589_1589);
}
END_TEST

START_TEST(sprintf_test_1590) {
  char test_str_1590[50] = "";
  char test_str_1590_1590[50] = "";
  s21_sprintf(test_str_1590, "%20e", -0.123456789);
  sprintf(test_str_1590_1590, "%20e", -0.123456789);
  ck_assert_str_eq(test_str_1590, test_str_1590_1590);
}
END_TEST

START_TEST(sprintf_test_1591) {
  char test_str_1591[50] = "";
  char test_str_1591_1591[50] = "";
  s21_sprintf(test_str_1591, "%20e", 123456789.12345679);
  sprintf(test_str_1591_1591, "%20e", 123456789.12345679);
  ck_assert_str_eq(test_str_1591, test_str_1591_1591);
}
END_TEST

START_TEST(sprintf_test_1592) {
  char test_str_1592[50] = "";
  char test_str_1592_1592[50] = "";
  s21_sprintf(test_str_1592, "%20e", -123456789.12345678);
  sprintf(test_str_1592_1592, "%20e", -123456789.12345678);
  ck_assert_str_eq(test_str_1592, test_str_1592_1592);
}
END_TEST

START_TEST(sprintf_test_1593) {
  char test_str_1593[50] = "";
  char test_str_1593_1593[50] = "";
  s21_sprintf(test_str_1593, "%20e", 1.23e-09);
  sprintf(test_str_1593_1593, "%20e", 1.23e-09);
  ck_assert_str_eq(test_str_1593, test_str_1593_1593);
}
END_TEST

START_TEST(sprintf_test_1594) {
  char test_str_1594[50] = "";
  char test_str_1594_1594[50] = "";
  s21_sprintf(test_str_1594, "%20e", 1.23e-09);
  sprintf(test_str_1594_1594, "%20e", 1.23e-09);
  ck_assert_str_eq(test_str_1594, test_str_1594_1594);
}
END_TEST

START_TEST(sprintf_test_1595) {
  char test_str_1595[50] = "";
  char test_str_1595_1595[50] = "";
  s21_sprintf(test_str_1595, "%20E", 0.0);
  sprintf(test_str_1595_1595, "%20E", 0.0);
  ck_assert_str_eq(test_str_1595, test_str_1595_1595);
}
END_TEST

START_TEST(sprintf_test_1596) {
  char test_str_1596[50] = "";
  char test_str_1596_1596[50] = "";
  s21_sprintf(test_str_1596, "%20E", 123456789.0);
  sprintf(test_str_1596_1596, "%20E", 123456789.0);
  ck_assert_str_eq(test_str_1596, test_str_1596_1596);
}
END_TEST

START_TEST(sprintf_test_1597) {
  char test_str_1597[50] = "";
  char test_str_1597_1597[50] = "";
  s21_sprintf(test_str_1597, "%20E", 0.123456789);
  sprintf(test_str_1597_1597, "%20E", 0.123456789);
  ck_assert_str_eq(test_str_1597, test_str_1597_1597);
}
END_TEST

START_TEST(sprintf_test_1598) {
  char test_str_1598[50] = "";
  char test_str_1598_1598[50] = "";
  s21_sprintf(test_str_1598, "%20E", -123456789.0);
  sprintf(test_str_1598_1598, "%20E", -123456789.0);
  ck_assert_str_eq(test_str_1598, test_str_1598_1598);
}
END_TEST

START_TEST(sprintf_test_1599) {
  char test_str_1599[50] = "";
  char test_str_1599_1599[50] = "";
  s21_sprintf(test_str_1599, "%20E", -0.123456789);
  sprintf(test_str_1599_1599, "%20E", -0.123456789);
  ck_assert_str_eq(test_str_1599, test_str_1599_1599);
}
END_TEST

START_TEST(sprintf_test_1600) {
  char test_str_1600[50] = "";
  char test_str_1600_1600[50] = "";
  s21_sprintf(test_str_1600, "%20E", 123456789.12345679);
  sprintf(test_str_1600_1600, "%20E", 123456789.12345679);
  ck_assert_str_eq(test_str_1600, test_str_1600_1600);
}
END_TEST

START_TEST(sprintf_test_1601) {
  char test_str_1601[50] = "";
  char test_str_1601_1601[50] = "";
  s21_sprintf(test_str_1601, "%20E", -123456789.12345678);
  sprintf(test_str_1601_1601, "%20E", -123456789.12345678);
  ck_assert_str_eq(test_str_1601, test_str_1601_1601);
}
END_TEST

START_TEST(sprintf_test_1602) {
  char test_str_1602[50] = "";
  char test_str_1602_1602[50] = "";
  s21_sprintf(test_str_1602, "%20E", 1.23e-09);
  sprintf(test_str_1602_1602, "%20E", 1.23e-09);
  ck_assert_str_eq(test_str_1602, test_str_1602_1602);
}
END_TEST

START_TEST(sprintf_test_1603) {
  char test_str_1603[50] = "";
  char test_str_1603_1603[50] = "";
  s21_sprintf(test_str_1603, "%20E", 1.23e-09);
  sprintf(test_str_1603_1603, "%20E", 1.23e-09);
  ck_assert_str_eq(test_str_1603, test_str_1603_1603);
}
END_TEST

START_TEST(sprintf_test_1604) {
  char test_str_1604[50] = "";
  char test_str_1604_1604[50] = "";
  s21_sprintf(test_str_1604, "%-10e", 0.0);
  sprintf(test_str_1604_1604, "%-10e", 0.0);
  ck_assert_str_eq(test_str_1604, test_str_1604_1604);
}
END_TEST

START_TEST(sprintf_test_1605) {
  char test_str_1605[50] = "";
  char test_str_1605_1605[50] = "";
  s21_sprintf(test_str_1605, "%-10e", 123456789.0);
  sprintf(test_str_1605_1605, "%-10e", 123456789.0);
  ck_assert_str_eq(test_str_1605, test_str_1605_1605);
}
END_TEST

START_TEST(sprintf_test_1606) {
  char test_str_1606[50] = "";
  char test_str_1606_1606[50] = "";
  s21_sprintf(test_str_1606, "%-10e", 0.123456789);
  sprintf(test_str_1606_1606, "%-10e", 0.123456789);
  ck_assert_str_eq(test_str_1606, test_str_1606_1606);
}
END_TEST

START_TEST(sprintf_test_1607) {
  char test_str_1607[50] = "";
  char test_str_1607_1607[50] = "";
  s21_sprintf(test_str_1607, "%-10e", -123456789.0);
  sprintf(test_str_1607_1607, "%-10e", -123456789.0);
  ck_assert_str_eq(test_str_1607, test_str_1607_1607);
}
END_TEST

START_TEST(sprintf_test_1608) {
  char test_str_1608[50] = "";
  char test_str_1608_1608[50] = "";
  s21_sprintf(test_str_1608, "%-10e", -0.123456789);
  sprintf(test_str_1608_1608, "%-10e", -0.123456789);
  ck_assert_str_eq(test_str_1608, test_str_1608_1608);
}
END_TEST

START_TEST(sprintf_test_1609) {
  char test_str_1609[50] = "";
  char test_str_1609_1609[50] = "";
  s21_sprintf(test_str_1609, "%-10e", 123456789.12345679);
  sprintf(test_str_1609_1609, "%-10e", 123456789.12345679);
  ck_assert_str_eq(test_str_1609, test_str_1609_1609);
}
END_TEST

START_TEST(sprintf_test_1610) {
  char test_str_1610[50] = "";
  char test_str_1610_1610[50] = "";
  s21_sprintf(test_str_1610, "%-10e", -123456789.12345678);
  sprintf(test_str_1610_1610, "%-10e", -123456789.12345678);
  ck_assert_str_eq(test_str_1610, test_str_1610_1610);
}
END_TEST

START_TEST(sprintf_test_1611) {
  char test_str_1611[50] = "";
  char test_str_1611_1611[50] = "";
  s21_sprintf(test_str_1611, "%-10e", 1.23e-09);
  sprintf(test_str_1611_1611, "%-10e", 1.23e-09);
  ck_assert_str_eq(test_str_1611, test_str_1611_1611);
}
END_TEST

START_TEST(sprintf_test_1612) {
  char test_str_1612[50] = "";
  char test_str_1612_1612[50] = "";
  s21_sprintf(test_str_1612, "%-10e", 1.23e-09);
  sprintf(test_str_1612_1612, "%-10e", 1.23e-09);
  ck_assert_str_eq(test_str_1612, test_str_1612_1612);
}
END_TEST

START_TEST(sprintf_test_1613) {
  char test_str_1613[50] = "";
  char test_str_1613_1613[50] = "";
  s21_sprintf(test_str_1613, "%-10E", 0.0);
  sprintf(test_str_1613_1613, "%-10E", 0.0);
  ck_assert_str_eq(test_str_1613, test_str_1613_1613);
}
END_TEST

START_TEST(sprintf_test_1614) {
  char test_str_1614[50] = "";
  char test_str_1614_1614[50] = "";
  s21_sprintf(test_str_1614, "%-10E", 123456789.0);
  sprintf(test_str_1614_1614, "%-10E", 123456789.0);
  ck_assert_str_eq(test_str_1614, test_str_1614_1614);
}
END_TEST

START_TEST(sprintf_test_1615) {
  char test_str_1615[50] = "";
  char test_str_1615_1615[50] = "";
  s21_sprintf(test_str_1615, "%-10E", 0.123456789);
  sprintf(test_str_1615_1615, "%-10E", 0.123456789);
  ck_assert_str_eq(test_str_1615, test_str_1615_1615);
}
END_TEST

START_TEST(sprintf_test_1616) {
  char test_str_1616[50] = "";
  char test_str_1616_1616[50] = "";
  s21_sprintf(test_str_1616, "%-10E", -123456789.0);
  sprintf(test_str_1616_1616, "%-10E", -123456789.0);
  ck_assert_str_eq(test_str_1616, test_str_1616_1616);
}
END_TEST

START_TEST(sprintf_test_1617) {
  char test_str_1617[50] = "";
  char test_str_1617_1617[50] = "";
  s21_sprintf(test_str_1617, "%-10E", -0.123456789);
  sprintf(test_str_1617_1617, "%-10E", -0.123456789);
  ck_assert_str_eq(test_str_1617, test_str_1617_1617);
}
END_TEST

START_TEST(sprintf_test_1618) {
  char test_str_1618[50] = "";
  char test_str_1618_1618[50] = "";
  s21_sprintf(test_str_1618, "%-10E", 123456789.12345679);
  sprintf(test_str_1618_1618, "%-10E", 123456789.12345679);
  ck_assert_str_eq(test_str_1618, test_str_1618_1618);
}
END_TEST

START_TEST(sprintf_test_1619) {
  char test_str_1619[50] = "";
  char test_str_1619_1619[50] = "";
  s21_sprintf(test_str_1619, "%-10E", -123456789.12345678);
  sprintf(test_str_1619_1619, "%-10E", -123456789.12345678);
  ck_assert_str_eq(test_str_1619, test_str_1619_1619);
}
END_TEST

START_TEST(sprintf_test_1620) {
  char test_str_1620[50] = "";
  char test_str_1620_1620[50] = "";
  s21_sprintf(test_str_1620, "%-10E", 1.23e-09);
  sprintf(test_str_1620_1620, "%-10E", 1.23e-09);
  ck_assert_str_eq(test_str_1620, test_str_1620_1620);
}
END_TEST

START_TEST(sprintf_test_1621) {
  char test_str_1621[50] = "";
  char test_str_1621_1621[50] = "";
  s21_sprintf(test_str_1621, "%-10E", 1.23e-09);
  sprintf(test_str_1621_1621, "%-10E", 1.23e-09);
  ck_assert_str_eq(test_str_1621, test_str_1621_1621);
}
END_TEST

START_TEST(sprintf_test_1622) {
  char test_str_1622[50] = "";
  char test_str_1622_1622[50] = "";
  s21_sprintf(test_str_1622, "%-20e", 0.0);
  sprintf(test_str_1622_1622, "%-20e", 0.0);
  ck_assert_str_eq(test_str_1622, test_str_1622_1622);
}
END_TEST

START_TEST(sprintf_test_1623) {
  char test_str_1623[50] = "";
  char test_str_1623_1623[50] = "";
  s21_sprintf(test_str_1623, "%-20e", 123456789.0);
  sprintf(test_str_1623_1623, "%-20e", 123456789.0);
  ck_assert_str_eq(test_str_1623, test_str_1623_1623);
}
END_TEST

START_TEST(sprintf_test_1624) {
  char test_str_1624[50] = "";
  char test_str_1624_1624[50] = "";
  s21_sprintf(test_str_1624, "%-20e", 0.123456789);
  sprintf(test_str_1624_1624, "%-20e", 0.123456789);
  ck_assert_str_eq(test_str_1624, test_str_1624_1624);
}
END_TEST

START_TEST(sprintf_test_1625) {
  char test_str_1625[50] = "";
  char test_str_1625_1625[50] = "";
  s21_sprintf(test_str_1625, "%-20e", -123456789.0);
  sprintf(test_str_1625_1625, "%-20e", -123456789.0);
  ck_assert_str_eq(test_str_1625, test_str_1625_1625);
}
END_TEST

START_TEST(sprintf_test_1626) {
  char test_str_1626[50] = "";
  char test_str_1626_1626[50] = "";
  s21_sprintf(test_str_1626, "%-20e", -0.123456789);
  sprintf(test_str_1626_1626, "%-20e", -0.123456789);
  ck_assert_str_eq(test_str_1626, test_str_1626_1626);
}
END_TEST

START_TEST(sprintf_test_1627) {
  char test_str_1627[50] = "";
  char test_str_1627_1627[50] = "";
  s21_sprintf(test_str_1627, "%-20e", 123456789.12345679);
  sprintf(test_str_1627_1627, "%-20e", 123456789.12345679);
  ck_assert_str_eq(test_str_1627, test_str_1627_1627);
}
END_TEST

START_TEST(sprintf_test_1628) {
  char test_str_1628[50] = "";
  char test_str_1628_1628[50] = "";
  s21_sprintf(test_str_1628, "%-20e", -123456789.12345678);
  sprintf(test_str_1628_1628, "%-20e", -123456789.12345678);
  ck_assert_str_eq(test_str_1628, test_str_1628_1628);
}
END_TEST

START_TEST(sprintf_test_1629) {
  char test_str_1629[50] = "";
  char test_str_1629_1629[50] = "";
  s21_sprintf(test_str_1629, "%-20e", 1.23e-09);
  sprintf(test_str_1629_1629, "%-20e", 1.23e-09);
  ck_assert_str_eq(test_str_1629, test_str_1629_1629);
}
END_TEST

START_TEST(sprintf_test_1630) {
  char test_str_1630[50] = "";
  char test_str_1630_1630[50] = "";
  s21_sprintf(test_str_1630, "%-20e", 1.23e-09);
  sprintf(test_str_1630_1630, "%-20e", 1.23e-09);
  ck_assert_str_eq(test_str_1630, test_str_1630_1630);
}
END_TEST

START_TEST(sprintf_test_1631) {
  char test_str_1631[50] = "";
  char test_str_1631_1631[50] = "";
  s21_sprintf(test_str_1631, "%-20E", 0.0);
  sprintf(test_str_1631_1631, "%-20E", 0.0);
  ck_assert_str_eq(test_str_1631, test_str_1631_1631);
}
END_TEST

START_TEST(sprintf_test_1632) {
  char test_str_1632[50] = "";
  char test_str_1632_1632[50] = "";
  s21_sprintf(test_str_1632, "%-20E", 123456789.0);
  sprintf(test_str_1632_1632, "%-20E", 123456789.0);
  ck_assert_str_eq(test_str_1632, test_str_1632_1632);
}
END_TEST

START_TEST(sprintf_test_1633) {
  char test_str_1633[50] = "";
  char test_str_1633_1633[50] = "";
  s21_sprintf(test_str_1633, "%-20E", 0.123456789);
  sprintf(test_str_1633_1633, "%-20E", 0.123456789);
  ck_assert_str_eq(test_str_1633, test_str_1633_1633);
}
END_TEST

START_TEST(sprintf_test_1634) {
  char test_str_1634[50] = "";
  char test_str_1634_1634[50] = "";
  s21_sprintf(test_str_1634, "%-20E", -123456789.0);
  sprintf(test_str_1634_1634, "%-20E", -123456789.0);
  ck_assert_str_eq(test_str_1634, test_str_1634_1634);
}
END_TEST

START_TEST(sprintf_test_1635) {
  char test_str_1635[50] = "";
  char test_str_1635_1635[50] = "";
  s21_sprintf(test_str_1635, "%-20E", -0.123456789);
  sprintf(test_str_1635_1635, "%-20E", -0.123456789);
  ck_assert_str_eq(test_str_1635, test_str_1635_1635);
}
END_TEST

START_TEST(sprintf_test_1636) {
  char test_str_1636[50] = "";
  char test_str_1636_1636[50] = "";
  s21_sprintf(test_str_1636, "%-20E", 123456789.12345679);
  sprintf(test_str_1636_1636, "%-20E", 123456789.12345679);
  ck_assert_str_eq(test_str_1636, test_str_1636_1636);
}
END_TEST

START_TEST(sprintf_test_1637) {
  char test_str_1637[50] = "";
  char test_str_1637_1637[50] = "";
  s21_sprintf(test_str_1637, "%-20E", -123456789.12345678);
  sprintf(test_str_1637_1637, "%-20E", -123456789.12345678);
  ck_assert_str_eq(test_str_1637, test_str_1637_1637);
}
END_TEST

START_TEST(sprintf_test_1638) {
  char test_str_1638[50] = "";
  char test_str_1638_1638[50] = "";
  s21_sprintf(test_str_1638, "%-20E", 1.23e-09);
  sprintf(test_str_1638_1638, "%-20E", 1.23e-09);
  ck_assert_str_eq(test_str_1638, test_str_1638_1638);
}
END_TEST

START_TEST(sprintf_test_1639) {
  char test_str_1639[50] = "";
  char test_str_1639_1639[50] = "";
  s21_sprintf(test_str_1639, "%-20E", 1.23e-09);
  sprintf(test_str_1639_1639, "%-20E", 1.23e-09);
  ck_assert_str_eq(test_str_1639, test_str_1639_1639);
}
END_TEST

START_TEST(sprintf_test_1640) {
  char test_str_1640[50] = "";
  char test_str_1640_1640[50] = "";
  s21_sprintf(test_str_1640, "%*e", 0, 0.0);
  sprintf(test_str_1640_1640, "%*e", 0, 0.0);
  ck_assert_str_eq(test_str_1640, test_str_1640_1640);
}
END_TEST

START_TEST(sprintf_test_1641) {
  char test_str_1641[50] = "";
  char test_str_1641_1641[50] = "";
  s21_sprintf(test_str_1641, "%*e", 0, 123456789.0);
  sprintf(test_str_1641_1641, "%*e", 0, 123456789.0);
  ck_assert_str_eq(test_str_1641, test_str_1641_1641);
}
END_TEST

START_TEST(sprintf_test_1642) {
  char test_str_1642[50] = "";
  char test_str_1642_1642[50] = "";
  s21_sprintf(test_str_1642, "%*e", 0, 0.123456789);
  sprintf(test_str_1642_1642, "%*e", 0, 0.123456789);
  ck_assert_str_eq(test_str_1642, test_str_1642_1642);
}
END_TEST

START_TEST(sprintf_test_1643) {
  char test_str_1643[50] = "";
  char test_str_1643_1643[50] = "";
  s21_sprintf(test_str_1643, "%*e", 0, -123456789.0);
  sprintf(test_str_1643_1643, "%*e", 0, -123456789.0);
  ck_assert_str_eq(test_str_1643, test_str_1643_1643);
}
END_TEST

START_TEST(sprintf_test_1644) {
  char test_str_1644[50] = "";
  char test_str_1644_1644[50] = "";
  s21_sprintf(test_str_1644, "%*e", 0, -0.123456789);
  sprintf(test_str_1644_1644, "%*e", 0, -0.123456789);
  ck_assert_str_eq(test_str_1644, test_str_1644_1644);
}
END_TEST

START_TEST(sprintf_test_1645) {
  char test_str_1645[50] = "";
  char test_str_1645_1645[50] = "";
  s21_sprintf(test_str_1645, "%*e", 0, 123456789.12345679);
  sprintf(test_str_1645_1645, "%*e", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_1645, test_str_1645_1645);
}
END_TEST

START_TEST(sprintf_test_1646) {
  char test_str_1646[50] = "";
  char test_str_1646_1646[50] = "";
  s21_sprintf(test_str_1646, "%*e", 0, -123456789.12345678);
  sprintf(test_str_1646_1646, "%*e", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_1646, test_str_1646_1646);
}
END_TEST

START_TEST(sprintf_test_1647) {
  char test_str_1647[50] = "";
  char test_str_1647_1647[50] = "";
  s21_sprintf(test_str_1647, "%*e", 0, 1.23e-09);
  sprintf(test_str_1647_1647, "%*e", 0, 1.23e-09);
  ck_assert_str_eq(test_str_1647, test_str_1647_1647);
}
END_TEST

START_TEST(sprintf_test_1648) {
  char test_str_1648[50] = "";
  char test_str_1648_1648[50] = "";
  s21_sprintf(test_str_1648, "%*e", 0, 1.23e-09);
  sprintf(test_str_1648_1648, "%*e", 0, 1.23e-09);
  ck_assert_str_eq(test_str_1648, test_str_1648_1648);
}
END_TEST

START_TEST(sprintf_test_1649) {
  char test_str_1649[50] = "";
  char test_str_1649_1649[50] = "";
  s21_sprintf(test_str_1649, "%*E", 0, 0.0);
  sprintf(test_str_1649_1649, "%*E", 0, 0.0);
  ck_assert_str_eq(test_str_1649, test_str_1649_1649);
}
END_TEST

START_TEST(sprintf_test_1650) {
  char test_str_1650[50] = "";
  char test_str_1650_1650[50] = "";
  s21_sprintf(test_str_1650, "%*E", 0, 123456789.0);
  sprintf(test_str_1650_1650, "%*E", 0, 123456789.0);
  ck_assert_str_eq(test_str_1650, test_str_1650_1650);
}
END_TEST

START_TEST(sprintf_test_1651) {
  char test_str_1651[50] = "";
  char test_str_1651_1651[50] = "";
  s21_sprintf(test_str_1651, "%*E", 0, 0.123456789);
  sprintf(test_str_1651_1651, "%*E", 0, 0.123456789);
  ck_assert_str_eq(test_str_1651, test_str_1651_1651);
}
END_TEST

START_TEST(sprintf_test_1652) {
  char test_str_1652[50] = "";
  char test_str_1652_1652[50] = "";
  s21_sprintf(test_str_1652, "%*E", 0, -123456789.0);
  sprintf(test_str_1652_1652, "%*E", 0, -123456789.0);
  ck_assert_str_eq(test_str_1652, test_str_1652_1652);
}
END_TEST

START_TEST(sprintf_test_1653) {
  char test_str_1653[50] = "";
  char test_str_1653_1653[50] = "";
  s21_sprintf(test_str_1653, "%*E", 0, -0.123456789);
  sprintf(test_str_1653_1653, "%*E", 0, -0.123456789);
  ck_assert_str_eq(test_str_1653, test_str_1653_1653);
}
END_TEST

START_TEST(sprintf_test_1654) {
  char test_str_1654[50] = "";
  char test_str_1654_1654[50] = "";
  s21_sprintf(test_str_1654, "%*E", 0, 123456789.12345679);
  sprintf(test_str_1654_1654, "%*E", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_1654, test_str_1654_1654);
}
END_TEST

START_TEST(sprintf_test_1655) {
  char test_str_1655[50] = "";
  char test_str_1655_1655[50] = "";
  s21_sprintf(test_str_1655, "%*E", 0, -123456789.12345678);
  sprintf(test_str_1655_1655, "%*E", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_1655, test_str_1655_1655);
}
END_TEST

START_TEST(sprintf_test_1656) {
  char test_str_1656[50] = "";
  char test_str_1656_1656[50] = "";
  s21_sprintf(test_str_1656, "%*E", 0, 1.23e-09);
  sprintf(test_str_1656_1656, "%*E", 0, 1.23e-09);
  ck_assert_str_eq(test_str_1656, test_str_1656_1656);
}
END_TEST

START_TEST(sprintf_test_1657) {
  char test_str_1657[50] = "";
  char test_str_1657_1657[50] = "";
  s21_sprintf(test_str_1657, "%*E", 0, 1.23e-09);
  sprintf(test_str_1657_1657, "%*E", 0, 1.23e-09);
  ck_assert_str_eq(test_str_1657, test_str_1657_1657);
}
END_TEST

START_TEST(sprintf_test_1658) {
  char test_str_1658[50] = "";
  char test_str_1658_1658[50] = "";
  s21_sprintf(test_str_1658, "%*e", 10, 0.0);
  sprintf(test_str_1658_1658, "%*e", 10, 0.0);
  ck_assert_str_eq(test_str_1658, test_str_1658_1658);
}
END_TEST

START_TEST(sprintf_test_1659) {
  char test_str_1659[50] = "";
  char test_str_1659_1659[50] = "";
  s21_sprintf(test_str_1659, "%*e", 10, 123456789.0);
  sprintf(test_str_1659_1659, "%*e", 10, 123456789.0);
  ck_assert_str_eq(test_str_1659, test_str_1659_1659);
}
END_TEST

START_TEST(sprintf_test_1660) {
  char test_str_1660[50] = "";
  char test_str_1660_1660[50] = "";
  s21_sprintf(test_str_1660, "%*e", 10, 0.123456789);
  sprintf(test_str_1660_1660, "%*e", 10, 0.123456789);
  ck_assert_str_eq(test_str_1660, test_str_1660_1660);
}
END_TEST

START_TEST(sprintf_test_1661) {
  char test_str_1661[50] = "";
  char test_str_1661_1661[50] = "";
  s21_sprintf(test_str_1661, "%*e", 10, -123456789.0);
  sprintf(test_str_1661_1661, "%*e", 10, -123456789.0);
  ck_assert_str_eq(test_str_1661, test_str_1661_1661);
}
END_TEST

START_TEST(sprintf_test_1662) {
  char test_str_1662[50] = "";
  char test_str_1662_1662[50] = "";
  s21_sprintf(test_str_1662, "%*e", 10, -0.123456789);
  sprintf(test_str_1662_1662, "%*e", 10, -0.123456789);
  ck_assert_str_eq(test_str_1662, test_str_1662_1662);
}
END_TEST

START_TEST(sprintf_test_1663) {
  char test_str_1663[50] = "";
  char test_str_1663_1663[50] = "";
  s21_sprintf(test_str_1663, "%*e", 10, 123456789.12345679);
  sprintf(test_str_1663_1663, "%*e", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_1663, test_str_1663_1663);
}
END_TEST

START_TEST(sprintf_test_1664) {
  char test_str_1664[50] = "";
  char test_str_1664_1664[50] = "";
  s21_sprintf(test_str_1664, "%*e", 10, -123456789.12345678);
  sprintf(test_str_1664_1664, "%*e", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_1664, test_str_1664_1664);
}
END_TEST

START_TEST(sprintf_test_1665) {
  char test_str_1665[50] = "";
  char test_str_1665_1665[50] = "";
  s21_sprintf(test_str_1665, "%*e", 10, 1.23e-09);
  sprintf(test_str_1665_1665, "%*e", 10, 1.23e-09);
  ck_assert_str_eq(test_str_1665, test_str_1665_1665);
}
END_TEST

START_TEST(sprintf_test_1666) {
  char test_str_1666[50] = "";
  char test_str_1666_1666[50] = "";
  s21_sprintf(test_str_1666, "%*e", 10, 1.23e-09);
  sprintf(test_str_1666_1666, "%*e", 10, 1.23e-09);
  ck_assert_str_eq(test_str_1666, test_str_1666_1666);
}
END_TEST

START_TEST(sprintf_test_1667) {
  char test_str_1667[50] = "";
  char test_str_1667_1667[50] = "";
  s21_sprintf(test_str_1667, "%*E", 10, 0.0);
  sprintf(test_str_1667_1667, "%*E", 10, 0.0);
  ck_assert_str_eq(test_str_1667, test_str_1667_1667);
}
END_TEST

START_TEST(sprintf_test_1668) {
  char test_str_1668[50] = "";
  char test_str_1668_1668[50] = "";
  s21_sprintf(test_str_1668, "%*E", 10, 123456789.0);
  sprintf(test_str_1668_1668, "%*E", 10, 123456789.0);
  ck_assert_str_eq(test_str_1668, test_str_1668_1668);
}
END_TEST

START_TEST(sprintf_test_1669) {
  char test_str_1669[50] = "";
  char test_str_1669_1669[50] = "";
  s21_sprintf(test_str_1669, "%*E", 10, 0.123456789);
  sprintf(test_str_1669_1669, "%*E", 10, 0.123456789);
  ck_assert_str_eq(test_str_1669, test_str_1669_1669);
}
END_TEST

START_TEST(sprintf_test_1670) {
  char test_str_1670[50] = "";
  char test_str_1670_1670[50] = "";
  s21_sprintf(test_str_1670, "%*E", 10, -123456789.0);
  sprintf(test_str_1670_1670, "%*E", 10, -123456789.0);
  ck_assert_str_eq(test_str_1670, test_str_1670_1670);
}
END_TEST

START_TEST(sprintf_test_1671) {
  char test_str_1671[50] = "";
  char test_str_1671_1671[50] = "";
  s21_sprintf(test_str_1671, "%*E", 10, -0.123456789);
  sprintf(test_str_1671_1671, "%*E", 10, -0.123456789);
  ck_assert_str_eq(test_str_1671, test_str_1671_1671);
}
END_TEST

START_TEST(sprintf_test_1672) {
  char test_str_1672[50] = "";
  char test_str_1672_1672[50] = "";
  s21_sprintf(test_str_1672, "%*E", 10, 123456789.12345679);
  sprintf(test_str_1672_1672, "%*E", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_1672, test_str_1672_1672);
}
END_TEST

START_TEST(sprintf_test_1673) {
  char test_str_1673[50] = "";
  char test_str_1673_1673[50] = "";
  s21_sprintf(test_str_1673, "%*E", 10, -123456789.12345678);
  sprintf(test_str_1673_1673, "%*E", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_1673, test_str_1673_1673);
}
END_TEST

START_TEST(sprintf_test_1674) {
  char test_str_1674[50] = "";
  char test_str_1674_1674[50] = "";
  s21_sprintf(test_str_1674, "%*E", 10, 1.23e-09);
  sprintf(test_str_1674_1674, "%*E", 10, 1.23e-09);
  ck_assert_str_eq(test_str_1674, test_str_1674_1674);
}
END_TEST

START_TEST(sprintf_test_1675) {
  char test_str_1675[50] = "";
  char test_str_1675_1675[50] = "";
  s21_sprintf(test_str_1675, "%*E", 10, 1.23e-09);
  sprintf(test_str_1675_1675, "%*E", 10, 1.23e-09);
  ck_assert_str_eq(test_str_1675, test_str_1675_1675);
}
END_TEST

START_TEST(sprintf_test_1676) {
  char test_str_1676[50] = "";
  char test_str_1676_1676[50] = "";
  s21_sprintf(test_str_1676, "%*e", 20, 0.0);
  sprintf(test_str_1676_1676, "%*e", 20, 0.0);
  ck_assert_str_eq(test_str_1676, test_str_1676_1676);
}
END_TEST

START_TEST(sprintf_test_1677) {
  char test_str_1677[50] = "";
  char test_str_1677_1677[50] = "";
  s21_sprintf(test_str_1677, "%*e", 20, 123456789.0);
  sprintf(test_str_1677_1677, "%*e", 20, 123456789.0);
  ck_assert_str_eq(test_str_1677, test_str_1677_1677);
}
END_TEST

START_TEST(sprintf_test_1678) {
  char test_str_1678[50] = "";
  char test_str_1678_1678[50] = "";
  s21_sprintf(test_str_1678, "%*e", 20, 0.123456789);
  sprintf(test_str_1678_1678, "%*e", 20, 0.123456789);
  ck_assert_str_eq(test_str_1678, test_str_1678_1678);
}
END_TEST

START_TEST(sprintf_test_1679) {
  char test_str_1679[50] = "";
  char test_str_1679_1679[50] = "";
  s21_sprintf(test_str_1679, "%*e", 20, -123456789.0);
  sprintf(test_str_1679_1679, "%*e", 20, -123456789.0);
  ck_assert_str_eq(test_str_1679, test_str_1679_1679);
}
END_TEST

START_TEST(sprintf_test_1680) {
  char test_str_1680[50] = "";
  char test_str_1680_1680[50] = "";
  s21_sprintf(test_str_1680, "%*e", 20, -0.123456789);
  sprintf(test_str_1680_1680, "%*e", 20, -0.123456789);
  ck_assert_str_eq(test_str_1680, test_str_1680_1680);
}
END_TEST

START_TEST(sprintf_test_1681) {
  char test_str_1681[50] = "";
  char test_str_1681_1681[50] = "";
  s21_sprintf(test_str_1681, "%*e", 20, 123456789.12345679);
  sprintf(test_str_1681_1681, "%*e", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_1681, test_str_1681_1681);
}
END_TEST

START_TEST(sprintf_test_1682) {
  char test_str_1682[50] = "";
  char test_str_1682_1682[50] = "";
  s21_sprintf(test_str_1682, "%*e", 20, -123456789.12345678);
  sprintf(test_str_1682_1682, "%*e", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_1682, test_str_1682_1682);
}
END_TEST

START_TEST(sprintf_test_1683) {
  char test_str_1683[50] = "";
  char test_str_1683_1683[50] = "";
  s21_sprintf(test_str_1683, "%*e", 20, 1.23e-09);
  sprintf(test_str_1683_1683, "%*e", 20, 1.23e-09);
  ck_assert_str_eq(test_str_1683, test_str_1683_1683);
}
END_TEST

START_TEST(sprintf_test_1684) {
  char test_str_1684[50] = "";
  char test_str_1684_1684[50] = "";
  s21_sprintf(test_str_1684, "%*e", 20, 1.23e-09);
  sprintf(test_str_1684_1684, "%*e", 20, 1.23e-09);
  ck_assert_str_eq(test_str_1684, test_str_1684_1684);
}
END_TEST

START_TEST(sprintf_test_1685) {
  char test_str_1685[50] = "";
  char test_str_1685_1685[50] = "";
  s21_sprintf(test_str_1685, "%*E", 20, 0.0);
  sprintf(test_str_1685_1685, "%*E", 20, 0.0);
  ck_assert_str_eq(test_str_1685, test_str_1685_1685);
}
END_TEST

START_TEST(sprintf_test_1686) {
  char test_str_1686[50] = "";
  char test_str_1686_1686[50] = "";
  s21_sprintf(test_str_1686, "%*E", 20, 123456789.0);
  sprintf(test_str_1686_1686, "%*E", 20, 123456789.0);
  ck_assert_str_eq(test_str_1686, test_str_1686_1686);
}
END_TEST

START_TEST(sprintf_test_1687) {
  char test_str_1687[50] = "";
  char test_str_1687_1687[50] = "";
  s21_sprintf(test_str_1687, "%*E", 20, 0.123456789);
  sprintf(test_str_1687_1687, "%*E", 20, 0.123456789);
  ck_assert_str_eq(test_str_1687, test_str_1687_1687);
}
END_TEST

START_TEST(sprintf_test_1688) {
  char test_str_1688[50] = "";
  char test_str_1688_1688[50] = "";
  s21_sprintf(test_str_1688, "%*E", 20, -123456789.0);
  sprintf(test_str_1688_1688, "%*E", 20, -123456789.0);
  ck_assert_str_eq(test_str_1688, test_str_1688_1688);
}
END_TEST

START_TEST(sprintf_test_1689) {
  char test_str_1689[50] = "";
  char test_str_1689_1689[50] = "";
  s21_sprintf(test_str_1689, "%*E", 20, -0.123456789);
  sprintf(test_str_1689_1689, "%*E", 20, -0.123456789);
  ck_assert_str_eq(test_str_1689, test_str_1689_1689);
}
END_TEST

START_TEST(sprintf_test_1690) {
  char test_str_1690[50] = "";
  char test_str_1690_1690[50] = "";
  s21_sprintf(test_str_1690, "%*E", 20, 123456789.12345679);
  sprintf(test_str_1690_1690, "%*E", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_1690, test_str_1690_1690);
}
END_TEST

START_TEST(sprintf_test_1691) {
  char test_str_1691[50] = "";
  char test_str_1691_1691[50] = "";
  s21_sprintf(test_str_1691, "%*E", 20, -123456789.12345678);
  sprintf(test_str_1691_1691, "%*E", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_1691, test_str_1691_1691);
}
END_TEST

START_TEST(sprintf_test_1692) {
  char test_str_1692[50] = "";
  char test_str_1692_1692[50] = "";
  s21_sprintf(test_str_1692, "%*E", 20, 1.23e-09);
  sprintf(test_str_1692_1692, "%*E", 20, 1.23e-09);
  ck_assert_str_eq(test_str_1692, test_str_1692_1692);
}
END_TEST

START_TEST(sprintf_test_1693) {
  char test_str_1693[50] = "";
  char test_str_1693_1693[50] = "";
  s21_sprintf(test_str_1693, "%*E", 20, 1.23e-09);
  sprintf(test_str_1693_1693, "%*E", 20, 1.23e-09);
  ck_assert_str_eq(test_str_1693, test_str_1693_1693);
}
END_TEST

START_TEST(sprintf_test_1694) {
  char test_str_1694[50] = "";
  char test_str_1694_1694[50] = "";
  s21_sprintf(test_str_1694, "%*e", -10, 0.0);
  sprintf(test_str_1694_1694, "%*e", -10, 0.0);
  ck_assert_str_eq(test_str_1694, test_str_1694_1694);
}
END_TEST

START_TEST(sprintf_test_1695) {
  char test_str_1695[50] = "";
  char test_str_1695_1695[50] = "";
  s21_sprintf(test_str_1695, "%*e", -10, 123456789.0);
  sprintf(test_str_1695_1695, "%*e", -10, 123456789.0);
  ck_assert_str_eq(test_str_1695, test_str_1695_1695);
}
END_TEST

START_TEST(sprintf_test_1696) {
  char test_str_1696[50] = "";
  char test_str_1696_1696[50] = "";
  s21_sprintf(test_str_1696, "%*e", -10, 0.123456789);
  sprintf(test_str_1696_1696, "%*e", -10, 0.123456789);
  ck_assert_str_eq(test_str_1696, test_str_1696_1696);
}
END_TEST

START_TEST(sprintf_test_1697) {
  char test_str_1697[50] = "";
  char test_str_1697_1697[50] = "";
  s21_sprintf(test_str_1697, "%*e", -10, -123456789.0);
  sprintf(test_str_1697_1697, "%*e", -10, -123456789.0);
  ck_assert_str_eq(test_str_1697, test_str_1697_1697);
}
END_TEST

START_TEST(sprintf_test_1698) {
  char test_str_1698[50] = "";
  char test_str_1698_1698[50] = "";
  s21_sprintf(test_str_1698, "%*e", -10, -0.123456789);
  sprintf(test_str_1698_1698, "%*e", -10, -0.123456789);
  ck_assert_str_eq(test_str_1698, test_str_1698_1698);
}
END_TEST

START_TEST(sprintf_test_1699) {
  char test_str_1699[50] = "";
  char test_str_1699_1699[50] = "";
  s21_sprintf(test_str_1699, "%*e", -10, 123456789.12345679);
  sprintf(test_str_1699_1699, "%*e", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_1699, test_str_1699_1699);
}
END_TEST

START_TEST(sprintf_test_1700) {
  char test_str_1700[50] = "";
  char test_str_1700_1700[50] = "";
  s21_sprintf(test_str_1700, "%*e", -10, -123456789.12345678);
  sprintf(test_str_1700_1700, "%*e", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_1700, test_str_1700_1700);
}
END_TEST

START_TEST(sprintf_test_1701) {
  char test_str_1701[50] = "";
  char test_str_1701_1701[50] = "";
  s21_sprintf(test_str_1701, "%*e", -10, 1.23e-09);
  sprintf(test_str_1701_1701, "%*e", -10, 1.23e-09);
  ck_assert_str_eq(test_str_1701, test_str_1701_1701);
}
END_TEST

START_TEST(sprintf_test_1702) {
  char test_str_1702[50] = "";
  char test_str_1702_1702[50] = "";
  s21_sprintf(test_str_1702, "%*e", -10, 1.23e-09);
  sprintf(test_str_1702_1702, "%*e", -10, 1.23e-09);
  ck_assert_str_eq(test_str_1702, test_str_1702_1702);
}
END_TEST

START_TEST(sprintf_test_1703) {
  char test_str_1703[50] = "";
  char test_str_1703_1703[50] = "";
  s21_sprintf(test_str_1703, "%*E", -10, 0.0);
  sprintf(test_str_1703_1703, "%*E", -10, 0.0);
  ck_assert_str_eq(test_str_1703, test_str_1703_1703);
}
END_TEST

START_TEST(sprintf_test_1704) {
  char test_str_1704[50] = "";
  char test_str_1704_1704[50] = "";
  s21_sprintf(test_str_1704, "%*E", -10, 123456789.0);
  sprintf(test_str_1704_1704, "%*E", -10, 123456789.0);
  ck_assert_str_eq(test_str_1704, test_str_1704_1704);
}
END_TEST

START_TEST(sprintf_test_1705) {
  char test_str_1705[50] = "";
  char test_str_1705_1705[50] = "";
  s21_sprintf(test_str_1705, "%*E", -10, 0.123456789);
  sprintf(test_str_1705_1705, "%*E", -10, 0.123456789);
  ck_assert_str_eq(test_str_1705, test_str_1705_1705);
}
END_TEST

START_TEST(sprintf_test_1706) {
  char test_str_1706[50] = "";
  char test_str_1706_1706[50] = "";
  s21_sprintf(test_str_1706, "%*E", -10, -123456789.0);
  sprintf(test_str_1706_1706, "%*E", -10, -123456789.0);
  ck_assert_str_eq(test_str_1706, test_str_1706_1706);
}
END_TEST

START_TEST(sprintf_test_1707) {
  char test_str_1707[50] = "";
  char test_str_1707_1707[50] = "";
  s21_sprintf(test_str_1707, "%*E", -10, -0.123456789);
  sprintf(test_str_1707_1707, "%*E", -10, -0.123456789);
  ck_assert_str_eq(test_str_1707, test_str_1707_1707);
}
END_TEST

START_TEST(sprintf_test_1708) {
  char test_str_1708[50] = "";
  char test_str_1708_1708[50] = "";
  s21_sprintf(test_str_1708, "%*E", -10, 123456789.12345679);
  sprintf(test_str_1708_1708, "%*E", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_1708, test_str_1708_1708);
}
END_TEST

START_TEST(sprintf_test_1709) {
  char test_str_1709[50] = "";
  char test_str_1709_1709[50] = "";
  s21_sprintf(test_str_1709, "%*E", -10, -123456789.12345678);
  sprintf(test_str_1709_1709, "%*E", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_1709, test_str_1709_1709);
}
END_TEST

START_TEST(sprintf_test_1710) {
  char test_str_1710[50] = "";
  char test_str_1710_1710[50] = "";
  s21_sprintf(test_str_1710, "%*E", -10, 1.23e-09);
  sprintf(test_str_1710_1710, "%*E", -10, 1.23e-09);
  ck_assert_str_eq(test_str_1710, test_str_1710_1710);
}
END_TEST

START_TEST(sprintf_test_1711) {
  char test_str_1711[50] = "";
  char test_str_1711_1711[50] = "";
  s21_sprintf(test_str_1711, "%*E", -10, 1.23e-09);
  sprintf(test_str_1711_1711, "%*E", -10, 1.23e-09);
  ck_assert_str_eq(test_str_1711, test_str_1711_1711);
}
END_TEST

START_TEST(sprintf_test_1712) {
  char test_str_1712[50] = "";
  char test_str_1712_1712[50] = "";
  s21_sprintf(test_str_1712, "%*e", -20, 0.0);
  sprintf(test_str_1712_1712, "%*e", -20, 0.0);
  ck_assert_str_eq(test_str_1712, test_str_1712_1712);
}
END_TEST

START_TEST(sprintf_test_1713) {
  char test_str_1713[50] = "";
  char test_str_1713_1713[50] = "";
  s21_sprintf(test_str_1713, "%*e", -20, 123456789.0);
  sprintf(test_str_1713_1713, "%*e", -20, 123456789.0);
  ck_assert_str_eq(test_str_1713, test_str_1713_1713);
}
END_TEST

START_TEST(sprintf_test_1714) {
  char test_str_1714[50] = "";
  char test_str_1714_1714[50] = "";
  s21_sprintf(test_str_1714, "%*e", -20, 0.123456789);
  sprintf(test_str_1714_1714, "%*e", -20, 0.123456789);
  ck_assert_str_eq(test_str_1714, test_str_1714_1714);
}
END_TEST

START_TEST(sprintf_test_1715) {
  char test_str_1715[50] = "";
  char test_str_1715_1715[50] = "";
  s21_sprintf(test_str_1715, "%*e", -20, -123456789.0);
  sprintf(test_str_1715_1715, "%*e", -20, -123456789.0);
  ck_assert_str_eq(test_str_1715, test_str_1715_1715);
}
END_TEST

START_TEST(sprintf_test_1716) {
  char test_str_1716[50] = "";
  char test_str_1716_1716[50] = "";
  s21_sprintf(test_str_1716, "%*e", -20, -0.123456789);
  sprintf(test_str_1716_1716, "%*e", -20, -0.123456789);
  ck_assert_str_eq(test_str_1716, test_str_1716_1716);
}
END_TEST

START_TEST(sprintf_test_1717) {
  char test_str_1717[50] = "";
  char test_str_1717_1717[50] = "";
  s21_sprintf(test_str_1717, "%*e", -20, 123456789.12345679);
  sprintf(test_str_1717_1717, "%*e", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_1717, test_str_1717_1717);
}
END_TEST

START_TEST(sprintf_test_1718) {
  char test_str_1718[50] = "";
  char test_str_1718_1718[50] = "";
  s21_sprintf(test_str_1718, "%*e", -20, -123456789.12345678);
  sprintf(test_str_1718_1718, "%*e", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_1718, test_str_1718_1718);
}
END_TEST

START_TEST(sprintf_test_1719) {
  char test_str_1719[50] = "";
  char test_str_1719_1719[50] = "";
  s21_sprintf(test_str_1719, "%*e", -20, 1.23e-09);
  sprintf(test_str_1719_1719, "%*e", -20, 1.23e-09);
  ck_assert_str_eq(test_str_1719, test_str_1719_1719);
}
END_TEST

START_TEST(sprintf_test_1720) {
  char test_str_1720[50] = "";
  char test_str_1720_1720[50] = "";
  s21_sprintf(test_str_1720, "%*e", -20, 1.23e-09);
  sprintf(test_str_1720_1720, "%*e", -20, 1.23e-09);
  ck_assert_str_eq(test_str_1720, test_str_1720_1720);
}
END_TEST

START_TEST(sprintf_test_1721) {
  char test_str_1721[50] = "";
  char test_str_1721_1721[50] = "";
  s21_sprintf(test_str_1721, "%*E", -20, 0.0);
  sprintf(test_str_1721_1721, "%*E", -20, 0.0);
  ck_assert_str_eq(test_str_1721, test_str_1721_1721);
}
END_TEST

START_TEST(sprintf_test_1722) {
  char test_str_1722[50] = "";
  char test_str_1722_1722[50] = "";
  s21_sprintf(test_str_1722, "%*E", -20, 123456789.0);
  sprintf(test_str_1722_1722, "%*E", -20, 123456789.0);
  ck_assert_str_eq(test_str_1722, test_str_1722_1722);
}
END_TEST

START_TEST(sprintf_test_1723) {
  char test_str_1723[50] = "";
  char test_str_1723_1723[50] = "";
  s21_sprintf(test_str_1723, "%*E", -20, 0.123456789);
  sprintf(test_str_1723_1723, "%*E", -20, 0.123456789);
  ck_assert_str_eq(test_str_1723, test_str_1723_1723);
}
END_TEST

START_TEST(sprintf_test_1724) {
  char test_str_1724[50] = "";
  char test_str_1724_1724[50] = "";
  s21_sprintf(test_str_1724, "%*E", -20, -123456789.0);
  sprintf(test_str_1724_1724, "%*E", -20, -123456789.0);
  ck_assert_str_eq(test_str_1724, test_str_1724_1724);
}
END_TEST

START_TEST(sprintf_test_1725) {
  char test_str_1725[50] = "";
  char test_str_1725_1725[50] = "";
  s21_sprintf(test_str_1725, "%*E", -20, -0.123456789);
  sprintf(test_str_1725_1725, "%*E", -20, -0.123456789);
  ck_assert_str_eq(test_str_1725, test_str_1725_1725);
}
END_TEST

START_TEST(sprintf_test_1726) {
  char test_str_1726[50] = "";
  char test_str_1726_1726[50] = "";
  s21_sprintf(test_str_1726, "%*E", -20, 123456789.12345679);
  sprintf(test_str_1726_1726, "%*E", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_1726, test_str_1726_1726);
}
END_TEST

START_TEST(sprintf_test_1727) {
  char test_str_1727[50] = "";
  char test_str_1727_1727[50] = "";
  s21_sprintf(test_str_1727, "%*E", -20, -123456789.12345678);
  sprintf(test_str_1727_1727, "%*E", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_1727, test_str_1727_1727);
}
END_TEST

START_TEST(sprintf_test_1728) {
  char test_str_1728[50] = "";
  char test_str_1728_1728[50] = "";
  s21_sprintf(test_str_1728, "%*E", -20, 1.23e-09);
  sprintf(test_str_1728_1728, "%*E", -20, 1.23e-09);
  ck_assert_str_eq(test_str_1728, test_str_1728_1728);
}
END_TEST

START_TEST(sprintf_test_1729) {
  char test_str_1729[50] = "";
  char test_str_1729_1729[50] = "";
  s21_sprintf(test_str_1729, "%*E", -20, 1.23e-09);
  sprintf(test_str_1729_1729, "%*E", -20, 1.23e-09);
  ck_assert_str_eq(test_str_1729, test_str_1729_1729);
}
END_TEST

START_TEST(sprintf_test_1730) {
  char test_str_1730[50] = "";
  char test_str_1730_1730[50] = "";
  s21_sprintf(test_str_1730, "%.10e", 0.0);
  sprintf(test_str_1730_1730, "%.10e", 0.0);
  ck_assert_str_eq(test_str_1730, test_str_1730_1730);
}
END_TEST

START_TEST(sprintf_test_1731) {
  char test_str_1731[50] = "";
  char test_str_1731_1731[50] = "";
  s21_sprintf(test_str_1731, "%.10e", 123456789.0);
  sprintf(test_str_1731_1731, "%.10e", 123456789.0);
  ck_assert_str_eq(test_str_1731, test_str_1731_1731);
}
END_TEST

START_TEST(sprintf_test_1732) {
  char test_str_1732[50] = "";
  char test_str_1732_1732[50] = "";
  s21_sprintf(test_str_1732, "%.10e", 0.123456789);
  sprintf(test_str_1732_1732, "%.10e", 0.123456789);
  ck_assert_str_eq(test_str_1732, test_str_1732_1732);
}
END_TEST

START_TEST(sprintf_test_1733) {
  char test_str_1733[50] = "";
  char test_str_1733_1733[50] = "";
  s21_sprintf(test_str_1733, "%.10e", -123456789.0);
  sprintf(test_str_1733_1733, "%.10e", -123456789.0);
  ck_assert_str_eq(test_str_1733, test_str_1733_1733);
}
END_TEST

START_TEST(sprintf_test_1734) {
  char test_str_1734[50] = "";
  char test_str_1734_1734[50] = "";
  s21_sprintf(test_str_1734, "%.10e", -0.123456789);
  sprintf(test_str_1734_1734, "%.10e", -0.123456789);
  ck_assert_str_eq(test_str_1734, test_str_1734_1734);
}
END_TEST

START_TEST(sprintf_test_1735) {
  char test_str_1735[50] = "";
  char test_str_1735_1735[50] = "";
  s21_sprintf(test_str_1735, "%.10e", 123456789.12345679);
  sprintf(test_str_1735_1735, "%.10e", 123456789.12345679);
  ck_assert_str_eq(test_str_1735, test_str_1735_1735);
}
END_TEST

START_TEST(sprintf_test_1736) {
  char test_str_1736[50] = "";
  char test_str_1736_1736[50] = "";
  s21_sprintf(test_str_1736, "%.10e", -123456789.12345678);
  sprintf(test_str_1736_1736, "%.10e", -123456789.12345678);
  ck_assert_str_eq(test_str_1736, test_str_1736_1736);
}
END_TEST

START_TEST(sprintf_test_1737) {
  char test_str_1737[50] = "";
  char test_str_1737_1737[50] = "";
  s21_sprintf(test_str_1737, "%.10e", 1.23e-09);
  sprintf(test_str_1737_1737, "%.10e", 1.23e-09);
  ck_assert_str_eq(test_str_1737, test_str_1737_1737);
}
END_TEST

START_TEST(sprintf_test_1738) {
  char test_str_1738[50] = "";
  char test_str_1738_1738[50] = "";
  s21_sprintf(test_str_1738, "%.10e", 1.23e-09);
  sprintf(test_str_1738_1738, "%.10e", 1.23e-09);
  ck_assert_str_eq(test_str_1738, test_str_1738_1738);
}
END_TEST

START_TEST(sprintf_test_1739) {
  char test_str_1739[50] = "";
  char test_str_1739_1739[50] = "";
  s21_sprintf(test_str_1739, "%.10E", 0.0);
  sprintf(test_str_1739_1739, "%.10E", 0.0);
  ck_assert_str_eq(test_str_1739, test_str_1739_1739);
}
END_TEST

START_TEST(sprintf_test_1740) {
  char test_str_1740[50] = "";
  char test_str_1740_1740[50] = "";
  s21_sprintf(test_str_1740, "%.10E", 123456789.0);
  sprintf(test_str_1740_1740, "%.10E", 123456789.0);
  ck_assert_str_eq(test_str_1740, test_str_1740_1740);
}
END_TEST

START_TEST(sprintf_test_1741) {
  char test_str_1741[50] = "";
  char test_str_1741_1741[50] = "";
  s21_sprintf(test_str_1741, "%.10E", 0.123456789);
  sprintf(test_str_1741_1741, "%.10E", 0.123456789);
  ck_assert_str_eq(test_str_1741, test_str_1741_1741);
}
END_TEST

START_TEST(sprintf_test_1742) {
  char test_str_1742[50] = "";
  char test_str_1742_1742[50] = "";
  s21_sprintf(test_str_1742, "%.10E", -123456789.0);
  sprintf(test_str_1742_1742, "%.10E", -123456789.0);
  ck_assert_str_eq(test_str_1742, test_str_1742_1742);
}
END_TEST

START_TEST(sprintf_test_1743) {
  char test_str_1743[50] = "";
  char test_str_1743_1743[50] = "";
  s21_sprintf(test_str_1743, "%.10E", -0.123456789);
  sprintf(test_str_1743_1743, "%.10E", -0.123456789);
  ck_assert_str_eq(test_str_1743, test_str_1743_1743);
}
END_TEST

START_TEST(sprintf_test_1744) {
  char test_str_1744[50] = "";
  char test_str_1744_1744[50] = "";
  s21_sprintf(test_str_1744, "%.10E", 123456789.12345679);
  sprintf(test_str_1744_1744, "%.10E", 123456789.12345679);
  ck_assert_str_eq(test_str_1744, test_str_1744_1744);
}
END_TEST

START_TEST(sprintf_test_1745) {
  char test_str_1745[50] = "";
  char test_str_1745_1745[50] = "";
  s21_sprintf(test_str_1745, "%.10E", -123456789.12345678);
  sprintf(test_str_1745_1745, "%.10E", -123456789.12345678);
  ck_assert_str_eq(test_str_1745, test_str_1745_1745);
}
END_TEST

START_TEST(sprintf_test_1746) {
  char test_str_1746[50] = "";
  char test_str_1746_1746[50] = "";
  s21_sprintf(test_str_1746, "%.10E", 1.23e-09);
  sprintf(test_str_1746_1746, "%.10E", 1.23e-09);
  ck_assert_str_eq(test_str_1746, test_str_1746_1746);
}
END_TEST

START_TEST(sprintf_test_1747) {
  char test_str_1747[50] = "";
  char test_str_1747_1747[50] = "";
  s21_sprintf(test_str_1747, "%.10E", 1.23e-09);
  sprintf(test_str_1747_1747, "%.10E", 1.23e-09);
  ck_assert_str_eq(test_str_1747, test_str_1747_1747);
}
END_TEST

START_TEST(sprintf_test_1748) {
  char test_str_1748[50] = "";
  char test_str_1748_1748[50] = "";
  s21_sprintf(test_str_1748, "%.14e", 0.0);
  sprintf(test_str_1748_1748, "%.14e", 0.0);
  ck_assert_str_eq(test_str_1748, test_str_1748_1748);
}
END_TEST

START_TEST(sprintf_test_1749) {
  char test_str_1749[50] = "";
  char test_str_1749_1749[50] = "";
  s21_sprintf(test_str_1749, "%.14e", 123456789.0);
  sprintf(test_str_1749_1749, "%.14e", 123456789.0);
  ck_assert_str_eq(test_str_1749, test_str_1749_1749);
}
END_TEST

START_TEST(sprintf_test_1750) {
  char test_str_1750[50] = "";
  char test_str_1750_1750[50] = "";
  s21_sprintf(test_str_1750, "%.14e", 0.123456789);
  sprintf(test_str_1750_1750, "%.14e", 0.123456789);
  ck_assert_str_eq(test_str_1750, test_str_1750_1750);
}
END_TEST

START_TEST(sprintf_test_1751) {
  char test_str_1751[50] = "";
  char test_str_1751_1751[50] = "";
  s21_sprintf(test_str_1751, "%.14e", -123456789.0);
  sprintf(test_str_1751_1751, "%.14e", -123456789.0);
  ck_assert_str_eq(test_str_1751, test_str_1751_1751);
}
END_TEST

START_TEST(sprintf_test_1752) {
  char test_str_1752[50] = "";
  char test_str_1752_1752[50] = "";
  s21_sprintf(test_str_1752, "%.14e", -0.123456789);
  sprintf(test_str_1752_1752, "%.14e", -0.123456789);
  ck_assert_str_eq(test_str_1752, test_str_1752_1752);
}
END_TEST

START_TEST(sprintf_test_1753) {
  char test_str_1753[50] = "";
  char test_str_1753_1753[50] = "";
  s21_sprintf(test_str_1753, "%.14e", 123456789.12345679);
  sprintf(test_str_1753_1753, "%.14e", 123456789.12345679);
  ck_assert_str_eq(test_str_1753, test_str_1753_1753);
}
END_TEST

START_TEST(sprintf_test_1754) {
  char test_str_1754[50] = "";
  char test_str_1754_1754[50] = "";
  s21_sprintf(test_str_1754, "%.14e", -123456789.12345678);
  sprintf(test_str_1754_1754, "%.14e", -123456789.12345678);
  ck_assert_str_eq(test_str_1754, test_str_1754_1754);
}
END_TEST

START_TEST(sprintf_test_1755) {
  char test_str_1755[50] = "";
  char test_str_1755_1755[50] = "";
  s21_sprintf(test_str_1755, "%.14e", 1.23e-09);
  sprintf(test_str_1755_1755, "%.14e", 1.23e-09);
  ck_assert_str_eq(test_str_1755, test_str_1755_1755);
}
END_TEST

START_TEST(sprintf_test_1756) {
  char test_str_1756[50] = "";
  char test_str_1756_1756[50] = "";
  s21_sprintf(test_str_1756, "%.14e", 1.23e-09);
  sprintf(test_str_1756_1756, "%.14e", 1.23e-09);
  ck_assert_str_eq(test_str_1756, test_str_1756_1756);
}
END_TEST

START_TEST(sprintf_test_1757) {
  char test_str_1757[50] = "";
  char test_str_1757_1757[50] = "";
  s21_sprintf(test_str_1757, "%.14E", 0.0);
  sprintf(test_str_1757_1757, "%.14E", 0.0);
  ck_assert_str_eq(test_str_1757, test_str_1757_1757);
}
END_TEST

START_TEST(sprintf_test_1758) {
  char test_str_1758[50] = "";
  char test_str_1758_1758[50] = "";
  s21_sprintf(test_str_1758, "%.14E", 123456789.0);
  sprintf(test_str_1758_1758, "%.14E", 123456789.0);
  ck_assert_str_eq(test_str_1758, test_str_1758_1758);
}
END_TEST

START_TEST(sprintf_test_1759) {
  char test_str_1759[50] = "";
  char test_str_1759_1759[50] = "";
  s21_sprintf(test_str_1759, "%.14E", 0.123456789);
  sprintf(test_str_1759_1759, "%.14E", 0.123456789);
  ck_assert_str_eq(test_str_1759, test_str_1759_1759);
}
END_TEST

START_TEST(sprintf_test_1760) {
  char test_str_1760[50] = "";
  char test_str_1760_1760[50] = "";
  s21_sprintf(test_str_1760, "%.14E", -123456789.0);
  sprintf(test_str_1760_1760, "%.14E", -123456789.0);
  ck_assert_str_eq(test_str_1760, test_str_1760_1760);
}
END_TEST

START_TEST(sprintf_test_1761) {
  char test_str_1761[50] = "";
  char test_str_1761_1761[50] = "";
  s21_sprintf(test_str_1761, "%.14E", -0.123456789);
  sprintf(test_str_1761_1761, "%.14E", -0.123456789);
  ck_assert_str_eq(test_str_1761, test_str_1761_1761);
}
END_TEST

START_TEST(sprintf_test_1762) {
  char test_str_1762[50] = "";
  char test_str_1762_1762[50] = "";
  s21_sprintf(test_str_1762, "%.14E", 123456789.12345679);
  sprintf(test_str_1762_1762, "%.14E", 123456789.12345679);
  ck_assert_str_eq(test_str_1762, test_str_1762_1762);
}
END_TEST

START_TEST(sprintf_test_1763) {
  char test_str_1763[50] = "";
  char test_str_1763_1763[50] = "";
  s21_sprintf(test_str_1763, "%.14E", -123456789.12345678);
  sprintf(test_str_1763_1763, "%.14E", -123456789.12345678);
  ck_assert_str_eq(test_str_1763, test_str_1763_1763);
}
END_TEST

START_TEST(sprintf_test_1764) {
  char test_str_1764[50] = "";
  char test_str_1764_1764[50] = "";
  s21_sprintf(test_str_1764, "%.14E", 1.23e-09);
  sprintf(test_str_1764_1764, "%.14E", 1.23e-09);
  ck_assert_str_eq(test_str_1764, test_str_1764_1764);
}
END_TEST

START_TEST(sprintf_test_1765) {
  char test_str_1765[50] = "";
  char test_str_1765_1765[50] = "";
  s21_sprintf(test_str_1765, "%.14E", 1.23e-09);
  sprintf(test_str_1765_1765, "%.14E", 1.23e-09);
  ck_assert_str_eq(test_str_1765, test_str_1765_1765);
}
END_TEST

START_TEST(sprintf_test_1766) {
  char test_str_1766[50] = "";
  char test_str_1766_1766[50] = "";
  s21_sprintf(test_str_1766, "%.1e", 0.0);
  sprintf(test_str_1766_1766, "%.1e", 0.0);
  ck_assert_str_eq(test_str_1766, test_str_1766_1766);
}
END_TEST

START_TEST(sprintf_test_1767) {
  char test_str_1767[50] = "";
  char test_str_1767_1767[50] = "";
  s21_sprintf(test_str_1767, "%.1e", 123456789.0);
  sprintf(test_str_1767_1767, "%.1e", 123456789.0);
  ck_assert_str_eq(test_str_1767, test_str_1767_1767);
}
END_TEST

START_TEST(sprintf_test_1768) {
  char test_str_1768[50] = "";
  char test_str_1768_1768[50] = "";
  s21_sprintf(test_str_1768, "%.1e", 0.123456789);
  sprintf(test_str_1768_1768, "%.1e", 0.123456789);
  ck_assert_str_eq(test_str_1768, test_str_1768_1768);
}
END_TEST

START_TEST(sprintf_test_1769) {
  char test_str_1769[50] = "";
  char test_str_1769_1769[50] = "";
  s21_sprintf(test_str_1769, "%.1e", -123456789.0);
  sprintf(test_str_1769_1769, "%.1e", -123456789.0);
  ck_assert_str_eq(test_str_1769, test_str_1769_1769);
}
END_TEST

START_TEST(sprintf_test_1770) {
  char test_str_1770[50] = "";
  char test_str_1770_1770[50] = "";
  s21_sprintf(test_str_1770, "%.1e", -0.123456789);
  sprintf(test_str_1770_1770, "%.1e", -0.123456789);
  ck_assert_str_eq(test_str_1770, test_str_1770_1770);
}
END_TEST

START_TEST(sprintf_test_1771) {
  char test_str_1771[50] = "";
  char test_str_1771_1771[50] = "";
  s21_sprintf(test_str_1771, "%.1e", 123456789.12345679);
  sprintf(test_str_1771_1771, "%.1e", 123456789.12345679);
  ck_assert_str_eq(test_str_1771, test_str_1771_1771);
}
END_TEST

START_TEST(sprintf_test_1772) {
  char test_str_1772[50] = "";
  char test_str_1772_1772[50] = "";
  s21_sprintf(test_str_1772, "%.1e", -123456789.12345678);
  sprintf(test_str_1772_1772, "%.1e", -123456789.12345678);
  ck_assert_str_eq(test_str_1772, test_str_1772_1772);
}
END_TEST

START_TEST(sprintf_test_1773) {
  char test_str_1773[50] = "";
  char test_str_1773_1773[50] = "";
  s21_sprintf(test_str_1773, "%.1e", 1.23e-09);
  sprintf(test_str_1773_1773, "%.1e", 1.23e-09);
  ck_assert_str_eq(test_str_1773, test_str_1773_1773);
}
END_TEST

START_TEST(sprintf_test_1774) {
  char test_str_1774[50] = "";
  char test_str_1774_1774[50] = "";
  s21_sprintf(test_str_1774, "%.1e", 1.23e-09);
  sprintf(test_str_1774_1774, "%.1e", 1.23e-09);
  ck_assert_str_eq(test_str_1774, test_str_1774_1774);
}
END_TEST

START_TEST(sprintf_test_1775) {
  char test_str_1775[50] = "";
  char test_str_1775_1775[50] = "";
  s21_sprintf(test_str_1775, "%.1E", 0.0);
  sprintf(test_str_1775_1775, "%.1E", 0.0);
  ck_assert_str_eq(test_str_1775, test_str_1775_1775);
}
END_TEST

START_TEST(sprintf_test_1776) {
  char test_str_1776[50] = "";
  char test_str_1776_1776[50] = "";
  s21_sprintf(test_str_1776, "%.1E", 123456789.0);
  sprintf(test_str_1776_1776, "%.1E", 123456789.0);
  ck_assert_str_eq(test_str_1776, test_str_1776_1776);
}
END_TEST

START_TEST(sprintf_test_1777) {
  char test_str_1777[50] = "";
  char test_str_1777_1777[50] = "";
  s21_sprintf(test_str_1777, "%.1E", 0.123456789);
  sprintf(test_str_1777_1777, "%.1E", 0.123456789);
  ck_assert_str_eq(test_str_1777, test_str_1777_1777);
}
END_TEST

START_TEST(sprintf_test_1778) {
  char test_str_1778[50] = "";
  char test_str_1778_1778[50] = "";
  s21_sprintf(test_str_1778, "%.1E", -123456789.0);
  sprintf(test_str_1778_1778, "%.1E", -123456789.0);
  ck_assert_str_eq(test_str_1778, test_str_1778_1778);
}
END_TEST

START_TEST(sprintf_test_1779) {
  char test_str_1779[50] = "";
  char test_str_1779_1779[50] = "";
  s21_sprintf(test_str_1779, "%.1E", -0.123456789);
  sprintf(test_str_1779_1779, "%.1E", -0.123456789);
  ck_assert_str_eq(test_str_1779, test_str_1779_1779);
}
END_TEST

START_TEST(sprintf_test_1780) {
  char test_str_1780[50] = "";
  char test_str_1780_1780[50] = "";
  s21_sprintf(test_str_1780, "%.1E", 123456789.12345679);
  sprintf(test_str_1780_1780, "%.1E", 123456789.12345679);
  ck_assert_str_eq(test_str_1780, test_str_1780_1780);
}
END_TEST

START_TEST(sprintf_test_1781) {
  char test_str_1781[50] = "";
  char test_str_1781_1781[50] = "";
  s21_sprintf(test_str_1781, "%.1E", -123456789.12345678);
  sprintf(test_str_1781_1781, "%.1E", -123456789.12345678);
  ck_assert_str_eq(test_str_1781, test_str_1781_1781);
}
END_TEST

START_TEST(sprintf_test_1782) {
  char test_str_1782[50] = "";
  char test_str_1782_1782[50] = "";
  s21_sprintf(test_str_1782, "%.1E", 1.23e-09);
  sprintf(test_str_1782_1782, "%.1E", 1.23e-09);
  ck_assert_str_eq(test_str_1782, test_str_1782_1782);
}
END_TEST

START_TEST(sprintf_test_1783) {
  char test_str_1783[50] = "";
  char test_str_1783_1783[50] = "";
  s21_sprintf(test_str_1783, "%.1E", 1.23e-09);
  sprintf(test_str_1783_1783, "%.1E", 1.23e-09);
  ck_assert_str_eq(test_str_1783, test_str_1783_1783);
}
END_TEST

START_TEST(sprintf_test_1784) {
  char test_str_1784[50] = "";
  char test_str_1784_1784[50] = "";
  s21_sprintf(test_str_1784, "%Le", (long double)0.0);
  sprintf(test_str_1784_1784, "%Le", (long double)0.0);
  ck_assert_str_eq(test_str_1784, test_str_1784_1784);
}
END_TEST

START_TEST(sprintf_test_1785) {
  char test_str_1785[50] = "";
  char test_str_1785_1785[50] = "";
  s21_sprintf(test_str_1785, "%Le", (long double)123456789.0);
  sprintf(test_str_1785_1785, "%Le", (long double)123456789.0);
  ck_assert_str_eq(test_str_1785, test_str_1785_1785);
}
END_TEST

START_TEST(sprintf_test_1786) {
  char test_str_1786[50] = "";
  char test_str_1786_1786[50] = "";
  s21_sprintf(test_str_1786, "%Le", (long double)0.123456789);
  sprintf(test_str_1786_1786, "%Le", (long double)0.123456789);
  ck_assert_str_eq(test_str_1786, test_str_1786_1786);
}
END_TEST

START_TEST(sprintf_test_1787) {
  char test_str_1787[50] = "";
  char test_str_1787_1787[50] = "";
  s21_sprintf(test_str_1787, "%Le", (long double)-123456789.0);
  sprintf(test_str_1787_1787, "%Le", (long double)-123456789.0);
  ck_assert_str_eq(test_str_1787, test_str_1787_1787);
}
END_TEST

START_TEST(sprintf_test_1788) {
  char test_str_1788[50] = "";
  char test_str_1788_1788[50] = "";
  s21_sprintf(test_str_1788, "%Le", (long double)-0.123456789);
  sprintf(test_str_1788_1788, "%Le", (long double)-0.123456789);
  ck_assert_str_eq(test_str_1788, test_str_1788_1788);
}
END_TEST

START_TEST(sprintf_test_1789) {
  char test_str_1789[50] = "";
  char test_str_1789_1789[50] = "";
  s21_sprintf(test_str_1789, "%Le", (long double)123456789.12345679);
  sprintf(test_str_1789_1789, "%Le", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_1789, test_str_1789_1789);
}
END_TEST

START_TEST(sprintf_test_1790) {
  char test_str_1790[50] = "";
  char test_str_1790_1790[50] = "";
  s21_sprintf(test_str_1790, "%Le", (long double)-123456789.12345678);
  sprintf(test_str_1790_1790, "%Le", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_1790, test_str_1790_1790);
}
END_TEST

START_TEST(sprintf_test_1791) {
  char test_str_1791[50] = "";
  char test_str_1791_1791[50] = "";
  s21_sprintf(test_str_1791, "%Le", (long double)1.23e-09);
  sprintf(test_str_1791_1791, "%Le", (long double)1.23e-09);
  ck_assert_str_eq(test_str_1791, test_str_1791_1791);
}
END_TEST

START_TEST(sprintf_test_1792) {
  char test_str_1792[50] = "";
  char test_str_1792_1792[50] = "";
  s21_sprintf(test_str_1792, "%Le", (long double)1.23e-09);
  sprintf(test_str_1792_1792, "%Le", (long double)1.23e-09);
  ck_assert_str_eq(test_str_1792, test_str_1792_1792);
}
END_TEST

START_TEST(sprintf_test_1793) {
  char test_str_1793[50] = "";
  char test_str_1793_1793[50] = "";
  s21_sprintf(test_str_1793, "%LE", (long double)0.0);
  sprintf(test_str_1793_1793, "%LE", (long double)0.0);
  ck_assert_str_eq(test_str_1793, test_str_1793_1793);
}
END_TEST

START_TEST(sprintf_test_1794) {
  char test_str_1794[50] = "";
  char test_str_1794_1794[50] = "";
  s21_sprintf(test_str_1794, "%LE", (long double)123456789.0);
  sprintf(test_str_1794_1794, "%LE", (long double)123456789.0);
  ck_assert_str_eq(test_str_1794, test_str_1794_1794);
}
END_TEST

START_TEST(sprintf_test_1795) {
  char test_str_1795[50] = "";
  char test_str_1795_1795[50] = "";
  s21_sprintf(test_str_1795, "%LE", (long double)0.123456789);
  sprintf(test_str_1795_1795, "%LE", (long double)0.123456789);
  ck_assert_str_eq(test_str_1795, test_str_1795_1795);
}
END_TEST

START_TEST(sprintf_test_1796) {
  char test_str_1796[50] = "";
  char test_str_1796_1796[50] = "";
  s21_sprintf(test_str_1796, "%LE", (long double)-123456789.0);
  sprintf(test_str_1796_1796, "%LE", (long double)-123456789.0);
  ck_assert_str_eq(test_str_1796, test_str_1796_1796);
}
END_TEST

START_TEST(sprintf_test_1797) {
  char test_str_1797[50] = "";
  char test_str_1797_1797[50] = "";
  s21_sprintf(test_str_1797, "%LE", (long double)-0.123456789);
  sprintf(test_str_1797_1797, "%LE", (long double)-0.123456789);
  ck_assert_str_eq(test_str_1797, test_str_1797_1797);
}
END_TEST

START_TEST(sprintf_test_1798) {
  char test_str_1798[50] = "";
  char test_str_1798_1798[50] = "";
  s21_sprintf(test_str_1798, "%LE", (long double)123456789.12345679);
  sprintf(test_str_1798_1798, "%LE", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_1798, test_str_1798_1798);
}
END_TEST

START_TEST(sprintf_test_1799) {
  char test_str_1799[50] = "";
  char test_str_1799_1799[50] = "";
  s21_sprintf(test_str_1799, "%LE", (long double)-123456789.12345678);
  sprintf(test_str_1799_1799, "%LE", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_1799, test_str_1799_1799);
}
END_TEST

START_TEST(sprintf_test_1800) {
  char test_str_1800[50] = "";
  char test_str_1800_1800[50] = "";
  s21_sprintf(test_str_1800, "%LE", (long double)1.23e-09);
  sprintf(test_str_1800_1800, "%LE", (long double)1.23e-09);
  ck_assert_str_eq(test_str_1800, test_str_1800_1800);
}
END_TEST

START_TEST(sprintf_test_1801) {
  char test_str_1801[50] = "";
  char test_str_1801_1801[50] = "";
  s21_sprintf(test_str_1801, "%LE", (long double)1.23e-09);
  sprintf(test_str_1801_1801, "%LE", (long double)1.23e-09);
  ck_assert_str_eq(test_str_1801, test_str_1801_1801);
}
END_TEST

START_TEST(sprintf_test_1802) {
  char test_str_1802[50] = "";
  char test_str_1802_1802[50] = "";
  s21_sprintf(test_str_1802, "%-e", 0.0);
  sprintf(test_str_1802_1802, "%-e", 0.0);
  ck_assert_str_eq(test_str_1802, test_str_1802_1802);
}
END_TEST

START_TEST(sprintf_test_1803) {
  char test_str_1803[50] = "";
  char test_str_1803_1803[50] = "";
  s21_sprintf(test_str_1803, "%-e", 123456789.0);
  sprintf(test_str_1803_1803, "%-e", 123456789.0);
  ck_assert_str_eq(test_str_1803, test_str_1803_1803);
}
END_TEST

START_TEST(sprintf_test_1804) {
  char test_str_1804[50] = "";
  char test_str_1804_1804[50] = "";
  s21_sprintf(test_str_1804, "%-e", 0.123456789);
  sprintf(test_str_1804_1804, "%-e", 0.123456789);
  ck_assert_str_eq(test_str_1804, test_str_1804_1804);
}
END_TEST

START_TEST(sprintf_test_1805) {
  char test_str_1805[50] = "";
  char test_str_1805_1805[50] = "";
  s21_sprintf(test_str_1805, "%-e", -123456789.0);
  sprintf(test_str_1805_1805, "%-e", -123456789.0);
  ck_assert_str_eq(test_str_1805, test_str_1805_1805);
}
END_TEST

START_TEST(sprintf_test_1806) {
  char test_str_1806[50] = "";
  char test_str_1806_1806[50] = "";
  s21_sprintf(test_str_1806, "%-e", -0.123456789);
  sprintf(test_str_1806_1806, "%-e", -0.123456789);
  ck_assert_str_eq(test_str_1806, test_str_1806_1806);
}
END_TEST

START_TEST(sprintf_test_1807) {
  char test_str_1807[50] = "";
  char test_str_1807_1807[50] = "";
  s21_sprintf(test_str_1807, "%-e", 123456789.12345679);
  sprintf(test_str_1807_1807, "%-e", 123456789.12345679);
  ck_assert_str_eq(test_str_1807, test_str_1807_1807);
}
END_TEST

START_TEST(sprintf_test_1808) {
  char test_str_1808[50] = "";
  char test_str_1808_1808[50] = "";
  s21_sprintf(test_str_1808, "%-e", -123456789.12345678);
  sprintf(test_str_1808_1808, "%-e", -123456789.12345678);
  ck_assert_str_eq(test_str_1808, test_str_1808_1808);
}
END_TEST

START_TEST(sprintf_test_1809) {
  char test_str_1809[50] = "";
  char test_str_1809_1809[50] = "";
  s21_sprintf(test_str_1809, "%-e", 1.23e-09);
  sprintf(test_str_1809_1809, "%-e", 1.23e-09);
  ck_assert_str_eq(test_str_1809, test_str_1809_1809);
}
END_TEST

START_TEST(sprintf_test_1810) {
  char test_str_1810[50] = "";
  char test_str_1810_1810[50] = "";
  s21_sprintf(test_str_1810, "%-e", 1.23e-09);
  sprintf(test_str_1810_1810, "%-e", 1.23e-09);
  ck_assert_str_eq(test_str_1810, test_str_1810_1810);
}
END_TEST

START_TEST(sprintf_test_1811) {
  char test_str_1811[50] = "";
  char test_str_1811_1811[50] = "";
  s21_sprintf(test_str_1811, "%-E", 0.0);
  sprintf(test_str_1811_1811, "%-E", 0.0);
  ck_assert_str_eq(test_str_1811, test_str_1811_1811);
}
END_TEST

START_TEST(sprintf_test_1812) {
  char test_str_1812[50] = "";
  char test_str_1812_1812[50] = "";
  s21_sprintf(test_str_1812, "%-E", 123456789.0);
  sprintf(test_str_1812_1812, "%-E", 123456789.0);
  ck_assert_str_eq(test_str_1812, test_str_1812_1812);
}
END_TEST

START_TEST(sprintf_test_1813) {
  char test_str_1813[50] = "";
  char test_str_1813_1813[50] = "";
  s21_sprintf(test_str_1813, "%-E", 0.123456789);
  sprintf(test_str_1813_1813, "%-E", 0.123456789);
  ck_assert_str_eq(test_str_1813, test_str_1813_1813);
}
END_TEST

START_TEST(sprintf_test_1814) {
  char test_str_1814[50] = "";
  char test_str_1814_1814[50] = "";
  s21_sprintf(test_str_1814, "%-E", -123456789.0);
  sprintf(test_str_1814_1814, "%-E", -123456789.0);
  ck_assert_str_eq(test_str_1814, test_str_1814_1814);
}
END_TEST

START_TEST(sprintf_test_1815) {
  char test_str_1815[50] = "";
  char test_str_1815_1815[50] = "";
  s21_sprintf(test_str_1815, "%-E", -0.123456789);
  sprintf(test_str_1815_1815, "%-E", -0.123456789);
  ck_assert_str_eq(test_str_1815, test_str_1815_1815);
}
END_TEST

START_TEST(sprintf_test_1816) {
  char test_str_1816[50] = "";
  char test_str_1816_1816[50] = "";
  s21_sprintf(test_str_1816, "%-E", 123456789.12345679);
  sprintf(test_str_1816_1816, "%-E", 123456789.12345679);
  ck_assert_str_eq(test_str_1816, test_str_1816_1816);
}
END_TEST

START_TEST(sprintf_test_1817) {
  char test_str_1817[50] = "";
  char test_str_1817_1817[50] = "";
  s21_sprintf(test_str_1817, "%-E", -123456789.12345678);
  sprintf(test_str_1817_1817, "%-E", -123456789.12345678);
  ck_assert_str_eq(test_str_1817, test_str_1817_1817);
}
END_TEST

START_TEST(sprintf_test_1818) {
  char test_str_1818[50] = "";
  char test_str_1818_1818[50] = "";
  s21_sprintf(test_str_1818, "%-E", 1.23e-09);
  sprintf(test_str_1818_1818, "%-E", 1.23e-09);
  ck_assert_str_eq(test_str_1818, test_str_1818_1818);
}
END_TEST

START_TEST(sprintf_test_1819) {
  char test_str_1819[50] = "";
  char test_str_1819_1819[50] = "";
  s21_sprintf(test_str_1819, "%-E", 1.23e-09);
  sprintf(test_str_1819_1819, "%-E", 1.23e-09);
  ck_assert_str_eq(test_str_1819, test_str_1819_1819);
}
END_TEST

START_TEST(sprintf_test_1821) {
  char test_str_1821[50] = "";
  char test_str_1821_1821[50] = "";
  s21_sprintf(test_str_1821, "%-g", 123456789.0);
  sprintf(test_str_1821_1821, "%-g", 123456789.0);
  ck_assert_str_eq(test_str_1821, test_str_1821_1821);
}
END_TEST

START_TEST(sprintf_test_1822) {
  char test_str_1822[50] = "";
  char test_str_1822_1822[50] = "";
  s21_sprintf(test_str_1822, "%-g", 0.123456789);
  sprintf(test_str_1822_1822, "%-g", 0.123456789);
  ck_assert_str_eq(test_str_1822, test_str_1822_1822);
}
END_TEST

START_TEST(sprintf_test_1823) {
  char test_str_1823[50] = "";
  char test_str_1823_1823[50] = "";
  s21_sprintf(test_str_1823, "%-g", -123456789.0);
  sprintf(test_str_1823_1823, "%-g", -123456789.0);
  ck_assert_str_eq(test_str_1823, test_str_1823_1823);
}
END_TEST

START_TEST(sprintf_test_1824) {
  char test_str_1824[50] = "";
  char test_str_1824_1824[50] = "";
  s21_sprintf(test_str_1824, "%-g", -0.123456789);
  sprintf(test_str_1824_1824, "%-g", -0.123456789);
  ck_assert_str_eq(test_str_1824, test_str_1824_1824);
}
END_TEST

START_TEST(sprintf_test_1825) {
  char test_str_1825[50] = "";
  char test_str_1825_1825[50] = "";
  s21_sprintf(test_str_1825, "%-g", 123456789.12345679);
  sprintf(test_str_1825_1825, "%-g", 123456789.12345679);
  ck_assert_str_eq(test_str_1825, test_str_1825_1825);
}
END_TEST

START_TEST(sprintf_test_1826) {
  char test_str_1826[50] = "";
  char test_str_1826_1826[50] = "";
  s21_sprintf(test_str_1826, "%-g", -123456789.12345678);
  sprintf(test_str_1826_1826, "%-g", -123456789.12345678);
  ck_assert_str_eq(test_str_1826, test_str_1826_1826);
}
END_TEST

START_TEST(sprintf_test_1827) {
  char test_str_1827[50] = "";
  char test_str_1827_1827[50] = "";
  s21_sprintf(test_str_1827, "%-g", 1.23e-09);
  sprintf(test_str_1827_1827, "%-g", 1.23e-09);
  ck_assert_str_eq(test_str_1827, test_str_1827_1827);
}
END_TEST

START_TEST(sprintf_test_1828) {
  char test_str_1828[50] = "";
  char test_str_1828_1828[50] = "";
  s21_sprintf(test_str_1828, "%-g", 1.23e-09);
  sprintf(test_str_1828_1828, "%-g", 1.23e-09);
  ck_assert_str_eq(test_str_1828, test_str_1828_1828);
}
END_TEST

START_TEST(sprintf_test_1830) {
  char test_str_1830[50] = "";
  char test_str_1830_1830[50] = "";
  s21_sprintf(test_str_1830, "%-G", 123456789.0);
  sprintf(test_str_1830_1830, "%-G", 123456789.0);
  ck_assert_str_eq(test_str_1830, test_str_1830_1830);
}
END_TEST

START_TEST(sprintf_test_1831) {
  char test_str_1831[50] = "";
  char test_str_1831_1831[50] = "";
  s21_sprintf(test_str_1831, "%-G", 0.123456789);
  sprintf(test_str_1831_1831, "%-G", 0.123456789);
  ck_assert_str_eq(test_str_1831, test_str_1831_1831);
}
END_TEST

START_TEST(sprintf_test_1832) {
  char test_str_1832[50] = "";
  char test_str_1832_1832[50] = "";
  s21_sprintf(test_str_1832, "%-G", -123456789.0);
  sprintf(test_str_1832_1832, "%-G", -123456789.0);
  ck_assert_str_eq(test_str_1832, test_str_1832_1832);
}
END_TEST

START_TEST(sprintf_test_1833) {
  char test_str_1833[50] = "";
  char test_str_1833_1833[50] = "";
  s21_sprintf(test_str_1833, "%-G", -0.123456789);
  sprintf(test_str_1833_1833, "%-G", -0.123456789);
  ck_assert_str_eq(test_str_1833, test_str_1833_1833);
}
END_TEST

START_TEST(sprintf_test_1834) {
  char test_str_1834[50] = "";
  char test_str_1834_1834[50] = "";
  s21_sprintf(test_str_1834, "%-G", 123456789.12345679);
  sprintf(test_str_1834_1834, "%-G", 123456789.12345679);
  ck_assert_str_eq(test_str_1834, test_str_1834_1834);
}
END_TEST

START_TEST(sprintf_test_1835) {
  char test_str_1835[50] = "";
  char test_str_1835_1835[50] = "";
  s21_sprintf(test_str_1835, "%-G", -123456789.12345678);
  sprintf(test_str_1835_1835, "%-G", -123456789.12345678);
  ck_assert_str_eq(test_str_1835, test_str_1835_1835);
}
END_TEST

START_TEST(sprintf_test_1836) {
  char test_str_1836[50] = "";
  char test_str_1836_1836[50] = "";
  s21_sprintf(test_str_1836, "%-G", 1.23e-09);
  sprintf(test_str_1836_1836, "%-G", 1.23e-09);
  ck_assert_str_eq(test_str_1836, test_str_1836_1836);
}
END_TEST

START_TEST(sprintf_test_1837) {
  char test_str_1837[50] = "";
  char test_str_1837_1837[50] = "";
  s21_sprintf(test_str_1837, "%-G", 1.23e-09);
  sprintf(test_str_1837_1837, "%-G", 1.23e-09);
  ck_assert_str_eq(test_str_1837, test_str_1837_1837);
}
END_TEST

START_TEST(sprintf_test_1838) {
  char test_str_1838[50] = "";
  char test_str_1838_1838[50] = "";
  s21_sprintf(test_str_1838, "%+e", 0.0);
  sprintf(test_str_1838_1838, "%+e", 0.0);
  ck_assert_str_eq(test_str_1838, test_str_1838_1838);
}
END_TEST

START_TEST(sprintf_test_1839) {
  char test_str_1839[50] = "";
  char test_str_1839_1839[50] = "";
  s21_sprintf(test_str_1839, "%+e", 123456789.0);
  sprintf(test_str_1839_1839, "%+e", 123456789.0);
  ck_assert_str_eq(test_str_1839, test_str_1839_1839);
}
END_TEST

START_TEST(sprintf_test_1840) {
  char test_str_1840[50] = "";
  char test_str_1840_1840[50] = "";
  s21_sprintf(test_str_1840, "%+e", 0.123456789);
  sprintf(test_str_1840_1840, "%+e", 0.123456789);
  ck_assert_str_eq(test_str_1840, test_str_1840_1840);
}
END_TEST

START_TEST(sprintf_test_1841) {
  char test_str_1841[50] = "";
  char test_str_1841_1841[50] = "";
  s21_sprintf(test_str_1841, "%+e", -123456789.0);
  sprintf(test_str_1841_1841, "%+e", -123456789.0);
  ck_assert_str_eq(test_str_1841, test_str_1841_1841);
}
END_TEST

START_TEST(sprintf_test_1842) {
  char test_str_1842[50] = "";
  char test_str_1842_1842[50] = "";
  s21_sprintf(test_str_1842, "%+e", -0.123456789);
  sprintf(test_str_1842_1842, "%+e", -0.123456789);
  ck_assert_str_eq(test_str_1842, test_str_1842_1842);
}
END_TEST

START_TEST(sprintf_test_1843) {
  char test_str_1843[50] = "";
  char test_str_1843_1843[50] = "";
  s21_sprintf(test_str_1843, "%+e", 123456789.12345679);
  sprintf(test_str_1843_1843, "%+e", 123456789.12345679);
  ck_assert_str_eq(test_str_1843, test_str_1843_1843);
}
END_TEST

START_TEST(sprintf_test_1844) {
  char test_str_1844[50] = "";
  char test_str_1844_1844[50] = "";
  s21_sprintf(test_str_1844, "%+e", -123456789.12345678);
  sprintf(test_str_1844_1844, "%+e", -123456789.12345678);
  ck_assert_str_eq(test_str_1844, test_str_1844_1844);
}
END_TEST

START_TEST(sprintf_test_1845) {
  char test_str_1845[50] = "";
  char test_str_1845_1845[50] = "";
  s21_sprintf(test_str_1845, "%+e", 1.23e-09);
  sprintf(test_str_1845_1845, "%+e", 1.23e-09);
  ck_assert_str_eq(test_str_1845, test_str_1845_1845);
}
END_TEST

START_TEST(sprintf_test_1846) {
  char test_str_1846[50] = "";
  char test_str_1846_1846[50] = "";
  s21_sprintf(test_str_1846, "%+e", 1.23e-09);
  sprintf(test_str_1846_1846, "%+e", 1.23e-09);
  ck_assert_str_eq(test_str_1846, test_str_1846_1846);
}
END_TEST

START_TEST(sprintf_test_1847) {
  char test_str_1847[50] = "";
  char test_str_1847_1847[50] = "";
  s21_sprintf(test_str_1847, "%+E", 0.0);
  sprintf(test_str_1847_1847, "%+E", 0.0);
  ck_assert_str_eq(test_str_1847, test_str_1847_1847);
}
END_TEST

START_TEST(sprintf_test_1848) {
  char test_str_1848[50] = "";
  char test_str_1848_1848[50] = "";
  s21_sprintf(test_str_1848, "%+E", 123456789.0);
  sprintf(test_str_1848_1848, "%+E", 123456789.0);
  ck_assert_str_eq(test_str_1848, test_str_1848_1848);
}
END_TEST

START_TEST(sprintf_test_1849) {
  char test_str_1849[50] = "";
  char test_str_1849_1849[50] = "";
  s21_sprintf(test_str_1849, "%+E", 0.123456789);
  sprintf(test_str_1849_1849, "%+E", 0.123456789);
  ck_assert_str_eq(test_str_1849, test_str_1849_1849);
}
END_TEST

START_TEST(sprintf_test_1850) {
  char test_str_1850[50] = "";
  char test_str_1850_1850[50] = "";
  s21_sprintf(test_str_1850, "%+E", -123456789.0);
  sprintf(test_str_1850_1850, "%+E", -123456789.0);
  ck_assert_str_eq(test_str_1850, test_str_1850_1850);
}
END_TEST

START_TEST(sprintf_test_1851) {
  char test_str_1851[50] = "";
  char test_str_1851_1851[50] = "";
  s21_sprintf(test_str_1851, "%+E", -0.123456789);
  sprintf(test_str_1851_1851, "%+E", -0.123456789);
  ck_assert_str_eq(test_str_1851, test_str_1851_1851);
}
END_TEST

START_TEST(sprintf_test_1852) {
  char test_str_1852[50] = "";
  char test_str_1852_1852[50] = "";
  s21_sprintf(test_str_1852, "%+E", 123456789.12345679);
  sprintf(test_str_1852_1852, "%+E", 123456789.12345679);
  ck_assert_str_eq(test_str_1852, test_str_1852_1852);
}
END_TEST

START_TEST(sprintf_test_1853) {
  char test_str_1853[50] = "";
  char test_str_1853_1853[50] = "";
  s21_sprintf(test_str_1853, "%+E", -123456789.12345678);
  sprintf(test_str_1853_1853, "%+E", -123456789.12345678);
  ck_assert_str_eq(test_str_1853, test_str_1853_1853);
}
END_TEST

START_TEST(sprintf_test_1854) {
  char test_str_1854[50] = "";
  char test_str_1854_1854[50] = "";
  s21_sprintf(test_str_1854, "%+E", 1.23e-09);
  sprintf(test_str_1854_1854, "%+E", 1.23e-09);
  ck_assert_str_eq(test_str_1854, test_str_1854_1854);
}
END_TEST

START_TEST(sprintf_test_1855) {
  char test_str_1855[50] = "";
  char test_str_1855_1855[50] = "";
  s21_sprintf(test_str_1855, "%+E", 1.23e-09);
  sprintf(test_str_1855_1855, "%+E", 1.23e-09);
  ck_assert_str_eq(test_str_1855, test_str_1855_1855);
}
END_TEST

START_TEST(sprintf_test_1856) {
  char test_str_1856[50] = "";
  char test_str_1856_1856[50] = "";
  s21_sprintf(test_str_1856, "%+g", 0.0);
  sprintf(test_str_1856_1856, "%+g", 0.0);
  ck_assert_str_eq(test_str_1856, test_str_1856_1856);
}
END_TEST

START_TEST(sprintf_test_1857) {
  char test_str_1857[50] = "";
  char test_str_1857_1857[50] = "";
  s21_sprintf(test_str_1857, "%+g", 123456789.0);
  sprintf(test_str_1857_1857, "%+g", 123456789.0);
  ck_assert_str_eq(test_str_1857, test_str_1857_1857);
}
END_TEST

START_TEST(sprintf_test_1858) {
  char test_str_1858[50] = "";
  char test_str_1858_1858[50] = "";
  s21_sprintf(test_str_1858, "%+g", 0.123456789);
  sprintf(test_str_1858_1858, "%+g", 0.123456789);
  ck_assert_str_eq(test_str_1858, test_str_1858_1858);
}
END_TEST

START_TEST(sprintf_test_1859) {
  char test_str_1859[50] = "";
  char test_str_1859_1859[50] = "";
  s21_sprintf(test_str_1859, "%+g", -123456789.0);
  sprintf(test_str_1859_1859, "%+g", -123456789.0);
  ck_assert_str_eq(test_str_1859, test_str_1859_1859);
}
END_TEST

START_TEST(sprintf_test_1860) {
  char test_str_1860[50] = "";
  char test_str_1860_1860[50] = "";
  s21_sprintf(test_str_1860, "%+g", -0.123456789);
  sprintf(test_str_1860_1860, "%+g", -0.123456789);
  ck_assert_str_eq(test_str_1860, test_str_1860_1860);
}
END_TEST

START_TEST(sprintf_test_1861) {
  char test_str_1861[50] = "";
  char test_str_1861_1861[50] = "";
  s21_sprintf(test_str_1861, "%+g", 123456789.12345679);
  sprintf(test_str_1861_1861, "%+g", 123456789.12345679);
  ck_assert_str_eq(test_str_1861, test_str_1861_1861);
}
END_TEST

START_TEST(sprintf_test_1862) {
  char test_str_1862[50] = "";
  char test_str_1862_1862[50] = "";
  s21_sprintf(test_str_1862, "%+g", -123456789.12345678);
  sprintf(test_str_1862_1862, "%+g", -123456789.12345678);
  ck_assert_str_eq(test_str_1862, test_str_1862_1862);
}
END_TEST

START_TEST(sprintf_test_1863) {
  char test_str_1863[50] = "";
  char test_str_1863_1863[50] = "";
  s21_sprintf(test_str_1863, "%+g", 1.23e-09);
  sprintf(test_str_1863_1863, "%+g", 1.23e-09);
  ck_assert_str_eq(test_str_1863, test_str_1863_1863);
}
END_TEST

START_TEST(sprintf_test_1864) {
  char test_str_1864[50] = "";
  char test_str_1864_1864[50] = "";
  s21_sprintf(test_str_1864, "%+g", 1.23e-09);
  sprintf(test_str_1864_1864, "%+g", 1.23e-09);
  ck_assert_str_eq(test_str_1864, test_str_1864_1864);
}
END_TEST

START_TEST(sprintf_test_1865) {
  char test_str_1865[50] = "";
  char test_str_1865_1865[50] = "";
  s21_sprintf(test_str_1865, "%+G", 0.0);
  sprintf(test_str_1865_1865, "%+G", 0.0);
  ck_assert_str_eq(test_str_1865, test_str_1865_1865);
}
END_TEST

START_TEST(sprintf_test_1866) {
  char test_str_1866[50] = "";
  char test_str_1866_1866[50] = "";
  s21_sprintf(test_str_1866, "%+G", 123456789.0);
  sprintf(test_str_1866_1866, "%+G", 123456789.0);
  ck_assert_str_eq(test_str_1866, test_str_1866_1866);
}
END_TEST

START_TEST(sprintf_test_1867) {
  char test_str_1867[50] = "";
  char test_str_1867_1867[50] = "";
  s21_sprintf(test_str_1867, "%+G", 0.123456789);
  sprintf(test_str_1867_1867, "%+G", 0.123456789);
  ck_assert_str_eq(test_str_1867, test_str_1867_1867);
}
END_TEST

START_TEST(sprintf_test_1868) {
  char test_str_1868[50] = "";
  char test_str_1868_1868[50] = "";
  s21_sprintf(test_str_1868, "%+G", -123456789.0);
  sprintf(test_str_1868_1868, "%+G", -123456789.0);
  ck_assert_str_eq(test_str_1868, test_str_1868_1868);
}
END_TEST

START_TEST(sprintf_test_1869) {
  char test_str_1869[50] = "";
  char test_str_1869_1869[50] = "";
  s21_sprintf(test_str_1869, "%+G", -0.123456789);
  sprintf(test_str_1869_1869, "%+G", -0.123456789);
  ck_assert_str_eq(test_str_1869, test_str_1869_1869);
}
END_TEST

START_TEST(sprintf_test_1870) {
  char test_str_1870[50] = "";
  char test_str_1870_1870[50] = "";
  s21_sprintf(test_str_1870, "%+G", 123456789.12345679);
  sprintf(test_str_1870_1870, "%+G", 123456789.12345679);
  ck_assert_str_eq(test_str_1870, test_str_1870_1870);
}
END_TEST

START_TEST(sprintf_test_1871) {
  char test_str_1871[50] = "";
  char test_str_1871_1871[50] = "";
  s21_sprintf(test_str_1871, "%+G", -123456789.12345678);
  sprintf(test_str_1871_1871, "%+G", -123456789.12345678);
  ck_assert_str_eq(test_str_1871, test_str_1871_1871);
}
END_TEST

START_TEST(sprintf_test_1872) {
  char test_str_1872[50] = "";
  char test_str_1872_1872[50] = "";
  s21_sprintf(test_str_1872, "%+G", 1.23e-09);
  sprintf(test_str_1872_1872, "%+G", 1.23e-09);
  ck_assert_str_eq(test_str_1872, test_str_1872_1872);
}
END_TEST

START_TEST(sprintf_test_1873) {
  char test_str_1873[50] = "";
  char test_str_1873_1873[50] = "";
  s21_sprintf(test_str_1873, "%+G", 1.23e-09);
  sprintf(test_str_1873_1873, "%+G", 1.23e-09);
  ck_assert_str_eq(test_str_1873, test_str_1873_1873);
}
END_TEST

START_TEST(sprintf_test_1874) {
  char test_str_1874[50] = "";
  char test_str_1874_1874[50] = "";
  s21_sprintf(test_str_1874, "% e", 0.0);
  sprintf(test_str_1874_1874, "% e", 0.0);
  ck_assert_str_eq(test_str_1874, test_str_1874_1874);
}
END_TEST

START_TEST(sprintf_test_1875) {
  char test_str_1875[50] = "";
  char test_str_1875_1875[50] = "";
  s21_sprintf(test_str_1875, "% e", 123456789.0);
  sprintf(test_str_1875_1875, "% e", 123456789.0);
  ck_assert_str_eq(test_str_1875, test_str_1875_1875);
}
END_TEST

START_TEST(sprintf_test_1876) {
  char test_str_1876[50] = "";
  char test_str_1876_1876[50] = "";
  s21_sprintf(test_str_1876, "% e", 0.123456789);
  sprintf(test_str_1876_1876, "% e", 0.123456789);
  ck_assert_str_eq(test_str_1876, test_str_1876_1876);
}
END_TEST

START_TEST(sprintf_test_1877) {
  char test_str_1877[50] = "";
  char test_str_1877_1877[50] = "";
  s21_sprintf(test_str_1877, "% e", -123456789.0);
  sprintf(test_str_1877_1877, "% e", -123456789.0);
  ck_assert_str_eq(test_str_1877, test_str_1877_1877);
}
END_TEST

START_TEST(sprintf_test_1878) {
  char test_str_1878[50] = "";
  char test_str_1878_1878[50] = "";
  s21_sprintf(test_str_1878, "% e", -0.123456789);
  sprintf(test_str_1878_1878, "% e", -0.123456789);
  ck_assert_str_eq(test_str_1878, test_str_1878_1878);
}
END_TEST

START_TEST(sprintf_test_1879) {
  char test_str_1879[50] = "";
  char test_str_1879_1879[50] = "";
  s21_sprintf(test_str_1879, "% e", 123456789.12345679);
  sprintf(test_str_1879_1879, "% e", 123456789.12345679);
  ck_assert_str_eq(test_str_1879, test_str_1879_1879);
}
END_TEST

START_TEST(sprintf_test_1880) {
  char test_str_1880[50] = "";
  char test_str_1880_1880[50] = "";
  s21_sprintf(test_str_1880, "% e", -123456789.12345678);
  sprintf(test_str_1880_1880, "% e", -123456789.12345678);
  ck_assert_str_eq(test_str_1880, test_str_1880_1880);
}
END_TEST

START_TEST(sprintf_test_1881) {
  char test_str_1881[50] = "";
  char test_str_1881_1881[50] = "";
  s21_sprintf(test_str_1881, "% e", 1.23e-09);
  sprintf(test_str_1881_1881, "% e", 1.23e-09);
  ck_assert_str_eq(test_str_1881, test_str_1881_1881);
}
END_TEST

START_TEST(sprintf_test_1882) {
  char test_str_1882[50] = "";
  char test_str_1882_1882[50] = "";
  s21_sprintf(test_str_1882, "% e", 1.23e-09);
  sprintf(test_str_1882_1882, "% e", 1.23e-09);
  ck_assert_str_eq(test_str_1882, test_str_1882_1882);
}
END_TEST

START_TEST(sprintf_test_1883) {
  char test_str_1883[50] = "";
  char test_str_1883_1883[50] = "";
  s21_sprintf(test_str_1883, "% E", 0.0);
  sprintf(test_str_1883_1883, "% E", 0.0);
  ck_assert_str_eq(test_str_1883, test_str_1883_1883);
}
END_TEST

START_TEST(sprintf_test_1884) {
  char test_str_1884[50] = "";
  char test_str_1884_1884[50] = "";
  s21_sprintf(test_str_1884, "% E", 123456789.0);
  sprintf(test_str_1884_1884, "% E", 123456789.0);
  ck_assert_str_eq(test_str_1884, test_str_1884_1884);
}
END_TEST

START_TEST(sprintf_test_1885) {
  char test_str_1885[50] = "";
  char test_str_1885_1885[50] = "";
  s21_sprintf(test_str_1885, "% E", 0.123456789);
  sprintf(test_str_1885_1885, "% E", 0.123456789);
  ck_assert_str_eq(test_str_1885, test_str_1885_1885);
}
END_TEST

START_TEST(sprintf_test_1886) {
  char test_str_1886[50] = "";
  char test_str_1886_1886[50] = "";
  s21_sprintf(test_str_1886, "% E", -123456789.0);
  sprintf(test_str_1886_1886, "% E", -123456789.0);
  ck_assert_str_eq(test_str_1886, test_str_1886_1886);
}
END_TEST

START_TEST(sprintf_test_1887) {
  char test_str_1887[50] = "";
  char test_str_1887_1887[50] = "";
  s21_sprintf(test_str_1887, "% E", -0.123456789);
  sprintf(test_str_1887_1887, "% E", -0.123456789);
  ck_assert_str_eq(test_str_1887, test_str_1887_1887);
}
END_TEST

START_TEST(sprintf_test_1888) {
  char test_str_1888[50] = "";
  char test_str_1888_1888[50] = "";
  s21_sprintf(test_str_1888, "% E", 123456789.12345679);
  sprintf(test_str_1888_1888, "% E", 123456789.12345679);
  ck_assert_str_eq(test_str_1888, test_str_1888_1888);
}
END_TEST

START_TEST(sprintf_test_1889) {
  char test_str_1889[50] = "";
  char test_str_1889_1889[50] = "";
  s21_sprintf(test_str_1889, "% E", -123456789.12345678);
  sprintf(test_str_1889_1889, "% E", -123456789.12345678);
  ck_assert_str_eq(test_str_1889, test_str_1889_1889);
}
END_TEST

START_TEST(sprintf_test_1890) {
  char test_str_1890[50] = "";
  char test_str_1890_1890[50] = "";
  s21_sprintf(test_str_1890, "% E", 1.23e-09);
  sprintf(test_str_1890_1890, "% E", 1.23e-09);
  ck_assert_str_eq(test_str_1890, test_str_1890_1890);
}
END_TEST

START_TEST(sprintf_test_1891) {
  char test_str_1891[50] = "";
  char test_str_1891_1891[50] = "";
  s21_sprintf(test_str_1891, "% E", 1.23e-09);
  sprintf(test_str_1891_1891, "% E", 1.23e-09);
  ck_assert_str_eq(test_str_1891, test_str_1891_1891);
}
END_TEST

START_TEST(sprintf_test_1892) {
  char test_str_1892[50] = "";
  char test_str_1892_1892[50] = "";
  s21_sprintf(test_str_1892, "% g", 0.0);
  sprintf(test_str_1892_1892, "% g", 0.0);
  ck_assert_str_eq(test_str_1892, test_str_1892_1892);
}
END_TEST

START_TEST(sprintf_test_1893) {
  char test_str_1893[50] = "";
  char test_str_1893_1893[50] = "";
  s21_sprintf(test_str_1893, "% g", 123456789.0);
  sprintf(test_str_1893_1893, "% g", 123456789.0);
  ck_assert_str_eq(test_str_1893, test_str_1893_1893);
}
END_TEST

START_TEST(sprintf_test_1894) {
  char test_str_1894[50] = "";
  char test_str_1894_1894[50] = "";
  s21_sprintf(test_str_1894, "% g", 0.123456789);
  sprintf(test_str_1894_1894, "% g", 0.123456789);
  ck_assert_str_eq(test_str_1894, test_str_1894_1894);
}
END_TEST

START_TEST(sprintf_test_1895) {
  char test_str_1895[50] = "";
  char test_str_1895_1895[50] = "";
  s21_sprintf(test_str_1895, "% g", -123456789.0);
  sprintf(test_str_1895_1895, "% g", -123456789.0);
  ck_assert_str_eq(test_str_1895, test_str_1895_1895);
}
END_TEST

START_TEST(sprintf_test_1896) {
  char test_str_1896[50] = "";
  char test_str_1896_1896[50] = "";
  s21_sprintf(test_str_1896, "% g", -0.123456789);
  sprintf(test_str_1896_1896, "% g", -0.123456789);
  ck_assert_str_eq(test_str_1896, test_str_1896_1896);
}
END_TEST

START_TEST(sprintf_test_1897) {
  char test_str_1897[50] = "";
  char test_str_1897_1897[50] = "";
  s21_sprintf(test_str_1897, "% g", 123456789.12345679);
  sprintf(test_str_1897_1897, "% g", 123456789.12345679);
  ck_assert_str_eq(test_str_1897, test_str_1897_1897);
}
END_TEST

START_TEST(sprintf_test_1898) {
  char test_str_1898[50] = "";
  char test_str_1898_1898[50] = "";
  s21_sprintf(test_str_1898, "% g", -123456789.12345678);
  sprintf(test_str_1898_1898, "% g", -123456789.12345678);
  ck_assert_str_eq(test_str_1898, test_str_1898_1898);
}
END_TEST

START_TEST(sprintf_test_1899) {
  char test_str_1899[50] = "";
  char test_str_1899_1899[50] = "";
  s21_sprintf(test_str_1899, "% g", 1.23e-09);
  sprintf(test_str_1899_1899, "% g", 1.23e-09);
  ck_assert_str_eq(test_str_1899, test_str_1899_1899);
}
END_TEST

START_TEST(sprintf_test_1900) {
  char test_str_1900[50] = "";
  char test_str_1900_1900[50] = "";
  s21_sprintf(test_str_1900, "% g", 1.23e-09);
  sprintf(test_str_1900_1900, "% g", 1.23e-09);
  ck_assert_str_eq(test_str_1900, test_str_1900_1900);
}
END_TEST

START_TEST(sprintf_test_1901) {
  char test_str_1901[50] = "";
  char test_str_1901_1901[50] = "";
  s21_sprintf(test_str_1901, "% G", 0.0);
  sprintf(test_str_1901_1901, "% G", 0.0);
  ck_assert_str_eq(test_str_1901, test_str_1901_1901);
}
END_TEST

START_TEST(sprintf_test_1902) {
  char test_str_1902[50] = "";
  char test_str_1902_1902[50] = "";
  s21_sprintf(test_str_1902, "% G", 123456789.0);
  sprintf(test_str_1902_1902, "% G", 123456789.0);
  ck_assert_str_eq(test_str_1902, test_str_1902_1902);
}
END_TEST

START_TEST(sprintf_test_1903) {
  char test_str_1903[50] = "";
  char test_str_1903_1903[50] = "";
  s21_sprintf(test_str_1903, "% G", 0.123456789);
  sprintf(test_str_1903_1903, "% G", 0.123456789);
  ck_assert_str_eq(test_str_1903, test_str_1903_1903);
}
END_TEST

START_TEST(sprintf_test_1904) {
  char test_str_1904[50] = "";
  char test_str_1904_1904[50] = "";
  s21_sprintf(test_str_1904, "% G", -123456789.0);
  sprintf(test_str_1904_1904, "% G", -123456789.0);
  ck_assert_str_eq(test_str_1904, test_str_1904_1904);
}
END_TEST

START_TEST(sprintf_test_1905) {
  char test_str_1905[50] = "";
  char test_str_1905_1905[50] = "";
  s21_sprintf(test_str_1905, "% G", -0.123456789);
  sprintf(test_str_1905_1905, "% G", -0.123456789);
  ck_assert_str_eq(test_str_1905, test_str_1905_1905);
}
END_TEST

START_TEST(sprintf_test_1906) {
  char test_str_1906[50] = "";
  char test_str_1906_1906[50] = "";
  s21_sprintf(test_str_1906, "% G", 123456789.12345679);
  sprintf(test_str_1906_1906, "% G", 123456789.12345679);
  ck_assert_str_eq(test_str_1906, test_str_1906_1906);
}
END_TEST

START_TEST(sprintf_test_1907) {
  char test_str_1907[50] = "";
  char test_str_1907_1907[50] = "";
  s21_sprintf(test_str_1907, "% G", -123456789.12345678);
  sprintf(test_str_1907_1907, "% G", -123456789.12345678);
  ck_assert_str_eq(test_str_1907, test_str_1907_1907);
}
END_TEST

START_TEST(sprintf_test_1908) {
  char test_str_1908[50] = "";
  char test_str_1908_1908[50] = "";
  s21_sprintf(test_str_1908, "% G", 1.23e-09);
  sprintf(test_str_1908_1908, "% G", 1.23e-09);
  ck_assert_str_eq(test_str_1908, test_str_1908_1908);
}
END_TEST

START_TEST(sprintf_test_1909) {
  char test_str_1909[50] = "";
  char test_str_1909_1909[50] = "";
  s21_sprintf(test_str_1909, "% G", 1.23e-09);
  sprintf(test_str_1909_1909, "% G", 1.23e-09);
  ck_assert_str_eq(test_str_1909, test_str_1909_1909);
}
END_TEST

START_TEST(sprintf_test_1910) {
  char test_str_1910[50] = "";
  char test_str_1910_1910[50] = "";
  s21_sprintf(test_str_1910, "%#e", 0.0);
  sprintf(test_str_1910_1910, "%#e", 0.0);
  ck_assert_str_eq(test_str_1910, test_str_1910_1910);
}
END_TEST

START_TEST(sprintf_test_1911) {
  char test_str_1911[50] = "";
  char test_str_1911_1911[50] = "";
  s21_sprintf(test_str_1911, "%#e", 123456789.0);
  sprintf(test_str_1911_1911, "%#e", 123456789.0);
  ck_assert_str_eq(test_str_1911, test_str_1911_1911);
}
END_TEST

START_TEST(sprintf_test_1912) {
  char test_str_1912[50] = "";
  char test_str_1912_1912[50] = "";
  s21_sprintf(test_str_1912, "%#e", 0.123456789);
  sprintf(test_str_1912_1912, "%#e", 0.123456789);
  ck_assert_str_eq(test_str_1912, test_str_1912_1912);
}
END_TEST

START_TEST(sprintf_test_1913) {
  char test_str_1913[50] = "";
  char test_str_1913_1913[50] = "";
  s21_sprintf(test_str_1913, "%#e", -123456789.0);
  sprintf(test_str_1913_1913, "%#e", -123456789.0);
  ck_assert_str_eq(test_str_1913, test_str_1913_1913);
}
END_TEST

START_TEST(sprintf_test_1914) {
  char test_str_1914[50] = "";
  char test_str_1914_1914[50] = "";
  s21_sprintf(test_str_1914, "%#e", -0.123456789);
  sprintf(test_str_1914_1914, "%#e", -0.123456789);
  ck_assert_str_eq(test_str_1914, test_str_1914_1914);
}
END_TEST

START_TEST(sprintf_test_1915) {
  char test_str_1915[50] = "";
  char test_str_1915_1915[50] = "";
  s21_sprintf(test_str_1915, "%#e", 123456789.12345679);
  sprintf(test_str_1915_1915, "%#e", 123456789.12345679);
  ck_assert_str_eq(test_str_1915, test_str_1915_1915);
}
END_TEST

START_TEST(sprintf_test_1916) {
  char test_str_1916[50] = "";
  char test_str_1916_1916[50] = "";
  s21_sprintf(test_str_1916, "%#e", -123456789.12345678);
  sprintf(test_str_1916_1916, "%#e", -123456789.12345678);
  ck_assert_str_eq(test_str_1916, test_str_1916_1916);
}
END_TEST

START_TEST(sprintf_test_1917) {
  char test_str_1917[50] = "";
  char test_str_1917_1917[50] = "";
  s21_sprintf(test_str_1917, "%#e", 1.23e-09);
  sprintf(test_str_1917_1917, "%#e", 1.23e-09);
  ck_assert_str_eq(test_str_1917, test_str_1917_1917);
}
END_TEST

START_TEST(sprintf_test_1918) {
  char test_str_1918[50] = "";
  char test_str_1918_1918[50] = "";
  s21_sprintf(test_str_1918, "%#e", 1.23e-09);
  sprintf(test_str_1918_1918, "%#e", 1.23e-09);
  ck_assert_str_eq(test_str_1918, test_str_1918_1918);
}
END_TEST

START_TEST(sprintf_test_1919) {
  char test_str_1919[50] = "";
  char test_str_1919_1919[50] = "";
  s21_sprintf(test_str_1919, "%#E", 0.0);
  sprintf(test_str_1919_1919, "%#E", 0.0);
  ck_assert_str_eq(test_str_1919, test_str_1919_1919);
}
END_TEST

START_TEST(sprintf_test_1920) {
  char test_str_1920[50] = "";
  char test_str_1920_1920[50] = "";
  s21_sprintf(test_str_1920, "%#E", 123456789.0);
  sprintf(test_str_1920_1920, "%#E", 123456789.0);
  ck_assert_str_eq(test_str_1920, test_str_1920_1920);
}
END_TEST

START_TEST(sprintf_test_1921) {
  char test_str_1921[50] = "";
  char test_str_1921_1921[50] = "";
  s21_sprintf(test_str_1921, "%#E", 0.123456789);
  sprintf(test_str_1921_1921, "%#E", 0.123456789);
  ck_assert_str_eq(test_str_1921, test_str_1921_1921);
}
END_TEST

START_TEST(sprintf_test_1922) {
  char test_str_1922[50] = "";
  char test_str_1922_1922[50] = "";
  s21_sprintf(test_str_1922, "%#E", -123456789.0);
  sprintf(test_str_1922_1922, "%#E", -123456789.0);
  ck_assert_str_eq(test_str_1922, test_str_1922_1922);
}
END_TEST

START_TEST(sprintf_test_1923) {
  char test_str_1923[50] = "";
  char test_str_1923_1923[50] = "";
  s21_sprintf(test_str_1923, "%#E", -0.123456789);
  sprintf(test_str_1923_1923, "%#E", -0.123456789);
  ck_assert_str_eq(test_str_1923, test_str_1923_1923);
}
END_TEST

START_TEST(sprintf_test_1924) {
  char test_str_1924[50] = "";
  char test_str_1924_1924[50] = "";
  s21_sprintf(test_str_1924, "%#E", 123456789.12345679);
  sprintf(test_str_1924_1924, "%#E", 123456789.12345679);
  ck_assert_str_eq(test_str_1924, test_str_1924_1924);
}
END_TEST

START_TEST(sprintf_test_1925) {
  char test_str_1925[50] = "";
  char test_str_1925_1925[50] = "";
  s21_sprintf(test_str_1925, "%#E", -123456789.12345678);
  sprintf(test_str_1925_1925, "%#E", -123456789.12345678);
  ck_assert_str_eq(test_str_1925, test_str_1925_1925);
}
END_TEST

START_TEST(sprintf_test_1926) {
  char test_str_1926[50] = "";
  char test_str_1926_1926[50] = "";
  s21_sprintf(test_str_1926, "%#E", 1.23e-09);
  sprintf(test_str_1926_1926, "%#E", 1.23e-09);
  ck_assert_str_eq(test_str_1926, test_str_1926_1926);
}
END_TEST

START_TEST(sprintf_test_1927) {
  char test_str_1927[50] = "";
  char test_str_1927_1927[50] = "";
  s21_sprintf(test_str_1927, "%#E", 1.23e-09);
  sprintf(test_str_1927_1927, "%#E", 1.23e-09);
  ck_assert_str_eq(test_str_1927, test_str_1927_1927);
}
END_TEST

START_TEST(sprintf_test_1928) {
  char test_str_1928[50] = "";
  char test_str_1928_1928[50] = "";
  s21_sprintf(test_str_1928, "%#g", 0.0);
  sprintf(test_str_1928_1928, "%#g", 0.0);
  ck_assert_str_eq(test_str_1928, test_str_1928_1928);
}
END_TEST

START_TEST(sprintf_test_1929) {
  char test_str_1929[50] = "";
  char test_str_1929_1929[50] = "";
  s21_sprintf(test_str_1929, "%#g", 123456789.0);
  sprintf(test_str_1929_1929, "%#g", 123456789.0);
  ck_assert_str_eq(test_str_1929, test_str_1929_1929);
}
END_TEST

START_TEST(sprintf_test_1930) {
  char test_str_1930[50] = "";
  char test_str_1930_1930[50] = "";
  s21_sprintf(test_str_1930, "%#g", 0.123456789);
  sprintf(test_str_1930_1930, "%#g", 0.123456789);
  ck_assert_str_eq(test_str_1930, test_str_1930_1930);
}
END_TEST

START_TEST(sprintf_test_1931) {
  char test_str_1931[50] = "";
  char test_str_1931_1931[50] = "";
  s21_sprintf(test_str_1931, "%#g", -123456789.0);
  sprintf(test_str_1931_1931, "%#g", -123456789.0);
  ck_assert_str_eq(test_str_1931, test_str_1931_1931);
}
END_TEST

START_TEST(sprintf_test_1932) {
  char test_str_1932[50] = "";
  char test_str_1932_1932[50] = "";
  s21_sprintf(test_str_1932, "%#g", -0.123456789);
  sprintf(test_str_1932_1932, "%#g", -0.123456789);
  ck_assert_str_eq(test_str_1932, test_str_1932_1932);
}
END_TEST

START_TEST(sprintf_test_1933) {
  char test_str_1933[50] = "";
  char test_str_1933_1933[50] = "";
  s21_sprintf(test_str_1933, "%#g", 123456789.12345679);
  sprintf(test_str_1933_1933, "%#g", 123456789.12345679);
  ck_assert_str_eq(test_str_1933, test_str_1933_1933);
}
END_TEST

START_TEST(sprintf_test_1934) {
  char test_str_1934[50] = "";
  char test_str_1934_1934[50] = "";
  s21_sprintf(test_str_1934, "%#g", -123456789.12345678);
  sprintf(test_str_1934_1934, "%#g", -123456789.12345678);
  ck_assert_str_eq(test_str_1934, test_str_1934_1934);
}
END_TEST

START_TEST(sprintf_test_1935) {
  char test_str_1935[50] = "";
  char test_str_1935_1935[50] = "";
  s21_sprintf(test_str_1935, "%#g", 1.23e-09);
  sprintf(test_str_1935_1935, "%#g", 1.23e-09);
  ck_assert_str_eq(test_str_1935, test_str_1935_1935);
}
END_TEST

START_TEST(sprintf_test_1936) {
  char test_str_1936[50] = "";
  char test_str_1936_1936[50] = "";
  s21_sprintf(test_str_1936, "%#g", 1.23e-09);
  sprintf(test_str_1936_1936, "%#g", 1.23e-09);
  ck_assert_str_eq(test_str_1936, test_str_1936_1936);
}
END_TEST

START_TEST(sprintf_test_1937) {
  char test_str_1937[50] = "";
  char test_str_1937_1937[50] = "";
  s21_sprintf(test_str_1937, "%#G", 0.0);
  sprintf(test_str_1937_1937, "%#G", 0.0);
  ck_assert_str_eq(test_str_1937, test_str_1937_1937);
}
END_TEST

START_TEST(sprintf_test_1938) {
  char test_str_1938[50] = "";
  char test_str_1938_1938[50] = "";
  s21_sprintf(test_str_1938, "%#G", 123456789.0);
  sprintf(test_str_1938_1938, "%#G", 123456789.0);
  ck_assert_str_eq(test_str_1938, test_str_1938_1938);
}
END_TEST

START_TEST(sprintf_test_1939) {
  char test_str_1939[50] = "";
  char test_str_1939_1939[50] = "";
  s21_sprintf(test_str_1939, "%#G", 0.123456789);
  sprintf(test_str_1939_1939, "%#G", 0.123456789);
  ck_assert_str_eq(test_str_1939, test_str_1939_1939);
}
END_TEST

START_TEST(sprintf_test_1940) {
  char test_str_1940[50] = "";
  char test_str_1940_1940[50] = "";
  s21_sprintf(test_str_1940, "%#G", -123456789.0);
  sprintf(test_str_1940_1940, "%#G", -123456789.0);
  ck_assert_str_eq(test_str_1940, test_str_1940_1940);
}
END_TEST

START_TEST(sprintf_test_1941) {
  char test_str_1941[50] = "";
  char test_str_1941_1941[50] = "";
  s21_sprintf(test_str_1941, "%#G", -0.123456789);
  sprintf(test_str_1941_1941, "%#G", -0.123456789);
  ck_assert_str_eq(test_str_1941, test_str_1941_1941);
}
END_TEST

START_TEST(sprintf_test_1942) {
  char test_str_1942[50] = "";
  char test_str_1942_1942[50] = "";
  s21_sprintf(test_str_1942, "%#G", 123456789.12345679);
  sprintf(test_str_1942_1942, "%#G", 123456789.12345679);
  ck_assert_str_eq(test_str_1942, test_str_1942_1942);
}
END_TEST

START_TEST(sprintf_test_1943) {
  char test_str_1943[50] = "";
  char test_str_1943_1943[50] = "";
  s21_sprintf(test_str_1943, "%#G", -123456789.12345678);
  sprintf(test_str_1943_1943, "%#G", -123456789.12345678);
  ck_assert_str_eq(test_str_1943, test_str_1943_1943);
}
END_TEST

START_TEST(sprintf_test_1944) {
  char test_str_1944[50] = "";
  char test_str_1944_1944[50] = "";
  s21_sprintf(test_str_1944, "%#G", 1.23e-09);
  sprintf(test_str_1944_1944, "%#G", 1.23e-09);
  ck_assert_str_eq(test_str_1944, test_str_1944_1944);
}
END_TEST

START_TEST(sprintf_test_1945) {
  char test_str_1945[50] = "";
  char test_str_1945_1945[50] = "";
  s21_sprintf(test_str_1945, "%#G", 1.23e-09);
  sprintf(test_str_1945_1945, "%#G", 1.23e-09);
  ck_assert_str_eq(test_str_1945, test_str_1945_1945);
}
END_TEST

START_TEST(sprintf_test_1946) {
  char test_str_1946[50] = "";
  char test_str_1946_1946[50] = "";
  s21_sprintf(test_str_1946, "%0e", 0.0);
  sprintf(test_str_1946_1946, "%0e", 0.0);
  ck_assert_str_eq(test_str_1946, test_str_1946_1946);
}
END_TEST

START_TEST(sprintf_test_1947) {
  char test_str_1947[50] = "";
  char test_str_1947_1947[50] = "";
  s21_sprintf(test_str_1947, "%0e", 123456789.0);
  sprintf(test_str_1947_1947, "%0e", 123456789.0);
  ck_assert_str_eq(test_str_1947, test_str_1947_1947);
}
END_TEST

START_TEST(sprintf_test_1948) {
  char test_str_1948[50] = "";
  char test_str_1948_1948[50] = "";
  s21_sprintf(test_str_1948, "%0e", 0.123456789);
  sprintf(test_str_1948_1948, "%0e", 0.123456789);
  ck_assert_str_eq(test_str_1948, test_str_1948_1948);
}
END_TEST

START_TEST(sprintf_test_1949) {
  char test_str_1949[50] = "";
  char test_str_1949_1949[50] = "";
  s21_sprintf(test_str_1949, "%0e", -123456789.0);
  sprintf(test_str_1949_1949, "%0e", -123456789.0);
  ck_assert_str_eq(test_str_1949, test_str_1949_1949);
}
END_TEST

START_TEST(sprintf_test_1950) {
  char test_str_1950[50] = "";
  char test_str_1950_1950[50] = "";
  s21_sprintf(test_str_1950, "%0e", -0.123456789);
  sprintf(test_str_1950_1950, "%0e", -0.123456789);
  ck_assert_str_eq(test_str_1950, test_str_1950_1950);
}
END_TEST

START_TEST(sprintf_test_1951) {
  char test_str_1951[50] = "";
  char test_str_1951_1951[50] = "";
  s21_sprintf(test_str_1951, "%0e", 123456789.12345679);
  sprintf(test_str_1951_1951, "%0e", 123456789.12345679);
  ck_assert_str_eq(test_str_1951, test_str_1951_1951);
}
END_TEST

START_TEST(sprintf_test_1952) {
  char test_str_1952[50] = "";
  char test_str_1952_1952[50] = "";
  s21_sprintf(test_str_1952, "%0e", -123456789.12345678);
  sprintf(test_str_1952_1952, "%0e", -123456789.12345678);
  ck_assert_str_eq(test_str_1952, test_str_1952_1952);
}
END_TEST

START_TEST(sprintf_test_1953) {
  char test_str_1953[50] = "";
  char test_str_1953_1953[50] = "";
  s21_sprintf(test_str_1953, "%0e", 1.23e-09);
  sprintf(test_str_1953_1953, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1953, test_str_1953_1953);
}
END_TEST

START_TEST(sprintf_test_1954) {
  char test_str_1954[50] = "";
  char test_str_1954_1954[50] = "";
  s21_sprintf(test_str_1954, "%0e", 1.23e-09);
  sprintf(test_str_1954_1954, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1954, test_str_1954_1954);
}
END_TEST

START_TEST(sprintf_test_1955) {
  char test_str_1955[50] = "";
  char test_str_1955_1955[50] = "";
  s21_sprintf(test_str_1955, "%0E", 0.0);
  sprintf(test_str_1955_1955, "%0E", 0.0);
  ck_assert_str_eq(test_str_1955, test_str_1955_1955);
}
END_TEST

START_TEST(sprintf_test_1956) {
  char test_str_1956[50] = "";
  char test_str_1956_1956[50] = "";
  s21_sprintf(test_str_1956, "%0E", 123456789.0);
  sprintf(test_str_1956_1956, "%0E", 123456789.0);
  ck_assert_str_eq(test_str_1956, test_str_1956_1956);
}
END_TEST

START_TEST(sprintf_test_1957) {
  char test_str_1957[50] = "";
  char test_str_1957_1957[50] = "";
  s21_sprintf(test_str_1957, "%0E", 0.123456789);
  sprintf(test_str_1957_1957, "%0E", 0.123456789);
  ck_assert_str_eq(test_str_1957, test_str_1957_1957);
}
END_TEST

START_TEST(sprintf_test_1958) {
  char test_str_1958[50] = "";
  char test_str_1958_1958[50] = "";
  s21_sprintf(test_str_1958, "%0E", -123456789.0);
  sprintf(test_str_1958_1958, "%0E", -123456789.0);
  ck_assert_str_eq(test_str_1958, test_str_1958_1958);
}
END_TEST

START_TEST(sprintf_test_1959) {
  char test_str_1959[50] = "";
  char test_str_1959_1959[50] = "";
  s21_sprintf(test_str_1959, "%0E", -0.123456789);
  sprintf(test_str_1959_1959, "%0E", -0.123456789);
  ck_assert_str_eq(test_str_1959, test_str_1959_1959);
}
END_TEST

START_TEST(sprintf_test_1960) {
  char test_str_1960[50] = "";
  char test_str_1960_1960[50] = "";
  s21_sprintf(test_str_1960, "%0E", 123456789.12345679);
  sprintf(test_str_1960_1960, "%0E", 123456789.12345679);
  ck_assert_str_eq(test_str_1960, test_str_1960_1960);
}
END_TEST

START_TEST(sprintf_test_1961) {
  char test_str_1961[50] = "";
  char test_str_1961_1961[50] = "";
  s21_sprintf(test_str_1961, "%0E", -123456789.12345678);
  sprintf(test_str_1961_1961, "%0E", -123456789.12345678);
  ck_assert_str_eq(test_str_1961, test_str_1961_1961);
}
END_TEST

START_TEST(sprintf_test_1962) {
  char test_str_1962[50] = "";
  char test_str_1962_1962[50] = "";
  s21_sprintf(test_str_1962, "%0E", 1.23e-09);
  sprintf(test_str_1962_1962, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1962, test_str_1962_1962);
}
END_TEST

START_TEST(sprintf_test_1963) {
  char test_str_1963[50] = "";
  char test_str_1963_1963[50] = "";
  s21_sprintf(test_str_1963, "%0E", 1.23e-09);
  sprintf(test_str_1963_1963, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1963, test_str_1963_1963);
}
END_TEST

START_TEST(sprintf_test_1964) {
  char test_str_1964[50] = "";
  char test_str_1964_1964[50] = "";
  s21_sprintf(test_str_1964, "%0g", 0.0);
  sprintf(test_str_1964_1964, "%0g", 0.0);
  ck_assert_str_eq(test_str_1964, test_str_1964_1964);
}
END_TEST

START_TEST(sprintf_test_1965) {
  char test_str_1965[50] = "";
  char test_str_1965_1965[50] = "";
  s21_sprintf(test_str_1965, "%0g", 123456789.0);
  sprintf(test_str_1965_1965, "%0g", 123456789.0);
  ck_assert_str_eq(test_str_1965, test_str_1965_1965);
}
END_TEST

START_TEST(sprintf_test_1966) {
  char test_str_1966[50] = "";
  char test_str_1966_1966[50] = "";
  s21_sprintf(test_str_1966, "%0g", 0.123456789);
  sprintf(test_str_1966_1966, "%0g", 0.123456789);
  ck_assert_str_eq(test_str_1966, test_str_1966_1966);
}
END_TEST

START_TEST(sprintf_test_1967) {
  char test_str_1967[50] = "";
  char test_str_1967_1967[50] = "";
  s21_sprintf(test_str_1967, "%0g", -123456789.0);
  sprintf(test_str_1967_1967, "%0g", -123456789.0);
  ck_assert_str_eq(test_str_1967, test_str_1967_1967);
}
END_TEST

START_TEST(sprintf_test_1968) {
  char test_str_1968[50] = "";
  char test_str_1968_1968[50] = "";
  s21_sprintf(test_str_1968, "%0g", -0.123456789);
  sprintf(test_str_1968_1968, "%0g", -0.123456789);
  ck_assert_str_eq(test_str_1968, test_str_1968_1968);
}
END_TEST

START_TEST(sprintf_test_1969) {
  char test_str_1969[50] = "";
  char test_str_1969_1969[50] = "";
  s21_sprintf(test_str_1969, "%0g", 123456789.12345679);
  sprintf(test_str_1969_1969, "%0g", 123456789.12345679);
  ck_assert_str_eq(test_str_1969, test_str_1969_1969);
}
END_TEST

START_TEST(sprintf_test_1970) {
  char test_str_1970[50] = "";
  char test_str_1970_1970[50] = "";
  s21_sprintf(test_str_1970, "%0g", -123456789.12345678);
  sprintf(test_str_1970_1970, "%0g", -123456789.12345678);
  ck_assert_str_eq(test_str_1970, test_str_1970_1970);
}
END_TEST

START_TEST(sprintf_test_1971) {
  char test_str_1971[50] = "";
  char test_str_1971_1971[50] = "";
  s21_sprintf(test_str_1971, "%0g", 1.23e-09);
  sprintf(test_str_1971_1971, "%0g", 1.23e-09);
  ck_assert_str_eq(test_str_1971, test_str_1971_1971);
}
END_TEST

START_TEST(sprintf_test_1972) {
  char test_str_1972[50] = "";
  char test_str_1972_1972[50] = "";
  s21_sprintf(test_str_1972, "%0g", 1.23e-09);
  sprintf(test_str_1972_1972, "%0g", 1.23e-09);
  ck_assert_str_eq(test_str_1972, test_str_1972_1972);
}
END_TEST

START_TEST(sprintf_test_1973) {
  char test_str_1973[50] = "";
  char test_str_1973_1973[50] = "";
  s21_sprintf(test_str_1973, "%0G", 0.0);
  sprintf(test_str_1973_1973, "%0G", 0.0);
  ck_assert_str_eq(test_str_1973, test_str_1973_1973);
}
END_TEST

START_TEST(sprintf_test_1974) {
  char test_str_1974[50] = "";
  char test_str_1974_1974[50] = "";
  s21_sprintf(test_str_1974, "%0G", 123456789.0);
  sprintf(test_str_1974_1974, "%0G", 123456789.0);
  ck_assert_str_eq(test_str_1974, test_str_1974_1974);
}
END_TEST

START_TEST(sprintf_test_1975) {
  char test_str_1975[50] = "";
  char test_str_1975_1975[50] = "";
  s21_sprintf(test_str_1975, "%0G", 0.123456789);
  sprintf(test_str_1975_1975, "%0G", 0.123456789);
  ck_assert_str_eq(test_str_1975, test_str_1975_1975);
}
END_TEST

START_TEST(sprintf_test_1976) {
  char test_str_1976[50] = "";
  char test_str_1976_1976[50] = "";
  s21_sprintf(test_str_1976, "%0G", -123456789.0);
  sprintf(test_str_1976_1976, "%0G", -123456789.0);
  ck_assert_str_eq(test_str_1976, test_str_1976_1976);
}
END_TEST

START_TEST(sprintf_test_1977) {
  char test_str_1977[50] = "";
  char test_str_1977_1977[50] = "";
  s21_sprintf(test_str_1977, "%0G", -0.123456789);
  sprintf(test_str_1977_1977, "%0G", -0.123456789);
  ck_assert_str_eq(test_str_1977, test_str_1977_1977);
}
END_TEST

START_TEST(sprintf_test_1978) {
  char test_str_1978[50] = "";
  char test_str_1978_1978[50] = "";
  s21_sprintf(test_str_1978, "%0G", 123456789.12345679);
  sprintf(test_str_1978_1978, "%0G", 123456789.12345679);
  ck_assert_str_eq(test_str_1978, test_str_1978_1978);
}
END_TEST

START_TEST(sprintf_test_1979) {
  char test_str_1979[50] = "";
  char test_str_1979_1979[50] = "";
  s21_sprintf(test_str_1979, "%0G", -123456789.12345678);
  sprintf(test_str_1979_1979, "%0G", -123456789.12345678);
  ck_assert_str_eq(test_str_1979, test_str_1979_1979);
}
END_TEST

START_TEST(sprintf_test_1980) {
  char test_str_1980[50] = "";
  char test_str_1980_1980[50] = "";
  s21_sprintf(test_str_1980, "%0G", 1.23e-09);
  sprintf(test_str_1980_1980, "%0G", 1.23e-09);
  ck_assert_str_eq(test_str_1980, test_str_1980_1980);
}
END_TEST

START_TEST(sprintf_test_1981) {
  char test_str_1981[50] = "";
  char test_str_1981_1981[50] = "";
  s21_sprintf(test_str_1981, "%0G", 1.23e-09);
  sprintf(test_str_1981_1981, "%0G", 1.23e-09);
  ck_assert_str_eq(test_str_1981, test_str_1981_1981);
}
END_TEST

START_TEST(sprintf_test_1982) {
  char test_str_1982[50] = "";
  char test_str_1982_1982[50] = "";
  s21_sprintf(test_str_1982, "%0e", 0.0);
  sprintf(test_str_1982_1982, "%0e", 0.0);
  ck_assert_str_eq(test_str_1982, test_str_1982_1982);
}
END_TEST

START_TEST(sprintf_test_1983) {
  char test_str_1983[50] = "";
  char test_str_1983_1983[50] = "";
  s21_sprintf(test_str_1983, "%0e", 123456789.0);
  sprintf(test_str_1983_1983, "%0e", 123456789.0);
  ck_assert_str_eq(test_str_1983, test_str_1983_1983);
}
END_TEST

START_TEST(sprintf_test_1984) {
  char test_str_1984[50] = "";
  char test_str_1984_1984[50] = "";
  s21_sprintf(test_str_1984, "%0e", 0.123456789);
  sprintf(test_str_1984_1984, "%0e", 0.123456789);
  ck_assert_str_eq(test_str_1984, test_str_1984_1984);
}
END_TEST

START_TEST(sprintf_test_1985) {
  char test_str_1985[50] = "";
  char test_str_1985_1985[50] = "";
  s21_sprintf(test_str_1985, "%0e", -123456789.0);
  sprintf(test_str_1985_1985, "%0e", -123456789.0);
  ck_assert_str_eq(test_str_1985, test_str_1985_1985);
}
END_TEST

START_TEST(sprintf_test_1986) {
  char test_str_1986[50] = "";
  char test_str_1986_1986[50] = "";
  s21_sprintf(test_str_1986, "%0e", -0.123456789);
  sprintf(test_str_1986_1986, "%0e", -0.123456789);
  ck_assert_str_eq(test_str_1986, test_str_1986_1986);
}
END_TEST

START_TEST(sprintf_test_1987) {
  char test_str_1987[50] = "";
  char test_str_1987_1987[50] = "";
  s21_sprintf(test_str_1987, "%0e", 123456789.12345679);
  sprintf(test_str_1987_1987, "%0e", 123456789.12345679);
  ck_assert_str_eq(test_str_1987, test_str_1987_1987);
}
END_TEST

START_TEST(sprintf_test_1988) {
  char test_str_1988[50] = "";
  char test_str_1988_1988[50] = "";
  s21_sprintf(test_str_1988, "%0e", -123456789.12345678);
  sprintf(test_str_1988_1988, "%0e", -123456789.12345678);
  ck_assert_str_eq(test_str_1988, test_str_1988_1988);
}
END_TEST

START_TEST(sprintf_test_1989) {
  char test_str_1989[50] = "";
  char test_str_1989_1989[50] = "";
  s21_sprintf(test_str_1989, "%0e", 1.23e-09);
  sprintf(test_str_1989_1989, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1989, test_str_1989_1989);
}
END_TEST

START_TEST(sprintf_test_1990) {
  char test_str_1990[50] = "";
  char test_str_1990_1990[50] = "";
  s21_sprintf(test_str_1990, "%0e", 1.23e-09);
  sprintf(test_str_1990_1990, "%0e", 1.23e-09);
  ck_assert_str_eq(test_str_1990, test_str_1990_1990);
}
END_TEST

START_TEST(sprintf_test_1991) {
  char test_str_1991[50] = "";
  char test_str_1991_1991[50] = "";
  s21_sprintf(test_str_1991, "%0E", 0.0);
  sprintf(test_str_1991_1991, "%0E", 0.0);
  ck_assert_str_eq(test_str_1991, test_str_1991_1991);
}
END_TEST

START_TEST(sprintf_test_1992) {
  char test_str_1992[50] = "";
  char test_str_1992_1992[50] = "";
  s21_sprintf(test_str_1992, "%0E", 123456789.0);
  sprintf(test_str_1992_1992, "%0E", 123456789.0);
  ck_assert_str_eq(test_str_1992, test_str_1992_1992);
}
END_TEST

START_TEST(sprintf_test_1993) {
  char test_str_1993[50] = "";
  char test_str_1993_1993[50] = "";
  s21_sprintf(test_str_1993, "%0E", 0.123456789);
  sprintf(test_str_1993_1993, "%0E", 0.123456789);
  ck_assert_str_eq(test_str_1993, test_str_1993_1993);
}
END_TEST

START_TEST(sprintf_test_1994) {
  char test_str_1994[50] = "";
  char test_str_1994_1994[50] = "";
  s21_sprintf(test_str_1994, "%0E", -123456789.0);
  sprintf(test_str_1994_1994, "%0E", -123456789.0);
  ck_assert_str_eq(test_str_1994, test_str_1994_1994);
}
END_TEST

START_TEST(sprintf_test_1995) {
  char test_str_1995[50] = "";
  char test_str_1995_1995[50] = "";
  s21_sprintf(test_str_1995, "%0E", -0.123456789);
  sprintf(test_str_1995_1995, "%0E", -0.123456789);
  ck_assert_str_eq(test_str_1995, test_str_1995_1995);
}
END_TEST

START_TEST(sprintf_test_1996) {
  char test_str_1996[50] = "";
  char test_str_1996_1996[50] = "";
  s21_sprintf(test_str_1996, "%0E", 123456789.12345679);
  sprintf(test_str_1996_1996, "%0E", 123456789.12345679);
  ck_assert_str_eq(test_str_1996, test_str_1996_1996);
}
END_TEST

START_TEST(sprintf_test_1997) {
  char test_str_1997[50] = "";
  char test_str_1997_1997[50] = "";
  s21_sprintf(test_str_1997, "%0E", -123456789.12345678);
  sprintf(test_str_1997_1997, "%0E", -123456789.12345678);
  ck_assert_str_eq(test_str_1997, test_str_1997_1997);
}
END_TEST

START_TEST(sprintf_test_1998) {
  char test_str_1998[50] = "";
  char test_str_1998_1998[50] = "";
  s21_sprintf(test_str_1998, "%0E", 1.23e-09);
  sprintf(test_str_1998_1998, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1998, test_str_1998_1998);
}
END_TEST

START_TEST(sprintf_test_1999) {
  char test_str_1999[50] = "";
  char test_str_1999_1999[50] = "";
  s21_sprintf(test_str_1999, "%0E", 1.23e-09);
  sprintf(test_str_1999_1999, "%0E", 1.23e-09);
  ck_assert_str_eq(test_str_1999, test_str_1999_1999);
}
END_TEST

START_TEST(sprintf_test_2000) {
  char test_str_2000[50] = "";
  char test_str_2000_2000[50] = "";
  s21_sprintf(test_str_2000, "%0g", 0.0);
  sprintf(test_str_2000_2000, "%0g", 0.0);
  ck_assert_str_eq(test_str_2000, test_str_2000_2000);
}
END_TEST

START_TEST(sprintf_test_2001) {
  char test_str_2001[50] = "";
  char test_str_2001_2001[50] = "";
  s21_sprintf(test_str_2001, "%0g", 123456789.0);
  sprintf(test_str_2001_2001, "%0g", 123456789.0);
  ck_assert_str_eq(test_str_2001, test_str_2001_2001);
}
END_TEST

START_TEST(sprintf_test_2002) {
  char test_str_2002[50] = "";
  char test_str_2002_2002[50] = "";
  s21_sprintf(test_str_2002, "%0g", 0.123456789);
  sprintf(test_str_2002_2002, "%0g", 0.123456789);
  ck_assert_str_eq(test_str_2002, test_str_2002_2002);
}
END_TEST

START_TEST(sprintf_test_2003) {
  char test_str_2003[50] = "";
  char test_str_2003_2003[50] = "";
  s21_sprintf(test_str_2003, "%0g", -123456789.0);
  sprintf(test_str_2003_2003, "%0g", -123456789.0);
  ck_assert_str_eq(test_str_2003, test_str_2003_2003);
}
END_TEST

START_TEST(sprintf_test_2004) {
  char test_str_2004[50] = "";
  char test_str_2004_2004[50] = "";
  s21_sprintf(test_str_2004, "%0g", -0.123456789);
  sprintf(test_str_2004_2004, "%0g", -0.123456789);
  ck_assert_str_eq(test_str_2004, test_str_2004_2004);
}
END_TEST

START_TEST(sprintf_test_2005) {
  char test_str_2005[50] = "";
  char test_str_2005_2005[50] = "";
  s21_sprintf(test_str_2005, "%0g", 123456789.12345679);
  sprintf(test_str_2005_2005, "%0g", 123456789.12345679);
  ck_assert_str_eq(test_str_2005, test_str_2005_2005);
}
END_TEST

START_TEST(sprintf_test_2006) {
  char test_str_2006[50] = "";
  char test_str_2006_2006[50] = "";
  s21_sprintf(test_str_2006, "%0g", -123456789.12345678);
  sprintf(test_str_2006_2006, "%0g", -123456789.12345678);
  ck_assert_str_eq(test_str_2006, test_str_2006_2006);
}
END_TEST

START_TEST(sprintf_test_2007) {
  char test_str_2007[50] = "";
  char test_str_2007_2007[50] = "";
  s21_sprintf(test_str_2007, "%0g", 1.23e-09);
  sprintf(test_str_2007_2007, "%0g", 1.23e-09);
  ck_assert_str_eq(test_str_2007, test_str_2007_2007);
}
END_TEST

START_TEST(sprintf_test_2008) {
  char test_str_2008[50] = "";
  char test_str_2008_2008[50] = "";
  s21_sprintf(test_str_2008, "%0g", 1.23e-09);
  sprintf(test_str_2008_2008, "%0g", 1.23e-09);
  ck_assert_str_eq(test_str_2008, test_str_2008_2008);
}
END_TEST

START_TEST(sprintf_test_2009) {
  char test_str_2009[50] = "";
  char test_str_2009_2009[50] = "";
  s21_sprintf(test_str_2009, "%0G", 0.0);
  sprintf(test_str_2009_2009, "%0G", 0.0);
  ck_assert_str_eq(test_str_2009, test_str_2009_2009);
}
END_TEST

START_TEST(sprintf_test_2010) {
  char test_str_2010[50] = "";
  char test_str_2010_2010[50] = "";
  s21_sprintf(test_str_2010, "%0G", 123456789.0);
  sprintf(test_str_2010_2010, "%0G", 123456789.0);
  ck_assert_str_eq(test_str_2010, test_str_2010_2010);
}
END_TEST

START_TEST(sprintf_test_2011) {
  char test_str_2011[50] = "";
  char test_str_2011_2011[50] = "";
  s21_sprintf(test_str_2011, "%0G", 0.123456789);
  sprintf(test_str_2011_2011, "%0G", 0.123456789);
  ck_assert_str_eq(test_str_2011, test_str_2011_2011);
}
END_TEST

START_TEST(sprintf_test_2012) {
  char test_str_2012[50] = "";
  char test_str_2012_2012[50] = "";
  s21_sprintf(test_str_2012, "%0G", -123456789.0);
  sprintf(test_str_2012_2012, "%0G", -123456789.0);
  ck_assert_str_eq(test_str_2012, test_str_2012_2012);
}
END_TEST

START_TEST(sprintf_test_2013) {
  char test_str_2013[50] = "";
  char test_str_2013_2013[50] = "";
  s21_sprintf(test_str_2013, "%0G", -0.123456789);
  sprintf(test_str_2013_2013, "%0G", -0.123456789);
  ck_assert_str_eq(test_str_2013, test_str_2013_2013);
}
END_TEST

START_TEST(sprintf_test_2014) {
  char test_str_2014[50] = "";
  char test_str_2014_2014[50] = "";
  s21_sprintf(test_str_2014, "%0G", 123456789.12345679);
  sprintf(test_str_2014_2014, "%0G", 123456789.12345679);
  ck_assert_str_eq(test_str_2014, test_str_2014_2014);
}
END_TEST

START_TEST(sprintf_test_2015) {
  char test_str_2015[50] = "";
  char test_str_2015_2015[50] = "";
  s21_sprintf(test_str_2015, "%0G", -123456789.12345678);
  sprintf(test_str_2015_2015, "%0G", -123456789.12345678);
  ck_assert_str_eq(test_str_2015, test_str_2015_2015);
}
END_TEST

START_TEST(sprintf_test_2016) {
  char test_str_2016[50] = "";
  char test_str_2016_2016[50] = "";
  s21_sprintf(test_str_2016, "%0G", 1.23e-09);
  sprintf(test_str_2016_2016, "%0G", 1.23e-09);
  ck_assert_str_eq(test_str_2016, test_str_2016_2016);
}
END_TEST

START_TEST(sprintf_test_2017) {
  char test_str_2017[50] = "";
  char test_str_2017_2017[50] = "";
  s21_sprintf(test_str_2017, "%0G", 1.23e-09);
  sprintf(test_str_2017_2017, "%0G", 1.23e-09);
  ck_assert_str_eq(test_str_2017, test_str_2017_2017);
}
END_TEST

START_TEST(sprintf_test_2018) {
  char test_str_2018[50] = "";
  char test_str_2018_2018[50] = "";
  s21_sprintf(test_str_2018, "%10e", 0.0);
  sprintf(test_str_2018_2018, "%10e", 0.0);
  ck_assert_str_eq(test_str_2018, test_str_2018_2018);
}
END_TEST

START_TEST(sprintf_test_2019) {
  char test_str_2019[50] = "";
  char test_str_2019_2019[50] = "";
  s21_sprintf(test_str_2019, "%10e", 123456789.0);
  sprintf(test_str_2019_2019, "%10e", 123456789.0);
  ck_assert_str_eq(test_str_2019, test_str_2019_2019);
}
END_TEST

START_TEST(sprintf_test_2020) {
  char test_str_2020[50] = "";
  char test_str_2020_2020[50] = "";
  s21_sprintf(test_str_2020, "%10e", 0.123456789);
  sprintf(test_str_2020_2020, "%10e", 0.123456789);
  ck_assert_str_eq(test_str_2020, test_str_2020_2020);
}
END_TEST

START_TEST(sprintf_test_2021) {
  char test_str_2021[50] = "";
  char test_str_2021_2021[50] = "";
  s21_sprintf(test_str_2021, "%10e", -123456789.0);
  sprintf(test_str_2021_2021, "%10e", -123456789.0);
  ck_assert_str_eq(test_str_2021, test_str_2021_2021);
}
END_TEST

START_TEST(sprintf_test_2022) {
  char test_str_2022[50] = "";
  char test_str_2022_2022[50] = "";
  s21_sprintf(test_str_2022, "%10e", -0.123456789);
  sprintf(test_str_2022_2022, "%10e", -0.123456789);
  ck_assert_str_eq(test_str_2022, test_str_2022_2022);
}
END_TEST

START_TEST(sprintf_test_2023) {
  char test_str_2023[50] = "";
  char test_str_2023_2023[50] = "";
  s21_sprintf(test_str_2023, "%10e", 123456789.12345679);
  sprintf(test_str_2023_2023, "%10e", 123456789.12345679);
  ck_assert_str_eq(test_str_2023, test_str_2023_2023);
}
END_TEST

START_TEST(sprintf_test_2024) {
  char test_str_2024[50] = "";
  char test_str_2024_2024[50] = "";
  s21_sprintf(test_str_2024, "%10e", -123456789.12345678);
  sprintf(test_str_2024_2024, "%10e", -123456789.12345678);
  ck_assert_str_eq(test_str_2024, test_str_2024_2024);
}
END_TEST

START_TEST(sprintf_test_2025) {
  char test_str_2025[50] = "";
  char test_str_2025_2025[50] = "";
  s21_sprintf(test_str_2025, "%10e", 1.23e-09);
  sprintf(test_str_2025_2025, "%10e", 1.23e-09);
  ck_assert_str_eq(test_str_2025, test_str_2025_2025);
}
END_TEST

START_TEST(sprintf_test_2026) {
  char test_str_2026[50] = "";
  char test_str_2026_2026[50] = "";
  s21_sprintf(test_str_2026, "%10e", 1.23e-09);
  sprintf(test_str_2026_2026, "%10e", 1.23e-09);
  ck_assert_str_eq(test_str_2026, test_str_2026_2026);
}
END_TEST

START_TEST(sprintf_test_2027) {
  char test_str_2027[50] = "";
  char test_str_2027_2027[50] = "";
  s21_sprintf(test_str_2027, "%10E", 0.0);
  sprintf(test_str_2027_2027, "%10E", 0.0);
  ck_assert_str_eq(test_str_2027, test_str_2027_2027);
}
END_TEST

START_TEST(sprintf_test_2028) {
  char test_str_2028[50] = "";
  char test_str_2028_2028[50] = "";
  s21_sprintf(test_str_2028, "%10E", 123456789.0);
  sprintf(test_str_2028_2028, "%10E", 123456789.0);
  ck_assert_str_eq(test_str_2028, test_str_2028_2028);
}
END_TEST

START_TEST(sprintf_test_2029) {
  char test_str_2029[50] = "";
  char test_str_2029_2029[50] = "";
  s21_sprintf(test_str_2029, "%10E", 0.123456789);
  sprintf(test_str_2029_2029, "%10E", 0.123456789);
  ck_assert_str_eq(test_str_2029, test_str_2029_2029);
}
END_TEST

START_TEST(sprintf_test_2030) {
  char test_str_2030[50] = "";
  char test_str_2030_2030[50] = "";
  s21_sprintf(test_str_2030, "%10E", -123456789.0);
  sprintf(test_str_2030_2030, "%10E", -123456789.0);
  ck_assert_str_eq(test_str_2030, test_str_2030_2030);
}
END_TEST

START_TEST(sprintf_test_2031) {
  char test_str_2031[50] = "";
  char test_str_2031_2031[50] = "";
  s21_sprintf(test_str_2031, "%10E", -0.123456789);
  sprintf(test_str_2031_2031, "%10E", -0.123456789);
  ck_assert_str_eq(test_str_2031, test_str_2031_2031);
}
END_TEST

START_TEST(sprintf_test_2032) {
  char test_str_2032[50] = "";
  char test_str_2032_2032[50] = "";
  s21_sprintf(test_str_2032, "%10E", 123456789.12345679);
  sprintf(test_str_2032_2032, "%10E", 123456789.12345679);
  ck_assert_str_eq(test_str_2032, test_str_2032_2032);
}
END_TEST

START_TEST(sprintf_test_2033) {
  char test_str_2033[50] = "";
  char test_str_2033_2033[50] = "";
  s21_sprintf(test_str_2033, "%10E", -123456789.12345678);
  sprintf(test_str_2033_2033, "%10E", -123456789.12345678);
  ck_assert_str_eq(test_str_2033, test_str_2033_2033);
}
END_TEST

START_TEST(sprintf_test_2034) {
  char test_str_2034[50] = "";
  char test_str_2034_2034[50] = "";
  s21_sprintf(test_str_2034, "%10E", 1.23e-09);
  sprintf(test_str_2034_2034, "%10E", 1.23e-09);
  ck_assert_str_eq(test_str_2034, test_str_2034_2034);
}
END_TEST

START_TEST(sprintf_test_2035) {
  char test_str_2035[50] = "";
  char test_str_2035_2035[50] = "";
  s21_sprintf(test_str_2035, "%10E", 1.23e-09);
  sprintf(test_str_2035_2035, "%10E", 1.23e-09);
  ck_assert_str_eq(test_str_2035, test_str_2035_2035);
}
END_TEST

START_TEST(sprintf_test_2036) {
  char test_str_2036[50] = "";
  char test_str_2036_2036[50] = "";
  s21_sprintf(test_str_2036, "%10g", 0.0);
  sprintf(test_str_2036_2036, "%10g", 0.0);
  ck_assert_str_eq(test_str_2036, test_str_2036_2036);
}
END_TEST

START_TEST(sprintf_test_2037) {
  char test_str_2037[50] = "";
  char test_str_2037_2037[50] = "";
  s21_sprintf(test_str_2037, "%10g", 123456789.0);
  sprintf(test_str_2037_2037, "%10g", 123456789.0);
  ck_assert_str_eq(test_str_2037, test_str_2037_2037);
}
END_TEST

START_TEST(sprintf_test_2038) {
  char test_str_2038[50] = "";
  char test_str_2038_2038[50] = "";
  s21_sprintf(test_str_2038, "%10g", 0.123456789);
  sprintf(test_str_2038_2038, "%10g", 0.123456789);
  ck_assert_str_eq(test_str_2038, test_str_2038_2038);
}
END_TEST

START_TEST(sprintf_test_2039) {
  char test_str_2039[50] = "";
  char test_str_2039_2039[50] = "";
  s21_sprintf(test_str_2039, "%10g", -123456789.0);
  sprintf(test_str_2039_2039, "%10g", -123456789.0);
  ck_assert_str_eq(test_str_2039, test_str_2039_2039);
}
END_TEST

START_TEST(sprintf_test_2040) {
  char test_str_2040[50] = "";
  char test_str_2040_2040[50] = "";
  s21_sprintf(test_str_2040, "%10g", -0.123456789);
  sprintf(test_str_2040_2040, "%10g", -0.123456789);
  ck_assert_str_eq(test_str_2040, test_str_2040_2040);
}
END_TEST

START_TEST(sprintf_test_2041) {
  char test_str_2041[50] = "";
  char test_str_2041_2041[50] = "";
  s21_sprintf(test_str_2041, "%10g", 123456789.12345679);
  sprintf(test_str_2041_2041, "%10g", 123456789.12345679);
  ck_assert_str_eq(test_str_2041, test_str_2041_2041);
}
END_TEST

START_TEST(sprintf_test_2042) {
  char test_str_2042[50] = "";
  char test_str_2042_2042[50] = "";
  s21_sprintf(test_str_2042, "%10g", -123456789.12345678);
  sprintf(test_str_2042_2042, "%10g", -123456789.12345678);
  ck_assert_str_eq(test_str_2042, test_str_2042_2042);
}
END_TEST

START_TEST(sprintf_test_2043) {
  char test_str_2043[50] = "";
  char test_str_2043_2043[50] = "";
  s21_sprintf(test_str_2043, "%10g", 1.23e-09);
  sprintf(test_str_2043_2043, "%10g", 1.23e-09);
  ck_assert_str_eq(test_str_2043, test_str_2043_2043);
}
END_TEST

START_TEST(sprintf_test_2044) {
  char test_str_2044[50] = "";
  char test_str_2044_2044[50] = "";
  s21_sprintf(test_str_2044, "%10g", 1.23e-09);
  sprintf(test_str_2044_2044, "%10g", 1.23e-09);
  ck_assert_str_eq(test_str_2044, test_str_2044_2044);
}
END_TEST

START_TEST(sprintf_test_2045) {
  char test_str_2045[50] = "";
  char test_str_2045_2045[50] = "";
  s21_sprintf(test_str_2045, "%10G", 0.0);
  sprintf(test_str_2045_2045, "%10G", 0.0);
  ck_assert_str_eq(test_str_2045, test_str_2045_2045);
}
END_TEST

START_TEST(sprintf_test_2046) {
  char test_str_2046[50] = "";
  char test_str_2046_2046[50] = "";
  s21_sprintf(test_str_2046, "%10G", 123456789.0);
  sprintf(test_str_2046_2046, "%10G", 123456789.0);
  ck_assert_str_eq(test_str_2046, test_str_2046_2046);
}
END_TEST

START_TEST(sprintf_test_2047) {
  char test_str_2047[50] = "";
  char test_str_2047_2047[50] = "";
  s21_sprintf(test_str_2047, "%10G", 0.123456789);
  sprintf(test_str_2047_2047, "%10G", 0.123456789);
  ck_assert_str_eq(test_str_2047, test_str_2047_2047);
}
END_TEST

START_TEST(sprintf_test_2048) {
  char test_str_2048[50] = "";
  char test_str_2048_2048[50] = "";
  s21_sprintf(test_str_2048, "%10G", -123456789.0);
  sprintf(test_str_2048_2048, "%10G", -123456789.0);
  ck_assert_str_eq(test_str_2048, test_str_2048_2048);
}
END_TEST

START_TEST(sprintf_test_2049) {
  char test_str_2049[50] = "";
  char test_str_2049_2049[50] = "";
  s21_sprintf(test_str_2049, "%10G", -0.123456789);
  sprintf(test_str_2049_2049, "%10G", -0.123456789);
  ck_assert_str_eq(test_str_2049, test_str_2049_2049);
}
END_TEST

START_TEST(sprintf_test_2050) {
  char test_str_2050[50] = "";
  char test_str_2050_2050[50] = "";
  s21_sprintf(test_str_2050, "%10G", 123456789.12345679);
  sprintf(test_str_2050_2050, "%10G", 123456789.12345679);
  ck_assert_str_eq(test_str_2050, test_str_2050_2050);
}
END_TEST

START_TEST(sprintf_test_2051) {
  char test_str_2051[50] = "";
  char test_str_2051_2051[50] = "";
  s21_sprintf(test_str_2051, "%10G", -123456789.12345678);
  sprintf(test_str_2051_2051, "%10G", -123456789.12345678);
  ck_assert_str_eq(test_str_2051, test_str_2051_2051);
}
END_TEST

START_TEST(sprintf_test_2052) {
  char test_str_2052[50] = "";
  char test_str_2052_2052[50] = "";
  s21_sprintf(test_str_2052, "%10G", 1.23e-09);
  sprintf(test_str_2052_2052, "%10G", 1.23e-09);
  ck_assert_str_eq(test_str_2052, test_str_2052_2052);
}
END_TEST

START_TEST(sprintf_test_2053) {
  char test_str_2053[50] = "";
  char test_str_2053_2053[50] = "";
  s21_sprintf(test_str_2053, "%10G", 1.23e-09);
  sprintf(test_str_2053_2053, "%10G", 1.23e-09);
  ck_assert_str_eq(test_str_2053, test_str_2053_2053);
}
END_TEST

START_TEST(sprintf_test_2054) {
  char test_str_2054[50] = "";
  char test_str_2054_2054[50] = "";
  s21_sprintf(test_str_2054, "%20e", 0.0);
  sprintf(test_str_2054_2054, "%20e", 0.0);
  ck_assert_str_eq(test_str_2054, test_str_2054_2054);
}
END_TEST

START_TEST(sprintf_test_2055) {
  char test_str_2055[50] = "";
  char test_str_2055_2055[50] = "";
  s21_sprintf(test_str_2055, "%20e", 123456789.0);
  sprintf(test_str_2055_2055, "%20e", 123456789.0);
  ck_assert_str_eq(test_str_2055, test_str_2055_2055);
}
END_TEST

START_TEST(sprintf_test_2056) {
  char test_str_2056[50] = "";
  char test_str_2056_2056[50] = "";
  s21_sprintf(test_str_2056, "%20e", 0.123456789);
  sprintf(test_str_2056_2056, "%20e", 0.123456789);
  ck_assert_str_eq(test_str_2056, test_str_2056_2056);
}
END_TEST

START_TEST(sprintf_test_2057) {
  char test_str_2057[50] = "";
  char test_str_2057_2057[50] = "";
  s21_sprintf(test_str_2057, "%20e", -123456789.0);
  sprintf(test_str_2057_2057, "%20e", -123456789.0);
  ck_assert_str_eq(test_str_2057, test_str_2057_2057);
}
END_TEST

START_TEST(sprintf_test_2058) {
  char test_str_2058[50] = "";
  char test_str_2058_2058[50] = "";
  s21_sprintf(test_str_2058, "%20e", -0.123456789);
  sprintf(test_str_2058_2058, "%20e", -0.123456789);
  ck_assert_str_eq(test_str_2058, test_str_2058_2058);
}
END_TEST

START_TEST(sprintf_test_2059) {
  char test_str_2059[50] = "";
  char test_str_2059_2059[50] = "";
  s21_sprintf(test_str_2059, "%20e", 123456789.12345679);
  sprintf(test_str_2059_2059, "%20e", 123456789.12345679);
  ck_assert_str_eq(test_str_2059, test_str_2059_2059);
}
END_TEST

START_TEST(sprintf_test_2060) {
  char test_str_2060[50] = "";
  char test_str_2060_2060[50] = "";
  s21_sprintf(test_str_2060, "%20e", -123456789.12345678);
  sprintf(test_str_2060_2060, "%20e", -123456789.12345678);
  ck_assert_str_eq(test_str_2060, test_str_2060_2060);
}
END_TEST

START_TEST(sprintf_test_2061) {
  char test_str_2061[50] = "";
  char test_str_2061_2061[50] = "";
  s21_sprintf(test_str_2061, "%20e", 1.23e-09);
  sprintf(test_str_2061_2061, "%20e", 1.23e-09);
  ck_assert_str_eq(test_str_2061, test_str_2061_2061);
}
END_TEST

START_TEST(sprintf_test_2062) {
  char test_str_2062[50] = "";
  char test_str_2062_2062[50] = "";
  s21_sprintf(test_str_2062, "%20e", 1.23e-09);
  sprintf(test_str_2062_2062, "%20e", 1.23e-09);
  ck_assert_str_eq(test_str_2062, test_str_2062_2062);
}
END_TEST

START_TEST(sprintf_test_2063) {
  char test_str_2063[50] = "";
  char test_str_2063_2063[50] = "";
  s21_sprintf(test_str_2063, "%20E", 0.0);
  sprintf(test_str_2063_2063, "%20E", 0.0);
  ck_assert_str_eq(test_str_2063, test_str_2063_2063);
}
END_TEST

START_TEST(sprintf_test_2064) {
  char test_str_2064[50] = "";
  char test_str_2064_2064[50] = "";
  s21_sprintf(test_str_2064, "%20E", 123456789.0);
  sprintf(test_str_2064_2064, "%20E", 123456789.0);
  ck_assert_str_eq(test_str_2064, test_str_2064_2064);
}
END_TEST

START_TEST(sprintf_test_2065) {
  char test_str_2065[50] = "";
  char test_str_2065_2065[50] = "";
  s21_sprintf(test_str_2065, "%20E", 0.123456789);
  sprintf(test_str_2065_2065, "%20E", 0.123456789);
  ck_assert_str_eq(test_str_2065, test_str_2065_2065);
}
END_TEST

START_TEST(sprintf_test_2066) {
  char test_str_2066[50] = "";
  char test_str_2066_2066[50] = "";
  s21_sprintf(test_str_2066, "%20E", -123456789.0);
  sprintf(test_str_2066_2066, "%20E", -123456789.0);
  ck_assert_str_eq(test_str_2066, test_str_2066_2066);
}
END_TEST

START_TEST(sprintf_test_2067) {
  char test_str_2067[50] = "";
  char test_str_2067_2067[50] = "";
  s21_sprintf(test_str_2067, "%20E", -0.123456789);
  sprintf(test_str_2067_2067, "%20E", -0.123456789);
  ck_assert_str_eq(test_str_2067, test_str_2067_2067);
}
END_TEST

START_TEST(sprintf_test_2068) {
  char test_str_2068[50] = "";
  char test_str_2068_2068[50] = "";
  s21_sprintf(test_str_2068, "%20E", 123456789.12345679);
  sprintf(test_str_2068_2068, "%20E", 123456789.12345679);
  ck_assert_str_eq(test_str_2068, test_str_2068_2068);
}
END_TEST

START_TEST(sprintf_test_2069) {
  char test_str_2069[50] = "";
  char test_str_2069_2069[50] = "";
  s21_sprintf(test_str_2069, "%20E", -123456789.12345678);
  sprintf(test_str_2069_2069, "%20E", -123456789.12345678);
  ck_assert_str_eq(test_str_2069, test_str_2069_2069);
}
END_TEST

START_TEST(sprintf_test_2070) {
  char test_str_2070[50] = "";
  char test_str_2070_2070[50] = "";
  s21_sprintf(test_str_2070, "%20E", 1.23e-09);
  sprintf(test_str_2070_2070, "%20E", 1.23e-09);
  ck_assert_str_eq(test_str_2070, test_str_2070_2070);
}
END_TEST

START_TEST(sprintf_test_2071) {
  char test_str_2071[50] = "";
  char test_str_2071_2071[50] = "";
  s21_sprintf(test_str_2071, "%20E", 1.23e-09);
  sprintf(test_str_2071_2071, "%20E", 1.23e-09);
  ck_assert_str_eq(test_str_2071, test_str_2071_2071);
}
END_TEST

START_TEST(sprintf_test_2072) {
  char test_str_2072[50] = "";
  char test_str_2072_2072[50] = "";
  s21_sprintf(test_str_2072, "%20g", 0.0);
  sprintf(test_str_2072_2072, "%20g", 0.0);
  ck_assert_str_eq(test_str_2072, test_str_2072_2072);
}
END_TEST

START_TEST(sprintf_test_2073) {
  char test_str_2073[50] = "";
  char test_str_2073_2073[50] = "";
  s21_sprintf(test_str_2073, "%20g", 123456789.0);
  sprintf(test_str_2073_2073, "%20g", 123456789.0);
  ck_assert_str_eq(test_str_2073, test_str_2073_2073);
}
END_TEST

START_TEST(sprintf_test_2074) {
  char test_str_2074[50] = "";
  char test_str_2074_2074[50] = "";
  s21_sprintf(test_str_2074, "%20g", 0.123456789);
  sprintf(test_str_2074_2074, "%20g", 0.123456789);
  ck_assert_str_eq(test_str_2074, test_str_2074_2074);
}
END_TEST

START_TEST(sprintf_test_2075) {
  char test_str_2075[50] = "";
  char test_str_2075_2075[50] = "";
  s21_sprintf(test_str_2075, "%20g", -123456789.0);
  sprintf(test_str_2075_2075, "%20g", -123456789.0);
  ck_assert_str_eq(test_str_2075, test_str_2075_2075);
}
END_TEST

START_TEST(sprintf_test_2076) {
  char test_str_2076[50] = "";
  char test_str_2076_2076[50] = "";
  s21_sprintf(test_str_2076, "%20g", -0.123456789);
  sprintf(test_str_2076_2076, "%20g", -0.123456789);
  ck_assert_str_eq(test_str_2076, test_str_2076_2076);
}
END_TEST

START_TEST(sprintf_test_2077) {
  char test_str_2077[50] = "";
  char test_str_2077_2077[50] = "";
  s21_sprintf(test_str_2077, "%20g", 123456789.12345679);
  sprintf(test_str_2077_2077, "%20g", 123456789.12345679);
  ck_assert_str_eq(test_str_2077, test_str_2077_2077);
}
END_TEST

START_TEST(sprintf_test_2078) {
  char test_str_2078[50] = "";
  char test_str_2078_2078[50] = "";
  s21_sprintf(test_str_2078, "%20g", -123456789.12345678);
  sprintf(test_str_2078_2078, "%20g", -123456789.12345678);
  ck_assert_str_eq(test_str_2078, test_str_2078_2078);
}
END_TEST

START_TEST(sprintf_test_2079) {
  char test_str_2079[50] = "";
  char test_str_2079_2079[50] = "";
  s21_sprintf(test_str_2079, "%20g", 1.23e-09);
  sprintf(test_str_2079_2079, "%20g", 1.23e-09);
  ck_assert_str_eq(test_str_2079, test_str_2079_2079);
}
END_TEST

START_TEST(sprintf_test_2080) {
  char test_str_2080[50] = "";
  char test_str_2080_2080[50] = "";
  s21_sprintf(test_str_2080, "%20g", 1.23e-09);
  sprintf(test_str_2080_2080, "%20g", 1.23e-09);
  ck_assert_str_eq(test_str_2080, test_str_2080_2080);
}
END_TEST

START_TEST(sprintf_test_2081) {
  char test_str_2081[50] = "";
  char test_str_2081_2081[50] = "";
  s21_sprintf(test_str_2081, "%20G", 0.0);
  sprintf(test_str_2081_2081, "%20G", 0.0);
  ck_assert_str_eq(test_str_2081, test_str_2081_2081);
}
END_TEST

START_TEST(sprintf_test_2082) {
  char test_str_2082[50] = "";
  char test_str_2082_2082[50] = "";
  s21_sprintf(test_str_2082, "%20G", 123456789.0);
  sprintf(test_str_2082_2082, "%20G", 123456789.0);
  ck_assert_str_eq(test_str_2082, test_str_2082_2082);
}
END_TEST

START_TEST(sprintf_test_2083) {
  char test_str_2083[50] = "";
  char test_str_2083_2083[50] = "";
  s21_sprintf(test_str_2083, "%20G", 0.123456789);
  sprintf(test_str_2083_2083, "%20G", 0.123456789);
  ck_assert_str_eq(test_str_2083, test_str_2083_2083);
}
END_TEST

START_TEST(sprintf_test_2084) {
  char test_str_2084[50] = "";
  char test_str_2084_2084[50] = "";
  s21_sprintf(test_str_2084, "%20G", -123456789.0);
  sprintf(test_str_2084_2084, "%20G", -123456789.0);
  ck_assert_str_eq(test_str_2084, test_str_2084_2084);
}
END_TEST

START_TEST(sprintf_test_2085) {
  char test_str_2085[50] = "";
  char test_str_2085_2085[50] = "";
  s21_sprintf(test_str_2085, "%20G", -0.123456789);
  sprintf(test_str_2085_2085, "%20G", -0.123456789);
  ck_assert_str_eq(test_str_2085, test_str_2085_2085);
}
END_TEST

START_TEST(sprintf_test_2086) {
  char test_str_2086[50] = "";
  char test_str_2086_2086[50] = "";
  s21_sprintf(test_str_2086, "%20G", 123456789.12345679);
  sprintf(test_str_2086_2086, "%20G", 123456789.12345679);
  ck_assert_str_eq(test_str_2086, test_str_2086_2086);
}
END_TEST

START_TEST(sprintf_test_2087) {
  char test_str_2087[50] = "";
  char test_str_2087_2087[50] = "";
  s21_sprintf(test_str_2087, "%20G", -123456789.12345678);
  sprintf(test_str_2087_2087, "%20G", -123456789.12345678);
  ck_assert_str_eq(test_str_2087, test_str_2087_2087);
}
END_TEST

START_TEST(sprintf_test_2088) {
  char test_str_2088[50] = "";
  char test_str_2088_2088[50] = "";
  s21_sprintf(test_str_2088, "%20G", 1.23e-09);
  sprintf(test_str_2088_2088, "%20G", 1.23e-09);
  ck_assert_str_eq(test_str_2088, test_str_2088_2088);
}
END_TEST

START_TEST(sprintf_test_2089) {
  char test_str_2089[50] = "";
  char test_str_2089_2089[50] = "";
  s21_sprintf(test_str_2089, "%20G", 1.23e-09);
  sprintf(test_str_2089_2089, "%20G", 1.23e-09);
  ck_assert_str_eq(test_str_2089, test_str_2089_2089);
}
END_TEST

START_TEST(sprintf_test_2090) {
  char test_str_2090[50] = "";
  char test_str_2090_2090[50] = "";
  s21_sprintf(test_str_2090, "%-10e", 0.0);
  sprintf(test_str_2090_2090, "%-10e", 0.0);
  ck_assert_str_eq(test_str_2090, test_str_2090_2090);
}
END_TEST

START_TEST(sprintf_test_2091) {
  char test_str_2091[50] = "";
  char test_str_2091_2091[50] = "";
  s21_sprintf(test_str_2091, "%-10e", 123456789.0);
  sprintf(test_str_2091_2091, "%-10e", 123456789.0);
  ck_assert_str_eq(test_str_2091, test_str_2091_2091);
}
END_TEST

START_TEST(sprintf_test_2092) {
  char test_str_2092[50] = "";
  char test_str_2092_2092[50] = "";
  s21_sprintf(test_str_2092, "%-10e", 0.123456789);
  sprintf(test_str_2092_2092, "%-10e", 0.123456789);
  ck_assert_str_eq(test_str_2092, test_str_2092_2092);
}
END_TEST

START_TEST(sprintf_test_2093) {
  char test_str_2093[50] = "";
  char test_str_2093_2093[50] = "";
  s21_sprintf(test_str_2093, "%-10e", -123456789.0);
  sprintf(test_str_2093_2093, "%-10e", -123456789.0);
  ck_assert_str_eq(test_str_2093, test_str_2093_2093);
}
END_TEST

START_TEST(sprintf_test_2094) {
  char test_str_2094[50] = "";
  char test_str_2094_2094[50] = "";
  s21_sprintf(test_str_2094, "%-10e", -0.123456789);
  sprintf(test_str_2094_2094, "%-10e", -0.123456789);
  ck_assert_str_eq(test_str_2094, test_str_2094_2094);
}
END_TEST

START_TEST(sprintf_test_2095) {
  char test_str_2095[50] = "";
  char test_str_2095_2095[50] = "";
  s21_sprintf(test_str_2095, "%-10e", 123456789.12345679);
  sprintf(test_str_2095_2095, "%-10e", 123456789.12345679);
  ck_assert_str_eq(test_str_2095, test_str_2095_2095);
}
END_TEST

START_TEST(sprintf_test_2096) {
  char test_str_2096[50] = "";
  char test_str_2096_2096[50] = "";
  s21_sprintf(test_str_2096, "%-10e", -123456789.12345678);
  sprintf(test_str_2096_2096, "%-10e", -123456789.12345678);
  ck_assert_str_eq(test_str_2096, test_str_2096_2096);
}
END_TEST

START_TEST(sprintf_test_2097) {
  char test_str_2097[50] = "";
  char test_str_2097_2097[50] = "";
  s21_sprintf(test_str_2097, "%-10e", 1.23e-09);
  sprintf(test_str_2097_2097, "%-10e", 1.23e-09);
  ck_assert_str_eq(test_str_2097, test_str_2097_2097);
}
END_TEST

START_TEST(sprintf_test_2098) {
  char test_str_2098[50] = "";
  char test_str_2098_2098[50] = "";
  s21_sprintf(test_str_2098, "%-10e", 1.23e-09);
  sprintf(test_str_2098_2098, "%-10e", 1.23e-09);
  ck_assert_str_eq(test_str_2098, test_str_2098_2098);
}
END_TEST

START_TEST(sprintf_test_2099) {
  char test_str_2099[50] = "";
  char test_str_2099_2099[50] = "";
  s21_sprintf(test_str_2099, "%-10E", 0.0);
  sprintf(test_str_2099_2099, "%-10E", 0.0);
  ck_assert_str_eq(test_str_2099, test_str_2099_2099);
}
END_TEST

START_TEST(sprintf_test_2100) {
  char test_str_2100[50] = "";
  char test_str_2100_2100[50] = "";
  s21_sprintf(test_str_2100, "%-10E", 123456789.0);
  sprintf(test_str_2100_2100, "%-10E", 123456789.0);
  ck_assert_str_eq(test_str_2100, test_str_2100_2100);
}
END_TEST

START_TEST(sprintf_test_2101) {
  char test_str_2101[50] = "";
  char test_str_2101_2101[50] = "";
  s21_sprintf(test_str_2101, "%-10E", 0.123456789);
  sprintf(test_str_2101_2101, "%-10E", 0.123456789);
  ck_assert_str_eq(test_str_2101, test_str_2101_2101);
}
END_TEST

START_TEST(sprintf_test_2102) {
  char test_str_2102[50] = "";
  char test_str_2102_2102[50] = "";
  s21_sprintf(test_str_2102, "%-10E", -123456789.0);
  sprintf(test_str_2102_2102, "%-10E", -123456789.0);
  ck_assert_str_eq(test_str_2102, test_str_2102_2102);
}
END_TEST

START_TEST(sprintf_test_2103) {
  char test_str_2103[50] = "";
  char test_str_2103_2103[50] = "";
  s21_sprintf(test_str_2103, "%-10E", -0.123456789);
  sprintf(test_str_2103_2103, "%-10E", -0.123456789);
  ck_assert_str_eq(test_str_2103, test_str_2103_2103);
}
END_TEST

START_TEST(sprintf_test_2104) {
  char test_str_2104[50] = "";
  char test_str_2104_2104[50] = "";
  s21_sprintf(test_str_2104, "%-10E", 123456789.12345679);
  sprintf(test_str_2104_2104, "%-10E", 123456789.12345679);
  ck_assert_str_eq(test_str_2104, test_str_2104_2104);
}
END_TEST

START_TEST(sprintf_test_2105) {
  char test_str_2105[50] = "";
  char test_str_2105_2105[50] = "";
  s21_sprintf(test_str_2105, "%-10E", -123456789.12345678);
  sprintf(test_str_2105_2105, "%-10E", -123456789.12345678);
  ck_assert_str_eq(test_str_2105, test_str_2105_2105);
}
END_TEST

START_TEST(sprintf_test_2106) {
  char test_str_2106[50] = "";
  char test_str_2106_2106[50] = "";
  s21_sprintf(test_str_2106, "%-10E", 1.23e-09);
  sprintf(test_str_2106_2106, "%-10E", 1.23e-09);
  ck_assert_str_eq(test_str_2106, test_str_2106_2106);
}
END_TEST

START_TEST(sprintf_test_2107) {
  char test_str_2107[50] = "";
  char test_str_2107_2107[50] = "";
  s21_sprintf(test_str_2107, "%-10E", 1.23e-09);
  sprintf(test_str_2107_2107, "%-10E", 1.23e-09);
  ck_assert_str_eq(test_str_2107, test_str_2107_2107);
}
END_TEST

START_TEST(sprintf_test_2108) {
  char test_str_2108[50] = "";
  char test_str_2108_2108[50] = "";
  s21_sprintf(test_str_2108, "%-10g", 0.0);
  sprintf(test_str_2108_2108, "%-10g", 0.0);
  ck_assert_str_eq(test_str_2108, test_str_2108_2108);
}
END_TEST

START_TEST(sprintf_test_2109) {
  char test_str_2109[50] = "";
  char test_str_2109_2109[50] = "";
  s21_sprintf(test_str_2109, "%-10g", 123456789.0);
  sprintf(test_str_2109_2109, "%-10g", 123456789.0);
  ck_assert_str_eq(test_str_2109, test_str_2109_2109);
}
END_TEST

START_TEST(sprintf_test_2110) {
  char test_str_2110[50] = "";
  char test_str_2110_2110[50] = "";
  s21_sprintf(test_str_2110, "%-10g", 0.123456789);
  sprintf(test_str_2110_2110, "%-10g", 0.123456789);
  ck_assert_str_eq(test_str_2110, test_str_2110_2110);
}
END_TEST

START_TEST(sprintf_test_2111) {
  char test_str_2111[50] = "";
  char test_str_2111_2111[50] = "";
  s21_sprintf(test_str_2111, "%-10g", -123456789.0);
  sprintf(test_str_2111_2111, "%-10g", -123456789.0);
  ck_assert_str_eq(test_str_2111, test_str_2111_2111);
}
END_TEST

START_TEST(sprintf_test_2112) {
  char test_str_2112[50] = "";
  char test_str_2112_2112[50] = "";
  s21_sprintf(test_str_2112, "%-10g", -0.123456789);
  sprintf(test_str_2112_2112, "%-10g", -0.123456789);
  ck_assert_str_eq(test_str_2112, test_str_2112_2112);
}
END_TEST

START_TEST(sprintf_test_2113) {
  char test_str_2113[50] = "";
  char test_str_2113_2113[50] = "";
  s21_sprintf(test_str_2113, "%-10g", 123456789.12345679);
  sprintf(test_str_2113_2113, "%-10g", 123456789.12345679);
  ck_assert_str_eq(test_str_2113, test_str_2113_2113);
}
END_TEST

START_TEST(sprintf_test_2114) {
  char test_str_2114[50] = "";
  char test_str_2114_2114[50] = "";
  s21_sprintf(test_str_2114, "%-10g", -123456789.12345678);
  sprintf(test_str_2114_2114, "%-10g", -123456789.12345678);
  ck_assert_str_eq(test_str_2114, test_str_2114_2114);
}
END_TEST

START_TEST(sprintf_test_2115) {
  char test_str_2115[50] = "";
  char test_str_2115_2115[50] = "";
  s21_sprintf(test_str_2115, "%-10g", 1.23e-09);
  sprintf(test_str_2115_2115, "%-10g", 1.23e-09);
  ck_assert_str_eq(test_str_2115, test_str_2115_2115);
}
END_TEST

START_TEST(sprintf_test_2116) {
  char test_str_2116[50] = "";
  char test_str_2116_2116[50] = "";
  s21_sprintf(test_str_2116, "%-10g", 1.23e-09);
  sprintf(test_str_2116_2116, "%-10g", 1.23e-09);
  ck_assert_str_eq(test_str_2116, test_str_2116_2116);
}
END_TEST

START_TEST(sprintf_test_2117) {
  char test_str_2117[50] = "";
  char test_str_2117_2117[50] = "";
  s21_sprintf(test_str_2117, "%-10G", 0.0);
  sprintf(test_str_2117_2117, "%-10G", 0.0);
  ck_assert_str_eq(test_str_2117, test_str_2117_2117);
}
END_TEST

START_TEST(sprintf_test_2118) {
  char test_str_2118[50] = "";
  char test_str_2118_2118[50] = "";
  s21_sprintf(test_str_2118, "%-10G", 123456789.0);
  sprintf(test_str_2118_2118, "%-10G", 123456789.0);
  ck_assert_str_eq(test_str_2118, test_str_2118_2118);
}
END_TEST

START_TEST(sprintf_test_2119) {
  char test_str_2119[50] = "";
  char test_str_2119_2119[50] = "";
  s21_sprintf(test_str_2119, "%-10G", 0.123456789);
  sprintf(test_str_2119_2119, "%-10G", 0.123456789);
  ck_assert_str_eq(test_str_2119, test_str_2119_2119);
}
END_TEST

START_TEST(sprintf_test_2120) {
  char test_str_2120[50] = "";
  char test_str_2120_2120[50] = "";
  s21_sprintf(test_str_2120, "%-10G", -123456789.0);
  sprintf(test_str_2120_2120, "%-10G", -123456789.0);
  ck_assert_str_eq(test_str_2120, test_str_2120_2120);
}
END_TEST

START_TEST(sprintf_test_2121) {
  char test_str_2121[50] = "";
  char test_str_2121_2121[50] = "";
  s21_sprintf(test_str_2121, "%-10G", -0.123456789);
  sprintf(test_str_2121_2121, "%-10G", -0.123456789);
  ck_assert_str_eq(test_str_2121, test_str_2121_2121);
}
END_TEST

START_TEST(sprintf_test_2122) {
  char test_str_2122[50] = "";
  char test_str_2122_2122[50] = "";
  s21_sprintf(test_str_2122, "%-10G", 123456789.12345679);
  sprintf(test_str_2122_2122, "%-10G", 123456789.12345679);
  ck_assert_str_eq(test_str_2122, test_str_2122_2122);
}
END_TEST

START_TEST(sprintf_test_2123) {
  char test_str_2123[50] = "";
  char test_str_2123_2123[50] = "";
  s21_sprintf(test_str_2123, "%-10G", -123456789.12345678);
  sprintf(test_str_2123_2123, "%-10G", -123456789.12345678);
  ck_assert_str_eq(test_str_2123, test_str_2123_2123);
}
END_TEST

START_TEST(sprintf_test_2124) {
  char test_str_2124[50] = "";
  char test_str_2124_2124[50] = "";
  s21_sprintf(test_str_2124, "%-10G", 1.23e-09);
  sprintf(test_str_2124_2124, "%-10G", 1.23e-09);
  ck_assert_str_eq(test_str_2124, test_str_2124_2124);
}
END_TEST

START_TEST(sprintf_test_2125) {
  char test_str_2125[50] = "";
  char test_str_2125_2125[50] = "";
  s21_sprintf(test_str_2125, "%-10G", 1.23e-09);
  sprintf(test_str_2125_2125, "%-10G", 1.23e-09);
  ck_assert_str_eq(test_str_2125, test_str_2125_2125);
}
END_TEST

START_TEST(sprintf_test_2126) {
  char test_str_2126[50] = "";
  char test_str_2126_2126[50] = "";
  s21_sprintf(test_str_2126, "%-20e", 0.0);
  sprintf(test_str_2126_2126, "%-20e", 0.0);
  ck_assert_str_eq(test_str_2126, test_str_2126_2126);
}
END_TEST

START_TEST(sprintf_test_2127) {
  char test_str_2127[50] = "";
  char test_str_2127_2127[50] = "";
  s21_sprintf(test_str_2127, "%-20e", 123456789.0);
  sprintf(test_str_2127_2127, "%-20e", 123456789.0);
  ck_assert_str_eq(test_str_2127, test_str_2127_2127);
}
END_TEST

START_TEST(sprintf_test_2128) {
  char test_str_2128[50] = "";
  char test_str_2128_2128[50] = "";
  s21_sprintf(test_str_2128, "%-20e", 0.123456789);
  sprintf(test_str_2128_2128, "%-20e", 0.123456789);
  ck_assert_str_eq(test_str_2128, test_str_2128_2128);
}
END_TEST

START_TEST(sprintf_test_2129) {
  char test_str_2129[50] = "";
  char test_str_2129_2129[50] = "";
  s21_sprintf(test_str_2129, "%-20e", -123456789.0);
  sprintf(test_str_2129_2129, "%-20e", -123456789.0);
  ck_assert_str_eq(test_str_2129, test_str_2129_2129);
}
END_TEST

START_TEST(sprintf_test_2130) {
  char test_str_2130[50] = "";
  char test_str_2130_2130[50] = "";
  s21_sprintf(test_str_2130, "%-20e", -0.123456789);
  sprintf(test_str_2130_2130, "%-20e", -0.123456789);
  ck_assert_str_eq(test_str_2130, test_str_2130_2130);
}
END_TEST

START_TEST(sprintf_test_2131) {
  char test_str_2131[50] = "";
  char test_str_2131_2131[50] = "";
  s21_sprintf(test_str_2131, "%-20e", 123456789.12345679);
  sprintf(test_str_2131_2131, "%-20e", 123456789.12345679);
  ck_assert_str_eq(test_str_2131, test_str_2131_2131);
}
END_TEST

START_TEST(sprintf_test_2132) {
  char test_str_2132[50] = "";
  char test_str_2132_2132[50] = "";
  s21_sprintf(test_str_2132, "%-20e", -123456789.12345678);
  sprintf(test_str_2132_2132, "%-20e", -123456789.12345678);
  ck_assert_str_eq(test_str_2132, test_str_2132_2132);
}
END_TEST

START_TEST(sprintf_test_2133) {
  char test_str_2133[50] = "";
  char test_str_2133_2133[50] = "";
  s21_sprintf(test_str_2133, "%-20e", 1.23e-09);
  sprintf(test_str_2133_2133, "%-20e", 1.23e-09);
  ck_assert_str_eq(test_str_2133, test_str_2133_2133);
}
END_TEST

START_TEST(sprintf_test_2134) {
  char test_str_2134[50] = "";
  char test_str_2134_2134[50] = "";
  s21_sprintf(test_str_2134, "%-20e", 1.23e-09);
  sprintf(test_str_2134_2134, "%-20e", 1.23e-09);
  ck_assert_str_eq(test_str_2134, test_str_2134_2134);
}
END_TEST

START_TEST(sprintf_test_2135) {
  char test_str_2135[50] = "";
  char test_str_2135_2135[50] = "";
  s21_sprintf(test_str_2135, "%-20E", 0.0);
  sprintf(test_str_2135_2135, "%-20E", 0.0);
  ck_assert_str_eq(test_str_2135, test_str_2135_2135);
}
END_TEST

START_TEST(sprintf_test_2136) {
  char test_str_2136[50] = "";
  char test_str_2136_2136[50] = "";
  s21_sprintf(test_str_2136, "%-20E", 123456789.0);
  sprintf(test_str_2136_2136, "%-20E", 123456789.0);
  ck_assert_str_eq(test_str_2136, test_str_2136_2136);
}
END_TEST

START_TEST(sprintf_test_2137) {
  char test_str_2137[50] = "";
  char test_str_2137_2137[50] = "";
  s21_sprintf(test_str_2137, "%-20E", 0.123456789);
  sprintf(test_str_2137_2137, "%-20E", 0.123456789);
  ck_assert_str_eq(test_str_2137, test_str_2137_2137);
}
END_TEST

START_TEST(sprintf_test_2138) {
  char test_str_2138[50] = "";
  char test_str_2138_2138[50] = "";
  s21_sprintf(test_str_2138, "%-20E", -123456789.0);
  sprintf(test_str_2138_2138, "%-20E", -123456789.0);
  ck_assert_str_eq(test_str_2138, test_str_2138_2138);
}
END_TEST

START_TEST(sprintf_test_2139) {
  char test_str_2139[50] = "";
  char test_str_2139_2139[50] = "";
  s21_sprintf(test_str_2139, "%-20E", -0.123456789);
  sprintf(test_str_2139_2139, "%-20E", -0.123456789);
  ck_assert_str_eq(test_str_2139, test_str_2139_2139);
}
END_TEST

START_TEST(sprintf_test_2140) {
  char test_str_2140[50] = "";
  char test_str_2140_2140[50] = "";
  s21_sprintf(test_str_2140, "%-20E", 123456789.12345679);
  sprintf(test_str_2140_2140, "%-20E", 123456789.12345679);
  ck_assert_str_eq(test_str_2140, test_str_2140_2140);
}
END_TEST

START_TEST(sprintf_test_2141) {
  char test_str_2141[50] = "";
  char test_str_2141_2141[50] = "";
  s21_sprintf(test_str_2141, "%-20E", -123456789.12345678);
  sprintf(test_str_2141_2141, "%-20E", -123456789.12345678);
  ck_assert_str_eq(test_str_2141, test_str_2141_2141);
}
END_TEST

START_TEST(sprintf_test_2142) {
  char test_str_2142[50] = "";
  char test_str_2142_2142[50] = "";
  s21_sprintf(test_str_2142, "%-20E", 1.23e-09);
  sprintf(test_str_2142_2142, "%-20E", 1.23e-09);
  ck_assert_str_eq(test_str_2142, test_str_2142_2142);
}
END_TEST

START_TEST(sprintf_test_2143) {
  char test_str_2143[50] = "";
  char test_str_2143_2143[50] = "";
  s21_sprintf(test_str_2143, "%-20E", 1.23e-09);
  sprintf(test_str_2143_2143, "%-20E", 1.23e-09);
  ck_assert_str_eq(test_str_2143, test_str_2143_2143);
}
END_TEST

START_TEST(sprintf_test_2144) {
  char test_str_2144[50] = "";
  char test_str_2144_2144[50] = "";
  s21_sprintf(test_str_2144, "%-20g", 0.0);
  sprintf(test_str_2144_2144, "%-20g", 0.0);
  ck_assert_str_eq(test_str_2144, test_str_2144_2144);
}
END_TEST

START_TEST(sprintf_test_2145) {
  char test_str_2145[50] = "";
  char test_str_2145_2145[50] = "";
  s21_sprintf(test_str_2145, "%-20g", 123456789.0);
  sprintf(test_str_2145_2145, "%-20g", 123456789.0);
  ck_assert_str_eq(test_str_2145, test_str_2145_2145);
}
END_TEST

START_TEST(sprintf_test_2146) {
  char test_str_2146[50] = "";
  char test_str_2146_2146[50] = "";
  s21_sprintf(test_str_2146, "%-20g", 0.123456789);
  sprintf(test_str_2146_2146, "%-20g", 0.123456789);
  ck_assert_str_eq(test_str_2146, test_str_2146_2146);
}
END_TEST

START_TEST(sprintf_test_2147) {
  char test_str_2147[50] = "";
  char test_str_2147_2147[50] = "";
  s21_sprintf(test_str_2147, "%-20g", -123456789.0);
  sprintf(test_str_2147_2147, "%-20g", -123456789.0);
  ck_assert_str_eq(test_str_2147, test_str_2147_2147);
}
END_TEST

START_TEST(sprintf_test_2148) {
  char test_str_2148[50] = "";
  char test_str_2148_2148[50] = "";
  s21_sprintf(test_str_2148, "%-20g", -0.123456789);
  sprintf(test_str_2148_2148, "%-20g", -0.123456789);
  ck_assert_str_eq(test_str_2148, test_str_2148_2148);
}
END_TEST

START_TEST(sprintf_test_2149) {
  char test_str_2149[50] = "";
  char test_str_2149_2149[50] = "";
  s21_sprintf(test_str_2149, "%-20g", 123456789.12345679);
  sprintf(test_str_2149_2149, "%-20g", 123456789.12345679);
  ck_assert_str_eq(test_str_2149, test_str_2149_2149);
}
END_TEST

START_TEST(sprintf_test_2150) {
  char test_str_2150[50] = "";
  char test_str_2150_2150[50] = "";
  s21_sprintf(test_str_2150, "%-20g", -123456789.12345678);
  sprintf(test_str_2150_2150, "%-20g", -123456789.12345678);
  ck_assert_str_eq(test_str_2150, test_str_2150_2150);
}
END_TEST

START_TEST(sprintf_test_2151) {
  char test_str_2151[50] = "";
  char test_str_2151_2151[50] = "";
  s21_sprintf(test_str_2151, "%-20g", 1.23e-09);
  sprintf(test_str_2151_2151, "%-20g", 1.23e-09);
  ck_assert_str_eq(test_str_2151, test_str_2151_2151);
}
END_TEST

START_TEST(sprintf_test_2152) {
  char test_str_2152[50] = "";
  char test_str_2152_2152[50] = "";
  s21_sprintf(test_str_2152, "%-20g", 1.23e-09);
  sprintf(test_str_2152_2152, "%-20g", 1.23e-09);
  ck_assert_str_eq(test_str_2152, test_str_2152_2152);
}
END_TEST

START_TEST(sprintf_test_2153) {
  char test_str_2153[50] = "";
  char test_str_2153_2153[50] = "";
  s21_sprintf(test_str_2153, "%-20G", 0.0);
  sprintf(test_str_2153_2153, "%-20G", 0.0);
  ck_assert_str_eq(test_str_2153, test_str_2153_2153);
}
END_TEST

START_TEST(sprintf_test_2154) {
  char test_str_2154[50] = "";
  char test_str_2154_2154[50] = "";
  s21_sprintf(test_str_2154, "%-20G", 123456789.0);
  sprintf(test_str_2154_2154, "%-20G", 123456789.0);
  ck_assert_str_eq(test_str_2154, test_str_2154_2154);
}
END_TEST

START_TEST(sprintf_test_2155) {
  char test_str_2155[50] = "";
  char test_str_2155_2155[50] = "";
  s21_sprintf(test_str_2155, "%-20G", 0.123456789);
  sprintf(test_str_2155_2155, "%-20G", 0.123456789);
  ck_assert_str_eq(test_str_2155, test_str_2155_2155);
}
END_TEST

START_TEST(sprintf_test_2156) {
  char test_str_2156[50] = "";
  char test_str_2156_2156[50] = "";
  s21_sprintf(test_str_2156, "%-20G", -123456789.0);
  sprintf(test_str_2156_2156, "%-20G", -123456789.0);
  ck_assert_str_eq(test_str_2156, test_str_2156_2156);
}
END_TEST

START_TEST(sprintf_test_2157) {
  char test_str_2157[50] = "";
  char test_str_2157_2157[50] = "";
  s21_sprintf(test_str_2157, "%-20G", -0.123456789);
  sprintf(test_str_2157_2157, "%-20G", -0.123456789);
  ck_assert_str_eq(test_str_2157, test_str_2157_2157);
}
END_TEST

START_TEST(sprintf_test_2158) {
  char test_str_2158[50] = "";
  char test_str_2158_2158[50] = "";
  s21_sprintf(test_str_2158, "%-20G", 123456789.12345679);
  sprintf(test_str_2158_2158, "%-20G", 123456789.12345679);
  ck_assert_str_eq(test_str_2158, test_str_2158_2158);
}
END_TEST

START_TEST(sprintf_test_2159) {
  char test_str_2159[50] = "";
  char test_str_2159_2159[50] = "";
  s21_sprintf(test_str_2159, "%-20G", -123456789.12345678);
  sprintf(test_str_2159_2159, "%-20G", -123456789.12345678);
  ck_assert_str_eq(test_str_2159, test_str_2159_2159);
}
END_TEST

START_TEST(sprintf_test_2160) {
  char test_str_2160[50] = "";
  char test_str_2160_2160[50] = "";
  s21_sprintf(test_str_2160, "%-20G", 1.23e-09);
  sprintf(test_str_2160_2160, "%-20G", 1.23e-09);
  ck_assert_str_eq(test_str_2160, test_str_2160_2160);
}
END_TEST

START_TEST(sprintf_test_2161) {
  char test_str_2161[50] = "";
  char test_str_2161_2161[50] = "";
  s21_sprintf(test_str_2161, "%-20G", 1.23e-09);
  sprintf(test_str_2161_2161, "%-20G", 1.23e-09);
  ck_assert_str_eq(test_str_2161, test_str_2161_2161);
}
END_TEST

START_TEST(sprintf_test_2162) {
  char test_str_2162[50] = "";
  char test_str_2162_2162[50] = "";
  s21_sprintf(test_str_2162, "%*e", 0, 0.0);
  sprintf(test_str_2162_2162, "%*e", 0, 0.0);
  ck_assert_str_eq(test_str_2162, test_str_2162_2162);
}
END_TEST

START_TEST(sprintf_test_2163) {
  char test_str_2163[50] = "";
  char test_str_2163_2163[50] = "";
  s21_sprintf(test_str_2163, "%*e", 0, 123456789.0);
  sprintf(test_str_2163_2163, "%*e", 0, 123456789.0);
  ck_assert_str_eq(test_str_2163, test_str_2163_2163);
}
END_TEST

START_TEST(sprintf_test_2164) {
  char test_str_2164[50] = "";
  char test_str_2164_2164[50] = "";
  s21_sprintf(test_str_2164, "%*e", 0, 0.123456789);
  sprintf(test_str_2164_2164, "%*e", 0, 0.123456789);
  ck_assert_str_eq(test_str_2164, test_str_2164_2164);
}
END_TEST

START_TEST(sprintf_test_2165) {
  char test_str_2165[50] = "";
  char test_str_2165_2165[50] = "";
  s21_sprintf(test_str_2165, "%*e", 0, -123456789.0);
  sprintf(test_str_2165_2165, "%*e", 0, -123456789.0);
  ck_assert_str_eq(test_str_2165, test_str_2165_2165);
}
END_TEST

START_TEST(sprintf_test_2166) {
  char test_str_2166[50] = "";
  char test_str_2166_2166[50] = "";
  s21_sprintf(test_str_2166, "%*e", 0, -0.123456789);
  sprintf(test_str_2166_2166, "%*e", 0, -0.123456789);
  ck_assert_str_eq(test_str_2166, test_str_2166_2166);
}
END_TEST

START_TEST(sprintf_test_2167) {
  char test_str_2167[50] = "";
  char test_str_2167_2167[50] = "";
  s21_sprintf(test_str_2167, "%*e", 0, 123456789.12345679);
  sprintf(test_str_2167_2167, "%*e", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_2167, test_str_2167_2167);
}
END_TEST

START_TEST(sprintf_test_2168) {
  char test_str_2168[50] = "";
  char test_str_2168_2168[50] = "";
  s21_sprintf(test_str_2168, "%*e", 0, -123456789.12345678);
  sprintf(test_str_2168_2168, "%*e", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_2168, test_str_2168_2168);
}
END_TEST

START_TEST(sprintf_test_2169) {
  char test_str_2169[50] = "";
  char test_str_2169_2169[50] = "";
  s21_sprintf(test_str_2169, "%*e", 0, 1.23e-09);
  sprintf(test_str_2169_2169, "%*e", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2169, test_str_2169_2169);
}
END_TEST

START_TEST(sprintf_test_2170) {
  char test_str_2170[50] = "";
  char test_str_2170_2170[50] = "";
  s21_sprintf(test_str_2170, "%*e", 0, 1.23e-09);
  sprintf(test_str_2170_2170, "%*e", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2170, test_str_2170_2170);
}
END_TEST

START_TEST(sprintf_test_2171) {
  char test_str_2171[50] = "";
  char test_str_2171_2171[50] = "";
  s21_sprintf(test_str_2171, "%*E", 0, 0.0);
  sprintf(test_str_2171_2171, "%*E", 0, 0.0);
  ck_assert_str_eq(test_str_2171, test_str_2171_2171);
}
END_TEST

START_TEST(sprintf_test_2172) {
  char test_str_2172[50] = "";
  char test_str_2172_2172[50] = "";
  s21_sprintf(test_str_2172, "%*E", 0, 123456789.0);
  sprintf(test_str_2172_2172, "%*E", 0, 123456789.0);
  ck_assert_str_eq(test_str_2172, test_str_2172_2172);
}
END_TEST

START_TEST(sprintf_test_2173) {
  char test_str_2173[50] = "";
  char test_str_2173_2173[50] = "";
  s21_sprintf(test_str_2173, "%*E", 0, 0.123456789);
  sprintf(test_str_2173_2173, "%*E", 0, 0.123456789);
  ck_assert_str_eq(test_str_2173, test_str_2173_2173);
}
END_TEST

START_TEST(sprintf_test_2174) {
  char test_str_2174[50] = "";
  char test_str_2174_2174[50] = "";
  s21_sprintf(test_str_2174, "%*E", 0, -123456789.0);
  sprintf(test_str_2174_2174, "%*E", 0, -123456789.0);
  ck_assert_str_eq(test_str_2174, test_str_2174_2174);
}
END_TEST

START_TEST(sprintf_test_2175) {
  char test_str_2175[50] = "";
  char test_str_2175_2175[50] = "";
  s21_sprintf(test_str_2175, "%*E", 0, -0.123456789);
  sprintf(test_str_2175_2175, "%*E", 0, -0.123456789);
  ck_assert_str_eq(test_str_2175, test_str_2175_2175);
}
END_TEST

START_TEST(sprintf_test_2176) {
  char test_str_2176[50] = "";
  char test_str_2176_2176[50] = "";
  s21_sprintf(test_str_2176, "%*E", 0, 123456789.12345679);
  sprintf(test_str_2176_2176, "%*E", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_2176, test_str_2176_2176);
}
END_TEST

START_TEST(sprintf_test_2177) {
  char test_str_2177[50] = "";
  char test_str_2177_2177[50] = "";
  s21_sprintf(test_str_2177, "%*E", 0, -123456789.12345678);
  sprintf(test_str_2177_2177, "%*E", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_2177, test_str_2177_2177);
}
END_TEST

START_TEST(sprintf_test_2178) {
  char test_str_2178[50] = "";
  char test_str_2178_2178[50] = "";
  s21_sprintf(test_str_2178, "%*E", 0, 1.23e-09);
  sprintf(test_str_2178_2178, "%*E", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2178, test_str_2178_2178);
}
END_TEST

START_TEST(sprintf_test_2179) {
  char test_str_2179[50] = "";
  char test_str_2179_2179[50] = "";
  s21_sprintf(test_str_2179, "%*E", 0, 1.23e-09);
  sprintf(test_str_2179_2179, "%*E", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2179, test_str_2179_2179);
}
END_TEST

START_TEST(sprintf_test_2180) {
  char test_str_2180[50] = "";
  char test_str_2180_2180[50] = "";
  s21_sprintf(test_str_2180, "%*g", 0, 0.0);
  sprintf(test_str_2180_2180, "%*g", 0, 0.0);
  ck_assert_str_eq(test_str_2180, test_str_2180_2180);
}
END_TEST

START_TEST(sprintf_test_2181) {
  char test_str_2181[50] = "";
  char test_str_2181_2181[50] = "";
  s21_sprintf(test_str_2181, "%*g", 0, 123456789.0);
  sprintf(test_str_2181_2181, "%*g", 0, 123456789.0);
  ck_assert_str_eq(test_str_2181, test_str_2181_2181);
}
END_TEST

START_TEST(sprintf_test_2182) {
  char test_str_2182[50] = "";
  char test_str_2182_2182[50] = "";
  s21_sprintf(test_str_2182, "%*g", 0, 0.123456789);
  sprintf(test_str_2182_2182, "%*g", 0, 0.123456789);
  ck_assert_str_eq(test_str_2182, test_str_2182_2182);
}
END_TEST

START_TEST(sprintf_test_2183) {
  char test_str_2183[50] = "";
  char test_str_2183_2183[50] = "";
  s21_sprintf(test_str_2183, "%*g", 0, -123456789.0);
  sprintf(test_str_2183_2183, "%*g", 0, -123456789.0);
  ck_assert_str_eq(test_str_2183, test_str_2183_2183);
}
END_TEST

START_TEST(sprintf_test_2184) {
  char test_str_2184[50] = "";
  char test_str_2184_2184[50] = "";
  s21_sprintf(test_str_2184, "%*g", 0, -0.123456789);
  sprintf(test_str_2184_2184, "%*g", 0, -0.123456789);
  ck_assert_str_eq(test_str_2184, test_str_2184_2184);
}
END_TEST

START_TEST(sprintf_test_2185) {
  char test_str_2185[50] = "";
  char test_str_2185_2185[50] = "";
  s21_sprintf(test_str_2185, "%*g", 0, 123456789.12345679);
  sprintf(test_str_2185_2185, "%*g", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_2185, test_str_2185_2185);
}
END_TEST

START_TEST(sprintf_test_2186) {
  char test_str_2186[50] = "";
  char test_str_2186_2186[50] = "";
  s21_sprintf(test_str_2186, "%*g", 0, -123456789.12345678);
  sprintf(test_str_2186_2186, "%*g", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_2186, test_str_2186_2186);
}
END_TEST

START_TEST(sprintf_test_2187) {
  char test_str_2187[50] = "";
  char test_str_2187_2187[50] = "";
  s21_sprintf(test_str_2187, "%*g", 0, 1.23e-09);
  sprintf(test_str_2187_2187, "%*g", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2187, test_str_2187_2187);
}
END_TEST

START_TEST(sprintf_test_2188) {
  char test_str_2188[50] = "";
  char test_str_2188_2188[50] = "";
  s21_sprintf(test_str_2188, "%*g", 0, 1.23e-09);
  sprintf(test_str_2188_2188, "%*g", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2188, test_str_2188_2188);
}
END_TEST

START_TEST(sprintf_test_2189) {
  char test_str_2189[50] = "";
  char test_str_2189_2189[50] = "";
  s21_sprintf(test_str_2189, "%*G", 0, 0.0);
  sprintf(test_str_2189_2189, "%*G", 0, 0.0);
  ck_assert_str_eq(test_str_2189, test_str_2189_2189);
}
END_TEST

START_TEST(sprintf_test_2190) {
  char test_str_2190[50] = "";
  char test_str_2190_2190[50] = "";
  s21_sprintf(test_str_2190, "%*G", 0, 123456789.0);
  sprintf(test_str_2190_2190, "%*G", 0, 123456789.0);
  ck_assert_str_eq(test_str_2190, test_str_2190_2190);
}
END_TEST

START_TEST(sprintf_test_2191) {
  char test_str_2191[50] = "";
  char test_str_2191_2191[50] = "";
  s21_sprintf(test_str_2191, "%*G", 0, 0.123456789);
  sprintf(test_str_2191_2191, "%*G", 0, 0.123456789);
  ck_assert_str_eq(test_str_2191, test_str_2191_2191);
}
END_TEST

START_TEST(sprintf_test_2192) {
  char test_str_2192[50] = "";
  char test_str_2192_2192[50] = "";
  s21_sprintf(test_str_2192, "%*G", 0, -123456789.0);
  sprintf(test_str_2192_2192, "%*G", 0, -123456789.0);
  ck_assert_str_eq(test_str_2192, test_str_2192_2192);
}
END_TEST

START_TEST(sprintf_test_2193) {
  char test_str_2193[50] = "";
  char test_str_2193_2193[50] = "";
  s21_sprintf(test_str_2193, "%*G", 0, -0.123456789);
  sprintf(test_str_2193_2193, "%*G", 0, -0.123456789);
  ck_assert_str_eq(test_str_2193, test_str_2193_2193);
}
END_TEST

START_TEST(sprintf_test_2194) {
  char test_str_2194[50] = "";
  char test_str_2194_2194[50] = "";
  s21_sprintf(test_str_2194, "%*G", 0, 123456789.12345679);
  sprintf(test_str_2194_2194, "%*G", 0, 123456789.12345679);
  ck_assert_str_eq(test_str_2194, test_str_2194_2194);
}
END_TEST

START_TEST(sprintf_test_2195) {
  char test_str_2195[50] = "";
  char test_str_2195_2195[50] = "";
  s21_sprintf(test_str_2195, "%*G", 0, -123456789.12345678);
  sprintf(test_str_2195_2195, "%*G", 0, -123456789.12345678);
  ck_assert_str_eq(test_str_2195, test_str_2195_2195);
}
END_TEST

START_TEST(sprintf_test_2196) {
  char test_str_2196[50] = "";
  char test_str_2196_2196[50] = "";
  s21_sprintf(test_str_2196, "%*G", 0, 1.23e-09);
  sprintf(test_str_2196_2196, "%*G", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2196, test_str_2196_2196);
}
END_TEST

START_TEST(sprintf_test_2197) {
  char test_str_2197[50] = "";
  char test_str_2197_2197[50] = "";
  s21_sprintf(test_str_2197, "%*G", 0, 1.23e-09);
  sprintf(test_str_2197_2197, "%*G", 0, 1.23e-09);
  ck_assert_str_eq(test_str_2197, test_str_2197_2197);
}
END_TEST

START_TEST(sprintf_test_2198) {
  char test_str_2198[50] = "";
  char test_str_2198_2198[50] = "";
  s21_sprintf(test_str_2198, "%*e", 10, 0.0);
  sprintf(test_str_2198_2198, "%*e", 10, 0.0);
  ck_assert_str_eq(test_str_2198, test_str_2198_2198);
}
END_TEST

START_TEST(sprintf_test_2199) {
  char test_str_2199[50] = "";
  char test_str_2199_2199[50] = "";
  s21_sprintf(test_str_2199, "%*e", 10, 123456789.0);
  sprintf(test_str_2199_2199, "%*e", 10, 123456789.0);
  ck_assert_str_eq(test_str_2199, test_str_2199_2199);
}
END_TEST

START_TEST(sprintf_test_2200) {
  char test_str_2200[50] = "";
  char test_str_2200_2200[50] = "";
  s21_sprintf(test_str_2200, "%*e", 10, 0.123456789);
  sprintf(test_str_2200_2200, "%*e", 10, 0.123456789);
  ck_assert_str_eq(test_str_2200, test_str_2200_2200);
}
END_TEST

START_TEST(sprintf_test_2201) {
  char test_str_2201[50] = "";
  char test_str_2201_2201[50] = "";
  s21_sprintf(test_str_2201, "%*e", 10, -123456789.0);
  sprintf(test_str_2201_2201, "%*e", 10, -123456789.0);
  ck_assert_str_eq(test_str_2201, test_str_2201_2201);
}
END_TEST

START_TEST(sprintf_test_2202) {
  char test_str_2202[50] = "";
  char test_str_2202_2202[50] = "";
  s21_sprintf(test_str_2202, "%*e", 10, -0.123456789);
  sprintf(test_str_2202_2202, "%*e", 10, -0.123456789);
  ck_assert_str_eq(test_str_2202, test_str_2202_2202);
}
END_TEST

START_TEST(sprintf_test_2203) {
  char test_str_2203[50] = "";
  char test_str_2203_2203[50] = "";
  s21_sprintf(test_str_2203, "%*e", 10, 123456789.12345679);
  sprintf(test_str_2203_2203, "%*e", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_2203, test_str_2203_2203);
}
END_TEST

START_TEST(sprintf_test_2204) {
  char test_str_2204[50] = "";
  char test_str_2204_2204[50] = "";
  s21_sprintf(test_str_2204, "%*e", 10, -123456789.12345678);
  sprintf(test_str_2204_2204, "%*e", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_2204, test_str_2204_2204);
}
END_TEST

START_TEST(sprintf_test_2205) {
  char test_str_2205[50] = "";
  char test_str_2205_2205[50] = "";
  s21_sprintf(test_str_2205, "%*e", 10, 1.23e-09);
  sprintf(test_str_2205_2205, "%*e", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2205, test_str_2205_2205);
}
END_TEST

START_TEST(sprintf_test_2206) {
  char test_str_2206[50] = "";
  char test_str_2206_2206[50] = "";
  s21_sprintf(test_str_2206, "%*e", 10, 1.23e-09);
  sprintf(test_str_2206_2206, "%*e", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2206, test_str_2206_2206);
}
END_TEST

START_TEST(sprintf_test_2207) {
  char test_str_2207[50] = "";
  char test_str_2207_2207[50] = "";
  s21_sprintf(test_str_2207, "%*E", 10, 0.0);
  sprintf(test_str_2207_2207, "%*E", 10, 0.0);
  ck_assert_str_eq(test_str_2207, test_str_2207_2207);
}
END_TEST

START_TEST(sprintf_test_2208) {
  char test_str_2208[50] = "";
  char test_str_2208_2208[50] = "";
  s21_sprintf(test_str_2208, "%*E", 10, 123456789.0);
  sprintf(test_str_2208_2208, "%*E", 10, 123456789.0);
  ck_assert_str_eq(test_str_2208, test_str_2208_2208);
}
END_TEST

START_TEST(sprintf_test_2209) {
  char test_str_2209[50] = "";
  char test_str_2209_2209[50] = "";
  s21_sprintf(test_str_2209, "%*E", 10, 0.123456789);
  sprintf(test_str_2209_2209, "%*E", 10, 0.123456789);
  ck_assert_str_eq(test_str_2209, test_str_2209_2209);
}
END_TEST

START_TEST(sprintf_test_2210) {
  char test_str_2210[50] = "";
  char test_str_2210_2210[50] = "";
  s21_sprintf(test_str_2210, "%*E", 10, -123456789.0);
  sprintf(test_str_2210_2210, "%*E", 10, -123456789.0);
  ck_assert_str_eq(test_str_2210, test_str_2210_2210);
}
END_TEST

START_TEST(sprintf_test_2211) {
  char test_str_2211[50] = "";
  char test_str_2211_2211[50] = "";
  s21_sprintf(test_str_2211, "%*E", 10, -0.123456789);
  sprintf(test_str_2211_2211, "%*E", 10, -0.123456789);
  ck_assert_str_eq(test_str_2211, test_str_2211_2211);
}
END_TEST

START_TEST(sprintf_test_2212) {
  char test_str_2212[50] = "";
  char test_str_2212_2212[50] = "";
  s21_sprintf(test_str_2212, "%*E", 10, 123456789.12345679);
  sprintf(test_str_2212_2212, "%*E", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_2212, test_str_2212_2212);
}
END_TEST

START_TEST(sprintf_test_2213) {
  char test_str_2213[50] = "";
  char test_str_2213_2213[50] = "";
  s21_sprintf(test_str_2213, "%*E", 10, -123456789.12345678);
  sprintf(test_str_2213_2213, "%*E", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_2213, test_str_2213_2213);
}
END_TEST

START_TEST(sprintf_test_2214) {
  char test_str_2214[50] = "";
  char test_str_2214_2214[50] = "";
  s21_sprintf(test_str_2214, "%*E", 10, 1.23e-09);
  sprintf(test_str_2214_2214, "%*E", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2214, test_str_2214_2214);
}
END_TEST

START_TEST(sprintf_test_2215) {
  char test_str_2215[50] = "";
  char test_str_2215_2215[50] = "";
  s21_sprintf(test_str_2215, "%*E", 10, 1.23e-09);
  sprintf(test_str_2215_2215, "%*E", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2215, test_str_2215_2215);
}
END_TEST

START_TEST(sprintf_test_2216) {
  char test_str_2216[50] = "";
  char test_str_2216_2216[50] = "";
  s21_sprintf(test_str_2216, "%*g", 10, 0.0);
  sprintf(test_str_2216_2216, "%*g", 10, 0.0);
  ck_assert_str_eq(test_str_2216, test_str_2216_2216);
}
END_TEST

START_TEST(sprintf_test_2217) {
  char test_str_2217[50] = "";
  char test_str_2217_2217[50] = "";
  s21_sprintf(test_str_2217, "%*g", 10, 123456789.0);
  sprintf(test_str_2217_2217, "%*g", 10, 123456789.0);
  ck_assert_str_eq(test_str_2217, test_str_2217_2217);
}
END_TEST

START_TEST(sprintf_test_2218) {
  char test_str_2218[50] = "";
  char test_str_2218_2218[50] = "";
  s21_sprintf(test_str_2218, "%*g", 10, 0.123456789);
  sprintf(test_str_2218_2218, "%*g", 10, 0.123456789);
  ck_assert_str_eq(test_str_2218, test_str_2218_2218);
}
END_TEST

START_TEST(sprintf_test_2219) {
  char test_str_2219[50] = "";
  char test_str_2219_2219[50] = "";
  s21_sprintf(test_str_2219, "%*g", 10, -123456789.0);
  sprintf(test_str_2219_2219, "%*g", 10, -123456789.0);
  ck_assert_str_eq(test_str_2219, test_str_2219_2219);
}
END_TEST

START_TEST(sprintf_test_2220) {
  char test_str_2220[50] = "";
  char test_str_2220_2220[50] = "";
  s21_sprintf(test_str_2220, "%*g", 10, -0.123456789);
  sprintf(test_str_2220_2220, "%*g", 10, -0.123456789);
  ck_assert_str_eq(test_str_2220, test_str_2220_2220);
}
END_TEST

START_TEST(sprintf_test_2221) {
  char test_str_2221[50] = "";
  char test_str_2221_2221[50] = "";
  s21_sprintf(test_str_2221, "%*g", 10, 123456789.12345679);
  sprintf(test_str_2221_2221, "%*g", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_2221, test_str_2221_2221);
}
END_TEST

START_TEST(sprintf_test_2222) {
  char test_str_2222[50] = "";
  char test_str_2222_2222[50] = "";
  s21_sprintf(test_str_2222, "%*g", 10, -123456789.12345678);
  sprintf(test_str_2222_2222, "%*g", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_2222, test_str_2222_2222);
}
END_TEST

START_TEST(sprintf_test_2223) {
  char test_str_2223[50] = "";
  char test_str_2223_2223[50] = "";
  s21_sprintf(test_str_2223, "%*g", 10, 1.23e-09);
  sprintf(test_str_2223_2223, "%*g", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2223, test_str_2223_2223);
}
END_TEST

START_TEST(sprintf_test_2224) {
  char test_str_2224[50] = "";
  char test_str_2224_2224[50] = "";
  s21_sprintf(test_str_2224, "%*g", 10, 1.23e-09);
  sprintf(test_str_2224_2224, "%*g", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2224, test_str_2224_2224);
}
END_TEST

START_TEST(sprintf_test_2225) {
  char test_str_2225[50] = "";
  char test_str_2225_2225[50] = "";
  s21_sprintf(test_str_2225, "%*G", 10, 0.0);
  sprintf(test_str_2225_2225, "%*G", 10, 0.0);
  ck_assert_str_eq(test_str_2225, test_str_2225_2225);
}
END_TEST

START_TEST(sprintf_test_2226) {
  char test_str_2226[50] = "";
  char test_str_2226_2226[50] = "";
  s21_sprintf(test_str_2226, "%*G", 10, 123456789.0);
  sprintf(test_str_2226_2226, "%*G", 10, 123456789.0);
  ck_assert_str_eq(test_str_2226, test_str_2226_2226);
}
END_TEST

START_TEST(sprintf_test_2227) {
  char test_str_2227[50] = "";
  char test_str_2227_2227[50] = "";
  s21_sprintf(test_str_2227, "%*G", 10, 0.123456789);
  sprintf(test_str_2227_2227, "%*G", 10, 0.123456789);
  ck_assert_str_eq(test_str_2227, test_str_2227_2227);
}
END_TEST

START_TEST(sprintf_test_2228) {
  char test_str_2228[50] = "";
  char test_str_2228_2228[50] = "";
  s21_sprintf(test_str_2228, "%*G", 10, -123456789.0);
  sprintf(test_str_2228_2228, "%*G", 10, -123456789.0);
  ck_assert_str_eq(test_str_2228, test_str_2228_2228);
}
END_TEST

START_TEST(sprintf_test_2229) {
  char test_str_2229[50] = "";
  char test_str_2229_2229[50] = "";
  s21_sprintf(test_str_2229, "%*G", 10, -0.123456789);
  sprintf(test_str_2229_2229, "%*G", 10, -0.123456789);
  ck_assert_str_eq(test_str_2229, test_str_2229_2229);
}
END_TEST

START_TEST(sprintf_test_2230) {
  char test_str_2230[50] = "";
  char test_str_2230_2230[50] = "";
  s21_sprintf(test_str_2230, "%*G", 10, 123456789.12345679);
  sprintf(test_str_2230_2230, "%*G", 10, 123456789.12345679);
  ck_assert_str_eq(test_str_2230, test_str_2230_2230);
}
END_TEST

START_TEST(sprintf_test_2231) {
  char test_str_2231[50] = "";
  char test_str_2231_2231[50] = "";
  s21_sprintf(test_str_2231, "%*G", 10, -123456789.12345678);
  sprintf(test_str_2231_2231, "%*G", 10, -123456789.12345678);
  ck_assert_str_eq(test_str_2231, test_str_2231_2231);
}
END_TEST

START_TEST(sprintf_test_2232) {
  char test_str_2232[50] = "";
  char test_str_2232_2232[50] = "";
  s21_sprintf(test_str_2232, "%*G", 10, 1.23e-09);
  sprintf(test_str_2232_2232, "%*G", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2232, test_str_2232_2232);
}
END_TEST

START_TEST(sprintf_test_2233) {
  char test_str_2233[50] = "";
  char test_str_2233_2233[50] = "";
  s21_sprintf(test_str_2233, "%*G", 10, 1.23e-09);
  sprintf(test_str_2233_2233, "%*G", 10, 1.23e-09);
  ck_assert_str_eq(test_str_2233, test_str_2233_2233);
}
END_TEST

START_TEST(sprintf_test_2234) {
  char test_str_2234[50] = "";
  char test_str_2234_2234[50] = "";
  s21_sprintf(test_str_2234, "%*e", 20, 0.0);
  sprintf(test_str_2234_2234, "%*e", 20, 0.0);
  ck_assert_str_eq(test_str_2234, test_str_2234_2234);
}
END_TEST

START_TEST(sprintf_test_2235) {
  char test_str_2235[50] = "";
  char test_str_2235_2235[50] = "";
  s21_sprintf(test_str_2235, "%*e", 20, 123456789.0);
  sprintf(test_str_2235_2235, "%*e", 20, 123456789.0);
  ck_assert_str_eq(test_str_2235, test_str_2235_2235);
}
END_TEST

START_TEST(sprintf_test_2236) {
  char test_str_2236[50] = "";
  char test_str_2236_2236[50] = "";
  s21_sprintf(test_str_2236, "%*e", 20, 0.123456789);
  sprintf(test_str_2236_2236, "%*e", 20, 0.123456789);
  ck_assert_str_eq(test_str_2236, test_str_2236_2236);
}
END_TEST

START_TEST(sprintf_test_2237) {
  char test_str_2237[50] = "";
  char test_str_2237_2237[50] = "";
  s21_sprintf(test_str_2237, "%*e", 20, -123456789.0);
  sprintf(test_str_2237_2237, "%*e", 20, -123456789.0);
  ck_assert_str_eq(test_str_2237, test_str_2237_2237);
}
END_TEST

START_TEST(sprintf_test_2238) {
  char test_str_2238[50] = "";
  char test_str_2238_2238[50] = "";
  s21_sprintf(test_str_2238, "%*e", 20, -0.123456789);
  sprintf(test_str_2238_2238, "%*e", 20, -0.123456789);
  ck_assert_str_eq(test_str_2238, test_str_2238_2238);
}
END_TEST

START_TEST(sprintf_test_2239) {
  char test_str_2239[50] = "";
  char test_str_2239_2239[50] = "";
  s21_sprintf(test_str_2239, "%*e", 20, 123456789.12345679);
  sprintf(test_str_2239_2239, "%*e", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_2239, test_str_2239_2239);
}
END_TEST

START_TEST(sprintf_test_2240) {
  char test_str_2240[50] = "";
  char test_str_2240_2240[50] = "";
  s21_sprintf(test_str_2240, "%*e", 20, -123456789.12345678);
  sprintf(test_str_2240_2240, "%*e", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_2240, test_str_2240_2240);
}
END_TEST

START_TEST(sprintf_test_2241) {
  char test_str_2241[50] = "";
  char test_str_2241_2241[50] = "";
  s21_sprintf(test_str_2241, "%*e", 20, 1.23e-09);
  sprintf(test_str_2241_2241, "%*e", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2241, test_str_2241_2241);
}
END_TEST

START_TEST(sprintf_test_2242) {
  char test_str_2242[50] = "";
  char test_str_2242_2242[50] = "";
  s21_sprintf(test_str_2242, "%*e", 20, 1.23e-09);
  sprintf(test_str_2242_2242, "%*e", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2242, test_str_2242_2242);
}
END_TEST

START_TEST(sprintf_test_2243) {
  char test_str_2243[50] = "";
  char test_str_2243_2243[50] = "";
  s21_sprintf(test_str_2243, "%*E", 20, 0.0);
  sprintf(test_str_2243_2243, "%*E", 20, 0.0);
  ck_assert_str_eq(test_str_2243, test_str_2243_2243);
}
END_TEST

START_TEST(sprintf_test_2244) {
  char test_str_2244[50] = "";
  char test_str_2244_2244[50] = "";
  s21_sprintf(test_str_2244, "%*E", 20, 123456789.0);
  sprintf(test_str_2244_2244, "%*E", 20, 123456789.0);
  ck_assert_str_eq(test_str_2244, test_str_2244_2244);
}
END_TEST

START_TEST(sprintf_test_2245) {
  char test_str_2245[50] = "";
  char test_str_2245_2245[50] = "";
  s21_sprintf(test_str_2245, "%*E", 20, 0.123456789);
  sprintf(test_str_2245_2245, "%*E", 20, 0.123456789);
  ck_assert_str_eq(test_str_2245, test_str_2245_2245);
}
END_TEST

START_TEST(sprintf_test_2246) {
  char test_str_2246[50] = "";
  char test_str_2246_2246[50] = "";
  s21_sprintf(test_str_2246, "%*E", 20, -123456789.0);
  sprintf(test_str_2246_2246, "%*E", 20, -123456789.0);
  ck_assert_str_eq(test_str_2246, test_str_2246_2246);
}
END_TEST

START_TEST(sprintf_test_2247) {
  char test_str_2247[50] = "";
  char test_str_2247_2247[50] = "";
  s21_sprintf(test_str_2247, "%*E", 20, -0.123456789);
  sprintf(test_str_2247_2247, "%*E", 20, -0.123456789);
  ck_assert_str_eq(test_str_2247, test_str_2247_2247);
}
END_TEST

START_TEST(sprintf_test_2248) {
  char test_str_2248[50] = "";
  char test_str_2248_2248[50] = "";
  s21_sprintf(test_str_2248, "%*E", 20, 123456789.12345679);
  sprintf(test_str_2248_2248, "%*E", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_2248, test_str_2248_2248);
}
END_TEST

START_TEST(sprintf_test_2249) {
  char test_str_2249[50] = "";
  char test_str_2249_2249[50] = "";
  s21_sprintf(test_str_2249, "%*E", 20, -123456789.12345678);
  sprintf(test_str_2249_2249, "%*E", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_2249, test_str_2249_2249);
}
END_TEST

START_TEST(sprintf_test_2250) {
  char test_str_2250[50] = "";
  char test_str_2250_2250[50] = "";
  s21_sprintf(test_str_2250, "%*E", 20, 1.23e-09);
  sprintf(test_str_2250_2250, "%*E", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2250, test_str_2250_2250);
}
END_TEST

START_TEST(sprintf_test_2251) {
  char test_str_2251[50] = "";
  char test_str_2251_2251[50] = "";
  s21_sprintf(test_str_2251, "%*E", 20, 1.23e-09);
  sprintf(test_str_2251_2251, "%*E", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2251, test_str_2251_2251);
}
END_TEST

START_TEST(sprintf_test_2252) {
  char test_str_2252[50] = "";
  char test_str_2252_2252[50] = "";
  s21_sprintf(test_str_2252, "%*g", 20, 0.0);
  sprintf(test_str_2252_2252, "%*g", 20, 0.0);
  ck_assert_str_eq(test_str_2252, test_str_2252_2252);
}
END_TEST

START_TEST(sprintf_test_2253) {
  char test_str_2253[50] = "";
  char test_str_2253_2253[50] = "";
  s21_sprintf(test_str_2253, "%*g", 20, 123456789.0);
  sprintf(test_str_2253_2253, "%*g", 20, 123456789.0);
  ck_assert_str_eq(test_str_2253, test_str_2253_2253);
}
END_TEST

START_TEST(sprintf_test_2254) {
  char test_str_2254[50] = "";
  char test_str_2254_2254[50] = "";
  s21_sprintf(test_str_2254, "%*g", 20, 0.123456789);
  sprintf(test_str_2254_2254, "%*g", 20, 0.123456789);
  ck_assert_str_eq(test_str_2254, test_str_2254_2254);
}
END_TEST

START_TEST(sprintf_test_2255) {
  char test_str_2255[50] = "";
  char test_str_2255_2255[50] = "";
  s21_sprintf(test_str_2255, "%*g", 20, -123456789.0);
  sprintf(test_str_2255_2255, "%*g", 20, -123456789.0);
  ck_assert_str_eq(test_str_2255, test_str_2255_2255);
}
END_TEST

START_TEST(sprintf_test_2256) {
  char test_str_2256[50] = "";
  char test_str_2256_2256[50] = "";
  s21_sprintf(test_str_2256, "%*g", 20, -0.123456789);
  sprintf(test_str_2256_2256, "%*g", 20, -0.123456789);
  ck_assert_str_eq(test_str_2256, test_str_2256_2256);
}
END_TEST

START_TEST(sprintf_test_2257) {
  char test_str_2257[50] = "";
  char test_str_2257_2257[50] = "";
  s21_sprintf(test_str_2257, "%*g", 20, 123456789.12345679);
  sprintf(test_str_2257_2257, "%*g", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_2257, test_str_2257_2257);
}
END_TEST

START_TEST(sprintf_test_2258) {
  char test_str_2258[50] = "";
  char test_str_2258_2258[50] = "";
  s21_sprintf(test_str_2258, "%*g", 20, -123456789.12345678);
  sprintf(test_str_2258_2258, "%*g", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_2258, test_str_2258_2258);
}
END_TEST

START_TEST(sprintf_test_2259) {
  char test_str_2259[50] = "";
  char test_str_2259_2259[50] = "";
  s21_sprintf(test_str_2259, "%*g", 20, 1.23e-09);
  sprintf(test_str_2259_2259, "%*g", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2259, test_str_2259_2259);
}
END_TEST

START_TEST(sprintf_test_2260) {
  char test_str_2260[50] = "";
  char test_str_2260_2260[50] = "";
  s21_sprintf(test_str_2260, "%*g", 20, 1.23e-09);
  sprintf(test_str_2260_2260, "%*g", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2260, test_str_2260_2260);
}
END_TEST

START_TEST(sprintf_test_2261) {
  char test_str_2261[50] = "";
  char test_str_2261_2261[50] = "";
  s21_sprintf(test_str_2261, "%*G", 20, 0.0);
  sprintf(test_str_2261_2261, "%*G", 20, 0.0);
  ck_assert_str_eq(test_str_2261, test_str_2261_2261);
}
END_TEST

START_TEST(sprintf_test_2262) {
  char test_str_2262[50] = "";
  char test_str_2262_2262[50] = "";
  s21_sprintf(test_str_2262, "%*G", 20, 123456789.0);
  sprintf(test_str_2262_2262, "%*G", 20, 123456789.0);
  ck_assert_str_eq(test_str_2262, test_str_2262_2262);
}
END_TEST

START_TEST(sprintf_test_2263) {
  char test_str_2263[50] = "";
  char test_str_2263_2263[50] = "";
  s21_sprintf(test_str_2263, "%*G", 20, 0.123456789);
  sprintf(test_str_2263_2263, "%*G", 20, 0.123456789);
  ck_assert_str_eq(test_str_2263, test_str_2263_2263);
}
END_TEST

START_TEST(sprintf_test_2264) {
  char test_str_2264[50] = "";
  char test_str_2264_2264[50] = "";
  s21_sprintf(test_str_2264, "%*G", 20, -123456789.0);
  sprintf(test_str_2264_2264, "%*G", 20, -123456789.0);
  ck_assert_str_eq(test_str_2264, test_str_2264_2264);
}
END_TEST

START_TEST(sprintf_test_2265) {
  char test_str_2265[50] = "";
  char test_str_2265_2265[50] = "";
  s21_sprintf(test_str_2265, "%*G", 20, -0.123456789);
  sprintf(test_str_2265_2265, "%*G", 20, -0.123456789);
  ck_assert_str_eq(test_str_2265, test_str_2265_2265);
}
END_TEST

START_TEST(sprintf_test_2266) {
  char test_str_2266[50] = "";
  char test_str_2266_2266[50] = "";
  s21_sprintf(test_str_2266, "%*G", 20, 123456789.12345679);
  sprintf(test_str_2266_2266, "%*G", 20, 123456789.12345679);
  ck_assert_str_eq(test_str_2266, test_str_2266_2266);
}
END_TEST

START_TEST(sprintf_test_2267) {
  char test_str_2267[50] = "";
  char test_str_2267_2267[50] = "";
  s21_sprintf(test_str_2267, "%*G", 20, -123456789.12345678);
  sprintf(test_str_2267_2267, "%*G", 20, -123456789.12345678);
  ck_assert_str_eq(test_str_2267, test_str_2267_2267);
}
END_TEST

START_TEST(sprintf_test_2268) {
  char test_str_2268[50] = "";
  char test_str_2268_2268[50] = "";
  s21_sprintf(test_str_2268, "%*G", 20, 1.23e-09);
  sprintf(test_str_2268_2268, "%*G", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2268, test_str_2268_2268);
}
END_TEST

START_TEST(sprintf_test_2269) {
  char test_str_2269[50] = "";
  char test_str_2269_2269[50] = "";
  s21_sprintf(test_str_2269, "%*G", 20, 1.23e-09);
  sprintf(test_str_2269_2269, "%*G", 20, 1.23e-09);
  ck_assert_str_eq(test_str_2269, test_str_2269_2269);
}
END_TEST

START_TEST(sprintf_test_2270) {
  char test_str_2270[50] = "";
  char test_str_2270_2270[50] = "";
  s21_sprintf(test_str_2270, "%*e", -10, 0.0);
  sprintf(test_str_2270_2270, "%*e", -10, 0.0);
  ck_assert_str_eq(test_str_2270, test_str_2270_2270);
}
END_TEST

START_TEST(sprintf_test_2271) {
  char test_str_2271[50] = "";
  char test_str_2271_2271[50] = "";
  s21_sprintf(test_str_2271, "%*e", -10, 123456789.0);
  sprintf(test_str_2271_2271, "%*e", -10, 123456789.0);
  ck_assert_str_eq(test_str_2271, test_str_2271_2271);
}
END_TEST

START_TEST(sprintf_test_2272) {
  char test_str_2272[50] = "";
  char test_str_2272_2272[50] = "";
  s21_sprintf(test_str_2272, "%*e", -10, 0.123456789);
  sprintf(test_str_2272_2272, "%*e", -10, 0.123456789);
  ck_assert_str_eq(test_str_2272, test_str_2272_2272);
}
END_TEST

START_TEST(sprintf_test_2273) {
  char test_str_2273[50] = "";
  char test_str_2273_2273[50] = "";
  s21_sprintf(test_str_2273, "%*e", -10, -123456789.0);
  sprintf(test_str_2273_2273, "%*e", -10, -123456789.0);
  ck_assert_str_eq(test_str_2273, test_str_2273_2273);
}
END_TEST

START_TEST(sprintf_test_2274) {
  char test_str_2274[50] = "";
  char test_str_2274_2274[50] = "";
  s21_sprintf(test_str_2274, "%*e", -10, -0.123456789);
  sprintf(test_str_2274_2274, "%*e", -10, -0.123456789);
  ck_assert_str_eq(test_str_2274, test_str_2274_2274);
}
END_TEST

START_TEST(sprintf_test_2275) {
  char test_str_2275[50] = "";
  char test_str_2275_2275[50] = "";
  s21_sprintf(test_str_2275, "%*e", -10, 123456789.12345679);
  sprintf(test_str_2275_2275, "%*e", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_2275, test_str_2275_2275);
}
END_TEST

START_TEST(sprintf_test_2276) {
  char test_str_2276[50] = "";
  char test_str_2276_2276[50] = "";
  s21_sprintf(test_str_2276, "%*e", -10, -123456789.12345678);
  sprintf(test_str_2276_2276, "%*e", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_2276, test_str_2276_2276);
}
END_TEST

START_TEST(sprintf_test_2277) {
  char test_str_2277[50] = "";
  char test_str_2277_2277[50] = "";
  s21_sprintf(test_str_2277, "%*e", -10, 1.23e-09);
  sprintf(test_str_2277_2277, "%*e", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2277, test_str_2277_2277);
}
END_TEST

START_TEST(sprintf_test_2278) {
  char test_str_2278[50] = "";
  char test_str_2278_2278[50] = "";
  s21_sprintf(test_str_2278, "%*e", -10, 1.23e-09);
  sprintf(test_str_2278_2278, "%*e", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2278, test_str_2278_2278);
}
END_TEST

START_TEST(sprintf_test_2279) {
  char test_str_2279[50] = "";
  char test_str_2279_2279[50] = "";
  s21_sprintf(test_str_2279, "%*E", -10, 0.0);
  sprintf(test_str_2279_2279, "%*E", -10, 0.0);
  ck_assert_str_eq(test_str_2279, test_str_2279_2279);
}
END_TEST

START_TEST(sprintf_test_2280) {
  char test_str_2280[50] = "";
  char test_str_2280_2280[50] = "";
  s21_sprintf(test_str_2280, "%*E", -10, 123456789.0);
  sprintf(test_str_2280_2280, "%*E", -10, 123456789.0);
  ck_assert_str_eq(test_str_2280, test_str_2280_2280);
}
END_TEST

START_TEST(sprintf_test_2281) {
  char test_str_2281[50] = "";
  char test_str_2281_2281[50] = "";
  s21_sprintf(test_str_2281, "%*E", -10, 0.123456789);
  sprintf(test_str_2281_2281, "%*E", -10, 0.123456789);
  ck_assert_str_eq(test_str_2281, test_str_2281_2281);
}
END_TEST

START_TEST(sprintf_test_2282) {
  char test_str_2282[50] = "";
  char test_str_2282_2282[50] = "";
  s21_sprintf(test_str_2282, "%*E", -10, -123456789.0);
  sprintf(test_str_2282_2282, "%*E", -10, -123456789.0);
  ck_assert_str_eq(test_str_2282, test_str_2282_2282);
}
END_TEST

START_TEST(sprintf_test_2283) {
  char test_str_2283[50] = "";
  char test_str_2283_2283[50] = "";
  s21_sprintf(test_str_2283, "%*E", -10, -0.123456789);
  sprintf(test_str_2283_2283, "%*E", -10, -0.123456789);
  ck_assert_str_eq(test_str_2283, test_str_2283_2283);
}
END_TEST

START_TEST(sprintf_test_2284) {
  char test_str_2284[50] = "";
  char test_str_2284_2284[50] = "";
  s21_sprintf(test_str_2284, "%*E", -10, 123456789.12345679);
  sprintf(test_str_2284_2284, "%*E", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_2284, test_str_2284_2284);
}
END_TEST

START_TEST(sprintf_test_2285) {
  char test_str_2285[50] = "";
  char test_str_2285_2285[50] = "";
  s21_sprintf(test_str_2285, "%*E", -10, -123456789.12345678);
  sprintf(test_str_2285_2285, "%*E", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_2285, test_str_2285_2285);
}
END_TEST

START_TEST(sprintf_test_2286) {
  char test_str_2286[50] = "";
  char test_str_2286_2286[50] = "";
  s21_sprintf(test_str_2286, "%*E", -10, 1.23e-09);
  sprintf(test_str_2286_2286, "%*E", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2286, test_str_2286_2286);
}
END_TEST

START_TEST(sprintf_test_2287) {
  char test_str_2287[50] = "";
  char test_str_2287_2287[50] = "";
  s21_sprintf(test_str_2287, "%*E", -10, 1.23e-09);
  sprintf(test_str_2287_2287, "%*E", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2287, test_str_2287_2287);
}
END_TEST

START_TEST(sprintf_test_2288) {
  char test_str_2288[50] = "";
  char test_str_2288_2288[50] = "";
  s21_sprintf(test_str_2288, "%*g", -10, 0.0);
  sprintf(test_str_2288_2288, "%*g", -10, 0.0);
  ck_assert_str_eq(test_str_2288, test_str_2288_2288);
}
END_TEST

START_TEST(sprintf_test_2289) {
  char test_str_2289[50] = "";
  char test_str_2289_2289[50] = "";
  s21_sprintf(test_str_2289, "%*g", -10, 123456789.0);
  sprintf(test_str_2289_2289, "%*g", -10, 123456789.0);
  ck_assert_str_eq(test_str_2289, test_str_2289_2289);
}
END_TEST

START_TEST(sprintf_test_2290) {
  char test_str_2290[50] = "";
  char test_str_2290_2290[50] = "";
  s21_sprintf(test_str_2290, "%*g", -10, 0.123456789);
  sprintf(test_str_2290_2290, "%*g", -10, 0.123456789);
  ck_assert_str_eq(test_str_2290, test_str_2290_2290);
}
END_TEST

START_TEST(sprintf_test_2291) {
  char test_str_2291[50] = "";
  char test_str_2291_2291[50] = "";
  s21_sprintf(test_str_2291, "%*g", -10, -123456789.0);
  sprintf(test_str_2291_2291, "%*g", -10, -123456789.0);
  ck_assert_str_eq(test_str_2291, test_str_2291_2291);
}
END_TEST

START_TEST(sprintf_test_2292) {
  char test_str_2292[50] = "";
  char test_str_2292_2292[50] = "";
  s21_sprintf(test_str_2292, "%*g", -10, -0.123456789);
  sprintf(test_str_2292_2292, "%*g", -10, -0.123456789);
  ck_assert_str_eq(test_str_2292, test_str_2292_2292);
}
END_TEST

START_TEST(sprintf_test_2293) {
  char test_str_2293[50] = "";
  char test_str_2293_2293[50] = "";
  s21_sprintf(test_str_2293, "%*g", -10, 123456789.12345679);
  sprintf(test_str_2293_2293, "%*g", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_2293, test_str_2293_2293);
}
END_TEST

START_TEST(sprintf_test_2294) {
  char test_str_2294[50] = "";
  char test_str_2294_2294[50] = "";
  s21_sprintf(test_str_2294, "%*g", -10, -123456789.12345678);
  sprintf(test_str_2294_2294, "%*g", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_2294, test_str_2294_2294);
}
END_TEST

START_TEST(sprintf_test_2295) {
  char test_str_2295[50] = "";
  char test_str_2295_2295[50] = "";
  s21_sprintf(test_str_2295, "%*g", -10, 1.23e-09);
  sprintf(test_str_2295_2295, "%*g", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2295, test_str_2295_2295);
}
END_TEST

START_TEST(sprintf_test_2296) {
  char test_str_2296[50] = "";
  char test_str_2296_2296[50] = "";
  s21_sprintf(test_str_2296, "%*g", -10, 1.23e-09);
  sprintf(test_str_2296_2296, "%*g", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2296, test_str_2296_2296);
}
END_TEST

START_TEST(sprintf_test_2297) {
  char test_str_2297[50] = "";
  char test_str_2297_2297[50] = "";
  s21_sprintf(test_str_2297, "%*G", -10, 0.0);
  sprintf(test_str_2297_2297, "%*G", -10, 0.0);
  ck_assert_str_eq(test_str_2297, test_str_2297_2297);
}
END_TEST

START_TEST(sprintf_test_2298) {
  char test_str_2298[50] = "";
  char test_str_2298_2298[50] = "";
  s21_sprintf(test_str_2298, "%*G", -10, 123456789.0);
  sprintf(test_str_2298_2298, "%*G", -10, 123456789.0);
  ck_assert_str_eq(test_str_2298, test_str_2298_2298);
}
END_TEST

START_TEST(sprintf_test_2299) {
  char test_str_2299[50] = "";
  char test_str_2299_2299[50] = "";
  s21_sprintf(test_str_2299, "%*G", -10, 0.123456789);
  sprintf(test_str_2299_2299, "%*G", -10, 0.123456789);
  ck_assert_str_eq(test_str_2299, test_str_2299_2299);
}
END_TEST

START_TEST(sprintf_test_2300) {
  char test_str_2300[50] = "";
  char test_str_2300_2300[50] = "";
  s21_sprintf(test_str_2300, "%*G", -10, -123456789.0);
  sprintf(test_str_2300_2300, "%*G", -10, -123456789.0);
  ck_assert_str_eq(test_str_2300, test_str_2300_2300);
}
END_TEST

START_TEST(sprintf_test_2301) {
  char test_str_2301[50] = "";
  char test_str_2301_2301[50] = "";
  s21_sprintf(test_str_2301, "%*G", -10, -0.123456789);
  sprintf(test_str_2301_2301, "%*G", -10, -0.123456789);
  ck_assert_str_eq(test_str_2301, test_str_2301_2301);
}
END_TEST

START_TEST(sprintf_test_2302) {
  char test_str_2302[50] = "";
  char test_str_2302_2302[50] = "";
  s21_sprintf(test_str_2302, "%*G", -10, 123456789.12345679);
  sprintf(test_str_2302_2302, "%*G", -10, 123456789.12345679);
  ck_assert_str_eq(test_str_2302, test_str_2302_2302);
}
END_TEST

START_TEST(sprintf_test_2303) {
  char test_str_2303[50] = "";
  char test_str_2303_2303[50] = "";
  s21_sprintf(test_str_2303, "%*G", -10, -123456789.12345678);
  sprintf(test_str_2303_2303, "%*G", -10, -123456789.12345678);
  ck_assert_str_eq(test_str_2303, test_str_2303_2303);
}
END_TEST

START_TEST(sprintf_test_2304) {
  char test_str_2304[50] = "";
  char test_str_2304_2304[50] = "";
  s21_sprintf(test_str_2304, "%*G", -10, 1.23e-09);
  sprintf(test_str_2304_2304, "%*G", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2304, test_str_2304_2304);
}
END_TEST

START_TEST(sprintf_test_2305) {
  char test_str_2305[50] = "";
  char test_str_2305_2305[50] = "";
  s21_sprintf(test_str_2305, "%*G", -10, 1.23e-09);
  sprintf(test_str_2305_2305, "%*G", -10, 1.23e-09);
  ck_assert_str_eq(test_str_2305, test_str_2305_2305);
}
END_TEST

START_TEST(sprintf_test_2306) {
  char test_str_2306[50] = "";
  char test_str_2306_2306[50] = "";
  s21_sprintf(test_str_2306, "%*e", -20, 0.0);
  sprintf(test_str_2306_2306, "%*e", -20, 0.0);
  ck_assert_str_eq(test_str_2306, test_str_2306_2306);
}
END_TEST

START_TEST(sprintf_test_2307) {
  char test_str_2307[50] = "";
  char test_str_2307_2307[50] = "";
  s21_sprintf(test_str_2307, "%*e", -20, 123456789.0);
  sprintf(test_str_2307_2307, "%*e", -20, 123456789.0);
  ck_assert_str_eq(test_str_2307, test_str_2307_2307);
}
END_TEST

START_TEST(sprintf_test_2308) {
  char test_str_2308[50] = "";
  char test_str_2308_2308[50] = "";
  s21_sprintf(test_str_2308, "%*e", -20, 0.123456789);
  sprintf(test_str_2308_2308, "%*e", -20, 0.123456789);
  ck_assert_str_eq(test_str_2308, test_str_2308_2308);
}
END_TEST

START_TEST(sprintf_test_2309) {
  char test_str_2309[50] = "";
  char test_str_2309_2309[50] = "";
  s21_sprintf(test_str_2309, "%*e", -20, -123456789.0);
  sprintf(test_str_2309_2309, "%*e", -20, -123456789.0);
  ck_assert_str_eq(test_str_2309, test_str_2309_2309);
}
END_TEST

START_TEST(sprintf_test_2310) {
  char test_str_2310[50] = "";
  char test_str_2310_2310[50] = "";
  s21_sprintf(test_str_2310, "%*e", -20, -0.123456789);
  sprintf(test_str_2310_2310, "%*e", -20, -0.123456789);
  ck_assert_str_eq(test_str_2310, test_str_2310_2310);
}
END_TEST

START_TEST(sprintf_test_2311) {
  char test_str_2311[50] = "";
  char test_str_2311_2311[50] = "";
  s21_sprintf(test_str_2311, "%*e", -20, 123456789.12345679);
  sprintf(test_str_2311_2311, "%*e", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_2311, test_str_2311_2311);
}
END_TEST

START_TEST(sprintf_test_2312) {
  char test_str_2312[50] = "";
  char test_str_2312_2312[50] = "";
  s21_sprintf(test_str_2312, "%*e", -20, -123456789.12345678);
  sprintf(test_str_2312_2312, "%*e", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_2312, test_str_2312_2312);
}
END_TEST

START_TEST(sprintf_test_2313) {
  char test_str_2313[50] = "";
  char test_str_2313_2313[50] = "";
  s21_sprintf(test_str_2313, "%*e", -20, 1.23e-09);
  sprintf(test_str_2313_2313, "%*e", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2313, test_str_2313_2313);
}
END_TEST

START_TEST(sprintf_test_2314) {
  char test_str_2314[50] = "";
  char test_str_2314_2314[50] = "";
  s21_sprintf(test_str_2314, "%*e", -20, 1.23e-09);
  sprintf(test_str_2314_2314, "%*e", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2314, test_str_2314_2314);
}
END_TEST

START_TEST(sprintf_test_2315) {
  char test_str_2315[50] = "";
  char test_str_2315_2315[50] = "";
  s21_sprintf(test_str_2315, "%*E", -20, 0.0);
  sprintf(test_str_2315_2315, "%*E", -20, 0.0);
  ck_assert_str_eq(test_str_2315, test_str_2315_2315);
}
END_TEST

START_TEST(sprintf_test_2316) {
  char test_str_2316[50] = "";
  char test_str_2316_2316[50] = "";
  s21_sprintf(test_str_2316, "%*E", -20, 123456789.0);
  sprintf(test_str_2316_2316, "%*E", -20, 123456789.0);
  ck_assert_str_eq(test_str_2316, test_str_2316_2316);
}
END_TEST

START_TEST(sprintf_test_2317) {
  char test_str_2317[50] = "";
  char test_str_2317_2317[50] = "";
  s21_sprintf(test_str_2317, "%*E", -20, 0.123456789);
  sprintf(test_str_2317_2317, "%*E", -20, 0.123456789);
  ck_assert_str_eq(test_str_2317, test_str_2317_2317);
}
END_TEST

START_TEST(sprintf_test_2318) {
  char test_str_2318[50] = "";
  char test_str_2318_2318[50] = "";
  s21_sprintf(test_str_2318, "%*E", -20, -123456789.0);
  sprintf(test_str_2318_2318, "%*E", -20, -123456789.0);
  ck_assert_str_eq(test_str_2318, test_str_2318_2318);
}
END_TEST

START_TEST(sprintf_test_2319) {
  char test_str_2319[50] = "";
  char test_str_2319_2319[50] = "";
  s21_sprintf(test_str_2319, "%*E", -20, -0.123456789);
  sprintf(test_str_2319_2319, "%*E", -20, -0.123456789);
  ck_assert_str_eq(test_str_2319, test_str_2319_2319);
}
END_TEST

START_TEST(sprintf_test_2320) {
  char test_str_2320[50] = "";
  char test_str_2320_2320[50] = "";
  s21_sprintf(test_str_2320, "%*E", -20, 123456789.12345679);
  sprintf(test_str_2320_2320, "%*E", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_2320, test_str_2320_2320);
}
END_TEST

START_TEST(sprintf_test_2321) {
  char test_str_2321[50] = "";
  char test_str_2321_2321[50] = "";
  s21_sprintf(test_str_2321, "%*E", -20, -123456789.12345678);
  sprintf(test_str_2321_2321, "%*E", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_2321, test_str_2321_2321);
}
END_TEST

START_TEST(sprintf_test_2322) {
  char test_str_2322[50] = "";
  char test_str_2322_2322[50] = "";
  s21_sprintf(test_str_2322, "%*E", -20, 1.23e-09);
  sprintf(test_str_2322_2322, "%*E", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2322, test_str_2322_2322);
}
END_TEST

START_TEST(sprintf_test_2323) {
  char test_str_2323[50] = "";
  char test_str_2323_2323[50] = "";
  s21_sprintf(test_str_2323, "%*E", -20, 1.23e-09);
  sprintf(test_str_2323_2323, "%*E", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2323, test_str_2323_2323);
}
END_TEST

START_TEST(sprintf_test_2324) {
  char test_str_2324[50] = "";
  char test_str_2324_2324[50] = "";
  s21_sprintf(test_str_2324, "%*g", -20, 0.0);
  sprintf(test_str_2324_2324, "%*g", -20, 0.0);
  ck_assert_str_eq(test_str_2324, test_str_2324_2324);
}
END_TEST

START_TEST(sprintf_test_2325) {
  char test_str_2325[50] = "";
  char test_str_2325_2325[50] = "";
  s21_sprintf(test_str_2325, "%*g", -20, 123456789.0);
  sprintf(test_str_2325_2325, "%*g", -20, 123456789.0);
  ck_assert_str_eq(test_str_2325, test_str_2325_2325);
}
END_TEST

START_TEST(sprintf_test_2326) {
  char test_str_2326[50] = "";
  char test_str_2326_2326[50] = "";
  s21_sprintf(test_str_2326, "%*g", -20, 0.123456789);
  sprintf(test_str_2326_2326, "%*g", -20, 0.123456789);
  ck_assert_str_eq(test_str_2326, test_str_2326_2326);
}
END_TEST

START_TEST(sprintf_test_2327) {
  char test_str_2327[50] = "";
  char test_str_2327_2327[50] = "";
  s21_sprintf(test_str_2327, "%*g", -20, -123456789.0);
  sprintf(test_str_2327_2327, "%*g", -20, -123456789.0);
  ck_assert_str_eq(test_str_2327, test_str_2327_2327);
}
END_TEST

START_TEST(sprintf_test_2328) {
  char test_str_2328[50] = "";
  char test_str_2328_2328[50] = "";
  s21_sprintf(test_str_2328, "%*g", -20, -0.123456789);
  sprintf(test_str_2328_2328, "%*g", -20, -0.123456789);
  ck_assert_str_eq(test_str_2328, test_str_2328_2328);
}
END_TEST

START_TEST(sprintf_test_2329) {
  char test_str_2329[50] = "";
  char test_str_2329_2329[50] = "";
  s21_sprintf(test_str_2329, "%*g", -20, 123456789.12345679);
  sprintf(test_str_2329_2329, "%*g", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_2329, test_str_2329_2329);
}
END_TEST

START_TEST(sprintf_test_2330) {
  char test_str_2330[50] = "";
  char test_str_2330_2330[50] = "";
  s21_sprintf(test_str_2330, "%*g", -20, -123456789.12345678);
  sprintf(test_str_2330_2330, "%*g", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_2330, test_str_2330_2330);
}
END_TEST

START_TEST(sprintf_test_2331) {
  char test_str_2331[50] = "";
  char test_str_2331_2331[50] = "";
  s21_sprintf(test_str_2331, "%*g", -20, 1.23e-09);
  sprintf(test_str_2331_2331, "%*g", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2331, test_str_2331_2331);
}
END_TEST

START_TEST(sprintf_test_2332) {
  char test_str_2332[50] = "";
  char test_str_2332_2332[50] = "";
  s21_sprintf(test_str_2332, "%*g", -20, 1.23e-09);
  sprintf(test_str_2332_2332, "%*g", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2332, test_str_2332_2332);
}
END_TEST

START_TEST(sprintf_test_2333) {
  char test_str_2333[50] = "";
  char test_str_2333_2333[50] = "";
  s21_sprintf(test_str_2333, "%*G", -20, 0.0);
  sprintf(test_str_2333_2333, "%*G", -20, 0.0);
  ck_assert_str_eq(test_str_2333, test_str_2333_2333);
}
END_TEST

START_TEST(sprintf_test_2334) {
  char test_str_2334[50] = "";
  char test_str_2334_2334[50] = "";
  s21_sprintf(test_str_2334, "%*G", -20, 123456789.0);
  sprintf(test_str_2334_2334, "%*G", -20, 123456789.0);
  ck_assert_str_eq(test_str_2334, test_str_2334_2334);
}
END_TEST

START_TEST(sprintf_test_2335) {
  char test_str_2335[50] = "";
  char test_str_2335_2335[50] = "";
  s21_sprintf(test_str_2335, "%*G", -20, 0.123456789);
  sprintf(test_str_2335_2335, "%*G", -20, 0.123456789);
  ck_assert_str_eq(test_str_2335, test_str_2335_2335);
}
END_TEST

START_TEST(sprintf_test_2336) {
  char test_str_2336[50] = "";
  char test_str_2336_2336[50] = "";
  s21_sprintf(test_str_2336, "%*G", -20, -123456789.0);
  sprintf(test_str_2336_2336, "%*G", -20, -123456789.0);
  ck_assert_str_eq(test_str_2336, test_str_2336_2336);
}
END_TEST

START_TEST(sprintf_test_2337) {
  char test_str_2337[50] = "";
  char test_str_2337_2337[50] = "";
  s21_sprintf(test_str_2337, "%*G", -20, -0.123456789);
  sprintf(test_str_2337_2337, "%*G", -20, -0.123456789);
  ck_assert_str_eq(test_str_2337, test_str_2337_2337);
}
END_TEST

START_TEST(sprintf_test_2338) {
  char test_str_2338[50] = "";
  char test_str_2338_2338[50] = "";
  s21_sprintf(test_str_2338, "%*G", -20, 123456789.12345679);
  sprintf(test_str_2338_2338, "%*G", -20, 123456789.12345679);
  ck_assert_str_eq(test_str_2338, test_str_2338_2338);
}
END_TEST

START_TEST(sprintf_test_2339) {
  char test_str_2339[50] = "";
  char test_str_2339_2339[50] = "";
  s21_sprintf(test_str_2339, "%*G", -20, -123456789.12345678);
  sprintf(test_str_2339_2339, "%*G", -20, -123456789.12345678);
  ck_assert_str_eq(test_str_2339, test_str_2339_2339);
}
END_TEST

START_TEST(sprintf_test_2340) {
  char test_str_2340[50] = "";
  char test_str_2340_2340[50] = "";
  s21_sprintf(test_str_2340, "%*G", -20, 1.23e-09);
  sprintf(test_str_2340_2340, "%*G", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2340, test_str_2340_2340);
}
END_TEST

START_TEST(sprintf_test_2341) {
  char test_str_2341[50] = "";
  char test_str_2341_2341[50] = "";
  s21_sprintf(test_str_2341, "%*G", -20, 1.23e-09);
  sprintf(test_str_2341_2341, "%*G", -20, 1.23e-09);
  ck_assert_str_eq(test_str_2341, test_str_2341_2341);
}
END_TEST

START_TEST(sprintf_test_2342) {
  char test_str_2342[50] = "";
  char test_str_2342_2342[50] = "";
  s21_sprintf(test_str_2342, "%.10e", 0.0);
  sprintf(test_str_2342_2342, "%.10e", 0.0);
  ck_assert_str_eq(test_str_2342, test_str_2342_2342);
}
END_TEST

START_TEST(sprintf_test_2343) {
  char test_str_2343[50] = "";
  char test_str_2343_2343[50] = "";
  s21_sprintf(test_str_2343, "%.10e", 123456789.0);
  sprintf(test_str_2343_2343, "%.10e", 123456789.0);
  ck_assert_str_eq(test_str_2343, test_str_2343_2343);
}
END_TEST

START_TEST(sprintf_test_2344) {
  char test_str_2344[50] = "";
  char test_str_2344_2344[50] = "";
  s21_sprintf(test_str_2344, "%.10e", 0.123456789);
  sprintf(test_str_2344_2344, "%.10e", 0.123456789);
  ck_assert_str_eq(test_str_2344, test_str_2344_2344);
}
END_TEST

START_TEST(sprintf_test_2345) {
  char test_str_2345[50] = "";
  char test_str_2345_2345[50] = "";
  s21_sprintf(test_str_2345, "%.10e", -123456789.0);
  sprintf(test_str_2345_2345, "%.10e", -123456789.0);
  ck_assert_str_eq(test_str_2345, test_str_2345_2345);
}
END_TEST

START_TEST(sprintf_test_2346) {
  char test_str_2346[50] = "";
  char test_str_2346_2346[50] = "";
  s21_sprintf(test_str_2346, "%.10e", -0.123456789);
  sprintf(test_str_2346_2346, "%.10e", -0.123456789);
  ck_assert_str_eq(test_str_2346, test_str_2346_2346);
}
END_TEST

START_TEST(sprintf_test_2347) {
  char test_str_2347[50] = "";
  char test_str_2347_2347[50] = "";
  s21_sprintf(test_str_2347, "%.10e", 123456789.12345679);
  sprintf(test_str_2347_2347, "%.10e", 123456789.12345679);
  ck_assert_str_eq(test_str_2347, test_str_2347_2347);
}
END_TEST

START_TEST(sprintf_test_2348) {
  char test_str_2348[50] = "";
  char test_str_2348_2348[50] = "";
  s21_sprintf(test_str_2348, "%.10e", -123456789.12345678);
  sprintf(test_str_2348_2348, "%.10e", -123456789.12345678);
  ck_assert_str_eq(test_str_2348, test_str_2348_2348);
}
END_TEST

START_TEST(sprintf_test_2349) {
  char test_str_2349[50] = "";
  char test_str_2349_2349[50] = "";
  s21_sprintf(test_str_2349, "%.10e", 1.23e-09);
  sprintf(test_str_2349_2349, "%.10e", 1.23e-09);
  ck_assert_str_eq(test_str_2349, test_str_2349_2349);
}
END_TEST

START_TEST(sprintf_test_2350) {
  char test_str_2350[50] = "";
  char test_str_2350_2350[50] = "";
  s21_sprintf(test_str_2350, "%.10e", 1.23e-09);
  sprintf(test_str_2350_2350, "%.10e", 1.23e-09);
  ck_assert_str_eq(test_str_2350, test_str_2350_2350);
}
END_TEST

START_TEST(sprintf_test_2351) {
  char test_str_2351[50] = "";
  char test_str_2351_2351[50] = "";
  s21_sprintf(test_str_2351, "%.10E", 0.0);
  sprintf(test_str_2351_2351, "%.10E", 0.0);
  ck_assert_str_eq(test_str_2351, test_str_2351_2351);
}
END_TEST

START_TEST(sprintf_test_2352) {
  char test_str_2352[50] = "";
  char test_str_2352_2352[50] = "";
  s21_sprintf(test_str_2352, "%.10E", 123456789.0);
  sprintf(test_str_2352_2352, "%.10E", 123456789.0);
  ck_assert_str_eq(test_str_2352, test_str_2352_2352);
}
END_TEST

START_TEST(sprintf_test_2353) {
  char test_str_2353[50] = "";
  char test_str_2353_2353[50] = "";
  s21_sprintf(test_str_2353, "%.10E", 0.123456789);
  sprintf(test_str_2353_2353, "%.10E", 0.123456789);
  ck_assert_str_eq(test_str_2353, test_str_2353_2353);
}
END_TEST

START_TEST(sprintf_test_2354) {
  char test_str_2354[50] = "";
  char test_str_2354_2354[50] = "";
  s21_sprintf(test_str_2354, "%.10E", -123456789.0);
  sprintf(test_str_2354_2354, "%.10E", -123456789.0);
  ck_assert_str_eq(test_str_2354, test_str_2354_2354);
}
END_TEST

START_TEST(sprintf_test_2355) {
  char test_str_2355[50] = "";
  char test_str_2355_2355[50] = "";
  s21_sprintf(test_str_2355, "%.10E", -0.123456789);
  sprintf(test_str_2355_2355, "%.10E", -0.123456789);
  ck_assert_str_eq(test_str_2355, test_str_2355_2355);
}
END_TEST

START_TEST(sprintf_test_2356) {
  char test_str_2356[50] = "";
  char test_str_2356_2356[50] = "";
  s21_sprintf(test_str_2356, "%.10E", 123456789.12345679);
  sprintf(test_str_2356_2356, "%.10E", 123456789.12345679);
  ck_assert_str_eq(test_str_2356, test_str_2356_2356);
}
END_TEST

START_TEST(sprintf_test_2357) {
  char test_str_2357[50] = "";
  char test_str_2357_2357[50] = "";
  s21_sprintf(test_str_2357, "%.10E", -123456789.12345678);
  sprintf(test_str_2357_2357, "%.10E", -123456789.12345678);
  ck_assert_str_eq(test_str_2357, test_str_2357_2357);
}
END_TEST

START_TEST(sprintf_test_2358) {
  char test_str_2358[50] = "";
  char test_str_2358_2358[50] = "";
  s21_sprintf(test_str_2358, "%.10E", 1.23e-09);
  sprintf(test_str_2358_2358, "%.10E", 1.23e-09);
  ck_assert_str_eq(test_str_2358, test_str_2358_2358);
}
END_TEST

START_TEST(sprintf_test_2359) {
  char test_str_2359[50] = "";
  char test_str_2359_2359[50] = "";
  s21_sprintf(test_str_2359, "%.10E", 1.23e-09);
  sprintf(test_str_2359_2359, "%.10E", 1.23e-09);
  ck_assert_str_eq(test_str_2359, test_str_2359_2359);
}
END_TEST

START_TEST(sprintf_test_2360) {
  char test_str_2360[50] = "";
  char test_str_2360_2360[50] = "";
  s21_sprintf(test_str_2360, "%.10g", 0.0);
  sprintf(test_str_2360_2360, "%.10g", 0.0);
  ck_assert_str_eq(test_str_2360, test_str_2360_2360);
}
END_TEST

START_TEST(sprintf_test_2361) {
  char test_str_2361[50] = "";
  char test_str_2361_2361[50] = "";
  s21_sprintf(test_str_2361, "%.10g", 123456789.0);
  sprintf(test_str_2361_2361, "%.10g", 123456789.0);
  ck_assert_str_eq(test_str_2361, test_str_2361_2361);
}
END_TEST

START_TEST(sprintf_test_2362) {
  char test_str_2362[50] = "";
  char test_str_2362_2362[50] = "";
  s21_sprintf(test_str_2362, "%.10g", 0.123456789);
  sprintf(test_str_2362_2362, "%.10g", 0.123456789);
  ck_assert_str_eq(test_str_2362, test_str_2362_2362);
}
END_TEST

START_TEST(sprintf_test_2363) {
  char test_str_2363[50] = "";
  char test_str_2363_2363[50] = "";
  s21_sprintf(test_str_2363, "%.10g", -123456789.0);
  sprintf(test_str_2363_2363, "%.10g", -123456789.0);
  ck_assert_str_eq(test_str_2363, test_str_2363_2363);
}
END_TEST

START_TEST(sprintf_test_2364) {
  char test_str_2364[50] = "";
  char test_str_2364_2364[50] = "";
  s21_sprintf(test_str_2364, "%.10g", -0.123456789);
  sprintf(test_str_2364_2364, "%.10g", -0.123456789);
  ck_assert_str_eq(test_str_2364, test_str_2364_2364);
}
END_TEST

START_TEST(sprintf_test_2365) {
  char test_str_2365[50] = "";
  char test_str_2365_2365[50] = "";
  s21_sprintf(test_str_2365, "%.10g", 123456789.12345679);
  sprintf(test_str_2365_2365, "%.10g", 123456789.12345679);
  ck_assert_str_eq(test_str_2365, test_str_2365_2365);
}
END_TEST

START_TEST(sprintf_test_2366) {
  char test_str_2366[50] = "";
  char test_str_2366_2366[50] = "";
  s21_sprintf(test_str_2366, "%.10g", -123456789.12345678);
  sprintf(test_str_2366_2366, "%.10g", -123456789.12345678);
  ck_assert_str_eq(test_str_2366, test_str_2366_2366);
}
END_TEST

START_TEST(sprintf_test_2367) {
  char test_str_2367[50] = "";
  char test_str_2367_2367[50] = "";
  s21_sprintf(test_str_2367, "%.10g", 1.23e-09);
  sprintf(test_str_2367_2367, "%.10g", 1.23e-09);
  ck_assert_str_eq(test_str_2367, test_str_2367_2367);
}
END_TEST

START_TEST(sprintf_test_2368) {
  char test_str_2368[50] = "";
  char test_str_2368_2368[50] = "";
  s21_sprintf(test_str_2368, "%.10g", 1.23e-09);
  sprintf(test_str_2368_2368, "%.10g", 1.23e-09);
  ck_assert_str_eq(test_str_2368, test_str_2368_2368);
}
END_TEST

START_TEST(sprintf_test_2369) {
  char test_str_2369[50] = "";
  char test_str_2369_2369[50] = "";
  s21_sprintf(test_str_2369, "%.10G", 0.0);
  sprintf(test_str_2369_2369, "%.10G", 0.0);
  ck_assert_str_eq(test_str_2369, test_str_2369_2369);
}
END_TEST

START_TEST(sprintf_test_2370) {
  char test_str_2370[50] = "";
  char test_str_2370_2370[50] = "";
  s21_sprintf(test_str_2370, "%.10G", 123456789.0);
  sprintf(test_str_2370_2370, "%.10G", 123456789.0);
  ck_assert_str_eq(test_str_2370, test_str_2370_2370);
}
END_TEST

START_TEST(sprintf_test_2371) {
  char test_str_2371[50] = "";
  char test_str_2371_2371[50] = "";
  s21_sprintf(test_str_2371, "%.10G", 0.123456789);
  sprintf(test_str_2371_2371, "%.10G", 0.123456789);
  ck_assert_str_eq(test_str_2371, test_str_2371_2371);
}
END_TEST

START_TEST(sprintf_test_2372) {
  char test_str_2372[50] = "";
  char test_str_2372_2372[50] = "";
  s21_sprintf(test_str_2372, "%.10G", -123456789.0);
  sprintf(test_str_2372_2372, "%.10G", -123456789.0);
  ck_assert_str_eq(test_str_2372, test_str_2372_2372);
}
END_TEST

START_TEST(sprintf_test_2373) {
  char test_str_2373[50] = "";
  char test_str_2373_2373[50] = "";
  s21_sprintf(test_str_2373, "%.10G", -0.123456789);
  sprintf(test_str_2373_2373, "%.10G", -0.123456789);
  ck_assert_str_eq(test_str_2373, test_str_2373_2373);
}
END_TEST

START_TEST(sprintf_test_2374) {
  char test_str_2374[50] = "";
  char test_str_2374_2374[50] = "";
  s21_sprintf(test_str_2374, "%.10G", 123456789.12345679);
  sprintf(test_str_2374_2374, "%.10G", 123456789.12345679);
  ck_assert_str_eq(test_str_2374, test_str_2374_2374);
}
END_TEST

START_TEST(sprintf_test_2375) {
  char test_str_2375[50] = "";
  char test_str_2375_2375[50] = "";
  s21_sprintf(test_str_2375, "%.10G", -123456789.12345678);
  sprintf(test_str_2375_2375, "%.10G", -123456789.12345678);
  ck_assert_str_eq(test_str_2375, test_str_2375_2375);
}
END_TEST

START_TEST(sprintf_test_2376) {
  char test_str_2376[50] = "";
  char test_str_2376_2376[50] = "";
  s21_sprintf(test_str_2376, "%.10G", 1.23e-09);
  sprintf(test_str_2376_2376, "%.10G", 1.23e-09);
  ck_assert_str_eq(test_str_2376, test_str_2376_2376);
}
END_TEST

START_TEST(sprintf_test_2377) {
  char test_str_2377[50] = "";
  char test_str_2377_2377[50] = "";
  s21_sprintf(test_str_2377, "%.10G", 1.23e-09);
  sprintf(test_str_2377_2377, "%.10G", 1.23e-09);
  ck_assert_str_eq(test_str_2377, test_str_2377_2377);
}
END_TEST

START_TEST(sprintf_test_2378) {
  char test_str_2378[50] = "";
  char test_str_2378_2378[50] = "";
  s21_sprintf(test_str_2378, "%.14e", 0.0);
  sprintf(test_str_2378_2378, "%.14e", 0.0);
  ck_assert_str_eq(test_str_2378, test_str_2378_2378);
}
END_TEST

START_TEST(sprintf_test_2379) {
  char test_str_2379[50] = "";
  char test_str_2379_2379[50] = "";
  s21_sprintf(test_str_2379, "%.14e", 123456789.0);
  sprintf(test_str_2379_2379, "%.14e", 123456789.0);
  ck_assert_str_eq(test_str_2379, test_str_2379_2379);
}
END_TEST

START_TEST(sprintf_test_2380) {
  char test_str_2380[50] = "";
  char test_str_2380_2380[50] = "";
  s21_sprintf(test_str_2380, "%.14e", 0.123456789);
  sprintf(test_str_2380_2380, "%.14e", 0.123456789);
  ck_assert_str_eq(test_str_2380, test_str_2380_2380);
}
END_TEST

START_TEST(sprintf_test_2381) {
  char test_str_2381[50] = "";
  char test_str_2381_2381[50] = "";
  s21_sprintf(test_str_2381, "%.14e", -123456789.0);
  sprintf(test_str_2381_2381, "%.14e", -123456789.0);
  ck_assert_str_eq(test_str_2381, test_str_2381_2381);
}
END_TEST

START_TEST(sprintf_test_2382) {
  char test_str_2382[50] = "";
  char test_str_2382_2382[50] = "";
  s21_sprintf(test_str_2382, "%.14e", -0.123456789);
  sprintf(test_str_2382_2382, "%.14e", -0.123456789);
  ck_assert_str_eq(test_str_2382, test_str_2382_2382);
}
END_TEST

START_TEST(sprintf_test_2383) {
  char test_str_2383[50] = "";
  char test_str_2383_2383[50] = "";
  s21_sprintf(test_str_2383, "%.14e", 123456789.12345679);
  sprintf(test_str_2383_2383, "%.14e", 123456789.12345679);
  ck_assert_str_eq(test_str_2383, test_str_2383_2383);
}
END_TEST

START_TEST(sprintf_test_2384) {
  char test_str_2384[50] = "";
  char test_str_2384_2384[50] = "";
  s21_sprintf(test_str_2384, "%.14e", -123456789.12345678);
  sprintf(test_str_2384_2384, "%.14e", -123456789.12345678);
  ck_assert_str_eq(test_str_2384, test_str_2384_2384);
}
END_TEST

START_TEST(sprintf_test_2385) {
  char test_str_2385[50] = "";
  char test_str_2385_2385[50] = "";
  s21_sprintf(test_str_2385, "%.14e", 1.23e-09);
  sprintf(test_str_2385_2385, "%.14e", 1.23e-09);
  ck_assert_str_eq(test_str_2385, test_str_2385_2385);
}
END_TEST

START_TEST(sprintf_test_2386) {
  char test_str_2386[50] = "";
  char test_str_2386_2386[50] = "";
  s21_sprintf(test_str_2386, "%.14e", 1.23e-09);
  sprintf(test_str_2386_2386, "%.14e", 1.23e-09);
  ck_assert_str_eq(test_str_2386, test_str_2386_2386);
}
END_TEST

START_TEST(sprintf_test_2387) {
  char test_str_2387[50] = "";
  char test_str_2387_2387[50] = "";
  s21_sprintf(test_str_2387, "%.14E", 0.0);
  sprintf(test_str_2387_2387, "%.14E", 0.0);
  ck_assert_str_eq(test_str_2387, test_str_2387_2387);
}
END_TEST

START_TEST(sprintf_test_2388) {
  char test_str_2388[50] = "";
  char test_str_2388_2388[50] = "";
  s21_sprintf(test_str_2388, "%.14E", 123456789.0);
  sprintf(test_str_2388_2388, "%.14E", 123456789.0);
  ck_assert_str_eq(test_str_2388, test_str_2388_2388);
}
END_TEST

START_TEST(sprintf_test_2389) {
  char test_str_2389[50] = "";
  char test_str_2389_2389[50] = "";
  s21_sprintf(test_str_2389, "%.14E", 0.123456789);
  sprintf(test_str_2389_2389, "%.14E", 0.123456789);
  ck_assert_str_eq(test_str_2389, test_str_2389_2389);
}
END_TEST

START_TEST(sprintf_test_2390) {
  char test_str_2390[50] = "";
  char test_str_2390_2390[50] = "";
  s21_sprintf(test_str_2390, "%.14E", -123456789.0);
  sprintf(test_str_2390_2390, "%.14E", -123456789.0);
  ck_assert_str_eq(test_str_2390, test_str_2390_2390);
}
END_TEST

START_TEST(sprintf_test_2391) {
  char test_str_2391[50] = "";
  char test_str_2391_2391[50] = "";
  s21_sprintf(test_str_2391, "%.14E", -0.123456789);
  sprintf(test_str_2391_2391, "%.14E", -0.123456789);
  ck_assert_str_eq(test_str_2391, test_str_2391_2391);
}
END_TEST

START_TEST(sprintf_test_2392) {
  char test_str_2392[50] = "";
  char test_str_2392_2392[50] = "";
  s21_sprintf(test_str_2392, "%.14E", 123456789.12345679);
  sprintf(test_str_2392_2392, "%.14E", 123456789.12345679);
  ck_assert_str_eq(test_str_2392, test_str_2392_2392);
}
END_TEST

START_TEST(sprintf_test_2393) {
  char test_str_2393[50] = "";
  char test_str_2393_2393[50] = "";
  s21_sprintf(test_str_2393, "%.14E", -123456789.12345678);
  sprintf(test_str_2393_2393, "%.14E", -123456789.12345678);
  ck_assert_str_eq(test_str_2393, test_str_2393_2393);
}
END_TEST

START_TEST(sprintf_test_2394) {
  char test_str_2394[50] = "";
  char test_str_2394_2394[50] = "";
  s21_sprintf(test_str_2394, "%.14E", 1.23e-09);
  sprintf(test_str_2394_2394, "%.14E", 1.23e-09);
  ck_assert_str_eq(test_str_2394, test_str_2394_2394);
}
END_TEST

START_TEST(sprintf_test_2395) {
  char test_str_2395[50] = "";
  char test_str_2395_2395[50] = "";
  s21_sprintf(test_str_2395, "%.14E", 1.23e-09);
  sprintf(test_str_2395_2395, "%.14E", 1.23e-09);
  ck_assert_str_eq(test_str_2395, test_str_2395_2395);
}
END_TEST

START_TEST(sprintf_test_2396) {
  char test_str_2396[50] = "";
  char test_str_2396_2396[50] = "";
  s21_sprintf(test_str_2396, "%.14g", 0.0);
  sprintf(test_str_2396_2396, "%.14g", 0.0);
  ck_assert_str_eq(test_str_2396, test_str_2396_2396);
}
END_TEST

START_TEST(sprintf_test_2397) {
  char test_str_2397[50] = "";
  char test_str_2397_2397[50] = "";
  s21_sprintf(test_str_2397, "%.14g", 123456789.0);
  sprintf(test_str_2397_2397, "%.14g", 123456789.0);
  ck_assert_str_eq(test_str_2397, test_str_2397_2397);
}
END_TEST

START_TEST(sprintf_test_2398) {
  char test_str_2398[50] = "";
  char test_str_2398_2398[50] = "";
  s21_sprintf(test_str_2398, "%.14g", 0.123456789);
  sprintf(test_str_2398_2398, "%.14g", 0.123456789);
  ck_assert_str_eq(test_str_2398, test_str_2398_2398);
}
END_TEST

START_TEST(sprintf_test_2399) {
  char test_str_2399[50] = "";
  char test_str_2399_2399[50] = "";
  s21_sprintf(test_str_2399, "%.14g", -123456789.0);
  sprintf(test_str_2399_2399, "%.14g", -123456789.0);
  ck_assert_str_eq(test_str_2399, test_str_2399_2399);
}
END_TEST

START_TEST(sprintf_test_2400) {
  char test_str_2400[50] = "";
  char test_str_2400_2400[50] = "";
  s21_sprintf(test_str_2400, "%.14g", -0.123456789);
  sprintf(test_str_2400_2400, "%.14g", -0.123456789);
  ck_assert_str_eq(test_str_2400, test_str_2400_2400);
}
END_TEST

START_TEST(sprintf_test_2401) {
  char test_str_2401[50] = "";
  char test_str_2401_2401[50] = "";
  s21_sprintf(test_str_2401, "%.14g", 123456789.12345679);
  sprintf(test_str_2401_2401, "%.14g", 123456789.12345679);
  ck_assert_str_eq(test_str_2401, test_str_2401_2401);
}
END_TEST

START_TEST(sprintf_test_2402) {
  char test_str_2402[50] = "";
  char test_str_2402_2402[50] = "";
  s21_sprintf(test_str_2402, "%.14g", -123456789.12345678);
  sprintf(test_str_2402_2402, "%.14g", -123456789.12345678);
  ck_assert_str_eq(test_str_2402, test_str_2402_2402);
}
END_TEST

START_TEST(sprintf_test_2403) {
  char test_str_2403[50] = "";
  char test_str_2403_2403[50] = "";
  s21_sprintf(test_str_2403, "%.14g", 1.23e-09);
  sprintf(test_str_2403_2403, "%.14g", 1.23e-09);
  ck_assert_str_eq(test_str_2403, test_str_2403_2403);
}
END_TEST

START_TEST(sprintf_test_2404) {
  char test_str_2404[50] = "";
  char test_str_2404_2404[50] = "";
  s21_sprintf(test_str_2404, "%.14g", 1.23e-09);
  sprintf(test_str_2404_2404, "%.14g", 1.23e-09);
  ck_assert_str_eq(test_str_2404, test_str_2404_2404);
}
END_TEST

START_TEST(sprintf_test_2405) {
  char test_str_2405[50] = "";
  char test_str_2405_2405[50] = "";
  s21_sprintf(test_str_2405, "%.14G", 0.0);
  sprintf(test_str_2405_2405, "%.14G", 0.0);
  ck_assert_str_eq(test_str_2405, test_str_2405_2405);
}
END_TEST

START_TEST(sprintf_test_2406) {
  char test_str_2406[50] = "";
  char test_str_2406_2406[50] = "";
  s21_sprintf(test_str_2406, "%.14G", 123456789.0);
  sprintf(test_str_2406_2406, "%.14G", 123456789.0);
  ck_assert_str_eq(test_str_2406, test_str_2406_2406);
}
END_TEST

START_TEST(sprintf_test_2407) {
  char test_str_2407[50] = "";
  char test_str_2407_2407[50] = "";
  s21_sprintf(test_str_2407, "%.14G", 0.123456789);
  sprintf(test_str_2407_2407, "%.14G", 0.123456789);
  ck_assert_str_eq(test_str_2407, test_str_2407_2407);
}
END_TEST

START_TEST(sprintf_test_2408) {
  char test_str_2408[50] = "";
  char test_str_2408_2408[50] = "";
  s21_sprintf(test_str_2408, "%.14G", -123456789.0);
  sprintf(test_str_2408_2408, "%.14G", -123456789.0);
  ck_assert_str_eq(test_str_2408, test_str_2408_2408);
}
END_TEST

START_TEST(sprintf_test_2409) {
  char test_str_2409[50] = "";
  char test_str_2409_2409[50] = "";
  s21_sprintf(test_str_2409, "%.14G", -0.123456789);
  sprintf(test_str_2409_2409, "%.14G", -0.123456789);
  ck_assert_str_eq(test_str_2409, test_str_2409_2409);
}
END_TEST

START_TEST(sprintf_test_2410) {
  char test_str_2410[50] = "";
  char test_str_2410_2410[50] = "";
  s21_sprintf(test_str_2410, "%.14G", 123456789.12345679);
  sprintf(test_str_2410_2410, "%.14G", 123456789.12345679);
  ck_assert_str_eq(test_str_2410, test_str_2410_2410);
}
END_TEST

START_TEST(sprintf_test_2411) {
  char test_str_2411[50] = "";
  char test_str_2411_2411[50] = "";
  s21_sprintf(test_str_2411, "%.14G", -123456789.12345678);
  sprintf(test_str_2411_2411, "%.14G", -123456789.12345678);
  ck_assert_str_eq(test_str_2411, test_str_2411_2411);
}
END_TEST

START_TEST(sprintf_test_2412) {
  char test_str_2412[50] = "";
  char test_str_2412_2412[50] = "";
  s21_sprintf(test_str_2412, "%.14G", 1.23e-09);
  sprintf(test_str_2412_2412, "%.14G", 1.23e-09);
  ck_assert_str_eq(test_str_2412, test_str_2412_2412);
}
END_TEST

START_TEST(sprintf_test_2413) {
  char test_str_2413[50] = "";
  char test_str_2413_2413[50] = "";
  s21_sprintf(test_str_2413, "%.14G", 1.23e-09);
  sprintf(test_str_2413_2413, "%.14G", 1.23e-09);
  ck_assert_str_eq(test_str_2413, test_str_2413_2413);
}
END_TEST

START_TEST(sprintf_test_2414) {
  char test_str_2414[50] = "";
  char test_str_2414_2414[50] = "";
  s21_sprintf(test_str_2414, "%.1e", 0.0);
  sprintf(test_str_2414_2414, "%.1e", 0.0);
  ck_assert_str_eq(test_str_2414, test_str_2414_2414);
}
END_TEST

START_TEST(sprintf_test_2415) {
  char test_str_2415[50] = "";
  char test_str_2415_2415[50] = "";
  s21_sprintf(test_str_2415, "%.1e", 123456789.0);
  sprintf(test_str_2415_2415, "%.1e", 123456789.0);
  ck_assert_str_eq(test_str_2415, test_str_2415_2415);
}
END_TEST

START_TEST(sprintf_test_2416) {
  char test_str_2416[50] = "";
  char test_str_2416_2416[50] = "";
  s21_sprintf(test_str_2416, "%.1e", 0.123456789);
  sprintf(test_str_2416_2416, "%.1e", 0.123456789);
  ck_assert_str_eq(test_str_2416, test_str_2416_2416);
}
END_TEST

START_TEST(sprintf_test_2417) {
  char test_str_2417[50] = "";
  char test_str_2417_2417[50] = "";
  s21_sprintf(test_str_2417, "%.1e", -123456789.0);
  sprintf(test_str_2417_2417, "%.1e", -123456789.0);
  ck_assert_str_eq(test_str_2417, test_str_2417_2417);
}
END_TEST

START_TEST(sprintf_test_2418) {
  char test_str_2418[50] = "";
  char test_str_2418_2418[50] = "";
  s21_sprintf(test_str_2418, "%.1e", -0.123456789);
  sprintf(test_str_2418_2418, "%.1e", -0.123456789);
  ck_assert_str_eq(test_str_2418, test_str_2418_2418);
}
END_TEST

START_TEST(sprintf_test_2419) {
  char test_str_2419[50] = "";
  char test_str_2419_2419[50] = "";
  s21_sprintf(test_str_2419, "%.1e", 123456789.12345679);
  sprintf(test_str_2419_2419, "%.1e", 123456789.12345679);
  ck_assert_str_eq(test_str_2419, test_str_2419_2419);
}
END_TEST

START_TEST(sprintf_test_2420) {
  char test_str_2420[50] = "";
  char test_str_2420_2420[50] = "";
  s21_sprintf(test_str_2420, "%.1e", -123456789.12345678);
  sprintf(test_str_2420_2420, "%.1e", -123456789.12345678);
  ck_assert_str_eq(test_str_2420, test_str_2420_2420);
}
END_TEST

START_TEST(sprintf_test_2421) {
  char test_str_2421[50] = "";
  char test_str_2421_2421[50] = "";
  s21_sprintf(test_str_2421, "%.1e", 1.23e-09);
  sprintf(test_str_2421_2421, "%.1e", 1.23e-09);
  ck_assert_str_eq(test_str_2421, test_str_2421_2421);
}
END_TEST

START_TEST(sprintf_test_2422) {
  char test_str_2422[50] = "";
  char test_str_2422_2422[50] = "";
  s21_sprintf(test_str_2422, "%.1e", 1.23e-09);
  sprintf(test_str_2422_2422, "%.1e", 1.23e-09);
  ck_assert_str_eq(test_str_2422, test_str_2422_2422);
}
END_TEST

START_TEST(sprintf_test_2423) {
  char test_str_2423[50] = "";
  char test_str_2423_2423[50] = "";
  s21_sprintf(test_str_2423, "%.1E", 0.0);
  sprintf(test_str_2423_2423, "%.1E", 0.0);
  ck_assert_str_eq(test_str_2423, test_str_2423_2423);
}
END_TEST

START_TEST(sprintf_test_2424) {
  char test_str_2424[50] = "";
  char test_str_2424_2424[50] = "";
  s21_sprintf(test_str_2424, "%.1E", 123456789.0);
  sprintf(test_str_2424_2424, "%.1E", 123456789.0);
  ck_assert_str_eq(test_str_2424, test_str_2424_2424);
}
END_TEST

START_TEST(sprintf_test_2425) {
  char test_str_2425[50] = "";
  char test_str_2425_2425[50] = "";
  s21_sprintf(test_str_2425, "%.1E", 0.123456789);
  sprintf(test_str_2425_2425, "%.1E", 0.123456789);
  ck_assert_str_eq(test_str_2425, test_str_2425_2425);
}
END_TEST

START_TEST(sprintf_test_2426) {
  char test_str_2426[50] = "";
  char test_str_2426_2426[50] = "";
  s21_sprintf(test_str_2426, "%.1E", -123456789.0);
  sprintf(test_str_2426_2426, "%.1E", -123456789.0);
  ck_assert_str_eq(test_str_2426, test_str_2426_2426);
}
END_TEST

START_TEST(sprintf_test_2427) {
  char test_str_2427[50] = "";
  char test_str_2427_2427[50] = "";
  s21_sprintf(test_str_2427, "%.1E", -0.123456789);
  sprintf(test_str_2427_2427, "%.1E", -0.123456789);
  ck_assert_str_eq(test_str_2427, test_str_2427_2427);
}
END_TEST

START_TEST(sprintf_test_2428) {
  char test_str_2428[50] = "";
  char test_str_2428_2428[50] = "";
  s21_sprintf(test_str_2428, "%.1E", 123456789.12345679);
  sprintf(test_str_2428_2428, "%.1E", 123456789.12345679);
  ck_assert_str_eq(test_str_2428, test_str_2428_2428);
}
END_TEST

START_TEST(sprintf_test_2429) {
  char test_str_2429[50] = "";
  char test_str_2429_2429[50] = "";
  s21_sprintf(test_str_2429, "%.1E", -123456789.12345678);
  sprintf(test_str_2429_2429, "%.1E", -123456789.12345678);
  ck_assert_str_eq(test_str_2429, test_str_2429_2429);
}
END_TEST

START_TEST(sprintf_test_2430) {
  char test_str_2430[50] = "";
  char test_str_2430_2430[50] = "";
  s21_sprintf(test_str_2430, "%.1E", 1.23e-09);
  sprintf(test_str_2430_2430, "%.1E", 1.23e-09);
  ck_assert_str_eq(test_str_2430, test_str_2430_2430);
}
END_TEST

START_TEST(sprintf_test_2431) {
  char test_str_2431[50] = "";
  char test_str_2431_2431[50] = "";
  s21_sprintf(test_str_2431, "%.1E", 1.23e-09);
  sprintf(test_str_2431_2431, "%.1E", 1.23e-09);
  ck_assert_str_eq(test_str_2431, test_str_2431_2431);
}
END_TEST

START_TEST(sprintf_test_2432) {
  char test_str_2432[50] = "";
  char test_str_2432_2432[50] = "";
  s21_sprintf(test_str_2432, "%.1g", 0.0);
  sprintf(test_str_2432_2432, "%.1g", 0.0);
  ck_assert_str_eq(test_str_2432, test_str_2432_2432);
}
END_TEST

START_TEST(sprintf_test_2433) {
  char test_str_2433[50] = "";
  char test_str_2433_2433[50] = "";
  s21_sprintf(test_str_2433, "%.1g", 123456789.0);
  sprintf(test_str_2433_2433, "%.1g", 123456789.0);
  ck_assert_str_eq(test_str_2433, test_str_2433_2433);
}
END_TEST

START_TEST(sprintf_test_2434) {
  char test_str_2434[50] = "";
  char test_str_2434_2434[50] = "";
  s21_sprintf(test_str_2434, "%.1g", 0.123456789);
  sprintf(test_str_2434_2434, "%.1g", 0.123456789);
  ck_assert_str_eq(test_str_2434, test_str_2434_2434);
}
END_TEST

START_TEST(sprintf_test_2435) {
  char test_str_2435[50] = "";
  char test_str_2435_2435[50] = "";
  s21_sprintf(test_str_2435, "%.1g", -123456789.0);
  sprintf(test_str_2435_2435, "%.1g", -123456789.0);
  ck_assert_str_eq(test_str_2435, test_str_2435_2435);
}
END_TEST

START_TEST(sprintf_test_2436) {
  char test_str_2436[50] = "";
  char test_str_2436_2436[50] = "";
  s21_sprintf(test_str_2436, "%.1g", -0.123456789);
  sprintf(test_str_2436_2436, "%.1g", -0.123456789);
  ck_assert_str_eq(test_str_2436, test_str_2436_2436);
}
END_TEST

START_TEST(sprintf_test_2437) {
  char test_str_2437[50] = "";
  char test_str_2437_2437[50] = "";
  s21_sprintf(test_str_2437, "%.1g", 123456789.12345679);
  sprintf(test_str_2437_2437, "%.1g", 123456789.12345679);
  ck_assert_str_eq(test_str_2437, test_str_2437_2437);
}
END_TEST

START_TEST(sprintf_test_2438) {
  char test_str_2438[50] = "";
  char test_str_2438_2438[50] = "";
  s21_sprintf(test_str_2438, "%.1g", -123456789.12345678);
  sprintf(test_str_2438_2438, "%.1g", -123456789.12345678);
  ck_assert_str_eq(test_str_2438, test_str_2438_2438);
}
END_TEST

START_TEST(sprintf_test_2439) {
  char test_str_2439[50] = "";
  char test_str_2439_2439[50] = "";
  s21_sprintf(test_str_2439, "%.1g", 1.23e-09);
  sprintf(test_str_2439_2439, "%.1g", 1.23e-09);
  ck_assert_str_eq(test_str_2439, test_str_2439_2439);
}
END_TEST

START_TEST(sprintf_test_2440) {
  char test_str_2440[50] = "";
  char test_str_2440_2440[50] = "";
  s21_sprintf(test_str_2440, "%.1g", 1.23e-09);
  sprintf(test_str_2440_2440, "%.1g", 1.23e-09);
  ck_assert_str_eq(test_str_2440, test_str_2440_2440);
}
END_TEST

START_TEST(sprintf_test_2441) {
  char test_str_2441[50] = "";
  char test_str_2441_2441[50] = "";
  s21_sprintf(test_str_2441, "%.1G", 0.0);
  sprintf(test_str_2441_2441, "%.1G", 0.0);
  ck_assert_str_eq(test_str_2441, test_str_2441_2441);
}
END_TEST

START_TEST(sprintf_test_2442) {
  char test_str_2442[50] = "";
  char test_str_2442_2442[50] = "";
  s21_sprintf(test_str_2442, "%.1G", 123456789.0);
  sprintf(test_str_2442_2442, "%.1G", 123456789.0);
  ck_assert_str_eq(test_str_2442, test_str_2442_2442);
}
END_TEST

START_TEST(sprintf_test_2443) {
  char test_str_2443[50] = "";
  char test_str_2443_2443[50] = "";
  s21_sprintf(test_str_2443, "%.1G", 0.123456789);
  sprintf(test_str_2443_2443, "%.1G", 0.123456789);
  ck_assert_str_eq(test_str_2443, test_str_2443_2443);
}
END_TEST

START_TEST(sprintf_test_2444) {
  char test_str_2444[50] = "";
  char test_str_2444_2444[50] = "";
  s21_sprintf(test_str_2444, "%.1G", -123456789.0);
  sprintf(test_str_2444_2444, "%.1G", -123456789.0);
  ck_assert_str_eq(test_str_2444, test_str_2444_2444);
}
END_TEST

START_TEST(sprintf_test_2445) {
  char test_str_2445[50] = "";
  char test_str_2445_2445[50] = "";
  s21_sprintf(test_str_2445, "%.1G", -0.123456789);
  sprintf(test_str_2445_2445, "%.1G", -0.123456789);
  ck_assert_str_eq(test_str_2445, test_str_2445_2445);
}
END_TEST

START_TEST(sprintf_test_2446) {
  char test_str_2446[50] = "";
  char test_str_2446_2446[50] = "";
  s21_sprintf(test_str_2446, "%.1G", 123456789.12345679);
  sprintf(test_str_2446_2446, "%.1G", 123456789.12345679);
  ck_assert_str_eq(test_str_2446, test_str_2446_2446);
}
END_TEST

START_TEST(sprintf_test_2447) {
  char test_str_2447[50] = "";
  char test_str_2447_2447[50] = "";
  s21_sprintf(test_str_2447, "%.1G", -123456789.12345678);
  sprintf(test_str_2447_2447, "%.1G", -123456789.12345678);
  ck_assert_str_eq(test_str_2447, test_str_2447_2447);
}
END_TEST

START_TEST(sprintf_test_2448) {
  char test_str_2448[50] = "";
  char test_str_2448_2448[50] = "";
  s21_sprintf(test_str_2448, "%.1G", 1.23e-09);
  sprintf(test_str_2448_2448, "%.1G", 1.23e-09);
  ck_assert_str_eq(test_str_2448, test_str_2448_2448);
}
END_TEST

START_TEST(sprintf_test_2449) {
  char test_str_2449[50] = "";
  char test_str_2449_2449[50] = "";
  s21_sprintf(test_str_2449, "%.1G", 1.23e-09);
  sprintf(test_str_2449_2449, "%.1G", 1.23e-09);
  ck_assert_str_eq(test_str_2449, test_str_2449_2449);
}
END_TEST

START_TEST(sprintf_test_2450) {
  char test_str_2450[50] = "";
  char test_str_2450_2450[50] = "";
  s21_sprintf(test_str_2450, "%Le", (long double)0.0);
  sprintf(test_str_2450_2450, "%Le", (long double)0.0);
  ck_assert_str_eq(test_str_2450, test_str_2450_2450);
}
END_TEST

START_TEST(sprintf_test_2451) {
  char test_str_2451[50] = "";
  char test_str_2451_2451[50] = "";
  s21_sprintf(test_str_2451, "%Le", (long double)123456789.0);
  sprintf(test_str_2451_2451, "%Le", (long double)123456789.0);
  ck_assert_str_eq(test_str_2451, test_str_2451_2451);
}
END_TEST

START_TEST(sprintf_test_2452) {
  char test_str_2452[50] = "";
  char test_str_2452_2452[50] = "";
  s21_sprintf(test_str_2452, "%Le", (long double)0.123456789);
  sprintf(test_str_2452_2452, "%Le", (long double)0.123456789);
  ck_assert_str_eq(test_str_2452, test_str_2452_2452);
}
END_TEST

START_TEST(sprintf_test_2453) {
  char test_str_2453[50] = "";
  char test_str_2453_2453[50] = "";
  s21_sprintf(test_str_2453, "%Le", (long double)-123456789.0);
  sprintf(test_str_2453_2453, "%Le", (long double)-123456789.0);
  ck_assert_str_eq(test_str_2453, test_str_2453_2453);
}
END_TEST

START_TEST(sprintf_test_2454) {
  char test_str_2454[50] = "";
  char test_str_2454_2454[50] = "";
  s21_sprintf(test_str_2454, "%Le", (long double)-0.123456789);
  sprintf(test_str_2454_2454, "%Le", (long double)-0.123456789);
  ck_assert_str_eq(test_str_2454, test_str_2454_2454);
}
END_TEST

START_TEST(sprintf_test_2455) {
  char test_str_2455[50] = "";
  char test_str_2455_2455[50] = "";
  s21_sprintf(test_str_2455, "%Le", (long double)123456789.12345679);
  sprintf(test_str_2455_2455, "%Le", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_2455, test_str_2455_2455);
}
END_TEST

START_TEST(sprintf_test_2456) {
  char test_str_2456[50] = "";
  char test_str_2456_2456[50] = "";
  s21_sprintf(test_str_2456, "%Le", (long double)-123456789.12345678);
  sprintf(test_str_2456_2456, "%Le", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_2456, test_str_2456_2456);
}
END_TEST

START_TEST(sprintf_test_2457) {
  char test_str_2457[50] = "";
  char test_str_2457_2457[50] = "";
  s21_sprintf(test_str_2457, "%Le", (long double)1.23e-09);
  sprintf(test_str_2457_2457, "%Le", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2457, test_str_2457_2457);
}
END_TEST

START_TEST(sprintf_test_2458) {
  char test_str_2458[50] = "";
  char test_str_2458_2458[50] = "";
  s21_sprintf(test_str_2458, "%Le", (long double)1.23e-09);
  sprintf(test_str_2458_2458, "%Le", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2458, test_str_2458_2458);
}
END_TEST

START_TEST(sprintf_test_2459) {
  char test_str_2459[50] = "";
  char test_str_2459_2459[50] = "";
  s21_sprintf(test_str_2459, "%LE", (long double)0.0);
  sprintf(test_str_2459_2459, "%LE", (long double)0.0);
  ck_assert_str_eq(test_str_2459, test_str_2459_2459);
}
END_TEST

START_TEST(sprintf_test_2460) {
  char test_str_2460[50] = "";
  char test_str_2460_2460[50] = "";
  s21_sprintf(test_str_2460, "%LE", (long double)123456789.0);
  sprintf(test_str_2460_2460, "%LE", (long double)123456789.0);
  ck_assert_str_eq(test_str_2460, test_str_2460_2460);
}
END_TEST

START_TEST(sprintf_test_2461) {
  char test_str_2461[50] = "";
  char test_str_2461_2461[50] = "";
  s21_sprintf(test_str_2461, "%LE", (long double)0.123456789);
  sprintf(test_str_2461_2461, "%LE", (long double)0.123456789);
  ck_assert_str_eq(test_str_2461, test_str_2461_2461);
}
END_TEST

START_TEST(sprintf_test_2462) {
  char test_str_2462[50] = "";
  char test_str_2462_2462[50] = "";
  s21_sprintf(test_str_2462, "%LE", (long double)-123456789.0);
  sprintf(test_str_2462_2462, "%LE", (long double)-123456789.0);
  ck_assert_str_eq(test_str_2462, test_str_2462_2462);
}
END_TEST

START_TEST(sprintf_test_2463) {
  char test_str_2463[50] = "";
  char test_str_2463_2463[50] = "";
  s21_sprintf(test_str_2463, "%LE", (long double)-0.123456789);
  sprintf(test_str_2463_2463, "%LE", (long double)-0.123456789);
  ck_assert_str_eq(test_str_2463, test_str_2463_2463);
}
END_TEST

START_TEST(sprintf_test_2464) {
  char test_str_2464[50] = "";
  char test_str_2464_2464[50] = "";
  s21_sprintf(test_str_2464, "%LE", (long double)123456789.12345679);
  sprintf(test_str_2464_2464, "%LE", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_2464, test_str_2464_2464);
}
END_TEST

START_TEST(sprintf_test_2465) {
  char test_str_2465[50] = "";
  char test_str_2465_2465[50] = "";
  s21_sprintf(test_str_2465, "%LE", (long double)-123456789.12345678);
  sprintf(test_str_2465_2465, "%LE", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_2465, test_str_2465_2465);
}
END_TEST

START_TEST(sprintf_test_2466) {
  char test_str_2466[50] = "";
  char test_str_2466_2466[50] = "";
  s21_sprintf(test_str_2466, "%LE", (long double)1.23e-09);
  sprintf(test_str_2466_2466, "%LE", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2466, test_str_2466_2466);
}
END_TEST

START_TEST(sprintf_test_2467) {
  char test_str_2467[50] = "";
  char test_str_2467_2467[50] = "";
  s21_sprintf(test_str_2467, "%LE", (long double)1.23e-09);
  sprintf(test_str_2467_2467, "%LE", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2467, test_str_2467_2467);
}
END_TEST

START_TEST(sprintf_test_2468) {
  char test_str_2468[50] = "";
  char test_str_2468_2468[50] = "";
  s21_sprintf(test_str_2468, "%Lg", (long double)0.0);
  sprintf(test_str_2468_2468, "%Lg", (long double)0.0);
  ck_assert_str_eq(test_str_2468, test_str_2468_2468);
}
END_TEST

START_TEST(sprintf_test_2469) {
  char test_str_2469[50] = "";
  char test_str_2469_2469[50] = "";
  s21_sprintf(test_str_2469, "%Lg", (long double)123456789.0);
  sprintf(test_str_2469_2469, "%Lg", (long double)123456789.0);
  ck_assert_str_eq(test_str_2469, test_str_2469_2469);
}
END_TEST

START_TEST(sprintf_test_2470) {
  char test_str_2470[50] = "";
  char test_str_2470_2470[50] = "";
  s21_sprintf(test_str_2470, "%Lg", (long double)0.123456789);
  sprintf(test_str_2470_2470, "%Lg", (long double)0.123456789);
  ck_assert_str_eq(test_str_2470, test_str_2470_2470);
}
END_TEST

START_TEST(sprintf_test_2471) {
  char test_str_2471[50] = "";
  char test_str_2471_2471[50] = "";
  s21_sprintf(test_str_2471, "%Lg", (long double)-123456789.0);
  sprintf(test_str_2471_2471, "%Lg", (long double)-123456789.0);
  ck_assert_str_eq(test_str_2471, test_str_2471_2471);
}
END_TEST

START_TEST(sprintf_test_2472) {
  char test_str_2472[50] = "";
  char test_str_2472_2472[50] = "";
  s21_sprintf(test_str_2472, "%Lg", (long double)-0.123456789);
  sprintf(test_str_2472_2472, "%Lg", (long double)-0.123456789);
  ck_assert_str_eq(test_str_2472, test_str_2472_2472);
}
END_TEST

START_TEST(sprintf_test_2473) {
  char test_str_2473[50] = "";
  char test_str_2473_2473[50] = "";
  s21_sprintf(test_str_2473, "%Lg", (long double)123456789.12345679);
  sprintf(test_str_2473_2473, "%Lg", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_2473, test_str_2473_2473);
}
END_TEST

START_TEST(sprintf_test_2474) {
  char test_str_2474[50] = "";
  char test_str_2474_2474[50] = "";
  s21_sprintf(test_str_2474, "%Lg", (long double)-123456789.12345678);
  sprintf(test_str_2474_2474, "%Lg", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_2474, test_str_2474_2474);
}
END_TEST

START_TEST(sprintf_test_2475) {
  char test_str_2475[50] = "";
  char test_str_2475_2475[50] = "";
  s21_sprintf(test_str_2475, "%Lg", (long double)1.23e-09);
  sprintf(test_str_2475_2475, "%Lg", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2475, test_str_2475_2475);
}
END_TEST

START_TEST(sprintf_test_2476) {
  char test_str_2476[50] = "";
  char test_str_2476_2476[50] = "";
  s21_sprintf(test_str_2476, "%Lg", (long double)1.23e-09);
  sprintf(test_str_2476_2476, "%Lg", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2476, test_str_2476_2476);
}
END_TEST

START_TEST(sprintf_test_2477) {
  char test_str_2477[50] = "";
  char test_str_2477_2477[50] = "";
  s21_sprintf(test_str_2477, "%LG", (long double)0.0);
  sprintf(test_str_2477_2477, "%LG", (long double)0.0);
  ck_assert_str_eq(test_str_2477, test_str_2477_2477);
}
END_TEST

START_TEST(sprintf_test_2478) {
  char test_str_2478[50] = "";
  char test_str_2478_2478[50] = "";
  s21_sprintf(test_str_2478, "%LG", (long double)123456789.0);
  sprintf(test_str_2478_2478, "%LG", (long double)123456789.0);
  ck_assert_str_eq(test_str_2478, test_str_2478_2478);
}
END_TEST

START_TEST(sprintf_test_2479) {
  char test_str_2479[50] = "";
  char test_str_2479_2479[50] = "";
  s21_sprintf(test_str_2479, "%LG", (long double)0.123456789);
  sprintf(test_str_2479_2479, "%LG", (long double)0.123456789);
  ck_assert_str_eq(test_str_2479, test_str_2479_2479);
}
END_TEST

START_TEST(sprintf_test_2480) {
  char test_str_2480[50] = "";
  char test_str_2480_2480[50] = "";
  s21_sprintf(test_str_2480, "%LG", (long double)-123456789.0);
  sprintf(test_str_2480_2480, "%LG", (long double)-123456789.0);
  ck_assert_str_eq(test_str_2480, test_str_2480_2480);
}
END_TEST

START_TEST(sprintf_test_2481) {
  char test_str_2481[50] = "";
  char test_str_2481_2481[50] = "";
  s21_sprintf(test_str_2481, "%LG", (long double)-0.123456789);
  sprintf(test_str_2481_2481, "%LG", (long double)-0.123456789);
  ck_assert_str_eq(test_str_2481, test_str_2481_2481);
}
END_TEST

START_TEST(sprintf_test_2482) {
  char test_str_2482[50] = "";
  char test_str_2482_2482[50] = "";
  s21_sprintf(test_str_2482, "%LG", (long double)123456789.12345679);
  sprintf(test_str_2482_2482, "%LG", (long double)123456789.12345679);
  ck_assert_str_eq(test_str_2482, test_str_2482_2482);
}
END_TEST

START_TEST(sprintf_test_2483) {
  char test_str_2483[50] = "";
  char test_str_2483_2483[50] = "";
  s21_sprintf(test_str_2483, "%LG", (long double)-123456789.12345678);
  sprintf(test_str_2483_2483, "%LG", (long double)-123456789.12345678);
  ck_assert_str_eq(test_str_2483, test_str_2483_2483);
}
END_TEST

START_TEST(sprintf_test_2484) {
  char test_str_2484[50] = "";
  char test_str_2484_2484[50] = "";
  s21_sprintf(test_str_2484, "%LG", (long double)1.23e-09);
  sprintf(test_str_2484_2484, "%LG", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2484, test_str_2484_2484);
}
END_TEST

START_TEST(sprintf_test_2485) {
  char test_str_2485[50] = "";
  char test_str_2485_2485[50] = "";
  s21_sprintf(test_str_2485, "%LG", (long double)1.23e-09);
  sprintf(test_str_2485_2485, "%LG", (long double)1.23e-09);
  ck_assert_str_eq(test_str_2485, test_str_2485_2485);
}
END_TEST

START_TEST(
    strtok_1) {  //данный код выполняет тестирование функций strtok и
                 // s21_strtok,
                 //   проверяя их результаты на равенство ожидаемому значению
                 //   NULL. Если все тесты успешно проходят, то можно сделать
                 //   вывод о корректности работы этих функций
  char *str_ = s21_strtok(
      "UwU", "UwU");  //объявляется указатель str_ на символ и вызывается
                      //   пользовательская функция s21_strtok, передавая ей две
                      //   аргумента: "UwU" в качестве строки для разделения и
                      //   "UwU" в качестве разделителя. Результат выполнения
                      //  функции присваивается переменной str_
  char *str = strtok("UwU", "UwU");
  ck_assert_ptr_null(
      str);  //используется макрос ck_assert_ptr_null для проверки того, что
             //   указатель str равен NULL. Если условие истинно, то тест
             //   считается успешным, иначе тест провален. В данном случае, мы
             //   ожидаем, что результат вызова функции strtok будет равен NULL,
             //   то есть не будет найдено ни одного токена.
  ck_assert_ptr_null(str_);
}
END_TEST

START_TEST(strtok_2) {
  char *str_ = s21_strtok("1", "\0");
  char *str = strtok("1", "\0");
  ck_assert_str_eq(str_, str);
}
END_TEST

START_TEST(strtok_3) {
  char *str_ = s21_strtok("", "");
  char *str = strtok("", "");
  ck_assert_ptr_null(str);
  ck_assert_ptr_null(str_);
}
END_TEST

START_TEST(strtok_4) {
  char *str_ = s21_strtok(s21_NULL, "/");
  char *str = strtok(s21_NULL, "/");
  ck_assert_ptr_null(str);
  ck_assert_ptr_null(str_);
}
END_TEST

START_TEST(strtok_5) {
  char *str_ = s21_strtok("aaabbb", ";,");
  char *str = strtok("aaabbb", ";,");
  ck_assert_str_eq(str_, str);
}
END_TEST

START_TEST(strtok_6) {
  char str_[] = "- OMAE WA MOU SHINDEIRU. - NANI?!? ";
  char *str_1 = "?!?";
  char *res = s21_strtok(str_, str_1);
  char *res_ = strtok(str_, str_1);
  ck_assert_str_eq(res, res_);
}
END_TEST

START_TEST(strtok_8) {
  char str_[] = "Initialize";
  char *res = strtok(str_, "i");
  char *res_ = s21_strtok(str_, "i");
  ck_assert_str_eq(res, res_);
}
END_TEST

START_TEST(strtok_9) {
  char str_[] = "весело \0 -----нет";
  char *res = strtok(str_, "нет");
  char *res_ = s21_strtok(str_, "нет");
  ck_assert_str_eq(res, res_);
}
END_TEST

START_TEST(strtok_10) {
  char str_[] = "Мы_молодцы (яМолодец)";
  char *res = strtok(str_, " ");
  char *res_ = s21_strtok(str_, " ");
  ck_assert_ptr_eq(res, res_);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core1");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  Suite *s1_1 = suite_create("Core2");
  TCase *tc1_1_1 = tcase_create("Core");
  SRunner *sr_1 = srunner_create(s1_1);
  int nf_1;

  suite_add_tcase(s1, tc1_1);
  suite_add_tcase(s1_1, tc1_1_1);

  Suite *ne_kak_u_vseh = suite_create("Core3");
  TCase *otli4noe_ot_vashego = tcase_create("Core");
  SRunner *krasivoe = srunner_create(ne_kak_u_vseh);
  int otli4noe_nf;

  suite_add_tcase(
      ne_kak_u_vseh,
      otli4noe_ot_vashego); /*добавляют тестовый сценарий otli4noe_ot_vashego в
                               тестовый набор ne_kak_u_vseh*/
  // STRTOK

  {
    tcase_add_test(otli4noe_ot_vashego, strtok_1);
    tcase_add_test(otli4noe_ot_vashego, strtok_2);
    tcase_add_test(otli4noe_ot_vashego, strtok_3);
    tcase_add_test(otli4noe_ot_vashego, strtok_4);
    tcase_add_test(otli4noe_ot_vashego, strtok_5);
    tcase_add_test(otli4noe_ot_vashego, strtok_6);

    tcase_add_test(otli4noe_ot_vashego, strtok_8);
    tcase_add_test(otli4noe_ot_vashego, strtok_9);
    tcase_add_test(otli4noe_ot_vashego, strtok_10);
  }

  // SSCANF
  {

  }  // TRIM
  {
    tcase_add_test(tc1_1, s21_trim_test_1);
    tcase_add_test(tc1_1, s21_trim_test_2);
    tcase_add_test(tc1_1, s21_trim_test_3);
    tcase_add_test(tc1_1, s21_trim_test_4);
    tcase_add_test(tc1_1, s21_trim_test_5);
    tcase_add_test(tc1_1, s21_trim_test_6);
    tcase_add_test(tc1_1, s21_trim_test_7);
    tcase_add_test(tc1_1, s21_trim_test_8);
    tcase_add_test(tc1_1, s21_trim_test_9);
    tcase_add_test(tc1_1, s21_trim_test_10);
    tcase_add_test(tc1_1, s21_trim_test_11);
    tcase_add_test(tc1_1, s21_trim_test_12);
  }
  tcase_add_test(tc1_1, s21_to_lower_test_1);
  tcase_add_test(tc1_1, s21_to_upper_test_1);
  tcase_add_test(tc1_1, s21_to_lower_test_2);
  tcase_add_test(tc1_1, s21_to_upper_test_2);
  tcase_add_test(tc1_1, s21_to_lower_test_3);
  tcase_add_test(tc1_1, s21_to_upper_test_3);
  tcase_add_test(tc1_1, s21_to_lower_test_4);
  tcase_add_test(tc1_1, s21_to_upper_test_4);
  tcase_add_test(tc1_1, s21_to_lower_test_5);
  tcase_add_test(tc1_1, s21_to_upper_test_5);
  tcase_add_test(tc1_1, s21_to_lower_test_6);
  tcase_add_test(tc1_1, s21_to_upper_test_6);
  tcase_add_test(tc1_1, s21_to_lower_test_7);
  tcase_add_test(tc1_1, s21_to_upper_test_7);
  tcase_add_test(tc1_1, s21_to_lower_test_8);
  tcase_add_test(tc1_1, s21_to_upper_test_8);
  tcase_add_test(tc1_1, s21_to_lower_test_9);
  tcase_add_test(tc1_1, s21_to_upper_test_9);

  tcase_add_test(tc1_1, s21_insert_test_1);
  tcase_add_test(tc1_1, s21_insert_test_2);
  tcase_add_test(tc1_1, s21_insert_test_3);
  tcase_add_test(tc1_1, s21_insert_test_4);
  tcase_add_test(tc1_1, s21_insert_test_5);
  tcase_add_test(tc1_1, s21_insert_test_6);
  tcase_add_test(tc1_1, s21_insert_test_7);

  tcase_add_test(tc1_1_1, memchr_1);
  tcase_add_test(tc1_1_1, memchr_2);
  tcase_add_test(tc1_1_1, memchr_3);
  tcase_add_test(tc1_1_1, memchr_4);
  tcase_add_test(tc1_1_1, memchr_5);
  tcase_add_test(tc1_1_1, memchr_6);
  tcase_add_test(tc1_1_1, memchr_7);
  tcase_add_test(tc1_1_1, memchr_8);
  tcase_add_test(tc1_1_1, memchr_9);
  tcase_add_test(tc1_1_1, memchr_10);
  tcase_add_test(tc1_1_1, memcmp_1);
  tcase_add_test(tc1_1_1, memcmp_2);
  tcase_add_test(tc1_1_1, memcmp_3);
  tcase_add_test(tc1_1_1, memcmp_4);
  tcase_add_test(tc1_1_1, memcmp_5);
  tcase_add_test(tc1_1_1, memcmp_6);
  tcase_add_test(tc1_1_1, memcmp_7);
  tcase_add_test(tc1_1_1, memcmp_9);
  tcase_add_test(tc1_1_1, memcmp_10);
  tcase_add_test(tc1_1_1, memcpy_1);
  tcase_add_test(tc1_1_1, memcpy_2);
  tcase_add_test(tc1_1_1, memcpy_3);
  tcase_add_test(tc1_1_1, memcpy_4);
  tcase_add_test(tc1_1_1, memcpy_5);
  tcase_add_test(tc1_1_1, memcpy_6);
  tcase_add_test(tc1_1_1, memcpy_7);
  tcase_add_test(tc1_1_1, memcpy_8);
  tcase_add_test(tc1_1_1, memset_1);
  tcase_add_test(tc1_1_1, memset_2);
  tcase_add_test(tc1_1_1, memset_3);
  tcase_add_test(tc1_1_1, memset_4);
  tcase_add_test(tc1_1_1, memset_5);
  tcase_add_test(tc1_1_1, memset_6);
  tcase_add_test(tc1_1_1, memset_7);
  tcase_add_test(tc1_1_1, memset_8);

  tcase_add_test(tc1_1_1, strncat_1);
  tcase_add_test(tc1_1_1, strncat_2);
  tcase_add_test(tc1_1_1, strncat_3);
  tcase_add_test(tc1_1_1, strncat_4);
  tcase_add_test(tc1_1_1, strncat_5);
  tcase_add_test(tc1_1_1, strchr_1);
  tcase_add_test(tc1_1_1, strchr_2);
  tcase_add_test(tc1_1_1, strchr_3);
  tcase_add_test(tc1_1_1, strchr_4);
  tcase_add_test(tc1_1_1, strchr_5);
  tcase_add_test(tc1_1_1, strchr_6);
  tcase_add_test(tc1_1_1, strchr_7);
  tcase_add_test(tc1_1_1, strchr_8);
  tcase_add_test(tc1_1_1, strchr_9);
  tcase_add_test(tc1_1_1, strchr_10);
  tcase_add_test(tc1_1_1, strncmp_1);
  tcase_add_test(tc1_1_1, strncmp_2);
  tcase_add_test(tc1_1_1, strncmp_3);
  tcase_add_test(tc1_1_1, strncmp_4);
  tcase_add_test(tc1_1_1, strncmp_5);
  tcase_add_test(tc1_1_1, strncmp_6);
  tcase_add_test(tc1_1_1, strncmp_7);
  tcase_add_test(tc1_1_1, strncpy_1);
  tcase_add_test(tc1_1_1, strncpy_2);
  tcase_add_test(tc1_1_1, strncpy_3);
  tcase_add_test(tc1_1_1, strncpy_4);
  tcase_add_test(tc1_1_1, strncpy_5);
  tcase_add_test(tc1_1_1, strncpy_6);
  tcase_add_test(tc1_1_1, strncpy_7);

  tcase_add_test(tc1_1_1, strcspn_1);
  tcase_add_test(tc1_1_1, strcspn_2);
  tcase_add_test(tc1_1_1, strcspn_3);
  tcase_add_test(tc1_1_1, strcspn_4);
  tcase_add_test(tc1_1_1, strcspn_5);
  tcase_add_test(tc1_1_1, strcspn_6);
  tcase_add_test(tc1_1_1, strcspn_7);

  tcase_add_test(tc1_1_1, strerror_1);
  tcase_add_test(tc1_1_1, strerror_2);
  tcase_add_test(tc1_1_1, strerror_3);
  tcase_add_test(tc1_1_1, strerror_4);
  tcase_add_test(tc1_1_1, strerror_5);
  tcase_add_test(tc1_1_1, strerror_6);
  tcase_add_test(tc1_1_1, strerror_7);
  tcase_add_test(tc1_1_1, strerror_8);
  tcase_add_test(tc1_1_1, strerror_9);
  tcase_add_test(tc1_1_1, strerror_10);
  tcase_add_test(tc1_1_1, strlen_1);
  tcase_add_test(tc1_1_1, strlen_2);
  tcase_add_test(tc1_1_1, strlen_3);
  tcase_add_test(tc1_1_1, strlen_4);
  tcase_add_test(tc1_1_1, strlen_5);
  tcase_add_test(tc1_1_1, strlen_6);
  tcase_add_test(tc1_1_1, strpbrk_1);
  tcase_add_test(tc1_1_1, strpbrk_2);
  tcase_add_test(tc1_1_1, strpbrk_3);
  tcase_add_test(tc1_1_1, strpbrk_4);
  tcase_add_test(tc1_1_1, strpbrk_5);
  tcase_add_test(tc1_1_1, strpbrk_6);
  tcase_add_test(tc1_1_1, strpbrk_7);

  tcase_add_test(tc1_1_1, strrchr_1);
  tcase_add_test(tc1_1_1, strrchr_2);
  tcase_add_test(tc1_1_1, strrchr_3);
  tcase_add_test(tc1_1_1, strrchr_4);
  tcase_add_test(tc1_1_1, strrchr_5);
  tcase_add_test(tc1_1_1, strrchr_6);
  tcase_add_test(tc1_1_1, strrchr_7);
  tcase_add_test(tc1_1_1, strrchr_8);

  tcase_add_test(tc1_1_1, strstr_1);
  tcase_add_test(tc1_1_1, strstr_2);
  tcase_add_test(tc1_1_1, strstr_3);
  tcase_add_test(tc1_1_1, strstr_4);
  tcase_add_test(tc1_1_1, strstr_5);
  tcase_add_test(tc1_1_1, strstr_6);
  // SPRINTF
  {
    tcase_add_test(tc1_1, sprintf_test_1);
    tcase_add_test(tc1_1, sprintf_test_2);
    tcase_add_test(tc1_1, sprintf_test_3);
    tcase_add_test(tc1_1, sprintf_test_4);
    tcase_add_test(tc1_1, sprintf_test_5);
    tcase_add_test(tc1_1, sprintf_test_6);
    tcase_add_test(tc1_1, sprintf_test_7);
    tcase_add_test(tc1_1, sprintf_test_8);
    tcase_add_test(tc1_1, sprintf_test_9);
    tcase_add_test(tc1_1, sprintf_test_10);
    tcase_add_test(tc1_1, sprintf_test_11);
    tcase_add_test(tc1_1, sprintf_test_12);
    tcase_add_test(tc1_1, sprintf_test_13);
    tcase_add_test(tc1_1, sprintf_test_14);
    tcase_add_test(tc1_1, sprintf_test_15);
    tcase_add_test(tc1_1, sprintf_test_16);
    tcase_add_test(tc1_1, sprintf_test_17);
    tcase_add_test(tc1_1, sprintf_test_18);
    tcase_add_test(tc1_1, sprintf_test_19);
    tcase_add_test(tc1_1, sprintf_test_20);
    tcase_add_test(tc1_1, sprintf_test_21);
    tcase_add_test(tc1_1, sprintf_test_22);
    tcase_add_test(tc1_1, sprintf_test_23);
    tcase_add_test(tc1_1, sprintf_test_24);
    tcase_add_test(tc1_1, sprintf_test_25);
    tcase_add_test(tc1_1, sprintf_test_26);
    tcase_add_test(tc1_1, sprintf_test_27);
    tcase_add_test(tc1_1, sprintf_test_28);
    tcase_add_test(tc1_1, sprintf_test_29);
    tcase_add_test(tc1_1, sprintf_test_30);
    tcase_add_test(tc1_1, sprintf_test_31);
    tcase_add_test(tc1_1, sprintf_test_32);
    tcase_add_test(tc1_1, sprintf_test_33);
    tcase_add_test(tc1_1, sprintf_test_34);
    tcase_add_test(tc1_1, sprintf_test_35);
    tcase_add_test(tc1_1, sprintf_test_36);
    tcase_add_test(tc1_1, sprintf_test_37);
    tcase_add_test(tc1_1, sprintf_test_38);
    tcase_add_test(tc1_1, sprintf_test_39);
    tcase_add_test(tc1_1, sprintf_test_40);
    tcase_add_test(tc1_1, sprintf_test_41);
    tcase_add_test(tc1_1, sprintf_test_42);
    tcase_add_test(tc1_1, sprintf_test_43);
    tcase_add_test(tc1_1, sprintf_test_44);
    tcase_add_test(tc1_1, sprintf_test_45);
    tcase_add_test(tc1_1, sprintf_test_46);
    tcase_add_test(tc1_1, sprintf_test_47);
    tcase_add_test(tc1_1, sprintf_test_48);
    tcase_add_test(tc1_1, sprintf_test_49);
    tcase_add_test(tc1_1, sprintf_test_50);
    tcase_add_test(tc1_1, sprintf_test_51);
    tcase_add_test(tc1_1, sprintf_test_52);
    tcase_add_test(tc1_1, sprintf_test_53);
    tcase_add_test(tc1_1, sprintf_test_54);
    tcase_add_test(tc1_1, sprintf_test_55);
    tcase_add_test(tc1_1, sprintf_test_56);
    tcase_add_test(tc1_1, sprintf_test_57);
    tcase_add_test(tc1_1, sprintf_test_58);
    tcase_add_test(tc1_1, sprintf_test_59);
    tcase_add_test(tc1_1, sprintf_test_60);
    tcase_add_test(tc1_1, sprintf_test_61);
    tcase_add_test(tc1_1, sprintf_test_62);
    tcase_add_test(tc1_1, sprintf_test_63);
    tcase_add_test(tc1_1, sprintf_test_64);
    tcase_add_test(tc1_1, sprintf_test_65);
    tcase_add_test(tc1_1, sprintf_test_66);
    tcase_add_test(tc1_1, sprintf_test_67);
    tcase_add_test(tc1_1, sprintf_test_68);
    tcase_add_test(tc1_1, sprintf_test_69);
    tcase_add_test(tc1_1, sprintf_test_70);
    tcase_add_test(tc1_1, sprintf_test_71);
    tcase_add_test(tc1_1, sprintf_test_72);
    tcase_add_test(tc1_1, sprintf_test_73);
    tcase_add_test(tc1_1, sprintf_test_74);
    tcase_add_test(tc1_1, sprintf_test_75);
    tcase_add_test(tc1_1, sprintf_test_76);
    tcase_add_test(tc1_1, sprintf_test_77);
    tcase_add_test(tc1_1, sprintf_test_78);
    tcase_add_test(tc1_1, sprintf_test_79);
    tcase_add_test(tc1_1, sprintf_test_80);
    tcase_add_test(tc1_1, sprintf_test_81);
    tcase_add_test(tc1_1, sprintf_test_82);
    tcase_add_test(tc1_1, sprintf_test_83);
    tcase_add_test(tc1_1, sprintf_test_84);
    tcase_add_test(tc1_1, sprintf_test_85);
    tcase_add_test(tc1_1, sprintf_test_86);
    tcase_add_test(tc1_1, sprintf_test_87);
    tcase_add_test(tc1_1, sprintf_test_88);
    tcase_add_test(tc1_1, sprintf_test_89);
    tcase_add_test(tc1_1, sprintf_test_90);
    tcase_add_test(tc1_1, sprintf_test_91);
    tcase_add_test(tc1_1, sprintf_test_92);
    tcase_add_test(tc1_1, sprintf_test_93);
    tcase_add_test(tc1_1, sprintf_test_94);
    tcase_add_test(tc1_1, sprintf_test_95);
    tcase_add_test(tc1_1, sprintf_test_96);
    tcase_add_test(tc1_1, sprintf_test_97);
    tcase_add_test(tc1_1, sprintf_test_98);
    tcase_add_test(tc1_1, sprintf_test_99);
    tcase_add_test(tc1_1, sprintf_test_100);
    tcase_add_test(tc1_1, sprintf_test_101);
    tcase_add_test(tc1_1, sprintf_test_102);
    tcase_add_test(tc1_1, sprintf_test_103);
    tcase_add_test(tc1_1, sprintf_test_104);
    tcase_add_test(tc1_1, sprintf_test_105);
    tcase_add_test(tc1_1, sprintf_test_106);
    tcase_add_test(tc1_1, sprintf_test_107);
    tcase_add_test(tc1_1, sprintf_test_108);
    tcase_add_test(tc1_1, sprintf_test_109);
    tcase_add_test(tc1_1, sprintf_test_110);
    tcase_add_test(tc1_1, sprintf_test_111);
    tcase_add_test(tc1_1, sprintf_test_112);
    tcase_add_test(tc1_1, sprintf_test_113);
    tcase_add_test(tc1_1, sprintf_test_114);
    tcase_add_test(tc1_1, sprintf_test_115);
    tcase_add_test(tc1_1, sprintf_test_116);
    tcase_add_test(tc1_1, sprintf_test_117);
    tcase_add_test(tc1_1, sprintf_test_118);
    tcase_add_test(tc1_1, sprintf_test_119);
    tcase_add_test(tc1_1, sprintf_test_120);
    tcase_add_test(tc1_1, sprintf_test_121);
    tcase_add_test(tc1_1, sprintf_test_122);
    tcase_add_test(tc1_1, sprintf_test_123);
    tcase_add_test(tc1_1, sprintf_test_124);
    tcase_add_test(tc1_1, sprintf_test_125);
    tcase_add_test(tc1_1, sprintf_test_126);
    tcase_add_test(tc1_1, sprintf_test_127);
    tcase_add_test(tc1_1, sprintf_test_128);
    tcase_add_test(tc1_1, sprintf_test_129);
    tcase_add_test(tc1_1, sprintf_test_130);
    tcase_add_test(tc1_1, sprintf_test_131);
    tcase_add_test(tc1_1, sprintf_test_132);
    tcase_add_test(tc1_1, sprintf_test_133);
    tcase_add_test(tc1_1, sprintf_test_134);
    tcase_add_test(tc1_1, sprintf_test_135);
    tcase_add_test(tc1_1, sprintf_test_136);
    tcase_add_test(tc1_1, sprintf_test_137);
    tcase_add_test(tc1_1, sprintf_test_138);
    tcase_add_test(tc1_1, sprintf_test_139);
    tcase_add_test(tc1_1, sprintf_test_140);
    tcase_add_test(tc1_1, sprintf_test_141);
    tcase_add_test(tc1_1, sprintf_test_142);
    tcase_add_test(tc1_1, sprintf_test_143);
    tcase_add_test(tc1_1, sprintf_test_144);
    tcase_add_test(tc1_1, sprintf_test_145);
    tcase_add_test(tc1_1, sprintf_test_146);
    tcase_add_test(tc1_1, sprintf_test_147);
    tcase_add_test(tc1_1, sprintf_test_148);
    tcase_add_test(tc1_1, sprintf_test_149);
    tcase_add_test(tc1_1, sprintf_test_150);
    tcase_add_test(tc1_1, sprintf_test_151);
    tcase_add_test(tc1_1, sprintf_test_152);
    tcase_add_test(tc1_1, sprintf_test_153);
    tcase_add_test(tc1_1, sprintf_test_154);
    tcase_add_test(tc1_1, sprintf_test_155);
    tcase_add_test(tc1_1, sprintf_test_156);
    tcase_add_test(tc1_1, sprintf_test_157);
    tcase_add_test(tc1_1, sprintf_test_158);
    tcase_add_test(tc1_1, sprintf_test_159);
    tcase_add_test(tc1_1, sprintf_test_160);
    tcase_add_test(tc1_1, sprintf_test_161);
    tcase_add_test(tc1_1, sprintf_test_162);
    tcase_add_test(tc1_1, sprintf_test_163);
    tcase_add_test(tc1_1, sprintf_test_164);
    tcase_add_test(tc1_1, sprintf_test_165);
    tcase_add_test(tc1_1, sprintf_test_166);
    tcase_add_test(tc1_1, sprintf_test_167);
    tcase_add_test(tc1_1, sprintf_test_168);
    tcase_add_test(tc1_1, sprintf_test_169);
    tcase_add_test(tc1_1, sprintf_test_170);
    tcase_add_test(tc1_1, sprintf_test_171);
    tcase_add_test(tc1_1, sprintf_test_172);
    tcase_add_test(tc1_1, sprintf_test_173);
    tcase_add_test(tc1_1, sprintf_test_174);
    tcase_add_test(tc1_1, sprintf_test_175);
    tcase_add_test(tc1_1, sprintf_test_176);
    tcase_add_test(tc1_1, sprintf_test_177);
    tcase_add_test(tc1_1, sprintf_test_178);
    tcase_add_test(tc1_1, sprintf_test_179);
    tcase_add_test(tc1_1, sprintf_test_180);
    tcase_add_test(tc1_1, sprintf_test_181);
    tcase_add_test(tc1_1, sprintf_test_182);
    tcase_add_test(tc1_1, sprintf_test_183);
    tcase_add_test(tc1_1, sprintf_test_184);
    tcase_add_test(tc1_1, sprintf_test_185);
    tcase_add_test(tc1_1, sprintf_test_186);
    tcase_add_test(tc1_1, sprintf_test_187);
    tcase_add_test(tc1_1, sprintf_test_188);
    tcase_add_test(tc1_1, sprintf_test_189);
    tcase_add_test(tc1_1, sprintf_test_190);
    tcase_add_test(tc1_1, sprintf_test_191);
    tcase_add_test(tc1_1, sprintf_test_192);
    tcase_add_test(tc1_1, sprintf_test_193);
    tcase_add_test(tc1_1, sprintf_test_194);
    tcase_add_test(tc1_1, sprintf_test_195);
    tcase_add_test(tc1_1, sprintf_test_196);
    tcase_add_test(tc1_1, sprintf_test_197);
    tcase_add_test(tc1_1, sprintf_test_198);
    tcase_add_test(tc1_1, sprintf_test_199);
    tcase_add_test(tc1_1, sprintf_test_200);
    tcase_add_test(tc1_1, sprintf_test_201);
    tcase_add_test(tc1_1, sprintf_test_202);
    tcase_add_test(tc1_1, sprintf_test_203);
    tcase_add_test(tc1_1, sprintf_test_204);
    tcase_add_test(tc1_1, sprintf_test_205);
    tcase_add_test(tc1_1, sprintf_test_206);
    tcase_add_test(tc1_1, sprintf_test_207);
    tcase_add_test(tc1_1, sprintf_test_208);
    tcase_add_test(tc1_1, sprintf_test_209);
    tcase_add_test(tc1_1, sprintf_test_210);
    tcase_add_test(tc1_1, sprintf_test_211);
    tcase_add_test(tc1_1, sprintf_test_212);
    tcase_add_test(tc1_1, sprintf_test_213);
    tcase_add_test(tc1_1, sprintf_test_214);
    tcase_add_test(tc1_1, sprintf_test_215);
    tcase_add_test(tc1_1, sprintf_test_216);
    tcase_add_test(tc1_1, sprintf_test_217);
    tcase_add_test(tc1_1, sprintf_test_218);
    tcase_add_test(tc1_1, sprintf_test_219);
    tcase_add_test(tc1_1, sprintf_test_220);
    tcase_add_test(tc1_1, sprintf_test_221);
    tcase_add_test(tc1_1, sprintf_test_222);
    tcase_add_test(tc1_1, sprintf_test_223);
    tcase_add_test(tc1_1, sprintf_test_224);
    tcase_add_test(tc1_1, sprintf_test_225);
    tcase_add_test(tc1_1, sprintf_test_226);
    tcase_add_test(tc1_1, sprintf_test_227);
    tcase_add_test(tc1_1, sprintf_test_228);
    tcase_add_test(tc1_1, sprintf_test_229);
    tcase_add_test(tc1_1, sprintf_test_230);
    tcase_add_test(tc1_1, sprintf_test_231);
    tcase_add_test(tc1_1, sprintf_test_232);
    tcase_add_test(tc1_1, sprintf_test_233);
    tcase_add_test(tc1_1, sprintf_test_234);
    tcase_add_test(tc1_1, sprintf_test_235);
    tcase_add_test(tc1_1, sprintf_test_236);
    tcase_add_test(tc1_1, sprintf_test_237);
    tcase_add_test(tc1_1, sprintf_test_238);
    tcase_add_test(tc1_1, sprintf_test_239);
    tcase_add_test(tc1_1, sprintf_test_240);
    tcase_add_test(tc1_1, sprintf_test_241);
    tcase_add_test(tc1_1, sprintf_test_242);
    tcase_add_test(tc1_1, sprintf_test_243);
    tcase_add_test(tc1_1, sprintf_test_244);
    tcase_add_test(tc1_1, sprintf_test_245);
    tcase_add_test(tc1_1, sprintf_test_246);
    tcase_add_test(tc1_1, sprintf_test_247);
    tcase_add_test(tc1_1, sprintf_test_248);
    tcase_add_test(tc1_1, sprintf_test_249);
    tcase_add_test(tc1_1, sprintf_test_250);
    tcase_add_test(tc1_1, sprintf_test_251);
    tcase_add_test(tc1_1, sprintf_test_252);
    tcase_add_test(tc1_1, sprintf_test_253);
    tcase_add_test(tc1_1, sprintf_test_254);
    tcase_add_test(tc1_1, sprintf_test_255);
    tcase_add_test(tc1_1, sprintf_test_256);
    tcase_add_test(tc1_1, sprintf_test_257);
    tcase_add_test(tc1_1, sprintf_test_258);
    tcase_add_test(tc1_1, sprintf_test_259);
    tcase_add_test(tc1_1, sprintf_test_260);
    tcase_add_test(tc1_1, sprintf_test_261);
    tcase_add_test(tc1_1, sprintf_test_262);
    tcase_add_test(tc1_1, sprintf_test_263);
    tcase_add_test(tc1_1, sprintf_test_264);
    tcase_add_test(tc1_1, sprintf_test_265);
    tcase_add_test(tc1_1, sprintf_test_266);
    tcase_add_test(tc1_1, sprintf_test_267);
    tcase_add_test(tc1_1, sprintf_test_268);
    tcase_add_test(tc1_1, sprintf_test_269);
    tcase_add_test(tc1_1, sprintf_test_270);
    tcase_add_test(tc1_1, sprintf_test_271);
    tcase_add_test(tc1_1, sprintf_test_272);
    tcase_add_test(tc1_1, sprintf_test_273);
    tcase_add_test(tc1_1, sprintf_test_274);
    tcase_add_test(tc1_1, sprintf_test_275);
    tcase_add_test(tc1_1, sprintf_test_276);
    tcase_add_test(tc1_1, sprintf_test_277);
    tcase_add_test(tc1_1, sprintf_test_278);
    tcase_add_test(tc1_1, sprintf_test_279);
    tcase_add_test(tc1_1, sprintf_test_280);
    tcase_add_test(tc1_1, sprintf_test_281);
    tcase_add_test(tc1_1, sprintf_test_282);
    tcase_add_test(tc1_1, sprintf_test_283);
    tcase_add_test(tc1_1, sprintf_test_284);
    tcase_add_test(tc1_1, sprintf_test_285);
    tcase_add_test(tc1_1, sprintf_test_286);
    tcase_add_test(tc1_1, sprintf_test_287);
    tcase_add_test(tc1_1, sprintf_test_288);
    tcase_add_test(tc1_1, sprintf_test_289);
    tcase_add_test(tc1_1, sprintf_test_290);
    tcase_add_test(tc1_1, sprintf_test_291);
    tcase_add_test(tc1_1, sprintf_test_292);
    tcase_add_test(tc1_1, sprintf_test_293);
    tcase_add_test(tc1_1, sprintf_test_294);
    tcase_add_test(tc1_1, sprintf_test_295);
    tcase_add_test(tc1_1, sprintf_test_296);
    tcase_add_test(tc1_1, sprintf_test_297);
    tcase_add_test(tc1_1, sprintf_test_298);
    tcase_add_test(tc1_1, sprintf_test_299);
    tcase_add_test(tc1_1, sprintf_test_300);
    tcase_add_test(tc1_1, sprintf_test_301);
    tcase_add_test(tc1_1, sprintf_test_302);
    tcase_add_test(tc1_1, sprintf_test_303);
    tcase_add_test(tc1_1, sprintf_test_304);
    tcase_add_test(tc1_1, sprintf_test_305);
    tcase_add_test(tc1_1, sprintf_test_306);
    tcase_add_test(tc1_1, sprintf_test_307);
    tcase_add_test(tc1_1, sprintf_test_308);
    tcase_add_test(tc1_1, sprintf_test_309);
    tcase_add_test(tc1_1, sprintf_test_310);
    tcase_add_test(tc1_1, sprintf_test_311);
    tcase_add_test(tc1_1, sprintf_test_312);
    tcase_add_test(tc1_1, sprintf_test_313);
    tcase_add_test(tc1_1, sprintf_test_314);
    tcase_add_test(tc1_1, sprintf_test_315);
    tcase_add_test(tc1_1, sprintf_test_316);
    tcase_add_test(tc1_1, sprintf_test_317);
    tcase_add_test(tc1_1, sprintf_test_318);
    tcase_add_test(tc1_1, sprintf_test_319);
    tcase_add_test(tc1_1, sprintf_test_320);
    tcase_add_test(tc1_1, sprintf_test_321);
    tcase_add_test(tc1_1, sprintf_test_322);
    tcase_add_test(tc1_1, sprintf_test_323);
    tcase_add_test(tc1_1, sprintf_test_324);
    tcase_add_test(tc1_1, sprintf_test_325);
    tcase_add_test(tc1_1, sprintf_test_326);
    tcase_add_test(tc1_1, sprintf_test_327);
    tcase_add_test(tc1_1, sprintf_test_328);
    tcase_add_test(tc1_1, sprintf_test_329);
    tcase_add_test(tc1_1, sprintf_test_330);
    tcase_add_test(tc1_1, sprintf_test_331);
    tcase_add_test(tc1_1, sprintf_test_332);
    tcase_add_test(tc1_1, sprintf_test_333);
    tcase_add_test(tc1_1, sprintf_test_334);
    tcase_add_test(tc1_1, sprintf_test_335);
    tcase_add_test(tc1_1, sprintf_test_336);
    tcase_add_test(tc1_1, sprintf_test_337);
    tcase_add_test(tc1_1, sprintf_test_338);
    tcase_add_test(tc1_1, sprintf_test_339);
    tcase_add_test(tc1_1, sprintf_test_340);
    tcase_add_test(tc1_1, sprintf_test_341);
    tcase_add_test(tc1_1, sprintf_test_342);
    tcase_add_test(tc1_1, sprintf_test_343);
    tcase_add_test(tc1_1, sprintf_test_344);
    tcase_add_test(tc1_1, sprintf_test_345);
    tcase_add_test(tc1_1, sprintf_test_346);
    tcase_add_test(tc1_1, sprintf_test_347);
    tcase_add_test(tc1_1, sprintf_test_348);
    tcase_add_test(tc1_1, sprintf_test_349);
    tcase_add_test(tc1_1, sprintf_test_350);
    tcase_add_test(tc1_1, sprintf_test_351);
    tcase_add_test(tc1_1, sprintf_test_352);
    tcase_add_test(tc1_1, sprintf_test_353);
    tcase_add_test(tc1_1, sprintf_test_354);
    tcase_add_test(tc1_1, sprintf_test_355);
    tcase_add_test(tc1_1, sprintf_test_356);
    tcase_add_test(tc1_1, sprintf_test_357);
    tcase_add_test(tc1_1, sprintf_test_358);
    tcase_add_test(tc1_1, sprintf_test_359);
    tcase_add_test(tc1_1, sprintf_test_360);
    tcase_add_test(tc1_1, sprintf_test_361);
    tcase_add_test(tc1_1, sprintf_test_362);
    tcase_add_test(tc1_1, sprintf_test_363);
    tcase_add_test(tc1_1, sprintf_test_364);
    tcase_add_test(tc1_1, sprintf_test_365);
    tcase_add_test(tc1_1, sprintf_test_366);
    tcase_add_test(tc1_1, sprintf_test_367);
    tcase_add_test(tc1_1, sprintf_test_368);
    tcase_add_test(tc1_1, sprintf_test_369);
    tcase_add_test(tc1_1, sprintf_test_370);
    tcase_add_test(tc1_1, sprintf_test_371);
    tcase_add_test(tc1_1, sprintf_test_372);
    tcase_add_test(tc1_1, sprintf_test_373);
    tcase_add_test(tc1_1, sprintf_test_374);
    tcase_add_test(tc1_1, sprintf_test_375);
    tcase_add_test(tc1_1, sprintf_test_376);
    tcase_add_test(tc1_1, sprintf_test_377);
    tcase_add_test(tc1_1, sprintf_test_378);
    tcase_add_test(tc1_1, sprintf_test_379);
    tcase_add_test(tc1_1, sprintf_test_380);
    tcase_add_test(tc1_1, sprintf_test_381);
    tcase_add_test(tc1_1, sprintf_test_382);
    tcase_add_test(tc1_1, sprintf_test_383);
    tcase_add_test(tc1_1, sprintf_test_384);
    tcase_add_test(tc1_1, sprintf_test_385);
    tcase_add_test(tc1_1, sprintf_test_386);
    tcase_add_test(tc1_1, sprintf_test_387);
    tcase_add_test(tc1_1, sprintf_test_388);
    tcase_add_test(tc1_1, sprintf_test_389);
    tcase_add_test(tc1_1, sprintf_test_390);
    tcase_add_test(tc1_1, sprintf_test_391);
    tcase_add_test(tc1_1, sprintf_test_392);
    tcase_add_test(tc1_1, sprintf_test_393);
    tcase_add_test(tc1_1, sprintf_test_394);
    tcase_add_test(tc1_1, sprintf_test_395);
    tcase_add_test(tc1_1, sprintf_test_396);
    tcase_add_test(tc1_1, sprintf_test_397);
    tcase_add_test(tc1_1, sprintf_test_398);
    tcase_add_test(tc1_1, sprintf_test_399);
    tcase_add_test(tc1_1, sprintf_test_400);
    tcase_add_test(tc1_1, sprintf_test_401);
    tcase_add_test(tc1_1, sprintf_test_402);
    tcase_add_test(tc1_1, sprintf_test_403);
    tcase_add_test(tc1_1, sprintf_test_404);
    tcase_add_test(tc1_1, sprintf_test_405);
    tcase_add_test(tc1_1, sprintf_test_406);
    tcase_add_test(tc1_1, sprintf_test_407);
    tcase_add_test(tc1_1, sprintf_test_408);
    tcase_add_test(tc1_1, sprintf_test_409);
    tcase_add_test(tc1_1, sprintf_test_410);
    tcase_add_test(tc1_1, sprintf_test_411);
    tcase_add_test(tc1_1, sprintf_test_412);
    tcase_add_test(tc1_1, sprintf_test_413);
    tcase_add_test(tc1_1, sprintf_test_414);
    tcase_add_test(tc1_1, sprintf_test_415);
    tcase_add_test(tc1_1, sprintf_test_416);
    tcase_add_test(tc1_1, sprintf_test_417);
    tcase_add_test(tc1_1, sprintf_test_418);
    tcase_add_test(tc1_1, sprintf_test_419);
    tcase_add_test(tc1_1, sprintf_test_420);
    tcase_add_test(tc1_1, sprintf_test_421);
    tcase_add_test(tc1_1, sprintf_test_422);
    tcase_add_test(tc1_1, sprintf_test_423);
    tcase_add_test(tc1_1, sprintf_test_424);
    tcase_add_test(tc1_1, sprintf_test_425);
    tcase_add_test(tc1_1, sprintf_test_426);
    tcase_add_test(tc1_1, sprintf_test_427);
    tcase_add_test(tc1_1, sprintf_test_428);
    tcase_add_test(tc1_1, sprintf_test_429);
    tcase_add_test(tc1_1, sprintf_test_430);
    tcase_add_test(tc1_1, sprintf_test_431);
    tcase_add_test(tc1_1, sprintf_test_432);
    tcase_add_test(tc1_1, sprintf_test_433);
    tcase_add_test(tc1_1, sprintf_test_434);
    tcase_add_test(tc1_1, sprintf_test_435);
    tcase_add_test(tc1_1, sprintf_test_436);
    tcase_add_test(tc1_1, sprintf_test_437);
    tcase_add_test(tc1_1, sprintf_test_438);
    tcase_add_test(tc1_1, sprintf_test_439);
    tcase_add_test(tc1_1, sprintf_test_440);
    tcase_add_test(tc1_1, sprintf_test_441);
    tcase_add_test(tc1_1, sprintf_test_442);
    tcase_add_test(tc1_1, sprintf_test_443);
    tcase_add_test(tc1_1, sprintf_test_444);
    tcase_add_test(tc1_1, sprintf_test_445);
    tcase_add_test(tc1_1, sprintf_test_446);
    tcase_add_test(tc1_1, sprintf_test_447);
    tcase_add_test(tc1_1, sprintf_test_448);
    tcase_add_test(tc1_1, sprintf_test_449);
    tcase_add_test(tc1_1, sprintf_test_450);
    tcase_add_test(tc1_1, sprintf_test_451);
    tcase_add_test(tc1_1, sprintf_test_452);
    tcase_add_test(tc1_1, sprintf_test_453);
    tcase_add_test(tc1_1, sprintf_test_454);
    tcase_add_test(tc1_1, sprintf_test_455);
    tcase_add_test(tc1_1, sprintf_test_456);
    tcase_add_test(tc1_1, sprintf_test_457);
    tcase_add_test(tc1_1, sprintf_test_458);
    tcase_add_test(tc1_1, sprintf_test_459);
    tcase_add_test(tc1_1, sprintf_test_460);
    tcase_add_test(tc1_1, sprintf_test_461);
    tcase_add_test(tc1_1, sprintf_test_462);
    tcase_add_test(tc1_1, sprintf_test_463);
    tcase_add_test(tc1_1, sprintf_test_464);
    tcase_add_test(tc1_1, sprintf_test_465);
    tcase_add_test(tc1_1, sprintf_test_466);
    tcase_add_test(tc1_1, sprintf_test_467);
    tcase_add_test(tc1_1, sprintf_test_468);
    tcase_add_test(tc1_1, sprintf_test_469);
    tcase_add_test(tc1_1, sprintf_test_470);
    tcase_add_test(tc1_1, sprintf_test_471);
    tcase_add_test(tc1_1, sprintf_test_472);
    tcase_add_test(tc1_1, sprintf_test_473);
    tcase_add_test(tc1_1, sprintf_test_474);
    tcase_add_test(tc1_1, sprintf_test_475);
    tcase_add_test(tc1_1, sprintf_test_476);
    tcase_add_test(tc1_1, sprintf_test_477);
    tcase_add_test(tc1_1, sprintf_test_478);
    tcase_add_test(tc1_1, sprintf_test_479);
    tcase_add_test(tc1_1, sprintf_test_480);
    tcase_add_test(tc1_1, sprintf_test_481);
    tcase_add_test(tc1_1, sprintf_test_482);
    tcase_add_test(tc1_1, sprintf_test_483);
    tcase_add_test(tc1_1, sprintf_test_484);
    tcase_add_test(tc1_1, sprintf_test_485);
    tcase_add_test(tc1_1, sprintf_test_486);
    tcase_add_test(tc1_1, sprintf_test_487);
    tcase_add_test(tc1_1, sprintf_test_488);
    tcase_add_test(tc1_1, sprintf_test_489);
    tcase_add_test(tc1_1, sprintf_test_490);
    tcase_add_test(tc1_1, sprintf_test_491);
    tcase_add_test(tc1_1, sprintf_test_492);
    tcase_add_test(tc1_1, sprintf_test_493);
    tcase_add_test(tc1_1, sprintf_test_494);
    tcase_add_test(tc1_1, sprintf_test_495);
    tcase_add_test(tc1_1, sprintf_test_496);
    tcase_add_test(tc1_1, sprintf_test_497);
    tcase_add_test(tc1_1, sprintf_test_498);
    tcase_add_test(tc1_1, sprintf_test_499);
    tcase_add_test(tc1_1, sprintf_test_500);
    tcase_add_test(tc1_1, sprintf_test_501);
    tcase_add_test(tc1_1, sprintf_test_502);
    tcase_add_test(tc1_1, sprintf_test_503);
    tcase_add_test(tc1_1, sprintf_test_504);
    tcase_add_test(tc1_1, sprintf_test_505);
    tcase_add_test(tc1_1, sprintf_test_506);
    tcase_add_test(tc1_1, sprintf_test_507);
    tcase_add_test(tc1_1, sprintf_test_508);
    tcase_add_test(tc1_1, sprintf_test_509);
    tcase_add_test(tc1_1, sprintf_test_510);
    tcase_add_test(tc1_1, sprintf_test_511);
    tcase_add_test(tc1_1, sprintf_test_512);
    tcase_add_test(tc1_1, sprintf_test_513);
    tcase_add_test(tc1_1, sprintf_test_514);
    tcase_add_test(tc1_1, sprintf_test_515);
    tcase_add_test(tc1_1, sprintf_test_516);
    tcase_add_test(tc1_1, sprintf_test_517);
    tcase_add_test(tc1_1, sprintf_test_518);
    tcase_add_test(tc1_1, sprintf_test_519);
    tcase_add_test(tc1_1, sprintf_test_520);
    tcase_add_test(tc1_1, sprintf_test_521);
    tcase_add_test(tc1_1, sprintf_test_522);
    tcase_add_test(tc1_1, sprintf_test_523);
    tcase_add_test(tc1_1, sprintf_test_524);
    tcase_add_test(tc1_1, sprintf_test_525);
    tcase_add_test(tc1_1, sprintf_test_526);
    tcase_add_test(tc1_1, sprintf_test_527);
    tcase_add_test(tc1_1, sprintf_test_528);
    tcase_add_test(tc1_1, sprintf_test_529);
    tcase_add_test(tc1_1, sprintf_test_530);
    tcase_add_test(tc1_1, sprintf_test_531);
    tcase_add_test(tc1_1, sprintf_test_532);
    tcase_add_test(tc1_1, sprintf_test_533);
    tcase_add_test(tc1_1, sprintf_test_534);
    tcase_add_test(tc1_1, sprintf_test_535);
    tcase_add_test(tc1_1, sprintf_test_536);
    tcase_add_test(tc1_1, sprintf_test_537);
    tcase_add_test(tc1_1, sprintf_test_538);
    tcase_add_test(tc1_1, sprintf_test_539);
    tcase_add_test(tc1_1, sprintf_test_540);
    tcase_add_test(tc1_1, sprintf_test_541);
    tcase_add_test(tc1_1, sprintf_test_542);
    tcase_add_test(tc1_1, sprintf_test_543);
    tcase_add_test(tc1_1, sprintf_test_544);
    tcase_add_test(tc1_1, sprintf_test_545);
    tcase_add_test(tc1_1, sprintf_test_546);
    tcase_add_test(tc1_1, sprintf_test_547);
    tcase_add_test(tc1_1, sprintf_test_548);
    tcase_add_test(tc1_1, sprintf_test_549);
    tcase_add_test(tc1_1, sprintf_test_550);
    tcase_add_test(tc1_1, sprintf_test_551);
    tcase_add_test(tc1_1, sprintf_test_552);
    tcase_add_test(tc1_1, sprintf_test_553);
    tcase_add_test(tc1_1, sprintf_test_554);
    tcase_add_test(tc1_1, sprintf_test_555);
    tcase_add_test(tc1_1, sprintf_test_556);
    tcase_add_test(tc1_1, sprintf_test_557);
    tcase_add_test(tc1_1, sprintf_test_558);
    tcase_add_test(tc1_1, sprintf_test_559);
    tcase_add_test(tc1_1, sprintf_test_560);
    tcase_add_test(tc1_1, sprintf_test_561);
    tcase_add_test(tc1_1, sprintf_test_562);
    tcase_add_test(tc1_1, sprintf_test_563);
    tcase_add_test(tc1_1, sprintf_test_564);
    tcase_add_test(tc1_1, sprintf_test_565);
    tcase_add_test(tc1_1, sprintf_test_566);
    tcase_add_test(tc1_1, sprintf_test_567);
    tcase_add_test(tc1_1, sprintf_test_568);
    tcase_add_test(tc1_1, sprintf_test_569);
    tcase_add_test(tc1_1, sprintf_test_570);
    tcase_add_test(tc1_1, sprintf_test_571);
    tcase_add_test(tc1_1, sprintf_test_572);
    tcase_add_test(tc1_1, sprintf_test_573);
    tcase_add_test(tc1_1, sprintf_test_574);
    tcase_add_test(tc1_1, sprintf_test_575);
    tcase_add_test(tc1_1, sprintf_test_576);
    tcase_add_test(tc1_1, sprintf_test_577);
    tcase_add_test(tc1_1, sprintf_test_578);
    tcase_add_test(tc1_1, sprintf_test_579);
    tcase_add_test(tc1_1, sprintf_test_580);
    tcase_add_test(tc1_1, sprintf_test_581);
    tcase_add_test(tc1_1, sprintf_test_582);
    tcase_add_test(tc1_1, sprintf_test_583);
    tcase_add_test(tc1_1, sprintf_test_584);
    tcase_add_test(tc1_1, sprintf_test_585);
    tcase_add_test(tc1_1, sprintf_test_586);
    tcase_add_test(tc1_1, sprintf_test_587);
    tcase_add_test(tc1_1, sprintf_test_588);
    tcase_add_test(tc1_1, sprintf_test_589);
    tcase_add_test(tc1_1, sprintf_test_590);
    tcase_add_test(tc1_1, sprintf_test_591);
    tcase_add_test(tc1_1, sprintf_test_592);
    tcase_add_test(tc1_1, sprintf_test_593);
    tcase_add_test(tc1_1, sprintf_test_594);
    tcase_add_test(tc1_1, sprintf_test_595);
    tcase_add_test(tc1_1, sprintf_test_596);
    tcase_add_test(tc1_1, sprintf_test_597);
    tcase_add_test(tc1_1, sprintf_test_598);
    tcase_add_test(tc1_1, sprintf_test_599);
    tcase_add_test(tc1_1, sprintf_test_600);
    tcase_add_test(tc1_1, sprintf_test_601);
    tcase_add_test(tc1_1, sprintf_test_602);
    tcase_add_test(tc1_1, sprintf_test_603);
    tcase_add_test(tc1_1, sprintf_test_604);
    tcase_add_test(tc1_1, sprintf_test_605);
    tcase_add_test(tc1_1, sprintf_test_606);
    tcase_add_test(tc1_1, sprintf_test_607);
    tcase_add_test(tc1_1, sprintf_test_608);
    tcase_add_test(tc1_1, sprintf_test_609);
    tcase_add_test(tc1_1, sprintf_test_610);
    tcase_add_test(tc1_1, sprintf_test_611);
    tcase_add_test(tc1_1, sprintf_test_612);
    tcase_add_test(tc1_1, sprintf_test_613);
    tcase_add_test(tc1_1, sprintf_test_614);
    tcase_add_test(tc1_1, sprintf_test_615);
    tcase_add_test(tc1_1, sprintf_test_616);
    tcase_add_test(tc1_1, sprintf_test_617);
    tcase_add_test(tc1_1, sprintf_test_618);
    tcase_add_test(tc1_1, sprintf_test_619);
    tcase_add_test(tc1_1, sprintf_test_620);
    tcase_add_test(tc1_1, sprintf_test_621);
    tcase_add_test(tc1_1, sprintf_test_622);
    tcase_add_test(tc1_1, sprintf_test_623);
    tcase_add_test(tc1_1, sprintf_test_624);
    tcase_add_test(tc1_1, sprintf_test_625);
    tcase_add_test(tc1_1, sprintf_test_626);
    tcase_add_test(tc1_1, sprintf_test_627);
    tcase_add_test(tc1_1, sprintf_test_628);
    tcase_add_test(tc1_1, sprintf_test_629);
    tcase_add_test(tc1_1, sprintf_test_630);
    tcase_add_test(tc1_1, sprintf_test_631);
    tcase_add_test(tc1_1, sprintf_test_632);
    tcase_add_test(tc1_1, sprintf_test_633);
    tcase_add_test(tc1_1, sprintf_test_634);
    tcase_add_test(tc1_1, sprintf_test_635);
    tcase_add_test(tc1_1, sprintf_test_636);
    tcase_add_test(tc1_1, sprintf_test_637);
    tcase_add_test(tc1_1, sprintf_test_638);
    tcase_add_test(tc1_1, sprintf_test_639);
    tcase_add_test(tc1_1, sprintf_test_640);
    tcase_add_test(tc1_1, sprintf_test_641);
    tcase_add_test(tc1_1, sprintf_test_642);
    tcase_add_test(tc1_1, sprintf_test_643);
    tcase_add_test(tc1_1, sprintf_test_644);
    tcase_add_test(tc1_1, sprintf_test_645);
    tcase_add_test(tc1_1, sprintf_test_646);
    tcase_add_test(tc1_1, sprintf_test_647);
    tcase_add_test(tc1_1, sprintf_test_648);
    tcase_add_test(tc1_1, sprintf_test_649);
    tcase_add_test(tc1_1, sprintf_test_650);
    tcase_add_test(tc1_1, sprintf_test_651);
    tcase_add_test(tc1_1, sprintf_test_652);
    tcase_add_test(tc1_1, sprintf_test_653);
    tcase_add_test(tc1_1, sprintf_test_654);
    tcase_add_test(tc1_1, sprintf_test_655);
    tcase_add_test(tc1_1, sprintf_test_656);
    tcase_add_test(tc1_1, sprintf_test_657);
    tcase_add_test(tc1_1, sprintf_test_658);
    tcase_add_test(tc1_1, sprintf_test_659);
    tcase_add_test(tc1_1, sprintf_test_660);
    tcase_add_test(tc1_1, sprintf_test_661);
    tcase_add_test(tc1_1, sprintf_test_662);
    tcase_add_test(tc1_1, sprintf_test_663);
    tcase_add_test(tc1_1, sprintf_test_664);
    tcase_add_test(tc1_1, sprintf_test_665);
    tcase_add_test(tc1_1, sprintf_test_666);
    tcase_add_test(tc1_1, sprintf_test_667);
    tcase_add_test(tc1_1, sprintf_test_668);
    tcase_add_test(tc1_1, sprintf_test_669);
    tcase_add_test(tc1_1, sprintf_test_670);
    tcase_add_test(tc1_1, sprintf_test_671);
    tcase_add_test(tc1_1, sprintf_test_672);
    tcase_add_test(tc1_1, sprintf_test_673);
    tcase_add_test(tc1_1, sprintf_test_674);
    tcase_add_test(tc1_1, sprintf_test_675);
    tcase_add_test(tc1_1, sprintf_test_676);
    tcase_add_test(tc1_1, sprintf_test_677);
    tcase_add_test(tc1_1, sprintf_test_678);
    tcase_add_test(tc1_1, sprintf_test_679);
    tcase_add_test(tc1_1, sprintf_test_680);
    tcase_add_test(tc1_1, sprintf_test_681);
    tcase_add_test(tc1_1, sprintf_test_682);
    tcase_add_test(tc1_1, sprintf_test_683);
    tcase_add_test(tc1_1, sprintf_test_684);
    tcase_add_test(tc1_1, sprintf_test_685);
    tcase_add_test(tc1_1, sprintf_test_686);
    tcase_add_test(tc1_1, sprintf_test_687);
    tcase_add_test(tc1_1, sprintf_test_688);
    tcase_add_test(tc1_1, sprintf_test_689);
    tcase_add_test(tc1_1, sprintf_test_690);
    tcase_add_test(tc1_1, sprintf_test_691);
    tcase_add_test(tc1_1, sprintf_test_692);
    tcase_add_test(tc1_1, sprintf_test_693);
    tcase_add_test(tc1_1, sprintf_test_694);
    tcase_add_test(tc1_1, sprintf_test_695);
    tcase_add_test(tc1_1, sprintf_test_696);
    tcase_add_test(tc1_1, sprintf_test_697);
    tcase_add_test(tc1_1, sprintf_test_698);
    tcase_add_test(tc1_1, sprintf_test_699);
    tcase_add_test(tc1_1, sprintf_test_700);
    tcase_add_test(tc1_1, sprintf_test_701);
    tcase_add_test(tc1_1, sprintf_test_702);
    tcase_add_test(tc1_1, sprintf_test_703);
    tcase_add_test(tc1_1, sprintf_test_704);
    tcase_add_test(tc1_1, sprintf_test_705);
    tcase_add_test(tc1_1, sprintf_test_706);
    tcase_add_test(tc1_1, sprintf_test_707);
    tcase_add_test(tc1_1, sprintf_test_708);
    tcase_add_test(tc1_1, sprintf_test_709);
    tcase_add_test(tc1_1, sprintf_test_710);
    tcase_add_test(tc1_1, sprintf_test_711);
    tcase_add_test(tc1_1, sprintf_test_712);
    tcase_add_test(tc1_1, sprintf_test_713);
    tcase_add_test(tc1_1, sprintf_test_714);
    tcase_add_test(tc1_1, sprintf_test_715);
    tcase_add_test(tc1_1, sprintf_test_716);
    tcase_add_test(tc1_1, sprintf_test_717);
    tcase_add_test(tc1_1, sprintf_test_718);
    tcase_add_test(tc1_1, sprintf_test_719);
    tcase_add_test(tc1_1, sprintf_test_720);
    tcase_add_test(tc1_1, sprintf_test_721);
    tcase_add_test(tc1_1, sprintf_test_722);
    tcase_add_test(tc1_1, sprintf_test_723);
    tcase_add_test(tc1_1, sprintf_test_724);
    tcase_add_test(tc1_1, sprintf_test_725);
    tcase_add_test(tc1_1, sprintf_test_726);
    tcase_add_test(tc1_1, sprintf_test_727);
    tcase_add_test(tc1_1, sprintf_test_728);
    tcase_add_test(tc1_1, sprintf_test_729);
    tcase_add_test(tc1_1, sprintf_test_730);
    tcase_add_test(tc1_1, sprintf_test_731);
    tcase_add_test(tc1_1, sprintf_test_732);
    tcase_add_test(tc1_1, sprintf_test_733);
    tcase_add_test(tc1_1, sprintf_test_734);
    tcase_add_test(tc1_1, sprintf_test_735);
    tcase_add_test(tc1_1, sprintf_test_736);
    tcase_add_test(tc1_1, sprintf_test_737);
    tcase_add_test(tc1_1, sprintf_test_738);
    tcase_add_test(tc1_1, sprintf_test_739);
    tcase_add_test(tc1_1, sprintf_test_740);
    tcase_add_test(tc1_1, sprintf_test_741);
    tcase_add_test(tc1_1, sprintf_test_742);
    tcase_add_test(tc1_1, sprintf_test_743);
    tcase_add_test(tc1_1, sprintf_test_744);
    tcase_add_test(tc1_1, sprintf_test_745);
    tcase_add_test(tc1_1, sprintf_test_746);
    tcase_add_test(tc1_1, sprintf_test_747);
    tcase_add_test(tc1_1, sprintf_test_748);
    tcase_add_test(tc1_1, sprintf_test_749);
    tcase_add_test(tc1_1, sprintf_test_750);
    tcase_add_test(tc1_1, sprintf_test_751);
    tcase_add_test(tc1_1, sprintf_test_752);
    tcase_add_test(tc1_1, sprintf_test_753);
    tcase_add_test(tc1_1, sprintf_test_754);
    tcase_add_test(tc1_1, sprintf_test_755);
    tcase_add_test(tc1_1, sprintf_test_756);
    tcase_add_test(tc1_1, sprintf_test_757);
    tcase_add_test(tc1_1, sprintf_test_758);
    tcase_add_test(tc1_1, sprintf_test_759);
    tcase_add_test(tc1_1, sprintf_test_760);
    tcase_add_test(tc1_1, sprintf_test_761);
    tcase_add_test(tc1_1, sprintf_test_762);
    tcase_add_test(tc1_1, sprintf_test_763);
    tcase_add_test(tc1_1, sprintf_test_764);
    tcase_add_test(tc1_1, sprintf_test_765);
    tcase_add_test(tc1_1, sprintf_test_766);
    tcase_add_test(tc1_1, sprintf_test_767);
    tcase_add_test(tc1_1, sprintf_test_768);
    tcase_add_test(tc1_1, sprintf_test_769);
    tcase_add_test(tc1_1, sprintf_test_770);
    tcase_add_test(tc1_1, sprintf_test_771);
    tcase_add_test(tc1_1, sprintf_test_772);
    tcase_add_test(tc1_1, sprintf_test_773);
    tcase_add_test(tc1_1, sprintf_test_774);
    tcase_add_test(tc1_1, sprintf_test_775);
    tcase_add_test(tc1_1, sprintf_test_776);
    tcase_add_test(tc1_1, sprintf_test_777);
    tcase_add_test(tc1_1, sprintf_test_778);
    tcase_add_test(tc1_1, sprintf_test_779);
    tcase_add_test(tc1_1, sprintf_test_780);
    tcase_add_test(tc1_1, sprintf_test_781);
    tcase_add_test(tc1_1, sprintf_test_782);
    tcase_add_test(tc1_1, sprintf_test_783);
    tcase_add_test(tc1_1, sprintf_test_784);
    tcase_add_test(tc1_1, sprintf_test_785);
    tcase_add_test(tc1_1, sprintf_test_786);
    tcase_add_test(tc1_1, sprintf_test_787);
    tcase_add_test(tc1_1, sprintf_test_788);
    tcase_add_test(tc1_1, sprintf_test_789);
    tcase_add_test(tc1_1, sprintf_test_790);
    tcase_add_test(tc1_1, sprintf_test_791);
    tcase_add_test(tc1_1, sprintf_test_792);
    tcase_add_test(tc1_1, sprintf_test_793);
    tcase_add_test(tc1_1, sprintf_test_794);
    tcase_add_test(tc1_1, sprintf_test_795);
    tcase_add_test(tc1_1, sprintf_test_796);
    tcase_add_test(tc1_1, sprintf_test_797);
    tcase_add_test(tc1_1, sprintf_test_798);
    tcase_add_test(tc1_1, sprintf_test_799);
    tcase_add_test(tc1_1, sprintf_test_800);
    tcase_add_test(tc1_1, sprintf_test_801);
    tcase_add_test(tc1_1, sprintf_test_802);
    tcase_add_test(tc1_1, sprintf_test_803);
    tcase_add_test(tc1_1, sprintf_test_804);
    tcase_add_test(tc1_1, sprintf_test_805);
    tcase_add_test(tc1_1, sprintf_test_806);
    tcase_add_test(tc1_1, sprintf_test_807);
    tcase_add_test(tc1_1, sprintf_test_808);
    tcase_add_test(tc1_1, sprintf_test_809);
    tcase_add_test(tc1_1, sprintf_test_810);
    tcase_add_test(tc1_1, sprintf_test_811);
    tcase_add_test(tc1_1, sprintf_test_812);
    tcase_add_test(tc1_1, sprintf_test_813);
    tcase_add_test(tc1_1, sprintf_test_814);
    tcase_add_test(tc1_1, sprintf_test_815);
    tcase_add_test(tc1_1, sprintf_test_816);
    tcase_add_test(tc1_1, sprintf_test_817);
    tcase_add_test(tc1_1, sprintf_test_818);
    tcase_add_test(tc1_1, sprintf_test_819);
    tcase_add_test(tc1_1, sprintf_test_820);
    tcase_add_test(tc1_1, sprintf_test_821);
    tcase_add_test(tc1_1, sprintf_test_822);
    tcase_add_test(tc1_1, sprintf_test_823);
    tcase_add_test(tc1_1, sprintf_test_824);
    tcase_add_test(tc1_1, sprintf_test_825);
    tcase_add_test(tc1_1, sprintf_test_826);
    tcase_add_test(tc1_1, sprintf_test_827);
    tcase_add_test(tc1_1, sprintf_test_828);
    tcase_add_test(tc1_1, sprintf_test_829);
    tcase_add_test(tc1_1, sprintf_test_830);
    tcase_add_test(tc1_1, sprintf_test_831);
    tcase_add_test(tc1_1, sprintf_test_832);
    tcase_add_test(tc1_1, sprintf_test_833);
    tcase_add_test(tc1_1, sprintf_test_834);
    tcase_add_test(tc1_1, sprintf_test_835);
    tcase_add_test(tc1_1, sprintf_test_836);
    tcase_add_test(tc1_1, sprintf_test_837);
    tcase_add_test(tc1_1, sprintf_test_838);
    tcase_add_test(tc1_1, sprintf_test_839);
    tcase_add_test(tc1_1, sprintf_test_840);
    tcase_add_test(tc1_1, sprintf_test_841);
    tcase_add_test(tc1_1, sprintf_test_842);
    tcase_add_test(tc1_1, sprintf_test_843);
    tcase_add_test(tc1_1, sprintf_test_844);
    tcase_add_test(tc1_1, sprintf_test_845);
    tcase_add_test(tc1_1, sprintf_test_846);
    tcase_add_test(tc1_1, sprintf_test_847);
    tcase_add_test(tc1_1, sprintf_test_848);
    tcase_add_test(tc1_1, sprintf_test_849);
    tcase_add_test(tc1_1, sprintf_test_850);
    tcase_add_test(tc1_1, sprintf_test_851);
    tcase_add_test(tc1_1, sprintf_test_852);
    tcase_add_test(tc1_1, sprintf_test_853);
    tcase_add_test(tc1_1, sprintf_test_854);
    tcase_add_test(tc1_1, sprintf_test_855);
    tcase_add_test(tc1_1, sprintf_test_856);
    tcase_add_test(tc1_1, sprintf_test_857);
    tcase_add_test(tc1_1, sprintf_test_858);
    tcase_add_test(tc1_1, sprintf_test_859);
    tcase_add_test(tc1_1, sprintf_test_860);
    tcase_add_test(tc1_1, sprintf_test_861);
    tcase_add_test(tc1_1, sprintf_test_862);
    tcase_add_test(tc1_1, sprintf_test_863);
    tcase_add_test(tc1_1, sprintf_test_864);
    tcase_add_test(tc1_1, sprintf_test_865);
    tcase_add_test(tc1_1, sprintf_test_866);
    tcase_add_test(tc1_1, sprintf_test_867);
    tcase_add_test(tc1_1, sprintf_test_868);
    tcase_add_test(tc1_1, sprintf_test_869);
    tcase_add_test(tc1_1, sprintf_test_870);
    tcase_add_test(tc1_1, sprintf_test_871);
    tcase_add_test(tc1_1, sprintf_test_872);
    tcase_add_test(tc1_1, sprintf_test_873);
    tcase_add_test(tc1_1, sprintf_test_874);
    tcase_add_test(tc1_1, sprintf_test_875);
    tcase_add_test(tc1_1, sprintf_test_876);
    tcase_add_test(tc1_1, sprintf_test_877);
    tcase_add_test(tc1_1, sprintf_test_878);
    tcase_add_test(tc1_1, sprintf_test_879);
    tcase_add_test(tc1_1, sprintf_test_880);
    tcase_add_test(tc1_1, sprintf_test_881);
    tcase_add_test(tc1_1, sprintf_test_882);
    tcase_add_test(tc1_1, sprintf_test_883);
    tcase_add_test(tc1_1, sprintf_test_884);
    tcase_add_test(tc1_1, sprintf_test_885);
    tcase_add_test(tc1_1, sprintf_test_886);
    tcase_add_test(tc1_1, sprintf_test_887);
    tcase_add_test(tc1_1, sprintf_test_888);
    tcase_add_test(tc1_1, sprintf_test_889);
    tcase_add_test(tc1_1, sprintf_test_890);
    tcase_add_test(tc1_1, sprintf_test_891);
    tcase_add_test(tc1_1, sprintf_test_892);
    tcase_add_test(tc1_1, sprintf_test_893);
    tcase_add_test(tc1_1, sprintf_test_894);
    tcase_add_test(tc1_1, sprintf_test_895);
    tcase_add_test(tc1_1, sprintf_test_896);
    tcase_add_test(tc1_1, sprintf_test_897);
    tcase_add_test(tc1_1, sprintf_test_898);
    tcase_add_test(tc1_1, sprintf_test_899);
    tcase_add_test(tc1_1, sprintf_test_900);
    tcase_add_test(tc1_1, sprintf_test_901);
    tcase_add_test(tc1_1, sprintf_test_902);
    tcase_add_test(tc1_1, sprintf_test_903);
    tcase_add_test(tc1_1, sprintf_test_904);
    tcase_add_test(tc1_1, sprintf_test_905);
    tcase_add_test(tc1_1, sprintf_test_906);
    tcase_add_test(tc1_1, sprintf_test_907);
    tcase_add_test(tc1_1, sprintf_test_908);
    tcase_add_test(tc1_1, sprintf_test_909);
    tcase_add_test(tc1_1, sprintf_test_910);
    tcase_add_test(tc1_1, sprintf_test_911);
    tcase_add_test(tc1_1, sprintf_test_912);
    tcase_add_test(tc1_1, sprintf_test_913);
    tcase_add_test(tc1_1, sprintf_test_914);
    tcase_add_test(tc1_1, sprintf_test_915);
    tcase_add_test(tc1_1, sprintf_test_916);
    tcase_add_test(tc1_1, sprintf_test_917);
    tcase_add_test(tc1_1, sprintf_test_918);
    tcase_add_test(tc1_1, sprintf_test_919);
    tcase_add_test(tc1_1, sprintf_test_920);
    tcase_add_test(tc1_1, sprintf_test_921);
    tcase_add_test(tc1_1, sprintf_test_922);
    tcase_add_test(tc1_1, sprintf_test_923);
    tcase_add_test(tc1_1, sprintf_test_924);
    tcase_add_test(tc1_1, sprintf_test_925);
    tcase_add_test(tc1_1, sprintf_test_926);
    tcase_add_test(tc1_1, sprintf_test_927);
    tcase_add_test(tc1_1, sprintf_test_928);
    tcase_add_test(tc1_1, sprintf_test_929);
    tcase_add_test(tc1_1, sprintf_test_930);
    tcase_add_test(tc1_1, sprintf_test_931);
    tcase_add_test(tc1_1, sprintf_test_932);
    tcase_add_test(tc1_1, sprintf_test_933);
    tcase_add_test(tc1_1, sprintf_test_934);
    tcase_add_test(tc1_1, sprintf_test_935);
    tcase_add_test(tc1_1, sprintf_test_936);
    tcase_add_test(tc1_1, sprintf_test_937);
    tcase_add_test(tc1_1, sprintf_test_938);
    tcase_add_test(tc1_1, sprintf_test_939);
    tcase_add_test(tc1_1, sprintf_test_940);
    tcase_add_test(tc1_1, sprintf_test_941);
    tcase_add_test(tc1_1, sprintf_test_942);
    tcase_add_test(tc1_1, sprintf_test_943);
    tcase_add_test(tc1_1, sprintf_test_944);
    tcase_add_test(tc1_1, sprintf_test_945);
    tcase_add_test(tc1_1, sprintf_test_946);
    tcase_add_test(tc1_1, sprintf_test_947);
    tcase_add_test(tc1_1, sprintf_test_948);
    tcase_add_test(tc1_1, sprintf_test_949);
    tcase_add_test(tc1_1, sprintf_test_950);
    tcase_add_test(tc1_1, sprintf_test_951);
    tcase_add_test(tc1_1, sprintf_test_952);
    tcase_add_test(tc1_1, sprintf_test_953);
    tcase_add_test(tc1_1, sprintf_test_954);
    tcase_add_test(tc1_1, sprintf_test_955);
    tcase_add_test(tc1_1, sprintf_test_956);
    tcase_add_test(tc1_1, sprintf_test_957);
    tcase_add_test(tc1_1, sprintf_test_958);
    tcase_add_test(tc1_1, sprintf_test_959);
    tcase_add_test(tc1_1, sprintf_test_960);
    tcase_add_test(tc1_1, sprintf_test_961);
    tcase_add_test(tc1_1, sprintf_test_962);
    tcase_add_test(tc1_1, sprintf_test_963);
    tcase_add_test(tc1_1, sprintf_test_964);
    tcase_add_test(tc1_1, sprintf_test_965);
    tcase_add_test(tc1_1, sprintf_test_966);
    tcase_add_test(tc1_1, sprintf_test_967);
    tcase_add_test(tc1_1, sprintf_test_968);
    tcase_add_test(tc1_1, sprintf_test_969);
    tcase_add_test(tc1_1, sprintf_test_970);
    tcase_add_test(tc1_1, sprintf_test_971);
    tcase_add_test(tc1_1, sprintf_test_972);
    tcase_add_test(tc1_1, sprintf_test_973);
    tcase_add_test(tc1_1, sprintf_test_974);
    tcase_add_test(tc1_1, sprintf_test_975);
    tcase_add_test(tc1_1, sprintf_test_976);
    tcase_add_test(tc1_1, sprintf_test_977);
    tcase_add_test(tc1_1, sprintf_test_978);
    tcase_add_test(tc1_1, sprintf_test_979);
    tcase_add_test(tc1_1, sprintf_test_980);
    tcase_add_test(tc1_1, sprintf_test_981);
    tcase_add_test(tc1_1, sprintf_test_982);
    tcase_add_test(tc1_1, sprintf_test_983);
    tcase_add_test(tc1_1, sprintf_test_984);
    tcase_add_test(tc1_1, sprintf_test_985);
    tcase_add_test(tc1_1, sprintf_test_986);
    tcase_add_test(tc1_1, sprintf_test_987);
    tcase_add_test(tc1_1, sprintf_test_988);
    tcase_add_test(tc1_1, sprintf_test_989);
    tcase_add_test(tc1_1, sprintf_test_990);
    tcase_add_test(tc1_1, sprintf_test_991);
    tcase_add_test(tc1_1, sprintf_test_992);
    tcase_add_test(tc1_1, sprintf_test_993);
    tcase_add_test(tc1_1, sprintf_test_994);
    tcase_add_test(tc1_1, sprintf_test_995);
    tcase_add_test(tc1_1, sprintf_test_996);
    tcase_add_test(tc1_1, sprintf_test_997);
    tcase_add_test(tc1_1, sprintf_test_998);
    tcase_add_test(tc1_1, sprintf_test_999);
    tcase_add_test(tc1_1, sprintf_test_1000);
    tcase_add_test(tc1_1, sprintf_test_1001);
    tcase_add_test(tc1_1, sprintf_test_1002);
    tcase_add_test(tc1_1, sprintf_test_1003);
    tcase_add_test(tc1_1, sprintf_test_1004);
    tcase_add_test(tc1_1, sprintf_test_1005);
    tcase_add_test(tc1_1, sprintf_test_1006);
    tcase_add_test(tc1_1, sprintf_test_1007);
    tcase_add_test(tc1_1, sprintf_test_1008);
    tcase_add_test(tc1_1, sprintf_test_1009);
    tcase_add_test(tc1_1, sprintf_test_1010);
    tcase_add_test(tc1_1, sprintf_test_1011);
    tcase_add_test(tc1_1, sprintf_test_1012);
    tcase_add_test(tc1_1, sprintf_test_1013);
    tcase_add_test(tc1_1, sprintf_test_1014);
    tcase_add_test(tc1_1, sprintf_test_1015);
    tcase_add_test(tc1_1, sprintf_test_1016);
    tcase_add_test(tc1_1, sprintf_test_1017);
    tcase_add_test(tc1_1, sprintf_test_1018);
    tcase_add_test(tc1_1, sprintf_test_1019);
    tcase_add_test(tc1_1, sprintf_test_1020);
    tcase_add_test(tc1_1, sprintf_test_1021);
    tcase_add_test(tc1_1, sprintf_test_1022);
    tcase_add_test(tc1_1, sprintf_test_1023);
    tcase_add_test(tc1_1, sprintf_test_1024);
    tcase_add_test(tc1_1, sprintf_test_1025);
    tcase_add_test(tc1_1, sprintf_test_1026);
    tcase_add_test(tc1_1, sprintf_test_1027);
    tcase_add_test(tc1_1, sprintf_test_1028);
    tcase_add_test(tc1_1, sprintf_test_1029);
    tcase_add_test(tc1_1, sprintf_test_1030);
    tcase_add_test(tc1_1, sprintf_test_1031);
    tcase_add_test(tc1_1, sprintf_test_1032);
    tcase_add_test(tc1_1, sprintf_test_1033);
    tcase_add_test(tc1_1, sprintf_test_1034);
    tcase_add_test(tc1_1, sprintf_test_1035);
    tcase_add_test(tc1_1, sprintf_test_1036);
    tcase_add_test(tc1_1, sprintf_test_1037);
    tcase_add_test(tc1_1, sprintf_test_1038);
    tcase_add_test(tc1_1, sprintf_test_1039);
    tcase_add_test(tc1_1, sprintf_test_1040);
    tcase_add_test(tc1_1, sprintf_test_1041);
    tcase_add_test(tc1_1, sprintf_test_1042);
    tcase_add_test(tc1_1, sprintf_test_1043);
    tcase_add_test(tc1_1, sprintf_test_1044);
    tcase_add_test(tc1_1, sprintf_test_1045);
    tcase_add_test(tc1_1, sprintf_test_1046);
    tcase_add_test(tc1_1, sprintf_test_1047);
    tcase_add_test(tc1_1, sprintf_test_1048);
    tcase_add_test(tc1_1, sprintf_test_1049);
    tcase_add_test(tc1_1, sprintf_test_1050);
    tcase_add_test(tc1_1, sprintf_test_1051);
    tcase_add_test(tc1_1, sprintf_test_1052);
    tcase_add_test(tc1_1, sprintf_test_1053);
    tcase_add_test(tc1_1, sprintf_test_1054);
    tcase_add_test(tc1_1, sprintf_test_1055);
    tcase_add_test(tc1_1, sprintf_test_1056);
    tcase_add_test(tc1_1, sprintf_test_1057);
    tcase_add_test(tc1_1, sprintf_test_1058);
    tcase_add_test(tc1_1, sprintf_test_1059);
    tcase_add_test(tc1_1, sprintf_test_1060);
    tcase_add_test(tc1_1, sprintf_test_1061);
    tcase_add_test(tc1_1, sprintf_test_1062);
    tcase_add_test(tc1_1, sprintf_test_1063);
    tcase_add_test(tc1_1, sprintf_test_1064);
    tcase_add_test(tc1_1, sprintf_test_1065);
    tcase_add_test(tc1_1, sprintf_test_1066);
    tcase_add_test(tc1_1, sprintf_test_1067);
    tcase_add_test(tc1_1, sprintf_test_1068);
    tcase_add_test(tc1_1, sprintf_test_1069);
    tcase_add_test(tc1_1, sprintf_test_1070);
    tcase_add_test(tc1_1, sprintf_test_1071);
    tcase_add_test(tc1_1, sprintf_test_1072);
    tcase_add_test(tc1_1, sprintf_test_1073);
    tcase_add_test(tc1_1, sprintf_test_1074);
    tcase_add_test(tc1_1, sprintf_test_1075);
    tcase_add_test(tc1_1, sprintf_test_1076);
    tcase_add_test(tc1_1, sprintf_test_1077);
    tcase_add_test(tc1_1, sprintf_test_1078);
    tcase_add_test(tc1_1, sprintf_test_1079);
    tcase_add_test(tc1_1, sprintf_test_1080);
    tcase_add_test(tc1_1, sprintf_test_1081);
    tcase_add_test(tc1_1, sprintf_test_1082);
    tcase_add_test(tc1_1, sprintf_test_1083);
    tcase_add_test(tc1_1, sprintf_test_1084);
    tcase_add_test(tc1_1, sprintf_test_1085);
    tcase_add_test(tc1_1, sprintf_test_1086);
    tcase_add_test(tc1_1, sprintf_test_1087);
    tcase_add_test(tc1_1, sprintf_test_1088);
    tcase_add_test(tc1_1, sprintf_test_1089);
    tcase_add_test(tc1_1, sprintf_test_1090);
    tcase_add_test(tc1_1, sprintf_test_1091);
    tcase_add_test(tc1_1, sprintf_test_1092);
    tcase_add_test(tc1_1, sprintf_test_1093);
    tcase_add_test(tc1_1, sprintf_test_1094);
    tcase_add_test(tc1_1, sprintf_test_1095);
    tcase_add_test(tc1_1, sprintf_test_1096);
    tcase_add_test(tc1_1, sprintf_test_1097);
    tcase_add_test(tc1_1, sprintf_test_1098);
    tcase_add_test(tc1_1, sprintf_test_1099);
    tcase_add_test(tc1_1, sprintf_test_1100);
    tcase_add_test(tc1_1, sprintf_test_1101);
    tcase_add_test(tc1_1, sprintf_test_1102);
    tcase_add_test(tc1_1, sprintf_test_1103);
    tcase_add_test(tc1_1, sprintf_test_1104);
    tcase_add_test(tc1_1, sprintf_test_1105);
    tcase_add_test(tc1_1, sprintf_test_1106);
    tcase_add_test(tc1_1, sprintf_test_1107);
    tcase_add_test(tc1_1, sprintf_test_1108);
    tcase_add_test(tc1_1, sprintf_test_1109);
    tcase_add_test(tc1_1, sprintf_test_1110);
    tcase_add_test(tc1_1, sprintf_test_1111);
    tcase_add_test(tc1_1, sprintf_test_1112);
    tcase_add_test(tc1_1, sprintf_test_1113);
    tcase_add_test(tc1_1, sprintf_test_1114);
    tcase_add_test(tc1_1, sprintf_test_1115);
    tcase_add_test(tc1_1, sprintf_test_1116);
    tcase_add_test(tc1_1, sprintf_test_1117);
    tcase_add_test(tc1_1, sprintf_test_1118);
    tcase_add_test(tc1_1, sprintf_test_1119);
    tcase_add_test(tc1_1, sprintf_test_1120);
    tcase_add_test(tc1_1, sprintf_test_1121);
    tcase_add_test(tc1_1, sprintf_test_1122);
    tcase_add_test(tc1_1, sprintf_test_1123);
    tcase_add_test(tc1_1, sprintf_test_1124);
    tcase_add_test(tc1_1, sprintf_test_1125);
    tcase_add_test(tc1_1, sprintf_test_1126);
    tcase_add_test(tc1_1, sprintf_test_1127);
    tcase_add_test(tc1_1, sprintf_test_1128);
    tcase_add_test(tc1_1, sprintf_test_1129);
    tcase_add_test(tc1_1, sprintf_test_1130);
    tcase_add_test(tc1_1, sprintf_test_1131);
    tcase_add_test(tc1_1, sprintf_test_1132);
    tcase_add_test(tc1_1, sprintf_test_1133);
    tcase_add_test(tc1_1, sprintf_test_1134);
    tcase_add_test(tc1_1, sprintf_test_1135);
    tcase_add_test(tc1_1, sprintf_test_1136);
    tcase_add_test(tc1_1, sprintf_test_1137);
    tcase_add_test(tc1_1, sprintf_test_1138);
    tcase_add_test(tc1_1, sprintf_test_1139);
    tcase_add_test(tc1_1, sprintf_test_1140);
    tcase_add_test(tc1_1, sprintf_test_1141);
    tcase_add_test(tc1_1, sprintf_test_1142);
    tcase_add_test(tc1_1, sprintf_test_1143);
    tcase_add_test(tc1_1, sprintf_test_1144);
    tcase_add_test(tc1_1, sprintf_test_1145);
    tcase_add_test(tc1_1, sprintf_test_1146);
    tcase_add_test(tc1_1, sprintf_test_1147);
    tcase_add_test(tc1_1, sprintf_test_1148);
    tcase_add_test(tc1_1, sprintf_test_1149);
    tcase_add_test(tc1_1, sprintf_test_1150);
    tcase_add_test(tc1_1, sprintf_test_1151);
    tcase_add_test(tc1_1, sprintf_test_1152);
    tcase_add_test(tc1_1, sprintf_test_1153);
    tcase_add_test(tc1_1, sprintf_test_1154);
    tcase_add_test(tc1_1, sprintf_test_1155);
    tcase_add_test(tc1_1, sprintf_test_1156);
    tcase_add_test(tc1_1, sprintf_test_1157);
    tcase_add_test(tc1_1, sprintf_test_1158);
    tcase_add_test(tc1_1, sprintf_test_1159);
    tcase_add_test(tc1_1, sprintf_test_1160);
    tcase_add_test(tc1_1, sprintf_test_1161);
    tcase_add_test(tc1_1, sprintf_test_1162);
    tcase_add_test(tc1_1, sprintf_test_1163);
    tcase_add_test(tc1_1, sprintf_test_1164);
    tcase_add_test(tc1_1, sprintf_test_1165);
    tcase_add_test(tc1_1, sprintf_test_1166);
    tcase_add_test(tc1_1, sprintf_test_1167);
    tcase_add_test(tc1_1, sprintf_test_1168);
    tcase_add_test(tc1_1, sprintf_test_1169);
    tcase_add_test(tc1_1, sprintf_test_1170);
    tcase_add_test(tc1_1, sprintf_test_1171);
    tcase_add_test(tc1_1, sprintf_test_1172);
    tcase_add_test(tc1_1, sprintf_test_1173);
    tcase_add_test(tc1_1, sprintf_test_1174);
    tcase_add_test(tc1_1, sprintf_test_1175);
    tcase_add_test(tc1_1, sprintf_test_1176);
    tcase_add_test(tc1_1, sprintf_test_1177);
    tcase_add_test(tc1_1, sprintf_test_1178);
    tcase_add_test(tc1_1, sprintf_test_1179);
    tcase_add_test(tc1_1, sprintf_test_1180);
    tcase_add_test(tc1_1, sprintf_test_1181);
    tcase_add_test(tc1_1, sprintf_test_1182);
    tcase_add_test(tc1_1, sprintf_test_1183);
    tcase_add_test(tc1_1, sprintf_test_1184);
    tcase_add_test(tc1_1, sprintf_test_1185);
    tcase_add_test(tc1_1, sprintf_test_1186);
    tcase_add_test(tc1_1, sprintf_test_1187);
    tcase_add_test(tc1_1, sprintf_test_1188);
    tcase_add_test(tc1_1, sprintf_test_1189);
    tcase_add_test(tc1_1, sprintf_test_1190);
    tcase_add_test(tc1_1, sprintf_test_1191);
    tcase_add_test(tc1_1, sprintf_test_1192);
    tcase_add_test(tc1_1, sprintf_test_1193);
    tcase_add_test(tc1_1, sprintf_test_1194);
    tcase_add_test(tc1_1, sprintf_test_1195);
    tcase_add_test(tc1_1, sprintf_test_1196);
    tcase_add_test(tc1_1, sprintf_test_1197);
    tcase_add_test(tc1_1, sprintf_test_1198);
    tcase_add_test(tc1_1, sprintf_test_1199);
    tcase_add_test(tc1_1, sprintf_test_1200);
    tcase_add_test(tc1_1, sprintf_test_1201);
    tcase_add_test(tc1_1, sprintf_test_1202);
    tcase_add_test(tc1_1, sprintf_test_1203);
    tcase_add_test(tc1_1, sprintf_test_1204);
    tcase_add_test(tc1_1, sprintf_test_1205);
    tcase_add_test(tc1_1, sprintf_test_1206);
    tcase_add_test(tc1_1, sprintf_test_1207);
    tcase_add_test(tc1_1, sprintf_test_1208);
    tcase_add_test(tc1_1, sprintf_test_1209);
    tcase_add_test(tc1_1, sprintf_test_1210);
    tcase_add_test(tc1_1, sprintf_test_1211);
    tcase_add_test(tc1_1, sprintf_test_1212);
    tcase_add_test(tc1_1, sprintf_test_1213);
    tcase_add_test(tc1_1, sprintf_test_1214);
    tcase_add_test(tc1_1, sprintf_test_1215);
    tcase_add_test(tc1_1, sprintf_test_1216);
    tcase_add_test(tc1_1, sprintf_test_1217);
    tcase_add_test(tc1_1, sprintf_test_1218);
    tcase_add_test(tc1_1, sprintf_test_1219);
    tcase_add_test(tc1_1, sprintf_test_1220);
    tcase_add_test(tc1_1, sprintf_test_1221);
    tcase_add_test(tc1_1, sprintf_test_1222);
    tcase_add_test(tc1_1, sprintf_test_1223);
    tcase_add_test(tc1_1, sprintf_test_1224);
    tcase_add_test(tc1_1, sprintf_test_1225);
    tcase_add_test(tc1_1, sprintf_test_1226);
    tcase_add_test(tc1_1, sprintf_test_1227);
    tcase_add_test(tc1_1, sprintf_test_1228);
    tcase_add_test(tc1_1, sprintf_test_1229);
    tcase_add_test(tc1_1, sprintf_test_1230);
    tcase_add_test(tc1_1, sprintf_test_1231);
    tcase_add_test(tc1_1, sprintf_test_1232);
    tcase_add_test(tc1_1, sprintf_test_1233);
    tcase_add_test(tc1_1, sprintf_test_1234);
    tcase_add_test(tc1_1, sprintf_test_1235);
    tcase_add_test(tc1_1, sprintf_test_1236);
    tcase_add_test(tc1_1, sprintf_test_1237);
    tcase_add_test(tc1_1, sprintf_test_1238);
    tcase_add_test(tc1_1, sprintf_test_1239);
    tcase_add_test(tc1_1, sprintf_test_1240);
    tcase_add_test(tc1_1, sprintf_test_1241);
    tcase_add_test(tc1_1, sprintf_test_1242);
    tcase_add_test(tc1_1, sprintf_test_1243);
    tcase_add_test(tc1_1, sprintf_test_1244);
    tcase_add_test(tc1_1, sprintf_test_1245);
    tcase_add_test(tc1_1, sprintf_test_1246);
    tcase_add_test(tc1_1, sprintf_test_1247);
    tcase_add_test(tc1_1, sprintf_test_1248);
    tcase_add_test(tc1_1, sprintf_test_1249);
    tcase_add_test(tc1_1, sprintf_test_1250);
    tcase_add_test(tc1_1, sprintf_test_1251);
    tcase_add_test(tc1_1, sprintf_test_1252);
    tcase_add_test(tc1_1, sprintf_test_1253);
    tcase_add_test(tc1_1, sprintf_test_1254);
    tcase_add_test(tc1_1, sprintf_test_1255);
    tcase_add_test(tc1_1, sprintf_test_1256);
    tcase_add_test(tc1_1, sprintf_test_1257);
    tcase_add_test(tc1_1, sprintf_test_1258);
    tcase_add_test(tc1_1, sprintf_test_1259);
    tcase_add_test(tc1_1, sprintf_test_1260);
    tcase_add_test(tc1_1, sprintf_test_1261);
    tcase_add_test(tc1_1, sprintf_test_1262);
    tcase_add_test(tc1_1, sprintf_test_1263);
    tcase_add_test(tc1_1, sprintf_test_1264);
    tcase_add_test(tc1_1, sprintf_test_1265);
    tcase_add_test(tc1_1, sprintf_test_1266);
    tcase_add_test(tc1_1, sprintf_test_1267);
    tcase_add_test(tc1_1, sprintf_test_1268);
    tcase_add_test(tc1_1, sprintf_test_1269);
    tcase_add_test(tc1_1, sprintf_test_1270);
    tcase_add_test(tc1_1, sprintf_test_1271);
    tcase_add_test(tc1_1, sprintf_test_1272);
    tcase_add_test(tc1_1, sprintf_test_1273);
    tcase_add_test(tc1_1, sprintf_test_1274);
    tcase_add_test(tc1_1, sprintf_test_1275);
    tcase_add_test(tc1_1, sprintf_test_1276);
    tcase_add_test(tc1_1, sprintf_test_1277);
    tcase_add_test(tc1_1, sprintf_test_1278);
    tcase_add_test(tc1_1, sprintf_test_1279);
    tcase_add_test(tc1_1, sprintf_test_1280);
    tcase_add_test(tc1_1, sprintf_test_1281);
    tcase_add_test(tc1_1, sprintf_test_1282);
    tcase_add_test(tc1_1, sprintf_test_1283);
    tcase_add_test(tc1_1, sprintf_test_1284);
    tcase_add_test(tc1_1, sprintf_test_1285);
    tcase_add_test(tc1_1, sprintf_test_1286);
    tcase_add_test(tc1_1, sprintf_test_1287);
    tcase_add_test(tc1_1, sprintf_test_1288);
    tcase_add_test(tc1_1, sprintf_test_1289);
    tcase_add_test(tc1_1, sprintf_test_1290);
    tcase_add_test(tc1_1, sprintf_test_1291);
    tcase_add_test(tc1_1, sprintf_test_1292);
    tcase_add_test(tc1_1, sprintf_test_1293);
    tcase_add_test(tc1_1, sprintf_test_1294);
    tcase_add_test(tc1_1, sprintf_test_1295);
    tcase_add_test(tc1_1, sprintf_test_1296);
    tcase_add_test(tc1_1, sprintf_test_1297);
    tcase_add_test(tc1_1, sprintf_test_1298);
    tcase_add_test(tc1_1, sprintf_test_1299);
    tcase_add_test(tc1_1, sprintf_test_1300);
    tcase_add_test(tc1_1, sprintf_test_1301);
    tcase_add_test(tc1_1, sprintf_test_1302);
    tcase_add_test(tc1_1, sprintf_test_1303);
    tcase_add_test(tc1_1, sprintf_test_1304);
    tcase_add_test(tc1_1, sprintf_test_1305);
    tcase_add_test(tc1_1, sprintf_test_1306);
    tcase_add_test(tc1_1, sprintf_test_1307);
    tcase_add_test(tc1_1, sprintf_test_1308);
    tcase_add_test(tc1_1, sprintf_test_1309);
    tcase_add_test(tc1_1, sprintf_test_1310);
    tcase_add_test(tc1_1, sprintf_test_1311);
    tcase_add_test(tc1_1, sprintf_test_1312);
    tcase_add_test(tc1_1, sprintf_test_1313);
    tcase_add_test(tc1_1, sprintf_test_1314);
    tcase_add_test(tc1_1, sprintf_test_1315);
    tcase_add_test(tc1_1, sprintf_test_1316);
    tcase_add_test(tc1_1, sprintf_test_1317);
    tcase_add_test(tc1_1, sprintf_test_1318);
    tcase_add_test(tc1_1, sprintf_test_1319);
    tcase_add_test(tc1_1, sprintf_test_1320);
    tcase_add_test(tc1_1, sprintf_test_1321);
    tcase_add_test(tc1_1, sprintf_test_1322);
    tcase_add_test(tc1_1, sprintf_test_1323);
    tcase_add_test(tc1_1, sprintf_test_1324);
    tcase_add_test(tc1_1, sprintf_test_1325);
    tcase_add_test(tc1_1, sprintf_test_1326);
    tcase_add_test(tc1_1, sprintf_test_1327);
    tcase_add_test(tc1_1, sprintf_test_1328);
    tcase_add_test(tc1_1, sprintf_test_1329);
    tcase_add_test(tc1_1, sprintf_test_1330);
    tcase_add_test(tc1_1, sprintf_test_1331);
    tcase_add_test(tc1_1, sprintf_test_1332);
    tcase_add_test(tc1_1, sprintf_test_1333);
    tcase_add_test(tc1_1, sprintf_test_1334);
    tcase_add_test(tc1_1, sprintf_test_1335);
    tcase_add_test(tc1_1, sprintf_test_1336);
    tcase_add_test(tc1_1, sprintf_test_1337);
    tcase_add_test(tc1_1, sprintf_test_1338);
    tcase_add_test(tc1_1, sprintf_test_1339);
    tcase_add_test(tc1_1, sprintf_test_1340);
    tcase_add_test(tc1_1, sprintf_test_1341);
    tcase_add_test(tc1_1, sprintf_test_1342);
    tcase_add_test(tc1_1, sprintf_test_1343);
    tcase_add_test(tc1_1, sprintf_test_1344);
    tcase_add_test(tc1_1, sprintf_test_1345);
    tcase_add_test(tc1_1, sprintf_test_1346);
    tcase_add_test(tc1_1, sprintf_test_1347);
    tcase_add_test(tc1_1, sprintf_test_1348);
    tcase_add_test(tc1_1, sprintf_test_1349);
    tcase_add_test(tc1_1, sprintf_test_1350);
    tcase_add_test(tc1_1, sprintf_test_1351);
    tcase_add_test(tc1_1, sprintf_test_1352);
    tcase_add_test(tc1_1, sprintf_test_1353);
    tcase_add_test(tc1_1, sprintf_test_1354);
    tcase_add_test(tc1_1, sprintf_test_1355);
    tcase_add_test(tc1_1, sprintf_test_1356);
    tcase_add_test(tc1_1, sprintf_test_1357);
    tcase_add_test(tc1_1, sprintf_test_1358);
    tcase_add_test(tc1_1, sprintf_test_1359);
    tcase_add_test(tc1_1, sprintf_test_1360);
    tcase_add_test(tc1_1, sprintf_test_1361);
    tcase_add_test(tc1_1, sprintf_test_1362);
    tcase_add_test(tc1_1, sprintf_test_1363);
    tcase_add_test(tc1_1, sprintf_test_1364);
    tcase_add_test(tc1_1, sprintf_test_1365);
    tcase_add_test(tc1_1, sprintf_test_1366);
    tcase_add_test(tc1_1, sprintf_test_1367);
    tcase_add_test(tc1_1, sprintf_test_1368);
    tcase_add_test(tc1_1, sprintf_test_1369);
    tcase_add_test(tc1_1, sprintf_test_1370);
    tcase_add_test(tc1_1, sprintf_test_1371);
    tcase_add_test(tc1_1, sprintf_test_1372);
    tcase_add_test(tc1_1, sprintf_test_1373);
    tcase_add_test(tc1_1, sprintf_test_1374);
    tcase_add_test(tc1_1, sprintf_test_1375);
    tcase_add_test(tc1_1, sprintf_test_1376);
    tcase_add_test(tc1_1, sprintf_test_1377);
    tcase_add_test(tc1_1, sprintf_test_1378);
    tcase_add_test(tc1_1, sprintf_test_1379);
    tcase_add_test(tc1_1, sprintf_test_1380);
    tcase_add_test(tc1_1, sprintf_test_1381);
    tcase_add_test(tc1_1, sprintf_test_1382);
    tcase_add_test(tc1_1, sprintf_test_1383);
    tcase_add_test(tc1_1, sprintf_test_1384);
    tcase_add_test(tc1_1, sprintf_test_1385);
    tcase_add_test(tc1_1, sprintf_test_1386);
    tcase_add_test(tc1_1, sprintf_test_1387);
    tcase_add_test(tc1_1, sprintf_test_1388);
    tcase_add_test(tc1_1, sprintf_test_1389);
    tcase_add_test(tc1_1, sprintf_test_1390);
    tcase_add_test(tc1_1, sprintf_test_1391);
    tcase_add_test(tc1_1, sprintf_test_1392);
    tcase_add_test(tc1_1, sprintf_test_1393);
    tcase_add_test(tc1_1, sprintf_test_1394);
    tcase_add_test(tc1_1, sprintf_test_1395);
    tcase_add_test(tc1_1, sprintf_test_1396);
    tcase_add_test(tc1_1, sprintf_test_1397);
    tcase_add_test(tc1_1, sprintf_test_1398);
    tcase_add_test(tc1_1, sprintf_test_1399);
    tcase_add_test(tc1_1, sprintf_test_1400);
    tcase_add_test(tc1_1, sprintf_test_1401);
    tcase_add_test(tc1_1, sprintf_test_1402);
    tcase_add_test(tc1_1, sprintf_test_1403);
    tcase_add_test(tc1_1, sprintf_test_1404);
    tcase_add_test(tc1_1, sprintf_test_1405);
    tcase_add_test(tc1_1, sprintf_test_1406);
    tcase_add_test(tc1_1, sprintf_test_1407);
    tcase_add_test(tc1_1, sprintf_test_1408);
    tcase_add_test(tc1_1, sprintf_test_1409);
    tcase_add_test(tc1_1, sprintf_test_1410);
    tcase_add_test(tc1_1, sprintf_test_1411);
    tcase_add_test(tc1_1, sprintf_test_1412);
    tcase_add_test(tc1_1, sprintf_test_1413);
    tcase_add_test(tc1_1, sprintf_test_1414);
    tcase_add_test(tc1_1, sprintf_test_1415);
    tcase_add_test(tc1_1, sprintf_test_1416);
    tcase_add_test(tc1_1, sprintf_test_1417);
    tcase_add_test(tc1_1, sprintf_test_1418);
    tcase_add_test(tc1_1, sprintf_test_1419);
    tcase_add_test(tc1_1, sprintf_test_1420);
    tcase_add_test(tc1_1, sprintf_test_1421);
    tcase_add_test(tc1_1, sprintf_test_1422);
    tcase_add_test(tc1_1, sprintf_test_1423);
    tcase_add_test(tc1_1, sprintf_test_1424);
    tcase_add_test(tc1_1, sprintf_test_1425);
    tcase_add_test(tc1_1, sprintf_test_1426);
    tcase_add_test(tc1_1, sprintf_test_1427);
    tcase_add_test(tc1_1, sprintf_test_1428);
    tcase_add_test(tc1_1, sprintf_test_1429);
    tcase_add_test(tc1_1, sprintf_test_1430);
    tcase_add_test(tc1_1, sprintf_test_1431);
    tcase_add_test(tc1_1, sprintf_test_1432);
    tcase_add_test(tc1_1, sprintf_test_1433);
    tcase_add_test(tc1_1, sprintf_test_1434);
    tcase_add_test(tc1_1, sprintf_test_1435);
    tcase_add_test(tc1_1, sprintf_test_1436);
    tcase_add_test(tc1_1, sprintf_test_1437);
    tcase_add_test(tc1_1, sprintf_test_1438);
    tcase_add_test(tc1_1, sprintf_test_1439);
    tcase_add_test(tc1_1, sprintf_test_1440);
    tcase_add_test(tc1_1, sprintf_test_1441);
    tcase_add_test(tc1_1, sprintf_test_1442);
    tcase_add_test(tc1_1, sprintf_test_1443);
    tcase_add_test(tc1_1, sprintf_test_1444);
    tcase_add_test(tc1_1, sprintf_test_1445);
    tcase_add_test(tc1_1, sprintf_test_1446);
    tcase_add_test(tc1_1, sprintf_test_1447);
    tcase_add_test(tc1_1, sprintf_test_1448);
    tcase_add_test(tc1_1, sprintf_test_1449);
    tcase_add_test(tc1_1, sprintf_test_1450);
    tcase_add_test(tc1_1, sprintf_test_1451);
    tcase_add_test(tc1_1, sprintf_test_1452);
    tcase_add_test(tc1_1, sprintf_test_1453);
    tcase_add_test(tc1_1, sprintf_test_1454);
    tcase_add_test(tc1_1, sprintf_test_1455);
    tcase_add_test(tc1_1, sprintf_test_1456);
    tcase_add_test(tc1_1, sprintf_test_1457);
    tcase_add_test(tc1_1, sprintf_test_1458);
    tcase_add_test(tc1_1, sprintf_test_1459);
    tcase_add_test(tc1_1, sprintf_test_1460);
    tcase_add_test(tc1_1, sprintf_test_1461);
    tcase_add_test(tc1_1, sprintf_test_1462);
    tcase_add_test(tc1_1, sprintf_test_1463);
    tcase_add_test(tc1_1, sprintf_test_1464);
    tcase_add_test(tc1_1, sprintf_test_1465);
    tcase_add_test(tc1_1, sprintf_test_1466);
    tcase_add_test(tc1_1, sprintf_test_1467);
    tcase_add_test(tc1_1, sprintf_test_1468);
    tcase_add_test(tc1_1, sprintf_test_1469);
    tcase_add_test(tc1_1, sprintf_test_1470);
    tcase_add_test(tc1_1, sprintf_test_1471);
    tcase_add_test(tc1_1, sprintf_test_1472);
    tcase_add_test(tc1_1, sprintf_test_1473);
    tcase_add_test(tc1_1, sprintf_test_1474);
    tcase_add_test(tc1_1, sprintf_test_1475);
    tcase_add_test(tc1_1, sprintf_test_1476);
    tcase_add_test(tc1_1, sprintf_test_1477);
    tcase_add_test(tc1_1, sprintf_test_1478);
    tcase_add_test(tc1_1, sprintf_test_1479);
    tcase_add_test(tc1_1, sprintf_test_1480);
    tcase_add_test(tc1_1, sprintf_test_1481);
    tcase_add_test(tc1_1, sprintf_test_1482);
    tcase_add_test(tc1_1, sprintf_test_1483);
    tcase_add_test(tc1_1, sprintf_test_1484);
    tcase_add_test(tc1_1, sprintf_test_1485);
    tcase_add_test(tc1_1, sprintf_test_1486);
    tcase_add_test(tc1_1, sprintf_test_1487);
    tcase_add_test(tc1_1, sprintf_test_1488);
    tcase_add_test(tc1_1, sprintf_test_1489);
    tcase_add_test(tc1_1, sprintf_test_1490);
    tcase_add_test(tc1_1, sprintf_test_1491);
    tcase_add_test(tc1_1, sprintf_test_1492);
    tcase_add_test(tc1_1, sprintf_test_1493);
    tcase_add_test(tc1_1, sprintf_test_1494);
    tcase_add_test(tc1_1, sprintf_test_1495);
    tcase_add_test(tc1_1, sprintf_test_1496);
    tcase_add_test(tc1_1, sprintf_test_1497);
    tcase_add_test(tc1_1, sprintf_test_1498);
    tcase_add_test(tc1_1, sprintf_test_1499);
    tcase_add_test(tc1_1, sprintf_test_1500);
    tcase_add_test(tc1_1, sprintf_test_1501);
    tcase_add_test(tc1_1, sprintf_test_1502);
    tcase_add_test(tc1_1, sprintf_test_1503);
    tcase_add_test(tc1_1, sprintf_test_1504);
    tcase_add_test(tc1_1, sprintf_test_1505);
    tcase_add_test(tc1_1, sprintf_test_1506);
    tcase_add_test(tc1_1, sprintf_test_1507);
    tcase_add_test(tc1_1, sprintf_test_1508);
    tcase_add_test(tc1_1, sprintf_test_1509);
    tcase_add_test(tc1_1, sprintf_test_1510);
    tcase_add_test(tc1_1, sprintf_test_1511);
    tcase_add_test(tc1_1, sprintf_test_1512);
    tcase_add_test(tc1_1, sprintf_test_1513);
    tcase_add_test(tc1_1, sprintf_test_1514);
    tcase_add_test(tc1_1, sprintf_test_1515);
    tcase_add_test(tc1_1, sprintf_test_1516);
    tcase_add_test(tc1_1, sprintf_test_1517);
    tcase_add_test(tc1_1, sprintf_test_1518);
    tcase_add_test(tc1_1, sprintf_test_1519);
    tcase_add_test(tc1_1, sprintf_test_1520);
    tcase_add_test(tc1_1, sprintf_test_1521);
    tcase_add_test(tc1_1, sprintf_test_1522);
    tcase_add_test(tc1_1, sprintf_test_1523);
    tcase_add_test(tc1_1, sprintf_test_1524);
    tcase_add_test(tc1_1, sprintf_test_1525);
    tcase_add_test(tc1_1, sprintf_test_1526);
    tcase_add_test(tc1_1, sprintf_test_1527);
    tcase_add_test(tc1_1, sprintf_test_1528);
    tcase_add_test(tc1_1, sprintf_test_1529);
    tcase_add_test(tc1_1, sprintf_test_1530);
    tcase_add_test(tc1_1, sprintf_test_1531);
    tcase_add_test(tc1_1, sprintf_test_1532);
    tcase_add_test(tc1_1, sprintf_test_1533);
    tcase_add_test(tc1_1, sprintf_test_1534);
    tcase_add_test(tc1_1, sprintf_test_1535);
    tcase_add_test(tc1_1, sprintf_test_1536);
    tcase_add_test(tc1_1, sprintf_test_1537);
    tcase_add_test(tc1_1, sprintf_test_1538);
    tcase_add_test(tc1_1, sprintf_test_1539);
    tcase_add_test(tc1_1, sprintf_test_1540);
    tcase_add_test(tc1_1, sprintf_test_1541);
    tcase_add_test(tc1_1, sprintf_test_1542);
    tcase_add_test(tc1_1, sprintf_test_1543);
    tcase_add_test(tc1_1, sprintf_test_1544);
    tcase_add_test(tc1_1, sprintf_test_1545);
    tcase_add_test(tc1_1, sprintf_test_1546);
    tcase_add_test(tc1_1, sprintf_test_1547);
    tcase_add_test(tc1_1, sprintf_test_1548);
    tcase_add_test(tc1_1, sprintf_test_1549);
    tcase_add_test(tc1_1, sprintf_test_1550);
    tcase_add_test(tc1_1, sprintf_test_1551);
    tcase_add_test(tc1_1, sprintf_test_1552);
    tcase_add_test(tc1_1, sprintf_test_1553);
    tcase_add_test(tc1_1, sprintf_test_1554);
    tcase_add_test(tc1_1, sprintf_test_1555);
    tcase_add_test(tc1_1, sprintf_test_1556);
    tcase_add_test(tc1_1, sprintf_test_1557);
    tcase_add_test(tc1_1, sprintf_test_1558);
    tcase_add_test(tc1_1, sprintf_test_1559);
    tcase_add_test(tc1_1, sprintf_test_1560);
    tcase_add_test(tc1_1, sprintf_test_1561);
    tcase_add_test(tc1_1, sprintf_test_1562);
    tcase_add_test(tc1_1, sprintf_test_1563);
    tcase_add_test(tc1_1, sprintf_test_1564);
    tcase_add_test(tc1_1, sprintf_test_1565);
    tcase_add_test(tc1_1, sprintf_test_1566);
    tcase_add_test(tc1_1, sprintf_test_1567);
    tcase_add_test(tc1_1, sprintf_test_1568);
    tcase_add_test(tc1_1, sprintf_test_1569);
    tcase_add_test(tc1_1, sprintf_test_1570);
    tcase_add_test(tc1_1, sprintf_test_1571);
    tcase_add_test(tc1_1, sprintf_test_1572);
    tcase_add_test(tc1_1, sprintf_test_1573);
    tcase_add_test(tc1_1, sprintf_test_1574);
    tcase_add_test(tc1_1, sprintf_test_1575);
    tcase_add_test(tc1_1, sprintf_test_1576);
    tcase_add_test(tc1_1, sprintf_test_1577);
    tcase_add_test(tc1_1, sprintf_test_1578);
    tcase_add_test(tc1_1, sprintf_test_1579);
    tcase_add_test(tc1_1, sprintf_test_1580);
    tcase_add_test(tc1_1, sprintf_test_1581);
    tcase_add_test(tc1_1, sprintf_test_1582);
    tcase_add_test(tc1_1, sprintf_test_1583);
    tcase_add_test(tc1_1, sprintf_test_1584);
    tcase_add_test(tc1_1, sprintf_test_1585);
    tcase_add_test(tc1_1, sprintf_test_1586);
    tcase_add_test(tc1_1, sprintf_test_1587);
    tcase_add_test(tc1_1, sprintf_test_1588);
    tcase_add_test(tc1_1, sprintf_test_1589);
    tcase_add_test(tc1_1, sprintf_test_1590);
    tcase_add_test(tc1_1, sprintf_test_1591);
    tcase_add_test(tc1_1, sprintf_test_1592);
    tcase_add_test(tc1_1, sprintf_test_1593);
    tcase_add_test(tc1_1, sprintf_test_1594);
    tcase_add_test(tc1_1, sprintf_test_1595);
    tcase_add_test(tc1_1, sprintf_test_1596);
    tcase_add_test(tc1_1, sprintf_test_1597);
    tcase_add_test(tc1_1, sprintf_test_1598);
    tcase_add_test(tc1_1, sprintf_test_1599);
    tcase_add_test(tc1_1, sprintf_test_1600);
    tcase_add_test(tc1_1, sprintf_test_1601);
    tcase_add_test(tc1_1, sprintf_test_1602);
    tcase_add_test(tc1_1, sprintf_test_1603);
    tcase_add_test(tc1_1, sprintf_test_1604);
    tcase_add_test(tc1_1, sprintf_test_1605);
    tcase_add_test(tc1_1, sprintf_test_1606);
    tcase_add_test(tc1_1, sprintf_test_1607);
    tcase_add_test(tc1_1, sprintf_test_1608);
    tcase_add_test(tc1_1, sprintf_test_1609);
    tcase_add_test(tc1_1, sprintf_test_1610);
    tcase_add_test(tc1_1, sprintf_test_1611);
    tcase_add_test(tc1_1, sprintf_test_1612);
    tcase_add_test(tc1_1, sprintf_test_1613);
    tcase_add_test(tc1_1, sprintf_test_1614);
    tcase_add_test(tc1_1, sprintf_test_1615);
    tcase_add_test(tc1_1, sprintf_test_1616);
    tcase_add_test(tc1_1, sprintf_test_1617);
    tcase_add_test(tc1_1, sprintf_test_1618);
    tcase_add_test(tc1_1, sprintf_test_1619);
    tcase_add_test(tc1_1, sprintf_test_1620);
    tcase_add_test(tc1_1, sprintf_test_1621);
    tcase_add_test(tc1_1, sprintf_test_1622);
    tcase_add_test(tc1_1, sprintf_test_1623);
    tcase_add_test(tc1_1, sprintf_test_1624);
    tcase_add_test(tc1_1, sprintf_test_1625);
    tcase_add_test(tc1_1, sprintf_test_1626);
    tcase_add_test(tc1_1, sprintf_test_1627);
    tcase_add_test(tc1_1, sprintf_test_1628);
    tcase_add_test(tc1_1, sprintf_test_1629);
    tcase_add_test(tc1_1, sprintf_test_1630);
    tcase_add_test(tc1_1, sprintf_test_1631);
    tcase_add_test(tc1_1, sprintf_test_1632);
    tcase_add_test(tc1_1, sprintf_test_1633);
    tcase_add_test(tc1_1, sprintf_test_1634);
    tcase_add_test(tc1_1, sprintf_test_1635);
    tcase_add_test(tc1_1, sprintf_test_1636);
    tcase_add_test(tc1_1, sprintf_test_1637);
    tcase_add_test(tc1_1, sprintf_test_1638);
    tcase_add_test(tc1_1, sprintf_test_1639);
    tcase_add_test(tc1_1, sprintf_test_1640);
    tcase_add_test(tc1_1, sprintf_test_1641);
    tcase_add_test(tc1_1, sprintf_test_1642);
    tcase_add_test(tc1_1, sprintf_test_1643);
    tcase_add_test(tc1_1, sprintf_test_1644);
    tcase_add_test(tc1_1, sprintf_test_1645);
    tcase_add_test(tc1_1, sprintf_test_1646);
    tcase_add_test(tc1_1, sprintf_test_1647);
    tcase_add_test(tc1_1, sprintf_test_1648);
    tcase_add_test(tc1_1, sprintf_test_1649);
    tcase_add_test(tc1_1, sprintf_test_1650);
    tcase_add_test(tc1_1, sprintf_test_1651);
    tcase_add_test(tc1_1, sprintf_test_1652);
    tcase_add_test(tc1_1, sprintf_test_1653);
    tcase_add_test(tc1_1, sprintf_test_1654);
    tcase_add_test(tc1_1, sprintf_test_1655);
    tcase_add_test(tc1_1, sprintf_test_1656);
    tcase_add_test(tc1_1, sprintf_test_1657);
    tcase_add_test(tc1_1, sprintf_test_1658);
    tcase_add_test(tc1_1, sprintf_test_1659);
    tcase_add_test(tc1_1, sprintf_test_1660);
    tcase_add_test(tc1_1, sprintf_test_1661);
    tcase_add_test(tc1_1, sprintf_test_1662);
    tcase_add_test(tc1_1, sprintf_test_1663);
    tcase_add_test(tc1_1, sprintf_test_1664);
    tcase_add_test(tc1_1, sprintf_test_1665);
    tcase_add_test(tc1_1, sprintf_test_1666);
    tcase_add_test(tc1_1, sprintf_test_1667);
    tcase_add_test(tc1_1, sprintf_test_1668);
    tcase_add_test(tc1_1, sprintf_test_1669);
    tcase_add_test(tc1_1, sprintf_test_1670);
    tcase_add_test(tc1_1, sprintf_test_1671);
    tcase_add_test(tc1_1, sprintf_test_1672);
    tcase_add_test(tc1_1, sprintf_test_1673);
    tcase_add_test(tc1_1, sprintf_test_1674);
    tcase_add_test(tc1_1, sprintf_test_1675);
    tcase_add_test(tc1_1, sprintf_test_1676);
    tcase_add_test(tc1_1, sprintf_test_1677);
    tcase_add_test(tc1_1, sprintf_test_1678);
    tcase_add_test(tc1_1, sprintf_test_1679);
    tcase_add_test(tc1_1, sprintf_test_1680);
    tcase_add_test(tc1_1, sprintf_test_1681);
    tcase_add_test(tc1_1, sprintf_test_1682);
    tcase_add_test(tc1_1, sprintf_test_1683);
    tcase_add_test(tc1_1, sprintf_test_1684);
    tcase_add_test(tc1_1, sprintf_test_1685);
    tcase_add_test(tc1_1, sprintf_test_1686);
    tcase_add_test(tc1_1, sprintf_test_1687);
    tcase_add_test(tc1_1, sprintf_test_1688);
    tcase_add_test(tc1_1, sprintf_test_1689);
    tcase_add_test(tc1_1, sprintf_test_1690);
    tcase_add_test(tc1_1, sprintf_test_1691);
    tcase_add_test(tc1_1, sprintf_test_1692);
    tcase_add_test(tc1_1, sprintf_test_1693);
    tcase_add_test(tc1_1, sprintf_test_1694);
    tcase_add_test(tc1_1, sprintf_test_1695);
    tcase_add_test(tc1_1, sprintf_test_1696);
    tcase_add_test(tc1_1, sprintf_test_1697);
    tcase_add_test(tc1_1, sprintf_test_1698);
    tcase_add_test(tc1_1, sprintf_test_1699);
    tcase_add_test(tc1_1, sprintf_test_1700);
    tcase_add_test(tc1_1, sprintf_test_1701);
    tcase_add_test(tc1_1, sprintf_test_1702);
    tcase_add_test(tc1_1, sprintf_test_1703);
    tcase_add_test(tc1_1, sprintf_test_1704);
    tcase_add_test(tc1_1, sprintf_test_1705);
    tcase_add_test(tc1_1, sprintf_test_1706);
    tcase_add_test(tc1_1, sprintf_test_1707);
    tcase_add_test(tc1_1, sprintf_test_1708);
    tcase_add_test(tc1_1, sprintf_test_1709);
    tcase_add_test(tc1_1, sprintf_test_1710);
    tcase_add_test(tc1_1, sprintf_test_1711);
    tcase_add_test(tc1_1, sprintf_test_1712);
    tcase_add_test(tc1_1, sprintf_test_1713);
    tcase_add_test(tc1_1, sprintf_test_1714);
    tcase_add_test(tc1_1, sprintf_test_1715);
    tcase_add_test(tc1_1, sprintf_test_1716);
    tcase_add_test(tc1_1, sprintf_test_1717);
    tcase_add_test(tc1_1, sprintf_test_1718);
    tcase_add_test(tc1_1, sprintf_test_1719);
    tcase_add_test(tc1_1, sprintf_test_1720);
    tcase_add_test(tc1_1, sprintf_test_1721);
    tcase_add_test(tc1_1, sprintf_test_1722);
    tcase_add_test(tc1_1, sprintf_test_1723);
    tcase_add_test(tc1_1, sprintf_test_1724);
    tcase_add_test(tc1_1, sprintf_test_1725);
    tcase_add_test(tc1_1, sprintf_test_1726);
    tcase_add_test(tc1_1, sprintf_test_1727);
    tcase_add_test(tc1_1, sprintf_test_1728);
    tcase_add_test(tc1_1, sprintf_test_1729);
    tcase_add_test(tc1_1, sprintf_test_1730);
    tcase_add_test(tc1_1, sprintf_test_1731);
    tcase_add_test(tc1_1, sprintf_test_1732);
    tcase_add_test(tc1_1, sprintf_test_1733);
    tcase_add_test(tc1_1, sprintf_test_1734);
    tcase_add_test(tc1_1, sprintf_test_1735);
    tcase_add_test(tc1_1, sprintf_test_1736);
    tcase_add_test(tc1_1, sprintf_test_1737);
    tcase_add_test(tc1_1, sprintf_test_1738);
    tcase_add_test(tc1_1, sprintf_test_1739);
    tcase_add_test(tc1_1, sprintf_test_1740);
    tcase_add_test(tc1_1, sprintf_test_1741);
    tcase_add_test(tc1_1, sprintf_test_1742);
    tcase_add_test(tc1_1, sprintf_test_1743);
    tcase_add_test(tc1_1, sprintf_test_1744);
    tcase_add_test(tc1_1, sprintf_test_1745);
    tcase_add_test(tc1_1, sprintf_test_1746);
    tcase_add_test(tc1_1, sprintf_test_1747);
    tcase_add_test(tc1_1, sprintf_test_1748);
    tcase_add_test(tc1_1, sprintf_test_1749);
    tcase_add_test(tc1_1, sprintf_test_1750);
    tcase_add_test(tc1_1, sprintf_test_1751);
    tcase_add_test(tc1_1, sprintf_test_1752);
    tcase_add_test(tc1_1, sprintf_test_1753);
    tcase_add_test(tc1_1, sprintf_test_1754);
    tcase_add_test(tc1_1, sprintf_test_1755);
    tcase_add_test(tc1_1, sprintf_test_1756);
    tcase_add_test(tc1_1, sprintf_test_1757);
    tcase_add_test(tc1_1, sprintf_test_1758);
    tcase_add_test(tc1_1, sprintf_test_1759);
    tcase_add_test(tc1_1, sprintf_test_1760);
    tcase_add_test(tc1_1, sprintf_test_1761);
    tcase_add_test(tc1_1, sprintf_test_1762);
    tcase_add_test(tc1_1, sprintf_test_1763);
    tcase_add_test(tc1_1, sprintf_test_1764);
    tcase_add_test(tc1_1, sprintf_test_1765);
    tcase_add_test(tc1_1, sprintf_test_1766);
    tcase_add_test(tc1_1, sprintf_test_1767);
    tcase_add_test(tc1_1, sprintf_test_1768);
    tcase_add_test(tc1_1, sprintf_test_1769);
    tcase_add_test(tc1_1, sprintf_test_1770);
    tcase_add_test(tc1_1, sprintf_test_1771);
    tcase_add_test(tc1_1, sprintf_test_1772);
    tcase_add_test(tc1_1, sprintf_test_1773);
    tcase_add_test(tc1_1, sprintf_test_1774);
    tcase_add_test(tc1_1, sprintf_test_1775);
    tcase_add_test(tc1_1, sprintf_test_1776);
    tcase_add_test(tc1_1, sprintf_test_1777);
    tcase_add_test(tc1_1, sprintf_test_1778);
    tcase_add_test(tc1_1, sprintf_test_1779);
    tcase_add_test(tc1_1, sprintf_test_1780);
    tcase_add_test(tc1_1, sprintf_test_1781);
    tcase_add_test(tc1_1, sprintf_test_1782);
    tcase_add_test(tc1_1, sprintf_test_1783);
    tcase_add_test(tc1_1, sprintf_test_1784);
    tcase_add_test(tc1_1, sprintf_test_1785);
    tcase_add_test(tc1_1, sprintf_test_1786);
    tcase_add_test(tc1_1, sprintf_test_1787);
    tcase_add_test(tc1_1, sprintf_test_1788);
    tcase_add_test(tc1_1, sprintf_test_1789);
    tcase_add_test(tc1_1, sprintf_test_1790);
    tcase_add_test(tc1_1, sprintf_test_1791);
    tcase_add_test(tc1_1, sprintf_test_1792);
    tcase_add_test(tc1_1, sprintf_test_1793);
    tcase_add_test(tc1_1, sprintf_test_1794);
    tcase_add_test(tc1_1, sprintf_test_1795);
    tcase_add_test(tc1_1, sprintf_test_1796);
    tcase_add_test(tc1_1, sprintf_test_1797);
    tcase_add_test(tc1_1, sprintf_test_1798);
    tcase_add_test(tc1_1, sprintf_test_1799);
    tcase_add_test(tc1_1, sprintf_test_1800);
    tcase_add_test(tc1_1, sprintf_test_1801);
    tcase_add_test(tc1_1, sprintf_test_1802);
    tcase_add_test(tc1_1, sprintf_test_1803);
    tcase_add_test(tc1_1, sprintf_test_1804);
    tcase_add_test(tc1_1, sprintf_test_1805);
    tcase_add_test(tc1_1, sprintf_test_1806);
    tcase_add_test(tc1_1, sprintf_test_1807);
    tcase_add_test(tc1_1, sprintf_test_1808);
    tcase_add_test(tc1_1, sprintf_test_1809);
    tcase_add_test(tc1_1, sprintf_test_1810);
    tcase_add_test(tc1_1, sprintf_test_1811);
    tcase_add_test(tc1_1, sprintf_test_1812);
    tcase_add_test(tc1_1, sprintf_test_1813);
    tcase_add_test(tc1_1, sprintf_test_1814);
    tcase_add_test(tc1_1, sprintf_test_1815);
    tcase_add_test(tc1_1, sprintf_test_1816);
    tcase_add_test(tc1_1, sprintf_test_1817);
    tcase_add_test(tc1_1, sprintf_test_1818);
    tcase_add_test(tc1_1, sprintf_test_1819);
    tcase_add_test(tc1_1, sprintf_test_1821);
    tcase_add_test(tc1_1, sprintf_test_1822);
    tcase_add_test(tc1_1, sprintf_test_1823);
    tcase_add_test(tc1_1, sprintf_test_1824);
    tcase_add_test(tc1_1, sprintf_test_1825);
    tcase_add_test(tc1_1, sprintf_test_1826);
    tcase_add_test(tc1_1, sprintf_test_1827);
    tcase_add_test(tc1_1, sprintf_test_1828);
    tcase_add_test(tc1_1, sprintf_test_1830);
    tcase_add_test(tc1_1, sprintf_test_1831);
    tcase_add_test(tc1_1, sprintf_test_1832);
    tcase_add_test(tc1_1, sprintf_test_1833);
    tcase_add_test(tc1_1, sprintf_test_1834);
    tcase_add_test(tc1_1, sprintf_test_1835);
    tcase_add_test(tc1_1, sprintf_test_1836);
    tcase_add_test(tc1_1, sprintf_test_1837);
    tcase_add_test(tc1_1, sprintf_test_1838);
    tcase_add_test(tc1_1, sprintf_test_1839);
    tcase_add_test(tc1_1, sprintf_test_1840);
    tcase_add_test(tc1_1, sprintf_test_1841);
    tcase_add_test(tc1_1, sprintf_test_1842);
    tcase_add_test(tc1_1, sprintf_test_1843);
    tcase_add_test(tc1_1, sprintf_test_1844);
    tcase_add_test(tc1_1, sprintf_test_1845);
    tcase_add_test(tc1_1, sprintf_test_1846);
    tcase_add_test(tc1_1, sprintf_test_1847);
    tcase_add_test(tc1_1, sprintf_test_1848);
    tcase_add_test(tc1_1, sprintf_test_1849);
    tcase_add_test(tc1_1, sprintf_test_1850);
    tcase_add_test(tc1_1, sprintf_test_1851);
    tcase_add_test(tc1_1, sprintf_test_1852);
    tcase_add_test(tc1_1, sprintf_test_1853);
    tcase_add_test(tc1_1, sprintf_test_1854);
    tcase_add_test(tc1_1, sprintf_test_1855);
    tcase_add_test(tc1_1, sprintf_test_1856);
    tcase_add_test(tc1_1, sprintf_test_1857);
    tcase_add_test(tc1_1, sprintf_test_1858);
    tcase_add_test(tc1_1, sprintf_test_1859);
    tcase_add_test(tc1_1, sprintf_test_1860);
    tcase_add_test(tc1_1, sprintf_test_1861);
    tcase_add_test(tc1_1, sprintf_test_1862);
    tcase_add_test(tc1_1, sprintf_test_1863);
    tcase_add_test(tc1_1, sprintf_test_1864);
    tcase_add_test(tc1_1, sprintf_test_1865);
    tcase_add_test(tc1_1, sprintf_test_1866);
    tcase_add_test(tc1_1, sprintf_test_1867);
    tcase_add_test(tc1_1, sprintf_test_1868);
    tcase_add_test(tc1_1, sprintf_test_1869);
    tcase_add_test(tc1_1, sprintf_test_1870);
    tcase_add_test(tc1_1, sprintf_test_1871);
    tcase_add_test(tc1_1, sprintf_test_1872);
    tcase_add_test(tc1_1, sprintf_test_1873);
    tcase_add_test(tc1_1, sprintf_test_1874);
    tcase_add_test(tc1_1, sprintf_test_1875);
    tcase_add_test(tc1_1, sprintf_test_1876);
    tcase_add_test(tc1_1, sprintf_test_1877);
    tcase_add_test(tc1_1, sprintf_test_1878);
    tcase_add_test(tc1_1, sprintf_test_1879);
    tcase_add_test(tc1_1, sprintf_test_1880);
    tcase_add_test(tc1_1, sprintf_test_1881);
    tcase_add_test(tc1_1, sprintf_test_1882);
    tcase_add_test(tc1_1, sprintf_test_1883);
    tcase_add_test(tc1_1, sprintf_test_1884);
    tcase_add_test(tc1_1, sprintf_test_1885);
    tcase_add_test(tc1_1, sprintf_test_1886);
    tcase_add_test(tc1_1, sprintf_test_1887);
    tcase_add_test(tc1_1, sprintf_test_1888);
    tcase_add_test(tc1_1, sprintf_test_1889);
    tcase_add_test(tc1_1, sprintf_test_1890);
    tcase_add_test(tc1_1, sprintf_test_1891);
    tcase_add_test(tc1_1, sprintf_test_1892);
    tcase_add_test(tc1_1, sprintf_test_1893);
    tcase_add_test(tc1_1, sprintf_test_1894);
    tcase_add_test(tc1_1, sprintf_test_1895);
    tcase_add_test(tc1_1, sprintf_test_1896);
    tcase_add_test(tc1_1, sprintf_test_1897);
    tcase_add_test(tc1_1, sprintf_test_1898);
    tcase_add_test(tc1_1, sprintf_test_1899);
    tcase_add_test(tc1_1, sprintf_test_1900);
    tcase_add_test(tc1_1, sprintf_test_1901);
    tcase_add_test(tc1_1, sprintf_test_1902);
    tcase_add_test(tc1_1, sprintf_test_1903);
    tcase_add_test(tc1_1, sprintf_test_1904);
    tcase_add_test(tc1_1, sprintf_test_1905);
    tcase_add_test(tc1_1, sprintf_test_1906);
    tcase_add_test(tc1_1, sprintf_test_1907);
    tcase_add_test(tc1_1, sprintf_test_1908);
    tcase_add_test(tc1_1, sprintf_test_1909);
    tcase_add_test(tc1_1, sprintf_test_1910);
    tcase_add_test(tc1_1, sprintf_test_1911);
    tcase_add_test(tc1_1, sprintf_test_1912);
    tcase_add_test(tc1_1, sprintf_test_1913);
    tcase_add_test(tc1_1, sprintf_test_1914);
    tcase_add_test(tc1_1, sprintf_test_1915);
    tcase_add_test(tc1_1, sprintf_test_1916);
    tcase_add_test(tc1_1, sprintf_test_1917);
    tcase_add_test(tc1_1, sprintf_test_1918);
    tcase_add_test(tc1_1, sprintf_test_1919);
    tcase_add_test(tc1_1, sprintf_test_1920);
    tcase_add_test(tc1_1, sprintf_test_1921);
    tcase_add_test(tc1_1, sprintf_test_1922);
    tcase_add_test(tc1_1, sprintf_test_1923);
    tcase_add_test(tc1_1, sprintf_test_1924);
    tcase_add_test(tc1_1, sprintf_test_1925);
    tcase_add_test(tc1_1, sprintf_test_1926);
    tcase_add_test(tc1_1, sprintf_test_1927);
    tcase_add_test(tc1_1, sprintf_test_1928);
    tcase_add_test(tc1_1, sprintf_test_1929);
    tcase_add_test(tc1_1, sprintf_test_1930);
    tcase_add_test(tc1_1, sprintf_test_1931);
    tcase_add_test(tc1_1, sprintf_test_1932);
    tcase_add_test(tc1_1, sprintf_test_1933);
    tcase_add_test(tc1_1, sprintf_test_1934);
    tcase_add_test(tc1_1, sprintf_test_1935);
    tcase_add_test(tc1_1, sprintf_test_1936);
    tcase_add_test(tc1_1, sprintf_test_1937);
    tcase_add_test(tc1_1, sprintf_test_1938);
    tcase_add_test(tc1_1, sprintf_test_1939);
    tcase_add_test(tc1_1, sprintf_test_1940);
    tcase_add_test(tc1_1, sprintf_test_1941);
    tcase_add_test(tc1_1, sprintf_test_1942);
    tcase_add_test(tc1_1, sprintf_test_1943);
    tcase_add_test(tc1_1, sprintf_test_1944);
    tcase_add_test(tc1_1, sprintf_test_1945);
    tcase_add_test(tc1_1, sprintf_test_1946);
    tcase_add_test(tc1_1, sprintf_test_1947);
    tcase_add_test(tc1_1, sprintf_test_1948);
    tcase_add_test(tc1_1, sprintf_test_1949);
    tcase_add_test(tc1_1, sprintf_test_1950);
    tcase_add_test(tc1_1, sprintf_test_1951);
    tcase_add_test(tc1_1, sprintf_test_1952);
    tcase_add_test(tc1_1, sprintf_test_1953);
    tcase_add_test(tc1_1, sprintf_test_1954);
    tcase_add_test(tc1_1, sprintf_test_1955);
    tcase_add_test(tc1_1, sprintf_test_1956);
    tcase_add_test(tc1_1, sprintf_test_1957);
    tcase_add_test(tc1_1, sprintf_test_1958);
    tcase_add_test(tc1_1, sprintf_test_1959);
    tcase_add_test(tc1_1, sprintf_test_1960);
    tcase_add_test(tc1_1, sprintf_test_1961);
    tcase_add_test(tc1_1, sprintf_test_1962);
    tcase_add_test(tc1_1, sprintf_test_1963);
    tcase_add_test(tc1_1, sprintf_test_1964);
    tcase_add_test(tc1_1, sprintf_test_1965);
    tcase_add_test(tc1_1, sprintf_test_1966);
    tcase_add_test(tc1_1, sprintf_test_1967);
    tcase_add_test(tc1_1, sprintf_test_1968);
    tcase_add_test(tc1_1, sprintf_test_1969);
    tcase_add_test(tc1_1, sprintf_test_1970);
    tcase_add_test(tc1_1, sprintf_test_1971);
    tcase_add_test(tc1_1, sprintf_test_1972);
    tcase_add_test(tc1_1, sprintf_test_1973);
    tcase_add_test(tc1_1, sprintf_test_1974);
    tcase_add_test(tc1_1, sprintf_test_1975);
    tcase_add_test(tc1_1, sprintf_test_1976);
    tcase_add_test(tc1_1, sprintf_test_1977);
    tcase_add_test(tc1_1, sprintf_test_1978);
    tcase_add_test(tc1_1, sprintf_test_1979);
    tcase_add_test(tc1_1, sprintf_test_1980);
    tcase_add_test(tc1_1, sprintf_test_1981);
    tcase_add_test(tc1_1, sprintf_test_1982);
    tcase_add_test(tc1_1, sprintf_test_1983);
    tcase_add_test(tc1_1, sprintf_test_1984);
    tcase_add_test(tc1_1, sprintf_test_1985);
    tcase_add_test(tc1_1, sprintf_test_1986);
    tcase_add_test(tc1_1, sprintf_test_1987);
    tcase_add_test(tc1_1, sprintf_test_1988);
    tcase_add_test(tc1_1, sprintf_test_1989);
    tcase_add_test(tc1_1, sprintf_test_1990);
    tcase_add_test(tc1_1, sprintf_test_1991);
    tcase_add_test(tc1_1, sprintf_test_1992);
    tcase_add_test(tc1_1, sprintf_test_1993);
    tcase_add_test(tc1_1, sprintf_test_1994);
    tcase_add_test(tc1_1, sprintf_test_1995);
    tcase_add_test(tc1_1, sprintf_test_1996);
    tcase_add_test(tc1_1, sprintf_test_1997);
    tcase_add_test(tc1_1, sprintf_test_1998);
    tcase_add_test(tc1_1, sprintf_test_1999);
    tcase_add_test(tc1_1, sprintf_test_2000);
    tcase_add_test(tc1_1, sprintf_test_2001);
    tcase_add_test(tc1_1, sprintf_test_2002);
    tcase_add_test(tc1_1, sprintf_test_2003);
    tcase_add_test(tc1_1, sprintf_test_2004);
    tcase_add_test(tc1_1, sprintf_test_2005);
    tcase_add_test(tc1_1, sprintf_test_2006);
    tcase_add_test(tc1_1, sprintf_test_2007);
    tcase_add_test(tc1_1, sprintf_test_2008);
    tcase_add_test(tc1_1, sprintf_test_2009);
    tcase_add_test(tc1_1, sprintf_test_2010);
    tcase_add_test(tc1_1, sprintf_test_2011);
    tcase_add_test(tc1_1, sprintf_test_2012);
    tcase_add_test(tc1_1, sprintf_test_2013);
    tcase_add_test(tc1_1, sprintf_test_2014);
    tcase_add_test(tc1_1, sprintf_test_2015);
    tcase_add_test(tc1_1, sprintf_test_2016);
    tcase_add_test(tc1_1, sprintf_test_2017);
    tcase_add_test(tc1_1, sprintf_test_2018);
    tcase_add_test(tc1_1, sprintf_test_2019);
    tcase_add_test(tc1_1, sprintf_test_2020);
    tcase_add_test(tc1_1, sprintf_test_2021);
    tcase_add_test(tc1_1, sprintf_test_2022);
    tcase_add_test(tc1_1, sprintf_test_2023);
    tcase_add_test(tc1_1, sprintf_test_2024);
    tcase_add_test(tc1_1, sprintf_test_2025);
    tcase_add_test(tc1_1, sprintf_test_2026);
    tcase_add_test(tc1_1, sprintf_test_2027);
    tcase_add_test(tc1_1, sprintf_test_2028);
    tcase_add_test(tc1_1, sprintf_test_2029);
    tcase_add_test(tc1_1, sprintf_test_2030);
    tcase_add_test(tc1_1, sprintf_test_2031);
    tcase_add_test(tc1_1, sprintf_test_2032);
    tcase_add_test(tc1_1, sprintf_test_2033);
    tcase_add_test(tc1_1, sprintf_test_2034);
    tcase_add_test(tc1_1, sprintf_test_2035);
    tcase_add_test(tc1_1, sprintf_test_2036);
    tcase_add_test(tc1_1, sprintf_test_2037);
    tcase_add_test(tc1_1, sprintf_test_2038);
    tcase_add_test(tc1_1, sprintf_test_2039);
    tcase_add_test(tc1_1, sprintf_test_2040);
    tcase_add_test(tc1_1, sprintf_test_2041);
    tcase_add_test(tc1_1, sprintf_test_2042);
    tcase_add_test(tc1_1, sprintf_test_2043);
    tcase_add_test(tc1_1, sprintf_test_2044);
    tcase_add_test(tc1_1, sprintf_test_2045);
    tcase_add_test(tc1_1, sprintf_test_2046);
    tcase_add_test(tc1_1, sprintf_test_2047);
    tcase_add_test(tc1_1, sprintf_test_2048);
    tcase_add_test(tc1_1, sprintf_test_2049);
    tcase_add_test(tc1_1, sprintf_test_2050);
    tcase_add_test(tc1_1, sprintf_test_2051);
    tcase_add_test(tc1_1, sprintf_test_2052);
    tcase_add_test(tc1_1, sprintf_test_2053);
    tcase_add_test(tc1_1, sprintf_test_2054);
    tcase_add_test(tc1_1, sprintf_test_2055);
    tcase_add_test(tc1_1, sprintf_test_2056);
    tcase_add_test(tc1_1, sprintf_test_2057);
    tcase_add_test(tc1_1, sprintf_test_2058);
    tcase_add_test(tc1_1, sprintf_test_2059);
    tcase_add_test(tc1_1, sprintf_test_2060);
    tcase_add_test(tc1_1, sprintf_test_2061);
    tcase_add_test(tc1_1, sprintf_test_2062);
    tcase_add_test(tc1_1, sprintf_test_2063);
    tcase_add_test(tc1_1, sprintf_test_2064);
    tcase_add_test(tc1_1, sprintf_test_2065);
    tcase_add_test(tc1_1, sprintf_test_2066);
    tcase_add_test(tc1_1, sprintf_test_2067);
    tcase_add_test(tc1_1, sprintf_test_2068);
    tcase_add_test(tc1_1, sprintf_test_2069);
    tcase_add_test(tc1_1, sprintf_test_2070);
    tcase_add_test(tc1_1, sprintf_test_2071);
    tcase_add_test(tc1_1, sprintf_test_2072);
    tcase_add_test(tc1_1, sprintf_test_2073);
    tcase_add_test(tc1_1, sprintf_test_2074);
    tcase_add_test(tc1_1, sprintf_test_2075);
    tcase_add_test(tc1_1, sprintf_test_2076);
    tcase_add_test(tc1_1, sprintf_test_2077);
    tcase_add_test(tc1_1, sprintf_test_2078);
    tcase_add_test(tc1_1, sprintf_test_2079);
    tcase_add_test(tc1_1, sprintf_test_2080);
    tcase_add_test(tc1_1, sprintf_test_2081);
    tcase_add_test(tc1_1, sprintf_test_2082);
    tcase_add_test(tc1_1, sprintf_test_2083);
    tcase_add_test(tc1_1, sprintf_test_2084);
    tcase_add_test(tc1_1, sprintf_test_2085);
    tcase_add_test(tc1_1, sprintf_test_2086);
    tcase_add_test(tc1_1, sprintf_test_2087);
    tcase_add_test(tc1_1, sprintf_test_2088);
    tcase_add_test(tc1_1, sprintf_test_2089);
    tcase_add_test(tc1_1, sprintf_test_2090);
    tcase_add_test(tc1_1, sprintf_test_2091);
    tcase_add_test(tc1_1, sprintf_test_2092);
    tcase_add_test(tc1_1, sprintf_test_2093);
    tcase_add_test(tc1_1, sprintf_test_2094);
    tcase_add_test(tc1_1, sprintf_test_2095);
    tcase_add_test(tc1_1, sprintf_test_2096);
    tcase_add_test(tc1_1, sprintf_test_2097);
    tcase_add_test(tc1_1, sprintf_test_2098);
    tcase_add_test(tc1_1, sprintf_test_2099);
    tcase_add_test(tc1_1, sprintf_test_2100);
    tcase_add_test(tc1_1, sprintf_test_2101);
    tcase_add_test(tc1_1, sprintf_test_2102);
    tcase_add_test(tc1_1, sprintf_test_2103);
    tcase_add_test(tc1_1, sprintf_test_2104);
    tcase_add_test(tc1_1, sprintf_test_2105);
    tcase_add_test(tc1_1, sprintf_test_2106);
    tcase_add_test(tc1_1, sprintf_test_2107);
    tcase_add_test(tc1_1, sprintf_test_2108);
    tcase_add_test(tc1_1, sprintf_test_2109);
    tcase_add_test(tc1_1, sprintf_test_2110);
    tcase_add_test(tc1_1, sprintf_test_2111);
    tcase_add_test(tc1_1, sprintf_test_2112);
    tcase_add_test(tc1_1, sprintf_test_2113);
    tcase_add_test(tc1_1, sprintf_test_2114);
    tcase_add_test(tc1_1, sprintf_test_2115);
    tcase_add_test(tc1_1, sprintf_test_2116);
    tcase_add_test(tc1_1, sprintf_test_2117);
    tcase_add_test(tc1_1, sprintf_test_2118);
    tcase_add_test(tc1_1, sprintf_test_2119);
    tcase_add_test(tc1_1, sprintf_test_2120);
    tcase_add_test(tc1_1, sprintf_test_2121);
    tcase_add_test(tc1_1, sprintf_test_2122);
    tcase_add_test(tc1_1, sprintf_test_2123);
    tcase_add_test(tc1_1, sprintf_test_2124);
    tcase_add_test(tc1_1, sprintf_test_2125);
    tcase_add_test(tc1_1, sprintf_test_2126);
    tcase_add_test(tc1_1, sprintf_test_2127);
    tcase_add_test(tc1_1, sprintf_test_2128);
    tcase_add_test(tc1_1, sprintf_test_2129);
    tcase_add_test(tc1_1, sprintf_test_2130);
    tcase_add_test(tc1_1, sprintf_test_2131);
    tcase_add_test(tc1_1, sprintf_test_2132);
    tcase_add_test(tc1_1, sprintf_test_2133);
    tcase_add_test(tc1_1, sprintf_test_2134);
    tcase_add_test(tc1_1, sprintf_test_2135);
    tcase_add_test(tc1_1, sprintf_test_2136);
    tcase_add_test(tc1_1, sprintf_test_2137);
    tcase_add_test(tc1_1, sprintf_test_2138);
    tcase_add_test(tc1_1, sprintf_test_2139);
    tcase_add_test(tc1_1, sprintf_test_2140);
    tcase_add_test(tc1_1, sprintf_test_2141);
    tcase_add_test(tc1_1, sprintf_test_2142);
    tcase_add_test(tc1_1, sprintf_test_2143);
    tcase_add_test(tc1_1, sprintf_test_2144);
    tcase_add_test(tc1_1, sprintf_test_2145);
    tcase_add_test(tc1_1, sprintf_test_2146);
    tcase_add_test(tc1_1, sprintf_test_2147);
    tcase_add_test(tc1_1, sprintf_test_2148);
    tcase_add_test(tc1_1, sprintf_test_2149);
    tcase_add_test(tc1_1, sprintf_test_2150);
    tcase_add_test(tc1_1, sprintf_test_2151);
    tcase_add_test(tc1_1, sprintf_test_2152);
    tcase_add_test(tc1_1, sprintf_test_2153);
    tcase_add_test(tc1_1, sprintf_test_2154);
    tcase_add_test(tc1_1, sprintf_test_2155);
    tcase_add_test(tc1_1, sprintf_test_2156);
    tcase_add_test(tc1_1, sprintf_test_2157);
    tcase_add_test(tc1_1, sprintf_test_2158);
    tcase_add_test(tc1_1, sprintf_test_2159);
    tcase_add_test(tc1_1, sprintf_test_2160);
    tcase_add_test(tc1_1, sprintf_test_2161);
    tcase_add_test(tc1_1, sprintf_test_2162);
    tcase_add_test(tc1_1, sprintf_test_2163);
    tcase_add_test(tc1_1, sprintf_test_2164);
    tcase_add_test(tc1_1, sprintf_test_2165);
    tcase_add_test(tc1_1, sprintf_test_2166);
    tcase_add_test(tc1_1, sprintf_test_2167);
    tcase_add_test(tc1_1, sprintf_test_2168);
    tcase_add_test(tc1_1, sprintf_test_2169);
    tcase_add_test(tc1_1, sprintf_test_2170);
    tcase_add_test(tc1_1, sprintf_test_2171);
    tcase_add_test(tc1_1, sprintf_test_2172);
    tcase_add_test(tc1_1, sprintf_test_2173);
    tcase_add_test(tc1_1, sprintf_test_2174);
    tcase_add_test(tc1_1, sprintf_test_2175);
    tcase_add_test(tc1_1, sprintf_test_2176);
    tcase_add_test(tc1_1, sprintf_test_2177);
    tcase_add_test(tc1_1, sprintf_test_2178);
    tcase_add_test(tc1_1, sprintf_test_2179);
    tcase_add_test(tc1_1, sprintf_test_2180);
    tcase_add_test(tc1_1, sprintf_test_2181);
    tcase_add_test(tc1_1, sprintf_test_2182);
    tcase_add_test(tc1_1, sprintf_test_2183);
    tcase_add_test(tc1_1, sprintf_test_2184);
    tcase_add_test(tc1_1, sprintf_test_2185);
    tcase_add_test(tc1_1, sprintf_test_2186);
    tcase_add_test(tc1_1, sprintf_test_2187);
    tcase_add_test(tc1_1, sprintf_test_2188);
    tcase_add_test(tc1_1, sprintf_test_2189);
    tcase_add_test(tc1_1, sprintf_test_2190);
    tcase_add_test(tc1_1, sprintf_test_2191);
    tcase_add_test(tc1_1, sprintf_test_2192);
    tcase_add_test(tc1_1, sprintf_test_2193);
    tcase_add_test(tc1_1, sprintf_test_2194);
    tcase_add_test(tc1_1, sprintf_test_2195);
    tcase_add_test(tc1_1, sprintf_test_2196);
    tcase_add_test(tc1_1, sprintf_test_2197);
    tcase_add_test(tc1_1, sprintf_test_2198);
    tcase_add_test(tc1_1, sprintf_test_2199);
    tcase_add_test(tc1_1, sprintf_test_2200);
    tcase_add_test(tc1_1, sprintf_test_2201);
    tcase_add_test(tc1_1, sprintf_test_2202);
    tcase_add_test(tc1_1, sprintf_test_2203);
    tcase_add_test(tc1_1, sprintf_test_2204);
    tcase_add_test(tc1_1, sprintf_test_2205);
    tcase_add_test(tc1_1, sprintf_test_2206);
    tcase_add_test(tc1_1, sprintf_test_2207);
    tcase_add_test(tc1_1, sprintf_test_2208);
    tcase_add_test(tc1_1, sprintf_test_2209);
    tcase_add_test(tc1_1, sprintf_test_2210);
    tcase_add_test(tc1_1, sprintf_test_2211);
    tcase_add_test(tc1_1, sprintf_test_2212);
    tcase_add_test(tc1_1, sprintf_test_2213);
    tcase_add_test(tc1_1, sprintf_test_2214);
    tcase_add_test(tc1_1, sprintf_test_2215);
    tcase_add_test(tc1_1, sprintf_test_2216);
    tcase_add_test(tc1_1, sprintf_test_2217);
    tcase_add_test(tc1_1, sprintf_test_2218);
    tcase_add_test(tc1_1, sprintf_test_2219);
    tcase_add_test(tc1_1, sprintf_test_2220);
    tcase_add_test(tc1_1, sprintf_test_2221);
    tcase_add_test(tc1_1, sprintf_test_2222);
    tcase_add_test(tc1_1, sprintf_test_2223);
    tcase_add_test(tc1_1, sprintf_test_2224);
    tcase_add_test(tc1_1, sprintf_test_2225);
    tcase_add_test(tc1_1, sprintf_test_2226);
    tcase_add_test(tc1_1, sprintf_test_2227);
    tcase_add_test(tc1_1, sprintf_test_2228);
    tcase_add_test(tc1_1, sprintf_test_2229);
    tcase_add_test(tc1_1, sprintf_test_2230);
    tcase_add_test(tc1_1, sprintf_test_2231);
    tcase_add_test(tc1_1, sprintf_test_2232);
    tcase_add_test(tc1_1, sprintf_test_2233);
    tcase_add_test(tc1_1, sprintf_test_2234);
    tcase_add_test(tc1_1, sprintf_test_2235);
    tcase_add_test(tc1_1, sprintf_test_2236);
    tcase_add_test(tc1_1, sprintf_test_2237);
    tcase_add_test(tc1_1, sprintf_test_2238);
    tcase_add_test(tc1_1, sprintf_test_2239);
    tcase_add_test(tc1_1, sprintf_test_2240);
    tcase_add_test(tc1_1, sprintf_test_2241);
    tcase_add_test(tc1_1, sprintf_test_2242);
    tcase_add_test(tc1_1, sprintf_test_2243);
    tcase_add_test(tc1_1, sprintf_test_2244);
    tcase_add_test(tc1_1, sprintf_test_2245);
    tcase_add_test(tc1_1, sprintf_test_2246);
    tcase_add_test(tc1_1, sprintf_test_2247);
    tcase_add_test(tc1_1, sprintf_test_2248);
    tcase_add_test(tc1_1, sprintf_test_2249);
    tcase_add_test(tc1_1, sprintf_test_2250);
    tcase_add_test(tc1_1, sprintf_test_2251);
    tcase_add_test(tc1_1, sprintf_test_2252);
    tcase_add_test(tc1_1, sprintf_test_2253);
    tcase_add_test(tc1_1, sprintf_test_2254);
    tcase_add_test(tc1_1, sprintf_test_2255);
    tcase_add_test(tc1_1, sprintf_test_2256);
    tcase_add_test(tc1_1, sprintf_test_2257);
    tcase_add_test(tc1_1, sprintf_test_2258);
    tcase_add_test(tc1_1, sprintf_test_2259);
    tcase_add_test(tc1_1, sprintf_test_2260);
    tcase_add_test(tc1_1, sprintf_test_2261);
    tcase_add_test(tc1_1, sprintf_test_2262);
    tcase_add_test(tc1_1, sprintf_test_2263);
    tcase_add_test(tc1_1, sprintf_test_2264);
    tcase_add_test(tc1_1, sprintf_test_2265);
    tcase_add_test(tc1_1, sprintf_test_2266);
    tcase_add_test(tc1_1, sprintf_test_2267);
    tcase_add_test(tc1_1, sprintf_test_2268);
    tcase_add_test(tc1_1, sprintf_test_2269);
    tcase_add_test(tc1_1, sprintf_test_2270);
    tcase_add_test(tc1_1, sprintf_test_2271);
    tcase_add_test(tc1_1, sprintf_test_2272);
    tcase_add_test(tc1_1, sprintf_test_2273);
    tcase_add_test(tc1_1, sprintf_test_2274);
    tcase_add_test(tc1_1, sprintf_test_2275);
    tcase_add_test(tc1_1, sprintf_test_2276);
    tcase_add_test(tc1_1, sprintf_test_2277);
    tcase_add_test(tc1_1, sprintf_test_2278);
    tcase_add_test(tc1_1, sprintf_test_2279);
    tcase_add_test(tc1_1, sprintf_test_2280);
    tcase_add_test(tc1_1, sprintf_test_2281);
    tcase_add_test(tc1_1, sprintf_test_2282);
    tcase_add_test(tc1_1, sprintf_test_2283);
    tcase_add_test(tc1_1, sprintf_test_2284);
    tcase_add_test(tc1_1, sprintf_test_2285);
    tcase_add_test(tc1_1, sprintf_test_2286);
    tcase_add_test(tc1_1, sprintf_test_2287);
    tcase_add_test(tc1_1, sprintf_test_2288);
    tcase_add_test(tc1_1, sprintf_test_2289);
    tcase_add_test(tc1_1, sprintf_test_2290);
    tcase_add_test(tc1_1, sprintf_test_2291);
    tcase_add_test(tc1_1, sprintf_test_2292);
    tcase_add_test(tc1_1, sprintf_test_2293);
    tcase_add_test(tc1_1, sprintf_test_2294);
    tcase_add_test(tc1_1, sprintf_test_2295);
    tcase_add_test(tc1_1, sprintf_test_2296);
    tcase_add_test(tc1_1, sprintf_test_2297);
    tcase_add_test(tc1_1, sprintf_test_2298);
    tcase_add_test(tc1_1, sprintf_test_2299);
    tcase_add_test(tc1_1, sprintf_test_2300);
    tcase_add_test(tc1_1, sprintf_test_2301);
    tcase_add_test(tc1_1, sprintf_test_2302);
    tcase_add_test(tc1_1, sprintf_test_2303);
    tcase_add_test(tc1_1, sprintf_test_2304);
    tcase_add_test(tc1_1, sprintf_test_2305);
    tcase_add_test(tc1_1, sprintf_test_2306);
    tcase_add_test(tc1_1, sprintf_test_2307);
    tcase_add_test(tc1_1, sprintf_test_2308);
    tcase_add_test(tc1_1, sprintf_test_2309);
    tcase_add_test(tc1_1, sprintf_test_2310);
    tcase_add_test(tc1_1, sprintf_test_2311);
    tcase_add_test(tc1_1, sprintf_test_2312);
    tcase_add_test(tc1_1, sprintf_test_2313);
    tcase_add_test(tc1_1, sprintf_test_2314);
    tcase_add_test(tc1_1, sprintf_test_2315);
    tcase_add_test(tc1_1, sprintf_test_2316);
    tcase_add_test(tc1_1, sprintf_test_2317);
    tcase_add_test(tc1_1, sprintf_test_2318);
    tcase_add_test(tc1_1, sprintf_test_2319);
    tcase_add_test(tc1_1, sprintf_test_2320);
    tcase_add_test(tc1_1, sprintf_test_2321);
    tcase_add_test(tc1_1, sprintf_test_2322);
    tcase_add_test(tc1_1, sprintf_test_2323);
    tcase_add_test(tc1_1, sprintf_test_2324);
    tcase_add_test(tc1_1, sprintf_test_2325);
    tcase_add_test(tc1_1, sprintf_test_2326);
    tcase_add_test(tc1_1, sprintf_test_2327);
    tcase_add_test(tc1_1, sprintf_test_2328);
    tcase_add_test(tc1_1, sprintf_test_2329);
    tcase_add_test(tc1_1, sprintf_test_2330);
    tcase_add_test(tc1_1, sprintf_test_2331);
    tcase_add_test(tc1_1, sprintf_test_2332);
    tcase_add_test(tc1_1, sprintf_test_2333);
    tcase_add_test(tc1_1, sprintf_test_2334);
    tcase_add_test(tc1_1, sprintf_test_2335);
    tcase_add_test(tc1_1, sprintf_test_2336);
    tcase_add_test(tc1_1, sprintf_test_2337);
    tcase_add_test(tc1_1, sprintf_test_2338);
    tcase_add_test(tc1_1, sprintf_test_2339);
    tcase_add_test(tc1_1, sprintf_test_2340);
    tcase_add_test(tc1_1, sprintf_test_2341);
    tcase_add_test(tc1_1, sprintf_test_2342);
    tcase_add_test(tc1_1, sprintf_test_2343);
    tcase_add_test(tc1_1, sprintf_test_2344);
    tcase_add_test(tc1_1, sprintf_test_2345);
    tcase_add_test(tc1_1, sprintf_test_2346);
    tcase_add_test(tc1_1, sprintf_test_2347);
    tcase_add_test(tc1_1, sprintf_test_2348);
    tcase_add_test(tc1_1, sprintf_test_2349);
    tcase_add_test(tc1_1, sprintf_test_2350);
    tcase_add_test(tc1_1, sprintf_test_2351);
    tcase_add_test(tc1_1, sprintf_test_2352);
    tcase_add_test(tc1_1, sprintf_test_2353);
    tcase_add_test(tc1_1, sprintf_test_2354);
    tcase_add_test(tc1_1, sprintf_test_2355);
    tcase_add_test(tc1_1, sprintf_test_2356);
    tcase_add_test(tc1_1, sprintf_test_2357);
    tcase_add_test(tc1_1, sprintf_test_2358);
    tcase_add_test(tc1_1, sprintf_test_2359);
    tcase_add_test(tc1_1, sprintf_test_2360);
    tcase_add_test(tc1_1, sprintf_test_2361);
    tcase_add_test(tc1_1, sprintf_test_2362);
    tcase_add_test(tc1_1, sprintf_test_2363);
    tcase_add_test(tc1_1, sprintf_test_2364);
    tcase_add_test(tc1_1, sprintf_test_2365);
    tcase_add_test(tc1_1, sprintf_test_2366);
    tcase_add_test(tc1_1, sprintf_test_2367);
    tcase_add_test(tc1_1, sprintf_test_2368);
    tcase_add_test(tc1_1, sprintf_test_2369);
    tcase_add_test(tc1_1, sprintf_test_2370);
    tcase_add_test(tc1_1, sprintf_test_2371);
    tcase_add_test(tc1_1, sprintf_test_2372);
    tcase_add_test(tc1_1, sprintf_test_2373);
    tcase_add_test(tc1_1, sprintf_test_2374);
    tcase_add_test(tc1_1, sprintf_test_2375);
    tcase_add_test(tc1_1, sprintf_test_2376);
    tcase_add_test(tc1_1, sprintf_test_2377);
    tcase_add_test(tc1_1, sprintf_test_2378);
    tcase_add_test(tc1_1, sprintf_test_2379);
    tcase_add_test(tc1_1, sprintf_test_2380);
    tcase_add_test(tc1_1, sprintf_test_2381);
    tcase_add_test(tc1_1, sprintf_test_2382);
    tcase_add_test(tc1_1, sprintf_test_2383);
    tcase_add_test(tc1_1, sprintf_test_2384);
    tcase_add_test(tc1_1, sprintf_test_2385);
    tcase_add_test(tc1_1, sprintf_test_2386);
    tcase_add_test(tc1_1, sprintf_test_2387);
    tcase_add_test(tc1_1, sprintf_test_2388);
    tcase_add_test(tc1_1, sprintf_test_2389);
    tcase_add_test(tc1_1, sprintf_test_2390);
    tcase_add_test(tc1_1, sprintf_test_2391);
    tcase_add_test(tc1_1, sprintf_test_2392);
    tcase_add_test(tc1_1, sprintf_test_2393);
    tcase_add_test(tc1_1, sprintf_test_2394);
    tcase_add_test(tc1_1, sprintf_test_2395);
    tcase_add_test(tc1_1, sprintf_test_2396);
    tcase_add_test(tc1_1, sprintf_test_2397);
    tcase_add_test(tc1_1, sprintf_test_2398);
    tcase_add_test(tc1_1, sprintf_test_2399);
    tcase_add_test(tc1_1, sprintf_test_2400);
    tcase_add_test(tc1_1, sprintf_test_2401);
    tcase_add_test(tc1_1, sprintf_test_2402);
    tcase_add_test(tc1_1, sprintf_test_2403);
    tcase_add_test(tc1_1, sprintf_test_2404);
    tcase_add_test(tc1_1, sprintf_test_2405);
    tcase_add_test(tc1_1, sprintf_test_2406);
    tcase_add_test(tc1_1, sprintf_test_2407);
    tcase_add_test(tc1_1, sprintf_test_2408);
    tcase_add_test(tc1_1, sprintf_test_2409);
    tcase_add_test(tc1_1, sprintf_test_2410);
    tcase_add_test(tc1_1, sprintf_test_2411);
    tcase_add_test(tc1_1, sprintf_test_2412);
    tcase_add_test(tc1_1, sprintf_test_2413);
    tcase_add_test(tc1_1, sprintf_test_2414);
    tcase_add_test(tc1_1, sprintf_test_2415);
    tcase_add_test(tc1_1, sprintf_test_2416);
    tcase_add_test(tc1_1, sprintf_test_2417);
    tcase_add_test(tc1_1, sprintf_test_2418);
    tcase_add_test(tc1_1, sprintf_test_2419);
    tcase_add_test(tc1_1, sprintf_test_2420);
    tcase_add_test(tc1_1, sprintf_test_2421);
    tcase_add_test(tc1_1, sprintf_test_2422);
    tcase_add_test(tc1_1, sprintf_test_2423);
    tcase_add_test(tc1_1, sprintf_test_2424);
    tcase_add_test(tc1_1, sprintf_test_2425);
    tcase_add_test(tc1_1, sprintf_test_2426);
    tcase_add_test(tc1_1, sprintf_test_2427);
    tcase_add_test(tc1_1, sprintf_test_2428);
    tcase_add_test(tc1_1, sprintf_test_2429);
    tcase_add_test(tc1_1, sprintf_test_2430);
    tcase_add_test(tc1_1, sprintf_test_2431);
    tcase_add_test(tc1_1, sprintf_test_2432);
    tcase_add_test(tc1_1, sprintf_test_2433);
    tcase_add_test(tc1_1, sprintf_test_2434);
    tcase_add_test(tc1_1, sprintf_test_2435);
    tcase_add_test(tc1_1, sprintf_test_2436);
    tcase_add_test(tc1_1, sprintf_test_2437);
    tcase_add_test(tc1_1, sprintf_test_2438);
    tcase_add_test(tc1_1, sprintf_test_2439);
    tcase_add_test(tc1_1, sprintf_test_2440);
    tcase_add_test(tc1_1, sprintf_test_2441);
    tcase_add_test(tc1_1, sprintf_test_2442);
    tcase_add_test(tc1_1, sprintf_test_2443);
    tcase_add_test(tc1_1, sprintf_test_2444);
    tcase_add_test(tc1_1, sprintf_test_2445);
    tcase_add_test(tc1_1, sprintf_test_2446);
    tcase_add_test(tc1_1, sprintf_test_2447);
    tcase_add_test(tc1_1, sprintf_test_2448);
    tcase_add_test(tc1_1, sprintf_test_2449);
    tcase_add_test(tc1_1, sprintf_test_2450);
    tcase_add_test(tc1_1, sprintf_test_2451);
    tcase_add_test(tc1_1, sprintf_test_2452);
    tcase_add_test(tc1_1, sprintf_test_2453);
    tcase_add_test(tc1_1, sprintf_test_2454);
    tcase_add_test(tc1_1, sprintf_test_2455);
    tcase_add_test(tc1_1, sprintf_test_2456);
    tcase_add_test(tc1_1, sprintf_test_2457);
    tcase_add_test(tc1_1, sprintf_test_2458);
    tcase_add_test(tc1_1, sprintf_test_2459);
    tcase_add_test(tc1_1, sprintf_test_2460);
    tcase_add_test(tc1_1, sprintf_test_2461);
    tcase_add_test(tc1_1, sprintf_test_2462);
    tcase_add_test(tc1_1, sprintf_test_2463);
    tcase_add_test(tc1_1, sprintf_test_2464);
    tcase_add_test(tc1_1, sprintf_test_2465);
    tcase_add_test(tc1_1, sprintf_test_2466);
    tcase_add_test(tc1_1, sprintf_test_2467);
    tcase_add_test(tc1_1, sprintf_test_2468);
    tcase_add_test(tc1_1, sprintf_test_2469);
    tcase_add_test(tc1_1, sprintf_test_2470);
    tcase_add_test(tc1_1, sprintf_test_2471);
    tcase_add_test(tc1_1, sprintf_test_2472);
    tcase_add_test(tc1_1, sprintf_test_2473);
    tcase_add_test(tc1_1, sprintf_test_2474);
    tcase_add_test(tc1_1, sprintf_test_2475);
    tcase_add_test(tc1_1, sprintf_test_2476);
    tcase_add_test(tc1_1, sprintf_test_2477);
    tcase_add_test(tc1_1, sprintf_test_2478);
    tcase_add_test(tc1_1, sprintf_test_2479);
    tcase_add_test(tc1_1, sprintf_test_2480);
    tcase_add_test(tc1_1, sprintf_test_2481);
    tcase_add_test(tc1_1, sprintf_test_2482);
    tcase_add_test(tc1_1, sprintf_test_2483);
    tcase_add_test(tc1_1, sprintf_test_2484);
    tcase_add_test(tc1_1, sprintf_test_2485);
  }
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  srunner_run_all(sr_1, CK_ENV);
  nf_1 = srunner_ntests_failed(sr_1);
  srunner_free(sr_1);
  srunner_run_all(krasivoe, CK_ENV);
  otli4noe_nf = srunner_ntests_failed(krasivoe);
  srunner_free(krasivoe);

  return (nf + nf_1 + otli4noe_nf == 0) ? 0 : 1;
}
