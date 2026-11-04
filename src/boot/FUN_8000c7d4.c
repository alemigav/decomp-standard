/* FUN_8000c7d4
 * image   boot (boot), base 0x80000480
 * address 0x8000c7d4  body 0x8000c7d4..0x8000c83f  size 108 B
 * body sha256 a05664a38b281cd970ff21d8bf042f853b5d89352305e5725912c61c796a0b9c
 * provider record sha256 b4a0edd7638c2d3c223d5d68d945d8d1b06bfc3ac69d8f1618889e9c2f27f73e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000c7d4(void)

{
  undefined1 auStack_10 [8];
  
  if (_DAT_80012920 == 0) {
    _DAT_80012920 = 1;
    osCreateMesgQueue(0x80017710,0x80017700,1);
    osSendMesg(0x80017710,0,0);
  }
  osRecvMesg(0x80017710,auStack_10,1);
  return;
}
