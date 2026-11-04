/* FUN_8007a3e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a3e0  body 0x8007a3e0..0x8007a50f  size 304 B
 * body sha256 2fab030f861ebf14161f4c3ae9e9597c88cc602d50e960a390d5f68cb8716c31
 * provider record sha256 55f50d71813a48826b002758c75e69130a1acf54306cf650118517cfed124915
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a3e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_80124838 = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0x208) + 0xe) = 0;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x800) != 0) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar1 + 0x10d0) = *(undefined4 *)(iVar1 + 0x16b0);
    *(undefined4 *)(iVar1 + 0x10d4) = *(undefined4 *)(iVar1 + 0x16b4);
    *(undefined4 *)(iVar1 + 0x10d8) = *(undefined4 *)(iVar1 + 0x16b8);
    *(undefined4 *)(iVar1 + 0x10dc) = *(undefined4 *)(iVar1 + 0x16bc);
    *(undefined2 *)(iVar1 + 0x10ec) = *(undefined2 *)(iVar1 + 0x16cc);
    *(undefined2 *)(iVar1 + 0x10ee) = *(undefined2 *)(iVar1 + 0x16ce);
    *(undefined4 *)(iVar1 + 0x10f4) = *(undefined4 *)(iVar1 + 0x16d4);
    *(undefined4 *)(iVar1 + 0x10f0) = *(undefined4 *)(iVar1 + 0x16d0);
    *(undefined4 *)(iVar1 + 0x1608) = 0;
    *(undefined4 *)(iVar1 + 0x1028) = 1;
  }
  iVar1 = 7;
  if ((*(uint *)(param_1 + 0x1a8) & 0x300) == 0) {
    do {
      iVar1 = iVar1 + -1;
      iVar2 = *(int *)(param_1 + 0x234) + (uint)(byte)(&UNK_8011a860)[iVar1 * 2] * 0x178;
      FUN_8004a5b4(iVar2 + 4,1);
      *(undefined2 *)(iVar2 + 0x11c) = 0;
      *(undefined4 *)(iVar2 + 0x60) = 0;
      *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) | 2;
    } while (iVar1 != 0);
  }
  else {
    DAT_80124838 = 0;
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfcff;
  }
  return;
}
