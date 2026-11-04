/* FUN_800a1be8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1be8  body 0x800a1be8..0x800a1ecb  size 740 B
 * body sha256 e3053f1c2fb2eff821c72df3676d43716ead5ce02ca2f753a66a8b8499d8d270
 * provider record sha256 ca12a2ced079242267eb6a66467f7f1fbdc016cc8a0d443ee9f8656d4d451e11
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a1be8(void)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined1 *puVar10;
  uint uVar11;
  
  if (_DAT_80147fa0 != 0) {
    uVar11 = 0;
    puVar10 = &DAT_8013bc90;
    do {
      if (puVar10[0xfc0] != '\0') {
        _DAT_80143c50 = uVar11;
        _DAT_80143c58 = puVar10;
        DAT_80143c54 = FUN_800a8364(puVar10[0xfc4]);
        if (*(int *)(_DAT_80143c58 + 0xf68) != 0) {
          iVar3 = **(int **)(_DAT_80143c58 + 0xf6c);
          while ((iVar3 != -1 &&
                 (**(uint **)(_DAT_80143c58 + 0xf6c) <=
                  (uint)(*(int *)(_DAT_80143c58 + 0xf74) + *(int *)(_DAT_80143c58 + 0x120))))) {
            uVar7 = (*(uint **)(_DAT_80143c58 + 0xf6c))[1];
            uVar8 = _DAT_80143c50 & 0xff;
            *(uint *)(_DAT_80143c58 + 0x124) = uVar7;
            FUN_800a82d8(uVar7,uVar8);
            iVar3 = *(int *)(_DAT_80143c58 + 0xf6c);
            *(int *)(_DAT_80143c58 + 0xf6c) = iVar3 + 8;
            iVar3 = *(int *)(iVar3 + 8);
          }
        }
        puVar2 = _DAT_80143c58;
        if (_DAT_80147fa4 == 0) {
          trap(0x1c00);
        }
        if ((_DAT_80147fa4 == -1) && (_DAT_80147fa0 << 0x10 == -0x80000000)) {
          trap(0x1800);
        }
        uVar7 = (((uint)(*(int *)(_DAT_80143c58 + 0x124) * 0xc00) / 0x3c) *
                 ((_DAT_80147fa0 << 0x10) / _DAT_80147fa4) >> 3) *
                (uint)*(ushort *)(_DAT_80143c58 + 0xfc2);
        *(uint *)(_DAT_80143c58 + 0x118) = uVar7 >> 8 & 0xffff;
        uVar7 = uVar7 >> 0x18;
        *(uint *)(puVar2 + 0x11c) = uVar7;
        *(int *)(puVar2 + 0x120) = (int)uVar7 >> 1;
        if (*(int *)(puVar2 + 0xf68) != 0) {
          iVar3 = *(int *)(puVar2 + 0xf70);
          *(uint *)(puVar2 + 0xf70) = iVar3 + *(int *)(puVar2 + 0x118) & 0xffff;
          *(uint *)(puVar2 + 0xf74) =
               *(int *)(puVar2 + 0xf74) +
               ((uint)(iVar3 + *(int *)(puVar2 + 0x118)) >> 0x10) + *(int *)(puVar2 + 0x11c);
        }
        cVar4 = FUN_800a0880();
        cVar5 = FUN_8009feb8();
        FUN_800a0518();
        FUN_800a06c8();
        FUN_800a02f8();
        cVar6 = FUN_800a0404();
        piVar9 = (int *)*(int *)(_DAT_80143c58 + 0xf7c);
        while (piVar1 = piVar9, piVar1 != (int *)0x0) {
          piVar9 = (int *)*piVar1;
          iVar3 = FUN_800b230c(piVar1[2]);
          if (iVar3 == -1) {
            if (*piVar1 != 0) {
              *(int *)(*piVar1 + 4) = piVar1[1];
            }
            if ((undefined4 *)piVar1[1] == (undefined4 *)0x0) {
              *(int *)(_DAT_80143c58 + 0xf7c) = *piVar1;
            }
            else {
              *(undefined4 *)piVar1[1] = *piVar1;
            }
            *piVar1 = (int)_DAT_8013bc80;
            if (_DAT_8013bc80 != (int *)0x0) {
              *(int **)((int)_DAT_8013bc80 + 4) = piVar1;
            }
            piVar1[1] = 0;
            _DAT_8013bc80 = piVar1;
          }
        }
        if (((cVar4 == '\0') && (cVar5 == '\0')) && (cVar6 == '\0')) {
          puVar10[0xfc0] = 0;
          puVar10[0xfc1] = 1;
        }
      }
      uVar11 = uVar11 + 1;
      puVar10 = puVar10 + 0xff8;
    } while (uVar11 < 8);
  }
  return;
}
