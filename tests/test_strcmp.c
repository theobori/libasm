/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strcmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>

int (*my_strcmp)(const char *, const char *);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strcmp = dlsym(handle, "strcmp");
}

Test(test_strcmp, not_equal, .init = init_func)
{
	int my = my_strcmp("aa", "ab");
	int real = strcmp("aa", "ab");

	cr_assert(my == real);
}

Test(test_strcmp, not_equal_2, .init = init_func)
{
	int my = my_strcmp("aa", "aA");
	int real = strcmp("aa", "aA");

	// printf("%d -- %d\n", my, real);
	cr_assert(my > 0 && real > 0);
}

Test(test_strcmp, not_equal_3, .init = init_func)
{
	int my = my_strcmp("ab", "aa");
	int real = strcmp("ab", "aa");

	cr_assert(my == real);
}

Test(test_strcmp, not_equal_4, .init = init_func)
{
	int my = my_strcmp("aaa", "aa");
	int real = strcmp("aaa", "aa");

	// printf("%d -- %d\n", my, real);
	cr_assert(my > 0 && real > 0);
}

Test(test_strcmp, not_equal_5, .init = init_func)
{
	int my = my_strcmp("aa", "aaa");
	int real = strcmp("aa", "aaa");

	// printf("%d -- %d\n", my, real);
	cr_assert(my < 0 && real < 0);
}

Test(test_strcmp, equal, .init = init_func)
{
	int my = my_strcmp("aa", "aa");
	int real = strcmp("aa", "aa");

	cr_assert(my == real);
}

Test(test_strcmp, null_1, .init = init_func)
{
	int my = my_strcmp(NULL, "aa");

	cr_assert(my < 0);
}

Test(test_strcmp, null_2, .init = init_func)
{
	int my = my_strcmp("aa", NULL);

	cr_assert(my > 0);
}
