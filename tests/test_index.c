/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_index
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <strings.h>

char *(*my_index)(char *, int);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_index = dlsym(handle, "index");
}

Test(test_index, middle, .init = init_func)
{
	cr_assert_str_eq(my_index("adbcde", 'd') , (*index)("adbcde", 'd'));
}

Test(test_index, first, .init = init_func)
{
	cr_assert_str_eq(my_index("abcdae", 'a'), (*index)("abcdae", 'a'));
}

Test(test_index, last, .init = init_func)
{
	cr_assert_str_eq(my_index("abzzcdez", 'z') , (*index)("abzzcdez", 'z'));
}

Test(test_index, inexistant, .init = init_func)
{
	cr_assert(my_index("abczzdez", 'A') == (*index)("abczzdez", 'A'));
}

Test(test_index, inexistant2, .init = init_func)
{
	cr_assert_str_eq(my_index("abcdez", '\0') , (*index)("abcdez", '\0'));
}

Test(test_index, null, .init = init_func)
{
	cr_assert_null(my_index(NULL, ' '));
}

Test(test_index, backslash_zero, .init = init_func)
{
    cr_assert(my_index("hello", '\0') == (*index)("hello", '\0'));
}