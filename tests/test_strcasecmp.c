/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strcasecmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

int (*my_strcasecmp)(const char *s1, const char *s2);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strcasecmp = dlsym(handle, "strcasecmp");
}

Test(test_strcasecmpm, equal_1, .init = init_func)
{
	int my = my_strcasecmp("aa", "Aa");
	int real = strcasecmp("aa", "Aa");

	cr_assert(my == real);
}

Test(test_strcasecmpm, equal_2, .init = init_func)
{
	int my = my_strcasecmp("abc", "aBc");
	int real = strcasecmp("abc", "aBc");

	cr_assert(my == real);
}

Test(test_strcasecmpm, not_equal, .init = init_func)
{
	int my = my_strcasecmp("abc", "aBcd");
	int real = strcasecmp("abc", "aBcd");

	cr_assert(my < 0 && real < 0);
}

Test(test_strcasecmp, null_1, .init = init_func)
{
	int my = my_strcasecmp(NULL, "aaA");

	cr_assert(my < 0);
}

Test(test_strcasecmp, null_2, .init = init_func)
{
	int my = my_strcasecmp("aAa", NULL);

	cr_assert(my > 0);
}
