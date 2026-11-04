/* FUN_8005c27c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c27c  body 0x8005c27c..0x8005c307  size 140 B
 * body sha256 0e45cd08badc3105ba22b546a7bb5398a5d90cb2786e566ea1c063f1dfa793a9
 * provider record sha256 35ba40708d9ac063951edbcc38d0bfd6b0b95d88e138b167a9052395b049425e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c27c(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 9 < 3) &&
     (iVar2 = *(int *)(param_1 + 0x234), *(short *)(iVar2 + 0x1e7e) != 0xff)) {
    sVar1 = *(short *)(&DAT_80110f44 + *(char *)(iVar2 + 0x1e72) * 2);
    *(short *)(iVar2 + 0x1dbc) = sVar1;
    if (sVar1 == -0x8000) {
      *(undefined2 *)(iVar2 + 0x1dbc) = 0;
      *(undefined2 *)(iVar2 + 0x1e7e) = 0xff;
    }
    else {
      *(char *)(iVar2 + 0x1e72) = *(char *)(iVar2 + 0x1e72) + '\x01';
      FUN_80040e58(iVar2 + 0x1db8,iVar2 + 0x1d68);
    }
  }
  return;
}
