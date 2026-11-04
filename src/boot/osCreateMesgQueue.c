/* osCreateMesgQueue
 * image   boot (boot), base 0x80000480
 * address 0x80006d30  body 0x80006d30..0x80006d53  size 36 B
 * body sha256 8816a6821dc97e5cdbbdeb27939d7d01ac4ba02a5c93df92a73da3ee8b93e177
 * recovered byte-exact (osmq: 9 of 9)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as OSMQ_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef int s32;
typedef unsigned int u32;
typedef struct OSThread_s OSThread;
typedef void *OSMesg;

typedef struct {
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;

extern OSThread __osThreadTail;

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count)
{
    mq->mtqueue = (OSThread *)&__osThreadTail;
    mq->fullqueue = (OSThread *)&__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}
