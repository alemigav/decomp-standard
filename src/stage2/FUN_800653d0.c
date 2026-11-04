/* FUN_800653d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800653d0  body 0x800653d0..0x80065627  size 600 B
 * body sha256 3f6cf1ba4319d08c54b08aefa099ee696c5e58d376709d3ab9e24c20ab89976a
 * provider record sha256 04719a425e6820445eceaabe76c81c73b57207d8ef287dd9bf657c60c3abd660
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800653d0(int param_1,undefined4 *param_2,uint param_3,char param_4)

{
  byte bVar5;
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  short unaff_s2;
  short unaff_s3;
  
  if ((*(byte *)(param_1 + 0x1ec) & 0x7f) == 0) {
    *(byte *)(param_1 + 0x1ec) = *(byte *)(param_1 + 0x1ec) | 7;
  }
  bVar5 = *(char *)(param_1 + 0x1ec) - 1;
  *(byte *)(param_1 + 0x1ec) = bVar5;
  if ((bVar5 & 0x80) == 0) {
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0xf7ff;
    iVar1 = FUN_8006ab40(*(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x4c
                         ,0x4c,0x2000);
    if (iVar1 == 0) {
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) | 0x800;
    }
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0x1000) != 0) {
    *(undefined2 *)(param_1 + 0x260) = *(undefined2 *)((int)param_2 + 2);
    *(undefined2 *)(param_1 + 0x262) = *(undefined2 *)((int)param_2 + 10);
    return 2;
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0x4000) != 0) {
    return 2;
  }
  if ((*(byte *)(param_1 + 0x1ec) & 0x80) != 0) {
    return 2;
  }
  uVar2 = FUN_8006568c((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32));
  uVar2 = uVar2 & 0xff;
  if (param_2 != (undefined4 *)0x0) {
    unaff_s2 = (short)*param_2;
    unaff_s3 = (short)param_2[2];
  }
  uVar3 = FUN_8006568c((int)unaff_s2,(int)unaff_s3);
  uVar3 = uVar3 & 0xff;
  if ((uVar2 == 0xff) || (uVar3 == 0xff)) {
    if (param_4 == '\0') {
      return 0;
    }
  }
  else if (param_4 == '\0') goto LAB_800655ac;
  uVar3 = param_3 & 0xff;
  iVar1 = *(int *)(DAT_800df92c + 0x38) + uVar3 * 0xc;
  unaff_s2 = (short)((int)*(short *)(iVar1 + 4) + (int)*(short *)(iVar1 + 8) >> 1);
  unaff_s3 = (short)((int)*(short *)(iVar1 + 6) + (int)*(short *)(iVar1 + 10) >> 1);
LAB_800655ac:
  if (uVar2 == uVar3) {
    uVar4 = 1;
    *(short *)(param_1 + 0x260) = unaff_s2;
    *(short *)(param_1 + 0x262) = unaff_s3;
  }
  else {
    uVar4 = 2;
    if (*(char *)(DAT_800df938 + 0x1ec) == '\0') {
      FUN_80065730(uVar2,uVar3,(int)unaff_s2,(int)unaff_s3);
      uVar4 = 1;
    }
  }
  return uVar4;
}
