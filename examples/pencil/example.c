
#include <stdio.h>
#include <sys/time.h>

void inner(int m, float col[static const restrict m], int k) {
	for (int j = 0; j<m; ++j) {
		col[j] = k;
	}
}

void kernel(int n, int m, float A[static const restrict n][m]);

static double get_time() {
	struct timeval Tp;
	int stat;

	stat = gettimeofday (&Tp, NULL);
	if (stat != 0)
		fprintf(stderr, "Error return from gettimeofday: %d", stat);
	return Tp.tv_sec + Tp.tv_usec * 1.0e-6;
}

int main() {
	printf("Kernel start\n");
	float A[128][128];
	double start_time = get_time();
	kernel(128, 128, A);
	double stop_time = get_time();
	printf("Kernel end, took %f secs\n", stop_time-start_time);
	return 0;
}
