/* FUN_8005791c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005791c  body 0x8005791c..0x80057c53  size 824 B
 * body sha256 f85deafb767f61a9bc8c45527aec7290476055cee9582e02b5a4e47941065733
 * provider record sha256 e85d4fb4fb1478a47da8b74844397ea87d7068e1db6f22d2659bfd5b4efc9cab
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005791c(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  byte local_20 [8];
  
  local_20[0] = 0x50;
  local_20[1] = 0x30;
  local_20[2] = 0x20;
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
  if ((((param_2 & 10) == 0) && (-0x1a < DAT_800df8c0)) && (DAT_800df8c0 < '\x1a')) {
    FUN_800551e0();
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  if (DAT_800e8b3e < 2) {
    iVar2 = (int)DAT_800df8c1;
  }
  else {
    fVar4 = (float)((int)DAT_800df8c0 * (int)DAT_800df8c0 + (int)DAT_800df8c1 * (int)DAT_800df8c1);
    fVar3 = (float)FUN_80048060(fVar4);
    iVar2 = (int)(fVar4 * fVar3);
    DAT_8010dd70 = iVar2;
  }
  if (((param_2 & 4) != 0) && (iVar2 < -0x19)) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  if (((((param_2 & 1) != 0) || (0x19 < iVar2)) &&
      ((*(undefined4 *)(param_1 + 4) = 0x1010000, (param_2 & 0x200) != 0 || (0x40 < iVar2)))) &&
     ((DAT_800e110c & 0x2000) == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  if ((param_2 & 2) == 0) {
    if ((param_2 & 8) == 0) {
      FUN_80055234(param_1,local_20[*(char *)(param_1 + 0x1ed)]);
    }
    else {
      *(ushort *)(param_1 + 0x66) =
           *(short *)(param_1 + 0x66) - (ushort)local_20[*(char *)(param_1 + 0x1ed)];
    }
  }
  else {
    *(ushort *)(param_1 + 0x66) =
         *(short *)(param_1 + 0x66) + (ushort)local_20[*(char *)(param_1 + 0x1ed)];
  }
  if (((param_2 & 0x80) != 0) || ((param_3 & 0x80) != 0)) {
    if ((*(ushort *)(param_1 + 0x1ac) & 0x10) != 0) {
      FUN_80069854(param_1,0x1c2,DAT_80112718);
      return;
    }
    iVar2 = FUN_8004e438(*(byte *)(param_1 + 8) + 4);
    if (iVar2 != 0) {
      return;
    }
    if ((param_3 & 0x80) != 0) {
      DAT_800e110c = DAT_800e110c | 0x200000;
    }
  }
  if (((param_2 & 0x100) != 0) && ((*(ushort *)(param_1 + 0x1aa) & 0xfff) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  return;
}
