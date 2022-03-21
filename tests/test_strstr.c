/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strstr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

char *(*my_strstr)(const char *, const char *);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strstr = dlsym(handle, "strstr");
}

Test(test_strstr, is_in, .init = init_func)
{
	char *my = my_strstr(strdup("zabcdefgh"), "abc");
	char *real = strstr(strdup("zabcdefgh"), "abc");

	cr_assert_str_eq(my, real);
}

Test(test_strstr, is_not_in, .init = init_func)
{
	char *my = my_strstr(strdup("zabcdefgh"), "aze");
	char *real = strstr(strdup("zabcdefgh"), "aze");

	cr_assert(my == real);
}

Test(test_strstr, size_less, .init = init_func)
{
	char *my = my_strstr(strdup("d"), "aze");
	char *real = strstr(strdup("d"), "aze");

	cr_assert(my == real);
}

Test(test_strstr, null_1, .init = init_func)
{
	char *my = my_strstr(NULL, "aa");

	cr_assert_null(my);
}

Test(test_strstr, null_2, .init = init_func)
{
	char *my = my_strstr("aa", NULL);

	cr_assert_null(my);
}

Test(test_strstr, both_empty, .init = init_func)
{
	char *my = my_strstr("", "");
	char *real = strstr("", "");

	cr_assert_str_eq(my, real);
}