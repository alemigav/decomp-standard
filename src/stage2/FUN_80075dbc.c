/* FUN_80075dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075dbc  body 0x80075dbc..0x80075ef7  size 316 B
 * body sha256 149c17e35204134e1922064c6739c0d8008d5bcaca6a835393815f032f6cd3c0
 * provider record sha256 4e7acedf744e2efd18f0411465d3dfdaac1da00203e8b4e2fb941e000138603e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80075dbc(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  
  iVar11 = 0x18;
  puVar10 = (undefined4 *)&UNK_8011a2a8;
  puVar9 = &DAT_8011a2a4;
  puVar8 = &DAT_8011a2a0;
  puVar7 = &DAT_8011a29c;
  puVar6 = &DAT_8011a298;
  puVar5 = &DAT_8011a294;
  puVar4 = &DAT_8011a290;
  puVar3 = (undefined4 *)&UNK_8011a28c;
  puVar2 = (undefined4 *)&UNK_8011a310;
  DAT_80119e70 = 0;
  DAT_80119e71 = 0;
  _DAT_80119e7c = 0x7f007f;
  DAT_80119e80 = 0x400040;
  DAT_80119e84 = 0x400040;
  DAT_80119e88 = 0x7f007f;
  DAT_80119eaf = 0xff;
  DAT_80119eae = 0xff;
  DAT_80119ead = 0xff;
  DAT_80119eac = 0xff;
  DAT_80119eab = 0xff;
  DAT_80119eaa = 0xff;
  DAT_80119ea9 = 0xff;
  DAT_80119ea8 = 0xff;
  puVar1 = &DAT_80119f2c;
  do {
    puVar10 = puVar10 + -9;
    puVar9 = puVar9 + -9;
    puVar8 = puVar8 + -9;
    puVar7 = puVar7 + -9;
    puVar6 = puVar6 + -9;
    puVar5 = puVar5 + -9;
    puVar4 = puVar4 + -9;
    puVar3 = puVar3 + -9;
    puVar2 = puVar2 + -1;
    iVar11 = iVar11 + -1;
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *puVar2 = 0;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar5 = 0;
    *puVar6 = 0;
    *puVar7 = 0;
    *puVar8 = 0;
    *puVar9 = 0;
    *puVar10 = 0;
    puVar1 = puVar1 + -2;
  } while (iVar11 != 0);
  DAT_80119ee0 = 0;
  DAT_80119ed8 = 0;
  DAT_80119ed4 = 0;
  DAT_80119ecc = DAT_800c52dc + 0x3000;
  DAT_80119ed0 = DAT_800c52dc + 0x3100;
  return;
}
