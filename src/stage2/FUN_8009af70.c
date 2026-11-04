/* FUN_8009af70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009af70  body 0x8009af70..0x8009b137  size 456 B
 * body sha256 345418d0f1d013263ced8c63c8e87a647762925a6b7dcb91e8c91be596fb7d99
 * provider record sha256 985f69eef931099366c2ab31382b436511b39a212250bc83e1db66665434efde
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009af70(void)

{
  bool bVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  short local_18 [4];
  
  iVar4 = *(int *)(DAT_800df92c + 0x2c) + DAT_800e8cac * 0x28;
  FUN_80082474(&DAT_80131788,iVar4,0x28);
  *(undefined1 *)(iVar4 + 3) = 0;
  *(undefined2 *)(iVar4 + 0x26) = 1;
  if ((DAT_80131781 & 0x10) == 0) {
    local_18[0] = 0x4b0;
    local_18[1] = 0;
    local_18[2] = 0;
    FUN_800837d0((int)DAT_800e1196,local_18,local_18);
    DAT_801317b4 = 0xfffff6a0;
    DAT_80131783 = 0xff;
    DAT_80131784 = 0xe6;
    DAT_80131785 = 0xa0;
    DAT_801317b0 = DAT_800e1158 + local_18[0];
    DAT_801317b8 = DAT_800e1160 + local_18[2];
  }
  if (DAT_80131782 == '\0') {
    if (*(byte *)(iVar4 + 10) < DAT_80131783) {
      *(byte *)(iVar4 + 10) = DAT_80131783;
    }
    if (*(byte *)(iVar4 + 0xb) < DAT_80131784) {
      *(byte *)(iVar4 + 0xb) = DAT_80131784;
    }
    bVar1 = *(byte *)(iVar4 + 0xc) < DAT_80131785;
    bVar3 = DAT_80131785;
  }
  else {
    if (DAT_80131782 != '\x01') goto LAB_8009b100;
    if (*(byte *)(iVar4 + 10) < DAT_80131783 >> 1) {
      *(byte *)(iVar4 + 10) = DAT_80131783 >> 1;
    }
    if (*(byte *)(iVar4 + 0xb) < DAT_80131784 >> 1) {
      *(byte *)(iVar4 + 0xb) = DAT_80131784 >> 1;
    }
    bVar1 = *(byte *)(iVar4 + 0xc) < DAT_80131785 >> 1;
    bVar3 = DAT_80131785 >> 1;
  }
  if (bVar1) {
    *(byte *)(iVar4 + 0xc) = bVar3;
  }
  DAT_80131782 = DAT_80131782 + '\x01';
LAB_8009b100:
  *(undefined2 *)(iVar4 + 0x1c) = DAT_801317b0._2_2_;
  *(undefined2 *)(iVar4 + 0x1e) = DAT_801317b4._2_2_;
  uVar2 = DAT_801317b8._2_2_;
  *(undefined2 *)(iVar4 + 0x26) = 6000;
  *(undefined2 *)(iVar4 + 0x20) = uVar2;
  return;
}
