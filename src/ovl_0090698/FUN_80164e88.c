/* FUN_80164e88
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164e88  body 0x80164e88..0x80164f8b  size 260 B
 * body sha256 6408a9346fdcfddddb91634f7c4705eb10911b632e30a8b51b2aff8831596c04
 * provider record sha256 9a6b50a3192cfb5c4a5d09943683734f8181f3a8be6e742522ab1ef9bb49265e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e88(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x2d2) == '\0') {
    if ((*(ushort *)(param_1 + 0x1aa) & 1) == 0) {
      (*(code *)(&PTR_FUN_80167f0c)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    }
    else {
      FUN_8016753c(param_1);
      uVar1 = func_0x80033604();
      FUN_80167688(param_1,0x2004,(uVar1 & 1) + 1);
      *(undefined1 *)(param_1 + 0x2cd) = 1;
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
  }
  else {
    FUN_8016753c();
    *(uint *)(param_1 + 4) =
         (uint)*(byte *)(param_1 + 0x2cf) * 0x10000 + (uint)*(byte *)(param_1 + 0x2d0) * 0x100 +
         (uint)*(byte *)(param_1 + 0x2d1) + 0x1000000;
    FUN_80162148(param_1,param_2,param_3);
  }
  return;
}
