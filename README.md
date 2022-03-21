# 👨‍💻 libasm

## Setup

1. Install the dependencies
    - Run the bash script `install.sh` (Can request sudo)
2. Compile using `make` to get a shared object containing every functions

## Unitary tests

Run `make tests_run`

## Implemented functions

```c
void my_memset(void *, int, size_t);
int my_ffs(int);
int my_strcmp(const char *, const char *);
char *my_index(char *, int);
void *my_memcpy(void *, void *, size_t);
void *my_memfrob(void *s, size_t n);
void *my_memmove(void *, const void *, size_t);
char *my_rindex(char *, int);
int my_strcasecmp(const char *s1, const char *s2);
char *my_strchr(char *, int);
size_t my_strcspn(const char *, const char *);
char *my_strfry(char *);
size_t my_strlen(char*);
int my_strncmp(const char *, const char *, size_t);
const char *my_strpbrk(const char *, const char *);
char *my_strrchr(char *, int);
char *my_strstr(const char *, const char *);
```