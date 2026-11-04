/* FUN_800334c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800334c8  body 0x800334c8..0x80033603  size 316 B
 * body sha256 2ee541b91793cc13f0c972066622c18aa0da2295aff2f36e99f1d720ea46a8ba
 * provider record sha256 a63c6d67fa95a7a9ec6aaf755963b6409ff5923deb156d93f4809ec598609e09
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800334c8(int param_1,ushort *param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = *(uint *)(param_3 + (uint)*(byte *)(param_1 + 0x1e8) * 4);
  if (param_4 == 0) {
    uVar9 = (uint)*(byte *)(param_1 + 0x1e9);
  }
  else {
    uVar9 = ((uVar8 & 0xffff) - (uint)*(byte *)(param_1 + 0x1e9)) - 1;
  }
  uVar10 = *(uint *)(param_2 + 2);
  iVar7 = (uVar10 >> 0x12) * (*(uint *)(param_3 + (uVar8 >> 0x10) + uVar9 * 4) & 0xfff) * 4 +
          (uint)*param_2;
  sVar1 = *(short *)((int)param_2 + iVar7 + 4);
  sVar2 = *(short *)((int)param_2 + iVar7 + 8);
  sVar3 = *(short *)((int)param_2 + iVar7 + 10);
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    *(undefined4 *)(param_1 + 0x2a8) = 0;
    *(undefined2 *)(param_1 + 0x2ac) = 0;
    if (param_4 != 0) {
      *(short *)(param_1 + 0x2a8) = sVar1;
      *(short *)(param_1 + 0x2aa) = sVar3;
      *(short *)(param_1 + 0x2ac) = sVar2;
      iVar7 = (uVar10 >> 0x12) *
              (*(uint *)(param_3 + (uint)*(ushort *)(param_3 + (uint)*(byte *)(param_1 + 0x1e8) * 4)
                        ) & 0xfff) * 4 + (uint)*param_2;
      *(short *)(param_1 + 0x2a8) = sVar1 + *(short *)((int)param_2 + iVar7 + 4);
      *(short *)(param_1 + 0x2aa) = sVar3 + *(short *)((int)param_2 + iVar7 + 10);
      *(short *)(param_1 + 0x2ac) = sVar2 + *(short *)((int)param_2 + iVar7 + 8);
    }
  }
  sVar4 = *(short *)(param_1 + 0x2a8);
  sVar5 = *(short *)(param_1 + 0x2aa);
  sVar6 = *(short *)(param_1 + 0x2ac);
  *(short *)(param_1 + 0x2a8) = sVar1;
  *(short *)(param_1 + 0x2aa) = sVar3;
  *(short *)(param_1 + 0x2ac) = sVar2;
  *(short *)(param_1 + 0x1e0) = sVar1 - sVar4;
  *(short *)(param_1 + 0x1e2) = sVar3 - sVar5;
  *(short *)(param_1 + 0x1e4) = sVar2 - sVar6;
  return;
}
