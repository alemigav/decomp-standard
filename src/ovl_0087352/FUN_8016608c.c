/* FUN_8016608c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016608c  body 0x8016608c..0x801660ff  size 116 B
 * body sha256 983692b5983e125f5d40cc907b899fbb76c2804ff5e383a864361d1600f245c5
 * provider record sha256 4a76efe788bb127c3a3de3c32eb944cb7aa805fb2fd23794ba8d0c8bf62df6d3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016608c(ushort param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)&DAT_800e13f0;
  if (_DAT_800df93c != (int *)&DAT_800e13f0) {
    do {
      iVar1 = *piVar2;
      if ((*(char *)(iVar1 + 8) == '!') && ((*(ushort *)(iVar1 + 0x2c6) & 4) == 0)) {
        *(ushort *)(iVar1 + 0x2c6) = *(ushort *)(iVar1 + 0x2c6) | param_1;
        *(undefined1 *)(iVar1 + 700) = 0;
        *(undefined1 *)(iVar1 + 699) = 0;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != _DAT_800df93c);
  }
  return;
}
