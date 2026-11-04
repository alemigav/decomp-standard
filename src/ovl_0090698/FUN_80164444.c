/* FUN_80164444
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164444  body 0x80164444..0x801645e7  size 420 B
 * body sha256 6e2704cd8282e497936863a65c2c7dc4cff29ad4baf340653a7807176234a9db
 * provider record sha256 d76b4e4367d80cc96c382866e9f1fed986ae9be69e0f549a7ceb3ffa909f8951
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164444(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar3;
  int iVar2;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
      }
      else {
        if (bVar1 != 3) goto LAB_801645c4;
        iVar2 = FUN_80162c2c(param_1,param_2,param_3);
      }
      if (iVar2 != 0) {
        *(undefined1 *)(param_1 + 5) = 4;
        *(undefined2 *)(param_1 + 6) = 0;
        *(undefined1 *)(param_1 + 0x2cd) = 0;
      }
      goto LAB_801645c4;
    }
    if (bVar1 != 0) goto LAB_801645c4;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x10;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000300;
  }
  sVar3 = FUN_80166f84(param_1,0x40);
  FUN_80166c70(param_1,(int)sVar3);
  if ((sVar3 == 0) ||
     (sVar3 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar3 + -1, sVar3 == 1)) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0xb000300;
    if (*(char *)(param_1 + 0x2d3) == '\0') {
      uVar4 = 0x89;
      if (2999 < *(uint *)(param_1 + 0x28c)) {
        uVar4 = 0x88;
      }
    }
    else {
      uVar4 = 0x89;
      if (2999 < (*(uint *)(param_1 + 0x290) & 0x3fffffff)) {
        uVar4 = 0x88;
      }
    }
    sVar3 = FUN_801645e8(param_1);
    FUN_801671ec(param_1,uVar4,(int)sVar3);
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
LAB_801645c4:
  func_0x80033648(param_1);
  return;
}
