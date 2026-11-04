/* FUN_80162938
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162938  body 0x80162938..0x801629cf  size 152 B
 * body sha256 ba34e9dc5c8bad5a4bbade2f9ca64b7ce3aa6b1dd2a2c9a434e786a2b77a25de
 * provider record sha256 f23e3e83da63435e680a28aa29e3d93af23927740be7c75fa8b78ae13f9a3516
 * callees 4 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162938(uint *param_1)

{
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    if (*(char *)((int)param_1 + 0x2be) == '\0') {
      func_0x800341dc(param_1[0x82],0xbf10bf00);
    }
    else {
      *param_1 = *param_1 | 0x400;
    }
    func_0x80077d18(7,param_1);
    FUN_80162b9c(param_1,0,(&DAT_80162d54)[*(byte *)((int)param_1 + 5)]);
  }
  else {
    func_0x8003247c(param_1);
  }
  return;
}
