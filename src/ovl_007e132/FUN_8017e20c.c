/* FUN_8017e20c
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017e20c  body 0x8017e20c..0x8017e363  size 344 B
 * body sha256 46269109ced56eaca918a136e1335817ee0626829ef8e026dc87c0a492cc72f4
 * provider record sha256 97b50214a5756484ef38a3b2cb8bf143b26a2e4ff1fb0a2bc14df59df34ac624
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017e20c(void)

{
  undefined4 uVar1;
  
  switch(DAT_800e1138) {
  default:
    func_0x800752dc(0x19c,8,1);
    _DAT_8011a298 = 0x80115dd8;
    uVar1 = 0x657;
    break;
  case 1:
  case 3:
  case 5:
  case 7:
  case 9:
    func_0x800752dc(0x19d,8,1);
    _DAT_8011a298 = 0x80115ddc;
    uVar1 = 0x658;
    break;
  case 0xc:
    func_0x800752dc(0x1a0,8,1);
    _DAT_8011a298 = 0x80115de0;
    uVar1 = 0x659;
    break;
  case 0xd:
    func_0x800752dc(0x1a1,8,1);
    _DAT_8011a298 = 0x80115de4;
    uVar1 = 0x65a;
    break;
  case 0xe:
    func_0x800752dc(0x19e,8,1);
    _DAT_8011a298 = 0x80115de8;
    uVar1 = 0x65b;
    break;
  case 0xf:
    func_0x800752dc(0x19f,8,1);
    _DAT_8011a298 = 0x80115dec;
    uVar1 = 0x65c;
  }
  func_0x80004cfc(uVar1,_DAT_800c52dc + 0x3100,1,"DIE EDH");
  return;
}
