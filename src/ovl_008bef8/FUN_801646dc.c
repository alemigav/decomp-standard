/* FUN_801646dc
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801646dc  body 0x801646dc..0x801648e7  size 524 B
 * body sha256 15d3a4d37631a28cebf39f42006f01d8edbdfe81fdac82d1e674415f05e86bfd
 * provider record sha256 a66ff24b1d52dee73be0aac9af494e38547cca7899c7651c33f64128de000378
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801646dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x8003331c(param_1,param_2,param_3,0);
        if (*(char *)(param_1 + 0x1e9) == '\x03') {
          func_0x80077adc(0x4020001,param_1 + 0x28);
        }
        cVar2 = func_0x80089d54(param_1,param_2,param_3,0x1000);
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
        return;
      }
      if (bVar1 == 3) {
        DAT_800e139f = 0x80;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80052d10(10,0x28,0x96,0xb);
    func_0x80052bd0(3,0x16);
    func_0x80052bd0(3,0x1a);
    func_0x80052d10(0x41,0xf0,0x78,0x15);
    func_0x80052d10(10,0xf5,0x46,0x56);
    func_0x80052d10(5,0x46,0x8c,0x6a);
    func_0x80052bd0(3,0x6e);
    func_0x80052d10(0x14,0xff,0x78,0x6c);
    func_0x80052d10(0x14,0xbe,100,0x80);
    func_0x80052d10(0x91,0xa0,0x1e,0x94);
    *(undefined2 *)(param_1 + 500) = 0;
    _DAT_800e1110 = _DAT_800e1110 | 0x1000000;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  *(undefined1 *)(param_1 + 0x1e9) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
  func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x400);
  if (*(short *)(param_1 + 500) != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000000;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  return;
}
