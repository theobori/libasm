/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_memmove
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

void *(*my_memmove)(void *, const void *, size_t);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_memmove = dlsym(handle, "memmove");
}

Test(test_memmove, perfect_fit, .init = init_func)
{
	char *my = my_memmove(strdup("     "), strdup("aaaaa"), 5);
	char *real = memmove(strdup("     "), strdup("aaaaa"), 5);

	cr_assert_str_eq(my, real);
}

Test(test_memmove, higher_size_than_strlen_2, .init = init_func)
{
	char *my = my_memmove(strdup("     "), strdup("aaa"), 5);
	char *real = memmove(strdup("     "), strdup("aaa"), 5);

	cr_assert_str_eq(my, real);
}

Test(test_memmove, higher_size_than_strlen_3, .init = init_func)
{
	char *my = my_memmove(strdup("     "), strdup("aaaaa"), 6);
	char *real = memmove(strdup("     "), strdup("aaaaa"), 6);

	cr_assert_str_eq(my, real);
}

Test(test_memmove, null_1, .init = init_func)
{
	cr_assert(my_memmove(NULL, strdup("aaaaa"), 3) == 0);
}

Test(test_memmove, null_2, .init = init_func)
{
	char *dest = strdup("     ");

	cr_assert(my_memmove(dest, NULL, 2) == dest);
}

Test(test_memmove, higher_size_than_strlen_4, .init = init_func)
{
    char *str = strdup("01234567899999");
    char *str2 = strdup("01234567899999");
    
    char *my = my_memmove(str + 2, str, 4);
    char *real = memmove(str2 + 2, str2, 4);
    cr_assert_str_eq(my, real);
}

Test(test_memmove, higher_size_than_strlen_5, .init = init_func)
{
    char *str = strdup("01234567899999");
    char *str2 = strdup("01234567899999");
    char *my = my_memmove(str, str + 2, 4);
    char *real = memmove(str2, str2 + 2, 4);

    cr_assert_str_eq(my, real);
}
