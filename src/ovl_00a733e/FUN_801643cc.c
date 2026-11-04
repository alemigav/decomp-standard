/* FUN_801643cc
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801643cc  body 0x801643cc..0x801644e3  size 280 B
 * body sha256 ff6d1738b531b7249d1b2563ee6ba978f1d09ef8eb778ff748da25a0ea8a33cf
 * provider record sha256 ee459383cd930b854c0187a88cab1f166a39d5d2121c9729f6ec2ac2ff42701d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801643cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 7) = 2;
      *(undefined4 *)(param_1 + 0x1e8) = 0xff00;
    }
    func_0x80032b5c(param_1,0);
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined1 *)(param_1 + 7) = 1;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80077d18(10,param_1);
    }
  }
  else if (bVar1 == 2) {
    func_0x80089d54(param_1,param_2,param_3,0xf);
  }
  return;
}
