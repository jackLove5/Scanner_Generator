/*
 * A C program that prints the first n fibonacci numbers
 */

// #include <stdio.h>
int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: ./fib n where n is a positive integer\n");
    return -1;
  }

  int n;

  sscanf(argv[1], "%d", &n);
  if (n < 1)
  {
    fprintf(stderr, "Usage: ./fib n where n is a positive integer\n");
    return -1;
  }

  int i;
  for (i = 0; i < n && i < 2; i++)
  {
    printf("1\n");
  }

  unsigned last = 1;
  unsigned second_last = 1;
  for (; i < n; i++)
  {
    unsigned curr = last + second_last;
    printf("%d\n", curr);
    second_last = last;
    last = curr;
  }

  return 0;
}
