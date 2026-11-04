/* FUN_801649fc
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801649fc  body 0x801649fc..0x80164a3f  size 68 B
 * body sha256 80f7e2317c7c0b56f8d143e86feb77f2432753288cad88d231ae2d109b33bcb5
 * provider record sha256 c534029494865c01e2a9f321da71f1c35ecfef637a2939b18187188c58c8e6bc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801649fc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8016313c();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 5) = 0xd;
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  return;
}
