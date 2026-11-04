/* FUN_80163dd8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163dd8  body 0x80163dd8..0x801640ab  size 724 B
 * body sha256 9367cdc8bf58bc5773cbd065cedd26fa79aabbc8171b6f4e2ee93fb7d236f55e
 * provider record sha256 c54b48ed2a8e533a056f56963da0c56a4b76d2e47005b9c424280ba426d6d494
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163dd8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      *(undefined1 *)(param_1 + 0x2b8) = 1;
      *(undefined2 *)(param_1 + 0x2ba) = 0x100;
      uVar3 = func_0x80033604();
      if ((uVar3 & 0xf) == 0) {
        uVar3 = func_0x80033604(param_1);
        FUN_80166b98(param_1,(uVar3 & 0xff) % 3 + 0xb,4);
      }
      func_0x80089d54(param_1,param_2,param_3,0x40);
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xa003f00;
    func_0x80052c6c(0x14,0x78,0);
    func_0x80052d10(0x1e,0x78,0x28,0x14);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
  }
  uVar3 = **(uint **)(param_1 + 0x214);
  if ((uVar3 & 0x10000) != 0) {
    func_0x80052bd0(0x1e,0);
    func_0x80052c6c(3,200,5);
    func_0x80052c6c(3,200,0xf);
    func_0x80052c6c(8,200,0x19);
    func_0x80052d10(0x3c,200,0,0x21);
    *(uint *)(_DAT_800e1364 + 0xbc0) = *(uint *)(_DAT_800e1364 + 0xbc0) & 0xfffffffe;
    uVar4 = 0xf;
    if ((DAT_800e1138 & 1) != 0) {
      iVar2 = 0x1608;
      do {
        uVar4 = uVar4 + 1;
        *(uint *)(_DAT_800e1364 + iVar2) = *(uint *)(_DAT_800e1364 + iVar2) & 0xfffffffe;
        iVar2 = iVar2 + 0x178;
      } while (uVar4 < 0x13);
    }
    func_0x80077d18(7,param_1);
    FUN_80166b98(&DAT_800e1130,8,8);
  }
  if ((uVar3 & 0x20000) != 0) {
    uVar4 = func_0x80033604();
    FUN_80166b98(param_1,(uVar4 & 0xff) % 3 + 0xb,4);
    uVar4 = func_0x80033604();
    if ((uVar4 & 3) == 0) {
      uVar4 = func_0x80033604();
      FUN_80166b98(param_1,(uVar4 & 0xff) % 3 + 0xb,5);
    }
  }
  if ((uVar3 & 0x40000) != 0) {
    FUN_80166b98(&DAT_800e1130,8,8);
  }
  return;
}
