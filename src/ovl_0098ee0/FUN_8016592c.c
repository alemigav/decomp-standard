/* FUN_8016592c
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x8016592c  body 0x8016592c..0x80165997  size 108 B
 * body sha256 2ced38a2c9b63291a5e14e288d90c0007e764fdbc34cf4a3beed826843b1f0c6
 * provider record sha256 2a272d77ec7d7816925a4aa1916755c345345e86047585d463db70169a7dfe90
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016592c(int param_1)

{
  undefined1 uVar2;
  int iVar1;
  
  uVar2 = 3;
  if (19999 < *(short *)(param_1 + 0x1f2)) {
    iVar1 = FUN_80162144(4,&DAT_8016690c,&DAT_80166910);
    uVar2 = 4;
    if ((iVar1 != 0) && (uVar2 = 1, (*(ushort *)(param_1 + 0x26c) & 0x20) == 0)) {
      *(undefined1 *)(param_1 + 0x26e) = 0;
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x26e) = uVar2;
  return;
}
