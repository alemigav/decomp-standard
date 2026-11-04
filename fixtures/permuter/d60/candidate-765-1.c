
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef long long s64;
typedef unsigned long long u64;
typedef struct OSThread_s OSThread;
struct OSThread_s
{
  OSThread *next;
  s32 priority;
  void *queue;
  void *tlnext;
  u16 state;
  u16 flags;
  s32 id;
  s32 fp;
  u8 pad1c[0x38 - 0x1c];
  u64 a0;
  u8 pad40[0xf0 - 0x40];
  u64 sp;
  u8 padf8[0x100 - 0xf8];
  u64 ra;
  u8 pad108[0x118 - 0x108];
  u32 sr;
  u32 pc;
  u8 pad120[0x128 - 0x120];
  u32 rcp;
  u32 fpcsr;
};
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32 mask);
extern OSThread *__osActiveQueue;
extern void __osCleanupThread(void);
void osCreateThread(OSThread *thread, s32 id, void (*entry)(void *), void *arg, void *sp, s32 pri)
{
  OSThread **new_var;
  u32 prevInt;
  thread->id = id;
  thread->priority = pri;
  thread->next = 0;
  thread->queue = 0;
  thread->pc = (u32) entry;
  thread->a0 = (u64) ((s32) arg);
  thread->sp = ((u64) ((s32) sp)) - 16;
  thread->ra = (u64) ((s32) __osCleanupThread);
  thread->sr = 0xff03;
  thread->rcp = 0x3f;
  thread->fpcsr = 0x01000800;
  thread->fp = 0;
  thread->state = 1;
  new_var = &__osActiveQueue;
  thread->flags = 0;
  prevInt = __osDisableInt();
  thread->tlnext = *new_var;
  __osActiveQueue = thread;
  __osRestoreInt(prevInt);
}
