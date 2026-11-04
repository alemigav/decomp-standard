/* FUN_80166ac8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166ac8  body 0x80166ac8..0x80166b1b  size 84 B
 * body sha256 0f03bc6807e4ce5cc84b7b54cd6b62d669e6d0112fcb16aa91234aa2ca350222
 * provider record sha256 157c26bd95a41dbdf999fff2320e4e21bd87736ca1e727be8847b28a9ced37c4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166ac8(int param_1,char param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = -0x7ff1eed0;
  }
  else {
    iVar1 = _DAT_800e13ec;
  }
  *(undefined1 *)(iVar1 + 4) = 2;
  *(char *)(iVar1 + 5) = param_2 + '\x02';
  *(undefined1 *)(iVar1 + 6) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  *(byte *)(iVar1 + 0x26f) = *(byte *)(iVar1 + 0x26f) | 0x80;
  return;
}
