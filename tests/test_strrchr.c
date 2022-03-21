/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strrchr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

char *(*my_strrchr)(char *, int);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strrchr = dlsym(handle, "strrchr");
}

Test(test_strrchr, middle, .init = init_func)
{
	cr_assert_str_eq(my_strrchr("abcdae", 'd'), (*strrchr)("abcdae", 'd'));
}

Test(test_strrchr, first, .init = init_func)
{
	cr_assert_str_eq(my_strrchr("abcdae", 'a'), (*strrchr)("abcdae", 'a'));
}

Test(test_strrchr, last, .init = init_func)
{
	cr_assert_str_eq(my_strrchr("abcdez", 'z'), (*strrchr)("abcdez", 'z'));
}

Test(test_strrchr, inexistant, .init = init_func)
{
	cr_assert(my_strrchr("abcdez", 'A') == (*strrchr)("abcdez", 'A'));
}

Test(test_strrchr, null, .init = init_func)
{
	cr_assert(my_strrchr(NULL, 'A') == NULL);
}
