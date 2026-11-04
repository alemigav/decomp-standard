/* FUN_8016598c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016598c  body 0x8016598c..0x80165a87  size 252 B
 * body sha256 ece341ac9a13c1c8e8a4db38c190f93c289c8c5d7d8f8f14d0a4e0307cd8160b
 * provider record sha256 1141ff4bb3f90c23a0d69f9eda0041d3e84f7e90a18ef9db4a756f243ba96ea5
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016598c(uint *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  func_0x80089d54();
  func_0x80032bd8(param_1,0,0);
  *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  iVar2 = FUN_801679f4(param_1,0,0,0);
  if (iVar2 != 0) {
    uVar3 = 5;
    *(undefined1 *)((int)param_1 + 6) = 2;
    *param_1 = *param_1 & 0xe7ffffff | 0x4000000;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    *param_1 = *param_1 | 0x42;
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      uVar3 = 6;
    }
    func_0x80077d18(uVar3,param_1);
    FUN_80165a88(param_1);
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      bVar1 = *(byte *)(param_1 + 0xb6);
      if ((8 < bVar1) && ((bVar1 < 0xb || (bVar1 == 0x10)))) {
        FUN_8016703c(param_1,0,7);
      }
    }
  }
  return;
}
