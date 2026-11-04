/* FUN_800347b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800347b0  body 0x800347b0..0x800349cf  size 544 B
 * body sha256 3ef4944634156d63510410db561c3727cc73ab58e82f276499ce5ef2208fb331
 * provider record sha256 06b0d19d3b29c634740a831cd8f8dd816ccf3d6bb946172cc792257c02f702d7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800347b0(int param_1,int param_2)

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
  undefined1 auStack_38 [2];
  ushort local_36;
  undefined2 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if ((*(byte *)(param_1 + 0x25c) & 1) == 0) {
    iVar9 = *(int *)(param_1 + 0x250);
    iVar8 = *(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178;
    uVar1 = *(ushort *)(*(int *)(param_1 + 0x234) + 0x5a);
    iVar10 = param_2 + (uint)uVar1;
    iVar4 = *(int *)(iVar9 + 0x234) + (uint)*(byte *)(iVar9 + 0x25d) * 0x178;
    local_30 = *(undefined4 *)(iVar4 + 0x4c);
    local_2c = *(undefined4 *)(iVar4 + 0x50);
    local_28 = *(undefined4 *)(iVar4 + 0x54);
    local_24 = *(undefined4 *)(iVar4 + 0x58);
    FUN_80034bdc(iVar8 + 0x4c,&local_30,auStack_38,iVar10 * 0x10000 >> 0x10);
    sVar3 = (short)param_2;
    if ((*(byte *)(param_1 + 0x25c) & 2) != 0) {
      local_36 = uVar1 + sVar3 + *(short *)(iVar8 + 0x5a);
    }
    if (param_1 == iVar9) {
      local_34 = 0;
      local_36 = uVar1 + sVar3 + *(short *)(iVar8 + 0x5a);
    }
    uVar7 = (uint)*(ushort *)(iVar8 + 0x134);
    sVar6 = *(short *)(iVar8 + 0x138);
    if ((*(byte *)(param_1 + 0x25c) & 0x80) != 0) {
      uVar7 = (uint)*(byte *)(iVar8 + 0x13c);
    }
    uVar5 = ((int)(short)local_36 - (int)sVar3) - (int)(short)uVar1;
    if ((int)sVar6 << 1 < (int)(uVar5 + (int)sVar6 & 0xfff)) {
      sVar2 = -sVar6;
      if ((uVar5 & 0x800) == 0) {
        sVar2 = sVar6;
      }
      local_36 = (short)iVar10 + sVar2;
    }
    sVar6 = *(ushort *)(iVar8 + 0x130) - (short)uVar7;
    uVar5 = uVar7 + ((uint)local_36 -
                    ((uint)*(ushort *)(iVar8 + 0x130) +
                    (uint)uVar1 + param_2 + (uint)*(ushort *)(iVar8 + 0x5a)));
    *(short *)(iVar8 + 0x130) = sVar6;
    if ((uVar5 & 0x800) == 0) {
      *(short *)(iVar8 + 0x130) = sVar6 + (short)uVar7 * 2;
    }
    if ((int)(uVar5 & 0xfff) < (int)(uVar7 << 0x10) >> 0xf) {
      *(ushort *)(iVar8 + 0x130) = local_36 - (uVar1 + sVar3 + *(short *)(iVar8 + 0x5a));
    }
    *(short *)(iVar8 + 0x5a) = *(short *)(iVar8 + 0x5a) + *(short *)(iVar8 + 0x130);
    FUN_80040e58(iVar8 + 0x58,iVar8 + 8);
    *(short *)(iVar8 + 0x5a) = *(short *)(iVar8 + 0x5a) - *(short *)(iVar8 + 0x130);
  }
  return;
}
