/* FUN_801713b0
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801713b0  body 0x801713b0..0x80171483  size 212 B
 * body sha256 1d7b64e0c3a9bee0de40c47ec9f7eb6ba1becbc5e30dd1407a5f78f3a20987bd
 * provider record sha256 13c0880ce8c6a77d8a78c53e4f9d5768d5f46ea7c92b849bb85282adb152274f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801713b0(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  puVar2 = &DAT_80171ce4;
  while ((param_1 < uVar1 || (uVar1 + puVar2[1] <= param_1))) {
    uVar3 = uVar3 + 1;
    uVar1 = uVar1 + puVar2[1];
    puVar2 = puVar2 + 3;
    if (8 < uVar3) {
      return 0xffffffff;
    }
  }
  if ((DAT_80172378 != uVar3) && (puVar2[2] != 2)) {
    DAT_8017237c = _DAT_8010b6fc;
    if (puVar2[2] != 0) {
      DAT_8017237c = _DAT_8010b6fc + 96000;
    }
    func_0x80004cfc(*puVar2,DAT_8017237c,0,0);
    DAT_80172378 = uVar3;
  }
  return puVar2[2];
}
