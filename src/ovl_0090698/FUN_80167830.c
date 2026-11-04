/* FUN_80167830
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167830  body 0x80167830..0x80167883  size 84 B
 * body sha256 7c6f8032028fe83354157ad01fa1faea476a7058139dc247f042cac4bf1aba8d
 * provider record sha256 5bb7cdd8bd4f3dfd952847f561a652eaf9caf13be9a1b5b892cae0a9789240ee
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167830(int param_1,char param_2)

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
