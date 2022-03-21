/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_memset
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

void *(*my_memset)(void *, int, size_t);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_memset = dlsym(handle, "memset");
}

Test(test_memset, valid, .init = init_func)
{
	char my[6] = {0};
	char real[6] = {0};

	my_memset(my, 'f', 5);
	memset(real, 'f', 5);
	cr_assert_str_eq(my, real);
}

Test(test_memset, less_than_max, .init = init_func)
{
	char my[6] = {0};
	char real[6] = {0};

	my_memset(my, 'f', 2);
	memset(real, 'f', 2);
	cr_assert_str_eq(my, real);
}

Test(test_memset, null, .init = init_func)
{
	cr_assert(my_memset(NULL, 'f', 3) == 0);
}