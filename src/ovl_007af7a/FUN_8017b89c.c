/* FUN_8017b89c
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017b89c  body 0x8017b89c..0x8017ba83  size 488 B
 * body sha256 75fa1be9c1e2d1d712e3311d62f6f3fe81ef3ff38e82bd4bfed803860d2b91f6
 * provider record sha256 144d718d258ec3764f9fd9cdda75a219ddbd973e5f13590e901d656e07ae0ed8
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017b89c(void)

{
  undefined1 uVar1;
  
  DAT_8017e5be = 0;
  _DAT_8010bfa8 = _DAT_8010bfa8 << 1 | 1;
  func_0x8004ce90(0);
  DAT_8017e5b8 = _DAT_800e924c;
  DAT_8017e5b4 = func_0x80025b0c();
  func_0x80026980(0);
  func_0x800274e4(4,1);
  uVar1 = DAT_800dfbe8;
  DAT_800dfbe8 = 0;
  func_0x800275c0(0,0x7fff,1,0);
  DAT_800dfbe8 = 1;
  func_0x800275c0(0,0x7fff,1,0);
  DAT_8017e5cb = DAT_800e923f;
  DAT_800e923f = 0;
  DAT_800dfbe8 = uVar1;
  func_0x80052bbc(0xf00c,0xc04);
  DAT_800e9182 = 0;
  DAT_8017e5ce = DAT_800e8cad;
  if (_DAT_800df92c != 0) {
    DAT_8017e5d4 = *(undefined4 *)(_DAT_800df92c + 0x2c);
  }
  DAT_8017e5c9 = 0;
  DAT_8017e5ca = 0;
  DAT_8017e5d0 = 0x2c808080;
  DAT_8017e5bf = 0;
  DAT_8017e5bc = 0;
  DAT_8017e5bd = 0;
  DAT_8017e5cd = 0;
  DAT_8017e5cc = 0;
  DAT_8017e5c4 = 0;
  DAT_8017e5c5 = 0;
  DAT_8017e5c6 = 0;
  DAT_8017e5c7 = 0;
  DAT_8017e5c8 = 0;
  DAT_8017e5c2 = 0;
  DAT_8017e5c0 = 0;
  DAT_8017e5c1 = 0;
  DAT_8017e5b0 = func_0x800479c8(_DAT_800c52dc + 0x3b800,&DAT_8017e55c,0x14c8,1);
  func_0x800274f8(0x200,0xffffe800,7,1);
  return;
}
