/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strlen
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

size_t (*my_strlen)(char*);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);
	my_strlen = dlsym(handle, "strlen");
}

Test(test_strlen, simple_strlen, .init = init_func)
{
	char *str = strdup("hello_world");

	cr_assert(strlen(str) == (*my_strlen)(str));
}

Test(test_strlen, strlen_empty_string, .init = init_func)
{
	char *str = strdup("");

	cr_assert(strlen(str) == (*my_strlen)(str));
}

Test(test_strlen, null, .init = init_func)
{
	cr_assert(my_strlen(NULL) == 0);
}
