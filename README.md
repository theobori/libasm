# 👨‍💻 libasm

## Setup

1. Install the dependencies
    - Run the bash script `install.sh` (Can request sudo)
2. Compile using `make` to get a shared object containing every functions

## Unitary tests

Run `make tests_run`

## Implemented functions

```c
void memset(void *, int, size_t);
int ffs(int);
int strcmp(const char *, const char *);
char *index(char *, int);
void *memcpy(void *, void *, size_t);
void *memfrob(void *s, size_t n);
void *memmove(void *, const void *, size_t);
char *rindex(char *, int);
int strcasecmp(const char *s1, const char *s2);
char *strchr(char *, int);
size_t strcspn(const char *, const char *);
char *strfry(char *);
size_t strlen(char*);
int strncmp(const char *, const char *, size_t);
const char *strpbrk(const char *, const char *);
char *strrchr(char *, int);
char *strstr(const char *, const char *);
```