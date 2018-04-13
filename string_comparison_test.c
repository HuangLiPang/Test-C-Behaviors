#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // str[4] = {'a', 'b', 'c', '\0'};
  const char str[] = "abc";
  // a[2] = {'a', '\0'};
  const char a[] = "a"; 
  char character_a = 'a';

  /* 
   * In C, single quotes (') represent a single character;
   * double quotes (") represent a string literal. 
   * Consequently, 'a' means a character 'a' and 
   * "a" means a charater 'a' and a null terminator '\0',
   * which is two characters.
   */

  printf("str[] = \"%s\"\n", str);
  printf("ascii code:\n");

  /* 
   * %c prints a single character and 
   * %d prints ascii code of the character.
   */

  printf("%c: %d\n%c: %d\n%c: %d\n\n", 'a', 'a', 'b', 'b', 'c', 'c');

  /* This is not legal because "a" is a string literal. */
  // printf("a: %d\nb: %d\nc: %d\n\n", "a", "b", "c");

  /* This is the same as line 18. */
  // printf("a: %d\nb: %d\nc: %d\n\n", str[0], str[1], str[2]);

  /* 
   * This will generate 2 warinings: 
   * 1. warning: result of comparison against a string
   *    literal is unspecified (use strncmp instead)
   * 2. warning: comparison between pointer and integer
   *    ('int' and 'char *')
   * and the comparison will be false.
   */
  for(int i = 0; i < 3; i++) {
      printf("str[%d] == 'a': %d\n", i, str[i] == "a");
  }

  /* character comparison */
  for(int i = 0; i < 3; i++) {
      printf("str[%d] == 'a': %d\n", i, str[i] == 'a');
  }
  /* character comparison */
  for(int i = 0; i < 3; i++) {
      printf("str[%d] == a[0]: %d\n", i, str[i] == a[0]);
  }
  /* character comparison using ascii code */
  for(int i = 0; i < 3; i++) {
      printf("str[%d] == 97: %d\n", i, str[i] == 97);
  }

  /* string comparision */
  /* 
   * strcmp  - comparison will include null-terminator in C strings
   * strncmp - compares at most N characters of null-terminator in C strings
   * memcmp  - compares binary byte buffers of N bytes
   *
   */

  const char s1[] = "atoms\0\0\0\0";  // an extra null bytes at end
  const char s2[] = "atoms\0abc";     // embedded null byte
  const char s3[] = "atomsaaa";

  // The following expression will be true.
  // strcmp stops at null terminator
  if(strcmp(s1, s2) == 0) {
    printf("strcmp(s1, s2) == 0\n");
  }
  // strings are different
  if(strcmp(s1, s3) != 0) {
    printf("strcmp(s1, s3) != 0\n");
  }
  // first 5 characters of strings are the same
  if(strncmp(s1, s3, 5) == 0) {
    printf("strncmp(s1, s3, 5) == 0\n");
  }
  // first 5 bytes are the same
  if(memcmp(s1, s3, 5) == 0) {
    printf("memcmp(s1, s3, 5) == 0\n");
  }
  // strings are the same up through the null terminator
  /* 
   * int strncmp ( const char * str1, const char * str2, size_t num );
   * strcmp compares up to num characters of the C string str1 
   * to those of the C string str2.
   * This function starts comparing the first character of each string.
   * If they are equal to each other, it continues with the following pairs
   * until the characters differ, until a terminating null-character is reached, 
   * or until num characters match in both strings, whichever happens first.
   *
   */
  if(strncmp(s1, s2, 8) == 0) {
    printf("strncmp(s1, s2, 8) == 0\n");
  }
  // first 8 bytes are different
  if(memcmp(s1, s2, 8) != 0) {
    printf("memcmp(s1, s2, 8) != 0\n");
  }

  return 0;
}

