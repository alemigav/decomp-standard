/* FUN_8016baa0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016baa0  body 0x8016baa0..0x8016bac7  size 40 B
 * body sha256 e5bb306800025a3e48e0d54e693717855b111602b13a955a3211159ce83924a0
 * provider record sha256 07324b850d4ec368d639f05b5884b872089a8284b692780965a5220233233a08
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016baa0(uint param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 0x1c;
  (&DAT_8016c3ae)[iVar1] = param_2;
  (&DAT_8016c3af)[iVar1] = param_3;
  return;
}
