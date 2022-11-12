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

shlang_free(q);

```

# Installation

Shlang follows [bochka](https://github.com/vhgn/bochka) system guides.
If you add this repository URL to your `Bochkadeps` and run `bochka`,
it will do everything automatically.

Alternatively you can run `make` to run tests and create library archives.

# Logic

Queue contains:

- index (`ptr`) to transmit new data there
- pointer to the receiver with the lowest index (`min`)
- pointer to the receiver with the biggest index (`max`)
- array of data (`arr`) to read from

Receiver contains:

- index of the next place it should read from (`ptr`)
- pointer to the queue it follows (`queue`)
- pointer to the receiver that is ahead of it (`next`)

When you request a new receiver:

- Assigns its index to next to be transmitted index
- Assigns itself as the furthest listener of queue
- Assigns itself as the closest listener of queue if it is the first

Reading data just increments the receiver pointer and rearranges listeners
Transmitting data increments the transmitter pointer