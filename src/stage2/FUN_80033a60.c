/* FUN_80033a60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033a60  body 0x80033a60..0x80033b7b  size 284 B
 * body sha256 a19b0b2ac04115c5f6a56466a87ee2ca3749e6dcb351caeeb5a9b6cdb8abfe97
 * provider record sha256 49e22b806c5311c3a7c8a03a67e57dee308ed7f5e80d31905280e1dcf99f9af1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80033a60(short *param_1,short param_2,short param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  short local_24;
  short local_20 [2];
  short local_1c;
  
  if ((param_1 != (short *)0x0) && (*(char *)(param_1 + 7) != '\0')) {
    local_48 = 0x10000000;
    local_44 = 0;
    local_40 = 0x10000000;
    local_3c = 0;
    local_38 = 0x10000000;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    FUN_80041454((int)param_3,&local_48);
    local_28 = (int)*param_1;
    local_24 = param_1[1];
    FUN_8004276c(&local_48,&local_28,local_20);
    param_1[8] = param_3;
    sVar2 = *(short *)(*(int *)(param_1 + 10) + 2);
    param_1[5] = param_2;
    param_1[4] = local_20[0] + sVar2;
    bVar1 = *(byte *)(param_1 + 7);
    sVar2 = *(short *)(*(int *)(param_1 + 10) + 10);
    *(byte *)(param_1 + 7) = bVar1 | 4;
    param_1[6] = local_1c + sVar2;
    if (param_4 != 0) {
      *(byte *)(param_1 + 7) = bVar1 & 0xfb;
    }
  }
  return;
}
