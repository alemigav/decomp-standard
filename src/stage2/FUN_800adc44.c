/* FUN_800adc44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800adc44  body 0x800adc44..0x800add27  size 228 B
 * body sha256 8470afe4b8d71330876483472ac05b9c0413397c04772f99fa194fb8b426d8db
 * provider record sha256 aa3aef64bcf289033ec6809886ab6251e35e9bdd35bec2fc1e51a3bfe80031c5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800adc44(short param_1)

{
  undefined4 uVar1;
  short *psVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < _DAT_80157e10) {
    psVar2 = (short *)&DAT_80157e20;
    do {
      if (*psVar2 == param_1) break;
      iVar5 = iVar5 + 1;
      psVar2 = psVar2 + 4;
    } while (iVar5 < _DAT_80157e10);
  }
  uVar1 = 0;
  if (iVar5 != _DAT_80157e10) {
    FUN_800a5678();
    iVar5 = iVar5 + 1;
    if (iVar5 < _DAT_80157e10) {
      puVar4 = (undefined4 *)(&DAT_80157e20 + iVar5 * 8);
      iVar3 = iVar5 * 8 + -8;
      do {
        uVar1 = puVar4[1];
        *(undefined4 *)(&DAT_80157e20 + iVar3) = *puVar4;
        *(undefined4 *)(&DAT_80157e24 + iVar3) = uVar1;
        puVar4 = puVar4 + 2;
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 8;
      } while (iVar5 < _DAT_80157e10);
    }
    _DAT_80157e10 = _DAT_80157e10 + -1;
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
