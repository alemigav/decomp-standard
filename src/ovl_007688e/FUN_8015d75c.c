/* FUN_8015d75c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015d75c  body 0x8015d75c..0x8015d8bf  size 356 B
 * body sha256 c4710ac0fe85df615561fc9cfa8d951848460aa29bdb7028dd70c6c427236078
 * provider record sha256 748438e6e886419689dc68016bccd23da1325496a02d704f8bcce067567bcee4
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015d75c(void)

{
  undefined4 uVar1;
  
  DAT_800e9182 = 0;
  if ((_DAT_800e10ec & 1) == 0) {
    func_0x8007608c(0x12,0);
    uVar1 = 0x14ce;
  }
  else {
    func_0x8007608c(0x13,0);
    uVar1 = 0x14cd;
  }
  func_0x800479c8(DAT_80161510,&DAT_80161480,uVar1,1);
  DAT_800e923f = 1;
  func_0x800274f8(0x203,0,7,0);
  func_0x800275c0(3,0x7c00,0,0);
  func_0x80026980(0);
  uVar1 = 0x14bb;
  if ((_DAT_800e10ec & 1) != 0) {
    uVar1 = 0x14bc;
  }
  func_0x80026910(uVar1);
  FUN_8015e1d0();
  DAT_80160c24 = 2;
  DAT_80160c22 = 0;
  DAT_80160c2e = 0;
  DAT_80160c2c = 0;
  DAT_80160c23 = 0;
  DAT_80160c1d = 0;
  DAT_80160c1e = 0;
  DAT_80160c1f = 0;
  DAT_80160c26 = 0;
  DAT_80160c27 = 0;
  DAT_80160c32 = 0xf0;
  DAT_80160c30 = 0;
  DAT_80160c34 = 0xffffffff;
  DAT_80160c1c = DAT_80160c1c + '\x01';
  func_0x800274e4(0,0);
  func_0x80027650(0);
  return;
}
