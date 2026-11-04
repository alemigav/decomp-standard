/* FUN_80056f70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80056f70  body 0x80056f70..0x8005721f  size 688 B
 * body sha256 33a6382e9776abbc37a0f5535f7e8648a5432a7386848df886fcfcfd7a0a9e49
 * provider record sha256 81fa2d4af9fe7a30a5056169d8eba9d53a4c8b261ae375728d2f3a992a6c13cc
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80056f70(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  byte local_28 [8];
  
  local_28[0] = 0x28;
  local_28[1] = 0x10;
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
  if (((param_2 & 4) == 0) && (-0x1a < iVar3)) {
    FUN_800551e0();
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    if ((((param_2 & 10) != 0) || (DAT_800df8c0 < -0x19)) || ('\x19' < DAT_800df8c0)) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
    uVar2 = 0x1010000;
    if ((param_2 & 1) == 0) {
      if (iVar3 < 0x1a) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      return;
    }
  }
  else {
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
    if ((param_3 & 0x80) != 0) {
      DAT_800e110c = DAT_800e110c | 0x200000;
    }
    if ((param_2 & 0x100) == 0) {
      return;
    }
    uVar2 = 0x1050000;
    if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
