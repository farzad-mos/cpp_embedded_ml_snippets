# QNX RTOS for ML Engineers: IPC & Scheduling Cheatsheet

## Why QNX?
QNX is a microkernel RTOS used in safety-critical automotive systems (e.g., Audi MIB, BMW iDrive).

---

## Real-Time Scheduling

```cpp
#include <sched.h>
#include <pthread.h>

struct sched_param param;
param.sched_priority = 10;
pthread_setschedparam(pthread_self(), SCHED_FIFO, &param);
```

Scheduling policies:
- `SCHED_FIFO`: strict real-time
- `SCHED_RR`: round robin
- `SCHED_OTHER`: default

Use Momentics IDE to analyze thread priority and CPU usage.

---

## IPC: Message Passing

```cpp
#include <sys/neutrino.h>

int coid = ConnectAttach(0, pid, chid, 0, 0);
MsgSend(coid, &tx_data, sizeof(tx_data), &rx_data, sizeof(rx_data));
```

- `MsgSend()` → synchronous message passing
- `PulseAttach()` → async notification
- `ChannelCreate()` → setup server thread

---

## Shared Memory

```cpp
int fd = shm_open("myshm", O_RDWR | O_CREAT, 0666);
ftruncate(fd, 4096);
void* mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
```

---

## Debugging

- `pidin` → process, memory, and thread info
- `perf` → analyze context switches
- Momentics IDE → trace profiling

---

## Resources

- [QNX Dev Hub](https://www.qnx.com/developers/docs)
- [Momentics IDE Download](https://www.qnx.com/download)