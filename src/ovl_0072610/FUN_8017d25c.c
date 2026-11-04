/* FUN_8017d25c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d25c  body 0x8017d25c..0x8017d403  size 424 B
 * body sha256 ffcbcc5a78e31ec3f0e1f68af2da1c534269fc4548f99a8dd4736e479d6b0e12
 * provider record sha256 f793488ca77a5ad721dadbfdea4d349bdefa2c8ebd5d7d3de7e001283990cbc9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d25c(void)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  
  DAT_80185744 = FUN_8017bec8(0xc);
  DAT_80185748 = FUN_8017bec8(0xc);
  FUN_8017bec8(4);
  FUN_8017bec8(4);
  FUN_8017bec8(0x12);
  FUN_8017bbe8(1);
  FUN_8017bec8(10);
  FUN_8017bec8(1);
  iVar1 = FUN_8017bec8(1);
  iVar4 = 0;
  if (iVar1 == 0) {
    iVar1 = DAT_80186c94;
    do {
      pbVar3 = &DAT_80185520 + iVar4;
      iVar4 = iVar4 + 1;
      *(uint *)(iVar1 + 0x1c) = (uint)*pbVar3;
      iVar1 = iVar1 + 4;
    } while (iVar4 < 0x40);
  }
  else {
    do {
      uVar2 = FUN_8017bec8(8);
      pbVar3 = &DAT_801854a0 + iVar4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(DAT_80186c94 + (uint)*pbVar3 * 4 + 0x1c) = uVar2;
    } while (iVar4 < 0x40);
  }
  iVar1 = FUN_8017bec8(1);
  iVar4 = 0;
  if (iVar1 == 0) {
    iVar4 = 0x3f;
    iVar1 = DAT_80186c94 + 0xfc;
    do {
      *(undefined4 *)(iVar1 + 0x11c) = 0x10;
      iVar4 = iVar4 + -1;
      iVar1 = iVar1 + -4;
    } while (-1 < iVar4);
  }
  else {
    do {
      uVar2 = FUN_8017bec8(8);
      pbVar3 = &DAT_801854a0 + iVar4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(DAT_80186c94 + (uint)*pbVar3 * 4 + 0x11c) = uVar2;
    } while (iVar4 < 0x40);
  }
  iVar4 = 0;
  iVar1 = DAT_80186c94;
  do {
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar1 + 0x21c) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x31c) = *(undefined4 *)(iVar1 + 0x11c);
    iVar1 = iVar1 + 4;
  } while (iVar4 < 0x40);
  FUN_8017d61c();
  return;
}
