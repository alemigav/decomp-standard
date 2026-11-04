/* FUN_800b4540
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4540  body 0x800b4540..0x800b467b  size 316 B
 * body sha256 98d6b65af9aaf434de8c112702d156e43d99674781df0bceeac45f50fc0f1b5a
 * provider record sha256 6a8f47f7f978aacfec2249135a6848d480825a727354bb84ab32a2e59e1794a5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b4540(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  byte bVar5;
  
  if (DAT_8015b000 != '\0') {
    osSendMesg(0x8015b010,0,0);
  }
  if (DAT_8015afc0 == 0) {
    DAT_8015b000 = 0;
  }
  else {
    bVar5 = 0;
    if (DAT_8015afc0 != 0) {
      do {
        _DAT_80143fd0 = _DAT_80143fd0 + 0xc;
        _DAT_80143fdc = FUN_80135cb0(_DAT_80143fdc);
        iVar1 = _DAT_80143fec;
        uVar4 = (uint)bVar5;
        bVar5 = bVar5 + 1;
        iVar2 = uVar4 * 0xc;
        uVar4 = (uint)_DAT_80143fcc;
        puVar3 = (undefined4 *)(uVar4 * 0xc + _DAT_80143fec);
        puVar3[1] = *(undefined4 *)(iVar2 + -0x7fea502c);
        _DAT_80143fcc = _DAT_80143fcc + 1;
        *puVar3 = *(undefined4 *)(iVar2 + -0x7fea5028);
        *(undefined4 *)(uVar4 * 0xc + iVar1 + 8) = *(undefined4 *)(iVar2 + -0x7fea5030);
      } while (bVar5 < DAT_8015afc0);
    }
    DAT_8015afc0 = 0;
    DAT_8015b000 = 1;
  }
  return;
}
