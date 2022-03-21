/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strpbrk
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

const char *(*my_strpbrk)(const char *, const char *);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strpbrk = dlsym(handle, "strpbrk");
}

Test(test_strpbrk, is_in_1, .init = init_func)
{
	const char *my = my_strpbrk("zabcdefgh", "gfa");
	const char *real = strpbrk("zabcdefgh", "gfa");

	cr_assert_str_eq(my, real);
}

Test(test_strpbrk, is_in_2, .init = init_func)
{
	const char *my = my_strpbrk("zabcdefgh", "fbz");
	const char *real = strpbrk("zabcdefgh", "fbz");

	cr_assert_str_eq(my, real);
}

Test(test_strpbrk, not_in, .init = init_func)
{
	const char *my = my_strpbrk("zabcdefgh", "1");
	const char *real = strpbrk("zabcdefgh", "1");

	cr_assert(my == real);
}

Test(test_strpbrk, null_1, .init = init_func)
{
	const char *my = my_strpbrk(NULL, "aa");

	cr_assert_null(my);
}

Test(test_strpbrk, null_2, .init = init_func)
{
	const char *my = my_strpbrk("aa", NULL);

	cr_assert_null(my);
}