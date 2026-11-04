/* FUN_800759d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800759d8  body 0x800759d8..0x80075c77  size 672 B
 * body sha256 960e5766d2d2476676d9894e1553498a584b69cb1c614eef0df9b554ec014824
 * provider record sha256 2c72bf12947adb03c96cfaf2e3ecfedd5cf05fa6c4ae37da0a35849ea7f5fd70
 * callees 10 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800759d8(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  
  iVar5 = 0xe;
  puVar4 = &UNK_8011a6c4;
  DAT_8011a370 = 0;
  DAT_8011a374 = 0;
  _DAT_8013a168 = 0;
  do {
    puVar4[0x28] = 0;
    iVar5 = iVar5 + -1;
    puVar4 = puVar4 + -0x3c;
  } while (-1 < iVar5);
  iVar5 = FUN_800ab580(0x5622,0x20,0x18,0xe,1000,0x180000);
  if (iVar5 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_800b40c4(1);
  DAT_80119db8 = 0xa0;
  DAT_80119dd2 = 2;
  DAT_80119dd4 = 1;
  DAT_80119dd6 = 0xf5c;
  DAT_80119dd8 = 0x1999;
  DAT_80119dda = 0x800;
  DAT_80119ddc = 0x68;
  DAT_80119dba = 0x65;
  DAT_80119dd3 = 100;
  DAT_80119dbc = 0x9d;
  DAT_80119dca = 100;
  DAT_80119dcb = 100;
  FUN_800b2694();
  iVar5 = func_0x80004c9c(0x7bc);
  iVar1 = func_0x80004c9c(0x7bd);
  iVar2 = func_0x80004c9c(0x7be);
  DAT_8011a714 = FUN_8008af80(iVar5 + iVar1 + iVar2 + 0x30);
  if ((DAT_8011a714 & 0xf) != 0) {
    DAT_8011a714 = DAT_8011a714 + 0xf & 0xfffffff0;
  }
  DAT_8011a700 = DAT_8011a714;
  iVar5 = func_0x80004cfc(0x7bc,DAT_8011a714,0,"SND_PROJ");
  DAT_8011a714 = DAT_8011a714 + iVar5;
  if ((DAT_8011a714 & 0xf) != 0) {
    DAT_8011a714 = DAT_8011a714 + 0xf & 0xfffffff0;
  }
  DAT_8011a70c = DAT_8011a714;
  iVar5 = func_0x80004cfc(0x7bd,DAT_8011a714,0,"SND_POOL");
  DAT_8011a714 = DAT_8011a714 + iVar5;
  if ((DAT_8011a714 & 0xf) != 0) {
    DAT_8011a714 = DAT_8011a714 + 0xf & 0xfffffff0;
  }
  DAT_8011a708 = DAT_8011a714;
  iVar5 = func_0x80004cfc(0x7be,DAT_8011a714,0,"SND_SMPDIR");
  DAT_8011a714 = DAT_8011a714 + iVar5;
  if ((DAT_8011a714 & 0xf) != 0) {
    DAT_8011a714 = DAT_8011a714 + 0xf & 0xfffffff0;
  }
  DAT_8011a704 = func_0x80004930(0x7bf);
  uVar3 = func_0x80004930(0x7bb);
  FUN_800b3f54(uVar3,0);
  FUN_800aa4f8(0x8013a170,&DAT_80119d88,&DAT_80119d94,&DAT_80119da0,&DAT_80119dac,0x459c4000,
               0x469c4000,0x469c4000,0,0x7f);
  FUN_80075c78();
  return;
}
