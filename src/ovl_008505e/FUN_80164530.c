/* FUN_80164530
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164530  body 0x80164530..0x801646e3  size 436 B
 * body sha256 d0644af555cdf252c73cc045bc9c83a4226f53af080519c72b7eb5a695b64d83
 * provider record sha256 54f180ec9d43252f7a8425384bfb9ade7d7fb3299fc671dacbc8b6163559728b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164530(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  undefined2 uVar4;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        uVar3 = (uint)*(ushort *)(param_1 + 0x66) + (uint)*(ushort *)(param_1 + 0x1f6) & 0xfff;
        *(short *)(param_1 + 0x66) = (short)uVar3;
        if (uVar3 - 0x780 < 0x101) {
          uVar3 = func_0x80033604(param_1);
          if ((0x1b68 >> (uVar3 & 0xf) & 1U) == 0) {
            *(undefined1 *)(param_1 + 7) = 3;
            *(undefined2 *)(param_1 + 0x1f6) = 0;
          }
          else {
            *(undefined1 *)(param_1 + 5) = 0xf;
            *(undefined2 *)(param_1 + 6) = 1;
          }
        }
      }
      else if ((bVar1 == 3) && ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
        *(undefined2 *)(param_1 + 6) = 0;
      }
      goto LAB_801646a0;
    }
    if (bVar1 != 0) goto LAB_801646a0;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0xf0;
    uVar3 = func_0x80033604(param_1);
    *(ushort *)(param_1 + 500) = (ushort)(byte)(&DAT_80166c88)[uVar3 & 7];
    uVar3 = func_0x80033604();
    uVar4 = 0xff81;
    if ((uVar3 & 1) != 0) {
      uVar4 = 0x7f;
    }
    *(undefined2 *)(param_1 + 0x1f6) = uVar4;
    uVar3 = func_0x80033604();
    if ((uVar3 & 1) != 0) {
      *(short *)(param_1 + 0x1f6) = -*(short *)(param_1 + 0x1f6);
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
  }
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
  if (sVar2 == 1) {
    *(undefined1 *)(param_1 + 7) = 2;
  }
LAB_801646a0:
  func_0x80032b5c(param_1,0);
  FUN_80166590(param_1,(int)*(short *)(param_1 + 0x1f6));
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
