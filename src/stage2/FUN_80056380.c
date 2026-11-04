/* FUN_80056380
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80056380  body 0x80056380..0x800566eb  size 876 B
 * body sha256 c39acf3ec663c1324ef3971715abb4ff8492e68e0295dace2d3112118be1c71f
 * provider record sha256 3cff8323ef6b216aba10201fb0554610ca99da9de4083c2a46fe4439091985f6
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80056380(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  byte local_28 [8];
  
  local_28[0] = 0x28;
  local_28[1] = 0x20;
  local_28[2] = 0x10;
  if ((*(char *)(param_1 + 6) == '\0') || (*(char *)(param_1 + 0x1e9) == '\0')) {
    cVar1 = *(char *)(param_1 + 0x1ed);
    *(undefined1 *)(param_1 + 0x1ed) = 0;
    if (*(short *)(param_1 + 0x1f2) < 0x65) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (DAT_800e13e4 != 0) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (*(short *)(param_1 + 0x1f2) < 0x15) {
      *(undefined1 *)(param_1 + 0x1ed) = 2;
    }
    if (cVar1 != *(char *)(param_1 + 0x1ed)) {
      *(undefined1 *)(param_1 + 6) = 0;
    }
  }
  if (DAT_800e8b3e < 2) {
    iVar3 = (int)DAT_800df8c1;
  }
  else {
    fVar5 = (float)((int)DAT_800df8c0 * (int)DAT_800df8c0 + (int)DAT_800df8c1 * (int)DAT_800df8c1);
    fVar4 = (float)FUN_80048060(fVar5);
    iVar3 = (int)(fVar5 * fVar4);
    DAT_8010dd70 = iVar3;
  }
  if (((param_2 & 1) == 0) && (iVar3 < 0x1a)) {
    FUN_800551e0();
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    if ((((param_2 & 10) != 0) || (DAT_800df8c0 < -0x19)) || ('\x19' < DAT_800df8c0)) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
    uVar2 = 0x1030000;
    if ((param_2 & 4) == 0) {
      if (iVar3 < -0x19) {
        *(undefined4 *)(param_1 + 4) = 0x1030000;
        return;
      }
      return;
    }
    goto LAB_800566c8;
  }
  if ((param_2 & 2) == 0) {
    if ((param_2 & 8) == 0) {
      FUN_80055234(param_1,local_28[*(char *)(param_1 + 0x1ed)]);
    }
    else {
      *(ushort *)(param_1 + 0x66) =
           *(short *)(param_1 + 0x66) - (ushort)local_28[*(char *)(param_1 + 0x1ed)];
    }
  }
  else {
    *(ushort *)(param_1 + 0x66) =
         *(short *)(param_1 + 0x66) + (ushort)local_28[*(char *)(param_1 + 0x1ed)];
  }
  if (((param_2 & 0x200) == 0) && (iVar3 < 0x41)) {
LAB_8005660c:
    if ((DAT_800e110c & 0x2000) != 0) goto LAB_80056630;
  }
  else {
    if ((DAT_800e110c & 0x2000) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      goto LAB_8005660c;
    }
LAB_80056630:
    *(undefined4 *)(param_1 + 4) = 0x10a0000;
  }
  if (((param_2 & 0x80) != 0) || ((param_3 & 0x80) != 0)) {
    if ((*(ushort *)(param_1 + 0x1ac) & 0x10) != 0) {
      FUN_80069854(param_1,0x1c2,DAT_80112718);
      return;
    }
    iVar3 = FUN_8004e438(*(byte *)(param_1 + 8) + 4);
    if (iVar3 != 0) {
      return;
    }
    if ((param_3 & 0x80) != 0) {
      DAT_800e110c = DAT_800e110c | 0x200000;
    }
  }
  if ((param_2 & 0x100) == 0) {
    return;
  }
  uVar2 = 0x1050000;
  if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0) {
    return;
  }
LAB_800566c8:
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
