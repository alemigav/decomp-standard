/* FUN_800068d0
 * image   boot (boot), base 0x80000480
 * address 0x800068d0  body 0x800068d0..0x80006a6b  size 412 B
 * body sha256 a1983ca424ce7072c8caa815a62349e30d38e6e92b9dd91f70e49059278bff90
 * provider record sha256 16ef9979c413f852e2ee9c91f94a8a5d7e10aac024d8900aef992480a9767827
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800068d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [24];
  undefined1 auStack_28 [8];
  
  if (_DAT_800128b0 == 0) {
    _DAT_800128b0 = 1;
    uVar2 = FUN_80007030();
    if (((int)((ulonglong)uVar2 >> 0x20) == 0) && ((uint)uVar2 < 0x165a0bc)) {
      osCreateMesgQueue(auStack_40,auStack_28,1);
      FUN_8000cec0(auStack_60);
      osRecvMesg(auStack_40,auStack_28,1);
    }
    DAT_80014f9c = 4;
    FUN_80006b20(0);
    FUN_8000d1f0(1,&DAT_80014fa0);
    osRecvMesg(param_1,auStack_28,1);
    uVar1 = FUN_8000d1f0(0,&DAT_80014fa0);
    osRecvMesg(param_1,auStack_28,1);
    FUN_80006a6c(param_2,param_3);
    DAT_80014fe0 = 0;
    FUN_8000cf60();
    osCreateMesgQueue(0x80014f80,0x80014f98,1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
