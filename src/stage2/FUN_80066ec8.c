/* FUN_80066ec8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80066ec8  body 0x80066ec8..0x80067027  size 352 B
 * body sha256 86d6287eb90bbbccb4eab40712a15ae8d9bef9b57c932c032bd0c4b9761a497f
 * provider record sha256 0480d05aa4ab74832ac43445130da79d42ab19b6e183a15343e2e8e850f5d48b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80066ec8(int param_1,undefined4 param_2,short *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)*(ushort *)(param_1 + 300) * 2 + (uint)(ushort)param_3[2];
  uVar2 = ((int)*(short *)(param_1 + 0x1b4) + (uint)*(ushort *)(param_1 + 300)) - (int)*param_3;
  uVar3 = ((int)*(short *)(param_1 + 0x1b6) + (uint)*(ushort *)(param_1 + 0x12e)) - (int)param_3[1];
  bVar4 = (uVar6 <= uVar2) << 1 |
          (uint)*(ushort *)(param_1 + 0x12e) * 2 + (uint)(ushort)param_3[3] <= uVar3;
  if ((uVar2 == 0xffffffff) || (uVar2 == uVar6 + 1)) {
    bVar4 = 2;
  }
  if (uVar3 == 0xffffffff) {
    bVar4 = 1;
  }
  else if (uVar3 == (uint)(ushort)param_3[3] + (uint)*(ushort *)(param_1 + 0x12e) * 2 + 1) {
    bVar4 = 1;
  }
  if (bVar4 == 0) {
    uVar1 = FUN_80066e28(param_1,param_2);
  }
  else {
    if ((bVar4 & 2) != 0) {
      iVar5 = (uint)*(ushort *)(param_1 + 300) + (uint)((ushort)param_3[2] >> 1) + 1;
      if (-1 < *(int *)(param_1 + 0x120) - (int)*(short *)(param_1 + 0x1b4)) {
        iVar5 = -iVar5;
      }
      *(uint *)(param_1 + 0x120) = (int)*param_3 + (uint)((ushort)param_3[2] >> 1) + iVar5;
    }
    if ((bVar4 & 1) == 0) {
      uVar1 = 1;
    }
    else {
      iVar5 = (uint)*(ushort *)(param_1 + 0x12e) + (uint)((ushort)param_3[3] >> 1) + 1;
      if (-1 < *(int *)(param_1 + 0x128) - (int)*(short *)(param_1 + 0x1b6)) {
        iVar5 = -iVar5;
      }
      *(uint *)(param_1 + 0x128) = (int)param_3[1] + (uint)((ushort)param_3[3] >> 1) + iVar5;
      uVar1 = 1;
    }
  }
  return uVar1;
}
