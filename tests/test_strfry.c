/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_index
*/

#define _GNU_SOURCE
#include <criterion/criterion.h>
#include <dlfcn.h>
#include <strings.h>
#include <string.h>

char *(*my_strfry)(char *);

static void init_func(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	my_strfry = dlsym(handle, "strfry");

}

Test(test_strfry, test_1, .init = init_func)
{
	char test[] = "123456789";

	// printf("%s\n", my_strfry(test));
}

Test(test_strfry, test_2, .init = init_func)
{
	char test[] = "";

	// printf("%s\n", my_strfry(test));
}

Test(test_strfry, test_3, .init = init_func)
{
	char test[] = "12";

	// printf("%s\n", my_strfry(test));
}

Test(test_strfry, null, .init = init_func)
{
	cr_assert(my_strfry(NULL) == 0);
}
