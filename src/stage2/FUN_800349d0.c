/* FUN_800349d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800349d0  body 0x800349d0..0x80034bdb  size 524 B
 * body sha256 bd391078b7167e273a70c6327a018c4c862f6000274bf04851509fead54e2e98
 * provider record sha256 c433e3d2393905591173f9000f3f30c7f2b1af1e27f4b502f9912567f2fd1f64
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800349d0(int param_1,int param_2,undefined2 *param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_40 [2];
  ushort local_3e;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if ((*(byte *)(param_1 + 0x25c) & 1) == 0) {
    iVar9 = *(int *)(param_1 + 0x250);
    uVar1 = *(ushort *)(*(int *)(param_1 + 0x234) + 0x5a);
    iVar10 = param_2 + (uint)uVar1;
    iVar4 = *(int *)(iVar9 + 0x234) + (uint)*(byte *)(iVar9 + 0x25d) * 0x178;
    iVar8 = *(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178;
    local_38 = *(undefined4 *)(iVar4 + 0x4c);
    local_34 = *(undefined4 *)(iVar4 + 0x50);
    local_30 = *(undefined4 *)(iVar4 + 0x54);
    local_2c = *(undefined4 *)(iVar4 + 0x58);
    FUN_80034bdc(iVar8 + 0x4c,&local_38,auStack_40,iVar10 * 0x10000 >> 0x10);
    sVar3 = (short)param_2;
    if ((*(byte *)(param_1 + 0x25c) & 2) != 0) {
      local_3e = uVar1 + sVar3 + *(short *)(iVar8 + 0x5a);
    }
    if (param_1 == iVar9) {
      local_3e = uVar1 + sVar3 + *(short *)(iVar8 + 0x5a);
    }
    uVar7 = (uint)*(ushort *)(iVar8 + 0x134);
    sVar6 = *(short *)(iVar8 + 0x138);
    if ((*(byte *)(param_1 + 0x25c) & 0x80) != 0) {
      uVar7 = (uint)*(byte *)(iVar8 + 0x13c);
    }
    uVar5 = ((int)(short)local_3e - (int)sVar3) - (int)(short)uVar1;
    if ((int)sVar6 << 1 < (int)(uVar5 + (int)sVar6 & 0xfff)) {
      sVar2 = -sVar6;
      if ((uVar5 & 0x800) == 0) {
        sVar2 = sVar6;
      }
      local_3e = (short)iVar10 + sVar2;
    }
    sVar6 = *(ushort *)(iVar8 + 0x130) - (short)uVar7;
    uVar5 = uVar7 + ((uint)local_3e -
                    ((uint)*(ushort *)(iVar8 + 0x130) +
                    (uint)uVar1 + param_2 + (uint)*(ushort *)(iVar8 + 0x5a)));
    *(short *)(iVar8 + 0x130) = sVar6;
    if ((uVar5 & 0x800) == 0) {
      *(short *)(iVar8 + 0x130) = sVar6 + (short)uVar7 * 2;
    }
    if ((int)(uVar5 & 0xfff) < (int)(uVar7 << 0x10) >> 0xf) {
      *(ushort *)(iVar8 + 0x130) = local_3e - (uVar1 + sVar3 + *(short *)(iVar8 + 0x5a));
    }
    *param_3 = *(undefined2 *)(iVar8 + 0x130);
  }
  return;
}
