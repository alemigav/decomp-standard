/* FUN_80166980
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166980  body 0x80166980..0x80166ac7  size 328 B
 * body sha256 5c84ceca5259fc3569fd47bb7ba45ff5c72ab1be4eacdcf5ea01b69653e8b45f
 * provider record sha256 f64664909c2988dfc6857930c8d272340d328525ccad133c4f8df3b58114a494
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166980(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  if (*(char *)(param_1 + 699) != '\0') {
    iVar2 = (param_3 & 0xff) * 6;
    iVar5 = param_1;
    if ((param_3 & 0xff) == 4) {
      iVar5 = -0x7ff1eed0;
    }
    uVar1 = func_0x80033604();
    iVar4 = *(int *)(iVar5 + 0x234) + (param_2 & 0x7f) * 0x178;
    if (((&DAT_80166f7c)[iVar2] & 0x80) == 0) {
      local_20 = *(undefined2 *)(iVar4 + 0x4e);
      iVar3 = -0x7ff16fd8;
      local_1e = *(undefined2 *)(iVar4 + 0x52);
      local_1c = *(undefined2 *)(iVar4 + 0x56);
    }
    else {
      iVar3 = iVar4 + 0x38;
      local_20 = 0;
      local_1e = 0;
      local_1c = 0;
    }
    func_0x80037780(((byte)(&DAT_80166f7c)[iVar2] & 0x7f) << 0x18 |
                    (uint)(byte)(&DAT_80166f7d)[iVar2] << 0x10 |
                    (uint)*(ushort *)(&DAT_80166f80 + iVar2),
                    (int)((((int)*(short *)(iVar5 + 0x66) +
                           (uVar1 & 0xff & (uint)*(ushort *)(&DAT_80166f7e + iVar2) * 2 - 1)) -
                          (uint)*(ushort *)(&DAT_80166f7e + iVar2)) * 0x10000) >> 0x10,iVar3,
                    &local_20);
    *(char *)(param_1 + 699) = *(char *)(param_1 + 699) + -1;
  }
  return;
}
