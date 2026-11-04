/* FUN_800a4560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a4560  body 0x800a4560..0x800a485b  size 764 B
 * body sha256 ef26ed199150b2b7979732006befdb59e79c30eb639c4afd3d42535fcf872a54
 * provider record sha256 30ca3995df09bb289a5ea96102ea4cfd90371a84ba3f115df1bb7b69f73cd3b7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a4560(undefined4 param_1,undefined2 param_2)

{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort uVar7;
  char cVar8;
  uint uVar9;
  
  cVar8 = '\0';
  uVar7 = 0;
  uVar9 = 0;
  if (_DAT_80143f14 != 0) {
    uVar4 = 0;
    do {
      iVar5 = uVar4 * 0x68;
      if (*(char *)(iVar5 + _DAT_80143f0c + 0x61) != '\0') {
        *(undefined1 *)(iVar5 + _DAT_80143f0c + 0x61) = 0;
        uVar9 = uVar9 | 1 << (*(byte *)(iVar5 + _DAT_80143f0c + 0x60) & 0x1f);
      }
      if (*(char *)(iVar5 + _DAT_80143f0c) != '\0') {
        FUN_800a3bf4((char *)(iVar5 + _DAT_80143f0c),param_2,cVar8);
        cVar8 = cVar8 + '\x01';
      }
      uVar7 = uVar7 + 1;
      uVar4 = (uint)uVar7;
    } while (uVar7 < _DAT_80143f14);
  }
  puVar2 = _DAT_80143f54;
  iVar5 = _DAT_80143f50;
  puVar6 = (ushort *)((uint)*_DAT_80143f54 * 0xa10 + _DAT_80143f50);
  if (*puVar6 == 0) {
    puVar6[0x1e] = 0;
    puVar6 = (ushort *)((uint)*puVar2 * 0xa10 + iVar5);
  }
  else {
    puVar6 = puVar6 + (*puVar6 - 1) * 0x28;
  }
  *(undefined4 *)(puVar6 + 0x2a) = param_1;
  puVar2 = _DAT_80143f54;
  iVar5 = _DAT_80143f50;
  *(undefined4 *)((uint)*_DAT_80143f54 * 0xa10 + _DAT_80143f50 + 8) = _DAT_80143f64;
  *(uint *)((uint)*puVar2 * 0xa10 + iVar5 + 4) = uVar9;
  iVar3 = _DAT_80143f68;
  bVar1 = _DAT_80143f68 != 0;
  *(int *)((uint)*puVar2 * 0xa10 + iVar5 + 0xc) = _DAT_80143f68;
  if (bVar1) {
    *(short *)((uint)*puVar2 * 0xa10 + iVar5 + 2) =
         (short)(_DAT_80143f6c / 6 + (_DAT_80143f6c >> 0x1f) >> 5) - (short)(_DAT_80143f6c >> 0x1f);
    _DAT_80143f6c = _DAT_80143f6c + 0xc0;
    if (_DAT_80143f6c == *(int *)(iVar3 + 4)) {
      _DAT_80143f6c = 0;
    }
  }
  *_DAT_80143f54 = *_DAT_80143f54 + 1;
  if (*_DAT_80143f54 < _DAT_80143f4e) {
    _DAT_80143fe4 = _DAT_80143f50 + (uint)*_DAT_80143f54 * 0xa10 + 0x10 & 0xfffffff0;
    _DAT_80143fe0 = _DAT_80143f50 + (uint)*_DAT_80143f54 * 0xa10 + 0x10;
    *(undefined2 *)((uint)*_DAT_80143f54 * 0xa10 + _DAT_80143f50) = 0;
  }
  return;
}
