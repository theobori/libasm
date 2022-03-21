/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strchr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

char *(*my_strchr)(char *, int);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strchr = dlsym(handle, "strchr");
}

Test(test_strchr, middle, .init = init_func)
{
	cr_assert(my_strchr("abcde", 'd') == (*strchr)("abcde", 'd'));
}

Test(test_strchr, first, .init = init_func)
{
	cr_assert(my_strchr("abcde", 'a') == (*strchr)("abcde", 'a'));
}

Test(test_strchr, last, .init = init_func)
{
	cr_assert(my_strchr("abcdez", 'z') == (*strchr)("abcdez", 'z'));
}

Test(test_strchr, inexistant, .init = init_func)
{
	cr_assert(my_strchr("abcdez", 'A') == (*strchr)("abcdez", 'A'));
}

Test(test_strchr, null, .init = init_func)
{
	cr_assert(my_strchr(NULL, 'A') == NULL);
}