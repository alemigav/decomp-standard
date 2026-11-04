/* FUN_8006f040
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f040  body 0x8006f040..0x8006f1af  size 368 B
 * body sha256 7c006f70e3dfab485a27dae305c8748816bff3d2404ed6defdbb29b59dbf0caa
 * provider record sha256 8111ab05f5f992381eef5d188be399c506afd23c87fa9bc9f1fb91300289e473
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006f040(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x1c);
  uVar2 = *(undefined2 *)(iVar6 + 0x12);
  uVar5 = (uint)*(byte *)(iVar6 + 0x14);
  *(int *)(param_1 + 0x1c) = iVar6 + 0x16;
  bVar1 = *(byte *)(iVar6 + 1);
  if ((&DAT_800dfb60)[bVar1] == 0) {
    DAT_800e8604 = DAT_800e8604 + '\x01';
  }
  (&DAT_800dfb60)[bVar1] = iVar6 + 2;
  if (DAT_800e8ca8 < 4) {
    puVar4 = &DAT_800e8d48;
  }
  else {
    puVar4 = &DAT_800e8d68;
  }
  iVar3 = FUN_800837ac(puVar4,uVar2);
  if (iVar3 == 0) {
    bVar1 = *(byte *)(iVar6 + 0x15);
    if (uVar5 < 0x20) {
      (&DAT_800e1ad9)[uVar5 * 0x368] = bVar1;
      if ((bVar1 & 2) != 0) {
        (&DAT_800e18f8)[uVar5 * 0xda] = 0x80000000;
      }
    }
  }
  else {
    *(undefined1 *)(&DAT_800dfb60)[bVar1] = 0;
    if (uVar5 < 0x20) {
      (&DAT_800e18f8)[uVar5 * 0xda] = 0x80000000;
      (&DAT_800e1ad9)[uVar5 * 0x368] = 0;
    }
  }
  return 1;
}
