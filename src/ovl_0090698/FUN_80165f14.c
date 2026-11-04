/* FUN_80165f14
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165f14  body 0x80165f14..0x80166037  size 292 B
 * body sha256 0a0357bcf2de28b588b23d1c6d743c789d697dfa1aa5c164f50dfdda1db26a8f
 * provider record sha256 e74871cb28ae1bfba0d5b58f0dc7daffdaafa1f2efbd4e17cad4af5ff7f35a2a
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165f14(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined1 *)((int)param_1 + 0x2d6) = 1;
    param_1[0x7a] = 0xc000700;
    *param_1 = *param_1 | 2;
    FUN_8016703c(param_1,0x13);
    FUN_80166248(param_1);
    uVar2 = func_0x80033604();
    FUN_80167688(param_1,0x2002,(uVar2 & 3) + 6);
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  if ((*(uint *)param_1[0x85] & 0x40000) != 0) {
    if (*(short *)(param_1 + 0x6a) != 0) {
      bVar1 = *(byte *)(param_1 + 0xb6);
      if ((8 < bVar1) && ((bVar1 < 0xb || (bVar1 == 0x10)))) {
        FUN_8016703c(param_1,0,7);
      }
      *(undefined1 *)((int)param_1 + 0x2d6) = 0xff;
      if (*(char *)((int)param_1 + 0x2da) == '\0') {
        *(undefined1 *)((int)param_1 + 0x2da) = 3;
        *(undefined1 *)((int)param_1 + 0x2db) = 1;
      }
    }
    param_1[1] = 0x7000000;
  }
  return;
}
