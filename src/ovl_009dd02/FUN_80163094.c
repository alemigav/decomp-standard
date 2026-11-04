/* FUN_80163094
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163094  body 0x80163094..0x80163167  size 212 B
 * body sha256 8b378d0d1b644e06046b9eb7191f27c1876110b555073b00bd725321a3ef1780
 * provider record sha256 9aa2f5320a466fc5f8f0b669e5fff2a53ef6290644caf0d2017f8e4711872930
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163094(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
    *(uint *)(param_1 + 0x1e8) = ((uint)*(byte *)(param_1 + 0x2cd) * 0xd + 5) * 0x1000000;
  }
  sVar3 = *(short *)(param_1 + 0x130) + 0x2b;
  if (*(char *)(param_1 + 0x2cd) == '\0') {
    sVar3 = *(short *)(param_1 + 0x130) + -0x2b;
  }
  *(short *)(param_1 + 0x130) = sVar3;
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    uVar2 = func_0x80033604();
    *(undefined *)(param_1 + 700) = (&DAT_80167298)[uVar2 & 7];
    FUN_80162f98();
  }
  return;
}
