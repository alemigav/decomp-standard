/* osSetEventMesg
 * image   boot (boot), base 0x80000480
 * address 0x8000cc90  body 0x8000cc90..0x8000ccef  size 96 B
 * body sha256 bbc3e9c8f6358666e9cd19364afdde613bddbec38354f32f596d3e2f9164028d
 * recovered byte-exact (osev: 24 of 24)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as OSEV_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef int s32;
typedef unsigned int u32;
typedef void *OSMesg;
typedef struct { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct { OSMesgQueue *queue; OSMesg msg; } __OSEventState;

extern __OSEventState __osEventStateTab[];
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32 mask);

void osSetEventMesg(u32 e, OSMesgQueue *mq, OSMesg msg)
{
    u32 prevInt = __osDisableInt();
    __OSEventState *msgs = &__osEventStateTab[e];

    msgs->queue = mq;
    msgs->msg = msg;

    __osRestoreInt(prevInt);
}
