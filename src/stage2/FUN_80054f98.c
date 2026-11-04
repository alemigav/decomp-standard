/* FUN_80054f98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054f98  body 0x80054f98..0x800550eb  size 340 B
 * body sha256 8a37836e0bf2669808d001b5fa09b9ffc9b2046400706e9373dae3465623ae10
 * provider record sha256 eeecbdff45ddcb130bba9e533425cf4da034f543bea4c2dff02986a013124853
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054f98(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = DAT_8010d940;
  uVar4 = 0;
  iVar3 = 0x300;
  DAT_800e9182 = 0;
  FUN_800479c8(DAT_800c52dc + 0x3b800,&DAT_8010d944,0x14d4,1);
  DAT_800e9182 = 0;
  FUN_80053d38();
  puVar2 = &DAT_8010c280;
  do {
    FUN_80054084(iVar1 + iVar3,puVar2);
    puVar2 = puVar2 + 8;
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 0x10;
  } while (uVar4 < 0x16c);
  *(undefined1 *)(iVar1 + 0x2da) = 0x40;
  *(undefined1 *)(iVar1 + 0x2db) = 4;
  *(undefined1 *)(iVar1 + 3) = 0;
  *(undefined1 *)(iVar1 + 2) = 0;
  *(undefined1 *)(iVar1 + 0x2d5) = 0;
  *(undefined1 *)(iVar1 + 0x2d8) = 0;
  *(undefined1 *)(iVar1 + 0x2dc) = 0;
  *(undefined1 *)(iVar1 + 0x2dd) = (undefined1)DAT_800e8cac;
  FUN_80027148(param_1);
  FUN_8004cd88(1);
  if (param_2 != 0) {
    FUN_80077adc(0x2060000,0);
    DAT_800e860b = 0;
    while (iVar1 = FUN_80053844(0xc,10,0xfc,0x8b), iVar1 != 0) {
      FUN_80053eb8(0x16c);
      FUN_8004cd88(1);
    }
  }
  return;
}
