/* FUN_80165ea8
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165ea8  body 0x80165ea8..0x80165fdb  size 308 B
 * body sha256 79b87a1b2041665ef76ead01e4ced244242235d5ee82c44b1c658140eb29824c
 * provider record sha256 2e0a9683eea41ee653d15cdcc10c2022a9e888e0a86662c5919151adebe0ff27
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ea8(int param_1)

{
  int iVar1;
  
  if (((((*(char *)(param_1 + 6) == '\x03') && (*(uint *)(param_1 + 0x28c) < 0x514)) &&
       ((DAT_800e139f & 0x80) == 0)) &&
      ((*(byte *)(param_1 + 0x1e9) < 0xb && (*(char *)(param_1 + 0x1a2) == DAT_800e12d2)))) &&
     (DAT_800e1138 != '\x0f')) {
    if (((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0) &&
       (iVar1 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                (int)((*(ushort *)(param_1 + 0x66) + 0x100) * 0x10000) >> 0x10),
       iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
    if (((*(ushort *)(param_1 + 0x2b6) & 0x40) == 0) &&
       (iVar1 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                (int)((*(ushort *)(param_1 + 0x66) - 0x100) * 0x10000) >> 0x10,0x100
                               ), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
  }
  return;
}
