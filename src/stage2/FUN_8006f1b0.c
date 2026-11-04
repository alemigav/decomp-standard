/* FUN_8006f1b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f1b0  body 0x8006f1b0..0x8006f32b  size 380 B
 * body sha256 ee66576d0c42f12539be5d583d2c9f0744aa01baf74ad420a6e1e320ef3190fc
 * provider record sha256 c9ebc10119fa98891c7d2fcd187f863fb107409610ebfab665a10e959b925ef2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006f1b0(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *(int *)(param_1 + 0x1c);
  uVar2 = *(undefined2 *)(iVar5 + 0x1a);
  uVar6 = (uint)*(byte *)(iVar5 + 0x1c);
  *(byte *)(iVar5 + 3) = *(byte *)(iVar5 + 3) | 0x80;
  *(int *)(param_1 + 0x1c) = iVar5 + 0x1e;
  bVar1 = *(byte *)(iVar5 + 1);
  if ((&DAT_800dfb60)[bVar1] == 0) {
    DAT_800e8604 = DAT_800e8604 + '\x01';
  }
  (&DAT_800dfb60)[bVar1] = iVar5 + 2;
  if (DAT_800e8ca8 < 4) {
    puVar4 = &DAT_800e8d48;
  }
  else {
    puVar4 = &DAT_800e8d68;
  }
  iVar3 = FUN_800837ac(puVar4,uVar2);
  if (iVar3 == 0) {
    bVar1 = *(byte *)(iVar5 + 0x1d);
    if (uVar6 < 0x20) {
      (&DAT_800e1ad9)[uVar6 * 0x368] = bVar1;
      if ((bVar1 & 2) != 0) {
        (&DAT_800e18f8)[uVar6 * 0xda] = 0x80000000;
      }
    }
  }
  else {
    *(undefined1 *)(&DAT_800dfb60)[bVar1] = 0;
    if (uVar6 < 0x20) {
      (&DAT_800e18f8)[uVar6 * 0xda] = 0x80000000;
      (&DAT_800e1ad9)[uVar6 * 0x368] = 0;
    }
  }
  return 1;
}
