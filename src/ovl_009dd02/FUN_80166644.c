/* FUN_80166644
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166644  body 0x80166644..0x801666c7  size 132 B
 * body sha256 0e352e28ee764546aaec6f1447e3750f86e513af7c950f40a0b4e764de99e89e
 * provider record sha256 5663a6d95198436193e38ff794ca0e65b0fe2827e02506cb3b9e717f92c2b323
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_80166644(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  *(undefined1 *)(param_1 + 0x2b4) = 0;
  puVar1 = _DAT_800e13ec;
  uVar2 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  puVar3 = &DAT_800e1130;
  if ((((_DAT_800e110c & 0x10000000) != 0) &&
      (((6000 < *(int *)(param_1 + 0x28c) || (6000 < uVar2)) &&
       ((*(uint *)(param_1 + 0x290) & 0xc0000000) == 0x40000000)))) &&
     ((int)uVar2 < *(int *)(param_1 + 0x28c))) {
    *(undefined1 *)(param_1 + 0x2b4) = 1;
    puVar3 = puVar1;
  }
  return puVar3;
}
