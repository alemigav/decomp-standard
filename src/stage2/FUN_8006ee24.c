/* FUN_8006ee24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ee24  body 0x8006ee24..0x8006ee8f  size 108 B
 * body sha256 eec84e633753f16a381f98c3eb41de88ba48c4dc425e4effbfd7b7f1bebca760
 * provider record sha256 5e9b6d56c7a5ef29e1c27bbc3a6af2ab40ada085078ad187385d78ceb0d1d80b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006ee24(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar4 + 2);
  bVar2 = *(byte *)(iVar4 + 3);
  uVar3 = *(ushort *)(iVar4 + 4);
  *(int *)(param_1 + 0x1c) = iVar4 + 6;
  uVar5 = (uint)uVar3 << 0x10;
  FUN_8004ac04(0,bVar2 | 0x300,uVar1,uVar5);
  DAT_800e1110 = DAT_800e1110 | uVar5;
  return 1;
}
