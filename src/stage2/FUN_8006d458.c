/* FUN_8006d458
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d458  body 0x8006d458..0x8006d5a7  size 336 B
 * body sha256 1555ad6643f63d76cf4d241c64e04e795ddb5db937da5fc546cb29dd1af26d17
 * provider record sha256 02b3914fa75a6c2f78b6e9f7896badc07471585bb5e7803f79914147ba6ce538
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d458(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar2 = 0;
  puVar1 = &DAT_80113ad8;
  do {
    puVar1[-5] = (char)uVar2;
    puVar1[-7] = 0;
    puVar1[-6] = 0;
    puVar1[-4] = 0xff;
    *puVar1 = 0xff;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0x174;
  } while (uVar2 < 10);
  FUN_8006d5a8();
  puVar4 = &DAT_800e8db4;
  iVar3 = 0x40;
  DAT_800e8d00 = 0;
  DAT_80114f39 = 0;
  DAT_80114f3a = 0;
  DAT_80114f3b = 0;
  DAT_80012888 = 0x78;
  DAT_800e110c = DAT_800e110c & 0xfffff3ff;
  DAT_800e1128 = 0;
  DAT_800e112a = 0;
  DAT_800e8cba = 0xffff;
  DAT_800e8cbc = 0xffff;
  DAT_80114f36 = 0xff;
  DAT_80114f37 = 0xff;
  DAT_80114f38 = 0xff;
  DAT_80114f3c = 0;
  DAT_80114f3d = 0;
  DAT_80114f3e = 0xff;
  DAT_80114f30 = DAT_800e13f0;
  do {
    *puVar4 = 0xffffffff;
    iVar3 = iVar3 + -1;
    puVar4 = puVar4 + 1;
  } while (iVar3 != 0);
  if ((DAT_800e1130 & 0x400) != 0) {
    DAT_800e1130 = DAT_800e1130 & 0xfffffbff;
  }
  DAT_800e12da = DAT_800e12da & 0xfff;
  return;
}
