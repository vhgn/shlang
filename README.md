# Description

Shlang is a queue library written in C.
It allows to have multiple receivers and transmitters of any kind of data.

# Usage

```c
int x;
shlang_queue_t* q;
shlang_recv_t* r;

q = shlang_init(10, sizeof(int));
r = shlang_follow(q);

for (x = 0; x < 10; x++) {
  shlang_trans(q, &x);
}

for (x = 0; x < 10; x++) {
  int data = *(int*) shlang_get(r);
  printf("ptr: %zu data: %d\n", r->ptr, data);
}
```

# Installation

Shlang follows [bochka](https://github.com/vhgn/bochka) system guides.
If you add this repository URL to your `Bochkadeps` and run `bochka`,
it will do everything automatically.

Alternatively you can run `make` to run tests and create library archives.

# Logic

