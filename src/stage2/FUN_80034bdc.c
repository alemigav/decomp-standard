/* FUN_80034bdc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80034bdc  body 0x80034bdc..0x80034d3b  size 352 B
 * body sha256 ce5e728cf3a72070ae9baffe067f2e2ff1d934e8ec58e78bb98f2ec4e8087112
 * provider record sha256 8743e3b203b02b28579a7fe5345f12717336aa78fc14f857d6cee8022ea581b4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80034bdc(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *param_2 - *param_1;
  uVar3 = param_2[2] - param_1[2];
  uVar5 = param_1[1] - param_2[1];
  iVar1 = FUN_80040bb4(iVar4 * iVar4 + uVar3 * uVar3);
  if (uVar3 != 0) {
    *(ushort *)(param_3 + 2) = (ushort)((uVar3 & 0x80000000) == 0) * 0x800 + 0x400;
  }
  if (iVar4 != 0) {
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (uVar3 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    sVar2 = FUN_80040a14((int)(uVar3 * 0x1000) / iVar4);
    *(ushort *)(param_3 + 2) = (0x1000 - sVar2) - ((ushort)((uint)iVar4 >> 0x14) & 0x800) & 0xfff;
  }
  if (uVar5 != 0) {
    *(ushort *)(param_3 + 4) = (ushort)((uVar5 & 0x80000000) == 0) * 0x800 + 0xc00;
  }
  if (iVar1 != 0) {
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (uVar5 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    sVar2 = FUN_80040a14((int)(uVar5 * 0x1000) / iVar1);
    *(ushort *)(param_3 + 4) = 0x1000U - sVar2 & 0xfff;
  }
  return;
}
