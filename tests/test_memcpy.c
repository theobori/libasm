/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_memcpy
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

void *(*my_memcpy)(void *, void *, size_t);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_memcpy = dlsym(handle, "memcpy");
}

Test(test_memcpy, valid, .init = init_func)
{
	char *my = my_memcpy(strdup("     "), strdup("aaaaa"), 5);
	char *real = memcpy(strdup("     "), strdup("aaaaa"), 5);

	cr_assert_str_eq(my, real);
}

Test(test_memcpy, size_higher_than_src, .init = init_func)
{
	char *my = my_memcpy(strdup("     "), strdup("aaa"), 5);
	char *real = memcpy(strdup("     "), strdup("aaa"), 5);

	cr_assert_str_eq(my, real);
}

Test(test_memcpy, size_higher_than_src_2, .init = init_func)
{
	char *my = my_memcpy(strdup("     "), strdup("aaaaa"), 6);
	char *real = memcpy(strdup("     "), strdup("aaaaa"), 6);

	cr_assert_str_eq(my, real);
}

Test(test_memcpy, size_higher_than_src_3, .init = init_func)
{
	char *my = my_memcpy(strdup("  "), strdup("aaaaa"), 6);
	char *real = memcpy(strdup("  "), strdup("aaaaa"), 6);

	cr_assert_str_eq(my, real);
}

Test(test_memcpy, size_higher_than_src_4, .init = init_func)
{
	char *my = my_memcpy(strdup("     "), strdup("aa"), 6);
	char *real = memcpy(strdup("     "), strdup("aa"), 6);

	cr_assert_str_eq(my, real);
}

Test(test_memcpy, null_1, .init = init_func)
{
	cr_assert(my_memcpy(NULL, "hello", 3) == 0);
}

Test(test_memcpy, null_2, .init = init_func)
{
	char *dest = strdup("     ");

	cr_assert(my_memcpy(dest, NULL, 2) == dest);
}
