/* FUN_80163168
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163168  body 0x80163168..0x8016329f  size 312 B
 * body sha256 ed765b84217b545bec9221cad376dc3d24fb33732b43798908124ef88ce4cb68
 * provider record sha256 28692cd31e4e2af6cf2cd112c7a04f144828296bd081f1a687517cdbd6646254
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163168(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  uint uVar1;
  undefined1 *puVar3;
  undefined2 uVar4;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar3 = &DAT_800e1130;
  }
  else {
    puVar3 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    sVar2 = FUN_80166d64(param_1,*(undefined4 *)(puVar3 + 0x28),*(undefined4 *)(puVar3 + 0x30),1);
    *(short *)(param_1 + 500) = -sVar2;
    if (sVar2 == 0) {
      uVar1 = func_0x80033604();
      uVar4 = 0xffff;
      if ((uVar1 & 1) != 0) {
        uVar4 = 1;
      }
      *(undefined2 *)(param_1 + 500) = uVar4;
    }
    *(undefined2 *)(param_1 + 0x1f6) = 0x400;
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) * 6;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 500);
  *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -6;
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80089d54(param_1,param_2,param_3,0x40);
  if (*(short *)(param_1 + 0x1f6) < 0) {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_80162948(param_1);
  return;
}
