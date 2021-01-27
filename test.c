#include <stdio.h>
int main() {
	int i = 5;
	unsigned int ui = 42e8;
	char c = 'c';
	float f = 3.141592;
	char *s = "hello world";

	//printf("hello", a); //hello
	printf("%d\n", s);
	printf("%p\n", s);
	printf("%.10d\n", i);
	printf("%0*.*d\n", 5, 4, 5);
	printf("%d", 123, 4, 22);
}
