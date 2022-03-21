/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_index
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <strings.h>

void *(*my_memfrob)(void *s, size_t n);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_memfrob = dlsym(handle, "memfrob");
}

Test(test_memfrob, size_0, .init = init_func)
{
	cr_assert(my_memfrob(NULL, 123) == 0);
}

Test(test_memfrob, null, .init = init_func)
{
	char *test = "123";

	cr_assert_eq((char *) (my_memfrob(test, 0)), test);
}

Test(test_memfrob, test_1, .init = init_func)
{
	char test[] = "123456789";

	my_memfrob(test, 1);
	// printf("%s -- ", test);
	my_memfrob(test, 1);
	// printf("%s\n", test);

	my_memfrob(test, 8);
	// printf("%s -- ", test);
	my_memfrob(test, 8);
	// printf("%s\n", test);
}