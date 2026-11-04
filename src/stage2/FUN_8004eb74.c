/* FUN_8004eb74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004eb74  body 0x8004eb74..0x8004eccb  size 344 B
 * body sha256 53a98f3cd6dd6180b49c80c3158e316af37edaa5b0e59565fe0e0a316874de32
 * provider record sha256 9b6c2f3e3e4ebbe3cf6b15b2b258a39194a2aab401bc6cc8edad70278aa96f4e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8004eb74(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short local_18 [2];
  short local_14;
  
  local_14 = 0;
  local_18[0] = (short)(((uint)*(ushort *)(param_1 + 0x136) * 0x87) / 100) + 0x80;
  FUN_800837d0((int)*(short *)(param_1 + 0x66),local_18,local_18);
  iVar3 = *(int *)(param_2 + 0x28) - *(int *)(param_1 + 0x28);
  iVar2 = *(int *)(param_2 + 0x30) - *(int *)(param_1 + 0x30);
  iVar5 = *(ushort *)(param_2 + 300) - 0x80;
  iVar6 = *(ushort *)(param_2 + 0x12e) - 0x80;
  if (((uint)(iVar3 + iVar5) <= (uint)(iVar5 * 2)) ||
     (bVar1 = false, (uint)(iVar2 + iVar6) <= (uint)(iVar6 * 2))) {
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < iVar3) {
      iVar4 = (int)(short)(local_18[0] + *(short *)(param_1 + 0x2a));
      iVar3 = *(int *)(param_2 + 0x120);
      iVar2 = *(int *)(param_1 + 0x30);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x28);
      iVar3 = *(int *)(param_2 + 0x120);
      iVar2 = (int)(short)(local_14 + *(short *)(param_1 + 0x32));
    }
    if ((uint)(iVar5 * 2) < (uint)((iVar4 - iVar3) + iVar5)) {
      bVar1 = false;
    }
    else {
      bVar1 = (uint)((iVar2 - *(int *)(param_2 + 0x128)) + iVar6) <= (uint)(iVar6 * 2);
    }
  }
  return bVar1;
}
