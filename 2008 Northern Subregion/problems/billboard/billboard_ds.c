#include <stdio.h>
#define max(a,b) (((a)<(b))?(b):(a))

int heap [524288];

FILE* in;
FILE* out;

int h, round_h, w, n;

int round_deg (int n) {
	int res = 1;
	while (res < n) res += res;
	return res;
}

int fill_heap (int h, int w) {
	int i, j;
	for (i = 0; i < sizeof (heap) / sizeof (*heap); i++) heap [i] = 0;
	for (i = round_h; i < round_h+h; i++) heap [i] = w;
	for (j = round_h >> 1; j; j >>= 1) {
		for (i = j; i < j*2; i++) {
			heap [i] = max (heap [2*i], heap [2*i+1]);
		}
	}
}

void print_heap () {
	int t;
	for (t = 0; t < round_h * 2; t++)
		printf ("%d ", heap [t]);
	printf ("\n");
}

int use (int i, int w, int * mx) {
	int id = -1;
	int k = 0;
	for (k = 0; k < 2; k++) {
		if (i < round_h && round_h > 1) {
			if (heap [i+k] >= w) {
				id = use (2*(i+k), w, heap + i+k); 
				break;
			}
		}
		else if (heap [i+k] >= w) {
			id = i+k - round_h + 1;
                	heap [i+k] -= w;
                	break;
		}
	}
	*mx = max (heap [i], heap [i+1]);
	return id;
}

int main () {
	int i;

	in = fopen ("billboard.in", "rt");
	out = fopen ("billboard.out", "wt");
	fscanf (in, "%d %d %d\n", &h, &w, &n);

	round_h = round_deg (h);

	fill_heap (h, w);

	for (i = 0; i < n; i++) {
		int _tmp;
		int sz;
		fscanf (in, "%d\n", &sz);
		fprintf (out, "%d\n", use (0, sz, &_tmp));
	}
 
	fclose (in);
	fclose (out);
	return 0;
}
