/* FUN_80039c34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039c34  body 0x80039c34..0x80039d0b  size 216 B
 * body sha256 4e51e45ca082cb0b5e3636fcfa41468d38affaf5d0112d7b726a71f3098e1b30
 * provider record sha256 1cd1f88070d116683bc379640309f0169bbac97a6a549f203c4a9a6f1721a8c5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039c34(void)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = DAT_800ebb94;
  puVar1 = (ushort *)(DAT_800ebb94 + 0x2a);
  puVar2 = (ushort *)(DAT_800ebb94 + 0x14);
  *(undefined2 *)(DAT_800ebb94 + 0x18) = *(undefined2 *)(DAT_800ebb94 + 0x12);
  *(ushort *)(iVar3 + 0x2a) = *puVar1 | *puVar2;
  uVar4 = FUN_80033604();
  uVar5 = *(ushort *)(DAT_800ebb94 + 0x16) + 1;
  if (uVar5 == 0) {
    trap(0x1c00);
  }
  if ((uVar5 == 0xffffffff) && ((uVar4 & 0xff) == 0x80000000)) {
    trap(0x1800);
  }
  *(char *)(DAT_800ebb94 + 0x21) = *(char *)(DAT_800ebb94 + 2) + (char)((uVar4 & 0xff) % uVar5);
  *(undefined1 *)(DAT_800ebb94 + 0x20) =
       *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)*(byte *)(DAT_800ebb94 + 0x21) * 8 + 2)
  ;
  *(char *)(DAT_800ebb94 + 0x1f) = *(char *)(DAT_800ebb94 + 0x1f) + *(char *)(DAT_800ebb94 + 0xb);
  FUN_80039aa0(DAT_800ebb94,
               *(int *)(DAT_800ebb94 + 0x78) + (uint)*(byte *)(DAT_800ebb94 + 0x1f) * 0x18);
  return;
}
