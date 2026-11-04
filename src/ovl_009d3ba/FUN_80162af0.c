/* FUN_80162af0
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162af0  body 0x80162af0..0x80162b93  size 164 B
 * body sha256 fab87037266a043cbd8cdae538c0a1d8e3f2251edda85a75b3b94408cba78e44
 * provider record sha256 8f1958967ce28a25ebf573f1b74fff1f01fba0dd40fddca6850a895e53da15a4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162af0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((DAT_800e139f & 0x80) == 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
      *(undefined1 *)(param_1 + 6) = 1;
    }
  }
  else if (bVar1 == 2) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
