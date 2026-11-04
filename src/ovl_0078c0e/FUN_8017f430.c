/* FUN_8017f430
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f430  body 0x8017f430..0x8017f61b  size 492 B
 * body sha256 4e33f7031369721980ff6a2b1f8f89f7262e849986fdc6ea51a9637b723a0e23
 * provider record sha256 c5cac5de6c0670e668f40aebf4250711f4b9aa7d59771aec2a146cb7854a4d1a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017f430(int param_1,undefined4 param_2,char param_3)

{
  undefined *puVar1;
  byte bVar2;
  
  bVar2 = param_3 + 1;
  if (DAT_800e8b3a - 0xc < 2) {
    if (DAT_800e8b3a == 0xc) {
      puVar1 = &DAT_80180354;
    }
    else {
      puVar1 = &DAT_8018037c;
    }
  }
  else if ((_DAT_800e8b44 & 0x40000000) == 0) {
    if ((DAT_800e8b3a & 1) == 0) {
      puVar1 = &DAT_8018032c;
    }
    else {
      puVar1 = &DAT_80180304;
    }
  }
  else if ((DAT_800e8b3a & 1) == 0) {
    puVar1 = &DAT_801802dc;
  }
  else {
    puVar1 = &DAT_801802b4;
  }
  func_0x80082474(param_1,puVar1,0x2e);
  if (bVar2 < 10) {
    func_0x80082474(param_1 + 0x12,&DAT_801803a4,2);
  }
  else {
    *(byte *)(param_1 + 0x13) = *(char *)(param_1 + 0x13) + bVar2 / 10;
  }
  if ((_DAT_800e8b44 & 0x4000000) != 0) {
    func_0x80082474(param_1 + 0x10,&DAT_801803a8,2);
  }
  *(byte *)(param_1 + 0x15) = *(char *)(param_1 + 0x15) + bVar2 % 10;
  *(char *)(param_1 + 0x29) = *(char *)(param_1 + 0x29) + (char)(_DAT_800e8b50 / 10);
  *(char *)(param_1 + 0x2b) =
       *(char *)(param_1 + 0x2b) + (char)_DAT_800e8b50 + (char)(_DAT_800e8b50 / 10) * -10;
  func_0x80082474(param_1 + 0x2e,&UNK_80180774 + (uint)DAT_800e8b3b * 0x1d,0x1b);
  return;
}
