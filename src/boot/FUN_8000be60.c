/* FUN_8000be60
 * image   boot (boot), base 0x80000480
 * address 0x8000be60  body 0x8000be60..0x8000bfef  size 400 B
 * body sha256 16a21d2848229a3e9abb29dad6833f612c4a18bd9efe991b33da83d67bbe6bc3
 * provider record sha256 5da7b42e08424a451000429f15084bf737420bc310aea1b8a9dd741b1f838c39
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000be60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (_DAT_800128f0 == 0) {
    osCreateMesgQueue(param_2,param_3,param_4);
    osCreateMesgQueue(0x80017660,0x80017678,1);
    if (_DAT_80012920 == 0) {
      FUN_8000c780();
    }
    osSetEventMesg(8,0x80017660,0x22222222);
    iVar1 = FUN_80007010(0);
    iVar3 = -1;
    if (iVar1 < param_1) {
      FUN_8000cdf0(0,param_1);
      iVar3 = iVar1;
    }
    uVar2 = FUN_800072e0();
    _DAT_800128f0 = 1;
    _DAT_80012900 = 0x80017710;
    _DAT_80012904 = pi_dma_raw;
    _DAT_80012908 = pi_dma_programmer;
    _DAT_800128f4 = 0x800164b0;
    _DAT_800128fc = 0x80017660;
    _DAT_800128f8 = param_2;
    osCreateThread(0x800164b0,0,FUN_8000c0d0,&DAT_800128f0,0x80017660,param_1);
    osStartThread(0x800164b0);
    FUN_80007300(uVar2);
    if (iVar3 != -1) {
      FUN_8000cdf0(0,iVar3);
    }
  }
  return;
}
