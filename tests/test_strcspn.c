/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strcspn
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

size_t (*my_strcspn)(const char *, const char *);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strcspn = dlsym(handle, "strcspn");
}

Test(test_strcspn, test_1, .init = init_func)
{
	size_t my = my_strcspn("abcdefgh", "f");
	size_t real = strcspn("abcdefgh", "f");

	cr_assert(my == real);
}

Test(test_strcspn, test_2, .init = init_func)
{
	size_t my = my_strcspn("abcdefgh", "a");
	size_t real = strcspn("abcdefgh", "a");

	cr_assert(my == real);
}

Test(test_strcspn, test_3, .init = init_func)
{
	size_t my = my_strcspn("abcdefgh", "h");
	size_t real = strcspn("abcdefgh", "h");

	cr_assert(my == real);
}

Test(test_strcspn, test_4, .init = init_func)
{
	size_t my = my_strcspn("abcdefgh", "qw");
	size_t real = strcspn("abcdefgh", "qw");

	cr_assert(my == real);
}

Test(test_strcspn, null_1, .init = init_func)
{
	int my = my_strcspn(NULL, "aa");

	cr_assert(my == 0);
}

Test(test_strcspn, null_2, .init = init_func)
{
	int my = my_strcspn("aa", NULL);

	cr_assert(my == 0);
}
