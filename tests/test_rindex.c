/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_rindex
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <strings.h>

char *(*my_rindex)(char *, int);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_rindex = dlsym(handle, "rindex");
}

Test(test_rindex, middle, .init = init_func)
{
	cr_assert_str_eq(my_rindex("abcdae", 'd'), rindex("abcdae", 'd'));
}

Test(test_rindex, first, .init = init_func)
{
	cr_assert_str_eq(my_rindex("abcdae", 'a'), rindex("abcdae", 'a'));
}

Test(test_rindex, last, .init = init_func)
{
	cr_assert_str_eq(my_rindex("abcdez", 'z'), rindex("abcdez", 'z'));
}

Test(test_rindex, inexistant, .init = init_func)
{
	char *my = my_rindex("hello", 'A'); 
	char *real = rindex("hello", 'A');

	cr_assert(my == real);
}

Test(test_rindex, backslash_zero, .init = init_func)
{
	char *my = my_rindex("hello", '\0'); 
	char *real = rindex("hello", '\0');

    cr_assert_str_eq(my, real);
}

Test(test_rindex, null_1, .init = init_func)
{
	char *my = my_rindex(0, '\0'); 

    cr_assert(my == 0);
}