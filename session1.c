#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void init_vector(double* v, size_t len, ptrdiff_t incr) {
   for (size_t i = 0; i < len; ++i) {
      v[i*incr] = i + 1;
   }
}

void print_vector(double* v, size_t len, ptrdiff_t incr) {
   for (size_t i = 0; i < len; ++i) {
      printf(" %4.1lf", v[i*incr]);
   }
   printf("\n");
}

int main() {
   size_t maxlen;
   printf("size of the array: ");
   if (scanf("%zu", &maxlen) != 1) return 1;
   double* vector = malloc(sizeof(double)*maxlen);
   if (!vector) {
      printf("out of memory\n"); return 1;
   }

   double* x = vector;
   printf("initialize x as one vector\n");
   size_t len = maxlen;
   init_vector(x, len, 1);
   printf("x =      "); print_vector(x, len, 1);

   printf("using the space for two vectors\n");
   len = maxlen/2;
   double* y = vector + len;
   init_vector(x, len, 1); init_vector(y, len, 1);
   printf("x =      "); print_vector(x, len, 1);
   printf("y =      "); print_vector(y, len, 1);
   printf("vector = "); print_vector(vector, maxlen, 1);

   printf("using the space for two interleaving vectors\n");
   y = vector + 1;
   init_vector(x, len, 2); init_vector(y, len, 2);
   printf("x =      "); print_vector(x, len, 2);
   printf("y =      "); print_vector(y, len, 2);
   printf("vector = "); print_vector(vector, maxlen, 1);
}