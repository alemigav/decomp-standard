/* FUN_80166b98
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166b98  body 0x80166b98..0x80166ccb  size 308 B
 * body sha256 804e7143a16f1f93b25ed2ae9a4d7e28de2efc152895eac0e14e2fff1e1e44ed
 * provider record sha256 13ecb4974cbe78e8aca32f427325eddbbda977111cd50450a06fe6f67e5da660
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166b98(int param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar3 = (param_3 & 0xff) * 6;
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar1 = &DAT_800e1130;
  }
  else {
    puVar1 = _DAT_800e13ec;
  }
  sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)*(short *)(puVar1 + 0x2a),(int)*(short *)(puVar1 + 0x32));
  iVar4 = *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178;
  if (((&DAT_801673b4)[iVar3] & 0x80) == 0) {
    local_18 = *(undefined2 *)(iVar4 + 0x4e);
    local_16 = *(undefined2 *)(iVar4 + 0x52);
    iVar5 = -0x7ff16fd8;
    local_14 = *(undefined2 *)(iVar4 + 0x56);
  }
  else {
    iVar5 = iVar4 + 0x38;
    local_14 = 0;
    local_16 = 0;
    local_18 = 0;
  }
  func_0x80037780(((byte)(&DAT_801673b4)[iVar3] & 0x7f) << 0x18 |
                  ((uint)(byte)(&DAT_801673b5)[iVar3] + (uint)*(ushort *)(&DAT_801673b6 + iVar3)) *
                  0x10000 | (uint)*(ushort *)(&DAT_801673b8 + iVar3),(int)sVar2,iVar5,&local_18);
  return;
}
