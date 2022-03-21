/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test__strncmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

int (*my_strncmp)(const char *, const char *, size_t);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strncmp = dlsym(handle, "strncmp");
}

Test(test_strncmp, not_equal_1, .init = init_func)
{
	int my = my_strncmp("aa", "ab", 2);
	int real = strncmp("aa", "ab", 2);

	cr_assert(my == real);
}

Test(test_strncmp, equal, .init = init_func)
{
	int my = my_strncmp("aa", "aa", 2);
	int real = strncmp("aa", "aa", 2);

	cr_assert(my == real);
}

Test(test_strncmp, not_equal_2, .init = init_func)
{
	int my = my_strncmp("ab", "aa", 2);
	int real = strncmp("ab", "aa", 2);

	cr_assert(my == real);
}

Test(test_strncmp, not_equal_3, .init = init_func)
{
	int my = my_strncmp("aaa", "aa", 3);
	int real = strncmp("aaa", "aa", 3);

	cr_assert(my == real);
}

Test(test_strncmp, not_equal_4, .init = init_func)
{
	int my = my_strncmp("aa", "ab", 1);
	int real = strncmp("aa", "ab", 1);

	cr_assert(my == real);
}

Test(test_strncmp, null_1, .init = init_func)
{
	int my = my_strncmp(NULL, "aa", 3);

	cr_assert(my < 0);
}

Test(test_strncmp, null_2, .init = init_func)
{
	int my = my_strncmp("aa", NULL, 3);

	cr_assert(my > 0);
}
