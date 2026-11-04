/* FUN_80162454
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162454  body 0x80162454..0x801625ff  size 428 B
 * body sha256 c0dc3947d1abae71a7cf3ba103c3634c052c9c9cd46a519e84933d14ab034505
 * provider record sha256 ae349a55066f1527acdb140ad6ac9a1863b178846e6adb2120519577fe8d366d
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162454(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar3;
  short sVar4;
  uint uVar2;
  short sVar5;
  
  if (*(char *)(param_1 + 6) == '\0') {
    iVar1 = *(int *)(&DAT_80167de8 + (*(byte *)(param_1 + 5) - 1) * 0xc);
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(int *)(param_1 + 0x1e8) = iVar1 * 0x1000000 + 0x300;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = uVar3 & 0x2e;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_801625d8;
  sVar4 = FUN_80166b04(param_1,(int)*(short *)(&DAT_80167dee + (*(byte *)(param_1 + 5) - 1) * 0xc));
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar4;
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  FUN_801669f8(param_1,1);
  *(undefined2 *)(param_1 + 0x1f6) = *(undefined2 *)(param_1 + 0x1e0);
  sVar4 = (&DAT_80167df2)[(*(byte *)(param_1 + 5) - 1) * 6];
  sVar5 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar5;
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + sVar4;
  if (sVar5 != -1) {
    if (*(char *)(param_1 + 0x2be) != '\0') goto LAB_801625d8;
    if (*(char *)(param_1 + 0x2d3) == '\0') {
      uVar2 = *(uint *)(param_1 + 0x28c);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
    }
    if (0x5db < uVar2) goto LAB_801625d8;
  }
  *(undefined4 *)(param_1 + 4) = 0x1000000;
LAB_801625d8:
  func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
  return;
}
