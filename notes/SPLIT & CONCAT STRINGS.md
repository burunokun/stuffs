Concat function
```c
// strcat: returns a copy of dest
//         returns 0 on success, non-zero on error. Also, on error, writes zero to dest[0]
char *concat(char *dest, char *src) {
	strcat(dest, src);
	return dest;
}
```

Split function
```c
// strcpy: returns a copy 
//         returns 0 on success, non-zero on error. Also, on error, writes zero to dest[0]
char **split_by_delim(char *s, char *delim) {
	char *token;
	char **arr = NULL;
	while ((token = strsep(&s, delim)) != NULL) {
		size_t token_len = strlen(token);
		if (token_len > 0) {
			arr = realloc(arr, sizeof(char *)*(++count));
			arr[count-1] = token;
		}
	}
	return arr;
}
```