/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_index
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <strings.h>

int (*my_ffs)(int);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_ffs = dlsym(handle, "ffs");
}

Test(test_ffs, test_1, .init = init_func)
{
	cr_assert_eq(my_ffs(12), ffs(12));
}
Test(test_ffs, test_2, .init = init_func)
{
	// printf("%d -- %d\n", my_ffs(0xffffffff), ffs(0xffffffff));
	cr_assert_eq(my_ffs(0xffffffff), ffs(0xffffffff));
}

Test(test_ffs, zero, .init = init_func)
{
	// printf("%d -- %d\n", my_ffs(0), ffs(0));
	cr_assert_eq(my_ffs(0), ffs(0));
}

Test(test_ffs, test_3, .init = init_func)
{
	// printf("%d -- %d\n", my_ffs(0xffffff + 1), ffs(0xffffff + 1));
	cr_assert_eq(my_ffs(0xffffff + 1), ffs(0xffffff + 1));
}

Test(test_ffs, limit, .init = init_func)
{
	// printf("%d -- %d\n", my_ffs(2147483648), ffs(2147483648));
	cr_assert_eq(my_ffs(2147483648), ffs(2147483648));
}
