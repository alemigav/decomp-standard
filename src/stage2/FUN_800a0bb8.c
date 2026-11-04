/* FUN_800a0bb8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a0bb8  body 0x800a0bb8..0x800a0d1b  size 356 B
 * body sha256 5dd417aeb059f1a61db7e87948f6b96d8815b9cf1a8b45506b90026aefe0ba6b
 * provider record sha256 ef119536953092914454ce5c7f4d0a2b6a3e1c0cd34c8976b09b306c030c8287
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a0bb8(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = _DAT_80143c58;
  piVar4 = *(int **)(_DAT_80143c58 + 0xf68);
  if (piVar4 != (int *)0x0) {
    *(int **)(_DAT_80143c58 + 0xf6c) = piVar4;
    *(undefined4 *)(iVar2 + 0xf74) = param_1;
    *(undefined4 *)(iVar2 + 0xf70) = 0;
    if (piVar4 != (int *)0x0) {
      iVar2 = *piVar4;
      while ((iVar2 != -1 &&
             (**(uint **)(_DAT_80143c58 + 0xf6c) <=
              (uint)(*(int *)(_DAT_80143c58 + 0xf74) + *(int *)(_DAT_80143c58 + 0x120))))) {
        uVar3 = (*(uint **)(_DAT_80143c58 + 0xf6c))[1];
        *(uint *)(_DAT_80143c58 + 0x124) = uVar3;
        FUN_800a82d8(uVar3,DAT_80143c53);
        iVar2 = *(int *)(_DAT_80143c58 + 0xf6c);
        *(int *)(_DAT_80143c58 + 0xf6c) = iVar2 + 8;
        iVar2 = *(int *)(iVar2 + 8);
      }
    }
    iVar2 = _DAT_80143c58;
    if (_DAT_80147fa4 == 0) {
      trap(0x1c00);
    }
    if ((_DAT_80147fa4 == -1) && (_DAT_80147fa0 << 0x10 == -0x80000000)) {
      trap(0x1800);
    }
    uVar3 = (((uint)(*(int *)(_DAT_80143c58 + 0x124) * 0xc00) / 0x3c) *
             ((_DAT_80147fa0 << 0x10) / _DAT_80147fa4) >> 3) *
            (uint)*(ushort *)(_DAT_80143c58 + 0xfc2);
    uVar1 = uVar3 >> 0x18;
    *(uint *)(_DAT_80143c58 + 0x11c) = uVar1;
    *(uint *)(iVar2 + 0x118) = uVar3 >> 8 & 0xffff;
    *(int *)(iVar2 + 0x120) = (int)uVar1 >> 1;
  }
  return;
}
